#pragma once
#include "MachineInfo.h"

namespace mi
{
	MachineInfo::MachineInfo() :
		UUID(L""),
		ID(""),
		initialized(false),
		memory(0),
		pLocator(NULL),
		pServices(NULL)
	{}

	void MachineInfo::Init()
	{
		WMIConnect();

		SystemInfoGenerator systemGenerator;
		systemInfo = systemGenerator.getSystemInfo(pLocator, pServices);

		ProcessorInfoGenerator procInfGenerator;
		processorInfo = procInfGenerator.getProcessorInfo(pLocator, pServices);

		OperatingSystemInfoGenerator OSInfGenerator;
		operatingSystemInfo = OSInfGenerator.getOperatingSystemInfo(pLocator, pServices);

		GPUInfoGenerator GPUGenerator;
		videoCardsInfo = GPUGenerator.getCPUInfo(pLocator, pServices);

		MonitorInfoGenerator monitorGenerator;
		monitorsInfo = monitorGenerator.getMonitorInfo(pLocator, pServices);

		DriveInfoGenerator driveGenerator;
		drivesInfo = driveGenerator.getDriveInfo(pLocator, pServices);

		MemoryInfoGenerator memoryGenerator;
		memoryInfo = memoryGenerator.getMemoryInfo(pLocator, pServices);

		for (auto iter = memoryInfo.cbegin(); iter != memoryInfo.cend(); iter++)
			memory += iter->getMemory();

		getUUID();
		std::wstring strForMD5 = UUID + processorInfo.getName();
		for (auto iter = videoCardsInfo.cbegin(); iter != videoCardsInfo.cend(); iter++)
			strForMD5 += iter->getName();

		ID = md5(strForMD5);

		initialized = true;
	}

	void MachineInfo::getInfo()
	{
		if (initialized)
		{
			std::wcout << L"Machine name: " << systemInfo.getName() << std::endl;
			std::cout << "Machine ID: " << ID << std::endl;
			std::wcout << L"Machine model: " << systemInfo.getModel() << std::endl;
			std::wcout << L"Machine manufacturer: " << systemInfo.getManufacturer() << std::endl;
			std::wcout << L"Operating system: " << operatingSystemInfo.getName() 
				<< " " << operatingSystemInfo.getBitDepth() << L"-bit (" 
				<< operatingSystemInfo.getMajorVersion() << L"." 
				<< operatingSystemInfo.getMinorVersion() << L" , Build "
				<< operatingSystemInfo.getBuild() << ")" << std::endl;
			std::wcout << L"Language: " << operatingSystemInfo.getLanguage() << std::endl;
			std::wcout << L"Memory: " << (float)(memory / 1024 / 1024) << " GB" << std::endl;
			std::cout << std::endl;
			std::wcout << L"Processor : " << processorInfo.getName() << L" " 
				<< (float)processorInfo.getMaxClockSpeed()/1000 << L" GHz (" 
				<< processorInfo.getCoresCount() << L" CPUs) ~" 
				<< (float)processorInfo.getCurrentClockSpeed()/1000 << L" GHz" << std::endl;
			std::wcout << L"Processor manufacturer: " << processorInfo.getManufacturer() << std::endl;
			std::wcout << L"Processor version: " << processorInfo.getVersion() << std::endl;
			std::wcout << L"Processor family: " << processorInfo.getFamily() << std::endl;
			std::wcout << L"Processor architecture: " << processorInfo.getArchitecture() << std::endl;
			std::cout << std::endl;

			std::cout << "Display devices:" << std::endl;
			std::cout << "=======================" << std::endl;
			std::cout << "GPUs:" << std::endl;
			std::cout << "=======================" << std::endl;

			for (std::vector<GPUInfo>::iterator iter = videoCardsInfo.begin(); iter < videoCardsInfo.end(); iter++)
			{
				std::wcout << L"Card Name: " << iter->getName() << std::endl;
				std::wcout << L"Card DAC type: " << iter->getDACType() << std::endl;
				std::wcout << L"Card Dedicated Memory: " << iter->getMemory() << " MB" << std::endl;
				std::wcout << L"Card Availability: " << iter->getAvailability() << std::endl;
				if (static_cast<GPUInfo::DeviceAvailability>(iter->getIntAvailability()) == 
					GPUInfo::DeviceAvailability::Running_Or_Full_Power)
				{
					std::cout << "Current Mode: " <<  iter->getHorizontalResolution()
						<< "x" << iter->getVerticalResolution() << " ("
						<< iter->getBitsPerPixel() << " bit) (" 
						<< iter->getRefreshRate() << "Hz)"<< std::endl;
				}
				std::cout << std::endl;
			}

			std::cout << "=======================" << std::endl;
			std::cout << "Monitors:" << std::endl;
			std::cout << "=======================" << std::endl;
			for (std::vector<MonitorInfo>::iterator iter = monitorsInfo.begin(); iter < monitorsInfo.end(); iter++)
			{
				std::wcout << L"Monitor Name: " << iter->getName() << std::endl;
				std::wcout << L"Monitor Availability: " << iter->getAvailability() << std::endl;
				if (static_cast<MonitorInfo::DeviceAvailability>(iter->getIntAvailability()) ==
					MonitorInfo::DeviceAvailability::Running_Or_Full_Power)
				{
					std::cout << "Native Mode: " << iter->getScreenWidth()
						<< "x" << iter->getScreenHeight() << "(p)" << std::endl;
				}
				std::cout << std::endl;
			}

			
			std::cout << "Drives info:" << std::endl;
			std::cout << "=======================" << std::endl;
			for (std::vector<DriveInfo>::iterator iter = drivesInfo.begin(); iter < drivesInfo.end(); iter++)
			{
				std::wcout << L"Drive " << iter->getName() << std::endl;
				std::wcout << L"Drive Type: " << iter->getType() << std::endl;
				if (static_cast<DriveInfo::DriveType>(iter->getIntType()) ==
					DriveInfo::DriveType::Local_Disk)
				{
					std::wcout << L"Free space: " << iter->getFreeSpace() << " GB" << std::endl;
					std::wcout << L"Total Space: " << iter->getTotalSpace() << " GB" << std::endl;
					std::wcout << L"File System: " << iter->getFileSystem() << std::endl;
				}
				std::cout << std::endl;
			}

		}
	}

