#include <globaldefs.h>
#include "World/GrottoTileGraph.h"

struct Container02028170 {
    unsigned char capacity;
    char pad;
    unsigned char count;
    char pad2;
    struct Elem02028170* base;
};

// USA: func_02028170
ARM void AppendCappedElement02028170(struct Container02028170* c, struct Elem02028170* src) {
    unsigned char count = c->count;
    struct Elem02028170* dst;
    if (c->capacity <= count) return;
    dst = &c->base[count];
    dst->id = src->id;
    dst->field_1 = src->field_1;
    dst->field_2 = src->field_2;
    dst->flags = src->flags;
    dst->x = src->x;
    dst->field_6 = src->field_6;
    dst->z = src->z;
    dst->field_c = src->field_c;
    c->count++;
}
