#if defined(jpn)
#define R(j,u) (j)
#define _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30 func_ov009_02185f5c
#define func_ov009_02184bbc func_ov009_02185ee8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int SendQueuedDataToGeometryFifo();
extern "C" unsigned int _Z18GetField0x3b0ValueP9GameState();
extern "C" unsigned int _Z26ResetGxEngineState020c52e8v();
extern "C" unsigned int _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(unsigned int);
extern "C" unsigned int _Z29WriteControlAndToggle020d86d0ii(unsigned int, unsigned int);
extern "C" unsigned int _Z33CleanInvalidateOamBuffers0203bd88v();
extern "C" unsigned int _ZN12RenderConfig12SubmitToFifoEv();
extern "C" unsigned int func_0202e0a4(unsigned int, unsigned int);
extern "C" unsigned int func_0203bd08();
extern "C" unsigned int func_020c5414();
extern "C" unsigned int func_ov009_02184bbc(unsigned int);

// USA: func_ov021_0218bb30  (semantic: Trans_0218bb30)
extern "C" ARM unsigned int func_ov021_0218bb30(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    int cc = 0;
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r5 = r0;
    r0 = (unsigned int)GameState::GetInstance();
    r0 = (unsigned int)_Z18GetField0x3b0ValueP9GameState();
    r4 = r0;
    r0 = (unsigned int)_Z26ResetGxEngineState020c52e8v();
    r0 = (unsigned int)func_020c5414();
    r1 = 0x4000060;
    cc = (int)(r4) - (int)(0x0);
    r0 = *(unsigned short*)((char*)r1 + 0x0);
    r0 = r0 & ~0x3000;
    r0 = r0 | 0x8;
    *(unsigned short*)((char*)r1 + 0x0) = (unsigned short)r0;
    r0 = *(unsigned short*)((char*)r1 + 0x0);
    r0 = r0 & ~0x3000;
    r0 = r0 | 0x10;
    *(unsigned short*)((char*)r1 + 0x0) = (unsigned short)r0;
    r0 = *(unsigned short*)((char*)r1 + 0x0);
    r0 = r0 & ~0x3000;
    r0 = r0 | 0x20;
    *(unsigned short*)((char*)r1 + 0x0) = (unsigned short)r0;
    if (cc == 0) { goto L60; }
    r0 = r4;
    r0 = (unsigned int)func_0202e0a4(r0, r1);
L60:;
    r0 = (unsigned int)_ZN12RenderConfig12SubmitToFifoEv();
    r0 = (unsigned int)SendQueuedDataToGeometryFifo();
    r0 = *(unsigned int*)((char*)r5 + 0x40);
    r0 = (unsigned int)_Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(r0);
    r0 = *(unsigned int*)((char*)r5 + 0x40);
    r0 = (unsigned int)func_ov009_02184bbc(r0);
    r0 = (unsigned int)func_0203bd08();
    r0 = (unsigned int)_Z33CleanInvalidateOamBuffers0203bd88v();
    r0 = 0x1;
    r1 = 0x0;
    r0 = (unsigned int)_Z29WriteControlAndToggle020d86d0ii(r0, r1);
    return r0;
}
