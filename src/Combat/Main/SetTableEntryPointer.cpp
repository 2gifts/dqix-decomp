#include <globaldefs.h>

struct TableEntry020bbf6c { void* ptr; unsigned char pad[0x20]; };
extern struct TableEntry020bbf6c data_0210f840[];

// USA: func_020bbf6c
ARM void SetTableEntryPointer_020bbf6c(int index, void* value) {
    data_0210f840[index].ptr = value;
}
