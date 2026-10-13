#include <globaldefs.h>

#if defined(jpn)
enum { MainIndex = 1, ListIndex = 0, FlagOffset = 0x790, WindowPrefix = 0x1400, FirstWindow = 0x394, SecondWindow = 0x3b8 };
#else
enum { MainIndex = 0, ListIndex = 1, FlagOffset = 0x962, WindowPrefix = 0x1800, FirstWindow = 0x164, SecondWindow = 0x188 };
#endif

#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include "std_library_functions.h"

struct StreamHeader0208d82c {
    unsigned int w0;
    unsigned short h4, h6;
    unsigned int w8;
    unsigned short hc, he;
};
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

struct State02166844 {
    int field0, field4, field8;
    StreamHeader0208d82c stream;
    SafeAllocator allocators[2];
    int taskId;
    short field48, field4a, field4c, field4e;
    unsigned char loFlags : 6;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
    unsigned char savedBytes[0x66];
    int savedWord;
};

// USA: func_ov004_02166844
extern "C" ARM int func_ov004_02166844(void* a1) {
    char* node;
    data_ov004_0217101c[MainIndex] = 0;
    int* g = GetGlobal02109418();
    char* c = (char*)func_0205ec34();
    node = (char*)func_ov011_021845f8(a1, 0);
    if (node == 0) {
        return 0;
    }

    data_ov004_0217101c[MainIndex] = ((SafeAllocator*)(node + 4))->Allocate(sizeof(State02166844));
    void* p = ((SafeAllocator*)(node + 4))->Allocate(2);
    if (p != 0) {
        *(short*)p = 0x7de0;
        CleanInvalidateCacheRange(p, 2);
        LoadToMainBGStandardPalette(p, 0x12, 2);
        CleanCacheRange(p, 2);
    }

    State02166844* state = (State02166844*)data_ov004_0217101c[MainIndex];
    if (state == 0) {
        return 0;
    }
    state->field0 = 0;
    state->field4 = 0;
    state->field8 = 0;
    _Z24InitStreamHeader0208d82cP20StreamHeader0208d82c(&state->stream);
    state->allocators[0].ResetAllocatorPointer();
    state->taskId = -1;
    state->field48 = 0;
    state->field4a = 0;
    state->field4c = 0;
    state->field4e = 0;
    state->loFlags = 0;
    state->bit6 = 0;
    state->bit7 = 1;
    memset(state->savedBytes, 0, sizeof(state->savedBytes));
    state->savedWord = 0;

    int n = data_ov004_0217059c;
    void* q = ((SafeAllocator*)(node + 4))->Allocate(n);
    ((State02166844*)data_ov004_0217101c[MainIndex])->allocators[0].CreateTypeA(q, n);
    n = data_ov004_0217059c;
    q = ((SafeAllocator*)(node + 4))->Allocate(n);
    ((State02166844*)data_ov004_0217101c[MainIndex])->allocators[1].CreateTypeA(q, n);

    char* n2 = (char*)_Z40CheckTypeAndReturnNode_02165e70_02165e70Pvi(a1, 7);
    if (n2 != 0) {
        unsigned short* flags = (unsigned short*)(n2 + 0x34);
        flags[0x6d] |= 0x10;
    }
    n2[0x110] = 0;

    memcpy(((State02166844*)data_ov004_0217101c[MainIndex])->savedBytes, c + 0x2cc, 0x66);
    ((State02166844*)data_ov004_0217101c[MainIndex])->savedWord = *(int*)((char*)g + 0xa0);
    func_020956b8(g, node + 4);
    func_02095b30(g, 1);

    data_ov004_0217101c[ListIndex] = 0;
    data_ov004_0217101c[ListIndex] = ((SafeAllocator*)(node + 4))->Allocate(0x20);
    for (unsigned char i = 0; i < 8; i++) {
        ((void**)data_ov004_0217101c[ListIndex])[i] = 0;
        ((void**)data_ov004_0217101c[ListIndex])[i] = ((SafeAllocator*)(node + 4))->Allocate(0x80);
    }

    char* f = (char*)_Z26GetGlobalField0x1c020421a0v();
    *(unsigned char*)(f + 0x1000 + FlagOffset) = 1;
    SetFieldsAt0x4And0x8((int*)(f + FirstWindow + WindowPrefix), 9, 1);
    SetFieldsAt0x4And0x8((int*)(f + SecondWindow + WindowPrefix), 0x19, 1);
    return 0;
}
