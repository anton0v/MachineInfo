#pragma once
#include <string>

namespace mi
{
	class DriveInfo
	{
	public:
		DriveInfo();

		std::wstring getName() const { return name; };
		std::wstring getFileSystem() const { return fileSystem; };
		std::wstring getType() const;
		int getIntType() const { return static_cast<int>(type); };
		float getTotalSpace() const { return totalSpace; };
		float getFreeSpace() const { return freeSpace; };

		enum class DriveType
		{
			Unknown = 0,
			No_Root_Directory = 1,
			Removable_Disk = 2,
			Local_Disk = 3,
			Network_Drive = 4,
			Compact_Disc = 5,
			RAM_Disk = 6
		};

	private:
		std::wstring name;
		std::wstring fileSystem;
		DriveType type;
		float totalSpace;
		float freeSpace;

		friend class DriveInfoGenerator;
	};
}

//enum class DriveAvailability
//{
//	Other = 1,
//	Unknown = 2,
//	Running_Or_Full_Power = 3,
//	Warning = 4,
//	In_Test = 5,
//	Not_Applicable = 6,
//	Power_Off = 7,
//	Off_Line = 8,
//	Off_Duty = 9,
//	Degraded = 10,
//	Not_Installed = 11,
//	Install_Error = 12,
//	Power_Save_Unknown = 13,
//	Power_Save_Low_Power_Mode = 14,
//	Power_Save_Standby = 15,
//	Power_Cycle = 16,
//	Power_Save_Warning = 17,
//	Paused = 18,
//	Not_Ready = 19,
//	Not_Configured = 20,
//	Quiesced = 21
//};