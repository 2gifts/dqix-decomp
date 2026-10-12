#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct Obj02039d84;
struct Obj02033874;
struct FormationState021bd704 {
    unsigned char padding_0[5];
    unsigned char enabled;
    unsigned char padding_6[4];
    unsigned short id;
    unsigned char padding_c[0x44 - 0xc];
    unsigned short flags;
    unsigned short padding_46;
    Vector3fix position;
    short angle;
};
struct PartyList021bd704 {
    unsigned char padding_0[0xf78];
    unsigned char members[4];
    unsigned char count;
};
extern "C" void* func_0202ae18();
unsigned char GetField0x397cValue(GameState*);
extern "C" int func_0202c508(void*);
void SetFlag0x1ceBit0x4(unsigned char*);
int fix32sin(int);
int fix32cos(int);
unsigned char GetByte0x26c(char*);
extern "C" void _Z24ResetObjectState02039d84P11Obj02039d84(Obj02039d84*);
extern "C" void _Z31EnqueueEventTag60Field_021d440ci(int);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874*, int);
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(unsigned char*);
extern "C" void func_ov017_021c3e18(int);

// USA: func_ov017_021bd704
extern "C" ARM void func_ov017_021bd704(FormationState021bd704* self) {
    GameState* game = GameState::GetInstance();
    void* search = func_0202ae18();
    int anchor = (self->flags & 0x40) != 0;
    int suppress = (self->flags & 0x1000) != 0 && self->enabled != 0;
    if (self->enabled == 0 && !anchor && !suppress) return;
    Vector3fix position = self->position;
    int angle = self->angle;
    if (self->enabled == 0 && anchor) {
        position = game->GetUnknownGameObject()->obj3D_.position_;
        angle = game->GetUnknownGameObject()->obj3D_.rotation_.y;
    }
    PartyList021bd704* party = (PartyList021bd704*)GetPtrField0x2a04(game);
    if (party != 0) {
        for (int i = 0; i < party->count; i++) {
            int id = party->members[i];
            GameObject* member = game->GetPartyMemberByIndex(id);
            if (member == 0) continue;
            if (func_0202c508(search)) {
                int member_id = member->obj3D_.unknown_4_;
                if (member_id != GetField0x397cValue(game) && anchor) {
                    member->obj3D_.SetInheritedAlpha(0);
                    SetFlag0x1ceBit0x4((unsigned char*)member);
                }
            } else if (self->enabled && !suppress) {
                if (id == 1) {
                    int x = FIX32_MULTIPLY(fix32sin(angle), 0x800);
                    int z = FIX32_MULTIPLY(fix32cos(angle), -0x1333);
                    position.z += z - x;
                    x = FIX32_MULTIPLY(fix32cos(angle), 0x800);
                    z = FIX32_MULTIPLY(fix32sin(angle), -0x1333);
                    position.x += z + x;
                } else if (id == 2) {
                    int x = FIX32_MULTIPLY(fix32sin(angle), -0x800);
                    int z = FIX32_MULTIPLY(fix32cos(angle), -0x1800);
                    position.z += z - x;
                    x = FIX32_MULTIPLY(fix32cos(angle), -0x800);
                    z = FIX32_MULTIPLY(fix32sin(angle), -0x1800);
                    position.x += z + x;
                } else if (id == 3) {
                    int z = FIX32_MULTIPLY(fix32cos(angle), -0x1ccc);
                    position.z += z;
                    int x = FIX32_MULTIPLY(fix32sin(angle), -0x1ccc);
                    position.x += x;
                }
            }
            if (self->id != 8100 && GetByte0x26c((char*)member)) {
                _Z24ResetObjectState02039d84P11Obj02039d84((Obj02039d84*)member);
                _Z31EnqueueEventTag60Field_021d440ci(-1);
            }
            member->obj3D_.position_ = position;
            _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)member, angle);
            member->obj3D_.EnableFlag(0x4000000);
            _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)member);
        }
    }
    if (func_0202c508(search)) func_ov017_021c3e18(0);
}
