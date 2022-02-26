#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include "OperatingSystemInfo.h"

namespace mi
{
	class OperatingSystemInfoGenerator
	{
	public:
		OperatingSystemInfo getOperatingSystemInfo(IWbemLocator *, IWbemServices *);
	};
}