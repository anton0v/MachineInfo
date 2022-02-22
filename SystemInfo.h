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
		wstring getName() { return name; };
		string getVersion() { return (to_string(majorVersion) + "." + to_string(minorVersion)); };
		int getVersionBuild() { return versionBuild; };
	private:
		wstring name;
		int minorVersion;
		int majorVersion;
		int versionBuild;
		void Init(IWbemLocator *, IWbemServices *);

		friend class MachineInfo;
	};
}