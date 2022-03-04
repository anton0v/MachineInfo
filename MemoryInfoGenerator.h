#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include <vector>
#include "MemoryInfo.h"

namespace mi
{
	class MemoryInfoGenerator
	{
	public:
		std::vector<MemoryInfo> getMemoryInfo(IWbemLocator *, IWbemServices *);
	};
}