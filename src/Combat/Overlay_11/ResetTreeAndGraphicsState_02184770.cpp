#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" int func_ov017_021959b4(void);
void DestroyTreeNode_02184604(void* self, unsigned char* node);

struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4* obj);

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToMainBG1ScreenData(void* p, int a, int b);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" int func_ov017_0218b5b0(void);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);

extern char data_0211e33c[];

// USA: func_ov011_02184770  (semantic: ResetTreeAndGraphicsState_02184770)
extern "C" ARM void func_ov011_02184770(char* self) {
    if (func_ov017_021959b4() != 0 && *(void(**)(void*))(self + 0x1dc) != 0) {
        (*(void(**)(void*))(self + 0x1dc))(self);
    }
    *(void**)(self + 0x1dc) = 0;
    DestroyTreeNode_02184604(self, (unsigned char*)self);

    volatile unsigned int* regA = (volatile unsigned int*)0x4000000;
    *regA = (*regA & ~0x1f00) | 0x100;

    ClearFlag0x10IfSet((struct Struct02074bd0*)(self + 0x194));
    ClearFlag0x11IfSet((struct Struct02074bf4*)(self + 0x194));

    volatile unsigned short* reg304 = (volatile unsigned short*)0x4000304;
    int flag190 = *(int*)(self + 0x190);
    *reg304 = (flag190 << 15) | (*reg304 & ~0x8000);

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    void* buf = data_0211e33c;
    memset(buf, 0, 0x600);
    CleanInvalidateCacheRange(buf, 0x20);
    LoadToMainBG1CharacterData((int)buf, 0, 0x20);
    CleanInvalidateCacheRange(buf, 0x600);
    LoadToMainBG1ScreenData(buf, 0, 0x600);

    unsigned int f1a8 = *(unsigned int*)(self + 0x1a8);
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg0 = (f1a8 << 8) | (*reg0 & ~0x1f00);
    unsigned int f1ac = *(unsigned int*)(self + 0x1ac);
    *reg1000 = (f1ac << 8) | (*reg1000 & ~0x1f00);

    int listPtr = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(self + 0x118);
    ((BackgroundLoader*)(listPtr))->RemoveTask((int)(key));

    BackgroundLoader::RemoveLockGlobal();
    ClearBitsInField4_0203b4e8((unsigned int*)func_ov017_0218b5b0(), 0xc0);
}
