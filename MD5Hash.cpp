#include <windows.h>
#include <sstream>
#include "MD5Hash.h"

namespace mi
{
	std::string md5(std::wstring input)
	{
		const BYTE *pBytes = reinterpret_cast<const BYTE*>(input.c_str());
		int inputSize = input.size() * 2;
		std::string bytes = "";

		for (int i = 0; i < inputSize; i++)
		{
			bytes.push_back(*pBytes++);
		}
		bytes.push_back(128);

		while(bytes.size() % 64 != 56)
			bytes.push_back(0);

		size_t bytesSize = bytes.size();
		for (int i = 0; i < 8; i++)
		{
			bytes.push_back((unsigned char)(bytesSize >> (i * 8)));
		}

		int constantsArray[64] = {
			0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
			0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
			0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
			0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
			0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
			0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
			0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
			0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
			0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
			0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
			0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
			0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
			0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
			0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
			0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
			0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
		};

		int a0 = 0x67452301;
		int b0 = 0xefcdab89;
		int c0 = 0x98badcfe;
		int d0 = 0x10325476;
		int a = a0, aa = a0;
		int b = b0, bb = b0;
		int c = c0, cc = c0;
		int d = d0, dd = d0;

		//Round 1
		int k = 1;
		for (int i = 0; i < 4; i++)
		{
			a = b + rotateLeft(a + F(b, c, d) + bytes[i] + constantsArray[k++], 7);
			d = a + rotateLeft(d + F(a, b, c) + bytes[i + 1] + constantsArray[k++], 12);
			c = d + rotateLeft(c + F(d, a, b) + bytes[i + 2] + constantsArray[k++], 17);
			b = c + rotateLeft(b + F(c, d, a) + bytes[i + 3] + constantsArray[k++], 22);
		}

		//Round 2
		int j = 1;
		for (int i = 0; i < 4; i++)
		{
			a = b + rotateLeft(a + G(b, c, d) + bytes[j] + constantsArray[k++], 5);
			j = (j + 5) % 16;
			d = a + rotateLeft(d + G(a, b, c) + bytes[j] + constantsArray[k++], 9);
			j = (j + 5) % 16;
			c = d + rotateLeft(c + G(d, a, b) + bytes[j] + constantsArray[k++], 14);
			j = (j + 5) % 16;
			b = c + rotateLeft(b + G(c, d, a) + bytes[j] + constantsArray[k++], 20);
			j = (j + 5) % 16;
		}

		//Round 3
		j = 5;
		for (int i = 0; i < 4; i++)
		{
			a = b + rotateLeft(a + H(b, c, d) + bytes[j] + constantsArray[k++], 4);
			j = (j + 3) % 16;
			d = a + rotateLeft(d + H(a, b, c) + bytes[j] + constantsArray[k++], 11);
			j = (j + 3) % 16;
			c = d + rotateLeft(c + H(d, a, b) + bytes[j] + constantsArray[k++], 16);
			j = (j + 3) % 16;
			b = c + rotateLeft(b + H(c, d, a) + bytes[j] + constantsArray[k++], 23);
			j = (j + 3) % 16;
		}

		//Round 4
		j = 0;
		for (int i = 0; i < 4; i++)
		{
			a = b + rotateLeft(a + I(b, c, d) + bytes[j] + constantsArray[k++], 6);
			j = (j + 7) % 16;
			d = a + rotateLeft(d + I(a, b, c) + bytes[j] + constantsArray[k++], 10);
			j = (j + 7) % 16;
			c = d + rotateLeft(c + I(d, a, b) + bytes[j] + constantsArray[k++], 15);
			j = (j + 7) % 16;
			b = c + rotateLeft(b + I(c, d, a) + bytes[j] + constantsArray[k++], 21);
			j = (j + 7) % 16;
		}

		a += aa;
		b += bb;
		c += cc;
		d += dd;

		std::string res = "{";
		std::stringstream sstream;
		sstream << "{";
		sstream << std::hex << a;
		sstream << "-";
		sstream << std::hex << b;
		sstream << "-";
		sstream << std::hex << c;
		sstream << "-";
		sstream << std::hex << d;

		sstream << "}";

		return sstream.str();
	}

	int rotateLeft(int x, int n)
	{
		return (x << n) | (x >> (32 - n));
	}

	int F(int x, int y, int z)
	{
		return (x & y) | (~x & z);
	}

	int G(int x, int y, int z)
	{
		return (x & z) | (y & ~z);
	}

	int H(int x, int y, int z)
	{
		return x ^ y ^ z;
	}

	int I(int x, int y, int z)
	{
		return y ^ (~z | x);
	}

}