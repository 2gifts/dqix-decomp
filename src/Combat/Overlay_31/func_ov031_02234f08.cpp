#include <globaldefs.h>

struct OwnedState_02234f08 {
    void* payload;
};

extern OwnedState_02234f08* data_ov031_02290ce8;
int TailCallForward_0223e2e0(int, void*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_02234f08
extern "C" ARM void func_ov031_02234f08(void) {
    TailCallForward_0223e2e0(1, data_ov031_02290ce8->payload);
// Keep the second pool entry separate, as in both original ROMs.
#if defined(jpn)
    func_ov031_0223cf70((void**)0x022918e8);
#else
    func_ov031_0223cf70((void**)0x02290ce8);
#endif
}
