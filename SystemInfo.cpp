#include <iostream>
#include <string>
#include <windows.h>
#include "SystemInfo.h"

using namespace std;

namespace mi
{
	typedef void(__stdcall *pRtlGetNtVersionNumbers)(
		LPDWORD major,
		LPDWORD minor,
		LPDWORD build
	);

	SystemInfo::SystemInfo()
	{
		name = L"";
		model = L"";
		manufacturer = L"";
		pRtlGetNtVersionNumbers RtlGetNtVersionNumbers;
		DWORD dwMinorV, dwMajorV;
		DWORD dwBulid;
		
		if (!(RtlGetNtVersionNumbers = reinterpret_cast<pRtlGetNtVersionNumbers>(
			GetProcAddress(GetModuleHandle("ntdll.dll"), "RtlGetNtVersionNumbers")
			))) {
			cout << "Could not locate RtlGetNtVersionNumbers entry point.\n" << endl;
			
		}
		else
		{
			RtlGetNtVersionNumbers(&dwMajorV, &dwMinorV, &dwBulid);
			minorVersion = dwMinorV;
			majorVersion = dwMajorV;
			versionBuild = (DWORD)(LOWORD(dwBulid));
		}
	}

	void SystemInfo::Init(IWbemLocator *pLocator, IWbemServices *pServices)
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
			throw exception("Query for computer system info failed.");
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
			hr = pclsObj->Get(L"Model", 0, &vtProp, 0, 0);
			model = vtProp.bstrVal;
			hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
			manufacturer = vtProp.bstrVal;
			VariantClear(&vtProp);

			pclsObj->Release();
		}
	}
}