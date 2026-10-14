#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/Vector.h"

struct Vec3;
struct HeadNode02046b24;
struct Outer02077a20;
struct ArrayContainsByteStruct;
struct TailList020469b4;
struct TailNode020469b4;

struct Entry02196430 {
    unsigned short tag;
    unsigned short group : 2;
};

struct Ctx02196430 {
    char pad0[0x36f8];
    Entry02196430* entry;
    void* list;
    char pad3700[0x3718 - 0x3700];
    void* node;
    char pad371c[0x42e2 - 0x371c];
    unsigned char busy;
    char pad42e3[0x42e6 - 0x42e3];
    unsigned char forceEvent;
    unsigned char locked;
    unsigned char allowRepeat;
    char pad42e9[0x44ae - 0x42e9];
    unsigned short pendingId;
    unsigned short pendingArg;
};

struct Actor02196430 {
    Object3D obj3D;
    char padac[0xbe - 0xac];
    unsigned char kind;
    char padbf[0xc3 - 0xbf];
    unsigned char fieldc3;
    char padc4[0x130 - 0xc4];
    int mode;
    char pad134[0x166 - 0x134];
    unsigned short field166;
    char pad168[0x16a - 0x168];
    unsigned short eventId;
    char pad16c[0x17d - 0x16c];
    unsigned char flags17d;
    char pad17e[0x18c - 0x17e];
    unsigned int flags18c;

    int GetFieldC3() const { return fieldc3; }
    unsigned char HasPartyFlag() const { return flags17d & 8; }
};

struct Zone02196430 {
    char pad0[2];
    unsigned char busy;
};

struct Work02196430 {
    unsigned short mapId;
};

struct Msg02196430 {
    unsigned char kind;
    unsigned char field1;
    short field2;
    unsigned char field4;
    char pad5[3];
    int field8;
    int fieldc;
    short angle;
    short field12;
};

struct Event02196430 {
    unsigned char kind;
    unsigned char field_0x1;
    unsigned short tag;
    unsigned short id;
    unsigned char pad6[2];
    int field_0x8;
    unsigned char field_0xc;
    unsigned char field_0xd;
    unsigned char field_0xe;
    unsigned char field_0xf;
    unsigned short color;
    unsigned char timeOfDay;
    unsigned char pad13;
    int field_0x14;
};

struct EventEntry02196430 {
    char pad0[4];
    signed char field4;
};

struct Kinds02196430 {
    unsigned char v[3];
};

extern "C" void* func_0202ae18(void);
extern "C" Work02196430* func_02012fe4(void);
void* GetField0x3f8Address_0200fd0c(GameState* state);
int IsField0Null_02046b08(void** obj);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24** obj);
int IsField0x1b4Or0x1b8Positive_02053cdc(int* obj);
int GetByte0x26c_02039d7c(char* obj);
unsigned int GetBitsInField4_0203b4fc(unsigned int* obj, unsigned int mask);
int GetIntField0x264_02039760(void* obj);
int GetField0x8OrDefault02077a20(Outer02077a20* p);
void InitObj0219a674(unsigned char* self);
short GetAbsAngleDeltaBetween_021a4754(Vec3* p0, int baseAngle, Vec3* p2);
extern "C" void func_ov017_0219b33c(Ctx02196430* self, Msg02196430* msg);
int HasMatchingHalfword_0219735c(unsigned char* obj, unsigned short key);
int GetField0x17dBits4To5IfFlag8_020795cc(unsigned char* obj);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* arr, int value);
int CheckProximity_02196fc8(unsigned char* self, unsigned char* other, int extra);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* flags, int mode);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
int GetField0x3acValue_020100a8(GameState* state);
void TrySetMode02076ccc(void* obj, int mode);
extern "C" unsigned short func_ov017_021971c4(Ctx02196430* self);
extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);
struct Entry0207d9bc;
Entry0207d9bc* GetData02108ea8_0207d78c();
EventEntry02196430* FindEntryByHalfword(Entry0207d9bc* table, unsigned short id);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char* obj);
extern "C" void func_ov017_021b6e70(Event02196430* evt, int index);
extern "C" int func_ov017_021970a0(int mode);
extern "C" void func_ov017_021b7104(void* node, Event02196430* evt);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

extern unsigned short data_02114e30;
extern Kinds02196430 data_ov017_021d6438;

