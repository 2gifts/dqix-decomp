#include <globaldefs.h>

struct OwnedState_0223da0c {
    char padding[0x808];
    void* payload;
};

extern OwnedState_0223da0c* data_ov031_02290d60;
int TailCallForward_0223e2e0(int, void*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_0223da0c
extern "C" ARM void func_ov031_0223da0c(void) {
    TailCallForward_0223e2e0(1, data_ov031_02290d60->payload);
// Keep the second pool entry separate, as in both original ROMs.
#if defined(jpn)
    func_ov031_0223cf70((void**)0x02291960);
#else
    func_ov031_0223cf70((void**)0x02290d60);
#endif
}
