#include <iostream>
#include "SystemInfo.h"

using namespace std;

int main()
{
	mi::SystemInfo sysinf;
	cout << sysinf.getName();
	return 0;
}