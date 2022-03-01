#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include <vector>
#include "MonitorInfo.h"

namespace mi
{
	class MonitorInfoGenerator
	{
	public:
		std::vector<MonitorInfo> getMonitorInfo(IWbemLocator *, IWbemServices *);
	};
}