#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" void func_ov000_0216d370(void* obj, int a, int b, int c);
void SetFields0x10To0x18(unsigned char* obj, int x, int y, int z);
void ApplyVec3Tail(void* obj, int* vec);
extern "C" void _Z22SetFlagOrState0216d530Pvi(void* obj, int val);

extern int data_ov000_021832a4[8];

// USA: func_ov000_0216d90c
extern "C" ARM void func_ov000_0216d90c(unsigned char* obj, int index) {
    GameState* state = GameState::GetInstance();
    GameObject* self = state->GetGameObjectByIndex(index);
    if (self == NULL) {
        return;
    }
    GameObject* other = state->GetGameObjectByIndex(obj[0x263]);
    if (other == NULL) {
        return;
    }
    fix32_t selfHeight = self->obj3D_.GetHeight();
    fix32_t otherHeight = other->obj3D_.GetHeight();
    int tall;
    if (otherHeight < selfHeight && 2.0f <= selfHeight) {
        tall = 1;
    } else {
        tall = 0;
    }
    func_ov000_0216d370(obj, 1, 1, 1);
    SetFields0x10To0x18(obj, 0, 0x1000, 0x1000);
    int r = NextRandomMax(*(struct Random**)(obj + 0x21c), 8);
    if (tall) {
        if (r == 2) {
            r = 7;
        } else if (r == 3) {
            r = 6;
        } else if (r == 4) {
            r = 1;
        } else if (r == 5) {
            r = 0;
        }
    }
    int vec[3];
    vec[0] = data_ov000_021832a4[r];
    vec[1] = 0x3000;
    vec[2] = 0x8000;
    ApplyVec3Tail(obj, vec);
    _Z22SetFlagOrState0216d530Pvi(obj, index);
    *(int*)(obj + 0x23c) = -20;
}
