
	thumb_func_start CyberAcademy_EnterMapGroup
	.include "src/asm05_cyberacademy_entermapgroup.s"
off_80526F4:
	.word byte_8052720
	.word dword_805272A
	.word dword_805272E
	.word dword_8052732
	.word byte_8052736
	.word byte_805273E
	.word dword_8052744
	.word off_8052748
	.word byte_8052754
	.word dword_805275C
	.word dword_8052760
byte_8052720:
	.byte 0x1C, 0x9, 0x1C, 0x10, 0x1C, 0x19, 0x1C, 0x23, 0xFF
	.byte 0xFF
dword_805272A:
	.word 0xFFFF091C
dword_805272E:
	.word 0xFFFF091C
dword_8052732:
	.word 0xFFFF091C
byte_8052736:
	.byte 0x1C, 0x10, 0x1C, 0x25, 0x18, 0x23, 0xFF, 0xFF
byte_805273E:
	.byte 0x1C, 0x10, 0x1C, 0x25, 0xFF, 0xFF
dword_8052744:
	.word 0xFFFF2A1C
off_8052748:
	.word off_81C241C
	.byte 0x1C, 0x10, 0x1C, 0x23, 0x18, 0x1F, 0xFF, 0xFF
byte_8052754:
	.byte 0x1C, 0x43, 0x1C, 0x7A, 0x18, 0x1C, 0xFF, 0xFF
dword_805275C:
	.word 0xFFFF1F18
dword_8052760:
	.word 0xFFFF2418
	thumb_func_end CyberAcademy_EnterMapGroup

	.include "src/asm05_cyberacademy_loadgfxanims.s"
off_8052778:
	.word off_80527A4
	.word off_80527AC
	.word off_80527B4
	.word off_80527BC
	.word off_80527C4
	.word off_80527CC
	.word off_80527D4
	.word off_80527DC
	.word dword_80527E4
	.word dword_80527E8
	.word dword_80527EC
off_80527A4:
	.word off_8052480
	.word 0xFFFFFFFF
off_80527AC:
	.word off_80524C0
	.word 0xFFFFFFFF
off_80527B4:
	.word off_8052480
	.word 0xFFFFFFFF
off_80527BC:
	.word off_80524C0
	.word 0xFFFFFFFF
off_80527C4:
	.word byte_80524E8
	.word 0xFFFFFFFF
off_80527CC:
	.word byte_80524E8
	.word 0xFFFFFFFF
off_80527D4:
	.word byte_8052510
	.word 0xFFFFFFFF
off_80527DC:
	.word byte_8052538
	.word 0xFFFFFFFF
dword_80527E4:
	.word 0xFFFFFFFF
dword_80527E8:
	.word 0xFFFFFFFF
dword_80527EC:
	.word 0xFFFFFFFF
	thumb_func_end CyberAcademy_LoadGFXAnims

	.include "src/asm05_cyberacademy_spawn.s"
off_8052808:
	.word byte_8052834
	.word byte_80529B4
	.word byte_8052A6C
	.word byte_8052B24
	.word dword_8052BDC
	.word dword_8052BE0
	.word byte_8052BE4
	.word byte_8052C10
	.word byte_8052D54
	.word dword_8052D80
	// <endpool> <endfile>
	.word dword_8052D84
	thumb_func_end CyberAcademy_SpawnMapObjectsForMap

/*For debugging purposes, connect comment at any range!*/
