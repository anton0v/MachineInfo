#pragma once
#include "DisplayDeviceInfo.h"

namespace mi
{
	class MonitorInfo : public DisplayDeviceInfo
	{
	public:
		MonitorInfo();
		int getScreenWidth() const { return screenWidth; };
		int getScreenHeight() const { return screenHeight; };
		int getPixelPerXLogicalInch() const { return pixelPerXLogicalInch; };
		int getPixelPerYLogicalInch() const { return pixelPerYLogicalInch; };
	private:
		int screenWidth;
		int screenHeight;
		int pixelPerXLogicalInch;
		int pixelPerYLogicalInch;

		friend class MonitorInfoGenerator;
	};
}