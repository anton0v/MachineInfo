#pragma once
#include "MachineInfo.h"

using namespace std;

namespace mi
{
	MachineInfo::MachineInfo()
	{
		WMIConnect();

		systemInfo.Init(pLocator, pServices);
		processorInfo.Init(pLocator, pServices);
	}

	void MachineInfo::WMIConnect()
	{
		HRESULT hres;

		hres = CoInitializeEx(0, COINIT_MULTITHREADED);
		if (FAILED(hres))
		{
			throw exception("Failed to initialize COM library.");
		}

		hres = CoInitializeSecurity(
			NULL,
			-1,
			NULL,
			NULL,
			RPC_C_AUTHN_LEVEL_DEFAULT,
			RPC_C_IMP_LEVEL_IMPERSONATE,
			NULL,
			EOAC_NONE,
			NULL
		);
		if (FAILED(hres))
		{
			CoUninitialize();
			throw exception("Failed to initialize security.");
		}

		hres = CoCreateInstance(
			CLSID_WbemLocator,
			0,
			CLSCTX_INPROC_SERVER,
			IID_IWbemLocator, (LPVOID *)&pLocator
		);
		if (FAILED(hres))
		{
			CoUninitialize();
			throw exception("Failed to create IWbemLocator object.");
		}

		hres = pLocator->ConnectServer(
			_bstr_t(L"ROOT\\CIMV2"),
			NULL,
			NULL,
			0,
			NULL,
			0,
			0,
			&pServices
		);
		if (FAILED(hres))
		{
			pLocator->Release();
			CoUninitialize();
			throw exception("Could not connect.");
		}

		hres = CoSetProxyBlanket(
			pServices,
			RPC_C_AUTHN_WINNT,
			RPC_C_AUTHZ_NONE,
			NULL,
			RPC_C_AUTHN_LEVEL_CALL,
			RPC_C_IMP_LEVEL_IMPERSONATE,
			NULL,
			EOAC_NONE
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw exception("Could not set proxy blanket.");
		}
	}
}