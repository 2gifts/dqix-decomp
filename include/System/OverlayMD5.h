#ifndef SYSTEM_OVERLAY_MD5_H
#define SYSTEM_OVERLAY_MD5_H

#include <globaldefs.h>

struct OverlayMD5Context {
    unsigned int state[4];
    unsigned int bitCount[2];
    unsigned char buffer[64];
};

#if defined(jpn)
#define func_ov031_02221eac func_ov031_0222268c
#define func_ov031_022227c0 func_ov031_02222fa0
#define func_ov031_02222818 func_ov031_02222ff8
#define data_ov031_0224b194 data_ov031_0224bd94
#endif

extern "C" {
void func_ov031_02221e84(OverlayMD5Context*);
void func_ov031_02221eac(OverlayMD5Context*, const void*, unsigned int);
void func_ov031_02221f24(unsigned char*, OverlayMD5Context*);
void func_ov031_022227c0(unsigned char*, const unsigned int*, unsigned int);
void func_ov031_02222830(void*, int, unsigned int);
}

#endif
