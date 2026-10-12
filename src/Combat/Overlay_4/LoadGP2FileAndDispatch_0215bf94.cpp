#include <globaldefs.h>
#if defined(jpn)
#include "Filesystem/FileIO.h"
extern char data_ov004_02170cbc;
int ApplyNodeUpdater020e038c(void*, void*, int);
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct Struct021707d8_0215bf94 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215bf94 data_ov004_021707d8;

extern int data_02109bf4;
extern char data_ov004_021703d7;
extern char data_ov004_021703ed;

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG3ScreenBase(void);
extern "C" void* func_02012fe4(void);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
void SetModeClamped0209ca70(void* obj, int val);
void OrGlobalFlag0x40(void);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
int TryInvoke020e53bc(void* a0, int a1, int a2);

#if defined(jpn)
// USA: func_ov004_0215bf94
extern "C" ARM int func_ov004_0215cfdc() {
#else
// USA: func_ov004_0215bf94
ARM int LoadGP2FileAndDispatch_0215bf94() {
#endif
    unsigned short* bg0 = (unsigned short*)GetSubBG0ScreenBase();
    int i;
    for (i = 0; i < 0x800; i++) {
        *bg0++ = 0;
    }
    memset((void*)GetMainBG3ScreenBase(), 0, 0x1000);
    struct Bits0215bf94 { unsigned char low7 : 7; unsigned char hi1 : 1; };
    void* g = func_02012fe4();
    Bits0215bf94* p2 = *(Bits0215bf94**)((char*)g + 8);
    unsigned char v = ((Bits0215bf94*)((char*)p2 + 0xd))->low7;
    SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&data_02109bf4, v);
    SetModeClamped0209ca70(&data_02109bf4, data_ov004_021707d8.ptr[0x2d]);
    OrGlobalFlag0x40();
#if defined(jpn)
    unsigned int size;
    LoadFileIntoMemory(&data_ov004_02170cbc, *(void**)(data_ov004_021707d8.ptr + 0xa4), &size);
    ApplyNodeUpdater020e038c(data_ov004_021707d8.ptr + 0x8c, *(void**)(data_ov004_021707d8.ptr + 0xa4), (int)size);
#else
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* buf = ExtractFileFromGP2(&data_ov004_021703d7, &data_ov004_021703ed, &size);
    if (size <= 0x10800) {
        memcpy(*(void**)(data_ov004_021707d8.ptr + 0x98), buf, size);
        TryInvoke020e53bc(data_ov004_021707d8.ptr + 0x8c, (int)*(void**)(data_ov004_021707d8.ptr + 0x98), (int)size);
    }
    BackgroundLoader::RemoveLockGlobal();
#endif
    return 0;
}
