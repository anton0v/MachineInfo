#include <iostream>
#include <string>
#include <windows.h>
#include "SystemInfo.h"

using namespace std;

namespace mi
{
	SystemInfo::SystemInfo() :
		name(L""),
		model(L""),
		manufacturer(L"")
	{}
}

//other variant
//typedef void(__stdcall *pRtlGetNtVersionNumbers)(
//	LPDWORD major,
//	LPDWORD minor,
//	LPDWORD build
//	);
//
//pRtlGetNtVersionNumbers RtlGetNtVersionNumbers;
//DWORD dwMinorV, dwMajorV;
//DWORD dwBulid;
//
//if (!(RtlGetNtVersionNumbers = reinterpret_cast<pRtlGetNtVersionNumbers>(
//	GetProcAddress(GetModuleHandle("ntdll.dll"), "RtlGetNtVersionNumbers")
//	))) {
//	cout << "Could not locate RtlGetNtVersionNumbers entry point.\n" << endl;
//
//}
//else
//{
//	RtlGetNtVersionNumbers(&dwMajorV, &dwMinorV, &dwBulid);
//	minorVersion = dwMinorV;
//	majorVersion = dwMajorV;
//	versionBuild = (DWORD)(LOWORD(dwBulid));
//}