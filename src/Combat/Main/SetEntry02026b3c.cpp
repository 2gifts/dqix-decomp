#include <globaldefs.h>

#if defined(jpn)
#define SetEntry02026b3c func_020264a0
#endif
#include "std_library_functions.h"

struct Entry02026b3c {
    short id;
    char name[0x18];
};

struct Obj02026b3c {
    #if defined(jpn)
    char pad[0x6ce];
#else
    char pad[0x77a];
#endif
    unsigned char count;
    char pad2[1];
    Entry02026b3c* entries;
};

#if defined(jpn)
extern "C" ARM void func_020264a0(Obj02026b3c* obj, unsigned int index, short id, const char* name);
#endif

// USA: func_02026b3c
ARM void SetEntry02026b3c(Obj02026b3c* obj, unsigned int index, short id, const char* name) {
    if (index >= obj->count) return;
    if (obj->entries == NULL) return;
    obj->entries[index].id = id;
    strcpy(obj->entries[index].name, name);
}
