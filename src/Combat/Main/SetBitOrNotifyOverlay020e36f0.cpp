#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
extern "C" int func_0202c508(void*);
extern "C" void func_ov017_021ced48(int, int);

// USA: func_020e36f0
ARM void SetBitOrNotifyOverlay020e36f0(unsigned char* obj) {
    void* state = func_0202ae18();
    if (!CheckField0NonZero_0202b7d8((int*)state)) return;
    if (func_0202c508(state)) {
        if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())) {
            obj[0] |= 1;
        }
        return;
    }
    func_ov017_021ced48(0, 0);
}
