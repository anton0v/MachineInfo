#pragma once
#include <string>

using namespace std;

namespace mi
{
	class SystemInfo
	{
	public:
		SystemInfo();
		string getName() { return name; }
	private:
		string name;
	};
}