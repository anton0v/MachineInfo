#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include <iostream>
#include <exception>
#include <string>
#include "SystemInfoGenerator.h"
#include "ProcessorInfoGenerator.h"

#pragma comment(lib, "wbemuuid.lib")

namespace mi
{
	class MachineInfo
	{
	public:
		MachineInfo();
		~MachineInfo()
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
		}
		
		SystemInfo systemInfo;
		ProcessorInfo processorInfo;
	private:
		void WMIConnect();
		IWbemLocator *pLocator;
		IWbemServices *pServices;
	};
}