#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

int IsIdInRange020981e4(int a, int id);
int IsInRange1To63(int a, int x);


struct Struct02030b7c { int field0; void* field4; };
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

extern "C" void* func_02012fe4(void);

extern int data_02108ce0;

struct RegNode02064d48 {
    short id;
    unsigned char field2;
    unsigned char field3;
    char name[12];
    struct RegNode02064d48* next;
};

// USA: func_02064d48
ARM int RegisterNode02064d48(char* obj) {
    int b = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
    char* g = (char*)func_02012fe4();

    if (IsIdInRange020981e4((int)(g + 0x840), *(unsigned short*)g)) {
        if (IsInRange1To63((int)(g + 0x840), b)) {
            return 1;
        }
    }

    if (FindNodeByByteId(*(void**)((char*)&data_02108ce0 + 4), b) == NULL) {
        return 1;
    }

    RegNode02064d48* node = (RegNode02064d48*)(*(SafeAllocator**)((char*)&data_02108ce0 + 0))->Allocate(0x14);
    if (node == NULL) {
        return 0;
    }

    node->id = (short)b;
    node->field2 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(obj + 8));

    _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(obj + 0x10));
    char* name = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(obj + 0x18));
    if (name != NULL) {
        strcpy(node->name, name);
    }

    node->field3 = (unsigned char)_ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(obj + 0x20));

    RegNode02064d48** headSlot = *(RegNode02064d48***)((char*)&data_02108ce0 + 8);
    node->next = *headSlot;
    *headSlot = node;
    return 1;
}
