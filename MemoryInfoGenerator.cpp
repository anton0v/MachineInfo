#include "MemoryInfoGenerator.h"

namespace mi
{
	std::vector<MemoryInfo> MemoryInfoGenerator::getMemoryInfo(IWbemLocator *pLocator, IWbemServices *pServices)
	{
		HRESULT hres;

		IEnumWbemClassObject* pEnumerator = NULL;
		hres = pServices->ExecQuery(
			bstr_t("WQL"),
			bstr_t("SELECT * FROM Win32_PhysicalMemory"),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			&pEnumerator
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Query for memory failed.");
		}

		IWbemClassObject *pclsObj = NULL;
		ULONG uReturn = 0;
		std::vector<MemoryInfo> vectorMemory;
		MemoryInfo memory;

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

			hr = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
			memory.name = vtProp.bstrVal;

			hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
			memory.manufacturer = vtProp.bstrVal;

			hr = pclsObj->Get(L"Capacity", 0, &vtProp, 0, 0);
			memory.memory = std::stoull(vtProp.bstrVal) / 1024;

			vectorMemory.push_back(memory);

			pclsObj->Release();
		}
		return vectorMemory;
	}
}