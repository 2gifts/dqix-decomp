#include <globaldefs.h>

#include "System/Interrupts.h"

struct Obj020d6610;

struct Block020d63f0 {
    unsigned short flagsA;
    unsigned char pad[0x1fe];
};

struct Sub020d63f0 {
    unsigned short resultArr[4]; // 0x0
    unsigned short cur;          // 0x8
    unsigned char pad0[0xe];     // 0xa
    unsigned short state;        // 0x18
    unsigned char pad1[2];       // 0x1a
    unsigned short status;       // 0x1c
};

struct Obj020d66dc {
    Block020d63f0 blocks[4];
    Sub020d63f0 sub;
};

struct Msg020d63f0 {
    unsigned char pad0[2];       // 0x0
    unsigned short subType;      // 0x2
    unsigned short event;        // 0x4
    unsigned char pad6[6];       // 0x6
    int param;                   // 0xc
    unsigned char pad10[2];      // 0x10
    unsigned short bit;          // 0x12
    unsigned char pad14[8];      // 0x14
    Obj020d66dc* obj;            // 0x1c
};

extern "C" void _Z28ClearAndSetBlockFlag020d6610P11Obj020d6610ii(Obj020d6610* obj, int bit, int extra);
extern "C" void _Z31AdvanceBattleBlockQueue020d66dcP11Obj020d66dci(Obj020d66dc* obj, int mode);

// USA: func_020d63f0
extern "C" ARM void func_020d63f0(Msg020d63f0* msg) {
    Obj020d66dc* obj = msg->obj;
    if (obj == 0) return;
    if (msg->subType == 0) {
        switch (msg->event) {
        case 0x15:
            _Z28ClearAndSetBlockFlag020d6610P11Obj020d6610ii((Obj020d6610*)obj, msg->bit, msg->param);
            _Z31AdvanceBattleBlockQueue020d66dcP11Obj020d66dci(obj, 0);
            break;
        case 7:
            _Z31AdvanceBattleBlockQueue020d66dcP11Obj020d66dci(obj, 0);
            break;
        case 0x19:
            break;
        case 9:
        case 0x1a: {
            unsigned short bit = msg->bit;
            unsigned int mask = 1U << bit;
            int state = DisableIRQInterrupts();
            unsigned short cur = obj->sub.cur;
            mask = ~mask;
            obj->blocks[cur].flagsA &= mask;
            if (obj->sub.state == 1) {
                unsigned short next = (cur + 1) & 3;
                obj->blocks[next].flagsA &= mask;
            }
            SetIRQInterruptState(state);
            _Z31AdvanceBattleBlockQueue020d66dcP11Obj020d66dci(obj, 0);
            if (obj->sub.state == 1) {
                _Z31AdvanceBattleBlockQueue020d66dcP11Obj020d66dci(obj, 0);
            }
            break;
        }
        }
    } else {
        obj->sub.status = 5;
    }
}
