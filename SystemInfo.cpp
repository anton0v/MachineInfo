#include <string>
#include <windows.h>
#include "SystemInfo.h"

using namespace std;

namespace mi
{
	SystemInfo::SystemInfo()
	{
		unsigned long size = 256;
		char buff[256];
		GetComputerNameA(buff, &size);
		name = buff;
	}
}
