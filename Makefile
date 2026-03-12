# binary tools used in build
MAKE = make

# Prefer local toolchain under tools/binutils if present; otherwise, fall back
# to system-wide arm-none-eabi-* binaries. This makes the project easier to
# build on machines where the toolchain is installed globally.
ifneq ("$(wildcard tools/binutils/bin/arm-none-eabi-as)","")
AS = tools/binutils/bin/arm-none-eabi-as
LD = tools/binutils/bin/arm-none-eabi-ld
OBJCOPY = tools/binutils/bin/arm-none-eabi-objcopy
OBJDUMP := tools/binutils/bin/arm-none-eabi-objdump
else
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP := arm-none-eabi-objdump
endif

AGBCC := tools/agbcc/bin/agbcc

GBAGFX = tools/gbagfx/gbagfx
SHA1SUM = sha1sum
PY = py
CPP = cpp

# project paths
SRCDIR = asm
CDIR = src
BIN = bin
OBJ =
CONST = constants
INC = include

# project files
SFILES = rom.s data.s ewram.s iwram.s vram.s

# to keep track of compressed files and to build decompressed versions into them
# defines rules to build and compress lz files
include lz_assets.mk

OFILES = $(addprefix $(OBJ),$(SFILES:.s=.o))
CSRCS := $(CDIR)/asm00_0_sound.c $(CDIR)/asm00_0_soundmain.c $(CDIR)/asm00_0_playsfx.c $(CDIR)/asm00_0_playmusic.c $(CDIR)/asm00_0_music_80005F2.c $(CDIR)/asm00_0_sub_800060A.c $(CDIR)/asm00_0_sound_8000642.c $(CDIR)/asm00_0_sound_800065A.c $(CDIR)/asm00_0_sound_8000672.c $(CDIR)/asm00_0_sound_800068A.c $(CDIR)/asm00_0_sound_80006A2.c $(CDIR)/asm00_0_musicGameState_8000784.c $(CDIR)/asm00_0_sub_80007A0.c $(CDIR)/asm00_0_zeroFill_80007B2.c $(CDIR)/asm00_0_sound_8000808.c $(CDIR)/asm00_1_sub_800318C.c $(CDIR)/asm00_1_runbattleobjectlogic.c $(CDIR)/asm00_2_sub_800ED80.c $(CDIR)/asm00_2_sub_800ED90.c $(CDIR)/asm00_2_chip_helpers.c $(CDIR)/battle_core_loadchipdata.c $(CDIR)/menu_core_initmainmenu.c $(CDIR)/asm03_0_beast_scan_helpers.c $(CDIR)/asm03_0_beast_panel_helpers.c $(CDIR)/asm03_2_text_render_wrappers.c $(CDIR)/asm03_2_text_sprite_wrappers.c $(CDIR)/asm03_2_text_sprite_reset_wrappers.c $(CDIR)/asm03_2_text_sprite_clear_8046696.c $(CDIR)/asm04_centraltown_loadgfxanims.c $(CDIR)/asm04_centraltown_spawn.c $(CDIR)/asm05_cyberacademy_loadgfxanims.c $(CDIR)/asm05_cyberacademy_spawn.c $(CDIR)/asm06_seasidetown_loadgfxanims.c $(CDIR)/asm06_seasidetown_spawn.c
C_PPS := $(CSRCS:.c=.i)
C_ASM := $(CSRCS:.c=.s)
C_OFILES := $(CSRCS:.c=.o)
BUILD_NAME = bn6f
ROM = $(BUILD_NAME).gba
ELF := $(ROM:.gba=.elf)
SYM = $(ROM:.gba=.sym)
NOGBASYM = bn6f_nogba.sym

# build flags
COMPLIANCE_FLAGS = -g -I$(INC)
WFLAGS =
ARCH = -mcpu=arm7tdmi -march=armv4t -mthumb -mthumb-interwork
CDEBUG =
CFLAGS =
ASFLAGS = $(ARCH) $(WFLAGS) $(COMPLIANCE_FLAGS) --agbasm-colonless-labels --agbasm-colon-defined-global-labels --agbasm-local-labels --agbasm-multiline-macros \
	--agbasm-charmap --agbasm-no-gba-thumb-after-label-disasm-fix
C_ASFLAGS = $(ARCH) $(WFLAGS) $(COMPLIANCE_FLAGS)
	
ASDEBUGFLAGS = --agbasm-debug $(@:.o=.dump)
LDFLAGS = -Map $(BUILD_NAME).map
LIB =

