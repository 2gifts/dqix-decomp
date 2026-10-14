#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_021864f0 func_ov013_02187820
#define func_ov013_02186590 func_ov013_021878c0
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
void* GetDataPtr02114e04_020d6c00();
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
void ClearBitsInWord_0203b4b0(unsigned int* p, unsigned int mask);

struct Manager0218b240 {
    char pad0[R(0xe95,0xe99)];
    unsigned char e99;
    unsigned char e9a;
    unsigned char e9b;
    unsigned char e9c;
    char pad1[0xea0 - 0xe9d];
    int ea0;
    int ea4;
    int ea8;
    char pad2[R(4,0xeb4 - 0xeac)];
    int eb4;
    char pad3[0xec0 - 0xeb8];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char rest : 4;
};

// USA: func_ov008_0218b240  (semantic: ResetLoaderState_0218b240)
extern "C" ARM void func_ov008_0218b240(Manager0218b240* obj) {
    if (obj->bit3) return;

    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    obj->bit0 = 0;
    ResetEntryList0205d6a0((Entry_0205d6a0*)((char*)obj + 0x18), 1);

    obj->e99 = 2;
    obj->e9a = 0;
    obj->e9b = 2;
    obj->e9c = 0;

    void* ptr = GetDataPtr02114e04_020d6c00();
    ClearFlags020466f4((FlagWord020466f4*)ptr, 0x2f);
    ClearBitsInWord_0203b4b0((unsigned int*)func_ov017_0218b5b0(), 0x10);

    loader->RemoveTask(obj->ea0);
    loader->RemoveTask(obj->eb4);
    loader->RemoveTask(obj->ea4);
    loader->RemoveTask(obj->ea8);

    obj->ea0 = -1;
    obj->eb4 = -1;
    obj->ea4 = -1;
    obj->ea8 = -1;

    obj->bit3 = 1;
}
