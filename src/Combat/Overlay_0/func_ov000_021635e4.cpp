#include <globaldefs.h>
#include "GameState/GameState.h"

struct IntField0x68_020377bc;

// USA: func_ov000_021635e4
extern "C" ARM short func_ov000_021635e4(int id, int mode) {
    GameState* bs = GameState::GetInstance();
    if (bs == 0) {
        return 0x10a;
    }
    GameObject* c = bs->GetGameObjectByIndex(id);
    if (c == 0) {
        return 0x10a;
    }
    int result = 0x1000;
    int b = ((Object3D*)((struct IntField0x68_020377bc*)c))->GetHeight();
    int a = ((Object3D*)((unsigned char*)c))->GetRadius();
    switch (mode) {
        case 0:
            if (b > a) {
                b = a;
            }
            result = b;
            break;
        case 1:
            if (b < a) {
                b = a;
            }
            result = b;
            break;
        case 2:
            result = (b + a) >> 1;
            break;
        case 3:
            result = a;
            break;
        case 4:
            result = b;
            break;
    }
    return (short)result;
}
