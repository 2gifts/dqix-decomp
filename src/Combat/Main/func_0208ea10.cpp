#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { SelectedEntryOffset = 0x5a7a, PackedEntriesOffset = 0x5a7c };
#else
enum { SelectedEntryOffset = 0x5cda, PackedEntriesOffset = 0x5cdc };
#endif

extern "C" int _ZN9GameState11GetInstanceEv();

struct Struct0208e9f4;
extern "C" void _Z20InitDefaults0208e9f4P14Struct0208e9f4(struct Struct0208e9f4*);

extern "C" void _Z29SetByte0x5cdaAndClearField0xaPhh(unsigned char* obj, unsigned char value);
extern "C" void func_0208ec04(struct Struct0208e9f4*);
extern "C" void* func_0208e0a8(void);
extern "C" int rand(void);

struct ResetStruct0208ea10;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct0208ea10*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct0208ea10*, int*);
extern "C" int _ZN6Script4LoadEPKvj(struct ResetStruct0208ea10*, const void*, unsigned int);
extern "C" int _ZN6Script7ExecuteEv(struct ResetStruct0208ea10*);

extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*, void*, unsigned int*);
extern "C" void* _Z13GetFileInNarcPKvPKcPS0_Pjj(const void*, const char*, void**, void**, unsigned int);

extern "C" void __clear(void*, int);
extern "C" int sprintf(char*, const char*, ...);

extern int data_020f1308;
extern char data_020f1330[];
extern char data_020f134a[];
extern char data_020f1356[];
extern char data_0211e33c[];

extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv(void);

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
// JPN: func_0208ea10
extern "C" ARM void func_0208ea10(void* p0, int a1) {
    char scriptFirst[0x430];
    char scriptLoop[0x430];
    char name[0x40];
    unsigned int fileLen;
    unsigned int size;
    void* ptr;

    unsigned char* gs = (unsigned char*)_ZN9GameState11GetInstanceEv();

    if (gs[SelectedEntryOffset] == 8) {
        _Z20InitDefaults0208e9f4P14Struct0208e9f4((struct Struct0208e9f4*)p0);
        _Z29SetByte0x5cdaAndClearField0xaPhh(gs, rand() % 8);
    } else {
        func_0208ec04((struct Struct0208e9f4*)p0);
        return;
    }

    _ZN16BackgroundLoader13AddLockGlobalEv();
    __clear(name, 0x40);
    fileLen = 0;

    if (_Z18LoadFileIntoMemoryPKcPvPj(data_020f1330, data_0211e33c, &fileLen) != 0) {
        if (_Z13GetFileInNarcPKvPKcPS0_Pjj(data_0211e33c, data_020f134a, (void**)&ptr, (void**)&size, 0) != 0) {
            _ZN6Script10InitializeEv((struct ResetStruct0208ea10*)scriptFirst);
            _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct0208ea10*)scriptFirst, &data_020f1308);
            _ZN6Script4LoadEPKvj((struct ResetStruct0208ea10*)scriptFirst, ptr, size);
            _ZN6Script7ExecuteEv((struct ResetStruct0208ea10*)scriptFirst);
            ((unsigned char*)func_0208e0a8())[0xa] = 1;
        }

        int i;
        for (i = 1; i <= 0x3f; i++) {
            sprintf(name, data_020f1356, i);
            fileLen = 0;
            if (_Z13GetFileInNarcPKvPKcPS0_Pjj(data_0211e33c, name, (void**)&ptr, (void**)&size, 0) != 0) {
                _ZN6Script10InitializeEv((struct ResetStruct0208ea10*)scriptLoop);
                _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct0208ea10*)scriptLoop, &data_020f1308);
                _ZN6Script4LoadEPKvj((struct ResetStruct0208ea10*)scriptLoop, ptr, size);
                _ZN6Script7ExecuteEv((struct ResetStruct0208ea10*)scriptLoop);
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

    _ZN16BackgroundLoader16RemoveLockGlobalEv();
}
