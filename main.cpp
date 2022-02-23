#include <iostream>
#include <conio.h>
#include <locale>
#include "MachineInfo.h"

using namespace std;

int main()
{
	wcout.imbue(locale("rus_rus.866"));
	wcin.imbue(locale("rus_rus.866"));

	mi::MachineInfo minf;
	wcout << minf.systemInfo.getName() << endl;
	wcout << minf.systemInfo.getModel() << endl;
	wcout << minf.systemInfo.getManufacturer() << endl;
	getch();
	return 0;
}