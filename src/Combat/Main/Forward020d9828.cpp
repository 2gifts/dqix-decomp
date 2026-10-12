#include <globaldefs.h>
struct ProcessorContext;
void MarkContextReadyAndSwitch(struct ProcessorContext*);

#if defined(jpn)
#define Forward020d9828 func_020db234
extern "C" ARM void func_020db234(void* p);
#endif

// USA: _Z15Forward020d9828Pv
ARM void Forward020d9828(void* p) {
    MarkContextReadyAndSwitch((struct ProcessorContext*)p);
}
