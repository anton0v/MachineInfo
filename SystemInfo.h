#pragma once
#include <string>

using namespace std;

namespace mi
{
	class SystemInfo
	{
	public:
		SystemInfo();
		string getName() { return name; };
		string getVersion() { return (to_string(majorVersion) + "." + to_string(minorVersion)); };
		int getVersionBuild() { return versionBuild; };
	private:
		string name;
		int minorVersion;
		int majorVersion;
		int versionBuild;

		friend class MachineInfo;
	};
}