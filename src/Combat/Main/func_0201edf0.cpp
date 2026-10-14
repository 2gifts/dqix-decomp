#include <globaldefs.h>
#include "Resource/Script.h"

struct Arg0201edf0 { int type; union { int i; float f; } value; };

struct Inner3_0201f214 { unsigned int v[3]; };

struct Element0201f214 {
    short s0;
    short s2;
    short s4;
    unsigned short h6;
    struct Inner3_0201f214 mid8;
    unsigned short h14;
    unsigned short h16;
    unsigned short h18;
    unsigned short h1a;
    unsigned short h1c;
    unsigned short h1e;
};

struct List0201f214;

void AppendCappedElement0201f214(struct List0201f214*, struct Element0201f214*);

struct Alloc0201edf0;
struct Container0201edf0 {
    int f0;
    struct Alloc0201edf0* alloc;
    struct List0201f214* list;
    char pad[16];
};
extern struct Container0201edf0 data_020fdc40;

// USA: func_0201edf0
extern "C" ARM int func_0201edf0(struct Arg0201edf0* p, int n) {
    struct Element0201f214 e;
    float v2;
    float v3;
    float v4;
    float v7;
    float v8;
    float v10;
    float v9;
    float v11;
    float v12;
    unsigned char h6;
    int a0;
    int a1;
    int a4;

    a0 = ((Script::Parameter*)&p[0])->ToInt();
    a1 = ((Script::Parameter*)&p[1])->ToInt();
    v2 = ((Script::Parameter*)&p[2])->ToFloat();
    v3 = ((Script::Parameter*)&p[3])->ToFloat();
    v4 = ((Script::Parameter*)&p[4])->ToFloat();
    a4 = ((Script::Parameter*)&p[5])->ToInt();
    struct Arg0201edf0* a6 = &p[6];
    p += 7;
    (void)(void*)((Script::Parameter*)a6)->ToString();
    v7 = 1.0f;
    v8 = 1.0f;
    v9 = 1.0f;
    if (n > 10) {
        v7 = ((Script::Parameter*)&p[0])->ToFloat();
        v8 = ((Script::Parameter*)&p[1])->ToFloat();
        struct Arg0201edf0* z = &p[2];
        p += 3;
        v9 = ((Script::Parameter*)z)->ToFloat();
    }
    v10 = 0.0f;
    v11 = 0.0f;
    v12 = 0.0f;
    if (n > 7) {
        v10 = ((Script::Parameter*)&p[0])->ToFloat();
        v11 = ((Script::Parameter*)&p[1])->ToFloat();
        struct Arg0201edf0* z = &p[2];
        p += 3;
        v12 = ((Script::Parameter*)z)->ToFloat();
    }
    h6 = 0xf;
    if (n > 13) {
        h6 = ((Script::Parameter*)&p[0])->ToInt() & 0xff;
        if (h6 & 0x10) {
            h6 &= ~0x10;
        } else {
            h6 |= 0x10;
        }
        if (h6 & 0x20)
            h6 = h6 & ~0x20;
        else
            h6 = h6 | 0x20;
    }
    e.s0 = a0;
    e.s2 = a1;
    e.s4 = a4;
    e.mid8.v[0] = (int)(4096.0f * v2);
    e.mid8.v[1] = (int)(4096.0f * v3);
    e.mid8.v[2] = (int)(4096.0f * v4);
    e.h14 = (int)(4096.0f * v10);
    e.h16 = (int)(4096.0f * v11);
    e.h18 = (int)(4096.0f * v12);
    e.h1a = (int)(4096.0f * v7);
    e.h1c = (int)(4096.0f * v8);
    e.h1e = (int)(4096.0f * v9);
    e.h6 = h6;
    AppendCappedElement0201f214(data_020fdc40.list, &e);
    return 1;
}
