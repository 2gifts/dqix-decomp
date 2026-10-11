#if defined(jpn)
#define R(j,u) (j)
#define _Z23EmptyDestructor0205cb60Pv func_0205deb8
#define _Z25ResetDisplayState02155480P11Obj02155480 func_ov006_02156b68
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#define func_ov006_021570fc func_ov006_02158704
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

int GetGlobal02109400(void);
void BlankFunction02094b38(void);

struct Obj02094ab0;
extern "C" void func_02094ab0(struct Obj02094ab0* obj);

struct EntryList0204af14;
void* GetEntryByIndexStride0x10(struct EntryList0204af14* list, unsigned int index);

void CleanInvalidateCacheRange(const void* where, unsigned int len);
extern "C" void LoadToMainBG1CharacterData(int, int, unsigned int);

struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8* obj, void* buf);

struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);

struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4* obj);


// USA: func_ov013_02186fa0  (semantic: ResetAndFlushDisplayState02186fa0)
extern "C" ARM void func_ov013_02186fa0(unsigned char* obj) {
    struct Obj02094ab0* g = (struct Obj02094ab0*)GetGlobal02109400();
    ((void(*)(void*, int))&BlankFunction02094b38)(g, 0x68);
    func_02094ab0(g);

    if (obj[R(0x50,0x64)] == 0) {
        void* entry = GetEntryByIndexStride0x10((struct EntryList0204af14*)(obj + 0x28), 0);
        void* buf;
        if (entry != 0 && (buf = *(void**)((char*)entry + 0xc)) != 0) {
            memset(buf, 0, 0x600);
            CleanInvalidateCacheRange(buf, 0x20);
            LoadToMainBG1CharacterData((int)buf, 0, 0x20);
            FlushAndDispatchList0204b0e8((struct List0204b0e8*)(obj + 0x28), buf);
        }

        ClearFlag0x10IfSet((struct Struct02074bd0*)(obj + 0x14));
        {
            volatile unsigned int* reg = (unsigned int*)0x4000000;
            *reg = (*reg & ~0x1f00) | (*(unsigned int*)(obj + R(0x4c,0x60)) << 8);
        }
    } else {
        ClearFlag0x11IfSet((struct Struct02074bf4*)(obj + 0x14));
        {
            volatile unsigned int* reg = (unsigned int*)0x4001000;
            *reg = (*reg & ~0x1f00) | (*(unsigned int*)(obj + R(0x4c,0x60)) << 8);
        }
    }

    if (*(int*)(obj + R(0x48,0x5c)) >= 0) {
        int a = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(a))->RemoveTask((int)(*(int*)(obj + R(0x48,0x5c))));
        *(int*)(obj + R(0x48,0x5c)) = -1;
    }

    if (*(void**)(obj + 0x0) == 0) return;

    unsigned char i;
    for (i = 0; i < R(4,5); i++) {
        ((SafeAllocator*)(*(void**)(obj + 0x0)))[i].Destroy();
    }
}
