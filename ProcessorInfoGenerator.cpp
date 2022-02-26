#include <exception>
#include "ProcessorInfoGenerator.h"

namespace mi
{
	ProcessorInfo ProcessorInfoGenerator::getProcessorInfo(IWbemLocator *pLocator, IWbemServices *pServices)
	{
		HRESULT hres;

		IEnumWbemClassObject* pEnumerator = NULL;
		hres = pServices->ExecQuery(
			bstr_t("WQL"),
			bstr_t("SELECT * FROM Win32_Processor"),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			&pEnumerator
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Query for processor failed.");
		}

		IWbemClassObject *pclsObj = NULL;
		ULONG uReturn = 0;
		ProcessorInfo pProcInf;

		while (pEnumerator)
		{
			HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
				&pclsObj, &uReturn);

			if (0 == uReturn)
			{
				break;
			}

			VARIANT vtProp;

			hr = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
			pProcInf.name = vtProp.bstrVal;

			hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
			pProcInf.manufacturer = vtProp.bstrVal;

			hr = pclsObj->Get(L"Version", 0, &vtProp, 0, 0);
			pProcInf.version = vtProp.bstrVal;

			hr = pclsObj->Get(L"Architecture", 0, &vtProp, 0, 0);
			pProcInf.architecture = static_cast<ProcessorInfo::CPUArchitecture>(vtProp.intVal);

			hr = pclsObj->Get(L"MaxClockSpeed", 0, &vtProp, 0, 0);
			pProcInf.maxClockSpeed = vtProp.intVal;

			hr = pclsObj->Get(L"DataWidth", 0, &vtProp, 0, 0);
			pProcInf.dataWidth = vtProp.intVal;

			hr = pclsObj->Get(L"Family", 0, &vtProp, 0, 0);
			pProcInf.family = static_cast<ProcessorInfo::CPUFamily>(vtProp.intVal);

			hr = pclsObj->Get(L"NumberOfCores", 0, &vtProp, 0, 0);
			pProcInf.coresCount = vtProp.intVal;

			pclsObj->Release();
		}
		return pProcInf;
	}
}