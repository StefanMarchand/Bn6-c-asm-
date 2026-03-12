
	thumb_func_start GreenTown_EnterMapGroup
	.include "src/asm07_greentown_entermapgroup.s"
off_805DF74:
	.word byte_805DF88
	.word dword_805DF90
	.word byte_805DF94
	.word byte_805DF9A
	.word byte_805DFA0
byte_805DF88:
	.byte 0x1C, 0x13, 0x18, 0x23, 0x1C, 0x9F, 0xFF, 0xFF
dword_805DF90:
	.word 0xFFFF591C
byte_805DF94:
	.byte 0x1C, 0x5A, 0x1C, 0x60, 0xFF, 0xFF
byte_805DF9A:
	.byte 0x1C, 0x5D, 0x1C, 0x62, 0xFF, 0xFF
byte_805DFA0:
	.byte 0xFF, 0xFF
	thumb_func_end GreenTown_EnterMapGroup

	thumb_func_start GreenTown_LoadGFXAnims
	.include "src/asm07_greentown_loadgfxanims.s"
off_805DFB4:
	.word off_805DFC8
	.word off_805DFD0
	.word off_805DFD8
	.word off_805DFE0
	.word off_805DFE8
off_805DFC8:
	.word off_805DE28
	.word 0xFFFFFFFF
off_805DFD0:
	.word byte_805DE50
	.word 0xFFFFFFFF
off_805DFD8:
	.word byte_805DE78
	.word 0xFFFFFFFF
off_805DFE0:
	.word byte_805DEA8
	.word 0xFFFFFFFF
off_805DFE8:
	.word byte_805DED8
	.word 0xFFFFFFFF
	thumb_func_end GreenTown_LoadGFXAnims

	thumb_func_start GreenTown_SpawnMapObjectsForMap
	.include "src/asm07_greentown_spawn.s"
pt_805E008:
	// <endpool> <endfile>
	.word byte_805E01C
	.word byte_805E084
	.word byte_805E09C
	.word byte_805E118
	.word dword_805E158
	thumb_func_end GreenTown_SpawnMapObjectsForMap

/*For debugging purposes, connect comment at any range!*/
