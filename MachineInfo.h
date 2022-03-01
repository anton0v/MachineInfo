#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include <iostream>
#include <vector>
#include <exception>
#include "SystemInfoGenerator.h"
#include "ProcessorInfoGenerator.h"
#include "OperatingSystemInfoGenerator.h"
#include "GPUInfoGenerator.h"
#include "MonitorInfoGenerator.h"

namespace mi
{
	class MachineInfo
	{
	public:
		MachineInfo();
		~MachineInfo()
		{
			if (initialized)
			{
				pServices->Release();
				pLocator->Release();
				CoUninitialize();
			}
		}

		void Init();

		bool isInitialized();
		
		SystemInfo systemInfo;
		ProcessorInfo processorInfo;
		OperatingSystemInfo operatingSystemInfo;
		std::vector<GPUInfo> videoCardsInfo;
		std::vector<MonitorInfo> monitorsInfo;
	private:
		void WMIConnect();
		IWbemLocator *pLocator;
		IWbemServices *pServices;
		bool initialized;
	};
}