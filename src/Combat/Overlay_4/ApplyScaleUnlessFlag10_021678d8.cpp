#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0208bb78(void* obj, int count);

// USA: func_ov004_021678d8  (semantic: ApplyScaleUnlessFlag10_021678d8)
extern "C" ARM void func_ov004_021678d8(void* obj) {
    unsigned char flags = *((unsigned char*)obj + 0xc);
    if (flags & 0x10) return;
    unsigned int count = GameState::GetInstance()->GetTickCount();
    if (count == 0) count = 1;
    func_0208bb78((char*)obj + 0x34, count);
}
