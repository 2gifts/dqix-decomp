#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct BitField020340d4;
struct Flags020340c4;
struct Flags020340b4;
struct BitField0203402c;

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* search);
extern "C" void func_ov017_021d360c(int kind, int index, int id, Vector3s vec);

struct Spot_021c2380 {
    unsigned short id;
    Vector3s pos;
};

Spot_021c2380* GetField0x74deForValidIndex(char* base, unsigned int index);
int GetField0x3acValue(GameState* battleStruct);
int GetFlag0x80At0xc2(BitField020340d4* obj);
void ClearFlag0x80At0xc2(Flags020340c4* obj);
void SetFlag0x80At0xc2(Flags020340b4* obj);
int CheckField0xc4Low15BitsNonZero(BitField0203402c* obj);
void SetField0xc4Low15Bits(unsigned char* obj, int value);
unsigned char GetByte0x26c(char* obj);
void SetByteField0x253(void* obj);

// USA: func_ov017_021c2380
extern "C" ARM int func_ov017_021c2380(int spotIdx, int monIdx) {
    GameState* gs = GameState::GetInstance();
    void* search = func_0202ae18();
    Spot_021c2380* spot = GetField0x74deForValidIndex((char*)gs, spotIdx);
    if (spot == NULL) {
        return 0;
    }
    if (spot->id == 0) {
        return 0;
    }

    GameObject* mon = gs->GetMaybeWanderingMonsterByIndex(monIdx);
    GameObject* member = gs->GetPartyMemberByIndex(monIdx);
    if (mon == NULL) {
        return 0;
    }

    int wasFlagged = 0;
    if (spotIdx == GetField0x3acValue(gs) && GetFlag0x80At0xc2((BitField020340d4*)mon)) {
        wasFlagged = GetFlag0x80At0xc2((BitField020340d4*)mon);
        ClearFlag0x80At0xc2((Flags020340c4*)mon);
    }
    if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)mon)) {
        return 0;
    }
    if (member != NULL && GetByte0x26c((char*)member)) {
        return 0;
    }
    if (spot->id != mon->obj3D_.GetField06()) {
        return 0;
    }

    Vector3fix target;
    target.x = spot->pos.x << 4;
    target.y = spot->pos.y << 4;
    target.z = spot->pos.z << 4;
    Vector3fix pos = mon->obj3D_.position_;
    if (fix32abs(target.x - pos.x) > 0x800) {
        return 0;
    }
    if (fix32abs(target.y - pos.y) > 0x800) {
        return 0;
    }
    if (fix32abs(target.z - pos.z) > 0x800) {
        return 0;
    }
    if (Vector3fix_Distance(&target, &pos) > 0x800) {
        return 0;
    }
    if (wasFlagged) {
        SetFlag0x80At0xc2((Flags020340b4*)mon);
        return 0;
    }

    if (func_0202c508(search)) {
        SetField0xc4Low15Bits((unsigned char*)mon, 5000);
        if (member != NULL) {
            SetByteField0x253(member);
        }
    }
    Vector3s zero = {0};
    func_ov017_021d360c(1, (unsigned char)spotIdx, (unsigned short)monIdx, zero);
    spot->id = 0;
    return 1;
}
