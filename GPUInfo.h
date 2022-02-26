#pragma once
#include "DisplayDeviceInfo.h"

namespace mi
{
	class GPUInfo : public DisplayDeviceInfo
	{
	public:
		GPUInfo();
		virtual std::wstring getDACType() const override { return DACType; };
		virtual int getMemory() const override { return memory; };
		virtual int getBitsPerPixel() const override { return bitsPerPixel; };
		virtual int getRefreshRate() const override { return refreshRate; };
		virtual int getHorizontalResolution() const override { return horizontalResolution; };
		virtual int getVerticalResolution() const override { return verticalResolution; };
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