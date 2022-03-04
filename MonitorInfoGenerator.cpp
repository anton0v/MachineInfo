#include "MonitorInfoGenerator.h"

namespace mi
{
	std::vector<MonitorInfo> MonitorInfoGenerator::getMonitorInfo(IWbemLocator *pLocator, IWbemServices *pServices)
	{
		HRESULT hres;

		IEnumWbemClassObject* pEnumerator = NULL;
		hres = pServices->ExecQuery(
			bstr_t("WQL"),
			bstr_t("SELECT * FROM Win32_DesktopMonitor"),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			&pEnumerator
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Query for monitor failed.");
		}

		IWbemClassObject *pclsObj = NULL;
		ULONG uReturn = 0;
		MonitorInfo monitor;
		std::vector<MonitorInfo> vectorMonitor;

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
			monitor.name = vtProp.bstrVal;

			hr = pclsObj->Get(L"Availability", 0, &vtProp, 0, 0);
			monitor.deviceAvailability = static_cast<MonitorInfo::DeviceAvailability>(vtProp.intVal);

			if (monitor.deviceAvailability == MonitorInfo::DeviceAvailability::Running_Or_Full_Power)
			{
				hr = pclsObj->Get(L"ScreenWidth", 0, &vtProp, 0, 0);
				monitor.screenWidth = vtProp.intVal;

				hr = pclsObj->Get(L"ScreenHeight", 0, &vtProp, 0, 0);
				monitor.screenHeight = vtProp.intVal;

				hr = pclsObj->Get(L"PixelPerXLogicalInch", 0, &vtProp, 0, 0);
				monitor.pixelPerXLogicalInch = vtProp.intVal;

				hr = pclsObj->Get(L"PixelPerYLogicalInch", 0, &vtProp, 0, 0);
				monitor.pixelPerYLogicalInch = vtProp.intVal;
			}

			vectorMonitor.push_back(monitor);

			pclsObj->Release();
		}
		return vectorMonitor;
	}
}