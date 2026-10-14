#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" int func_ov017_021d60f4(void* a);
void SetFogState_020c54a4(int enable, unsigned int fogMode, unsigned int fogShift, unsigned short fogOffset);
typedef void (*SetFogStateWideFn_02161e8c)(int, unsigned int, unsigned int, unsigned int);

struct Inner02161e8c { unsigned int v[14]; };
struct Wrap02161e8c { struct Inner02161e8c mid; };

struct FlagHolder02161e8c { char pad[0x85]; unsigned char flag; };

// USA: func_ov001_02161e8c  (semantic: SetOrClearFogAndCopyBlob_02161e8c)
extern "C" ARM int func_ov001_02161e8c(void* param0) {
    FlagHolder02161e8c* holder = (FlagHolder02161e8c*)LightingManager::GetInstance();
    if (func_ov017_021d60f4(param0) == 0) {
        holder->flag = 0;
        SetFogState_020c54a4(0, 0, 0, 0);
    } else {
        Wrap02161e8c copy;
        Wrap02161e8c tmp;
        Wrap02161e8c* tmpPtr = &tmp;
        tmpPtr->mid = ((Wrap02161e8c*)((char*)LightingManager::GetInstance() + 0x4c))->mid;
        copy.mid = tmpPtr->mid;
        holder->flag = 1;
        ((SetFogStateWideFn_02161e8c)SetFogState_020c54a4)(1, copy.mid.v[1], copy.mid.v[2], copy.mid.v[3]);
    }
    return 1;
}
