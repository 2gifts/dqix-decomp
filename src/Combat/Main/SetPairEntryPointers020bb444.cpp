#include <globaldefs.h>
#if defined(jpn)
#define data_020f1f14 data_020f2080
#define data_020f1ef8 data_020f2064
#endif

struct PairEntry020bb444 { unsigned char pad[0x18]; };
struct PairContext020bb444 {
    unsigned char pad[8];
    struct PairEntry020bb444 *e0, *e1, *e2, *e3, *e4;
};

extern struct PairEntry020bb444 data_020f1f14[];
extern struct PairContext020bb444 data_020f1ef8;

// USA: func_020bb444
ARM void SetPairEntryPointers020bb444(int i0, int i1, int i2, int i3, int i4) {
    data_020f1ef8.e0 = &data_020f1f14[i0];
    data_020f1ef8.e1 = &data_020f1f14[i1];
    data_020f1ef8.e2 = &data_020f1f14[i2];
    data_020f1ef8.e3 = &data_020f1f14[i3];
    data_020f1ef8.e4 = &data_020f1f14[i4];
}