.SUFFIXES:

.PHONY: syms

# TODO: INTEGRATE SCAN INCLUDES

all: $(C_OFILES) $(ROM)
	@$(SHA1SUM) -c $(BUILD_NAME).sha1
	@# Update machine-readable build status
	@SHA1=$$(sha1sum $(ROM) | cut -d' ' -f1); \
	TIMESTAMP=$$(date -u +"%Y-%m-%dT%H:%M:%SZ"); \
	SHA1="$$SHA1" TIMESTAMP="$$TIMESTAMP" python3 tools/update_build_status.py

$(ROM): $(ELF)
	$(OBJCOPY) -O binary $(ELF) $(ROM)

$(ELF): $(OFILES)
	$(LD) $(LDFLAGS) -o $(ELF) -T ld_script.ld $(OFILES) $(LIB)

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

rom.o: $(CDIR)/asm00_0_soundmain.s $(CDIR)/asm00_0_sound.s $(CDIR)/asm00_0_playsfx.s $(CDIR)/asm00_0_playmusic.s $(CDIR)/asm00_0_music_80005F2.s $(CDIR)/asm00_0_sub_800060A_rominc.s $(CDIR)/asm00_0_sound_wrappers.s $(CDIR)/asm00_0_sound_8000642_rominc.s $(CDIR)/asm00_0_sound_800065A_rominc.s $(CDIR)/asm00_0_sound_8000672_rominc.s $(CDIR)/asm00_0_sound_800068A_rominc.s $(CDIR)/asm00_0_sound_80006A2_rominc.s $(CDIR)/asm00_0_musicGameState_8000784_rominc.s $(CDIR)/asm00_0_sub_80007A0_rominc.s $(CDIR)/asm00_0_zeroFill_80007B2_rominc.s $(CDIR)/asm00_0_sub_80007BE_rominc.s $(CDIR)/asm00_0_sound_8000808_rominc.s $(CDIR)/asm00_1_sub_800318C_rominc.s $(CDIR)/asm00_1_runbattleobjectlogic_rominc.s $(CDIR)/asm00_2_sub_800ED80.s $(CDIR)/asm00_2_sub_800ED90.s $(CDIR)/asm00_2_chip_helpers_rominc.s $(CDIR)/asm00_2_small_helpers_rominc.s $(CDIR)/battle_core_initbattle_rominc.s $(CDIR)/battle_core_loadchipdata_rominc.s $(CDIR)/menu_core_initmainmenu_rominc.s $(CDIR)/asm03_0_beast_scan_helpers_rominc.s $(CDIR)/asm03_0_beast_panel_helpers_rominc.s $(CDIR)/asm03_1_0_realworld_wrappers_rominc.s $(CDIR)/asm03_2_text_render_wrappers_rominc.s $(CDIR)/asm03_2_text_sprite_wrappers_rominc.s $(CDIR)/asm03_2_text_sprite_reset_wrappers_rominc.s $(CDIR)/asm03_2_text_sprite_clear_8046696_rominc.s $(CDIR)/asm04_centraltown_loadgfxanims.s $(CDIR)/asm04_centraltown_spawn.s $(CDIR)/asm05_cyberacademy_loadgfxanims.s $(CDIR)/asm05_cyberacademy_spawn.s $(CDIR)/asm06_seasidetown_loadgfxanims.s $(CDIR)/asm06_seasidetown_spawn.s

