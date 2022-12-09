#include "vcsLib.h"

const uint8_t HexDigits[16 * 8] =
{
	0x7c, 0x86, 0x8a, 0x92, 0xa2, 0xc2, 0x7c, 0x00, // 0
	0x10, 0x30, 0x10, 0x10, 0x10, 0x10, 0x7c, 0x00, // 1
	0x3c, 0x42, 0x44, 0x08, 0x10, 0x20, 0x7e, 0x00, // 2
	0x3c, 0x42, 0x02, 0x1c, 0x02, 0x82, 0x7e, 0x00, // 3
	0x82, 0x82, 0x82, 0x7e, 0x02, 0x02, 0x02, 0x00, // 4
	0xfe, 0x80, 0x80, 0xfc, 0x02, 0x82, 0x7c, 0x00, // 5
	0x08, 0x10, 0x20, 0x7c, 0x82, 0x82, 0x7c, 0x00, // 6
	0xfe, 0x84, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, // 7
	0x7c, 0x82, 0x82, 0x7c, 0x82, 0x82, 0x7c, 0x00, // 8
	0x7c, 0x82, 0x82, 0x7c, 0x08, 0x10, 0x20, 0x00, // 9
	0x10, 0x28, 0x44, 0xfe, 0x82, 0x82, 0x82, 0x00, // A
	0xf8, 0x84, 0x84, 0xf8, 0x82, 0x82, 0xfc, 0x00, // B
	0x3e, 0x40, 0x80, 0x80, 0x80, 0x40, 0x3e, 0x00, // C
	0xfc, 0x84, 0x82, 0x82, 0x82, 0x84, 0xfc, 0x00, // D
	0xfe, 0x80, 0x80, 0xf8, 0x80, 0x80, 0xfe, 0x00, // E
	0xfe, 0x80, 0x80, 0xf8, 0x80, 0x80, 0x80, 0x00, // F
};

int elf_main(uint32_t* args)
{
	// Always reset PC first, cause it's going to be close to the end of the 6507 address space
	vcsJmp3();
	
	// Init TIA and RIOT RAM
	vcsLda2(0);
	for (int i = 0; i < 256; i++) {
		vcsSta3((unsigned char)i);
	}

	while (1)
	{
		// 3 lines of VSYNC
		vcsLda2(2);
		vcsSta3(VSYNC);
		for (int i = 0; i < 3; i++) {
			vcsSta3(WSYNC);
		}
		vcsLda2(0);
		vcsSta3(VSYNC);
		// 37 lines of VBLANK
		for (int i = 0; i < 37; i++) {
			vcsSta3(WSYNC);
		}
		uint32_t displayValue = args[ARG_TYPE];
		// 192 lines of COLUBK
		for (int k = 0; k < 4; k++)
		{
			const uint8_t* pf1a = &HexDigits[((displayValue >> (k * 8)) & 0xf) << 3];
			const uint8_t* pf1b = &HexDigits[((displayValue >> ((k * 8)+4)) & 0xf) << 3];

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					vcsLda2(0);
					vcsSta3(VBLANK);
					vcsWrite5(COLUPF, 0xff);
					vcsWrite5(PF1, pf1a[i]);
					vcsJmp3();
					vcsNop2n(11);
					vcsWrite5(PF1, pf1b[i]);
					vcsSta3(WSYNC);
				}
			}
		}
	
		vcsWrite5(VBLANK, 2);
		// 30 lines of Overscan
		for (int i = 0; i < 30; i++) {
			vcsSta3(WSYNC);
			uint8_t p0Button = vcsRead4(INPT4);
			if (0 == (p0Button & 0x80))
			{
				vcsJmp3();
				vcsNop2n(0xf00);
				return 0;
			}
		}
	}
}
