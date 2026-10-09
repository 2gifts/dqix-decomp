#include <globaldefs.h>
#include "GameState/GameState.h"

extern unsigned short __attribute__((aligned(4))) data_020e8a8c[];

int TestBitInArray0x8ec(unsigned char* obj, int index);
extern "C" int _Z19GetSlotBits0201137cPci(char* base, int id);

// USA: func_02085cd0
extern "C" ARM int func_02085cd0(unsigned char* actor, int mode) {
    if (mode < 0) {
        short v = *(short*)(actor + 0x2ac);
        if (v > 0) {
            int x = *(int*)(actor + 0x29c);
            mode = (unsigned int)(x << 23) >> 27;
        } else {
            mode = 0x21;
        }
    }
    GameState* bs = GameState::GetInstance();
    short ids[4];
    {
        const unsigned short* src = data_020e8a8c;
        short* dst = ids;
        int n = 4;
        do {
            *dst++ = *src++;
        } while (--n);
    }
    switch (mode) {
    case 0x21:
        ids[0] = 0x84;
        ids[1] = 0x8a;
        ids[2] = 0x8d;
        break;
    case 0:
        ids[0] = 1;
        ids[1] = 5;
        ids[2] = 7;
        break;
    case 1:
        ids[0] = 0xb;
        ids[1] = 0xf;
        ids[2] = 0x11;
        break;
    case 2:
        ids[0] = 0x17;
        ids[1] = 0x19;
        ids[2] = 0x1d;
        break;
    case 3:
        break;
    case 4:
        ids[0] = 0x59;
        ids[1] = 0x5b;
        ids[2] = 0x5d;
        break;
    case 5:
        ids[0] = 0x42;
        ids[1] = 0x44;
        ids[2] = 0x4a;
        break;
    case 6:
        ids[0] = 0x6f;
        ids[1] = 0x73;
        ids[2] = 0x75;
        break;
    case 7:
        ids[0] = 0x79;
        ids[1] = 0x7b;
        ids[2] = 0x7f;
        break;
    case 8:
        ids[0] = 0xb1;
        ids[1] = 0xb3;
        ids[2] = 0xb7;
        break;
    case 9:
        ids[0] = 0xbb;
        ids[1] = 0xbf;
        ids[2] = 0xc1;
        break;
    case 10:
        ids[0] = 0xf3;
        ids[1] = 0xf5;
        ids[2] = 0xf7;
        break;
    case 11:
        ids[0] = 0xd1;
        ids[1] = 0xd3;
        ids[2] = 0xd7;
        break;
    }
    int total = 0;
    unsigned char i;
    short idx;
    for (i = 0; (idx = ids[i]) != -1; i++) {
        if (TestBitInArray0x8ec(actor, idx)) {
            total += _Z19GetSlotBits0201137cPci((char*)bs, idx);
        }
    }
    return total;
}