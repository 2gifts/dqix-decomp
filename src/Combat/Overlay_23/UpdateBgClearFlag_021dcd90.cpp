#include <globaldefs.h>

#if defined(jpn)
enum { kDisplayFlagOffset = 0x717 };
#else
enum { kDisplayFlagOffset = 0x79b };
#endif


#if defined(jpn)
#define func_ov023_021dcd90 func_ov023_021dd698
#endif
#include "std_library_functions.h"

extern "C" unsigned int GetMainBG1ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);
void ResetPendingSlotsAndFlags_021dcdf4(void* obj);

struct Obj021dcd90 {
    char pad[kDisplayFlagOffset];
    unsigned char bit0 : 1;
    unsigned char flagBit1 : 1;
    unsigned char rest : 6;
};

// USA: func_ov023_021dcd90  (semantic: UpdateBgClearFlag_021dcd90)
extern "C" ARM void func_ov023_021dcd90(Obj021dcd90* obj, unsigned char enable) {
    if (obj->flagBit1 && !enable) {
        memset((void*)GetMainBG1ScreenBase(), 0, 0x800);
        memset((void*)GetMainBG2ScreenBase(), 0, 0x800);
        ResetPendingSlotsAndFlags_021dcdf4(obj);
    }
    obj->flagBit1 = enable;
}
