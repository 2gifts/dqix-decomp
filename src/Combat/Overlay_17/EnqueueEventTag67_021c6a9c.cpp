#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Inner021c6a9c {
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
    unsigned char field9;
    unsigned char fielda;
    unsigned char fieldb;
    unsigned char pad[8];
};

struct LocalEvt021c6a9c {
    unsigned char tag;
    unsigned char pad0[3];
    struct Inner021c6a9c fields;
};

// USA: func_ov017_021c6a9c
ARM void EnqueueEventTag67_021c6a9c(unsigned short a0, int a1, int a2, unsigned char a3, unsigned char a4, signed char a5) {
    void* p = GetData02100044();
    LocalEvt021c6a9c buf;
    struct Inner021c6a9c* r6 = &buf.fields;
    GameState::GetInstance();
    unsigned char a4v = a4;
    signed char a5v = a5;
    r6->field9 = a4v;
    buf.tag = 0x43;
    r6->field4 = a0;
    r6->field6 = a2;
    r6->field8 = a3;
    r6->fielda = a1;
    r6->fieldb = a5v;
    func_0205e330(p, &buf, 0);
}
