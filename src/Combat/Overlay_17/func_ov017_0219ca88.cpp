#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "Combat/Main/CopyRecord0200fbb4.h"

struct Vec3 { int x, y, z; };
struct ListHead02046b38;
struct ListNode02046b38;
struct HeadNode02046b24;
struct TailList020469b4;
struct TailNode020469b4;
struct TransitionState0219ca88 { unsigned char padding0[2]; unsigned char active; unsigned char padding3[7]; unsigned char fieldA; };
struct Entry0219ca88 {
    int kind;
    Vec3 position;
    unsigned char padding10[0x42];
    short radius;
    int field54;
    Vec3 target;
    unsigned char padding64[12];
};
struct Container0219ca88 { unsigned short id; unsigned char padding2[0x6a]; unsigned char entries[0x1c]; int count; };
struct ActorView0219ca88 { unsigned char padding0[0x18c]; unsigned int flags; };
struct TriggerState0219ca88 { unsigned char padding0[3]; unsigned char active; };
struct Event0219ca88 { unsigned char kind; unsigned char padding1[7]; Entry0219ca88* entry; unsigned char paddingC[4]; unsigned short angle; unsigned char padding12[2]; };
struct Header0219ca88 { unsigned int field0, field4, field8, id; unsigned char padding10[0x24]; };

extern "C" Container0219ca88* func_02012fe4();
void* GetField0x3f8Address(GameState*);
void* GetField0x3b0Value(GameState*);
extern "C" void* func_0205ec34(void*);
int ListContainsNode(ListHead02046b38*, ListNode02046b38*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
unsigned int GetBitsInField8(unsigned int*, unsigned int);
void ClearBitsInField8(unsigned int*, unsigned int);
void SetBitsInField8(unsigned int*, unsigned int);
int IsField0Null(void**);
void SetObjFieldIfFound_0219bed0(void*);
unsigned char GetByte0x4(char*);
int GetWord0x7f6c(void*);
int GetField0x3acValue(GameState*);
void* GetElementStride0x70(unsigned char*, int);
extern "C" int func_020321e0(Vec3*, Vec3*, short, Vec3*, int);
extern "C" void* func_ov017_0219c6f4(void*);
unsigned char GetByteField0x252(void*);
void InitObj0219a674(unsigned char*);
int GetAbsAngleDeltaBetween_021a4754(Vec3*, int, Vec3*);
extern "C" void func_ov017_0219b33c(GameResources*, Event0219ca88*);
void InitAndResetHeader_0219e310(unsigned char*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(void*);

// USA: func_ov017_0219ca88
extern "C" ARM void func_ov017_0219ca88(GameResources* resources) {
    GameState* game = GameState::GetInstance();
    GameObject* actor = game->GetUnknownGameObject();
    Container0219ca88* container = func_02012fe4();
    TransitionState0219ca88* state = (TransitionState0219ca88*)GetField0x3f8Address(game);
    BackgroundLoader::GetInstance();
    Vec3* actorPosition;
    int handled = 0;
    void* lookup = func_0205ec34(GetField0x3b0Value(game));
    if (ListContainsNode((ListHead02046b38*)resources->unknown_ptr_array_36fc[0], (ListNode02046b38*)resources->unknown_ptr_array_36fc[4])) return;
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) == 4) return;
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) == 10) return;
    if (GetBitsInField8((unsigned int*)resources, 8)) {
        if (((TriggerState0219ca88*)resources->unknown_ptr_array_36fc[5])->active) return;
        if (IsMainBrightnessTransitionActive(resources)) return;
        ClearBitsInField8((unsigned int*)resources, 8);
    }
    if (ListContainsNode((ListHead02046b38*)resources->unknown_ptr_array_36fc[0], (ListNode02046b38*)resources->unknown_ptr_array_371c[0])) return;
    if (IsField0Null((void**)resources->unknown_ptr_array_36fc[0]) && !IsBrightnessTransitionActive(resources) && ((unsigned char*)resources->unknown_42e3)[6]) {
        if (state->active) state->fieldA = 0;
        else SetObjFieldIfFound_0219bed0((void*)1);
        resources->unknown_42e3[6] = 0;
    }
    int eligible = 1;
    if (GetByte0x4((char*)game) != 6 && GetWord0x7f6c(game) != 5) {
        if (((ActorView0219ca88*)actor)->flags & 1) eligible = 0;
        else if (state->active) eligible = 0;
        if (eligible) {
            actorPosition = (Vec3*)&actor->obj3D_.position_;
            Vec3 position = *actorPosition;
            for (int entryIndex = 0; entryIndex < container->count; ++entryIndex) {
                GetField0x3acValue(game);
                Entry0219ca88* entry = (Entry0219ca88*)GetElementStride0x70(container->entries, entryIndex);
                if (func_020321e0(&position, &entry->position, entry->radius, &entry->target, entry->field54)) {
                    func_ov017_0219c6f4(entry);
                    handled = 1;
                }
                if (handled && entry->kind == 1) {
                    handled = 0;
                    if (!GetByteField0x252(actor)) continue;
                    Event0219ca88 event;
                    InitObj0219a674((unsigned char*)&event);
                    event.kind = 8;
                    event.entry = entry;
                    event.angle = GetAbsAngleDeltaBetween_021a4754(actorPosition, (short)actor->obj3D_.rotation_.y, &entry->target);
                    func_ov017_0219b33c(resources, &event);
                }
                if (handled) {
                    if (!((TriggerState0219ca88*)resources->unknown_ptr_array_36fc[5])->active) break;
                    SetBitsInField8((unsigned int*)resources, 8);
                    return;
                }
            }
        }
    }
    if (state->active) {
        state->active = 0;
        handled = 1;
    }
    if (!handled) return;
    _Z28CallFunc0200fbb4AtField0x3f8Pv(game, state);
    InitAndResetHeader_0219e310((unsigned char*)resources->unknown_ptr_array_36fc[4], 0);
    AppendNodeToTail((TailList020469b4*)resources->unknown_ptr_array_36fc[0], (TailNode020469b4*)resources->unknown_ptr_array_36fc[4]);
    if (!state->fieldA) {
        Header0219ca88 header;
        header.id = container->id;
        if (LookupAndForEachNode020649b0(lookup, 6, &header)) func_0206f81c(&header);
    }
}