$(CDIR)/%.i: $(CDIR)/%.c $(INC)/asm00_0_sound.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/battle_core_initbattle.i: $(CDIR)/battle_core_initbattle.c $(INC)/battle_core_initbattle.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm00_1_sub_800318C.i: $(CDIR)/asm00_1_sub_800318C.c $(INC)/asm00_1_battle_objects.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm00_1_runbattleobjectlogic.i: $(CDIR)/asm00_1_runbattleobjectlogic.c $(INC)/asm00_1_battle_objects.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/battle_core_loadchipdata.i: $(CDIR)/battle_core_loadchipdata.c $(INC)/battle_core_loadchipdata.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/menu_core_initmainmenu.i: $(CDIR)/menu_core_initmainmenu.c $(INC)/menu_core_initmainmenu.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm03_0_beast_scan_helpers.i: $(CDIR)/asm03_0_beast_scan_helpers.c $(INC)/asm03_0_beast_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm03_0_beast_panel_helpers.i: $(CDIR)/asm03_0_beast_panel_helpers.c $(INC)/asm03_0_beast_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm00_2_sub_800ED80.i: $(CDIR)/asm00_2_sub_800ED80.c $(INC)/asm00_2_ai.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm00_2_sub_800ED90.i: $(CDIR)/asm00_2_sub_800ED90.c $(INC)/asm00_2_sub_800ED90.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm00_2_chip_helpers.i: $(CDIR)/asm00_2_chip_helpers.c $(INC)/asm00_2_chip_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm00_2_small_helpers.i: $(CDIR)/asm00_2_small_helpers.c $(INC)/asm00_2_small_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm03_1_0_realworld_wrappers.i: $(CDIR)/asm03_1_0_realworld_wrappers.c $(INC)/asm03_1_0_realworld_wrappers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm03_2_text_render_wrappers.i: $(CDIR)/asm03_2_text_render_wrappers.c $(INC)/asm03_2_text_render_wrappers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm03_2_text_sprite_wrappers.i: $(CDIR)/asm03_2_text_sprite_wrappers.c $(INC)/asm03_2_text_sprite_wrappers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm03_2_text_sprite_reset_wrappers.i: $(CDIR)/asm03_2_text_sprite_reset_wrappers.c $(INC)/asm03_2_text_sprite_reset_wrappers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm03_2_text_sprite_clear_8046696.i: $(CDIR)/asm03_2_text_sprite_clear_8046696.c $(INC)/asm03_2_text_sprite_clear_8046696.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm04_centraltown_loadgfxanims.i: $(CDIR)/asm04_centraltown_loadgfxanims.c $(INC)/mapgroup_spawn_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm04_centraltown_spawn.i: $(CDIR)/asm04_centraltown_spawn.c $(INC)/mapgroup_spawn_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm05_cyberacademy_loadgfxanims.i: $(CDIR)/asm05_cyberacademy_loadgfxanims.c $(INC)/mapgroup_spawn_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm05_cyberacademy_spawn.i: $(CDIR)/asm05_cyberacademy_spawn.c $(INC)/mapgroup_spawn_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm06_seasidetown_loadgfxanims.i: $(CDIR)/asm06_seasidetown_loadgfxanims.c $(INC)/mapgroup_spawn_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm06_seasidetown_spawn.i: $(CDIR)/asm06_seasidetown_spawn.c $(INC)/mapgroup_spawn_helpers.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/%.s: $(CDIR)/%.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@

$(CDIR)/asm00_0_soundmain.s: $(CDIR)/asm00_0_soundmain.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_thumb_wrapper.py $@ call_m4aSoundMain

$(CDIR)/asm00_0_sound.s: $(CDIR)/asm00_0_sound.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_thumb_wrapper.py $@ call_m4a_2_814F00C

$(CDIR)/asm00_0_playsfx.s: $(CDIR)/asm00_0_playsfx.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_thumb_wrapper.py $@ PlaySoundEffect
	python3 tools/fix_agbcc_play_sound_effect.py $@

$(CDIR)/asm00_0_playmusic.s: $(CDIR)/asm00_0_playmusic.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_playmusic.py $@

$(CDIR)/asm00_0_music_80005F2.s: $(CDIR)/asm00_0_music_80005F2.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_music_80005F2.py $@

$(CDIR)/asm00_0_sub_800060A.s: $(CDIR)/asm00_0_sub_800060A.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_800060A.py $@

$(CDIR)/asm00_0_sub_800060A_rominc.s: $(CDIR)/asm00_0_sub_800060A.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_800060A_rominc.py $@

$(CDIR)/asm00_0_sound_8000642.s: $(CDIR)/asm00_0_sound_8000642.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_8000642.py $@

$(CDIR)/asm00_0_sound_8000642_rominc.s: $(CDIR)/asm00_0_sound_8000642.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_8000642_rominc.py $@

$(CDIR)/asm00_0_sound_800065A.s: $(CDIR)/asm00_0_sound_800065A.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_800065A.py $@

$(CDIR)/asm00_0_sound_800065A_rominc.s: $(CDIR)/asm00_0_sound_800065A.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_800065A_rominc.py $@

$(CDIR)/asm00_0_sound_8000672.s: $(CDIR)/asm00_0_sound_8000672.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_8000672.py $@

$(CDIR)/asm00_0_sound_8000672_rominc.s: $(CDIR)/asm00_0_sound_8000672.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_8000672_rominc.py $@

$(CDIR)/asm00_0_sound_800068A.s: $(CDIR)/asm00_0_sound_800068A.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_800068A.py $@

