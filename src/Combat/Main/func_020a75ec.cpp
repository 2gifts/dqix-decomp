#include <globaldefs.h>
#include "GameState/GameState.h"

struct WrappedActor020a75ec {
    Object3D object;
    short field_ac;
    short angle;
    char padding_b0[4];
    short field_b4;
    char padding_b6[0x7a];
    unsigned int wrapFlags;
    char padding_134[8];
    unsigned short phase;
    short field_13e;
    int oscillation;
    Vector3i previousPosition;
    unsigned char reset;
    char padding_151[3];
    unsigned char active;
    char padding_155[5];
    unsigned char field_15a;
};
struct PartyIndices020a75ec { char padding[0xf78]; unsigned char indices[4]; unsigned char count; };
struct AreaWork020a75ec { unsigned short area; char padding_2[0x2772]; Vector3i position; int angle; };
struct InputWork020a75ec { char padding[0x38]; int x; int y; char padding_40[4]; unsigned int state; char padding_48[0xc]; unsigned char active; };
struct SaveFlags020a75ec { char padding[0x8c]; unsigned char flags[1]; };
struct PartyActor020a75ec { Object3D object; unsigned short state; };
struct ListHead02046b60;
struct Bytes02033b88;
struct Vec3copy0202ec84;
extern short data_020e9450[];
extern InputWork020a75ec data_02114e54;
extern unsigned short data_02114e30[];
extern "C" AreaWork020a75ec* func_02012fe4();
extern "C" void func_020332ac(WrappedActor020a75ec*);
extern "C" void func_020a78dc(WrappedActor020a75ec*);
int ListContainsId(ListHead02046b60*, int);
void* GetPtrField0x2a04(GameState*);
void* GetField0x3b0Value(GameState*);
extern "C" int _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void*, Vec3copy0202ec84*, int*, int*);
extern "C" SaveFlags020a75ec* func_0205ec34();
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
int IsField0Null(void**);
int TestBitInByteArray(int, unsigned char*, int);
int SetByte0xbeShiftPrev(Bytes02033b88*, int);
extern "C" void func_ov017_021a93f0(GameResources*, int, int);

// USA: func_020a75ec
extern "C" ARM void func_020a75ec(WrappedActor020a75ec* actor) {
    GameState* state = GameState::GetInstance();
    AreaWork020a75ec* area = func_02012fe4();
    short field = actor->field_b4;
    func_020332ac(actor);
    actor->field_b4 = field;
    func_020a78dc(actor);
    actor->phase += state->GetTickCount() * 364;
    actor->oscillation = data_020e9450[((actor->phase >> 4) * 2 + 1)] >> 4;
    if (area->area != 10000) return;
    Vector3i position;
    int changed = 0;
    position = actor->object.position_;
    actor->wrapFlags = 0;
    if (position.x >= 0x90000) {
        position.x -= 0x120000;
        actor->wrapFlags |= 1;
        changed = 1;
    } else if (position.x < -0x90000) {
        position.x += 0x120000;
        actor->wrapFlags |= 2;
        changed = 1;
    }
    if (position.z >= 0x70000) {
        position.z -= 0xe0000;
        actor->wrapFlags |= 4;
        changed = 1;
    } else if (position.z < -0x70000) {
        position.z += 0xe0000;
        actor->wrapFlags |= 8;
        changed = 1;
    }
    if (changed) {
        actor->object.position_ = position;
        actor->previousPosition = position;
    }
    GameResources* scene = func_ov017_0218b5b0();
    void* head = scene->unknown_ptr_array_36fc[0];
    if (!ListContainsId((ListHead02046b60*)head, 3) && !ListContainsId((ListHead02046b60*)head, 1)) {
        PartyIndices020a75ec* party = (PartyIndices020a75ec*)GetPtrField0x2a04(state);
        for (int i = 0; i < party->count; i++) {
            PartyActor020a75ec* member = (PartyActor020a75ec*)state->GetPartyMemberByIndex(party->indices[i]);
            if (member) {
                member->object.position_ = actor->object.position_;
                member->state = 0;
            }
        }
        area->position = actor->object.position_;
        area->angle = actor->angle;
    }
    int screenX;
    int screenY;
    void* view = GetField0x3b0Value(state);
    int hit = 0;
    if (_Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(view, (Vec3copy0202ec84*)&actor->object.position_, &screenX, &screenY) == 0) {
        int inputX;
        int inputY;
        if (data_02114e54.active && data_02114e54.state < 10) {
            inputX = data_02114e54.x;
            inputY = data_02114e54.y;
        }
        if (screenX - 16 < inputX && inputX < screenX + 16 && screenY - 20 < inputY && inputY < screenY + 8) hit = 1;
    }
    SaveFlags020a75ec* flags = func_0205ec34();
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 2) || hit) {
        if (IsField0Null((void**)head) && TestBitInByteArray((int)flags, flags->flags, 43)) {
            actor->field_15a = 0;
            actor->active = 0;
            SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
            func_ov017_021a93f0(scene, 0, 1);
        }
    }
}
