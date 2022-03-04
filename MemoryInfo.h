#pragma once
#include <string>

namespace mi
{
	class MemoryInfo
	{
	public:
		MemoryInfo();
		std::wstring getName() const { return name; };
		std::wstring getManufacturer() const { return manufacturer; };
		unsigned int getMemory() const { return memory; };
	private:
		std::wstring name;
		std::wstring manufacturer;
		unsigned int memory;

		friend class MemoryInfoGenerator;
	};
}