#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include "std_library_functions.h"

struct StreamHeader0208d82c;
extern "C" void _Z24InitStreamHeader0208d82cP20StreamHeader0208d82c(struct StreamHeader0208d82c* header);
int* GetGlobal02109418(void);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
void SetFieldsAt0x4And0x8(int* obj, int a, int b);
extern "C" void* func_0205ec34(void);
extern "C" void func_020956b8(int* g, void* p);
extern "C" void func_02095b30(int* g, int v);
extern "C" void* func_ov011_021845f8(void* obj, int key);
extern "C" void* _Z40CheckTypeAndReturnNode_02165e70_02165e70Pvi(void* obj, int type);

extern void* data_ov004_0217101c[2];
extern int data_ov004_0217059c;

struct Flags02166844 {
    char pad[0x50];
    unsigned char loFlags : 6;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

// USA: func_ov004_02166844
extern "C" ARM int func_ov004_02166844(void* a1) {
    char* node;
    data_ov004_0217101c[0] = 0;
    int* g = GetGlobal02109418();
    char* c = (char*)func_0205ec34();
    node = (char*)func_ov011_021845f8(a1, 0);
    if (node == 0) {
        return 0;
    }

    data_ov004_0217101c[0] = ((SafeAllocator*)(node + 4))->Allocate(0xbc);
    void* p = ((SafeAllocator*)(node + 4))->Allocate(2);
    if (p != 0) {
        *(short*)p = 0x7de0;
        CleanInvalidateCacheRange(p, 2);
        LoadToMainBGStandardPalette(p, 0x12, 2);
        CleanCacheRange(p, 2);
    }

    char* b = (char*)data_ov004_0217101c[0];
    if (b == 0) {
        return 0;
    }
    *(int*)(b + 0) = 0;
    *(int*)(b + 4) = 0;
    *(int*)(b + 8) = 0;
    _Z24InitStreamHeader0208d82cP20StreamHeader0208d82c((struct StreamHeader0208d82c*)(b + 0xc));
    ((SafeAllocator*)(b + 0x1c))->ResetAllocatorPointer();
    *(int*)(b + 0x44) = -1;
    *(short*)(b + 0x48) = 0;
    *(short*)(b + 0x4a) = 0;
    *(short*)(b + 0x4c) = 0;
    *(short*)(b + 0x4e) = 0;
    struct Flags02166844* fl = (struct Flags02166844*)b;
    fl->loFlags = 0;
    fl->bit6 = 0;
    fl->bit7 = 1;
    memset(b + 0x51, 0, 0x66);
    *(int*)(b + 0xb8) = 0;

    int n = data_ov004_0217059c;
    void* q = ((SafeAllocator*)(node + 4))->Allocate(n);
    ((SafeAllocator*)((char*)data_ov004_0217101c[0] + 0x1c))->CreateTypeA(q, n);
    n = data_ov004_0217059c;
    q = ((SafeAllocator*)(node + 4))->Allocate(n);
    ((SafeAllocator*)((char*)data_ov004_0217101c[0] + 0x30))->CreateTypeA(q, n);

    char* n2 = (char*)_Z40CheckTypeAndReturnNode_02165e70_02165e70Pvi(a1, 7);
    if (n2 != 0) {
        unsigned short* flags = (unsigned short*)(n2 + 0x34);
        flags[0x6d] |= 0x10;
    }
    n2[0x110] = 0;

    memcpy((char*)data_ov004_0217101c[0] + 0x51, c + 0x2cc, 0x66);
    *(int*)((char*)data_ov004_0217101c[0] + 0xb8) = *(int*)((char*)g + 0xa0);
    func_020956b8(g, node + 4);
    func_02095b30(g, 1);

    data_ov004_0217101c[1] = 0;
    data_ov004_0217101c[1] = ((SafeAllocator*)(node + 4))->Allocate(0x20);
    for (unsigned char i = 0; i < 8; i++) {
        ((void**)data_ov004_0217101c[1])[i] = 0;
        ((void**)data_ov004_0217101c[1])[i] = ((SafeAllocator*)(node + 4))->Allocate(0x80);
    }

    char* f = (char*)_Z26GetGlobalField0x1c020421a0v();
    *(unsigned char*)(f + 0x1000 + 0x962) = 1;
    SetFieldsAt0x4And0x8((int*)(f + 0x164 + 0x1800), 9, 1);
    SetFieldsAt0x4And0x8((int*)(f + 0x188 + 0x1800), 0x19, 1);
    return 0;
}
