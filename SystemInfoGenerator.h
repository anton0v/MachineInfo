#pragma once
#include "SystemInfo.h"

namespace mi
{
	class SystemInfoGenerator
	{
	public:
		SystemInfo getSystemInfo(IWbemLocator *, IWbemServices *);
	};
}