#pragma once
#include <string>

namespace mi
{
	class OperatingSystemInfo
	{
	public:
		OperatingSystemInfo();
		
		std::wstring getName() const { return name; };
		std::wstring getManufacturer() const { return manufacturer; };
		std::wstring getVersion() const { return version; };
		std::wstring getLanguage() const;
		int getBitDepth() const { return bitDepth; };
		int getMajorVersion() const { return majorVersion; };
		int getMinorVersion() const { return minorVersion; };
		int getBuild() const { return build; };

		enum class OSLanguage
		{
			Unknown = 0,
			Arabian = 1,
			Chinese = 4,
			English = 9,
			Bulgarian = 1026,
			Catalan = 1027,
			Czech = 1029,
			Danish = 1030,
			German = 1031,
			Greek = 1032,
			EnglishUS = 1033,
			Spanish = 1034,
			Finnish = 1035,
			French = 1036,
			Hebrew = 1037,
			Hungarian = 1038,
			Icelandic = 1039,
			Italian = 1040,
			Japanese = 1041,
			Korean = 1042,
			Dutch = 1043,
			Norwegian = 1044,
			Polish = 1045,
			Portuguese = 1046,
			Rhaeto = 1047,
			Romanian = 1048,
			Russian = 1049,
			Croatian = 1050,
			Slovak = 1051,
			Albanian = 1052,
			Swedish = 1053,
			Thai = 1054,
			Turkish = 1055,
			Urdu = 1056,
			Indonesian = 1057,
			Ukrainian = 1058,
			Belarusian = 1059,
			Slovenian = 1060,
			Estonian = 1061,
			Latvian = 1062,
			Lithuanian = 1063,
			Persian = 1065,
			Vietnamese = 1066,
			Basque = 1069,
			Serbian = 1070,
			Macedonian = 1071,
			Sutu = 1072,
			Tsonga = 1073,
			Tswana = 1074,
			Xhosa = 1076,
			Zulu = 1077,
			Afrikaans = 1078,
			Faeroese = 1080,
			Hindi = 1081,
			Maltese = 1082,
			Scottish = 1084,
			Yiddish = 1085
		};

	private:
		std::wstring name;
		std::wstring manufacturer;
		std::wstring version;
		OSLanguage language;
		int bitDepth;
		int majorVersion;
		int minorVersion;
		int build;

		friend class OperatingSystemInfoGenerator;
	};
}