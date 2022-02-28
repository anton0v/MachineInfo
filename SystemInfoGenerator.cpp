#include "SystemInfoGenerator.h"

namespace mi
{
	SystemInfo SystemInfoGenerator::getSystemInfo(IWbemLocator *pLocator, IWbemServices *pServices)
	{
		HRESULT hres;

		IEnumWbemClassObject* pEnumerator = NULL;
		hres = pServices->ExecQuery(
			bstr_t("WQL"),
			bstr_t("SELECT * FROM Win32_ComputerSystem"),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			&pEnumerator
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Query for computer system info failed.");
		}

		IWbemClassObject *pclsObj = NULL;
		ULONG uReturn = 0;
		SystemInfo sysInf;

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
			sysInf.name = vtProp.bstrVal;

			hr = pclsObj->Get(L"Model", 0, &vtProp, 0, 0);
			sysInf.model = vtProp.bstrVal;

			hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
			sysInf.manufacturer = vtProp.bstrVal;

			VariantClear(&vtProp);

			pclsObj->Release();
		}

		return sysInf;
	}
}