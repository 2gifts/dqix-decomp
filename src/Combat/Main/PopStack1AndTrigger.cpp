#include <globaldefs.h>

extern "C" void func_020a1940(int);
struct InputLog {
    unsigned char countA;
    unsigned char countB;
    signed char logB[8];
    signed char logA[8];
};
extern InputLog data_02109da4;
extern signed char data_020f1977[];

static inline int GetCountB(const InputLog* p) { return p->countB; }

// USA: func_020a1f4c
ARM void PopStack1AndTrigger(int flag) {
    if (GetCountB(&data_02109da4) == 0) return;
    data_02109da4.countB--;
    if (flag == 0 || GetCountB(&data_02109da4) == 0) return;
    signed char i = data_02109da4.logB[data_02109da4.countB - 1];
    func_020a1940(data_020f1977[i]);
}
