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
	myMachine.processorInfo.getArchitecture();
	wcout << myMachine.processorInfo.getName() << endl;
	wcout << myMachine.processorInfo.getManufacturer() << endl;
	wcout << myMachine.processorInfo.getVersion() << endl;
	cout << myMachine.processorInfo.getArchitecture() << endl;
	cout << myMachine.processorInfo.getMaxClockSpeed() << endl;
	cout << myMachine.processorInfo.getDataWidth() << endl;
	cout << myMachine.processorInfo.getFamily() << endl;
	cout << myMachine.processorInfo.getCoresCount() << endl;
	getch();
	return 0;
}