#pragma once
#include <string>

namespace mi
{
	class DisplayDeviceInfo
	{
	public:
		DisplayDeviceInfo() :
			name(L""),
			deviceAvailability(DeviceAvailability::Unknown)
		{}
		std::wstring getName() const { return name; };
		std::wstring getAvailability() const;
		int  getIntAvailability() const { return static_cast<int>(deviceAvailability); };

		enum class DeviceAvailability
		{
			Other = 1,
			Unknown = 2,
			Running_Or_Full_Power = 3,
			Warning = 4,
			In_Test = 5,
			Not_Applicable = 6,
			Power_Off = 7,
			Off_Line = 8,
			Off_Duty = 9,
			Degraded = 10,
			Not_Installed = 11,
			Install_Error = 12,
			Power_Save_Unknown = 13,
			Power_Save_Low_Power_Mode = 14,
			Power_Save_Standby = 15,
			Power_Cycle = 16,
			Power_Save_Warning = 17,
			Paused = 18,
			Not_Ready = 19,
			Not_Configured = 20,
			Quiesced = 21
		};

	protected:
		std::wstring name;
		DeviceAvailability deviceAvailability;

		friend class GPUInfoGenerator;
		friend class MonitorInfoGenerator;
	};
}

//virtual std::wstring getDACType() const { return L""; };
//virtual std::wstring getDeviceID() const { return L""; };
//virtual int getMemory() const { return 0; };
//virtual int getBitsPerPixel() const { return 0; };
//virtual int getRefreshRate() const { return 0; };
//virtual int getHorizontalResolution() const { return 0; };
//virtual int getVerticalResolution() const { return 0; };
//virtual int getScreenWidth() const { return 0; };
//virtual int getScreenHeight() const { return 0; };