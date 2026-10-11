#include <globaldefs.h>

#if defined(jpn)
extern "C" void func_0206982c(void* obj, int count);
#define RepeatStepClampedToField0x3c4 func_0206982c
#else
void RepeatStepClampedToField0x3c4(void* obj, int count);
#endif

// USA: func_0204359c
ARM void Forward0204359c(void* obj, int count) {
    RepeatStepClampedToField0x3c4(obj, count);
}
