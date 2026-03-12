
	thumb_func_start SeasideTown_EnterMapGroup
	.include "src/asm06_seasidetown_entermapgroup.s"
off_8059624:
	.word byte_8059638
	.word byte_8059646
	.word byte_805964E
	.word byte_805965A
	.word byte_8059662
byte_8059638:
	.byte 0x1C, 0x3D, 0x1C, 0x3E, 0x1C, 0x13, 0x1C, 0x32, 0x1C
	.byte 0x2F, 0x18, 0x1B, 0xFF, 0xFF
byte_8059646:
	.byte 0x1C, 0x35, 0x1C, 0x45, 0x1C, 0x46, 0xFF, 0xFF
byte_805964E:
	.byte 0x1C, 0x35, 0x1C, 0x4D, 0x1C, 0x2F, 0x18, 0x25, 0x18
	.byte 0x1C, 0xFF, 0xFF
byte_805965A:
	.byte 0x1C, 0x35, 0x1C, 0x40, 0x1C, 0x48, 0xFF, 0xFF
byte_8059662:
	.byte 0xFF, 0xFF
	thumb_func_end SeasideTown_EnterMapGroup

	.include "src/asm06_seasidetown_loadgfxanims.s"
off_8059678:
	.word off_805968C
	.word off_80596A0
	.word off_80596AC
	.word off_80596B4
	.word off_80596BC
off_805968C:
	.word off_8059378
	.word byte_80593B8
	.word byte_80593F8
	.word byte_8059438
	.word 0xFFFFFFFF
off_80596A0:
	.word byte_8059468
	.word byte_80594A8
	.word 0xFFFFFFFF
off_80596AC:
	.word byte_80594E8
	.word 0xFFFFFFFF
off_80596B4:
	.word byte_8059528
	.word 0xFFFFFFFF
off_80596BC:
	.word byte_8059558
	.word byte_8059588
	.word 0xFFFFFFFF
	thumb_func_end SeasideTown_LoadGFXAnims

	.include "src/asm06_seasidetown_spawn.s"
off_80596E0:
	// <endpool> <endfile>
	.word byte_80596F4
	.word byte_805975C
	.word byte_8059A58
	.word byte_8059C00
	.word byte_8059D30
	thumb_func_end SeasideTown_SpawnMapObjectsForMap

/*For debugging purposes, connect comment at any range!*/
