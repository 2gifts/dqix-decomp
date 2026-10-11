#include <globaldefs.h>

struct OwnedState_0223684c {
    char padding[0x9c];
    void* payload;
};

extern "C" OwnedState_0223684c* data_ov031_02290d00;
namespace DuplicatePool {
    extern "C" OwnedState_0223684c* data_ov031_02290d00;
}
extern "C" void func_ov031_0223e2c0(int, void*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_0223684c
extern "C" ARM void func_ov031_0223684c(void) {
    func_ov031_0223e2c0(0, data_ov031_02290d00->payload);
    func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290d00);
}
