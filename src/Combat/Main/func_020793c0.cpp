#include <globaldefs.h>
#include "GameState/GameState.h"
struct CandidateFlags020793c0 { unsigned int flags; };
struct CandidateView020793c0 {
    Object3D object;
    char unknownAc[0xc0-0xac];
    unsigned char kind;
    char unknownC1[2];
    unsigned char state;
    char unknownC4[0x130-0xc4];
    CandidateFlags020793c0* flags;
};
struct CandidateState020793c0 { char unknown0[0x56c]; unsigned char inactive; };
int GetSignedByte0x1c8(void*);
extern "C" int func_020342ac(GameObject*);
CandidateState020793c0* GetFieldAt0x150(unsigned char*);
extern "C" int _Z37HasHighBit14SetForField4Entry02034340Pv(void*);
struct Position020793c0 { int x, y, z; };
extern "C" Position020793c0 func_02034104(GameObject*);
extern "C" int Vector3fix_Distance(const Vector3fix*, const Vector3fix*);
// USA: func_020793c0
extern "C" ARM short func_020793c0(Object3D* reference, int maximumDistance) {
    GameState* state = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        GameObject* candidate = state->GetPartyMemberByIndex(i);
        if (!candidate) {
            if (i == 0) return -1;
            continue;
        }
        if (GetSignedByte0x1c8(candidate) != -1) continue;
        if (!func_020342ac(candidate)) continue;
        if (reference->GetField06() != candidate->obj3D_.GetField06()) continue;
        CandidateView020793c0* view = (CandidateView020793c0*)candidate;
        if (view->kind == 6) continue;
        if (candidate->obj3D_.GetField06() != reference->GetField06()) continue;
        if (GetFieldAt0x150((unsigned char*)candidate)->inactive != 0) continue;
        if (view->flags->flags & 1) continue;
        if ((int)view->state > 0) continue;
        if (_Z37HasHighBit14SetForField4Entry02034340Pv(candidate)) continue;
        Position020793c0 copy = func_02034104(candidate);
        if (Vector3fix_Distance((Vector3fix*)&copy, &reference->position_) < maximumDistance) return (short)i;
    }
    return -1;
}
