#include <globaldefs.h>

struct InitTarget0205cfd4;
extern void InitStruct0205cfd4(struct InitTarget0205cfd4* s);

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
extern void ResetList0204af64(struct List0204af64* obj);

extern "C" void func_0204c684(void*);

// JPN: func_ov017_0219a2ac
// USA: func_ov017_021996fc
ARM void InitFieldArenaListsAndCounters_021996fc(unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0xa90, regionalOffset1=0x294, regionalOffset2=0x2d4, regionalOffset3=0x3800, regionalOffset4=0x3000, regionalOffset5=0xe54, regionalOffset6=0xe58, regionalOffset7=0xe5c, regionalOffset8=0xe60, regionalOffset9=0xe64};
#else
 enum {regionalOffset0=0xcb0, regionalOffset1=0xb4, regionalOffset2=0xf4, regionalOffset3=0x3c00, regionalOffset4=0x4000, regionalOffset5=0x74, regionalOffset6=0x78, regionalOffset7=0x7c, regionalOffset8=0x80, regionalOffset9=0x84};
#endif
    InitStruct0205cfd4(*(struct InitTarget0205cfd4**)(base + 0x3000 + regionalOffset0));

    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)(base + regionalOffset1 + regionalOffset3 + i * 0x20));
    }

    for (int j = 0; j < 4; j++) {
        func_0204c684(base + regionalOffset2 + regionalOffset3 + j * 0xe0);
    }

    *(int*)(base + regionalOffset4 + regionalOffset5) = 0;
    *(int*)(base + regionalOffset4 + regionalOffset6) = 0;
    *(int*)(base + regionalOffset4 + regionalOffset7) = -1;
    *(int*)(base + regionalOffset4 + regionalOffset8) = 0;
    *(int*)(base + regionalOffset4 + regionalOffset9) = 0;
}
