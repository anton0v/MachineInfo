#include <iostream>
#include <conio.h>
#include <locale>
#include <string>
#include <vector>
#include "MachineInfo.h"
#include "MD5Hash.h"

int main()
{
	std::wcout.imbue(std::locale("rus_rus.866"));
	std::wcin.imbue(std::locale("rus_rus.866"));

	std::cout << mi::md5(L"Собака") << std::endl;
	std::cout << mi::md5(L"Собака") << std::endl;

	getch();
	return 0;
}