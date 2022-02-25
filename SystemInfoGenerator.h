#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include "SystemInfo.h"

namespace mi
{
	class SystemInfoGenerator
	{
	public:
		SystemInfo getSystemInfo(IWbemLocator *, IWbemServices *);
	};
}