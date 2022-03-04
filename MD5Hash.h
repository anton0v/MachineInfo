#pragma once
#include <string>

namespace mi
{
	std::string md5(std::wstring input);

	int rotateLeft(int x, int n);
	int F(int x, int y, int z);
	int G(int x, int y, int z);
	int H(int x, int y, int z);
	int I(int x, int y, int z);
}