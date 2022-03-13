#include <iostream>
#include <locale>
#include <string>
#include "MachineInfo.h"

int main()
{
	std::wcout.imbue(std::locale("rus_rus.866"));
	std::wcin.imbue(std::locale("rus_rus.866"));

	mi::MachineInfo myMachine;

	myMachine.Init();
	
	myMachine.getInfo();

	return 0;
}