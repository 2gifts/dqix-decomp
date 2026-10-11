#include <globaldefs.h>

#if defined(jpn)
enum { kObjectOffset = 0x4c0 };
#else
enum { kObjectOffset = 0x6d0 };
#endif


extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_02012fe4(void);
struct Obj02022d78;
void SetActiveModeSavingPrevious02022d78(struct Obj02022d78*, int);
int IsInRange0201b588(int);

// USA: func_020dc214
ARM void SetModeBasedOnCombatState020dc214(int mode) {
    int base = func_ov017_0218b5b0();
    void* raw = *(void**)(base + 0x3000 + kObjectOffset);
    unsigned short id = *(unsigned short*)func_02012fe4();
    struct Obj02022d78* obj = (struct Obj02022d78*)raw;
    if (mode == 1) {
        SetActiveModeSavingPrevious02022d78(obj, 1);
        return;
    }
    if (mode == 2) {
        SetActiveModeSavingPrevious02022d78(obj, 4);
        return;
    }
    if (mode != 0) {
        return;
    }
    if (IsInRange0201b588(id)) {
        SetActiveModeSavingPrevious02022d78(obj, 3);
        return;
    }
    if (id == 0x2710 || id == 0x2774) {
        SetActiveModeSavingPrevious02022d78(obj, 4);
    } else {
        SetActiveModeSavingPrevious02022d78(obj, 0);
    }
}
