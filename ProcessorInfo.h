#pragma once
#include <string>

namespace mi
{
	class ProcessorInfo
	{
	public:
		ProcessorInfo();
		std::wstring getName() const { return name; }
		std::wstring getManufacturer() const { return manufacturer; }
		std::wstring getVersion() const { return version; }
		std::wstring getArchitecture() const;
		std::wstring getFamily() const;
		int getMaxClockSpeed() const { return maxClockSpeed; }
		int getCurrentClockSpeed() const { return currentClockSpeed; }
		int getDataWidth() const { return bitDepth; }
		int getCoresCount() const { return coresCount; }
		int getIntFamily() const { return static_cast<int>(family); }
		int getIntArchitecure() const { return static_cast<int>(architecture); }

		enum class CPUArchitecture
		{
			X861,
			MIPS_2,
			Alpha_3,
			POWERPC_6,
			IA64 = 6,
			X64 = 9,
			UNKNOWN
		};

		enum class CPUFamily
		{
			Other = 1,
			Unknown = 2,
			_8086 = 3,
			_80286 = 4,
			_80386 = 5,
			_80486 = 6,
			_8087 = 7,
			_80287 = 8,
			_80387 = 9,
			_80487 = 10,
			Pentium_R_brand = 11,
			Pentium_R_Pro = 12,
			Pentium_R_II = 13,
			Pentium_R__processor_with_MMX_TM_technology = 14,
			Celeron_TM = 15,
			Pentium_R_II_Xeon_TM = 16,
			Pentium_R_III = 17,
			M1_Family = 18,
			M2_Family = 19,
			Intel_R_Celeron_R_M_processor = 20,
			Intel_R_Pentium_R_4_HT_processor = 21,
			K5_Family = 24,
			K6_Family = 25,
			K6_2 = 26,
			K6_3 = 27,
			AMD_Athlon_TM_Processor_Family = 28,
			AMD_R_Duron_TM_Processor = 29,
			AMD29000_Family = 30,
			K6_2_plus = 31,
			Power_PC_Family = 32,
			Power_PC_601 = 33,
			Power_PC_603 = 34,
			Power_PC_603_plus = 35,
			Power_PC_604 = 36,
			Power_PC_620 = 37,
			Power_PC_X704 = 38,
			Power_PC_750 = 39,
			Intel_R_Core_TM_Duo_processor = 40,
			Intel_R_Core_TM_Duo_mobile_processor = 41,
			Intel_R_Core_TM_Solo_mobile_processor = 42,
			Intel_R_Atom_TM_processor = 43,
			Alpha_Family = 48,
			Alpha_21064 = 49,
			Alpha_21066 = 50,
			Alpha_21164 = 51,
			Alpha_21164PC = 52,
			Alpha_21164a = 53,
			Alpha_21264 = 54,
			Alpha_21364 = 55,
			AMD_Turion_TM_II_Ultra_Dual_Core_Mobile_M_Processor_Family = 56,
			AMD_Turion_TM_II_Dual_Core_Mobile_M_Processor_Family = 57,
			AMD_Athlon_TM_II_Dual_Core_Mobile_M_Processor_Family = 58,
			AMD_Opteron_TM_6100_Series_Processor = 59,
			AMD_Opteron_TM_4100_Series_Processor = 60,
			MIPS_Family = 64,
			MIPS_R4000 = 65,
			MIPS_R4200 = 66,
			MIPS_R4400 = 67,
			MIPS_R4600 = 68,
			MIPS_R10000 = 69,
			SPARC_Family = 80,
			SuperSPARC = 81,
			microSPARC_II = 82,
			microSPARC_IIep = 83,
			UltraSPARC = 84,
			UltraSPARC_II = 85,
			UltraSPARC_IIi = 86,
			UltraSPARC_III = 87,
			UltraSPARC_IIIi = 88,
			_68040 = 96,
			_68xxx_Family = 97,
			_68000 = 98,
			_68010 = 99,
			_68020 = 100,
			_68030 = 101,
			Hobbit_Family = 112,
			Crusoe_TM_TM5000_Family = 120,
			Crusoe_TM_TM3000_Family = 121,
			Efficeon_TM_TM8000_Family = 122,
			Weitek = 128,
			Itanium_TM_Processor = 130,
			AMD_Athlon_TM_64_Processor_Family = 131,
			AMD_Opteron_TM_Processor_Family = 132,
			AMD_Sempron_TM_Processor_Family = 133,
			AMD_Turion_TM_64_Mobile_Technology = 134,
			Dual_Core_AMD_Opteron_TM_Processor_Family = 135,
			AMD_Athlon_TM_64_X2_Dual_Core_Processor_Family = 136,
			AMD_Turion_TM_64_X2_Mobile_Technology = 137,
			Quad_Core_AMD_Opteron_TM_Processor_Family = 138,
			Third_Generation_AMD_Opteron_TM_Processor_Family = 139,
			AMD_Phenom_TM_FX_Quad_Core_Processor_Family = 140,
			AMD_Phenom_TM_X4_Quad_Core_Processor_Family = 141,
			AMD_Phenom_TM_X2_Dual_Core_Processor_Family = 142,
			AMD_Athlon_TM_X2_Dual_Core_Processor_Family = 143,
			PA_RISC_Family = 144,
			PA_RISC_8500 = 145,
			PA_RISC_8000 = 146,
			PA_RISC_7300LC = 147,
			PA_RISC_7200 = 148,
			PA_RISC_7100LC = 149,
			PA_RISC_7100 = 150,
			V30_Family = 160,
			Quad_Core_Intel_R_Xeon_R_processor_3200_Series = 161,
			Dual_Core_Intel_R_Xeon_R_processor_3000_Series = 162,
			Quad_Core_Intel_R_Xeon_R_processor_5300_Series = 163,
			Dual_Core_Intel_R_Xeon_R_processor_5100_Series = 164,
			Dual_Core_Intel_R_Xeon_R_processor_5000_Series = 165,
			Dual_Core_Intel_R_Xeon_R_processor_LV = 166,
			Dual_Core_Intel_R_Xeon_R_processor_ULV = 167,
			Dual_Core_Intel_R_Xeon_R_processor_7100_Series = 168,
			Quad_Core_Intel_R_Xeon_R_processor_5400_Series = 169,
			Quad_Core_Intel_R_Xeon_R_processor = 170,
			Dual_Core_Intel_R_Xeon_R_processor_5200_Series = 171,
			Dual_Core_Intel_R_Xeon_R_processor_7200_Series = 172,
			Quad_Core_Intel_R_Xeon_R_processor_7300_Series = 173,
			Quad_Core_Intel_R_Xeon_R_processor_7400_Series = 174,
			Multi_Core_Intel_R_Xeon_R_processor_7400_Series = 175,
			Pentium_R_III_Xeon_TM = 176,
			Pentium_R_III_Processor_with_Intel_R_SpeedStep_TM_Technology = 177,
			Pentium_R_4 = 178,
			Intel_R_Xeon_TM = 179,
			AS400_Family = 180,
			Intel_R_Xeon_TM_processor_MP = 181,
			AMD_Athlon_TM_XP_Family = 182,
			AMD_Athlon_TM_MP_Family = 183,
			Intel_R_Itanium_R_2 = 184,
			Intel_R_Pentium_R_M_processor = 185,
			Intel_R_Celeron_R_D_processor = 186,
			Intel_R_Pentium_R_D_processor = 187,
			Intel_R_Pentium_R_Processor_Extreme_Edition = 188,
			Intel_R_Core_TM_Solo_Processor = 189,
			K7 = 190,
			Intel_R_Core_TM_2_Duo_Processor = 191,
			Intel_R_Core_TM_2_Solo_processor = 192,
			Intel_R_Core_TM_2_Extreme_processor = 193,
			Intel_R_Core_TM_2_Quad_processor = 194,
			Intel_R_Core_TM_2_Extreme_mobile_processor = 195,
			Intel_R_Core_TM_2_Duo_mobile_processor = 196,
			Intel_R_Core_TM_2_Solo_mobile_processor = 197,
			Intel_R_Core_TM_i7_processor = 198,
			Dual_Core_Intel_R_Celeron_R_Processor = 199,
			S_390_and_zSeries_Family = 200,
			ESA_390_G4 = 201,
			ESA_390_G5 = 202,
			ESA_390_G6 = 203,
			z_Architectur_base = 204,
			Intel_R_Core_TM_i5_processor = 205,
			Intel_R_Core_TM_i3_processor = 206,
			Intel_R_Core_TM_i9_processor = 207,
			VIA_C7_TM_M_Processor_Family = 210,
			VIA_C7_TM_D_Processor_Family = 211,
			VIA_C7_TM_Processor_Family = 212,
			VIA_Eden_TM_Processor_Family = 213,
			Multi_Core_Intel_R_Xeon_R_processor = 214,
			Dual_Core_Intel_R_Xeon_R_processor_3xxx_Series = 215,
			Quad_Core_Intel_R_Xeon_R_processor_3xxx_Series = 216,
			VIA_Nano_TM_Processor_Family = 217,
			Dual_Core_Intel_R_Xeon_R_processor_5xxx_Series = 218,
			Quad_Core_Intel_R_Xeon_R_processor_5xxx_Series = 219,
			Dual_Core_Intel_R_Xeon_R_processor_7xxx_Series = 221,
			Quad_Core_Intel_R_Xeon_R_processor_7xxx_Series = 222,
			Multi_Core_Intel_R_Xeon_R_processor_7xxx_Series = 223,
			Multi_Core_Intel_R_Xeon_R_processor_3400_Series = 224,
			Embedded_AMD_Opteron_TM_Quad_Core_Processor_Family = 230,
			AMD_Phenom_TM_Triple_Core_Processor_Family = 231,
			AMD_Turion_TM_Ultra_Dual_Core_Mobile_Processor_Family = 232,
			AMD_Turion_TM_Dual_Core_Mobile_Processor_Family = 233,
			AMD_Athlon_TM_Dual_Core_Processor_Family = 234,
			AMD_Sempron_TM_SI_Processor_Family = 235,
			AMD_Phenom_TM_II_Processor_Family = 236,
			AMD_Athlon_TM_II_Processor_Family = 237,
			Six_Core_AMD_Opteron_TM_Processor_Family = 238,
			AMD_Sempron_TM_M_Processor_Family = 239,
			i860 = 250,
			i960 = 251,
			Reserved_SMBIOS_Extension = 254,
			Reserved_Un_initialized_Flash_Content_Lo = 255,
			SH_3 = 260,
			SH_4 = 261,
			ARM = 280,
			StrongARM = 281,
			_6x86 = 300,
			MediaGX = 301,
			MII = 302,
			WinChip = 320,
			DSP = 350,
			Video_Processor = 500,
			Reserved_For_Future_Special_Purpose_Assignment = 65534,
			Reserved_Un_initialized_Flash_Content_Hi = 65535
		};

	private:
		std::wstring name;
		std::wstring manufacturer;
		std::wstring version;
		CPUArchitecture architecture;
		CPUFamily family;

		int maxClockSpeed;
		int currentClockSpeed;
		int bitDepth;
		int coresCount;

		friend class ProcessorInfoGenerator;
	};
}