#include "DisplayDeviceInfo.h"

namespace mi
{
	std::wstring DisplayDeviceInfo::getAvailability() const
	{
		switch (deviceAvailability)
		{
		case DeviceAvailability::Other :
			return L"Other";
		case DeviceAvailability::Unknown :
			return L"Unknown";
		case DeviceAvailability::Running_Or_Full_Power :
			return L"Running_Or_Full_Power";
		case DeviceAvailability::Warning :
			return L"Warning";
		case DeviceAvailability::In_Test :
			return L"In_Test";
		case DeviceAvailability::Not_Applicable :
			return L"Not_Applicable";
		case DeviceAvailability::Power_Off :
			return L"Power_Off";
		case DeviceAvailability::Off_Line :
			return L"Off_Line";
		case DeviceAvailability::Off_Duty :
			return L"Off_Duty";
		case DeviceAvailability::Degraded :
			return L"Degraded";
		case DeviceAvailability::Not_Installed :
			return L"Not_Installed";
		case DeviceAvailability::Install_Error :
			return L"Install_Error";
		case DeviceAvailability::Power_Save_Unknown :
			return L"Power_Save_Unknown";
		case DeviceAvailability::Power_Save_Low_Power_Mode :
			return L"Power_Save_Low_Power_Mode";
		case DeviceAvailability::Power_Save_Standby :
			return L"Power_Save_Standby";
		case DeviceAvailability::Power_Cycle :
			return L"Power_Cycle";
		case DeviceAvailability::Power_Save_Warning :
			return L"Power_Save_Warning";
		case DeviceAvailability::Paused :
			return L"Paused";
		case DeviceAvailability::Not_Ready :
			return L"Not_Ready";
		case DeviceAvailability::Not_Configured :
			return L"Not_Configured";
		case DeviceAvailability::Quiesced :
			return L"Quiesced";
		default :
			return L"Unknown";
		}
	}
}