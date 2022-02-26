#include <iostream>
#include <conio.h>
#include <locale>
#include <string>
#include "MachineInfo.h"

int main()
{
	std::wcout.imbue(std::locale("rus_rus.866"));
	std::wcin.imbue(std::locale("rus_rus.866"));

	mi::MachineInfo myMachine;

	myMachine.Init();

	std::wcout << myMachine.operatingSystemInfo.getName() << std::endl;
	std::wcout << myMachine.operatingSystemInfo.getManufacturer() << std::endl;
	std::wcout << myMachine.operatingSystemInfo.getVersion() << std::endl;
	std::wcout << myMachine.operatingSystemInfo.getLanguage() << std::endl;
	std::wcout << myMachine.operatingSystemInfo.getMajorVersion() << std::endl;
	std::wcout << myMachine.operatingSystemInfo.getMinorVersion() << std::endl;
	std::wcout << myMachine.operatingSystemInfo.getBuild() << std::endl;
	std::wcout << myMachine.operatingSystemInfo.getBitDepth() << std::endl;

	getch();
	return 0;
}