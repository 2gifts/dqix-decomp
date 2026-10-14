#include <globaldefs.h>

struct Tween020c0260 { int f0; int f4; int f8; int fc; };
struct State020c0278 { char unk0[8]; int field8; int fieldC; };

ARM void AdvanceTweenStep020c0260(struct Tween020c0260* t);
ARM int CheckField8GeFieldC(struct State020c0278* state);
ARM int EvaluateTween020c022c(struct Tween020c0260* t);
int EnqueueEvent0x14_020d1ff0(int a, int b, int c);

extern "C" void func_020bcf3c(void);

extern char data_0210fd74;
extern char data_0210fdbc;

// USA: func_020bceb4
ARM void UpdateTweenAndNotify020bceb4(void) {
    char* base = &data_0210fdbc;
    if (*(int*)(&data_0210fd74 + 0x48) == 0) {
        return;
    }
    if (*(int*)(base + 0x4) != 0) {
        return;
    }
    AdvanceTweenStep020c0260((struct Tween020c0260*)(base + 0x3c));
    if (*(int*)(base + 0x4c) != 0) {
        if (CheckField8GeFieldC((struct State020c0278*)(base + 0x3c)) != 0) {
            func_020bcf3c();
            return;
        }
    }
    int v = EvaluateTween020c022c((struct Tween020c0260*)(base + 0x3c)) >> 8;
    if (v == *(int*)(base + 0x50)) {
        return;
    }
    EnqueueEvent0x14_020d1ff0(*(int*)(base + 0x24), v, 0);
    *(int*)(base + 0x50) = v;
}
