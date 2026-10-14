#include <globaldefs.h>

struct Container_1f368 {
    char unk0[0x18];
    void* entries[8];
    unsigned char count;
};

// USA: func_0201f368
ARM void* GetPointerFromArray0x18_0201f368(struct Container_1f368* container, int index) {
    if (index < 0 || container->count <= index) {
        return 0;
    }
    return container->entries[index];
}
