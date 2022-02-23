#include "ProcessorInfo.h"
#pragma once

namespace mi
{
	mi::ProcessorInfo::ProcessorInfo()
	{
		name = L"";
		manufacturer = L"";
		version = L"";
		architecture = 0;
		maxClockSpeed = 0;
		dataWidth = 0;
		family = 0;
		coresCount = 0;
	}

	void mi::ProcessorInfo::Init(IWbemLocator *pLocator, IWbemServices *pServices)
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
			throw exception("Query for computer system name failed.");
		}

		IWbemClassObject *pclsObj = NULL;
		ULONG uReturn = 0;

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
			name = vtProp.bstrVal;

			hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
			manufacturer = vtProp.bstrVal;
			
			hr = pclsObj->Get(L"Version", 0, &vtProp, 0, 0);
			version = vtProp.bstrVal;
			
			hr = pclsObj->Get(L"Architecture", 0, &vtProp, 0, 0);
			architecture = vtProp.intVal;
			
			hr = pclsObj->Get(L"MaxClockSpeed", 0, &vtProp, 0, 0);
			maxClockSpeed = vtProp.intVal;
			
			hr = pclsObj->Get(L"DataWidth", 0, &vtProp, 0, 0);
			dataWidth = vtProp.intVal;
			
			hr = pclsObj->Get(L"Family", 0, &vtProp, 0, 0);
			family = vtProp.intVal;

			hr = pclsObj->Get(L"NumberOfCores", 0, &vtProp, 0, 0);
			coresCount = vtProp.intVal;

			pclsObj->Release();
		}
	}
}