$(CDIR)/asm00_0_sound_800068A_rominc.s: $(CDIR)/asm00_0_sound_800068A.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_800068A_rominc.py $@

$(CDIR)/asm00_0_sound_80006A2.s: $(CDIR)/asm00_0_sound_80006A2.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_80006A2.py $@

$(CDIR)/asm00_0_sound_80006A2_rominc.s: $(CDIR)/asm00_0_sound_80006A2.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_80006A2_rominc.py $@

$(CDIR)/asm00_0_musicGameState_8000784.s: $(CDIR)/asm00_0_musicGameState_8000784.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_musicGameState_8000784.py $@

$(CDIR)/asm00_0_musicGameState_8000784_rominc.s: $(CDIR)/asm00_0_musicGameState_8000784.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_musicGameState_8000784_rominc.py $@

$(CDIR)/asm00_0_sub_80007A0.s: $(CDIR)/asm00_0_sub_80007A0.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_80007A0.py $@

$(CDIR)/asm00_0_sub_80007A0_rominc.s: $(CDIR)/asm00_0_sub_80007A0.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_80007A0_rominc.py $@

$(CDIR)/asm00_0_zeroFill_80007B2.s: $(CDIR)/asm00_0_zeroFill_80007B2.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_zeroFill_80007B2.py $@

$(CDIR)/asm00_0_zeroFill_80007B2_rominc.s: $(CDIR)/asm00_0_zeroFill_80007B2.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_zeroFill_80007B2_rominc.py $@

$(CDIR)/asm00_0_sound_wrappers.s: $(CDIR)/asm00_0_sound_wrappers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm00_0_sound_wrappers.py $@

$(CDIR)/asm00_0_sound_8000808.s: $(CDIR)/asm00_0_sound_8000808.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_8000808.py $@

$(CDIR)/asm00_0_sub_80007BE_rominc.s: $(CDIR)/asm00_0_sub_80007BE.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_80007BE_rominc.py $@

$(CDIR)/asm00_0_sound_8000808_rominc.s: $(CDIR)/asm00_0_sound_8000808.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_8000808_rominc.py $@

$(CDIR)/asm00_1_sub_800318C.s: $(CDIR)/asm00_1_sub_800318C.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_800318C.py $@

$(CDIR)/asm00_1_sub_800318C_rominc.s: $(CDIR)/asm00_1_sub_800318C.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_800318C.py $@

$(CDIR)/asm00_1_runbattleobjectlogic.s: $(CDIR)/asm00_1_runbattleobjectlogic.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_runbattleobjectlogic.py $@

$(CDIR)/asm00_1_runbattleobjectlogic_rominc.s: $(CDIR)/asm00_1_runbattleobjectlogic.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_runbattleobjectlogic.py $@

$(CDIR)/asm00_2_sub_800ED80.s: $(CDIR)/asm00_2_sub_800ED80.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_800ED80.py $@

$(CDIR)/asm00_2_sub_800ED90.s: $(CDIR)/asm00_2_sub_800ED90.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_800ED90.py $@

$(CDIR)/asm00_2_chip_helpers.s: $(CDIR)/asm00_2_chip_helpers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm00_2_chip_helpers.py $@

$(CDIR)/asm00_2_chip_helpers_rominc.s: $(CDIR)/asm00_2_chip_helpers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm00_2_chip_helpers.py $@

$(CDIR)/asm00_2_small_helpers_rominc.s: $(CDIR)/asm00_2_small_helpers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm00_2_small_helpers_rominc.py $@

$(CDIR)/battle_core_initbattle.s: $(CDIR)/battle_core_initbattle.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_8012346.py $@

$(CDIR)/battle_core_initbattle_rominc.s: $(CDIR)/battle_core_initbattle.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_8012346_rominc.py $@

$(CDIR)/battle_core_loadchipdata.s: $(CDIR)/battle_core_loadchipdata.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_battle_core_loadchipdata.py $@

$(CDIR)/battle_core_loadchipdata_rominc.s: $(CDIR)/battle_core_loadchipdata.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_battle_core_loadchipdata_rominc.py $@

$(CDIR)/menu_core_initmainmenu.s: $(CDIR)/menu_core_initmainmenu.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_menu_core_initmainmenu.py $@

$(CDIR)/menu_core_initmainmenu_rominc.s: $(CDIR)/menu_core_initmainmenu.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_menu_core_initmainmenu_rominc.py $@

