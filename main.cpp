#include <iostream>
#include <conio.h>
#include <locale>
#include <string>
#include <vector>
#include "MachineInfo.h"

int main()
{
	std::wcout.imbue(std::locale("rus_rus.866"));
	std::wcin.imbue(std::locale("rus_rus.866"));

	mi::MachineInfo myMachine;

	myMachine.Init();

	std::wcout << myMachine.monitorsInfo.at(0).getAvailability() << std::endl;
	std::wcout << myMachine.monitorsInfo.at(1).getAvailability() << std::endl;

	getch();
	return 0;
}