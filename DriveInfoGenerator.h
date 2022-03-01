#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include <vector>
#include "DriveInfo.h"

namespace mi
{
	class DriveInfoGenerator
	{
	public:
		std::vector<DriveInfo> getDriveInfo(IWbemLocator *, IWbemServices *);
	};
}