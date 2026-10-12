#include <globaldefs.h>

#if defined(jpn)
#define SetFromRegionMinus1_021ea3ac func_ov023_021ea310
#endif
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int n);
unsigned char CopyOutRegion0x5718(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021ea3ac
#if defined(jpn)
extern "C"
#endif
ARM int SetFromRegionMinus1_021ea3ac(void* obj) {
    GameState* bs = GameState::GetInstance();
    char buf[4];
    __clear(buf, 4);
    int v = CopyOutRegion0x5718((char*)bs, buf);
    func_ov017_021d6134(obj, v - 1);
    return 1;
}
