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
CSRCS := $(CDIR)/asm00_0_sound.c $(CDIR)/asm00_0_soundmain.c $(CDIR)/asm00_0_playsfx.c $(CDIR)/asm00_0_playmusic.c $(CDIR)/asm00_0_music_80005F2.c $(CDIR)/asm00_0_sub_800060A.c $(CDIR)/asm00_0_sound_8000642.c $(CDIR)/asm00_0_sound_800065A.c $(CDIR)/asm00_0_sound_8000672.c $(CDIR)/asm00_0_sound_800068A.c $(CDIR)/asm00_0_musicGameState_8000784.c $(CDIR)/asm00_0_sub_80007A0.c $(CDIR)/asm00_0_zeroFill_80007B2.c $(CDIR)/asm00_0_sound_8000808.c $(CDIR)/asm00_2_sub_800ED80.c $(CDIR)/battle_core_loadchipdata.c
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

rom.o: $(CDIR)/asm00_0_soundmain.s $(CDIR)/asm00_0_sound.s $(CDIR)/asm00_0_playsfx.s $(CDIR)/asm00_0_playmusic.s $(CDIR)/asm00_0_music_80005F2.s $(CDIR)/asm00_0_sub_800060A_rominc.s $(CDIR)/asm00_0_sound_8000642_rominc.s $(CDIR)/asm00_0_sound_800065A_rominc.s $(CDIR)/asm00_0_sound_8000672_rominc.s $(CDIR)/asm00_0_sound_800068A_rominc.s $(CDIR)/asm00_0_musicGameState_8000784_rominc.s $(CDIR)/asm00_0_sub_80007A0_rominc.s $(CDIR)/asm00_0_zeroFill_80007B2_rominc.s $(CDIR)/asm00_0_sound_8000808_rominc.s $(CDIR)/asm00_2_sub_800ED80.s $(CDIR)/battle_core_initbattle_rominc.s $(CDIR)/battle_core_loadchipdata_rominc.s

$(CDIR)/%.i: $(CDIR)/%.c $(INC)/asm00_0_sound.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/battle_core_initbattle.i: $(CDIR)/battle_core_initbattle.c $(INC)/battle_core_initbattle.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/battle_core_loadchipdata.i: $(CDIR)/battle_core_loadchipdata.c $(INC)/battle_core_loadchipdata.h
	$(CPP) -undef -nostdinc -I$(INC) $< -o $@

$(CDIR)/asm00_2_sub_800ED80.i: $(CDIR)/asm00_2_sub_800ED80.c $(INC)/asm00_2_ai.h
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

$(CDIR)/asm00_0_sound_8000808.s: $(CDIR)/asm00_0_sound_8000808.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_8000808.py $@

$(CDIR)/asm00_0_sound_8000808_rominc.s: $(CDIR)/asm00_0_sound_8000808.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sound_8000808_rominc.py $@

$(CDIR)/asm00_2_sub_800ED80.s: $(CDIR)/asm00_2_sub_800ED80.i
	$(AGBCC) -O2 -mthumb-interwork $< -o $@
	python3 tools/fix_agbcc_sub_800ED80.py $@

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
