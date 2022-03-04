#include "DriveInfoGenerator.h"

namespace mi
{
	std::vector<DriveInfo> DriveInfoGenerator::getDriveInfo(IWbemLocator *pLocator, IWbemServices *pServices)
	{
		HRESULT hres;

		IEnumWbemClassObject* pEnumerator = NULL;
		hres = pServices->ExecQuery(
			bstr_t("WQL"),
			bstr_t("SELECT * FROM Win32_LogicalDisk"),
			WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
			NULL,
			&pEnumerator
		);

		if (FAILED(hres))
		{
			pServices->Release();
			pLocator->Release();
			CoUninitialize();
			throw std::exception("Query for drive failed.");
		}

		IWbemClassObject *pclsObj = NULL;
		ULONG uReturn = 0;
		DriveInfo drive;
		std::vector<DriveInfo> vectorDrive;

		while (pEnumerator)
		{
			HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
				&pclsObj, &uReturn);

			if (0 == uReturn)
			{
				break;
			}

			VARIANT vtProp;

			hr = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
			drive.name = vtProp.bstrVal;

			hr = pclsObj->Get(L"DriveType", 0, &vtProp, 0, 0);
			drive.type = static_cast<DriveInfo::DriveType>(vtProp.intVal);

			if (drive.type == DriveInfo::DriveType::Local_Disk)
			{
				std::wstring fileSystem;
				float totalSpace;
				float freeSpace;

				hr = pclsObj->Get(L"FileSystem", 0, &vtProp, 0, 0);
				drive.fileSystem = vtProp.bstrVal;

				hr = pclsObj->Get(L"Size", 0, &vtProp, 0, 0);
				drive.totalSpace = std::stoull(vtProp.bstrVal) / 1024 / 1024 / 1024;

				hr = pclsObj->Get(L"FreeSpace", 0, &vtProp, 0, 0);
				drive.freeSpace = std::stoull(vtProp.bstrVal) / 1024 / 1024 / 1024;
			}

			vectorDrive.push_back(drive);

			pclsObj->Release();
		}
		return vectorDrive;
	}
}