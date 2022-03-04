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
#include "DriveInfoGenerator.h"
#include "MemoryInfoGenerator.h"
#include "MD5Hash.h"

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

		void getInfo();

		bool isInitialized();
		
		SystemInfo systemInfo;
		ProcessorInfo processorInfo;
		OperatingSystemInfo operatingSystemInfo;
		std::vector<GPUInfo> videoCardsInfo;
		std::vector<MonitorInfo> monitorsInfo;
		std::vector<DriveInfo> drivesInfo;
		std::vector<MemoryInfo> memoryInfo;
	private:
		void WMIConnect();
		void getUUID();
		unsigned int memory;
		std::wstring UUID;
		IWbemLocator *pLocator;
		IWbemServices *pServices;
		std::string ID;
		bool initialized;
	};
}