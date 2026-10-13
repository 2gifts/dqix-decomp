#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"

#if defined(jpn)
enum { displayFieldOffset = 0x2c8 };
#else
enum { displayFieldOffset = 0x2d4 };
#endif
int GetField0x64(struct StructF0x64_0203cdf8*);


// USA: func_020409e0
ARM int GetDisplayValue020409e0(Entry_203dce4* obj) {
    if (obj->child14) {
        return GetField0x64((struct StructF0x64_0203cdf8*)(obj->child14));
    }
    if (obj->child18) {
        return *(int*)((char*)obj->child18 + 0xb0);
    }
    if (obj->child1c) {
        return *(int*)((char*)obj->child1c + displayFieldOffset);
    }
    return 0;
}
