
	thumb_func_start CentralTown_EnterMapGroup
	.include "src/asm04_centraltown_entermapgroup.s"
off_804E698: // [*const SpriteLoadData; CENTRAL_TOWN_NUM_MAPS]
  .word byte_804E6AC // [SpriteLoadData; 8]
	.word dword_804E6BE // [SpriteLoadData; 1]
	.word dword_804E6C2 // [SpriteLoadData; 1]
	.word byte_804E6C6 // [SpriteLoadData; 0]
	.word byte_804E6C8 // [SpriteLoadData; 3]
byte_804E6AC: // [SpriteLoadData; 8]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x11
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x15
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x16
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x51
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x13
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x18, 
    sprite_index: 0x24
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x18, 
    sprite_index: 0x25
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x18, 
    sprite_index: 0x1C
  ]
  .hword 0xFFFF
dword_804E6BE: // [SpriteLoadData; 1]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x07
  ]
  .hword 0xFFFF
dword_804E6C2: // [SpriteLoadData; 1]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x14
  ]
  .hword 0xFFFF
byte_804E6C6: // [SpriteLoadData; 0]
  .hword 0xFFFF
byte_804E6C8: // [SpriteLoadData; 3]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x96
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x1C, 
    sprite_index: 0x9D
  ]
	sprite_load_data_struct [
    sprite_type_offset: 0x18, 
    sprite_index: 0x1C
  ]
  .hword 0xFFFF
	thumb_func_end CentralTown_EnterMapGroup

	.include "src/asm04_centraltown_loadgfxanims.s"
off_804E6E4:
	.word dword_804E6F8
	.word off_804E6FC
	.word off_804E70C
	.word dword_804E714
	.word off_804E718
dword_804E6F8:
	.word 0xFFFFFFFF
off_804E6FC:
	.word off_804E450
	.word off_804E478
	.word off_804E4A0
	.word 0xFFFFFFFF
off_804E70C:
	.word byte_804E5D4
	.word 0xFFFFFFFF
dword_804E714:
	.word 0xFFFFFFFF
off_804E718:
	.word byte_804E604
	.word 0xFFFFFFFF
	thumb_func_end CentralTown_LoadGFXAnims

	.include "src/asm04_centraltown_spawn.s"
off_804E738: // [*const MapObjectSpawnData; CENTRAL_TOWN_NUM_MAPS]
	// <endpool>
	.word CentralTownObjectSpawns // [MapObjectSpawnData; 15]]
	.word LansHouseObjectSpawns // [MapObjectSpawnData; 4]
	.word LansRoomObjectSpawns // [MapObjectSpawnData; 0]
	.word BathroomObjectSpawns // [MapObjectSpawnData; 0]
	.word AsterLandObjectSpawns // [MapObjectSpawnData; 4]
	thumb_func_end CentralTown_SpawnMapObjectsForMap
/*For debugging purposes, connect comment at any range!*/
