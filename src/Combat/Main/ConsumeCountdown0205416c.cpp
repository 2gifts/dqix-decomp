#include <globaldefs.h>

#if defined(jpn)
#define ConsumeCountdown0205416c func_020554e4
#endif
#if defined(jpn)
enum { CountdownOffset = 0x1b4 };
#else
enum { CountdownOffset = 0x1c0 };
#endif

#include "GameState/GameState.h"

extern "C" void func_02054028(void* obj, int n);

#if defined(jpn)
extern "C" void func_020554e4(void* obj);
#endif

// USA: func_0205416c
ARM void ConsumeCountdown0205416c(void* obj) {
    unsigned int n = (unsigned int)((GameState*)(GameState::GetInstance()))->GetEffectiveDeltaTime();
    unsigned short v = *(unsigned short*)((char*)obj + CountdownOffset);
    if (v >= n) {
        *(unsigned short*)((char*)obj + CountdownOffset) = v - n;
        return;
    }
    func_02054028(obj, 0);
}