$(CDIR)/asm03_0_beast_scan_helpers_rominc.s: $(CDIR)/asm03_0_beast_scan_helpers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm03_0_beast_scan_helpers_rominc.py $@

$(CDIR)/asm03_0_beast_panel_helpers_rominc.s: $(CDIR)/asm03_0_beast_panel_helpers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm03_0_beast_panel_helpers_rominc.py $@

$(CDIR)/asm03_1_0_realworld_wrappers_rominc.s: $(CDIR)/asm03_1_0_realworld_wrappers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm03_1_0_realworld_wrappers_rominc.py $@

$(CDIR)/asm03_2_text_render_wrappers_rominc.s: $(CDIR)/asm03_2_text_render_wrappers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm03_2_text_render_wrappers_rominc.py $@

$(CDIR)/asm03_2_text_sprite_wrappers_rominc.s: $(CDIR)/asm03_2_text_sprite_wrappers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm03_2_text_sprite_wrappers_rominc.py $@

$(CDIR)/asm03_2_text_sprite_reset_wrappers_rominc.s: $(CDIR)/asm03_2_text_sprite_reset_wrappers.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm03_2_text_sprite_reset_wrappers_rominc.py $@

$(CDIR)/asm03_2_text_sprite_clear_8046696_rominc.s: $(CDIR)/asm03_2_text_sprite_clear_8046696.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_asm03_2_text_sprite_clear_8046696_rominc.py $@

$(CDIR)/asm04_centraltown_loadgfxanims.s: $(CDIR)/asm04_centraltown_loadgfxanims.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_mapgroup_loadgfxanims.py $@ CentralTown_LoadGFXAnims off_804E6E0 off_804E6E4

$(CDIR)/asm04_centraltown_spawn.s: $(CDIR)/asm04_centraltown_spawn.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_mapgroup_spawn.py $@ CentralTown_SpawnMapObjectsForMap off_804E734 off_804E738

$(CDIR)/asm05_cyberacademy_loadgfxanims.s: $(CDIR)/asm05_cyberacademy_loadgfxanims.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_mapgroup_loadgfxanims.py $@ CyberAcademy_LoadGFXAnims off_8052774 off_8052778

$(CDIR)/asm05_cyberacademy_spawn.s: $(CDIR)/asm05_cyberacademy_spawn.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_mapgroup_spawn.py $@ CyberAcademy_SpawnMapObjectsForMap off_8052804 off_8052808

$(CDIR)/asm06_seasidetown_loadgfxanims.s: $(CDIR)/asm06_seasidetown_loadgfxanims.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_mapgroup_loadgfxanims.py $@ SeasideTown_LoadGFXAnims off_8059674 off_8059678

$(CDIR)/asm06_seasidetown_spawn.s: $(CDIR)/asm06_seasidetown_spawn.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_mapgroup_spawn.py $@ SeasideTown_SpawnMapObjectsForMap off_80596DC off_80596E0

$(CDIR)/%.o: $(CDIR)/%.s
	$(AS) $(C_ASFLAGS) $< -o $@

assets: $(LZ_FILES) $(LZ_BINFILES)
	

checksum:
	@$(SHA1SUM) -c $(BUILD_NAME).sha1

fdiff:
	$(PY) tools/fdiff.py $(BUILD_NAME).ign $(ROM) -s2

tail: $(ROM)
	@# Create tail.bin using the tail location in current elf then compile again
	$(PY) tools/gen_obj_tail.py $(ELF) _$(ROM) bin/tail.bin 'tail'
	@echo "Updated tail.bin!"

clean:
	rm -f *.o
	rm -f $(CDIR)/*.o
	rm -f $(CDIR)/*.i
	rm -f $(CDIR)/*.s
	rm -f *.map
	rm -f *.elf
	# rm -f *.gba
	rm -f $(COMPRESSED_TEXT_ARCHIVES_DIR)/*.lz
	rm -f $(COMPRESSED_TEXT_ARCHIVES_DIR)/*.bin

syms: $(SYM)

$(SYM): $(ELF)
	$(OBJDUMP) -t $< | sort -u | grep -E "^0[23689]" | perl -p -e 's/^(\w{8}) (\w).{6} \S+\t(\w{8}) (\S+)$$/\1 \2 \3 \4/g' > $@

nogbasyms: $(NOGBASYM)

$(NOGBASYM): $(ELF)
	$(OBJDUMP) -t $< | sort -u | grep -E "^0" | perl -p -e 's/^(\w{8}) (\w).{6} \S+\t(\w{8}) (\S+)$$/\1 \4/g' > $@
