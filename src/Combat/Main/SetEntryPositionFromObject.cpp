#include <globaldefs.h>

struct Container0205a3d0;
void SetEntryPosition_020e27ec(struct Container0205a3d0* c, int key, short a, short b);

struct WinObj020e28f0 {
    char pad0[0x1c];
    unsigned short key;
    char pad1[2];
    struct Container0205a3d0* container;
};

// USA: func_020e28f0
ARM void SetEntryPositionFromObject(struct WinObj020e28f0* obj, short a, short b) {
    SetEntryPosition_020e27ec(obj->container, obj->key, a, b);
}
