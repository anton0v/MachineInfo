#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include <vector>
#include "GPUInfo.h"

namespace mi
{
	class GPUInfoGenerator
	{
	public:
		std::vector<GPUInfo> getCPUInfo(IWbemLocator *, IWbemServices *);
	};
}