
	thumb_func_start SkyTown_EnterMapGroup
	.include "src/asm08_skytown_entermapgroup.s"
off_80603D8:
	.word byte_80603E8
	.word byte_80603EE
	.word byte_80603FC
	.word byte_80603FE
byte_80603E8:
	.byte 0x1C, 0x13, 0x18, 0x21, 0xFF, 0xFF
byte_80603EE:
	.byte 0x1C, 0x6E, 0x1C, 0x58, 0x1C, 0x41, 0x1C, 0x90, 0x1C
	.byte 0x91, 0x1C, 0x4B, 0xFF, 0xFF
byte_80603FC:
	.byte 0xFF, 0xFF
byte_80603FE:
	.byte 0x1C, 0x65, 0x18, 0x24, 0x18, 0x25, 0xFF, 0xFF
	thumb_func_end SkyTown_EnterMapGroup

	thumb_func_start SkyTown_LoadGFXAnims
	.include "src/asm08_skytown_loadgfxanims.s"
off_8060418:
	.word off_8060428
	.word off_8060430
	.word off_806043C
	.word off_8060444
off_8060428:
	.word off_8060284
	.word 0xFFFFFFFF
off_8060430:
	.word byte_80602A4
	.word byte_80602CC
	.word 0xFFFFFFFF
off_806043C:
	.word byte_80602FC
	.word 0xFFFFFFFF
off_8060444:
	.word byte_806032C
	.word 0xFFFFFFFF
	thumb_func_end SkyTown_LoadGFXAnims

	thumb_func_start SkyTown_SpawnMapObjectsForMap
	.include "src/asm08_skytown_spawn.s"
pt_8060464:
	// <endpool> <endfile>
	.word byte_8060474
	.word byte_80604A0
	.word dword_80605E4
	.word byte_80605E8
	thumb_func_end SkyTown_SpawnMapObjectsForMap

/*For debugging purposes, connect comment at any range!*/
