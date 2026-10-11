#if defined(jpn)
#define func_ov009_02184c30 _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#define func_ov005_02158560 func_ov005_02159b58
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct TaggedInput021869b8 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    TaggedNumber02184c30 d;
    TaggedNumber02184c30 e;
};

extern "C" int func_ov009_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct VTable021869b8 {
    char pad[0xe8];
    int (*fn)(void*);
};
struct ObjE2021869b8 {
    struct VTable021869b8* vtable;
};
extern "C" ARM struct ObjE2021869b8* func_ov023_021f6880(void* list, int v);

extern "C" ARM int func_ov023_021fbd00(void* obj, void* ctx, int a0, int a1, int a2, int a5,
                                       unsigned char a6);

extern "C" void* _Z26ResetAndReturnSelf020dfc2cPv(void* p);
extern "C" void* _Z22ZeroInitReturn020df80cPv(void* p);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);
extern "C" void _Z23EmptyDestructor0205a494Pv(void* obj);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
extern "C" void _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern int data_ov024_021ff17c;

struct Sub021869b8 {
    SafeAllocator a0;
    SafeAllocator a1;
    SafeAllocator a2;
    char pad3c[0x54 - 0x3c];
    char m54[0x6c - 0x54];
    char m6c[0x7c - 0x6c];
    char m7c[0x8c - 0x7c];
    char m8c[0xa4 - 0x8c];
    char ma4[R(0x128 - 0xa4, 0x12c - 0xa4)];
    char m12c[R(0x718 - 0x128, 0x79c - 0x12c)];
};

struct Buf021869b8 {
    void* vtable;
    char pad4[0x20 - 4];
    Sub021869b8 sub;
};

// USA: func_ov011_021869b8
extern "C" ARM int func_ov011_021869b8(struct TaggedInput021869b8* obj, int argc) {
    struct Buf021869b8 local;
    unsigned char flag;
    void* ctx;
    void* node;
    void* block;
    int extra;
    int tag18;
    struct Sub021869b8* sub;
    int tag8;
    int tag10;
    int tag0;
    struct ObjE2021869b8* e2;
    void* list;

    tag0 = func_ov009_02184c30(&obj->a);
    tag8 = func_ov009_02184c30(&obj->b);
    tag10 = func_ov009_02184c30(&obj->c);
    tag18 = func_ov009_02184c30(&obj->d);

    flag = 0;
    if (argc - 4) flag = (unsigned char)func_ov009_02184c30(&obj->e);

    ctx = func_ov017_021b2164();
    node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    block = ((SafeAllocator*)((char*)node + 4))->Allocate(R(0x738, 0x7bc));
    if (block == 0) return 0;

    extra = 0;
    list = func_ov011_021849c8(ctx);
    e2 = func_ov023_021f6880(list, tag18);
    if (e2 != 0) extra = e2->vtable->fn(e2);

    sub = &local.sub;
    local.vtable = &data_ov024_021ff17c;
    sub->a0.ResetAllocatorPointer();
    sub->a1.ResetAllocatorPointer();
    sub->a2.ResetAllocatorPointer();
    _Z26ResetAndReturnSelf020dfc2cPv(sub->m54);
    _Z22ZeroInitReturn020df80cPv(sub->m6c);
    _Z22ZeroInitReturn020df80cPv(sub->m7c);
    _Z26ResetAndReturnSelf020dfc2cPv(sub->m8c);
    _Z26ResetAndReturnSelf020dfc2cPv(sub->ma4);
    _Z18InitStruct0205a444Pc(sub->m12c);
    memcpy(block, &local, sizeof(Buf021869b8));

    if (func_ov023_021fbd00(block, ctx, tag0, tag8, tag10, extra, flag) == 0) {
        _Z23EmptyDestructor0205a494Pv(local.sub.m12c);
        return 0;
    }
    _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    _Z23EmptyDestructor0205a494Pv(local.sub.m12c);
    return 1;
}
