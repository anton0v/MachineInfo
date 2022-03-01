#include "DriveInfo.h"

namespace mi
{
	DriveInfo::DriveInfo() :
		name(L""),
		fileSystem(L""),
		type(DriveType::Unknown),
		totalSpace(0),
		freeSpace(0)
	{
	}

	std::wstring DriveInfo::getType() const
	{
		switch (type)
		{
		case DriveType::Unknown :
			return L"Unknown";
		case DriveType::No_Root_Directory :
			return L"No_Root_Directory";
		case DriveType::Removable_Disk :
			return L"Removable_Disk";
		case DriveType::Local_Disk :
			return L"Local_Disk";
		case DriveType::Network_Drive :
			return L"Network_Drive";
		case DriveType::Compact_Disc :
			return L"Compact_Disc";
		case DriveType::RAM_Disk :
			return L"RAM_Disk";
		default:
			return L"Unknown";
		}
	}

	
}

//std::wstring DriveInfo::getAvailability() const
//{
//	switch (availability)
//	{
//	case DriveAvailability::Other:
//		return L"Other";
//	case DriveAvailability::Unknown:
//		return L"Unknown";
//	case DriveAvailability::Running_Or_Full_Power:
//		return L"Running_Or_Full_Power";
//	case DriveAvailability::Warning:
//		return L"Warning";
//	case DriveAvailability::In_Test:
//		return L"In_Test";
//	case DriveAvailability::Not_Applicable:
//		return L"Not_Applicable";
//	case DriveAvailability::Power_Off:
//		return L"Power_Off";
//	case DriveAvailability::Off_Line:
//		return L"Off_Line";
//	case DriveAvailability::Off_Duty:
//		return L"Off_Duty";
//	case DriveAvailability::Degraded:
//		return L"Degraded";
//	case DriveAvailability::Not_Installed:
//		return L"Not_Installed";
//	case DriveAvailability::Install_Error:
//		return L"Install_Error";
//	case DriveAvailability::Power_Save_Unknown:
//		return L"Power_Save_Unknown";
//	case DriveAvailability::Power_Save_Low_Power_Mode:
//		return L"Power_Save_Low_Power_Mode";
//	case DriveAvailability::Power_Save_Standby:
//		return L"Power_Save_Standby";
//	case DriveAvailability::Power_Cycle:
//		return L"Power_Cycle";
//	case DriveAvailability::Power_Save_Warning:
//		return L"Power_Save_Warning";
//	case DriveAvailability::Paused:
//		return L"Paused";
//	case DriveAvailability::Not_Ready:
//		return L"Not_Ready";
//	case DriveAvailability::Not_Configured:
//		return L"Not_Configured";
//	case DriveAvailability::Quiesced:
//		return L"Quiesced";
//	default:
//		return L"Unknown";
//	}
//}