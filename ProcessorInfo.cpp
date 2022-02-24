#include "ProcessorInfo.h"

namespace mi
{
	mi::ProcessorInfo::ProcessorInfo() :
		name(L""),
		manufacturer(L""),
		version(L""),
		architecture(0),
		maxClockSpeed(0),
		dataWidth(0),
		family(0),
		coresCount(0)
	{}
}