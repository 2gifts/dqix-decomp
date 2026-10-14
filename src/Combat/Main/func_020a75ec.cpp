#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"

#if defined(jpn)
#define func_020a78dc func_020a9660
#endif

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
struct InputWork020a75ec { char padding[0x38]; int x; int y; char padding_40[4]; unsigned int state; char padding_48[0xc]; unsigned char active; };
struct PartyActor020a75ec { Object3D object; unsigned short state; };
struct ListHead02046b60;
struct Bytes02033b88;
struct Vec3copy0202ec84;
extern short data_020e9450[];
extern InputWork020a75ec data_02114e54;
extern unsigned short data_02114e30[];
extern "C" Zone3D* func_02012fe4();
extern "C" void func_020332ac(WrappedActor020a75ec*);
extern "C" void func_020a78dc(WrappedActor020a75ec*);
int ListContainsId(ListHead02046b60*, int);
void* GetPtrField0x2a04_02010828(GameState*);
void* GetField0x3b0Value_020100bc(GameState*);
int ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
extern "C" void* func_0205ec34();
int TestFlag0SetAndFlag1Clear_02012444(unsigned short*, int);
int IsField0Null_02046b08(void**);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
int SetByte0xbeShiftPrev(Bytes02033b88*, int);
extern "C" void func_ov017_021a93f0(GameResources*, int, int);

#if defined(jpn)
enum { kSavedPosition = 0x27b4, kSavedAngle = 0x27c0 };
#else
enum { kSavedPosition = 0x2774, kSavedAngle = 0x2780 };
#endif

// USA: func_020a75ec
extern "C" ARM void func_020a75ec(WrappedActor020a75ec* actor) {
    GameState* state = GameState::GetInstance();
    Zone3D* zone = func_02012fe4();
    short field = actor->field_b4;
    func_020332ac(actor);
    actor->field_b4 = field;
    func_020a78dc(actor);
    actor->phase += state->GetTickCount() * 364;
    actor->oscillation = data_020e9450[((actor->phase >> 4) * 2 + 1)] >> 4;
    if (zone->currentZoneID_ != 10000) return;
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
        unsigned char* party = (unsigned char*)GetPtrField0x2a04_02010828(state);
        for (int i = 0; i < party[0xf7c]; i++) {
            PartyActor020a75ec* member = (PartyActor020a75ec*)state->GetPartyMemberByIndex(*(party + 0xf78 + i));
            if (member) {
                member->object.position_ = actor->object.position_;
                member->state = 0;
            }
        }
        *(Vector3i*)((char*)zone + kSavedPosition) = actor->object.position_;
        *(int*)((char*)zone + kSavedAngle) = actor->angle;
    }
    int screenX;
    int screenY;
    void* view = GetField0x3b0Value_020100bc(state);
    int hit = 0;
    if (ComputeTwoFromVec3_0202ec84(view, (Vec3copy0202ec84*)&actor->object.position_, &screenX, &screenY) == 0) {
        int inputX;
        int inputY;
        if (data_02114e54.active && data_02114e54.state < 10) {
            inputX = data_02114e54.x;
            inputY = data_02114e54.y;
        }
        if (screenX - 16 < inputX && inputX < screenX + 16 && screenY - 20 < inputY && inputY < screenY + 8) hit = 1;
    }
#if !defined(jpn)
    unsigned char* flags = (unsigned char*)func_0205ec34();
#endif
    if (TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 2) || hit) {
        if (IsField0Null_02046b08((void**)head)
#if !defined(jpn)
            && TestBitInByteArray_0206dfb0((int)flags, flags + 0x8c, 43)
#endif
        ) {
            actor->field_15a = 0;
            actor->active = 0;
            SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
            func_ov017_021a93f0(scene, 0, 1);
        }
    }
}
