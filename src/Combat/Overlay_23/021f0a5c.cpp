#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct GameState {
    static GameState* GetInstance();
};
struct GameObject;
struct ArrayContainsByteStruct;
struct TableA68 { char storage[4]; };
struct Obj021d9988;
struct BattleResultEntry { unsigned char id, fileId, type, flag; unsigned int experience; };
struct BattleEntry { char pad0[0x11b]; unsigned char state; char pad11c[2]; unsigned char count; char pad11f; void* entries; };
struct LevelStats {
    unsigned int exp;
    unsigned short level : 7;
    unsigned short pct : 9;
    char pad6[0x14 - 6];
};
struct LoadedEntry { LevelStats base, gained, extra, bonus; int tail; };
struct CombatStats {
    char pad0[0x138]; unsigned int exps[0xd];
    char pad16c[0x16c - 0x16c]; unsigned short levels[0x1fc];
    unsigned short skillPoints;
    char pad566[0x950 - 0x566]; int index;
};
struct BattleWork {
    char pad0[0x30]; SafeAllocator allocator;
    char pad44[0xeac - 0x30 - sizeof(SafeAllocator)]; int state;
    char padeb0[0x3760 - 0xeb0]; char entry[0x5588 - 0x3760];
    BattleEntry* result;
    char pad558c[0x5770 - 0x558c]; LoadedEntry loaded[4];
    char pad58c0[0x5904 - 0x58c0]; TableA68 strings;
};
struct ResultState {
    int state, task; char pad8[0x18 - 8]; int id;
    unsigned char learned[4][0x14];
    unsigned char learnedCount[4];
    char pad70[0xe5 - 0x70]; signed char outcome;
    char pade6[0xf0 - 0xe6]; char skillTable[0x118 - 0xf0];
    char entries[0x2788 - 0x118]; unsigned char count;
    char copyData[4]; unsigned char copyLength;
};
struct MessageController {
    char pad0[0x10]; void* actor; char pad14[0x998 - 0x14]; int field998;
    char pad99c[0x19b2 - 0x99c]; unsigned char field19b2;
    char pad19b3[0x19ca - 0x19b3]; unsigned char field19ca;
};

extern "C" ResultState* _ZZ17GetGlobal021ffefcvE1s;
extern char data_02109bf4[];

