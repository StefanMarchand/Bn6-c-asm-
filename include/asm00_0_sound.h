#ifndef ASM00_0_SOUND_H
#define ASM00_0_SOUND_H

struct GameState {
    unsigned char pad[0xF];
    unsigned char bgMusicIndicator;
};

struct Toolkit {
    unsigned char pad[0x3C];
    struct GameState *gameState;
};

register struct Toolkit *gToolkit asm("r10");

extern unsigned char byte_2010B90[];
extern void *off_8000704[];
extern int dword_200A490[];

int m4aSoundMain(void);
int call_m4aSoundMain(void);
int m4a_2_814F00C(void);
int call_m4a_2_814F00C(void);
void ZeroFillByWord(void *memBlock, int size);
int sub_814E9F0(void);
int sub_814E87C(void);
int sub_814EA58(void);
int sub_814F988(void);
int sub_814F9AC(void);
int sub_814FA14(void);
int sound_8000808(int value, int unused1, int unused2, int (*handler)(void));
int sound_8000822(int value, int bgMusicIndicator);
int m4a_800061E(int songId, int unused1, int unused2);
int sound_8000630(int songId, int unused1, int unused2);
int PlaySoundEffect(int songId, int unused1, int unused2);
int PlayMusic(int songId, int unused1, int unused2);
int music_80005F2(int songId, int previousSong, int unused2);
int sub_800060A(int value, int unused1, int unused2);
int sound_8000642(int index, int unused1, int unused2);
int sound_800065A(int index, int unused1, int unused2);
int sound_8000672(int index, int unused1, int unused2);
int sound_800068A(int index, int unused1, int unused2);
int musicGameState_8000784(int songId, int unused1, int unused2);
int sub_80007A0(int value, int unused1, int unused2);
void zeroFill_80007B2(void);

#endif
