#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct TaggedValue02030b44;
extern "C" float _ZNK6Script9Parameter7ToFloatEv(struct TaggedValue02030b44* v);

void InsertShortIntoTable021098f4(unsigned short);

struct ListEeec;
struct NodeEeec;
void PushNodeToList(struct ListEeec* list, struct NodeEeec* node);

struct CallbackCache02108d04 {
    short field0;
    short pad2;
    void* field4;
    void* field8;
    void* fieldC;
};
extern struct CallbackCache02108d04 data_02108d04;

struct Entry0206ed44 {
    short key;
    unsigned char f2;
    unsigned char f3;
    int f4;
    short f8;
    short fa;
    short fc;
};

// USA: func_0206ed44  (semantic: InsertEntryIfNewKey0206ed44)
extern "C" ARM int func_0206ed44(void* param0) {
    struct Entry0206ed44* node;
    int i;
    short* arr;
    int key;
    key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    arr = (short*)data_02108d04.field8;
    if (arr != 0) {
        for (i = 0; i < data_02108d04.field0; i++) {
            if (arr[i] == key) break;
        }
        if (i == data_02108d04.field0) {
            return 1;
        }
    }
    node = (struct Entry0206ed44*)((SafeAllocator*)data_02108d04.field4)->Allocate(0x14);
    if (node == 0) {
        InsertShortIntoTable021098f4(2);
        return 0;
    }
    node->key = (short)key;
    node->f2 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 8));
    node->f3 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x10));
    node->f4 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x18));
    node->f8 = (short)(int)(4096.0f * _ZNK6Script9Parameter7ToFloatEv((struct TaggedValue02030b44*)((char*)param0 + 0x20)));
    node->fa = (short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x28));
    node->fc = (short)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)param0 + 0x30));
    if (((unsigned int)node->f4 << 26 >> 29) == 0) {
        node->f4 &= ~7;
    }
    PushNodeToList((struct ListEeec*)data_02108d04.fieldC, (struct NodeEeec*)node);
    return 1;
}
