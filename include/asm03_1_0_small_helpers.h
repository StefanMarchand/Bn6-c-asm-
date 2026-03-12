struct S2011E30PetUpdateSmall {
    unsigned char state;
};

struct GameStateJackIn {
    unsigned char pad0[0x12];
    unsigned char enterMapFadeParam1;
    unsigned char enterMapFadeParam2;
};

register struct S2011E30PetUpdateSmall *gPetUpdateSmall asm("r5");
register struct ToolkitJackIn {
    unsigned char pad0[0x28];
    unsigned char *mainJumptableIndexPtr;
    unsigned char pad1[0x10];
    struct GameStateJackIn *gameState;
} *gToolkitJackIn asm("r10");

void ZeroFillByWord(void *memBlock, int size);
void zeroFillVRAM(void);
void ZeroFillGFX30025c0(void);
void map_triggerEnterMapOnWarp_8005C04(void);
void navi_80340F6(void);

extern unsigned char byte_2011A40[];
extern unsigned char byte_80984C8[];
extern unsigned int dword_2000DC0[];