	bool MachineInfo::isInitialized()
	{
		return initialized;
	}

	void MachineInfo::WMIConnect()
	{
		HRESULT hres;

		hres = CoInitializeEx(0, COINIT_MULTITHREADED);
		if (FAILED(hres))
		{
			throw std::exception("Failed to initialize COM library.");
		}

		hres = CoInitializeSecurity(
			NULL,
			-1,
			NULL,
			NULL,
			RPC_C_AUTHN_LEVEL_DEFAULT,
			RPC_C_IMP_LEVEL_IMPERSONATE,
			NULL,
			EOAC_NONE,
			NULL
		);
		if (FAILED(hres))
		{
			CoUninitialize();
			throw std::exception("Failed to initialize security.");
		}

		hres = CoCreateInstance(
			CLSID_WbemLocator,
			0,
			CLSCTX_INPROC_SERVER,
			IID_IWbemLocator, (LPVOID *)&pLocator
		);
		if (FAILED(hres))
		{
			CoUninitialize();
			throw std::exception("Failed to create IWbemLocator object.");
		}

		hres = pLocator->ConnectServer(
			_bstr_t(L"ROOT\\CIMV2"),
			NULL,
			NULL,
			0,
			NULL,
			0,
			0,
			&pServices
		);
		if (FAILED(hres))
		{
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Could not connect.");
		}

		hres = CoSetProxyBlanket(
			pServices,
			RPC_C_AUTHN_WINNT,
			RPC_C_AUTHZ_NONE,
			NULL,
			RPC_C_AUTHN_LEVEL_CALL,
			RPC_C_IMP_LEVEL_IMPERSONATE,
			NULL,
			EOAC_NONE
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Could not set proxy blanket.");
		}
	}

	void MachineInfo::getUUID()
	{
		HRESULT hres;

		IEnumWbemClassObject* pEnumerator = NULL;
		hres = pServices->ExecQuery(
			bstr_t("WQL"),
			bstr_t("SELECT * FROM Win32_ComputerSystemProduct"),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			&pEnumerator
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Query for UUID failed.");
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

			hr = pclsObj->Get(L"UUID", 0, &vtProp, 0, 0);
			UUID = vtProp.bstrVal;

			pclsObj->Release();
		}
	}
}