#include <iostream>
#include <conio.h>
#include <locale>
#include "MachineInfo.h"

using namespace std;

int main()
{
	wcout.imbue(locale("rus_rus.866"));
	wcin.imbue(locale("rus_rus.866"));

	mi::MachineInfo myMachine;
	wcout << myMachine.systemInfo.getManufacturer() << endl;
	wcout << myMachine.processorInfo.getManufacturer() << endl;
	getch();
	return 0;
}