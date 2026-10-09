#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "System/BGBases.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include "std_library_functions.h"

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};

struct Word0x0_0215e5b0 {
    char pad0[0x2c];
    void* record;
};

struct Word0x0_0215e5b0* GetWord0x0(int* obj);
extern "C" void _Z25SetSubBg0Control_0215e758iiiii(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void _Z25SetSubBg1Control_0215e78ciiiii(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* obj);
extern "C" void func_0204b174(void* list, void* rec, void* alloc, int size);

extern char data_0211e33c[] __attribute__((aligned(4)));

// USA: func_ov001_0215e5b0
extern "C" ARM int func_ov001_0215e5b0(void) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    struct Word0x0_0215e5b0* word = GetWord0x0((int*)GameState::GetInstance());

    char* buf = data_0211e33c;
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0x1f00) | 0x300;
    _Z25SetSubBg0Control_0215e758iiiii(0, 0, 0xe, 0, 0);
    _Z25SetSubBg1Control_0215e78ciiiii(0, 0, 0xf, 0, 0);

    volatile unsigned short* bgcnt = (volatile unsigned short*)0x4001008;
    bgcnt[0] = (bgcnt[0] & ~3);
    bgcnt[1] = (bgcnt[1] & ~3) | 1;
    bgcnt[2] = (bgcnt[2] & ~3) | 2;
    bgcnt[3] = (bgcnt[3] & ~3) | 3;

    *(volatile unsigned int*)0x4000010 = 0;
    *(volatile unsigned int*)0x4000014 = 0;
    *(volatile unsigned short*)0x4001050 = 0;

    struct List0204af64 list;
    _Z17ResetList0204af64P12List0204af64(&list);
    list.b1c_lo = 1;
    func_0204b174(&list, word->record, 0, 0);

    unsigned int size = 0x6400;
    memset(buf, 0, size);
    memset(buf + 0x20, 0x11111111, 0x20);
    CleanInvalidateCacheRange(buf, size);
    LoadToSubBG0CharacterData(buf, 0, size);

    unsigned short* screen = (unsigned short*)GetSubBG0ScreenBase();
    unsigned short tile = 3;
    for (unsigned short i = 0; i < 0x300; i++) {
        *screen++ = tile;
        tile++;
    }

    screen = (unsigned short*)GetSubBG1ScreenBase();
    for (unsigned short i = 0; i < 0x300; i++) {
        *screen++ = 1;
    }

    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
