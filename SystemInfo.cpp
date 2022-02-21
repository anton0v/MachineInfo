#include <iostream>
#include <string>
#include <windows.h>
#include <VersionHelpers.h>
#include "SystemInfo.h"

using namespace std;

namespace mi
{
	typedef void(__stdcall *pRtlGetNtVersionNumbers)(
		LPDWORD major,
		LPDWORD minor,
		LPDWORD build
	);

	SystemInfo::SystemInfo()
	{
		unsigned long size = 256;
		char buff[256];
		GetComputerNameA(buff, &size);
		name = buff;
		pRtlGetNtVersionNumbers RtlGetNtVersionNumbers;
		DWORD dwMinorV, dwMajorV;
		DWORD dwBulid;
		
		if (!(RtlGetNtVersionNumbers = reinterpret_cast<pRtlGetNtVersionNumbers>(
			GetProcAddress(GetModuleHandle("ntdll.dll"), "RtlGetNtVersionNumbers")
			))) {
			cout << "Could not locate RtlGetNtVersionNumbers entry point.\n" << endl;
			
		}
		else
		{
			RtlGetNtVersionNumbers(&dwMajorV, &dwMinorV, &dwBulid);
			minorVersion = dwMinorV;
			majorVersion = dwMajorV;
			versionBuild = (DWORD)(LOWORD(dwBulid));
		}
	}
}

//other variants
//DWORD dwVersion;
//DWORD dwMinorV, dwMajorV;
//DWORD dwBulid;
//
//dwVersion = GetVersion();
//dwMinorV = (DWORD)(HIBYTE(LOWORD(dwVersion)));
//dwMajorV = (DWORD)(LOBYTE(LOWORD(dwVersion)));
//dwBulid = (DWORD)(HIWORD(dwVersion));
//version = dwVersion;
//version = hexadecimalToDecimal(to_string(version));

//OSVERSIONINFOEX versionInfo;
//ZeroMemory(&versionInfo, sizeof(OSVERSIONINFOEX));
//versionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
//GetVersionEx((LPOSVERSIONINFO)(&versionInfo));
//DWORD dwBuild = versionInfo.dwBuildNumber;
//DWORD dwMinorV = versionInfo.dwMinorVersion;
//DWORD dwMajorV = versionInfo.dwMajorVersion;