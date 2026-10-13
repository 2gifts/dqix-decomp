#include <globaldefs.h>
#if defined(jpn)
#include "Filesystem/FileIO.h"
extern char data_ov004_02170cbc;
int ApplyNodeUpdater020e038c(void*, void*, int);
#endif
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

#if defined(jpn)
struct Element020e0310 { int key; int value; };
struct Container020e0310 {
    unsigned int count : 12;
    unsigned int rest : 20;
    Element020e0310* base;
};
typedef Container020e0310 NameTable0215bf94;
#else
struct NameEntry0215bf94 {
    void* first;
    void* second;
    unsigned int unknown8;
    unsigned short key;
    unsigned short unknownE;
};
struct NameTable0215bf94 {
    unsigned int count : 12;
    unsigned int rest : 20;
    NameEntry0215bf94* entries;
};
#endif
struct ItemNameLoader0215bf94 {
    unsigned char unknown0[0x2d];
    unsigned char mode;
    unsigned char unknown2e[0x8c - 0x2e];
    NameTable0215bf94 names;
#if defined(jpn)
    unsigned char unknown94[0x10];
#else
    unsigned char unknown94[4];
#endif
    void* fileBuffer;
};
struct Struct021707d8_0215bf94 { char pad[8]; ItemNameLoader0215bf94* ptr; };
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
    struct DispatchState0215bf94 {
        unsigned char unknown0[0xd];
        unsigned char state : 7;
        unsigned char unknownHighBit : 1;
    };
    struct GlobalState0215bf94 {
        unsigned char unknown0[8];
        DispatchState0215bf94* current;
    };
    GlobalState0215bf94* owner = (GlobalState0215bf94*)func_02012fe4();
    unsigned char v = owner->current->state;
    SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&data_02109bf4, v);
    SetModeClamped0209ca70(&data_02109bf4, data_ov004_021707d8.ptr->mode);
    OrGlobalFlag0x40();
#if defined(jpn)
    unsigned int size;
    LoadFileIntoMemory(&data_ov004_02170cbc, data_ov004_021707d8.ptr->fileBuffer, &size);
    ApplyNodeUpdater020e038c(&data_ov004_021707d8.ptr->names, data_ov004_021707d8.ptr->fileBuffer, (int)size);
#else
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* buf = ExtractFileFromGP2(&data_ov004_021703d7, &data_ov004_021703ed, &size);
    if (size <= 0x10800) {
        memcpy(data_ov004_021707d8.ptr->fileBuffer, buf, size);
        TryInvoke020e53bc(&data_ov004_021707d8.ptr->names, (int)data_ov004_021707d8.ptr->fileBuffer, (int)size);
    }
    BackgroundLoader::RemoveLockGlobal();
#endif
    return 0;
}
