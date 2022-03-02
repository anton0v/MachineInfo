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