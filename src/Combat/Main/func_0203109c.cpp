#include <globaldefs.h>

struct Vec0203109c {
    int x;
    int y;
    int z;
};

struct Box0203109c {
    Vec0203109c lo;
    Vec0203109c hi;
};

// USA: func_0203109c
extern "C" ARM bool func_0203109c(Box0203109c* a, Box0203109c* b) {
    if (a->lo.x < b->hi.x) {
        return false;
    }
    if (a->lo.y < b->hi.y) {
        return false;
    }
    if (a->lo.z < b->hi.z) {
        return false;
    }
    if (b->lo.x < a->hi.x) {
        return false;
    }
    if (b->lo.y < a->hi.y) {
        return false;
    }
    return b->lo.z >= a->hi.z;
}