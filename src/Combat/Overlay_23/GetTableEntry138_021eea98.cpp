#include <globaldefs.h>

struct Table021eea98 {
    #if defined(jpn)
    char pad[0x8b8];
#else
    char pad[0x950];
#endif
    int index;
};

struct Obj021eea98 {
    #if defined(jpn)
    char pad[0x144];
#else
    char pad[0x150];
#endif
    struct Table021eea98* table;
};

// USA: func_ov023_021eea98
ARM int GetTableEntry138_021eea98(struct Obj021eea98* o) {
    struct Table021eea98* t = o->table;
    return *(int*)((char*)t + (t->index * 4) + 0x138);
}
