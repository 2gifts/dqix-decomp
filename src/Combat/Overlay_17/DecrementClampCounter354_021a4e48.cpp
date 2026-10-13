#include <globaldefs.h>
#if defined(jpn)
enum { kCounterOffset = 0x4134 };
#else
enum { kCounterOffset = 0x4354 };
#endif

struct CounterOwner {
    unsigned char unknown0[kCounterOffset];
    signed char counter;
};

// USA: func_ov017_021a4e48
ARM void DecrementClampCounter354_021a4e48(unsigned char* obj) {
    CounterOwner* owner = (CounterOwner*)obj;
    owner->counter--;
    if (owner->counter < 0) {
        owner->counter = 0;
    }
}
