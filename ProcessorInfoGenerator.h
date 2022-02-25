#pragma once
#include <comdef.h>
#include <Wbemidl.h>
#include "ProcessorInfo.h"

namespace mi
{
	class ProcessorInfoGenerator
	{
	public:
		ProcessorInfo getProcessorInfo(IWbemLocator *, IWbemServices *);
	};
}