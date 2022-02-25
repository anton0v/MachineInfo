#pragma once
#include <string>

namespace mi
{
	class ProcessorInfo
	{
	public:
		ProcessorInfo();
		std::wstring getName() const { return name; };
		std::wstring getManufacturer() const { return manufacturer; };
		std::wstring getVersion() const { return version; };
		int getArchitecture() const { return architecture; };
		int getMaxClockSpeed() const { return maxClockSpeed; };
		int getDataWidth() const { return dataWidth; };
		int getFamily() const { return family; };
		int getCoresCount() const { return coresCount; };
	private:
		std::wstring name;
		std::wstring manufacturer;
		std::wstring version;
		int architecture;
		int maxClockSpeed;
		int dataWidth;
		int family;
		int coresCount;

		friend class ProcessorInfoGenerator;
	};
}