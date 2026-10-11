#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_021864f0 func_ov013_02187820
#define func_ov013_02186590 func_ov013_021878c0
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#define func_ov013_02186bd4 func_ov013_02187f00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

#pragma opt_arithtransformation off

int GetFieldAt0x150(unsigned char* obj);
int GetTableByte020dd11c(unsigned int a, unsigned int b);

// USA: func_ov013_02184b4c
extern "C" ARM void func_ov013_02184b4c(void* obj, void* arg) {
    unsigned char* o = (unsigned char*)obj;
    unsigned char* p = (unsigned char*)arg;
    unsigned char* ctx;
    unsigned short baseVal;
    int field950;
    int i;

    if (arg == 0) return;

    ctx = (unsigned char*)GetFieldAt0x150(p);
    *(void**)(o + R(0x62c,0x6a4)) = *(void**)(p + 0x134);

    baseVal = *(unsigned short*)(ctx + 0x564);
    *(int*)(o + R(0x5f4,0x66c)) = baseVal;
    *(int*)(o + R(0x5f0,0x668)) = baseVal;

    field950 = *(int*)(ctx + R(0x8b8,0x950));
    {
        unsigned int idx = field950 & 0xff;
        o[R(0x630,0x6a8)] = (unsigned char)field950;
        *(int*)(o + R(0x638,0x6b0)) = *(unsigned short*)(ctx + 0x16c + idx * 2);
    }
    {
        unsigned char* q = ctx + o[R(0x630,0x6a8)];
        *(int*)(o + R(0x640,0x6b8)) = q[0x186];
    }

    *(unsigned short*)(o + R(0x648,0x6c0)) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x30);
    *(unsigned short*)(o + R(0x64c,0x6c4)) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x32);
    *(unsigned short*)(o + R(0x64e,0x6c6)) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x34);
    *(unsigned short*)(o + R(0x650,0x6c8)) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x36);
    *(unsigned short*)(o + R(0x652,0x6ca)) = *(unsigned short*)(*(unsigned char**)(p + 0x134) + 0x38);

    if (o[R(0x5cc,0x640)] != 0) {
        *(unsigned short*)(o + R(0x646,0x6be)) = *(unsigned short*)(*(unsigned char**)(p + 0x138));
        *(unsigned short*)(o + R(0x64a,0x6c2)) = *(unsigned short*)(*(unsigned char**)(p + 0x138) + 2);
    } else {
        *(unsigned short*)(o + R(0x646,0x6be)) = *(unsigned short*)(*(unsigned char**)(p + 0x130) + 4);
        *(unsigned short*)(o + R(0x64a,0x6c2)) = *(unsigned short*)(*(unsigned char**)(p + 0x130) + 6);
    }

    if (*(int*)(o + R(0x640,0x6b8)) != 0) o[R(0x63c,0x6b4)] = 1;
    *(int*)(o + R(0x5f8,0x670)) = 0x64;

    for (i = 0; i < 5; i++) {
        (o + i)[R(0x631,0x6a9)] = (unsigned char)GetTableByte020dd11c(o[R(0x630,0x6a8)], (unsigned char)i);
        (o + i)[R(0x624,0x69c)] = 0;
        {
            unsigned char idx = (o + i)[R(0x631,0x6a9)];
            unsigned char* q2 = ctx + idx;
            *(int*)(o + R(0x5fc,0x674) + i * 4) = q2[0x464];
        }
    }
}
