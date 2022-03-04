#pragma once
#include "DisplayDeviceInfo.h"

namespace mi
{
	class GPUInfo : public DisplayDeviceInfo
	{
	public:
		GPUInfo();
		std::wstring getDACType() const  { return DACType; };
		int getMemory() const  { return memory; };
		int getBitsPerPixel() const  { return bitsPerPixel; };
		int getRefreshRate() const  { return refreshRate; };
		int getHorizontalResolution() const  { return horizontalResolution; };
		int getVerticalResolution() const  { return verticalResolution; };
	private:
		int memory;
		int bitsPerPixel;
		int refreshRate;
		int horizontalResolution;
		int verticalResolution;
		std::wstring DACType;

		friend class GPUInfoGenerator;
	};
}