#pragma once
#include <string>
#include <comdef.h>
#include <Wbemidl.h>

using namespace std;

namespace mi
{
	class SystemInfo
	{
	public:
		SystemInfo();
		wstring getName() const { return name; };
		wstring getModel() const { return model; };
		wstring getManufacturer() const { return manufacturer; };
		string getVersion() const { return (to_string(majorVersion) + "." + to_string(minorVersion)); };
		int getVersionBuild() const { return versionBuild; };
	private:
		wstring name;
		wstring model;
		wstring manufacturer;
		int minorVersion;
		int majorVersion;
		int versionBuild;

		friend class SystemInfoGenerator;
	};
}