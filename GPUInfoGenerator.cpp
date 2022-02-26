#include "GPUInfoGenerator.h"

namespace mi
{
	std::vector<GPUInfo> GPUInfoGenerator::getCPUInfo(IWbemLocator *pLocator, IWbemServices *pServices)
	{
		HRESULT hres;

		IEnumWbemClassObject* pEnumerator = NULL;
		hres = pServices->ExecQuery(
			bstr_t("WQL"),
			bstr_t("SELECT * FROM Win32_VideoController"),
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
		GPUInfo gpu;
		std::vector<GPUInfo> vectorGPU;

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
			gpu.name = vtProp.bstrVal;

			hr = pclsObj->Get(L"AdapterDACType", 0, &vtProp, 0, 0);
			gpu.DACType = vtProp.bstrVal;

			hr = pclsObj->Get(L"Availability", 0, &vtProp, 0, 0);
			gpu.deviceAvailability = static_cast<GPUInfo::DeviceAvailability>(vtProp.intVal);

			hr = pclsObj->Get(L"AdapterRAM", 0, &vtProp, 0, 0);
			gpu.memory = vtProp.intVal / 1024;

			if (gpu.deviceAvailability == GPUInfo::DeviceAvailability::Running_Or_Full_Power)
			{
				hr = pclsObj->Get(L"CurrentBitsPerPixel", 0, &vtProp, 0, 0);
				gpu.bitsPerPixel = vtProp.intVal;

				hr = pclsObj->Get(L"CurrentHorizontalResolution", 0, &vtProp, 0, 0);
				gpu.horizontalResolution = vtProp.intVal;

				hr = pclsObj->Get(L"CurrentVerticalResolution", 0, &vtProp, 0, 0);
				gpu.verticalResolution = vtProp.intVal;

				hr = pclsObj->Get(L"CurrentRefreshRate", 0, &vtProp, 0, 0);
				gpu.refreshRate = vtProp.intVal;
			}

			vectorGPU.push_back(gpu);

			pclsObj->Release();
		}
		return vectorGPU;
	}
}