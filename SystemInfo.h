#pragma once
#include <string>

namespace mi
{
	class SystemInfo
	{
	public:
		SystemInfo();
		std::wstring getName() const { return name; };
		std::wstring getModel() const { return model; };
		std::wstring getManufacturer() const { return manufacturer; };
	private:
		std::wstring name;
		std::wstring model;
		std::wstring manufacturer;

		friend class SystemInfoGenerator;
	};
}