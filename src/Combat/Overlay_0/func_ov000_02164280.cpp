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
#if defined(jpn)
    char pad0[0x27c];
#else
    char pad0[0x2cc];
#endif
    struct Foo0207df50 pairTables[28];
};

struct BattleScreen {
#if defined(jpn)
    char pad0[0x138];
#else
    char pad0[0x14c];
#endif
    struct Foo0207df50 pairTables;
#if defined(jpn)
    char pad1BC[0x36ac - 0x1a8];
#else
    char pad1BC[0x36f0 - 0x1bc];
#endif
    char workBuf[0x800];
};

extern "C" BattleResources* func_ov017_0218b5b0(void);
extern "C" char* func_0203bd08(void);
int* GetGlobalPtr02105244_0203bd14();
extern "C" void MapVRAMBanksToTextureImage(int handle);
void ConfigurePairMode020bb48c(unsigned int mode, int installHandlers);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void MapVRAMBanksToSubBG(int value);
void CopyInternalFields0207df50(struct Foo0207df50* p);
void InitBattleContext0203bd24(char* context);
extern "C" void func_0203c35c(int* ptr);
void ClearFlag320_02195540(unsigned char* obj);
void RestorePairTables0207df90(char* obj);
extern "C" void func_0207de48(void* p, int a, int b);
void BackupPairTables0207dfac(char* obj);

// USA: func_ov000_02164280
extern "C" ARM void func_ov000_02164280(BattleScreen* screen) {
    BattleResources* res = func_ov017_0218b5b0();
    char* context = func_0203bd08();
    int* global = GetGlobalPtr02105244_0203bd14();
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(7);
    ConfigurePairMode020bb48c(3, 1);
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
    CopyInternalFields0207df50(&screen->pairTables);

    InitBattleContext0203bd24(context);
    func_0203c35c(global);
    ClearFlag320_02195540((unsigned char*)res);
    CopyInternalFields0207df50(res->pairTables);
    RestorePairTables0207df90((char*)res->pairTables);
    func_0207de48(screen->workBuf, 0x18000, 0x800);
    BackupPairTables0207dfac((char*)res->pairTables);
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
}
