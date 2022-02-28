#pragma once
#include <vector>
#include "DisplayDeviceInfo.h"
#include "GPUInfoGenerator.h"

namespace mi
{
	class DisplayDeviceInfoGenerator
	{
	public:
		std::vector<DisplayDeviceInfo> getDisplayDeviceInfo(IWbemLocator *, IWbemServices *);
	};
}