#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

extern AllocatorUnion data_02114e20;
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern void TailForward02012da4(AllocatorUnion* alloc, void* data);

struct ResetStruct0218eef0;
void InitCombatFieldStruct0218eef0(struct ResetStruct0218eef0* s);

struct Obj0218ef7c;
struct SrcState0218ef7c;
struct P0218ef7c;
extern "C" int func_ov015_0218ef7c(struct Obj0218ef7c* obj, struct SrcState0218ef7c* src, struct P0218ef7c* p);

extern "C" int func_ov015_0218f27c(void* p, void* q);
extern "C" void func_ov015_0218f0c4(void* p);

struct ListNode021919e4 { void* payload; struct ListNode021919e4* next; };

struct Obj021919e4 {
    char pad0[0x2c];
    struct ListNode021919e4* list;
};

// USA: func_ov015_021919e4
extern "C" ARM void* func_ov015_021919e4(struct Obj021919e4* obj, void* p1) {
    struct ListNode021919e4* node = (struct ListNode021919e4*)AllocateAligned4_02012d88(&data_02114e20, 8);
    if (node == 0) {
        return 0;
    }
    node->payload = 0;
    node->next = 0;
    node->payload = AllocateAligned4_02012d88(&data_02114e20, 0x5c);
    if (node->payload == 0) {
        TailForward02012da4(&data_02114e20, node);
        return 0;
    }
    void* payload = node->payload;

    InitCombatFieldStruct0218eef0((struct ResetStruct0218eef0*)payload);
    int status = func_ov015_0218ef7c((struct Obj0218ef7c*)payload, (struct SrcState0218ef7c*)obj, (struct P0218ef7c*)p1);
    if (status == 0) {
        TailForward02012da4(&data_02114e20, node->payload);
        node->payload = 0;
        TailForward02012da4(&data_02114e20, node);
        return 0;
    }

    if (!func_ov015_0218f27c(payload, p1)) {
        func_ov015_0218f0c4(node->payload);
        TailForward02012da4(&data_02114e20, node->payload);
        node->payload = 0;
        TailForward02012da4(&data_02114e20, node);
        return 0;
    }

    struct ListNode021919e4** pp = &obj->list;
    while (*pp != 0) {
        pp = &(*pp)->next;
    }
    *pp = node;
    return node->payload;
}
