#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct MsgCtl0216b7bc {
    char pad0[0x5c];
    char* textBuf;
    char pad60[0x998 - 0x60];
    int busy;
    int mode;
    int status;
    char pad9a4[0x19b2 - 0x9a4];
    unsigned char autoAdvance;
};

struct Progress840 {
    char pad0[0x1b42];
    unsigned char rewardFlags;
};

struct Container020e0310;

struct Msg0216b7bc {
    char pad0[4];
    short state;
    short subState;
    char pad8[2];
    short request;
    char padC[0x1324 - 0xc];
    char names[4];
};

extern "C" struct MsgCtl0216b7bc* _Z26GetGlobalField0x1c020421a0v();
extern "C" void* func_02012fe4(void);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" void func_02046380(struct MsgCtl0216b7bc* ctl);
extern "C" void func_0204500c(struct MsgCtl0216b7bc* ctl, char* text, int a, int b);
extern "C" void func_ov003_0216d8d4(struct Msg0216b7bc* obj, int key, int p3, int p4, int p5);

extern char data_ov003_021801b2[];
extern char data_ov003_021801c2[];

// USA: func_ov003_0216b7bc
extern "C" ARM void func_ov003_0216b7bc(struct Msg0216b7bc* obj) {
    struct MsgCtl0216b7bc* ctl = _Z26GetGlobalField0x1c020421a0v();
    GameState::GetInstance();
    if (obj->request == 3) {
        obj->subState = 2;
        obj->request = 0;
    }
    if (obj->subState == 0) {
        struct Progress840* progress = (struct Progress840*)((char*)func_02012fe4() + 0x840);
        char* buf = ctl->textBuf;
        memset(buf, 0, 0x960);
        _Z20AppendString02042058PcPKc(buf, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)obj->names, 0));
        if (progress->rewardFlags == 0) {
            _Z20AppendString02042058PcPKc(buf, data_ov003_021801b2);
        } else {
            _Z20AppendString02042058PcPKc(buf, data_ov003_021801c2);
        }
        unsigned char flags = progress->rewardFlags;
        int idx = -1;
        if (flags & 1) {
            idx = 1;
        } else if (flags & 2) {
            idx = 2;
        } else if (flags & 4) {
            idx = 3;
        } else if (flags & 8) {
            idx = 4;
        } else if (flags & 0x10) {
            idx = 5;
        }
        if (idx >= 0) {
            _Z20AppendString02042058PcPKc(buf, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)obj->names, idx));
        }
        progress->rewardFlags &= ~0xff;
        func_02046380(ctl);
        func_0204500c(ctl, buf, 0, 0xe3);
        ctl->autoAdvance = 1;
        ctl->mode = 2;
        ctl->busy = 1;
        obj->subState = 1;
    } else if (obj->subState == 1) {
        if (ctl->status == 3) {
            func_ov003_0216d8d4(obj, 0x29, -1, -1, -1);
            obj->subState = 2;
        }
    } else if (obj->subState == 2 && ctl->status == 3) {
        obj->state = 2;
        obj->subState = 0;
    }
}
