#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct Block1c02089edc {
    unsigned short v[10];
};

struct Block3002089edc {
    unsigned char v[13];
};

struct Element02089edc {
    signed char b0;
    int w4;
    unsigned char b8;
    short ha;
    int wc;
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    float w14;
    float w18;
    struct Block1c02089edc block1c;
    struct Block3002089edc block30;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
};

struct ElementArray02089edc {
    struct Element02089edc* base;
    short count;
    short capacity;
    short field8;
};

extern "C" void _Z27AppendCappedElement02089edcP20ElementArray02089edcP15Element02089edc(struct ElementArray02089edc* arr, struct Element02089edc* src);

struct Container02108efc {
    struct ElementArray02089edc* pool;
    int unk4;
    int unk8;
    SafeAllocator* alloc;
};
extern struct Container02108efc data_02108efc;

extern int data_020e8c58[5][5][2];
extern int data_020e8c5c[5][5][2];

struct Parameter02089b90 {
    int value;
    void* str;
};

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Parameter02089b90* p);
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Parameter02089b90* p);
int StringLength(const char* s);
extern "C" float _fflt(int v);
extern "C" float _fdiv(float a, float b);

// USA: func_02089b90
extern "C" ARM int func_02089b90(struct Parameter02089b90* p) {
    struct Element02089edc e;
    char* str;
    int i;
    int idx;
    struct Parameter02089b90* base;
    e.b0 = -1;
    e.w4 = 0;
    e.b8 = 0;
    e.ha = 0;
    e.wc = 0;
    e.b10 = 0;
    e.b11 = 0;
    e.b12 = 0;
    e.w14 = 1.0f;
    e.w18 = 1.0f;
    memset(&e.block1c, -1, sizeof(e.block1c));
    memset(&e.block30, -1, sizeof(e.block30));
    e.b3d = 0;
    e.b3e = 0;
    e.b3f = 0;
    if (data_02108efc.pool->field8 == 1) {
        e.b0 = (signed char)_ZNK6Script9Parameter5ToIntEv(&p[0]);
        str = (char*)_ZNK6Script9Parameter8ToStringEv(&p[1]);
        if (str != 0) {
            int len = StringLength(str);
            e.w4 = (int)data_02108efc.alloc->Allocate(len + 1);
            memset((void*)e.w4, 0, len + 1);
            memcpy((void*)e.w4, str, len);
        }
        e.b8 = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&p[2]);
        e.ha = (short)_ZNK6Script9Parameter5ToIntEv(&p[3]);
        e.wc = _ZNK6Script9Parameter5ToIntEv(&p[4]);
        e.b10 = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&p[5]);
        e.b11 = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&p[6]);
        e.b12 = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&p[7]);
        base = p;
        p += 9;
        idx = _ZNK6Script9Parameter5ToIntEv(&base[8]);
        if (idx >= 0 && idx <= 5) {
            e.w14 = _fdiv(_fflt(data_020e8c58[e.b8][idx][0]), 4096.0f);
            e.w18 = _fdiv(_fflt(data_020e8c5c[e.b8][idx][0]), 4096.0f);
        }
        for (i = 0; i < 10; i++) {
            e.block1c.v[i] = (short)_ZNK6Script9Parameter5ToIntEv(p);
            p++;
        }
        for (i = 0; i < 13; i++) {
            e.block30.v[i] = (unsigned char)_ZNK6Script9Parameter5ToIntEv(p);
            p++;
        }
        e.b3d = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&p[0]);
        e.b3e = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&p[1]);
        e.b3f = (unsigned char)_ZNK6Script9Parameter5ToIntEv(&p[2]);
    }
    _Z27AppendCappedElement02089edcP20ElementArray02089edcP15Element02089edc(data_02108efc.pool, &e);
    return 1;
}