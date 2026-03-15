	thumb_func_start ExpoSite_EnterMapGroup
	.include "src/asm09_exposite_entermapgroup.s"
off_8062B1C:
	.word byte_8062B34
	.word byte_8062B3E
	.word dword_8062B4A
	.word dword_8062B4E
	.word byte_8062B52
	.word byte_8062B58
byte_8062B34:
	.byte 0x1C, 0x70, 0x1C, 0x76, 0x1C, 0x77, 0x1C, 0x78, 0xFF
	.byte 0xFF
byte_8062B3E:
	.byte 0x1C, 0x8B, 0x1C, 0x8C, 0x18, 0x38, 0x18, 0x39, 0x18
	.byte 0x3A, 0xFF, 0xFF
dword_8062B4A:
	.word 0xFFFF351C
dword_8062B4E:
	.word 0xFFFF7B1C
byte_8062B52:
	.byte 0x1C, 0x65, 0x1C, 0x20, 0xFF, 0xFF
byte_8062B58:
	.byte 0x1C, 0x85, 0x1C, 0x83, 0x1C, 0x84, 0x1C, 0x94, 0x1C
	.byte 0x97, 0xFF, 0xFF
	thumb_func_end ExpoSite_EnterMapGroup

	thumb_func_start ExpoSite_LoadGFXAnims
	.include "src/asm09_exposite_loadgfxanims.s"
off_8062B78:
	.word off_8062B90
	.word off_8062B9C
	.word off_8062BA4
	.word off_8062BAC
	.word off_8062BB8
	.word off_8062BC4
off_8062B90:
	.word byte_8062860
	.word byte_80628A0
	.word 0xFFFFFFFF
off_8062B9C:
	.word byte_80628E0
	.word 0xFFFFFFFF
off_8062BA4:
	.word byte_8062908
	.word 0xFFFFFFFF
off_8062BAC:
	.word byte_8062958
	.word byte_80629C0
	.word 0xFFFFFFFF
off_8062BB8:
	.word byte_80629F0
	.word byte_8062A30
	.word 0xFFFFFFFF
off_8062BC4:
	.word byte_8062A70
	.word 0xFFFFFFFF
	thumb_func_end ExpoSite_LoadGFXAnims

	thumb_func_start ExpoSite_SpawnMapObjectsForMap
	.include "src/asm09_exposite_spawn.s"
pt_8062BE4:
	// <endpool> <endfile>
	.word byte_8062BFC
	.word byte_8062DA4
	.word byte_8062DE4
	.word byte_8062E88
	.word byte_8062EB4
	.word byte_8062F1C
	thumb_func_end ExpoSite_SpawnMapObjectsForMap

/*For debugging purposes, connect comment at any range!*/
