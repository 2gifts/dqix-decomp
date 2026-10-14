#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; int u; };

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct Struct_02027d94;
void ClearStructHeader(struct Struct_02027d94* obj);

struct Elem02028170 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short h4;
    unsigned short h6;
    unsigned short h8;
    int w12;
};
struct Container02028170;
void AppendCappedElement02028170(struct Container02028170* c, struct Elem02028170* src);

struct InputStruct02027ce4 {
    struct Variant02030b0c a;
    struct Variant02030b0c b;
    struct TaggedValue02030b44 x;
    struct TaggedValue02030b44 y;
    struct TaggedValue02030b44 z;
};

extern struct Container02028170* data_020fdd30;

// USA: func_02027ce4
ARM int AppendFixedVec3Element02027ce4(struct InputStruct02027ce4* arg) {
    struct Elem02028170 local;
    ClearStructHeader((struct Struct_02027d94*)&local);
    local.b0 = (unsigned char)((Script::Parameter*)&arg->a)->ToInt();
    local.b1 = (unsigned char)((Script::Parameter*)&arg->b)->ToInt();
    local.h4 = (short)((int)(4096.0f * ((Script::Parameter*)&arg->x)->ToFloat()) >> 12);
    local.h6 = (short)((int)(4096.0f * ((Script::Parameter*)&arg->y)->ToFloat()) >> 12);
    local.h8 = (short)((int)(4096.0f * ((Script::Parameter*)&arg->z)->ToFloat()) >> 12);
    AppendCappedElement02028170(data_020fdd30, &local);
    return 1;
}
