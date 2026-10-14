#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct Obj020a14fc;
void InitCappedArray020a14fc(struct Obj020a14fc* obj, void* flag, int count);

struct Vec4Variant020a10cc {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct Variant02030b0c v2;
    struct Variant02030b0c v3;
};

struct Global02109d94_10cc {
    unsigned char flags;
    char pad1;
    unsigned short overrideVal;
    struct Obj020a14fc* obj;
    void* flag;
    int cond;
};
extern struct Global02109d94_10cc data_02109d94;

// USA: func_020a10cc
ARM int InitCappedArrayFromVariants020a10cc(struct Vec4Variant020a10cc* arg0) {
    unsigned short sum = 0;
    unsigned short a = (unsigned short)((Script::Parameter*)&arg0->v0)->ToInt();
    unsigned short b = (unsigned short)((Script::Parameter*)&arg0->v1)->ToInt();
    unsigned short c = (unsigned short)((Script::Parameter*)&arg0->v2)->ToInt();
    unsigned short d = (unsigned short)((Script::Parameter*)&arg0->v3)->ToInt();

    if (data_02109d94.flags & 1) sum += a;
    if (data_02109d94.flags & 2) sum += b;
    if (data_02109d94.flags & 4) sum += c;
    if (data_02109d94.flags & 8) sum += d;

    if (data_02109d94.cond != 0 && data_02109d94.overrideVal != 0) {
        sum = data_02109d94.overrideVal;
    }

    InitCappedArray020a14fc(data_02109d94.obj, data_02109d94.flag, sum);
    return 1;
}
