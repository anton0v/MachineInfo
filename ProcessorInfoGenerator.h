#pragma once
#include "ProcessorInfo.h"

namespace mi
{
	class ProcessorInfoGenerator
	{
	public:
		ProcessorInfoGenerator();
		ProcessorInfo getProcessorInfo(IWbemLocator *, IWbemServices *);
	private:
		bool isGenerated;
	};
}