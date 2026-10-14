#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
unsigned short GetBattleContextField0x14cLow16_020d46fc(void);
extern "C" void func_020ca390(int, void*, unsigned int);
extern "C" int func_020d59bc(void* cb, void* obj, void* blockPtr, unsigned short f14, unsigned short maskedFlags, unsigned short f16, int one);
extern "C" int func_020d6318(void*);

struct Sub020d66dc {
    unsigned short resultArr[4];
    unsigned short cur;
    unsigned short counter;
    unsigned char pad0[2];
    unsigned short flags;
    unsigned char pad1[4];
    unsigned short field14;
    unsigned short field16;
    unsigned short state;
    unsigned char pad2[2];
    unsigned short status;
};

struct Block020d66dc {
    unsigned short flagsA;
    unsigned char pad[0x1fe];
};

struct Obj020d66dc {
    Block020d66dc blocks[4];
    Sub020d66dc sub;
};

#pragma optimize_for_size off
// USA: func_020d66dc
ARM void AdvanceBattleBlockQueue020d66dc(Obj020d66dc* obj, int mode) {
    unsigned int state = DisableIRQInterrupts();
    if (obj->blocks[obj->sub.cur].flagsA == 0) {
        unsigned short ctxVal = GetBattleContextField0x14cLow16_020d46fc();
        unsigned short oldCur = obj->sub.cur;
        unsigned short newCur = (oldCur + 1) & 3;
        int nextIdx = (obj->sub.state == 1) ? ((newCur + 1) & 3) : newCur;

        func_020ca390(0, &obj->blocks[nextIdx], 0x200);

        obj->blocks[nextIdx].flagsA = obj->sub.flags & (ctxVal | 1);
        obj->sub.cur = newCur;
        unsigned short flagsSnapshot = obj->sub.flags;
        obj->blocks[oldCur].flagsA = flagsSnapshot;
        if (mode == 1) {
            obj->blocks[oldCur].flagsA &= ~1;
        }

        SetIRQInterruptState(state);

        unsigned short maskedFlags = (unsigned short)(obj->sub.flags & ctxVal);
        unsigned short f16 = obj->sub.field16;
        unsigned short f14 = obj->sub.field14;
        int result = func_020d59bc((void*)func_020d6318, obj, &obj->blocks[oldCur], f14, maskedFlags, f16, 1);

        if (result == 7) {
            obj->sub.resultArr[oldCur] = 0xffff;
            obj->sub.counter = (obj->sub.counter + 1) & 3;
        } else {
            if (result == 0 || result == 2) {
                return;
            }
            obj->sub.status = 5;
        }
    } else {
        SetIRQInterruptState(state);
    }
}
