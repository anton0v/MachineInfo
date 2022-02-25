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
	getch();
	return 0;
}