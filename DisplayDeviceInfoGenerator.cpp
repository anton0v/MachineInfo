#include "DisplayDeviceInfoGenerator.h"

namespace mi
{
	std::vector<DisplayDeviceInfo> DisplayDeviceInfoGenerator::getDisplayDeviceInfo(IWbemLocator *pLocator, IWbemServices *pServices)
	{
		GPUInfoGenerator GPUGenerator;
		std::vector<GPUInfo> vectorGPUInfo = GPUGenerator.getCPUInfo(pLocator, pServices);

		return std::vector<DisplayDeviceInfo>();
	}
}