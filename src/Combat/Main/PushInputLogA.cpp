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
extern signed char data_020f1962[];

// USA: _Z13PushInputLogAi
ARM void PushInputLogA(int id) {
    if (data_02109da4.countA >= 8) func_020c9be0();
    if ((unsigned int)id >= 7) return;
    func_020a1940(data_020f1962[id]);
    data_02109da4.logA[data_02109da4.countA] = id;
    data_02109da4.countA++;
}
