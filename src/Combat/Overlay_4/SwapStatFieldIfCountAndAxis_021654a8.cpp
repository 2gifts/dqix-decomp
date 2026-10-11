#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { countOffset=0x9f4,pageBase=0x1900 };
#else
enum { countOffset=0x8f4,pageBase=0x1800 };
#endif

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* self);
#define NODE_KIND_CALL func_ov023_021f6f10
#else
int ScaleStatsIfType12_021f6f10(void* self);
#define NODE_KIND_CALL ScaleStatsIfType12_021f6f10
#endif
struct AxisFloats0203b5f8;
int IsAxisIntZero(struct AxisFloats0203b5f8* s, int axis);
extern char* data_ov004_02171010;
struct ShortPairSrc0216351c;
void CopyShortPair0216351c(struct ShortPairSrc0216351c* src, short* out1, short* out2);
extern "C" void func_ov004_02164084(void* a1);

// USA: func_ov004_021654a8
ARM int SwapStatFieldIfCountAndAxis_021654a8(void* a1) {
    GameState::GetInstance();
    struct AxisFloats0203b5f8* axis = ((struct AxisFloats0203b5f8*)func_ov017_0218b5b0());
    void* obj = func_ov023_021f6880(func_ov011_021849c8(a1), 0xa);
    if (obj == NULL) return 0;
    if (NODE_KIND_CALL(obj) != 7) return 0;

    unsigned char count = *(unsigned char*)(data_ov004_02171010 + 0x1000 + countOffset);
    if (count <= 8) goto fastpath;
    if (IsAxisIntZero(axis, 0) != 0) goto swappath;

fastpath: {
    char* base = data_ov004_02171010 + pageBase;
    short f8 = *(short*)(base + 0xf8);
    short f6 = *(short*)(base + 0xf6);
    *(short*)((char*)obj + 0x5c) = f6;
    *(short*)((char*)obj + 0x5e) = f8;
    return 0;
}

swappath: {
    char* base2 = data_ov004_02171010;
    short* p1 = (short*)(base2 + 0xf6 + pageBase);
    #if defined(jpn)
    short* p2 = (short*)(base2 + 0x1f8 + 0x1800);
#else
    short* p2 = (short*)(base2 + 0xf8 + pageBase);
#endif
    CopyShortPair0216351c((struct ShortPairSrc0216351c*)obj, p1, p2);
    func_ov004_02164084(a1);
    return 0;
}
}
