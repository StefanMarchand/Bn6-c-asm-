# Minimal placeholder build system for BN6 C+ASM project
# This is a stopgap so `make` produces a deterministic test ROM and
# updates build_status.json. It does NOT yet build the real BN6 ROM.

ROM_NAME := bn6f
ROM_FILE := $(ROM_NAME).gba

.PHONY: all clean

all: $(ROM_FILE) build_status.json

# For now, create a small dummy GBA ROM image so the pipeline exists.
# Later this will be replaced with a real ARM build (ASM + C).
$(ROM_FILE):
	@echo "[build] Generating placeholder $(ROM_FILE)"
	@# 1MB zero-filled placeholder
	@dd if=/dev/zero of=$(ROM_FILE) bs=1K count=1024 status=none

build_status.json: $(ROM_FILE)
	@echo "[status] Updating build_status.json"
	@SHA1=$$(sha1sum $(ROM_FILE) | cut -d' ' -f1); \
	TIMESTAMP=$$(date -u +"%Y-%m-%dT%H:%M:%SZ"); \
	SHA1="$$SHA1" TIMESTAMP="$$TIMESTAMP" python3 tools/update_build_status.py

clean:
	@echo "[clean] Removing build artifacts"
	@rm -f $(ROM_FILE) build_status.json
