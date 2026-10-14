#include <globaldefs.h>

extern "C" void func_020c9be0(void);
extern "C" void func_020a1940(int);
struct InputLog {
    unsigned char countA;
    unsigned char countB;
    signed char logB[8];
    signed char logA[8];
};
extern InputLog data_02109da4;
extern signed char data_020f1977[];

// USA: func_020a1ef0
ARM void PushInputLogB_020a1ef0(int id) {
    if (data_02109da4.countB >= 8) func_020c9be0();
    if ((unsigned int)id >= 7) return;
    func_020a1940(data_020f1977[id]);
    data_02109da4.logB[data_02109da4.countB] = id;
    data_02109da4.countB++;
}
