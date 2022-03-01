#include "OperatingSystemInfoGenerator.h"

namespace mi
{
	OperatingSystemInfo OperatingSystemInfoGenerator::getOperatingSystemInfo(IWbemLocator *pLocator, IWbemServices *pServices)
	{
		HRESULT hres;

		IEnumWbemClassObject* pEnumerator = NULL;
		hres = pServices->ExecQuery(
			bstr_t("WQL"),
			bstr_t("SELECT * FROM Win32_OperatingSystem"),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			&pEnumerator
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Query for os failed.");
		}

		IWbemClassObject *pclsObj = NULL;
		ULONG uReturn = 0;
		OperatingSystemInfo os;

		while (pEnumerator)
		{
			HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
				&pclsObj, &uReturn);

			if (0 == uReturn)
			{
				break;
			}

			VARIANT vtProp;
			std::wstring temp;

			hr = pclsObj->Get(L"Caption", 0, &vtProp, 0, 0);
			os.name = vtProp.bstrVal;

			hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
			os.manufacturer = vtProp.bstrVal;

			hr = pclsObj->Get(L"OSLanguage", 0, &vtProp, 0, 0);
			os.language = static_cast<OperatingSystemInfo::OSLanguage>(vtProp.intVal);

			hr = pclsObj->Get(L"Version", 0, &vtProp, 0, 0);
			temp = vtProp.bstrVal;
			os.version = temp;
			os.build = std::stoi(temp.substr(temp.rfind(L".") + 1));
			os.minorVersion = std::stoi((temp.substr(temp.find(L".") + 1)).erase(temp.rfind(L".")));
			os.majorVersion = std::stoi(temp.erase(temp.find(L".")));


			hr = pclsObj->Get(L"OSArchitecture", 0, &vtProp, 0, 0);
			temp = vtProp.bstrVal;
			temp.erase(temp.find(L"-"));
			os.bitDepth = std::stoi(temp);

			pclsObj->Release();
		}
		return os;
	}
}