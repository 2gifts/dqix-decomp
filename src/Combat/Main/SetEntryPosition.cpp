#include <globaldefs.h>

struct Container0205a3d0;
struct Elem0205a3d0;
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);

// USA: func_020e27ec
ARM void SetEntryPosition_020e27ec(struct Container0205a3d0* c, int key, short a, short b) {
    struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(c, key);
    if (e != NULL) {
        *(short*)((char*)e + 0x4) = a;
        *(short*)((char*)e + 0x6) = b;
    }
}
