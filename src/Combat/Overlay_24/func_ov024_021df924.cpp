#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Util/Random.h"

struct Field150Holder02052df8;
struct S_a0720;
struct S_9fffc;
struct Field0x30;
struct S_a0038;

struct Stats021df924 {
    char pad0[0x3d];
    unsigned char rank;
};
struct Item021df924 {
    char pad0[0x10];
    unsigned short id;
};
struct Odds021df924 {
    char pad0[2];
    unsigned char rate[2];
    unsigned short message[2];
};
struct Level021df924 {
    char pad0[4];
    unsigned int level : 10;
    unsigned int rest : 22;
};
struct Fighter021df924 : GameObject {
    char pad13C[8];
    Item021df924* item;
    Odds021df924* odds;
    char pad14C[4];
    Level021df924* info;
};
struct Message021df924 {
    char pad0[4];
    short id;
};
struct BattleFlags021df924 {
    char pad0[0x1c];
    unsigned char field_1c : 7;
    unsigned char alternate : 1;
};
struct World021df924 {
    char pad0[0x8e4a];
    short pending;
};
struct Action021df924 {
    int field_0;
    Message021df924* message;
    int field_8;
    BattleFlags021df924* flags;
    World021df924* world;
};
struct PackedCodes021df924 {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int flags : 2;
};
struct ActionData021df924 {
    char pad0[0x20];
    PackedCodes021df924 success;
    PackedCodes021df924 failure;
};
struct Counts021df924 {
    unsigned int low : 10;
    unsigned int bit10 : 1;
    unsigned int first : 7;
    unsigned int second : 7;
    unsigned int rest : 7;
};
struct Loader021df924 {
    SafeAllocator alloc;
    char body[0x2c - sizeof(SafeAllocator)];
    void* source;
    char pad30[8];
};

extern float data_ov024_021fe860[];

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
int IsIdOrEffectMatchTarget0215fd24(int world, int id);
extern "C" unsigned short* func_02012fe4(void);
static inline int GetActionID() { return *func_02012fe4(); }
extern "C" int func_ov024_021df71c(Fighter021df924* self, unsigned short actionID, int alternate, unsigned short* resultID, unsigned short* combatantKey, unsigned short* entryID);
short GetHalfwordEntryFromField150(Field150Holder02052df8* holder, int part);
void* GetActiveCombatWork();
char* GetOffsetPtr02160f08(void* work);
void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
extern "C" void _Z28SetShortFields0x8e4aTo0x8e4ePviii(void* world, short a, short b, short c);
extern "C" int func_0207ccf0(void* buf, int a, int b, int c, int d, int e, int f);
int CopyIndexedRegion0x75f0(void* unused, short* indices, int* dest, int count);
extern "C" void func_020abe84(void* unused, short* indices, Counts021df924* values, int count);
void LoadBattleBlock020ac4c0(void* block);
void AddClamped24BitField(S_a0720* block, unsigned int value);
void AddClampedLow16BitFieldAt0x8(S_9fffc* block, unsigned int value);
void AddCappedValue(Field0x30* block, unsigned int value);
void AddClampedHigh16BitFieldAt0x8(S_a0038* block, unsigned int value);
void CopyInBattleField0x7540(void* block);
extern "C" void* func_ov000_0215e958(void* world);
void AddEntryAndIncrementCount0215a88c(void* world, void* entry, int value);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* target, int a, int b, int c, int d);

