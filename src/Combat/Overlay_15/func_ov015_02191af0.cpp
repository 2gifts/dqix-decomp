#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

extern "C" void func_ov015_0218f0c4(void* p);
extern "C" void func_ov015_02192700(void* obj, int flag);
extern "C" extern void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

struct ListNode02191af0 { void* payload; ListNode02191af0* next; };

struct Obj02191af0 {
    char pad0[0x2c];
    ListNode02191af0* list;
    char pad1[0x23c];
    short counter;
    char pad2[0xb0];
    unsigned short total;
};

// USA: func_ov015_02191af0
extern "C" ARM void func_ov015_02191af0(Obj02191af0* obj, int count) {
    ListNode02191af0* cur = obj->list;
    if (cur == 0) {
        return;
    }
    int i = 0;
    ListNode02191af0* prev = 0;
    ListNode02191af0* nxt = cur->next;
    while (i < count) {
        prev = cur;
        cur = nxt;
        nxt = nxt->next;
        i++;
    }
    func_ov015_0218f0c4(cur->payload);
    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, cur->payload);
    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, cur);
    if (prev != 0) {
        prev->next = nxt;
    } else {
        obj->list = nxt;
    }
    if ((obj->total - 1) <= obj->counter) {
        obj->counter = obj->total - 2;
        if (obj->counter < 0) {
            obj->counter = 0;
        }
    }
    func_ov015_02192700(obj, 0);
}
