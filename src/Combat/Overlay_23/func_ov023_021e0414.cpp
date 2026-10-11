#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct Container020dedd0;
struct Element020de650_021e0414 {
    char pad0[8];
    unsigned int nibble : 4;
    unsigned int restBits : 28;
};
Element020de650_021e0414* FindElementByKey020dedd0(struct Container020dedd0*, int);

void ClearFields_021e20c0(void*);


extern int data_ov023_021fdc4c;
extern int data_ov023_021fdc61;

struct Obj021e0414 {
    char pad0[0x48];
    Container020dedd0* field48;
    Element020de650_021e0414* field4c;
#if defined(jpn)
    char pad50[0x6b8 - 0x50];
#else
    char pad50[0x73c - 0x50];
#endif

    int field73c;
    char pad740[0x770 - 0x740];
    short field770;
    char pad772[0x79a - 0x772];
    signed char field79a;
};

// JPN: func_ov023_021e09b4
// USA: func_ov023_021e0414  (semantic: RefreshEntryElementAndDispatch_021e0414)
extern "C" ARM int func_ov023_021e0414(struct Obj021e0414* obj) {
    int a = (int)BackgroundLoader::GetInstance();
    if (obj->field48 != NULL) {
        obj->field4c = FindElementByKey020dedd0(obj->field48, obj->field770);
    }
    Element020de650_021e0414* elem = obj->field4c;
    if (elem != NULL) {
        unsigned int nibble = elem->nibble;
        int cond1 = (nibble <= 7);
        signed char flag = (cond1 != 0);
        signed char b = obj->field79a;
        if (b != flag) {
            ClearFields_021e20c0((char*)obj + 0xcc);
            elem = obj->field4c;
            unsigned int nibble2 = elem->nibble;
            int cond2 = (nibble2 <= 7);
            if (cond2) {
                obj->field73c = ((BackgroundLoader*)(a))->QueueLoadFile((const char*)((int)&data_ov023_021fdc4c), (SafeAllocator*)(0));
            } else {
                obj->field73c = ((BackgroundLoader*)(a))->QueueLoadFile((const char*)((int)&data_ov023_021fdc61), (SafeAllocator*)(0));
            }
        }
    }
    return 6;
}
