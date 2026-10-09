#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"

struct Block0207df50 {
    unsigned int v[10];
};

struct Pair0207df50 {
    unsigned int v[2];
};

struct Foo0207df50 {
    struct Block0207df50 a;
    struct Block0207df50 b;
    unsigned int c;
    unsigned int d;
    struct Pair0207df50 p1;
    struct Pair0207df50 p2;
    unsigned int e;
    unsigned int f;
};

struct BattleResources {
    char pad0[0x2cc];
    struct Foo0207df50 pairTables[28];
};

struct BattleScreen {
    char pad0[0x14c];
    struct Foo0207df50 pairTables;
    char pad1BC[0x36f0 - 0x1bc];
    char workBuf[0x800];
};

extern "C" BattleResources* func_ov017_0218b5b0(void);
extern "C" char* func_0203bd08(void);
int* GetGlobalPtr02105244();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void _Z25ConfigurePairMode020bb48cji(unsigned int mode, int installHandlers);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void MapVRAMBanksToSubBG(int value);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50* p);
extern "C" void _Z25InitBattleContext0203bd24Pc(char* context);
extern "C" void func_0203c35c(int* ptr);
extern "C" void _Z21ClearFlag320_02195540Ph(unsigned char* obj);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void func_0207de48(void* p, int a, int b);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);

// USA: func_ov000_02164280
extern "C" ARM void func_ov000_02164280(BattleScreen* screen) {
    BattleResources* res = func_ov017_0218b5b0();
    char* context = func_0203bd08();
    int* global = GetGlobalPtr02105244();
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(7);
    _Z25ConfigurePairMode020bb48cji(3, 1);
    MapVRAMBanksToSubObj(8);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & 0xffcfffef) | 0x10 | 0x200000;
    MapVRAMBanksToSubBG(0x180);

    screen->pairTables.a = res->pairTables[27].a;
    screen->pairTables.b = res->pairTables[27].b;
    screen->pairTables.c = res->pairTables[27].c;
    screen->pairTables.d = res->pairTables[27].d;
    screen->pairTables.p1 = res->pairTables[27].p1;
    screen->pairTables.p2 = res->pairTables[27].p2;
    screen->pairTables.e = res->pairTables[27].e;
    screen->pairTables.f = res->pairTables[27].f;
    _Z26CopyInternalFields0207df50P11Foo0207df50(&screen->pairTables);

    _Z25InitBattleContext0203bd24Pc(context);
    func_0203c35c(global);
    _Z21ClearFlag320_02195540Ph((unsigned char*)res);
    _Z26CopyInternalFields0207df50P11Foo0207df50(res->pairTables);
    _Z25RestorePairTables0207df90Pc((char*)res->pairTables);
    func_0207de48(screen->workBuf, 0x18000, 0x800);
    _Z24BackupPairTables0207dfacPc((char*)res->pairTables);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
}
