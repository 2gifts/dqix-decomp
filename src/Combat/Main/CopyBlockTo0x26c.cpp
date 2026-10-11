#include <globaldefs.h>

#if defined(jpn)
enum { kOffset26c = 0x260 };
#else
enum { kOffset26c = 0x26c };
#endif


struct Vec3Block020398b4 { int v[3]; };

struct SubBlock020398b4 {
    unsigned char a, b, c, d;   // 0x0-0x3
    unsigned short e;           // 0x4
    short f, g, h;              // 0x6, 0x8, 0xa
    struct Vec3Block020398b4 v0; // 0xc
    struct Vec3Block020398b4 v1; // 0x18
    struct Vec3Block020398b4 v2; // 0x24
    struct Vec3Block020398b4 v3; // 0x30
    struct Vec3Block020398b4 v4; // 0x3c
    int field48;                // 0x48
    int field4c;                // 0x4c
    short field50;              // 0x50
    unsigned char field52;      // 0x52
    unsigned char field53;      // 0x53
    unsigned char field54;      // 0x54
    int field58;                // 0x58
    int field5c;                // 0x5c
    int field60;                // 0x60
};

struct Owner020398b4 {
    unsigned char pad[kOffset26c];
    struct SubBlock020398b4 dst;
};

// USA: func_020398b4
ARM void CopyBlockTo0x26c(struct Owner020398b4* obj, struct SubBlock020398b4* src) {
    obj->dst.a = src->a;
    obj->dst.b = src->b;
    obj->dst.c = src->c;
    obj->dst.d = src->d;
    obj->dst.e = src->e;
    obj->dst.f = src->f;
    obj->dst.g = src->g;
    obj->dst.h = src->h;
    obj->dst.v0 = src->v0;
    obj->dst.v1 = src->v1;
    obj->dst.v2 = src->v2;
    obj->dst.v3 = src->v3;
    obj->dst.v4 = src->v4;
    obj->dst.field48 = src->field48;
    obj->dst.field4c = src->field4c;
    obj->dst.field50 = src->field50;
    obj->dst.field52 = src->field52;
    obj->dst.field53 = src->field53;
    obj->dst.field54 = src->field54;
    obj->dst.field58 = src->field58;
    obj->dst.field5c = src->field5c;
    obj->dst.field60 = src->field60;
}
