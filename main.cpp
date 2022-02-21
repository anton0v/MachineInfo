#include <iostream>
#include "SystemInfo.h"

using namespace std;

int main()
{
	mi::SystemInfo sysinf;
	cout << sysinf.getName() << endl;
	cout << sysinf.getVersion() << endl;
	cout << sysinf.getVersionBuild() << endl;
	return 0;
}