#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Graphics/LightingManager.h"
#include "Util/Random.h"

extern "C" void* func_0202ae18(void);
extern "C" unsigned char* func_02012fe4(void);
struct PointerField32c_ffc0;
void* GetPointerAt0x32c(struct PointerField32c_ffc0* obj);
extern "C" unsigned char* func_0205ec34(void);
int IsField0Null(void** obj);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
int IsField0x1b4Or0x1b8Positive(int* obj);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
int GetIntField0x264(void* obj);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
int NextRandomBetween(struct Random* rng, int lo, int hi);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void _Z19InitStruct_02196c08Ph(unsigned char* obj);
int GetField0x3acValue(GameState* battleStruct);
extern "C" unsigned short func_ov017_021a1a20(void);
void* GetPtrField0x114(void* obj);
struct ColorHolder;
unsigned short ConvertColorToDecimal(struct ColorHolder* obj);
extern "C" int func_ov017_021970a0(int mode);
extern "C" void func_ov017_021b6e70(void* evt, unsigned short tag);
extern "C" void func_ov017_021b7104(void* node, void* src);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Ctx02196c4c {
    unsigned char pad0[0x36f8];
    unsigned short* entry;
    void* list;
    unsigned char pad3700[0x3718 - 0x3700];
    void* node;
};

struct Actor02196c4c {
    unsigned char pad0[3];
    unsigned char active;
};

struct Event02196c4c {
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

// USA: func_ov017_02196c4c
extern "C" ARM int func_ov017_02196c4c(Ctx02196c4c* self) {
    GameState* battle = GameState::GetInstance();
    func_0202ae18();
    unsigned char* work = func_02012fe4();
    unsigned short* entry = self->entry;
    GameObject* combatant = battle->GetUnknownGameObject();
    void* field32c = GetPointerAt0x32c((struct PointerField32c_ffc0*)battle);
    LightingManager* lighting;
    Actor02196c4c* actor = (Actor02196c4c*)func_ov017_0218b5b0()->unknown_ptr_array_371c[6];
    unsigned char* flags = func_0205ec34();
    lighting = LightingManager::GetInstance();

    if (IsField0Null((void**)self->list) == 0) {
        return GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)self->list) == 0x45 ? 0 : 2;
    }
    if (entry == NULL) {
        return 2;
    }
    if (IsField0x1b4Or0x1b8Positive((int*)combatant)) {
        return 2;
    }
    if (*(unsigned int*)((unsigned char*)combatant + 0x18c) & 1) {
        return 2;
    }
    if (GetBitsInField4((unsigned int*)self, 0x10)) {
        return 2;
    }
    if (actor->active != 0) {
        return 2;
    }
    if (GetIntField0x264(combatant) != 0) {
        return 0;
    }
    if (*entry != 10000) {
        return 0;
    }
    if (!TestBitInByteArray((int)flags, flags + 0x8c, 0x2b)) {
        return 0;
    }

    int expired = 0;
    if (*(int*)(work + 0x2794) <= 0) {
        expired = 1;
        *(int*)(work + 0x2794) = NextRandomBetween(GetBTRandom(), 0x1e, 0x64);
    }
    if (expired == 0) {
        return 0;
    }

    func_ov017_021b6f18(self->node);
    Event02196c4c evt;
    _Z19InitStruct_02196c08Ph((unsigned char*)&evt);
    evt.kind = 1;
    evt.field_0x1 = GetField0x3acValue(battle);
    evt.id = func_ov017_021a1a20();
    evt.tag = 0xffff;
    evt.field_0xe = 1;
    evt.color = ConvertColorToDecimal((struct ColorHolder*)GetPtrField0x114(field32c));
    evt.field_0xf = func_ov017_021970a0(0);
    func_ov017_021b6e70(&evt, evt.tag);
    evt.timeOfDay = lighting->timeOfDayIndex_;
    func_ov017_021b7104(self->node, &evt);
    AppendNodeToTail((struct TailList020469b4*)self->list, (struct TailNode020469b4*)self->node);
    return 1;
}
