#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"


struct ThreeWords0x50_02040a20 { unsigned int v[3]; };

// USA: func_02040a20
ARM int GetOffset0x54FromFallbackChain(Entry_203dce4* obj) {
    void* p;

    p = obj->child14;
    if (p != NULL) {
        return GetField0x60((struct StructF0x60_0203cdd0*)p);
    }

    p = obj->child18;
    if (p != NULL) {
        struct ThreeWords0x50_02040a20 t1;
        t1 = *(struct ThreeWords0x50_02040a20*)((char*)p + 0x50);
        return (int)t1.v[1];
    }

    p = obj->child1c;
    if (p != NULL) {
        struct ThreeWords0x50_02040a20 t2;
        t2 = *(struct ThreeWords0x50_02040a20*)((char*)p + 0x50);
        return (int)t2.v[1];
    }

    return 0;
}
