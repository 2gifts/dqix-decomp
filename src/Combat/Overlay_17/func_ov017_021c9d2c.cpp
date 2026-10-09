#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvtBody021c9d2c {
    unsigned char slot : 3;
    unsigned char flagA : 1;
    unsigned char flagB : 1;
    unsigned char byte1;
    unsigned short field2;
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned int fieldc;
};

struct LocalEvt021c9d2c {
    unsigned char tag;
    unsigned char pad0[3];
    LocalEvtBody021c9d2c body;
};

static inline int IsValidSlot(int slot) {
    return slot >= 0 && slot <= 3;
}

// USA: func_ov017_021c9d2c
extern "C" ARM void func_ov017_021c9d2c(int slot, unsigned short a1, unsigned short a2, unsigned short a3, int a4, unsigned int a5, unsigned char a6, int flagA, int flagB) {
    void* p = GetData02100044();
    GameState::GetInstance();
    if (IsValidSlot(slot)) {
        LocalEvt021c9d2c buf;
        buf.tag = 4;
        LocalEvtBody021c9d2c* body = &buf.body;
        body->slot = slot;
        body->field2 = a1;
        body->field6 = a3;
        body->field4 = a2;
        body->field8 = a4;
        body->byte1 = a6;
        body->fieldc = a5;
        body->flagA = flagA;
        body->flagB = flagB;
        func_0205e330(p, &buf, 0);
    }
}
