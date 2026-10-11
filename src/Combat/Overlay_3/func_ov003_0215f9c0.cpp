#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"

#if defined(jpn)
enum { kRegionValue226_10E = 0x10e };
#else
enum { kRegionValue226_10E = 0x226 };
#endif


struct Struct020dfc40 {
    char unk_0[0x18];
};
struct MainBgControlBackup02074af4 {
    unsigned short savedBgCnt[8];
    unsigned char initialized;
    unsigned char unk_11;
    char unk_12[2];
};
struct Obj02081ee4 {
    char unk_0[0xc];
};
struct Sub02081ee4 {
    char unk_0[4];
};
struct Struct020a9ea4 {
    char unk_0[8];
};

extern "C" void func_02074af4(struct MainBgControlBackup02074af4* obj);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);
extern "C" void _Z19InitWithSub02081ee4P11Obj02081ee4P11Sub02081ee4(struct Obj02081ee4* obj, struct Sub02081ee4* sub);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(struct Struct020dfc40* p);
extern "C" void _Z19ClearStruct020a9ea4P14Struct020a9ea4(struct Struct020a9ea4* p);

struct BattleScreen_0215f9c0 {
    char buffer[kRegionValue226_10E];
    unsigned short unk_226;
    SafeAllocator allocA;
    SafeAllocator allocB;
    SafeAllocator unk_250;
    SafeAllocator allocC;
    SafeAllocator allocD;
    SafeAllocator allocE;
    SafeAllocator allocF;
    SafeAllocator allocG;
    char unk_2c8[0x2dc - 0x2c8];
    struct Struct020dfc40 unk_2dc;
    struct MainBgControlBackup02074af4 bgBackup;
    struct Obj02081ee4 unk_308;
    struct Sub02081ee4 unk_314;
    int unk_318;
    int unk_31c;
    int unk_320;
    int unk_324;
    int unk_328;
    int unk_32c;
    int savedBgMode;
    char unk_334[0x388 - 0x334];
    int unk_388;
    char unk_38c[4];
    int unk_390;
    int unk_394;
    int unk_398;
#if !defined(jpn)
    char unk_39c[0x45c - 0x39c];
#endif
    int unk_45c;
    int unk_460;
    int flags;
    unsigned char unk_468[4];
    int unk_46c;
    int unk_470;
    short unk_474;
    short unk_476;
    short unk_478;
    short unk_47a;
    short unk_47c;
    short unk_47e;
    short unk_480;
    short unk_482;
    short unk_484;
    short unk_486;
    short unk_488;
    short unk_48a;
    char unk_48c[2];
    short unk_48e;
    short unk_490;
    short unk_492;
    short unk_494;
    short unk_496;
    short unk_498;
    short unk_49a;
    short unk_49c;
    char unk_49e;
    unsigned char unk_49f;
    unsigned char unk_4a0;
    unsigned char unk_4a1;
    signed char unk_4a2;
    unsigned char unk_4a3;
    unsigned char unk_4a4;
    unsigned char unk_4a5;
    unsigned char unk_4a6;
    unsigned char unk_4a7;
    unsigned char unk_4a8;
    char unk_4a9[0x4b0 - 0x4a9];
    int unk_4b0;
    struct Struct020a9ea4 unk_4b4;
    unsigned char unk_4bc;
    unsigned char unk_4bd;
    unsigned char unk_4be;
    unsigned char unk_4bf;
    unsigned char unk_4c0;
};

// USA: func_ov003_0215f9c0
// JPN: func_ov003_0215fb74
extern "C" ARM void func_ov003_0215f9c0(struct BattleScreen_0215f9c0* self, int setFlags) {
    memset(self->buffer, 0, sizeof(self->buffer));
    self->unk_226 = 0;
    self->allocA.ResetAllocatorPointer();
    self->allocB.ResetAllocatorPointer();
    self->allocC.ResetAllocatorPointer();
    self->allocD.ResetAllocatorPointer();
    self->allocE.ResetAllocatorPointer();
    self->allocF.ResetAllocatorPointer();
    self->allocG.ResetAllocatorPointer();
    self->bgBackup.initialized = 0;
    self->bgBackup.unk_11 = 0;
    func_02074af4(&self->bgBackup);
    self->savedBgMode = (DISPCNT & 0x1f00) >> 8;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
    _Z18InitStruct0205a444Pc(self->unk_334);
    self->unk_388 = 0;
    _Z19InitWithSub02081ee4P11Obj02081ee4P11Sub02081ee4(&self->unk_308, &self->unk_314);
    _Z19ResetStruct020dfc40P14Struct020dfc40(&self->unk_2dc);
    self->unk_318 = 0;
    self->unk_31c = 0;
    self->unk_320 = 0;
    self->unk_324 = 0;
    self->unk_328 = 0;
    self->unk_32c = 0;
    self->unk_390 = 0;
    self->unk_394 = 0;
    self->unk_398 = 0;
    self->unk_45c = 0;
    self->unk_460 = 0;
    self->flags = 0;
    memset(self->unk_468, 0, sizeof(self->unk_468));
    self->unk_46c = -1;
    self->unk_470 = 0;
    self->unk_474 = -1;
    self->unk_476 = 0;
    self->unk_478 = 0;
    self->unk_47a = 0;
    self->unk_47c = -1;
    self->unk_47e = -1;
    self->unk_480 = -1;
    self->unk_482 = -1;
    self->unk_484 = self->unk_486 = -1;
    self->unk_48a = -1;
    self->unk_48e = -1;
    self->unk_490 = -1;
    self->unk_492 = -1;
    self->unk_494 = -1;
    self->unk_496 = -1;
    self->unk_498 = -1;
    self->unk_49a = -1;
    self->unk_49c = -1;
    self->unk_488 = -1;
    self->unk_49f = 0;
    self->unk_4a0 = 0;
    self->unk_4a1 = 0;
    self->unk_4a2 = -1;
    self->unk_4a3 = 0;
    self->unk_4a4 = 0;
    self->unk_4a5 = 0;
    self->unk_4a6 = 0;
    self->unk_4a7 = 0;
    self->unk_4a8 = 0;
    self->unk_4b0 = 0;
    _Z19ClearStruct020a9ea4P14Struct020a9ea4(&self->unk_4b4);
    self->unk_4bc = 0;
    if (setFlags) {
        self->flags |= 0x30000;
    }
    self->unk_4bd = 0xff;
    self->unk_4be = 0;
    self->unk_4bf = 0;
    self->unk_4c0 = 0;
}
