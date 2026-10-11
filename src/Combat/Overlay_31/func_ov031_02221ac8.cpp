#include <globaldefs.h>

extern "C" const unsigned int data_ov031_02248110[256];   // Td0
extern "C" const unsigned int data_ov031_02248510[256];   // Td1
extern "C" const unsigned int data_ov031_02246110[256];   // Td2
extern "C" const unsigned int data_ov031_02246510[256];   // Td3
extern "C" const unsigned int data_ov031_02246910[256];   // Td4

#define Td0 data_ov031_02248110
#define Td1 data_ov031_02248510
#define Td2 data_ov031_02246110
#define Td3 data_ov031_02246510
#define Td4 data_ov031_02246910

#define GETU32(p) \
    (((unsigned int)(p)[0] << 24) ^ ((unsigned int)(p)[1] << 16) ^ \
     ((unsigned int)(p)[2] << 8) ^ ((unsigned int)(p)[3]))

#define PUTU32(ct, st) { \
    (ct)[0] = (unsigned char)((st) >> 24); \
    (ct)[1] = (unsigned char)((st) >> 16); \
    (ct)[2] = (unsigned char)((st) >> 8);  \
    (ct)[3] = (unsigned char)(st); }

// USA: func_ov031_02221ac8
#pragma optimize_for_size off
extern "C" THUMB void func_ov031_02221ac8(const unsigned int *rk, int Nr,
                                           const unsigned char *ct, unsigned char *pt) {
    unsigned int s0, s1, s2, s3, t0, t1, t2, t3;
    int r;

    s0 = GETU32(ct     ) ^ rk[0];
    s1 = GETU32(ct +  4) ^ rk[1];
    s2 = GETU32(ct +  8) ^ rk[2];
    s3 = GETU32(ct + 12) ^ rk[3];

    r = Nr >> 1;
    for (;;) {
        t0 =
            Td0[(s0 >> 24)       ] ^
            Td1[(s3 >> 16) & 0xff] ^
            Td2[(s2 >>  8) & 0xff] ^
            Td3[(s1      ) & 0xff] ^
            rk[4];
        t1 =
            Td0[(s1 >> 24)       ] ^
            Td1[(s0 >> 16) & 0xff] ^
            Td2[(s3 >>  8) & 0xff] ^
            Td3[(s2      ) & 0xff] ^
            rk[5];
        t2 =
            Td0[(s2 >> 24)       ] ^
            Td1[(s1 >> 16) & 0xff] ^
            Td2[(s0 >>  8) & 0xff] ^
            Td3[(s3      ) & 0xff] ^
            rk[6];
        t3 =
            Td0[(s3 >> 24)       ] ^
            Td1[(s2 >> 16) & 0xff] ^
            Td2[(s1 >>  8) & 0xff] ^
            Td3[(s0      ) & 0xff] ^
            rk[7];

        rk += 8;
        if (--r == 0) {
            break;
        }

        s0 =
            Td0[(t0 >> 24)       ] ^
            Td1[(t3 >> 16) & 0xff] ^
            Td2[(t2 >>  8) & 0xff] ^
            Td3[(t1      ) & 0xff] ^
            rk[0];
        s1 =
            Td0[(t1 >> 24)       ] ^
            Td1[(t0 >> 16) & 0xff] ^
            Td2[(t3 >>  8) & 0xff] ^
            Td3[(t2      ) & 0xff] ^
            rk[1];
        s2 =
            Td0[(t2 >> 24)       ] ^
            Td1[(t1 >> 16) & 0xff] ^
            Td2[(t0 >>  8) & 0xff] ^
            Td3[(t3      ) & 0xff] ^
            rk[2];
        s3 =
            Td0[(t3 >> 24)       ] ^
            Td1[(t2 >> 16) & 0xff] ^
            Td2[(t1 >>  8) & 0xff] ^
            Td3[(t0      ) & 0xff] ^
            rk[3];
    }

    s0 =
        (Td4[(t0 >> 24)       ] & 0xff000000) ^
        (Td4[(t3 >> 16) & 0xff] & 0x00ff0000) ^
        (Td4[(t2 >>  8) & 0xff] & 0x0000ff00) ^
        (Td4[(t1      ) & 0xff] & 0x000000ff) ^
        rk[0];
    PUTU32(pt, s0);

    s1 =
        (Td4[(t1 >> 24)       ] & 0xff000000) ^
        (Td4[(t0 >> 16) & 0xff] & 0x00ff0000) ^
        (Td4[(t3 >>  8) & 0xff] & 0x0000ff00) ^
        (Td4[(t2      ) & 0xff] & 0x000000ff) ^
        rk[1];
    PUTU32(pt + 4, s1);

    s2 =
        (Td4[(t2 >> 24)       ] & 0xff000000) ^
        (Td4[(t1 >> 16) & 0xff] & 0x00ff0000) ^
        (Td4[(t0 >>  8) & 0xff] & 0x0000ff00) ^
        (Td4[(t3      ) & 0xff] & 0x000000ff) ^
        rk[2];
    PUTU32(pt + 8, s2);

    s3 =
        (Td4[(t3 >> 24)       ] & 0xff000000) ^
        (Td4[(t2 >> 16) & 0xff] & 0x00ff0000) ^
        (Td4[(t1 >>  8) & 0xff] & 0x0000ff00) ^
        (Td4[(t0      ) & 0xff] & 0x000000ff) ^
        rk[3];
    PUTU32(pt + 12, s3);
}
