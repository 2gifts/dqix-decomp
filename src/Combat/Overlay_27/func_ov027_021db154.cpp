#include <globaldefs.h>

extern "C" unsigned short func_ov027_021dab38(unsigned short* data, int len);
extern "C" void func_020ca390(int val, void* dst, unsigned int size);
extern "C" void func_020ca3b8(int src, void* dst, int size);
extern "C" void func_ov027_021db124(void);
int IssueBattleCommandSlot24_020d69cc(int a0, int a1, int a2, int a3, unsigned short a4, unsigned char a5);

struct Record021db154 { unsigned char data[0x16]; };

struct BigObj021db154 {
    unsigned char pad0[0x358];
    unsigned char f358;
    unsigned char pad1[0x35a - 0x359];
    unsigned short f35a;
    unsigned short f35c;
    Record021db154 arr35e[15];
    unsigned char f4a8[8];
    unsigned short f4b0;
    unsigned char pad2[0x4b3 - 0x4b2];
    unsigned char f4b3;
    unsigned char f4b4;
    unsigned char f4b5;
    unsigned char pad3[0x4b8 - 0x4b6];
    unsigned int f4b8;
};

struct DispatchCtx021db154 {
    unsigned char pad0[0x10];
    unsigned int f10;
    void (*f14)(unsigned int);
    unsigned char pad1[0x1c - 0x18];
    BigObj021db154* f1c;
    unsigned char pad2[0x24 - 0x20];
    unsigned char f24;
    unsigned char pad3[0x26 - 0x25];
    unsigned char f26;
    unsigned char pad4[0x29 - 0x27];
    unsigned char f29;
    unsigned char pad5[0x40 - 0x2a];
    unsigned int f40;
    unsigned char f44;
    unsigned char f45;
    unsigned char f46;
    unsigned char f47;
    unsigned short f48;
    unsigned char f4a;
    unsigned char pad6[0x4c - 0x4b];
    unsigned short f4c;
    unsigned short f4e;
};

extern DispatchCtx021db154 data_ov027_021dd940;
extern int data_ov027_021dd980;
extern unsigned short data_ov027_021dd988;
extern unsigned char data_ov027_021dd990[0x58];
extern unsigned char data_ov027_021dd9e8[8];

// USA: func_ov027_021db154  (semantic: PublishBattleSnapshot_021db154)
#pragma optimize_for_size off
extern "C" ARM void func_ov027_021db154(int a0, unsigned short a1, unsigned char a2) {
    if (data_ov027_021dd940.f26 != data_ov027_021dd940.f1c->f4b4) {
        func_ov027_021db124();
    }

    data_ov027_021dd940.f44 = (data_ov027_021dd940.f44 & ~3) | 2;
    BigObj021db154* obj = data_ov027_021dd940.f1c;
    data_ov027_021dd940.f45 = obj->f4b3;
    data_ov027_021dd940.f46 = data_ov027_021dd940.f26;
    data_ov027_021dd940.f40 = obj->f4b8;
    data_ov027_021dd940.f44 = (data_ov027_021dd940.f44 & ~0xfc) | (((unsigned int)obj->f4b5 << 26) >> 24);
    unsigned char oldF29 = data_ov027_021dd940.f29;
    data_ov027_021dd940.f29 = oldF29 + 1;
    data_ov027_021dd940.f47 = oldF29;
    data_ov027_021dd940.f4a = obj->f358;
    data_ov027_021dd940.f4c = obj->f35a;
    data_ov027_021dd940.f4e = obj->f35c;

    if (data_ov027_021dd940.f10 == 0 && data_ov027_021dd940.f14 != 0) {
        data_ov027_021dd940.f14(obj->f4b8);
    }

    int i;
    for (i = 0; i < 8; i++) {
        data_ov027_021dd9e8[i] = data_ov027_021dd940.f1c->f4a8[i];
    }

    func_020ca390(0, data_ov027_021dd990, 0x58);

    obj = data_ov027_021dd940.f1c;
    unsigned int sl = 0;
    unsigned short diff = obj->f4b0 ^ obj->f35a;
    for (i = 0; i < 15; i++) {
        if (diff & (2 << i)) {
            func_020ca3b8((int)((char*)data_ov027_021dd940.f1c + 0x35e + i * 0x16), data_ov027_021dd990 + sl * 0x16, 0x16);
            data_ov027_021dd940.f1c->f4b0 |= (2u << i);
            sl++;
            if (sl == 4) break;
        }
    }
    if (sl < 4) {
        data_ov027_021dd990[sl * 0x16] &= ~0xf0;
    }

    data_ov027_021dd940.f48 = 0;
    data_ov027_021dd940.f48 = func_ov027_021dab38(&data_ov027_021dd988, 0x68);

    obj = data_ov027_021dd940.f1c;
    if (obj->f4b0 == obj->f35a) {
        data_ov027_021dd940.f24 = 1;
    }

    IssueBattleCommandSlot24_020d69cc(0, (int)&data_ov027_021dd980, 0x70, a0, a1, (unsigned char)(a2 | 3));

    if (data_ov027_021dd940.f10 != 1) return;
    if (data_ov027_021dd940.f14 == 0) return;
    obj = data_ov027_021dd940.f1c;
    data_ov027_021dd940.f14(obj->f4b8);
}
