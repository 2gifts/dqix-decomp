#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

struct Struct021931b4;
extern "C" void _Z22PushArrayValue021931b4P14Struct021931b4i(struct Struct021931b4* s, int v);
extern "C" void func_ov015_02192700(void* obj, int a1);
extern "C" void func_ov015_0218f0c4(void* p);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);

struct Owner_021931cc;
extern "C" int _Z11Pop021931ccP14Owner_021931cc(struct Owner_021931cc* obj);

extern AllocatorUnion data_02114e20;

struct ListNode02192064 { void* value; struct ListNode02192064* next; };

struct Obj02192064 {
    char pad0[0x2c];
    struct ListNode02192064* list;
    void* field30;
    int field34;
    unsigned char field38;
    char pad39[0x1a4 - 0x39];
    int field1a4;
    char pad1a8[0x2b0 - 0x1a4 - 4];
    short field2b0;
};

// USA: func_ov015_02192064
extern "C" ARM void func_ov015_02192064(struct Obj02192064* obj, int mode) {
    int key = obj->field34;
    if (key == 0) {
        return;
    }
    switch (mode) {
    case 0: {
        _Z22PushArrayValue021931b4P14Struct021931b4i((struct Struct021931b4*)obj, obj->field1a4);
        obj->field1a4 = 0x27;
        func_ov015_02192700(obj, 0);
        return;
    }
    case 1: {
        struct ListNode02192064* node = obj->list;
        struct ListNode02192064* prev = 0;
        while (node != 0) {
            if ((int)node->value == key) {
                break;
            }
            prev = node;
            node = node->next;
        }

        if (node != 0) {
            struct ListNode02192064* next = node->next;
            func_ov015_0218f0c4(node->value);
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node->value);
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, node);
            if (prev != 0) {
                prev->next = next;
            } else {
                obj->list = next;
            }
            if (obj->field34 == (int)obj->field30) {
                obj->field38 = *((unsigned char*)obj->field30 + 0x1c);
                obj->field30 = 0;
            }
            obj->field34 = 0;
        }

        obj->field2b0 = 0;
        obj->field1a4 = _Z11Pop021931ccP14Owner_021931cc((struct Owner_021931cc*)obj);
        func_ov015_02192700(obj, 0);
        break;
    }
    }
}
