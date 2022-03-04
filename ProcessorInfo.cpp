#include "ProcessorInfo.h"

namespace mi
{
	mi::ProcessorInfo::ProcessorInfo() :
		name(L""),
		manufacturer(L""),
		version(L""),
		architecture(CPUArchitecture::UNKNOWN),
		maxClockSpeed(0),
		currentClockSpeed(0),
		bitDepth(0),
		family(CPUFamily::Unknown),
		coresCount(0)
	{}

	std::wstring ProcessorInfo::getArchitecture() const
	{
		switch (architecture)
		{
		case CPUArchitecture::X861 :
			return L"x861";
		case CPUArchitecture::MIPS_2 : 
			return L"MIPS_2";
		case CPUArchitecture::Alpha_3 :
			return L"Alpha 3";
		case CPUArchitecture::POWERPC_6 :
			return L"PowerPC 6";
		case CPUArchitecture::IA64 :
			return L"ia64";
		case CPUArchitecture::X64 : 
			return L"x64";
		case CPUArchitecture::UNKNOWN :
			return L"Unknown";
		default :
			return L"Unknown";
		}
	}

	std::wstring ProcessorInfo::getFamily() const
	{
		switch (family)
		{
		case CPUFamily::Other :
			return L"Other";
		case CPUFamily::Unknown :
			return L"Unknown";
		case CPUFamily::_8086 :
			return L"_8086";
		case CPUFamily::_80286 :
			return L"80286";
		case CPUFamily::_80386 :
			return L"80386";
		case CPUFamily::_80486 :
			return L"80486";
		case CPUFamily::_8087 :
			return L"8087";
		case CPUFamily::_80287 :
			return L"80287";
		case CPUFamily::_80387 :
			return L"80387";
		case CPUFamily::_80487 :
			return L"80487";
		case CPUFamily::Pentium_R_brand :
			return L"Pentium_R_brand";
		case CPUFamily::Pentium_R_Pro :
			return L"Pentium_R_Pro";
		case CPUFamily::Pentium_R_II :
			return L"Pentium_R_II";
		case CPUFamily::Pentium_R__processor_with_MMX_TM_technology :
			return L"Pentium_R__processor_with_MMX_TM_technology";
		case CPUFamily::Celeron_TM :
			return L"Celeron_TM";
		case CPUFamily::Pentium_R_II_Xeon_TM :
			return L"Pentium_R_II_Xeon_TM";
		case CPUFamily::Pentium_R_III :
			return L"Pentium_R_III";
		case CPUFamily::M1_Family :
			return L"M1_Family";
		case CPUFamily::M2_Family :
			return L"M2_Family";
		case CPUFamily::Intel_R_Celeron_R_M_processor :
			return L"Intel_R_Celeron_R_M_processor";
		case CPUFamily::Intel_R_Pentium_R_4_HT_processor :
			return L"Intel_R_Pentium_R_4_HT_processor";
		case CPUFamily::K5_Family :
			return L"K5_Family";
		case CPUFamily::K6_Family :
			return L"K6_Family";
		case CPUFamily::K6_2 :
			return L"K6_2";
		case CPUFamily::K6_3 :
			return L"K6_3";
		case CPUFamily::AMD_Athlon_TM_Processor_Family :
			return L"AMD_Athlon_TM_Processor_Family";
		case CPUFamily::AMD_R_Duron_TM_Processor :
			return L"AMD_R_Duron_TM_Processor";
		case CPUFamily::AMD29000_Family :
			return L"AMD29000_Family";
		case CPUFamily::K6_2_plus :
			return L"K6_2_plus";
		case CPUFamily::Power_PC_Family :
			return L"Power_PC_Family";
		case CPUFamily::Power_PC_601 :
			return L"Power_PC_601";
		case CPUFamily::Power_PC_603 :
			return L"Power_PC_603";
		case CPUFamily::Power_PC_603_plus :
			return L"Power_PC_603_plus";
		case CPUFamily::Power_PC_604 :
			return L"Power_PC_604";
		case CPUFamily::Power_PC_620 :
			return L"Power_PC_620";
		case CPUFamily::Power_PC_X704 :
			return L"Power_PC_X704";
		case CPUFamily::Power_PC_750 :
			return L"Power_PC_750";
		case CPUFamily::Intel_R_Core_TM_Duo_processor :
			return L"Intel_R_Core_TM_Duo_processor";
		case CPUFamily::Intel_R_Core_TM_Duo_mobile_processor :
			return L"Intel_R_Core_TM_Duo_mobile_processor";
		case CPUFamily::Intel_R_Core_TM_Solo_mobile_processor :
			return L"Intel_R_Core_TM_Solo_mobile_processor";
		case CPUFamily::Intel_R_Atom_TM_processor :
			return L"Intel_R_Atom_TM_processor";
		case CPUFamily::Alpha_Family :
			return L"Alpha_Family";
		case CPUFamily::Alpha_21064 :
			return L"Alpha_21064";
		case CPUFamily::Alpha_21066 :
			return L"Alpha_21066";
		case CPUFamily::Alpha_21164 :
			return L"Alpha_21164";
		case CPUFamily::Alpha_21164PC :
			return L"Alpha_21164PC";
		case CPUFamily::Alpha_21164a :
			return L"Alpha_21164a";
		case CPUFamily::Alpha_21264 :
			return L"Alpha_21264";
		case CPUFamily::Alpha_21364 :
			return L"Alpha_21364";
		case CPUFamily::AMD_Turion_TM_II_Ultra_Dual_Core_Mobile_M_Processor_Family :
			return L"AMD_Turion_TM_II_Ultra_Dual_Core_Mobile_M_Processor_Family";
		case CPUFamily::AMD_Turion_TM_II_Dual_Core_Mobile_M_Processor_Family :
			return L"AMD_Turion_TM_II_Dual_Core_Mobile_M_Processor_Family";
		case CPUFamily::AMD_Athlon_TM_II_Dual_Core_Mobile_M_Processor_Family :
			return L"AMD_Athlon_TM_II_Dual_Core_Mobile_M_Processor_Family";
		case CPUFamily::AMD_Opteron_TM_6100_Series_Processor :
			return L"AMD_Opteron_TM_6100_Series_Processor";
		case CPUFamily::AMD_Opteron_TM_4100_Series_Processor :
			return L"AMD_Opteron_TM_4100_Series_Processor";
		case CPUFamily::MIPS_Family :
			return L"MIPS_Family";
		case CPUFamily::MIPS_R4000 :
			return L"MIPS_R4000";
		case CPUFamily::MIPS_R4200 :
			return L"MIPS_R4200";
		case CPUFamily::MIPS_R4400 :
			return L"MIPS_R4400";
		case CPUFamily::MIPS_R4600 :
			return L"MIPS_R4600";
		case CPUFamily::MIPS_R10000 :
			return L"MIPS_R10000";
		case CPUFamily::SPARC_Family :
			return L"SPARC_Family";
		case CPUFamily::SuperSPARC :
			return L"SuperSPARC";
		case CPUFamily::microSPARC_II :
			return L"microSPARC_II";
		case CPUFamily::microSPARC_IIep :
			return L"microSPARC_IIep";
		case CPUFamily::UltraSPARC :
			return L"UltraSPARC";
		case CPUFamily::UltraSPARC_II :
			return L"UltraSPARC_II";
		case CPUFamily::UltraSPARC_IIi :
			return L"UltraSPARC_IIi";
		case CPUFamily::UltraSPARC_III :
			return L"UltraSPARC_III";
		case CPUFamily::UltraSPARC_IIIi :
			return L"UltraSPARC_IIIi";
		case CPUFamily::_68040 :
			return L"68040";
		case CPUFamily::_68xxx_Family :
			return L"68xxx_Family";
		case CPUFamily::_68000 :
			return L"68000";
		case CPUFamily::_68010 :
			return L"68010";
		case CPUFamily::_68020 :
			return L"68020";
		case CPUFamily::_68030 :
			return L"68030";
		case CPUFamily::Hobbit_Family :
			return L"Hobbit_Family";
		case CPUFamily::Crusoe_TM_TM5000_Family :
			return L"Crusoe_TM_TM5000_Family";
		case CPUFamily::Crusoe_TM_TM3000_Family :
			return L"Crusoe_TM_TM3000_Family";
		case CPUFamily::Efficeon_TM_TM8000_Family :
			return L"Efficeon_TM_TM8000_Family";
		case CPUFamily::Weitek :
			return L"Weitek";
		case CPUFamily::Itanium_TM_Processor :
			return L"Itanium_TM_Processor";
		case CPUFamily::AMD_Athlon_TM_64_Processor_Family :
			return L"AMD_Athlon_TM_64_Processor_Family";
		case CPUFamily::AMD_Opteron_TM_Processor_Family :
			return L"AMD_Opteron_TM_Processor_Family";
		case CPUFamily::AMD_Sempron_TM_Processor_Family :
			return L"AMD_Sempron_TM_Processor_Family";
		case CPUFamily::AMD_Turion_TM_64_Mobile_Technology :
			return L"AMD_Turion_TM_64_Mobile_Technology";
		case CPUFamily::Dual_Core_AMD_Opteron_TM_Processor_Family :
			return L"Dual_Core_AMD_Opteron_TM_Processor_Family";
		case CPUFamily::AMD_Athlon_TM_64_X2_Dual_Core_Processor_Family :
			return L"AMD_Athlon_TM_64_X2_Dual_Core_Processor_Family";
		case CPUFamily::AMD_Turion_TM_64_X2_Mobile_Technology :
			return L"AMD_Turion_TM_64_X2_Mobile_Technology";
		case CPUFamily::Quad_Core_AMD_Opteron_TM_Processor_Family :
			return L"Quad_Core_AMD_Opteron_TM_Processor_Family";
		case CPUFamily::Third_Generation_AMD_Opteron_TM_Processor_Family :
			return L"Third_Generation_AMD_Opteron_TM_Processor_Family";
		case CPUFamily::AMD_Phenom_TM_FX_Quad_Core_Processor_Family :
			return L"AMD_Phenom_TM_FX_Quad_Core_Processor_Family";
		case CPUFamily::AMD_Phenom_TM_X4_Quad_Core_Processor_Family :
			return L"AMD_Phenom_TM_X4_Quad_Core_Processor_Family";
		case CPUFamily::AMD_Phenom_TM_X2_Dual_Core_Processor_Family :
			return L"AMD_Phenom_TM_X2_Dual_Core_Processor_Family";
		case CPUFamily::AMD_Athlon_TM_X2_Dual_Core_Processor_Family :
			return L"AMD_Athlon_TM_X2_Dual_Core_Processor_Family";
		case CPUFamily::PA_RISC_Family :
			return L"PA_RISC_Family";
		case CPUFamily::PA_RISC_8500 :
			return L"PA_RISC_8500";
		case CPUFamily::PA_RISC_8000 :
			return L"PA_RISC_8000";
		case CPUFamily::PA_RISC_7300LC :
			return L"PA_RISC_7300LC";
		case CPUFamily::PA_RISC_7200 :
			return L"PA_RISC_7200";
		case CPUFamily::PA_RISC_7100LC :
			return L"PA_RISC_7100LC";
		case CPUFamily::PA_RISC_7100 :
			return L"PA_RISC_7100";
		case CPUFamily::V30_Family :
			return L"V30_Family";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor_3200_Series :
			return L"Quad_Core_Intel_R_Xeon_R_processor_3200_Series";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_3000_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_3000_Series";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor_5300_Series :
			return L"Quad_Core_Intel_R_Xeon_R_processor_5300_Series";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_5100_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_5100_Series";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_5000_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_5000_Series";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_LV :
			return L"Dual_Core_Intel_R_Xeon_R_processor_LV";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_ULV :
			return L"Dual_Core_Intel_R_Xeon_R_processor_ULV";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_7100_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_7100_Series";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor_5400_Series :
			return L"Quad_Core_Intel_R_Xeon_R_processor_5400_Series";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor :
			return L"Quad_Core_Intel_R_Xeon_R_processor";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_5200_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_5200_Series";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_7200_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_7200_Series";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor_7300_Series :
			return L"Quad_Core_Intel_R_Xeon_R_processor_7300_Series";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor_7400_Series :
			return L"Quad_Core_Intel_R_Xeon_R_processor_7400_Series";
		case CPUFamily::Multi_Core_Intel_R_Xeon_R_processor_7400_Series :
			return L"Multi_Core_Intel_R_Xeon_R_processor_7400_Series";
		case CPUFamily::Pentium_R_III_Xeon_TM :
			return L"Pentium_R_III_Xeon_TM";
		case CPUFamily::Pentium_R_III_Processor_with_Intel_R_SpeedStep_TM_Technology :
			return L"Pentium_R_III_Processor_with_Intel_R_SpeedStep_TM_Technology";
		case CPUFamily::Pentium_R_4 :
			return L"Pentium_R_4";
		case CPUFamily::Intel_R_Xeon_TM :
			return L"Intel_R_Xeon_TM";
		case CPUFamily::AS400_Family :
			return L"AS400_Family";
		case CPUFamily::Intel_R_Xeon_TM_processor_MP :
			return L"Intel_R_Xeon_TM_processor_MP";
		case CPUFamily::AMD_Athlon_TM_XP_Family :
			return L"AMD_Athlon_TM_XP_Family";
		case CPUFamily::AMD_Athlon_TM_MP_Family :
			return L"AMD_Athlon_TM_MP_Family";
		case CPUFamily::Intel_R_Itanium_R_2 :
			return L"Intel_R_Itanium_R_2";
		case CPUFamily::Intel_R_Pentium_R_M_processor :
			return L"Intel_R_Pentium_R_M_processor";
		case CPUFamily::Intel_R_Celeron_R_D_processor :
			return L"Intel_R_Celeron_R_D_processor";
		case CPUFamily::Intel_R_Pentium_R_D_processor :
			return L"Intel_R_Pentium_R_D_processor";
		case CPUFamily::Intel_R_Pentium_R_Processor_Extreme_Edition :
			return L"Intel_R_Pentium_R_Processor_Extreme_Edition";
		case CPUFamily::Intel_R_Core_TM_Solo_Processor :
			return L"Intel_R_Core_TM_Solo_Processor";
		case CPUFamily::K7 :
			return L"K7";
		case CPUFamily::Intel_R_Core_TM_2_Duo_Processor :
			return L"Intel_R_Core_TM_2_Duo_Processor";
		case CPUFamily::Intel_R_Core_TM_2_Solo_processor :
			return L"Intel_R_Core_TM_2_Solo_processor";
		case CPUFamily::Intel_R_Core_TM_2_Extreme_processor :
			return L"Intel_R_Core_TM_2_Extreme_processor";
		case CPUFamily::Intel_R_Core_TM_2_Quad_processor :
			return L"Intel_R_Core_TM_2_Quad_processor";
		case CPUFamily::Intel_R_Core_TM_2_Extreme_mobile_processor :
			return L"Intel_R_Core_TM_2_Extreme_mobile_processo";
		case CPUFamily::Intel_R_Core_TM_2_Duo_mobile_processor :
			return L"Intel_R_Core_TM_2_Duo_mobile_processor";
		case CPUFamily::Intel_R_Core_TM_2_Solo_mobile_processor :
			return L"Intel_R_Core_TM_2_Solo_mobile_processor";
		case CPUFamily::Intel_R_Core_TM_i7_processor :
			return L"Intel_R_Core_TM_i7_processor";
		case CPUFamily::Dual_Core_Intel_R_Celeron_R_Processor :
			return L"Dual_Core_Intel_R_Celeron_R_Processor";
		case CPUFamily::S_390_and_zSeries_Family :
			return L"S_390_and_zSeries_Family";
		case CPUFamily::ESA_390_G4 :
			return L"ESA_390_G4";
		case CPUFamily::ESA_390_G5 :
			return L"ESA_390_G5";
		case CPUFamily::ESA_390_G6 :
			return L"ESA_390_G6";
		case CPUFamily::z_Architectur_base :
			return L"z_Architectur_base";
		case CPUFamily::Intel_R_Core_TM_i5_processor :
			return L"Intel_R_Core_TM_i5_processor";
		case CPUFamily::Intel_R_Core_TM_i3_processor :
			return L"Intel_R_Core_TM_i3_processor";
		case CPUFamily::Intel_R_Core_TM_i9_processor :
			return L"Intel_R_Core_TM_i9_processor";
		case CPUFamily::VIA_C7_TM_M_Processor_Family :
			return L"VIA_C7_TM_M_Processor_Family";
		case CPUFamily::VIA_C7_TM_D_Processor_Family :
			return L"VIA_C7_TM_D_Processor_Family";
		case CPUFamily::VIA_C7_TM_Processor_Family :
			return L"VIA_C7_TM_Processor_Family";
		case CPUFamily::VIA_Eden_TM_Processor_Family :
			return L"VIA_Eden_TM_Processor_Family";
		case CPUFamily::Multi_Core_Intel_R_Xeon_R_processor :
			return L"Multi_Core_Intel_R_Xeon_R_processor";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_3xxx_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_3xxx_Series";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor_3xxx_Series :
			return L"Quad_Core_Intel_R_Xeon_R_processor_3xxx_Series";
		case CPUFamily::VIA_Nano_TM_Processor_Family :
			return L"VIA_Nano_TM_Processor_Family";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_5xxx_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_5xxx_Series";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor_5xxx_Series :
			return L"Quad_Core_Intel_R_Xeon_R_processor_5xxx_Series";
		case CPUFamily::Dual_Core_Intel_R_Xeon_R_processor_7xxx_Series :
			return L"Dual_Core_Intel_R_Xeon_R_processor_7xxx_Series";
		case CPUFamily::Quad_Core_Intel_R_Xeon_R_processor_7xxx_Series :
			return L"Quad_Core_Intel_R_Xeon_R_processor_7xxx_Series";
		case CPUFamily::Multi_Core_Intel_R_Xeon_R_processor_7xxx_Series :
			return L"Multi_Core_Intel_R_Xeon_R_processor_7xxx_Series";
		case CPUFamily::Multi_Core_Intel_R_Xeon_R_processor_3400_Series :
			return L"Multi_Core_Intel_R_Xeon_R_processor_3400_Series";
		case CPUFamily::Embedded_AMD_Opteron_TM_Quad_Core_Processor_Family :
			return L"Embedded_AMD_Opteron_TM_Quad_Core_Processor_Family";
		case CPUFamily::AMD_Phenom_TM_Triple_Core_Processor_Family :
			return L"AMD_Phenom_TM_Triple_Core_Processor_Family";
		case CPUFamily::AMD_Turion_TM_Ultra_Dual_Core_Mobile_Processor_Family :
			return L"AMD_Turion_TM_Ultra_Dual_Core_Mobile_Processor_Family";
		case CPUFamily::AMD_Turion_TM_Dual_Core_Mobile_Processor_Family :
			return L"AMD_Turion_TM_Dual_Core_Mobile_Processor_Family";
		case CPUFamily::AMD_Athlon_TM_Dual_Core_Processor_Family :
			return L"AMD_Athlon_TM_Dual_Core_Processor_Family";
		case CPUFamily::AMD_Sempron_TM_SI_Processor_Family :
			return L"AMD_Sempron_TM_SI_Processor_Family";
		case CPUFamily::AMD_Phenom_TM_II_Processor_Family :
			return L"AMD_Phenom_TM_II_Processor_Famil";
		case CPUFamily::AMD_Athlon_TM_II_Processor_Family :
			return L"AMD_Athlon_TM_II_Processor_Family";
		case CPUFamily::Six_Core_AMD_Opteron_TM_Processor_Family :
			return L"Six_Core_AMD_Opteron_TM_Processor_Family";
		case CPUFamily::AMD_Sempron_TM_M_Processor_Family :
			return L"AMD_Sempron_TM_M_Processor_Family";
		case CPUFamily::i860 :
			return L"i860";
		case CPUFamily::i960 :
			return L"i960";
		case CPUFamily::Reserved_SMBIOS_Extension :
			return L"Reserved_SMBIOS_Extension";
		case CPUFamily::Reserved_Un_initialized_Flash_Content_Lo :
			return L"Reserved_Un_initialized_Flash_Content_L";
		case CPUFamily::SH_3 :
			return L"SH_3";
		case CPUFamily::SH_4 :
			return L"SH_4";
		case CPUFamily::ARM :
			return L"ARM";
		case CPUFamily::StrongARM :
			return L"StrongARM";
		case CPUFamily::_6x86 :
			return L"6x86";
		case CPUFamily::MediaGX :
			return L"MediaGX";
		case CPUFamily::MII :
			return L"MII";
		case CPUFamily::WinChip :
			return L"WinChip";
		case CPUFamily::DSP :
			return L"DSP";
		case CPUFamily::Video_Processor :
			return L"Video_Processor";
		case CPUFamily::Reserved_For_Future_Special_Purpose_Assignment :
			return L"Reserved_For_Future_Special_Purpose_Assignment";
		case CPUFamily::Reserved_Un_initialized_Flash_Content_Hi :
			return L"Reserved_Un_initialized_Flash_Content_Hi";
		default : 
			return L"Unknown";
		}
	}
}