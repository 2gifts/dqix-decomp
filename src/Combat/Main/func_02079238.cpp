#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct CandidateFlags02079238 { unsigned int flags; };

struct CombatantView02079238 {
    Object3D object;
    char     unknownAc[0xae - 0xac];
    short    facingAngle;
    char     unknownB0[0xc0 - 0xb0];
    unsigned char kind;
    char     unknownC1[0xc3 - 0xc1];
    unsigned char state;
    char     unknownC4[0x130 - 0xc4];
    CandidateFlags02079238* flags;
};

struct CandidateState02079238 { char unknown0[0x56c]; unsigned char inactive; };

struct Position02079238 { int x, y, z; };

int GetSignedByte0x1c8(void*);
extern "C" int func_020342ac(GameObject*);
CandidateState02079238* GetFieldAt0x150(unsigned char*);
extern "C" int _Z37HasHighBit14SetForField4Entry02034340Pv(void*);
extern "C" Position02079238 func_02034104(GameObject*);
extern "C" void __clear(void* dst, int size);
int fix32sin(int x);
int fix32cos(int x);

// USA: func_02079238
extern "C" ARM short func_02079238(Object3D* reference, int maximumDistance) {
    GameState* state = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        GameObject* candidate = state->GetPartyMemberByIndex(i);
        if (!candidate) {
            if (i == 0) return -1;
            continue;
        }
        if (GetSignedByte0x1c8(candidate) != -1) continue;
        if (reference->GetField06() != candidate->obj3D_.GetField06()) continue;
        CombatantView02079238* view = (CombatantView02079238*)candidate;
        if (!func_020342ac(candidate)) continue;
        if (view->kind == 6) continue;
        if (candidate->obj3D_.GetField06() != reference->GetField06()) continue;
        if (GetFieldAt0x150((unsigned char*)candidate)->inactive != 0) continue;
        if (view->flags->flags & 1) continue;
        if ((int)view->state > 0) continue;
        if (_Z37HasHighBit14SetForField4Entry02034340Pv(candidate)) continue;
        Position02079238 copy = func_02034104(candidate);
        Position02079238 offset;
        Vector3fix_Subtract((const Vector3fix*)&copy,
                            (const Vector3fix*)((char*)reference + 0x44),
                            (Vector3fix*)&offset);
        int dist = Vector3fix_Length((const Vector3fix*)&offset);
        if (dist <= maximumDistance) {
            short facing = ((CombatantView02079238*)reference)->facingAngle;
            Position02079238 dir;
            __clear(&dir, 0xc);
            dir.x = fix32sin(facing);
            dir.z = fix32cos(facing);
            if (fix32_Divide(Vector3fix_InnerProduct((const Vector3fix*)&offset,
                                                     (const Vector3fix*)&dir), dist) > 0xb50)
                return (short)i;
        }
    }
    return -1;
}
