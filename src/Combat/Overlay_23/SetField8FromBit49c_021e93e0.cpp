#include <globaldefs.h>

#if defined(jpn)
enum { kSubPointerOffset = 0x144 };
#else
enum { kSubPointerOffset = 0x150 };
#endif


#if defined(jpn)
#define SetField8FromBit49c_021e93e0 func_ov023_021e9344
#endif
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov023_021e8f28(int v);
extern "C" void func_ov017_021d6134(void* obj, int v);

struct Sub0x150_021e93e0 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_ov023_021e93e0
#if defined(jpn)
extern "C"
#endif
ARM int SetField8FromBit49c_021e93e0(void* obj) {
    GameState::GetInstance();
    void* p = func_ov023_021e8f28(func_ov017_021d60f4(obj));
    if (p == NULL) {
        return 0;
    }
    struct Sub0x150_021e93e0* q = *(struct Sub0x150_021e93e0**)((char*)p + kSubPointerOffset);
    func_ov017_021d6134((char*)obj + 8, q->bit0);
    return 1;
}
