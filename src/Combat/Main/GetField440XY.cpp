#include <globaldefs.h>

struct Field440XY {
    short x;
    short y;
};

struct Field440XYObj {
    char pad0[0x440];
    struct Field440XY* field440;
};

// USA: func_02066cc0
ARM void GetField440XY_02066cc0(struct Field440XYObj* obj, short* outX, short* outY) {
    if (obj->field440 != NULL) {
        *outX = obj->field440->x;
        *outY = obj->field440->y;
    }
}
