#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

#if defined(jpn)
enum { SelectedEntryOffset = 0x5a7a, PackedEntriesOffset = 0x5a7c };
#else
enum { SelectedEntryOffset = 0x5cda, PackedEntriesOffset = 0x5cdc };
#endif

struct Struct0208e9f4;
void InitDefaults0208e9f4(struct Struct0208e9f4*);

void SetByte0x5cdaAndClearField0xa(unsigned char* obj, unsigned char value);
extern "C" void func_0208ec04(struct Struct0208e9f4*);
extern "C" void* func_0208e0a8(void);
extern "C" int rand(void);

struct ResetStruct0208ea10;
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct0208ea10*, int*);

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* _Z13GetFileInNarcPKvPKcPS0_Pjj(const void*, const char*, void**, void**, unsigned int);

extern "C" void __clear(void*, int);
extern "C" int sprintf(char*, const char*, ...);

extern int data_020f1308;
extern char data_020f1330[];
extern char data_020f134a[];
extern char data_020f1356[];
extern char data_0211e33c[];

struct Fields0208ea10 {
    unsigned int low9 : 9;
    unsigned int nibA : 4;
    unsigned int nibB : 4;
    unsigned int id8 : 8;
    unsigned int type4 : 4;
    unsigned int kind : 2;
    unsigned int flag : 1;
};

struct Entry0208ea10 {
    union {
        unsigned int raw;
        struct Fields0208ea10 b;
    } u;
};

// USA: func_0208ea10
extern "C" ARM void func_0208ea10(void* p0, int a1) {
    char scriptFirst[0x430];
    char scriptLoop[0x430];
    char name[0x40];
    unsigned int fileLen;
    unsigned int size;
    void* ptr;

    unsigned char* gs = (unsigned char*)GameState::GetInstance();

    if (gs[SelectedEntryOffset] == 8) {
        InitDefaults0208e9f4((struct Struct0208e9f4*)p0);
        SetByte0x5cdaAndClearField0xa(gs, rand() % 8);
    } else {
        func_0208ec04((struct Struct0208e9f4*)p0);
        return;
    }

    BackgroundLoader::AddLockGlobal();
    __clear(name, 0x40);
    fileLen = 0;

    if (LoadFileIntoMemory(data_020f1330, data_0211e33c, &fileLen) != 0) {
        if (_Z13GetFileInNarcPKvPKcPS0_Pjj(data_0211e33c, data_020f134a, (void**)&ptr, (void**)&size, 0) != 0) {
            ((Script*)((struct ResetStruct0208ea10*)scriptFirst))->Initialize();
            _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct0208ea10*)scriptFirst, &data_020f1308);
            ((Script*)((struct ResetStruct0208ea10*)scriptFirst))->Load(ptr, size);
            ((Script*)((struct ResetStruct0208ea10*)scriptFirst))->Execute();
            ((unsigned char*)func_0208e0a8())[0xa] = 1;
        }

        int i;
        for (i = 1; i <= 0x3f; i++) {
            sprintf(name, data_020f1356, i);
            fileLen = 0;
            if (_Z13GetFileInNarcPKvPKcPS0_Pjj(data_0211e33c, name, (void**)&ptr, (void**)&size, 0) != 0) {
                ((Script*)((struct ResetStruct0208ea10*)scriptLoop))->Initialize();
                _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct0208ea10*)scriptLoop, &data_020f1308);
                ((Script*)((struct ResetStruct0208ea10*)scriptLoop))->Load(ptr, size);
                ((Script*)((struct ResetStruct0208ea10*)scriptLoop))->Execute();
            }
        }

        int j;
        for (j = 0; j < 2; j++) {
            struct Entry0208ea10* e = &((struct Entry0208ea10*)(gs + PackedEntriesOffset))[j + 0x62];
            e->u.b.flag = 1;
            e->u.b.type4 = 2;
            e->u.b.nibA = 1;
            e->u.b.nibB = 1;
            e->u.b.kind = 1;
            e->u.b.low9 = 0;
            e->u.raw &= 0xfe01ffff;
        }
    }

    BackgroundLoader::RemoveLockGlobal();
}
