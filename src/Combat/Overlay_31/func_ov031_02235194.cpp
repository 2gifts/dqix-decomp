#include <globaldefs.h>

struct OwnedState_02235194 {
    void* inner;
    char padding[8];
    void* payload;
};

extern OwnedState_02235194* data_ov031_02290cf4;
int TailCallForward_0223e2e0(int, void*);
extern "C" void func_ov031_0223ba20(void*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_02235194
extern "C" ARM void func_ov031_02235194(void) {
    TailCallForward_0223e2e0(0, data_ov031_02290cf4->payload);
    func_ov031_0223ba20(data_ov031_02290cf4->inner);
    // Keep the second pool entry separate, as in both original ROMs.
#if defined(jpn)
    func_ov031_0223cf70((void**)0x022918f4);
#else
    func_ov031_0223cf70((void**)0x02290cf4);
#endif
}