// USA: func_ov017_02196430
extern "C" ARM int func_ov017_02196430(Ctx02196430* self) {
    GameState* game = GameState::GetInstance();
    void* session = func_0202ae18();
    Entry02196430* entry = self->entry;
    Actor02196430* player = (Actor02196430*)game->GetUnknownGameObject();
    Ctx02196430* res = (Ctx02196430*)func_ov017_0218b5b0();
    Work02196430* work = func_02012fe4();
    LightingManager* lighting = LightingManager::GetInstance();
    ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GetPtrField0x2a04_02010828(game);
    unsigned short tag;
    int special;
    int facing;
    int index;
    int i;
    int allowRepeat = res->allowRepeat;
    Msg02196430 approachMsg;
    Msg02196430 contactMsg;
    Msg02196430 nearbyMsg;
    Event02196430 evt;
    Vector3fix pos;
    Vector3fix offset;
    Vector3fix dir;
    Kinds02196430 kinds;

    if (self->busy != 0) {
        return 2;
    }
    if (IsField0Null_02046b08((void**)self->list) == 0) {
        return GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->list) == 0x45 ? 0 : 2;
    }
    if (entry == NULL) {
        return 2;
    }
    if (IsField0x1b4Or0x1b8Positive_02053cdc((int*)player)) {
        return 2;
    }
    if (player->flags18c & 1) {
        return 2;
    }
    if (GetByte0x26c_02039d7c((char*)player) != 0) {
        return 2;
    }
    if (GetBitsInField4_0203b4fc((unsigned int*)self, 0x10)) {
        return 2;
    }
    if (res->locked != 0) {
        return 2;
    }
    if (((Zone02196430*)GetField0x3f8Address_0200fd0c(game))->busy != 0) {
        return 2;
    }
    if (GetIntField0x264_02039760(player) != 0 && allowRepeat == 0) {
        return 0;
    }

    int doEvent = 0;
    special = 0;
    int skip = 0;
    int direct = 0;
    facing = 0;
    tag = entry->tag;
    if (player->GetFieldC3() > 0 && allowRepeat == 0) {
        skip = 1;
    }
    unsigned short id = 0;
    index = -1;
    if (skip == 0) {
        for (i = 0; i < 12; i++) {
            direct = 0;
            index = i + (entry->group * 12 + 0x70);
            Actor02196430* other = (Actor02196430*)game->GetMaybeFieldMonsterByIndex(index);
            if (other == NULL) {
                continue;
            }
            if (other->kind != 2 && ((other->flags17d & 2) || (other->flags17d & 4))) {
                int touching;
                int playerHeight = player->obj3D.GetHeight();
                int otherHeight = other->obj3D.GetHeight();
                if (player->obj3D.position_.y + playerHeight < other->obj3D.position_.y ||
                    other->obj3D.position_.y + otherHeight < player->obj3D.position_.y) {
                    touching = 0;
                } else {
                    int reach = (player->obj3D.GetRadius() >> 1) + (GetField0x8OrDefault02077a20((Outer02077a20*)other) >> 1);
                    int dist = Vector3fix_Distance(&player->obj3D.position_, &other->obj3D.position_);
                    Vector3fix_Subtract(&player->obj3D.position_, &other->obj3D.position_, &dir);
                    Vector3fix_Normalize(&dir, &dir);
                    if (dist < reach) {
                        Vector3fixMultiplyScalar(&dir, reach, &offset);
                        Vector3fix_Add(&other->obj3D.position_, &offset, &pos);
                        player->obj3D.position_.x = pos.x;
                        player->obj3D.position_.y = pos.y;
                        player->obj3D.position_.z = pos.z;
                    }
                    touching = dist < reach + 0x1000;
                }
                if (touching && func_0202c508(session)) {
                    InitObj0219a674((unsigned char*)&approachMsg);
                    approachMsg.kind = 9;
                    approachMsg.field2 = other->obj3D.unknown_4_;
                    approachMsg.angle = GetAbsAngleDeltaBetween_021a4754((Vec3*)&player->obj3D.position_, (short)player->obj3D.rotation_.y, (Vec3*)&other->obj3D.position_);
                    if (approachMsg.angle < 0x1922) {
                        func_ov017_0219b33c(self, &approachMsg);
                    }
                }
                continue;
            }
            if (other->kind != 2) {
                if (other->flags17d & 1) {
                    continue;
                }
                if (HasMatchingHalfword_0219735c((unsigned char*)self, other->eventId)) {
                    continue;
                }
                if (!(other->HasPartyFlag() &&
                      ArrayContainsByte_02086ef0(party, GetField0x17dBits4To5IfFlag8_020795cc((unsigned char*)other)))) {
                    if (allowRepeat != 0) {
                        continue;
                    }
                    if (!CheckProximity_02196fc8((unsigned char*)player, (unsigned char*)other, 0)) {
                        continue;
                    }
                }
            } else {
                if (!CheckProximity_02196fc8((unsigned char*)player, (unsigned char*)other, 0x1000)) {
                    continue;
                }
                if (!other->obj3D.IsVisible()) {
                    continue;
                }
                InitObj0219a674((unsigned char*)&contactMsg);
                contactMsg.kind = 0xe;
                func_ov017_0219b33c(self, &contactMsg);
                if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 1) == 0 && self->forceEvent == 0) {
                    continue;
                }
                if (CheckSubstructByte0x7cPositive_020535c8((signed char*)player)) {
                    continue;
                }
                direct = 1;
            }
            if (other->obj3D.GetInheritedAlpha() != 0x1f) {
                continue;
            }
            if (other->kind == 6) {
                continue;
            }
            if (!other->obj3D.IsVisible()) {
                continue;
            }
            if (tag != other->obj3D.GetField06()) {
                continue;
            }
            if (direct == 0 && (other->flags17d & 8)) {
                if (!ArrayContainsByte_02086ef0(party, GetField0x17dBits4To5IfFlag8_020795cc((unsigned char*)other))) {
                    continue;
                }
            }
            if (other->mode == 0 && !(other->flags17d & 8)) {
                continue;
            }
            if (other->mode != 8 && other->mode != 9 && other->mode != 0) {
                other->field166 = GetField0x3acValue_020100a8(game);
                TrySetMode02076ccc(other, 8);
            }
            id = other->eventId;
            doEvent = 1;
            if (9007.6f < (float)GetAbsAngleDeltaBetween_021a4754((Vec3*)&other->obj3D.position_, (short)other->obj3D.rotation_.y, (Vec3*)&player->obj3D.position_)) {
                facing = 1;
                break;
            }
            if (9007.6f < (float)GetAbsAngleDeltaBetween_021a4754((Vec3*)&player->obj3D.position_, (short)player->obj3D.rotation_.y, (Vec3*)&other->obj3D.position_)) {
                facing = 2;
            }
            break;
        }
    }

    unsigned short nearbyId = func_ov017_021971c4(self);
    if (nearbyId != 0) {
        InitObj0219a674((unsigned char*)&nearbyMsg);
        nearbyMsg.kind = 0xe;
        func_ov017_0219b33c(self, &nearbyMsg);
    }
    if (!CheckSubstructByte0x7cPositive_020535c8((signed char*)player) &&
        (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 1) != 0 || self->forceEvent != 0) && nearbyId != 0) {
        doEvent = 1;
        direct = 1;
        id = nearbyId;
        if ((unsigned int)(work->mapId - 0x170c) <= 3) {
            special = 1;
        }
    }
    if (doEvent) {
        if (id < 1 || id > 0x8004) {
            doEvent = 0;
        }
    }
    if (doEvent && direct && func_0202c508(session)) {
        EventEntry02196430* found = FindEntryByHalfword(GetData02108ea8_0207d78c(), id);
        if (found != NULL && found->field4 < 0) {
            doEvent = 0;
        }
    }
    if (func_0202c540(session) && IsField0Null_02046b08((void**)self->list) && self->pendingId != 0) {
        id = self->pendingId;
        self->pendingId = 0;
        self->pendingArg = 0;
        doEvent = 1;
        direct = 1;
        index = -1;
    }
    if (doEvent) {
        func_ov017_021b6f18(self->node);
        InitStruct_02196c08((unsigned char*)&evt);
        evt.kind = 1;
        if (special) {
            evt.field_0xe = 1;
        }
        evt.field_0x1 = GetField0x3acValue_020100a8(game);
        evt.id = id;
        evt.tag = index;
        func_ov017_021b6e70(&evt, index);
        if (direct) {
            evt.field_0xf = 0;
        } else {
            evt.field_0xf = func_ov017_021970a0(facing);
        }
        GameObject* target = game->GetMaybeFieldMonsterByIndex(index);
        if (target != NULL) {
            kinds = data_ov017_021d6438;
            unsigned char* kind = kinds.v;
            for (int k = 0; k < 3; k++, kind++) {
                if (*kind == target->obj3D_.unknown_2_) {
                    evt.field_0xf = 0;
                    break;
                }
            }
        }
        evt.field_0x14 = direct;
        evt.timeOfDay = lighting->timeOfDayIndex_;
        func_ov017_021b7104(self->node, &evt);
        AppendNodeToTail((TailList020469b4*)self->list, (TailNode020469b4*)self->node);
        return 1;
    }
    return 0;
}
