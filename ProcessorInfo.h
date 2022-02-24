#pragma once
#include <string>
#include <comdef.h>
#include <Wbemidl.h>

using namespace std;

namespace mi
{
	class ProcessorInfo
	{
	public:
		ProcessorInfo();
		wstring getName() const { return name; };
		wstring getManufacturer() const { return manufacturer; };
		wstring getVersion() const { return version; };
		int getArchitecture() const { return architecture; };
		int getMaxClockSpeed() const { return maxClockSpeed; };
		int getDataWidth() const { return dataWidth; };
		int getFamily() const { return family; };
		int getCoresCount() const { return coresCount; };
	private:
		wstring name;
		wstring manufacturer;
		wstring version;
		int architecture;
		int maxClockSpeed;
		int dataWidth;
		int family;
		int coresCount;

		friend class ProcessorInfoGenerator;
	};
}