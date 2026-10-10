#include <globaldefs.h>

#include "std_library_functions.h"

struct Words02082fa8 { unsigned int a, b, c; };

struct PackedTriple02082cdc {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct SlotRecord02082d6c {
    unsigned char hdr00;
    unsigned char lo01 : 4;
    unsigned char bit01_4 : 1;
    unsigned char hi01 : 3;
    unsigned char name02[13];
    unsigned char val0f[13];
    unsigned int w1c[13];
    unsigned int w50;
    unsigned short h54;
    unsigned char pad56[2];
    struct Words02082fa8 tr58[13];
    unsigned short h_f4;
    unsigned char b_f6[27];
    unsigned char b_111[9];
    unsigned char b_11a[0x24];
    unsigned char flags13e;
    unsigned char lo13f : 3;
    unsigned char hi13f : 5;
    unsigned char b140[0x14];
    struct PackedTriple02082cdc w154;
    unsigned char pad158[8];
    unsigned char b160[0x1c];
    unsigned char b17c[0xc0];
};

struct SlotState02082d6c {
    unsigned char pad000[0x18];
    unsigned int w18;
    unsigned short h1c;
    unsigned short h1e;
    unsigned char pad020[0x1c];
    char name3c[0x3c];
    unsigned int w78_lo : 30;
    unsigned int bit30 : 1;
    unsigned int w78_top : 1;
    unsigned char pad07c[0x0c];
    unsigned char pad088[0xb0];
    unsigned int w138[13];
    unsigned short h16c[13];
    unsigned char b186[13];
    unsigned char pad193[0x2d1];
    unsigned char b464[27];
    unsigned char pad47f[9];
    unsigned char b488[0x1c];
    unsigned char b4a4[0xc0];
    unsigned short h564;
    unsigned char pad566[4];
    unsigned char b56a;
    unsigned char b56b_lo : 4;
    unsigned char b56b_hi : 4;
    unsigned char pad56c[0x850 - 0x56c];
    struct Words02082fa8 tr850[13];
    unsigned char b8ec[0x24];
    unsigned char b910[9];
    unsigned char pad919[0x94c - 0x919];
    unsigned int w94c;
    unsigned int w950;
    unsigned short h954;
};

extern "C" void func_02082828();
extern "C" void _Z33LoadAndApplyResourceEntry02082fc4PvS_(void*, void*);
extern "C" void _Z18Copy3Words02082fa8P13Words02082fa8S0_(struct Words02082fa8*, struct Words02082fa8*);
extern "C" void __clear(void*, unsigned int);
extern "C" void func_02042764(void*, void*, int);
extern char data_020ef078[];

// USA: func_02082d6c
extern "C" ARM void func_02082d6c(struct SlotState02082d6c* dst, struct SlotRecord02082d6c* src) {
    if (src == NULL) {
        return;
    }
    func_02082828();
    dst->b56a = src->lo01;
    dst->w950 = src->w50;
    dst->h954 = src->h54;
    for (int i = 0; i < 13; i++) {
        dst->h16c[i] = src->name02[i];
        dst->b186[i] = src->val0f[i];
        dst->w138[i] = src->w1c[i];
    }
    _Z33LoadAndApplyResourceEntry02082fc4PvS_(dst, NULL);
    for (int i = 0; i < 13; i++) {
        _Z18Copy3Words02082fa8P13Words02082fa8S0_(&dst->tr850[i], &src->tr58[i]);
    }
    dst->h564 = src->h_f4;
    for (int j = 0; j < 27; j++) {
        dst->b464[j] = src->b_f6[j];
    }
    memcpy(dst->b910, src->b_111, 9);
    memcpy(dst->b8ec, src->b_11a, 0x24);
    unsigned char flags = src->flags13e;
    if (flags & 1) {
        dst->w18 |= 1;
    }
    if (flags & 2) {
        dst->w18 |= 2;
    }
    if (flags & 4) {
        dst->w18 |= 4;
    }
    char local[0x30];
    __clear(local, 0x30);
    func_02042764(src->b140, local, 1);
    sprintf(dst->name3c, data_020ef078, local);
    dst->bit30 = src->bit01_4;
    dst->h1c = src->w154.b;
    dst->h1e = src->w154.c;
    memcpy(dst->b488, src->b160, 0x1c);
    dst->b56b_lo = src->hi01;
    dst->b56b_hi = src->lo13f;
    memcpy(dst->b4a4, src->b17c, 0xc0);
    dst->w94c = src->hi13f;
}
