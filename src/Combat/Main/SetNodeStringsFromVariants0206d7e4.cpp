#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Variant02030b0c;
extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

struct Struct02030b7c;
extern "C" extern void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

struct Node0206d7e4;

struct Data02108cec_d7e4 {
    unsigned char pad0[0xa];
    unsigned short field0xa;
    unsigned char pad1[0x10 - 0xc];
    void* field0x10;
    void* field0x14;
};
extern struct Data02108cec_d7e4 data_02108cec;

struct Node0206d7e4 {
    unsigned char pad0[0x44];
    unsigned short id0x44;
    unsigned char pad1[0x54 - 0x46];
    void* str0x54;
    void* str0x58;
    unsigned char pad2[0x70 - 0x5c];
    struct Node0206d7e4* next;
};

// USA: func_0206d7e4
ARM int SetNodeStringsFromVariants0206d7e4(void* param0) {
    struct Node0206d7e4* node;
    int key = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)param0);
    node = (Node0206d7e4*)FindNodeByByteId(data_02108cec.field0x10, key);
    if (node == 0) {
        return 0;
    }
    while (node != 0) {
        if (node->id0x44 == data_02108cec.field0xa) {
            break;
        }
        node = node->next;
    }
    if (node == 0) {
        return 0;
    }

    char* str;
    unsigned short len;

    str = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)((char*)param0 + 8));
    len = (unsigned short)strlen(str);
    node->str0x54 = ((SafeAllocator*)data_02108cec.field0x14)->Allocate(len + 1);
    if (node->str0x54 != 0) {
        memset(node->str0x54, 0, len + 1);
        memcpy(node->str0x54, str, len);
    }

    str = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)((char*)param0 + 0x10));
    len = (unsigned short)strlen(str);
    node->str0x58 = ((SafeAllocator*)data_02108cec.field0x14)->Allocate(len + 1);
    if (node->str0x58 != 0) {
        memset(node->str0x58, 0, len + 1);
        memcpy(node->str0x58, str, len);
    }

    return 1;
}
