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
		wstring getName() { return name; };
		wstring getManufacturer() { return manufacturer; };
		wstring getVersion() { return version; };
		int getArchitecture() { return architecture; };
		int getMaxClockSpeed() { return maxClockSpeed; };
		int getDataWidth() { return dataWidth; };
		int getFamily() { return family; };
		int getCoresCount() { return coresCount; };
	private:
		wstring name;
		wstring manufacturer;
		wstring version;
		int architecture;
		int maxClockSpeed;
		int dataWidth;
		int family;
		int coresCount;
		void Init(IWbemLocator *, IWbemServices *);

		friend class MachineInfo;
	};
}