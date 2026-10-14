#include <globaldefs.h>

#include "System/Interrupts.h"

struct Obj020d6610;

struct Block020d63f0 {
    unsigned short flagsA;
    unsigned char pad[0x1fe];
};

struct Sub020d63f0 {
    unsigned short resultArr[4];
    unsigned short cur;
    unsigned char pad0[0xe];
    unsigned short state;
    unsigned char pad1[2];
    unsigned short status;
};

struct Obj020d66dc {
    Block020d63f0 blocks[4];
    Sub020d63f0 sub;
};

struct Msg020d63f0 {
    unsigned char pad0[2];
    unsigned short subType;
    unsigned short event;
    unsigned char pad6[6];
    int param;
    unsigned char pad10[2];
    unsigned short bit;
    unsigned char pad14[8];
    Obj020d66dc* obj;
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
