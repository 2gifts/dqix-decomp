#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "std_library_functions.h"

struct NameBuf02046574 { char c[0x40]; };

struct Obj02046574 {
    char pad[IS_JPN ? 0x37c : 0x4ac];
    struct NameBuf02046574 names[16];
};

// USA: func_02046574
ARM void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str) {
    if (str == NULL) return;
    if (index < 0) return;
    if (index >= 0x10) return;
    strncpy(obj->names[index].c, str, 0x3f);
    obj->names[index].c[0x3f] = 0;
}