// USA: func_ov024_021df924
extern "C" ARM void* func_ov024_021df924(Action021df924* self, short id, int targetId, ActionData021df924* data) {
    Fighter021df924* actor = (Fighter021df924*)GetCombatantWithFlag0x100(GameState::GetInstance(), id);
    if (!actor) return 0;
    Fighter021df924* target = (Fighter021df924*)GetCombatantWithFlag0x400ByID((int)self->world, targetId);
    if (!target) return 0;
    Odds021df924* odds = target->odds;
    if (!odds) return 0;
    int stolen = 0;
    unsigned char* rate;
    unsigned short* msg;
    rate = odds->rate;
    msg = odds->message;
    short level = (unsigned short)actor->info->level;
    Random* rng = (Random*)self->world;
    float rolls[2];
    rolls[0] = NextRandomFloatBetween(rng, 0.0f, 100.0f);
    rolls[1] = NextRandomFloatBetween(rng, 0.0f, 100.0f);
    int anyRate = 0;
    unsigned short resultID;
    unsigned short entryID;
    unsigned short combatantKey;
    Counts021df924 counts;
    Loader021df924 loader;
    int i;
    for (i = 0; i < 2; i++, rate++, msg++) {
        if (*rate == 0) continue;
        resultID = 0;
        entryID = 0;
        combatantKey = 0;
        int found = 0;
        void* scene = func_0202ae18();
        if (self->world->pending == 0 && func_0202c508(scene) && IsIdOrEffectMatchTarget0215fd24((int)self->world, id)) {
            found = func_ov024_021df71c(target, GetActionID(), i != 0, &resultID, &combatantKey, &entryID);
        }
        if (((Stats021df924*)target->currentStats_)->rank != 0 && !found) continue;
        if (data_ov024_021fe860[*rate] > 0.0f) anyRate = 1;
        float low = 2.0f * (100.0f * data_ov024_021fe860[*rate]);
        float high = 6.0f * (100.0f * data_ov024_021fe860[*rate]);
        if (GetHalfwordEntryFromField150((Field150Holder02052df8*)actor, 9) == 0x467f) {
            low = 2.0f * low;
            high = 2.0f * high;
        }
        if (low > 50.0f) low = 50.0f;
        if (high > 50.0f) high = 50.0f;
        if (level > 0x33) {
            if (level >= 999) low = high;
            else low = low + (float)(level - 0x33) * ((high - low) / 948.0f);
        }
        if (!(rolls[i] < low)) continue;
        self->message->id = *msg;
        stolen = 1;
        ((Stats021df924*)target->currentStats_)->rank = i + 1;
        if (IsIdOrEffectMatchTarget0215fd24((int)self->world, id)) {
            char* work = GetOffsetPtr02160f08(GetActiveCombatWork());
            char* special = work + 0xd0;
            char* normal = work + 0xe8;
            loader.alloc.ResetAllocatorPointer();
            ZeroInitReturn020de824(loader.body);
            InitStruct0207cbe8((char*)&loader);
            InitStruct0207cbe8((char*)&loader);
            if (found) {
                self->message->id = resultID;
                _Z28SetShortFields0x8e4aTo0x8e4ePviii(self->world, entryID, combatantKey, resultID);
                loader.source = special;
            } else {
                loader.source = normal;
                func_0207ccf0(&loader, self->message->id, 1, id, 1, 0, 0);
                counts.low = 0;
                counts.bit10 = 0;
                counts.first = 0;
                counts.second = 0;
                if (target->item) {
                    short item = target->item->id;
                    if (CopyIndexedRegion0x75f0(0, &item, (int*)&counts, 1)) {
                        if (i == 0) {
                            unsigned int count = counts.first + 1;
                            if (count > 99) count = 99;
                            counts.first = count;
                        }
                        if (i == 1) {
                            unsigned int count = counts.second + 1;
                            if (count > 99) count = 99;
                            counts.second = count;
                        }
                        func_020abe84(0, &item, &counts, 1);
                    }
                }
            }
        }
        break;
    }
    char block[0xb0];
    LoadBattleBlock020ac4c0(block);
    char* tail = block + 0x68;
    AddClamped24BitField((S_a0720*)block, 1);
    AddClampedLow16BitFieldAt0x8((S_9fffc*)tail, 1);
    unsigned short message;
    if (stolen) {
        AddCappedValue((Field0x30*)block, 1);
        AddClampedHigh16BitFieldAt0x8((S_a0038*)tail, 1);
        message = data->failure.first;
    } else if (!anyRate) {
        message = 0x25a;
    } else {
        message = data->failure.third;
    }
    CopyInBattleField0x7540(block);
    void* entry = func_ov000_0215e958(self->world);
    if (!entry) return 0;
    if (message) AddEntryAndIncrementCount0215a88c(self->world, entry, message);
    func_ov000_0215cd44(self->world, entry, target, 0, 0, 0, self->flags->alternate != 0);
    return entry;
}
