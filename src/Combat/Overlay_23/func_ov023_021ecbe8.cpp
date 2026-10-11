#include <globaldefs.h>
#include "GameState/GameState.h"


// JPN: func_ov023_021ecb3c
// USA: func_ov023_021ecbe8  (semantic: AdvanceFadeState_021ecbe8)
extern "C" ARM void func_ov023_021ecbe8(char* obj) {
#if defined(jpn)
    enum { recordStride = 0x15c };
#else
    enum { recordStride = 0x244 };
#endif
    if (!(*(unsigned short*)(obj + 0x438) & 0x40)) return;

    unsigned char state = *(unsigned char*)(obj + 0x433);
    if (state == 0) {
        unsigned char idx = *(unsigned char*)(obj + 0x28);
        char* arr = *(char**)(obj + 0x20);
        unsigned int category = (*(unsigned int*)(arr + idx * recordStride)) >> 30;

        switch (category) {
        case 0:
            *(unsigned char*)(obj + 0x43d) = 0;
            *(short*)(obj + 0x440) = 3;
            *(short*)(obj + 0x442) = 3;
            *(short*)(obj + 0x444) = 0x1a;
            *(short*)(obj + 0x446) = 7;
            break;
        case 1:
            *(unsigned char*)(obj + 0x43d) = 1;
            *(short*)(obj + 0x440) = 3;
            *(short*)(obj + 0x442) = 3;
            *(short*)(obj + 0x444) = 0x1a;
            *(short*)(obj + 0x446) = 7;
            break;
        case 2:
            *(unsigned char*)(obj + 0x43d) = 2;
            *(short*)(obj + 0x440) = 0;
            *(short*)(obj + 0x442) = 1;
            *(short*)(obj + 0x444) = 0x20;
            *(short*)(obj + 0x446) = 0xb;
            break;
        }

        *(short*)(obj + 0x43a) = 0x60;
        *(short*)(obj + 0x43e) = (short)((*(short*)(obj + 0x43a) - (*(short*)(obj + 0x442) << 3) - 0x41) / 8 + 2);
        if (*(short*)(obj + 0x43e) <= 0) *(short*)(obj + 0x43e) = 0;
        *(unsigned char*)(obj + 0x433) = *(unsigned char*)(obj + 0x433) + 1;
    }

    if (state == 1) {
        GameState* bs = GameState::GetInstance();
        unsigned int scaleCount = bs->GetTickCount();

        int sum = *(unsigned char*)(obj + 0x43c) + (int)scaleCount;
        *(unsigned char*)(obj + 0x43c) = (unsigned char)sum;
        float ratio = (float)(unsigned int)(sum & 0xff) / 60.0f;
        float one = 1.0f;
        float f43a = (float)*(short*)(obj + 0x43a);
        float diff = ratio - one;
        float tmp = f43a * diff;
        *(short*)(obj + 0x43a) = (short)(tmp * (ratio - one));

        *(short*)(obj + 0x43e) = (short)((*(short*)(obj + 0x43a) - (*(short*)(obj + 0x442) << 3) - 0x41) / 8 + 2);
        if (*(short*)(obj + 0x43e) <= 0) *(short*)(obj + 0x43e) = 0;

        if (*(short*)(obj + 0x43a) < 1) {
            *(short*)(obj + 0x43a) = 0;
            *(unsigned char*)(obj + 0x433) = *(unsigned char*)(obj + 0x433) + 1;
        }
    }

    if (state != 2) return;

    *(unsigned short*)(obj + 0x438) = *(unsigned short*)(obj + 0x438) & ~0x40;
    *(unsigned char*)(obj + 0x433) = 0;
}