extern "C" MessageController* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(MessageController*);
char* FindEntryByKey(TableA68*, int);
void* GetPtrField0x2a04(GameState*);
int ArrayContainsByte(ArrayContainsByteStruct*, int);
extern "C" void _Z20ResetFields_021eefacP14Reset_021eefac(ResultState*);
extern "C" BattleResultEntry* _Z24FindByByteAt118_021f0360Pvi(void*, int);
extern "C" int func_02082490(LoadedEntry*, void*, unsigned int, unsigned char, unsigned int);
GameObject* GetCombatantWithFlag0x100(GameState*, int);
extern "C" CombatStats* _Z15GetFieldAt0x150Ph(GameObject*);
extern "C" void func_02083cbc(CombatStats*, LevelStats*, LevelStats*);
extern "C" void func_02083e28(CombatStats*, int);
extern "C" unsigned char func_0209aa54(void*, GameObject*, unsigned char*, int);
extern "C" int _Z25GetTableEntry138_021eea98P11Obj021eea98(GameObject*);
extern "C" void _Z24InitCombatEntry_021d8b6cPv(BattleEntry*);
extern "C" void func_ov023_021d8af8(BattleEntry*);
extern "C" void func_ov023_021d8a40(BattleEntry*);
extern "C" void _Z24CopyEntryFields_021d8cb4PvS_(void*, void*);
extern "C" void _Z24CopyAndStoreLen_021d9988P11Obj021d9988Pvj(Obj021d9988*, void*, unsigned int);
extern "C" void func_ov023_021d8e4c(BattleEntry*, int, LevelStats*, LevelStats*);
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(MessageController*, int, int);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
extern "C" void func_0204500c(MessageController*, char*, int, int);
extern "C" void _Z36ResetAndDispatchActorContext0209c6d8Pvs(void*, short);
extern "C" void func_ov017_021ce704(int);
extern "C" void func_ov017_021cc730(int, int, int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" int func_ov023_021f4fc8();
extern "C" int _Z30CheckThresholdOverAny_021f5228i(int);
extern "C" void* func_0205ec34();
int TestBitInByteArray(int, unsigned char*, int);
extern "C" int _Z25IsAnimationActive0209ca2cPv(void*);

static inline int GetLevel(CombatStats* stats) { return stats->levels[stats->index]; }

// USA: func_ov023_021f0a5c
extern "C" ARM int func_ov023_021f0a5c(BattleWork* work) {
    char text[0x100];
    char text2[0x100];
    char filename[40];
    char actorName[12];
    char actorName2[12];
    GameState* game = GameState::GetInstance();
    ResultState* state = _ZZ17GetGlobal021ffefcvE1s;
    MessageController* messages = _Z26GetGlobalField0x1c020421a0v();
    func_02046380(messages);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* suffix = FindEntryByKey(&work->strings, 0x22);
    int inParty = ArrayContainsByte((ArrayContainsByteStruct*)GetPtrField0x2a04(game), state->id);
    if (state->state == 0) {
        state->id++;
        if (state->id >= 4) {
            _Z20ResetFields_021eefacP14Reset_021eefac(state);
            return 0xb;
        }
        BattleResultEntry* entry = _Z24FindByByteAt118_021f0360Pvi(_ZZ17GetGlobal021ffefcvE1s, state->id);
        if (!entry) return work->state;
        sprintf(filename, FindEntryByKey(&work->strings, 0), entry->fileId);
        state->task = loader->QueueLoadFile(filename, 0);
        state->state++;
    } else if (state->state == 1) {
        if (!loader->GetTaskStatus(state->task)) return work->state;
        unsigned int length;
        void* file;
        int id = state->id;
        loader->GetLoadedFileByID(state->task, &file, &length);
        loader->RemoveTask(state->task);
        int learned = 0;
        BattleResultEntry* entry = _Z24FindByByteAt118_021f0360Pvi(_ZZ17GetGlobal021ffefcvE1s, id);
        if (file && func_02082490(&work->loaded[id], file, length, entry->type, entry->experience)) {
            if (!entry->flag) learned = 1;
        }
        LevelStats* extra = &work->loaded[id].extra;
        int type = entry->type;
        int level = type + extra->level;
        int retry = 0;
        if (learned) {
            if (inParty) {
                GameObject* actor = GetCombatantWithFlag0x100(game, id);
                if (actor) {
                    CombatStats* stats = _Z15GetFieldAt0x150Ph(actor);
                    stats->levels[stats->index] = level;
                    unsigned short room = 0xa28 - stats->skillPoints;
                    if (room < extra->pct) extra->pct = room;
                    stats->skillPoints += extra->pct;
                    func_02083cbc(stats, &work->loaded[id].gained, &work->loaded[id].bonus);
                    func_02083e28(stats, 0);
                    state->learnedCount[id] = func_0209aa54(state->skillTable, actor, state->learned[id], type);
                }
            }
        } else {
            state->state = 0;
            retry = 1;
        }
        if (inParty) {
            GameObject* actor = GetCombatantWithFlag0x100(game, id);
            if (actor) {
                CombatStats* stats = _Z15GetFieldAt0x150Ph(actor);
                if (GetLevel(stats) >= 99) {
                    unsigned int exp = work->loaded[id].base.exp;
                    if (learned) exp = work->loaded[id].gained.exp;
                    if (exp != 0 && exp <= _Z25GetTableEntry138_021eea98P11Obj021eea98(actor)) {
                        if (stats) stats->exps[stats->index] = exp;
                        entry->experience = exp;
                    }
                }
            }
        }
        if (retry) return work->state;
        state->state++;
    } else if (state->state == 2) {
        if (work->result) {
            _Z24InitCombatEntry_021d8b6cPv(work->result);
            func_ov023_021d8af8(work->result);
            work->result = 0;
            return work->state;
        }
        work->allocator.Reset();
        if (!inParty) {
            state->state = 4;
        } else {
            work->result = (BattleEntry*)work->allocator.Allocate(0x12c);
            func_ov023_021d8a40(work->result);
            _Z24CopyEntryFields_021d8cb4PvS_(work->result, work->entry);
            ResultState* global = _ZZ17GetGlobal021ffefcvE1s;
            unsigned char countEntries = global->count;
            BattleEntry* result = work->result;
            result->entries = global->entries;
            result->count = countEntries;
            _Z24CopyAndStoreLen_021d9988P11Obj021d9988Pvj((Obj021d9988*)work->result, _ZZ17GetGlobal021ffefcvE1s->copyData, _ZZ17GetGlobal021ffefcvE1s->copyLength);
            state->state++;
        }
    } else if (state->state == 3) {
        if (work->result->state == 0xff) state->state++;
    } else if (state->state == 4) {
        int id = state->id;
        LevelStats* gained;
        LevelStats* extra;
        LevelStats* base;
        base = &work->loaded[id].base;
        extra = &work->loaded[id].extra;
        if (work->result) func_ov023_021d8e4c(work->result, id, base, extra);
        if (_Z24FindByByteAt118_021f0360Pvi(_ZZ17GetGlobal021ffefcvE1s, id)) {
            gained = &work->loaded[(unsigned int)id].gained;
            if (gained->level - base->level > 1) {
                sprintf(text, FindEntryByKey(&work->strings, 0x16));
                _Z17StoreInArray0x8b0P11StoreStructii(messages, 0, base->level);
                _Z17StoreInArray0x8b0P11StoreStructii(messages, 1, gained->level);
            } else {
                sprintf(text, FindEntryByKey(&work->strings, 0xa));
                _Z17StoreInArray0x8b0P11StoreStructii(messages, 0, gained->level);
            }
            strcat(text, suffix);
            _Z30InitObjFromCombatantId020e4bf4Pvi(actorName, id);
            messages->actor = actorName;
            func_0204500c(messages, text, 1, 0xe3);
            messages->field19b2 = 0;
            messages->field998 = 1;
        }
        if (inParty) {
            _Z36ResetAndDispatchActorContext0209c6d8Pvs(data_02109bf4, 0x35);
            func_ov017_021ce704(id);
            func_ov017_021cc730(id, 0, 0, 1);
            func_ov017_021c9e00(id, 0, 0, 0);
            state->state++;
        } else {
            state->state += 2;
        }
    } else if (state->state == 5) {
        if (func_ov023_021f4fc8()) {
            int id = state->id;
            if (_Z24FindByByteAt118_021f0360Pvi(_ZZ17GetGlobal021ffefcvE1s, id)) {
                sprintf(text2, FindEntryByKey(&work->strings, 0x26));
                strcat(text2, suffix);
                _Z30InitObjFromCombatantId020e4bf4Pvi(actorName2, id);
                messages->actor = actorName2;
                func_0204500c(messages, text2, 1, 0xe3);
                messages->field19b2 = 0;
                messages->field998 = 1;
            }
            state->state++;
        }
    } else if (state->state == 6) {
        if (inParty) {
            int id = state->id;
            LevelStats* extra = &work->loaded[id].extra;
            unsigned short points = 0;
            GameObject* actor = GetCombatantWithFlag0x100(game, id);
            if (actor) {
                CombatStats* stats = _Z15GetFieldAt0x150Ph(actor);
                if (stats) points = stats->skillPoints;
            }
            GetPtrField0x2a04(game);
            if (state->learnedCount[id]) {
                state->outcome = 10;
            } else if (extra->pct) {
                state->outcome = 12;
            } else if (points && _Z30CheckThresholdOverAny_021f5228i(id)) {
                state->outcome = 8;
                void* base = func_0205ec34();
                if (TestBitInByteArray((int)base, (unsigned char*)base + 0x8c, 0x119c)) messages->field19ca = 0;
            }
        }
        state->state++;
    } else if (state->state == 7) {
        if (_Z25IsAnimationActive0209ca2cPv(data_02109bf4)) return work->state;
        if (func_ov023_021f4fc8()) {
            signed char outcome = state->outcome;
            _Z20ResetFields_021eefacP14Reset_021eefac(state);
            if (outcome >= 0) return outcome;
        }
        return work->state;
    }
    return work->state;
}
