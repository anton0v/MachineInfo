#include "OperatingSystemInfo.h"

namespace mi
{
	OperatingSystemInfo::OperatingSystemInfo() :
		name(L""),
		manufacturer(L""),
		version(L""),
		language(OSLanguage::Unknown),
		bitDepth(0),
		majorVersion(0),
		minorVersion(0),
		build(0)
	{}

	std::wstring OperatingSystemInfo::getLanguage()
	{
		switch (language)
		{
		case OSLanguage::Arabian :
			return L"Arabian";
		case OSLanguage::Chinese :
			return L"Chinese";
		case OSLanguage::English :
			return L"English";
		case OSLanguage::Bulgarian :
			return L"Bulgarian";
		case OSLanguage::Catalan :
			return L"Catalan";
		case OSLanguage::Czech:
			return L"Czech";
		case OSLanguage::Danish :
			return L"Danish";
		case OSLanguage::German :
			return L"German";
		case OSLanguage::Greek :
			return L"Greek";
		case OSLanguage::EnglishUS :
			return L"EnglishUS";
		case OSLanguage::Spanish :
			return L"Spanish";
		case OSLanguage::Finnish :
			return L"Finnish";
		case OSLanguage::French :
			return L"French";
		case OSLanguage::Hebrew :
			return L"Hebrew";
		case OSLanguage::Hungarian :
			return L"Hungarian";
		case OSLanguage::Icelandic :
			return L"Icelandic";
		case OSLanguage::Italian :
			return L"Italian";
		case OSLanguage::Japanese :
			return L"Japanese";
		case OSLanguage::Korean :
			return L"Korean";
		case OSLanguage::Dutch :
			return L"Dutch";
		case OSLanguage::Norwegian:
			return L"Norwegian";
		case OSLanguage::Polish :
			return L"Polish";
		case OSLanguage::Portuguese :
			return L"Portuguese";
		case OSLanguage::Rhaeto :
			return L"Rhaeto";
		case OSLanguage::Romanian :
			return L"Romanian";
		case OSLanguage::Russian :
			return L"Russian";
		case OSLanguage::Croatian :
			return L"Croatian";
		case OSLanguage::Slovak:
			return L"Slovak";
		case OSLanguage::Albanian :
			return L"Albanian";
		case OSLanguage::Swedish :
			return L"Swedish";
		case OSLanguage::Thai :
			return L"Thai";
		case OSLanguage::Turkish :
			return L"Turkish";
		case OSLanguage::Urdu :
			return L"Urdu";
		case OSLanguage::Indonesian :
			return L"Indonesian";
		case OSLanguage::Ukrainian :
			return L"Ukrainian";
		case OSLanguage::Belarusian :
			return L"Belarusian";
		case OSLanguage::Slovenian :
			return L"Slovenian";
		case OSLanguage::Estonian :
			return L"Estonian";
		case OSLanguage::Latvian :
			return L"Latvian";
		case OSLanguage::Lithuanian :
			return L"Lithuanian";
		case OSLanguage::Persian :
			return L"Persian";
		case OSLanguage::Vietnamese :
			return L"Vietnamese";
		case OSLanguage::Basque :
			return L"Basque";
		case OSLanguage::Serbian :
			return L"Serbian";
		case OSLanguage::Macedonian :
			return L"Macedonian";
		case OSLanguage::Sutu :
			return L"Sutu";
		case OSLanguage::Tsonga :
			return L"Tsonga";
		case OSLanguage::Tswana :
			return L"Tswana";
		case OSLanguage::Xhosa :
			return L"Xhosa";
		case OSLanguage::Zulu :
			return L"Zulu";
		case OSLanguage::Afrikaans :
			return L"Afrikaans";
		case OSLanguage::Faeroese :
			return L"Faeroese";
		case OSLanguage::Hindi :
			return L"Hindi";
		case OSLanguage::Maltese :
			return L"Maltese";
		case OSLanguage::Scottish :
			return L"Scottish";
		case OSLanguage::Yiddish:
			return L"Yiddish";
		default:
			return L"Unknown";
		}
	}
}