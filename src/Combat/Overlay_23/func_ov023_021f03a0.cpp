#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct ArrayContainsByteStruct;
struct GatherObj02163a7c;
struct S_10088;
struct Bytes02033b88;
struct Entry_0205d6a0 { char storage[4]; };
struct Obj021d9988;
struct TableA68 { char storage[4]; };
struct Reset_021eefac {
    int state, task; char pad8[9]; signed char member;
    unsigned char loaded[4]; char pad16[2]; int actorId;
#if defined(jpn)
    char pad1c[0x118-0x1c]; char entries[0x2498-0x118]; unsigned char count;
#else
    char pad1c[0x118-0x1c]; char entries[0x2788-0x118]; unsigned char count;
#endif

    char copyData[4]; unsigned char copyLength;
};
struct BattleResultEntry { unsigned char id, fileId, type, flag; int experience; };
struct BattleInfo { char pad0[0x25]; unsigned char legacyBoss; };
struct BattleEntry { char pad0[0x11b]; unsigned char state; char pad11c[2]; unsigned char count; char pad11f; void* entries; };
struct LoadedEntry { char storage[0x54]; };
struct BattleWork {
    char pad0[0x30]; SafeAllocator allocator;
#if defined(jpn)
    char pad44[0x218-0x30-sizeof(SafeAllocator)]; void* battle; BattleInfo* info;
#else
    char pad44[0x29c-0x30-sizeof(SafeAllocator)]; void* battle; BattleInfo* info;
#endif

#if defined(jpn)
    char pad2a4[0xb94-0x220]; char cameraTask[4]; char padc1c[0xe28-0xb98]; int state;
#else
    char pad2a4[0xc18-0x2a4]; char cameraTask[4]; char padc1c[0xeac-0xc1c]; int state;
#endif

#if defined(jpn)
    char padeb0[0x371c-0xe2c]; char entry[0x38a4-0x371c]; Entry_0205d6a0 entries;
#else
    char padeb0[0x3760-0xeb0]; char entry[0x38e8-0x3760]; Entry_0205d6a0 entries;
#endif

#if defined(jpn)
    char pad38ec[0x5778-0x38a8]; BattleEntry* result;
#else
    char pad38ec[0x5588-0x38ec]; BattleEntry* result;
#endif

#if defined(jpn)
    char pad558c[0x5948-0x577c]; int experience[4]; int gold; unsigned char levelUp;
#else
    char pad558c[0x5758-0x558c]; int experience[4]; int gold; unsigned char levelUp;
#endif

#if defined(jpn)
    char pad576d[3]; LoadedEntry loaded[4]; char pad58c0[0x5af4-0x5ab0]; TableA68 strings;
#else
    char pad576d[3]; LoadedEntry loaded[4]; char pad58c0[0x5904-0x58c0]; TableA68 strings;
#endif

};
struct MessageController {
#if defined(jpn)
    char pad0[0x10]; void* actor; char pad14[0x868-0x14]; int field998;
#else
    char pad0[0x10]; void* actor; char pad14[0x998-0x14]; int field998;
#endif

#if defined(jpn)
    char pad99c[0x17de - 0x86c]; unsigned char field19ae, field19af;
#else
    char pad99c[0x19ae - 0x99c]; unsigned char field19ae, field19af;
#endif

#if defined(jpn)
    char pad19b0[2]; unsigned char field19b2; char pad19b3[0x17fb-0x17e3]; unsigned char field19ca;
#else
    char pad19b0[2]; unsigned char field19b2; char pad19b3[0x19ca-0x19b3]; unsigned char field19ca;
#endif

};
struct ActorFlags { char pad0[0xc1]; unsigned char fieldc1; unsigned char low : 4; unsigned char visible : 1; unsigned char high : 3; };
extern "C" Reset_021eefac* _ZZ17GetGlobal021ffefcvE1s;
extern "C" MessageController* _Z26GetGlobalField0x1c020421a0v();
extern "C" void* func_0202ae18();
int ArrayContainsByte(ArrayContainsByteStruct*, int);
extern "C" void _Z31ScaleOrResetCombatants_021ed988Pci(char*, int);
extern "C" void func_ov000_02163b90(BattleWork*, int);
extern "C" void func_ov000_021626a0(BattleWork*, int, int);
extern "C" void _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c(GatherObj02163a7c*);
extern "C" void func_ov000_021639b4(BattleWork*);
void ClearBitsInField4(unsigned int*, unsigned int);
extern "C" void _Z38RunFlagPassAndSetMode02167dd8_02167dd8Ph(unsigned char*);
extern "C" int func_ov000_02153e40(void*, short*, int, int);
extern "C" void func_02048cf0(GameObject*, int);
extern "C" void func_ov000_0216e3c4(void*);
extern "C" unsigned char* _Z16GetField02163524Pv(void*);
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" void _Z26ResetCombatantSlot020d7334Phi(unsigned char*, int);
int IsFlag10088Set(S_10088*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
extern "C" void _Z23ClearStateFlags0203400cPh(unsigned char*);
GameObject* GetCombatantWithFlag0x400(GameState*, int);
GameObject* GetCombatantWithFlag0x100(GameState*, int);
GameObject* GetCombatantWithFlag0x1000(GameState*, int);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0*, int);
void SetCombatWorkFlags0x55f4(void*, int);
extern "C" void func_ov023_021d8a40(BattleEntry*);
extern "C" void _Z24CopyEntryFields_021d8cb4PvS_(void*, void*);
extern "C" void _Z24CopyAndStoreLen_021d9988P11Obj021d9988Pvj(Obj021d9988*, void*, unsigned int);
extern "C" void func_02046380(MessageController*);
extern "C" void func_ov023_021d8ddc(BattleEntry*, int*);
int GetCheckedSignedByte(void*, unsigned int);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
char* FindEntryByKey(TableA68*, int);
extern "C" void func_0204500c(MessageController*, char*, int, int);
extern "C" BattleResultEntry* _Z24FindByByteAt118_021f0360Pvi(void*, int);
extern "C" int func_02082490(LoadedEntry*, void*, unsigned int, unsigned char, int);
extern "C" int func_ov023_021f4438(BattleWork*);
extern "C" int func_ov023_021f4fc8();
extern "C" void _Z20ResetFields_021eefacP14Reset_021eefac(Reset_021eefac*);

#if defined(jpn)
extern "C" void func_02045d88(MessageController*,char*,int);
#endif
// JPN: func_ov023_021effa4
// USA: func_ov023_021f03a0
extern "C" ARM int func_ov023_021f03a0(BattleWork* work) {
    int i;
    char text[256];
#if defined(jpn)

#else
    char actorName[12];
#endif

    char filename[40];
    short ids[12];
    GameState* game = GameState::GetInstance();
    Reset_021eefac* state = _ZZ17GetGlobal021ffefcvE1s;
    MessageController* messages = _Z26GetGlobalField0x1c020421a0v();
    func_0202ae18();
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ArrayContainsByte((ArrayContainsByteStruct*)GetPtrField0x2a04(game), state->actorId);
    if (state->state == 0) {
        if (work->levelUp) _Z31ScaleOrResetCombatants_021ed988Pci((char*)work, 0);
        func_ov000_02163b90(work, 1);
        func_ov000_021626a0(work, 4, 0);
        _Z40ApplyField41ToGatheredCombatants02163a7cP17GatherObj02163a7c((GatherObj02163a7c*)work);
        func_ov000_021639b4(work);
        ClearBitsInField4((unsigned int*)resources, 0x400);
        _Z38RunFlagPassAndSetMode02167dd8_02167dd8Ph((unsigned char*)work);
        void* battle = work->battle;
        int count;
        GameState* combatGame = GameState::GetInstance();
        count = func_ov000_02153e40(battle, ids, 12, 0);
        for (i = 0; i < count; i++) {
            GameObject* actor = combatGame->GetCombatantByIndex(ids[i]);
            if (actor) func_02048cf0(actor, 0);
        }
        func_ov000_0216e3c4(work->cameraTask);
        unsigned char* field = _Z16GetField02163524Pv(work);
        GameState* partyGame = GameState::GetInstance();
        for (int i = 0; i < 4; i++) {
            if (TestBitAt0x34((unsigned char*)work->info, (unsigned char)i)) {
                if (field) _Z26ResetCombatantSlot020d7334Phi(field, i);
                GameObject* actor = partyGame->GetCombatantByIndex(i);
                if (actor && !IsFlag10088Set((S_10088*)actor)) {
                    ((ActorFlags*)actor)->fieldc1 &= ~0xf0;
                    SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
                    actor->obj3D_.SkipAnimationTransition();
                    _Z23ClearStateFlags0203400cPh((unsigned char*)actor);
                    actor->obj3D_.MakeVisible();
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            GameObject* actor = GetCombatantWithFlag0x400(partyGame, i + 0xc0);
            if (actor && ((ActorFlags*)actor)->visible) actor->obj3D_.MakeVisible();
        }
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(&work->entries, 1);
        SetCombatWorkFlags0x55f4(work, 0x40000);
        work->allocator.Reset();
        work->result = (BattleEntry*)work->allocator.Allocate(0x12c);
        func_ov023_021d8a40(work->result);
        _Z24CopyEntryFields_021d8cb4PvS_(work->result, work->entry);
        Reset_021eefac* global = _ZZ17GetGlobal021ffefcvE1s;
        unsigned char countEntries = global->count;
        BattleEntry* result = work->result;
        result->entries = global->entries;
        result->count = countEntries;
        _Z24CopyAndStoreLen_021d9988P11Obj021d9988Pvj((Obj021d9988*)work->result, _ZZ17GetGlobal021ffefcvE1s->copyData, _ZZ17GetGlobal021ffefcvE1s->copyLength);
        state->state++;
    } else if (state->state == 1) {
        if (work->result->state != 0xff) goto done;
#if defined(jpn)

#else
        func_02046380(messages);
#endif

        func_ov023_021d8ddc(work->result, work->experience);
        BaseCombatStats* stats = 0;
        if (work->info->legacyBoss) {
            for (int i = 0; i < 4 && !stats; i++) {
                int id = GetCheckedSignedByte(game, (unsigned char)i);
                if (work->experience[id]) {
                    GameObject* actor = GetCombatantWithFlag0x100(game, id);
#if defined(jpn)

#else
#if defined(jpn)

#else
                    _Z30InitObjFromCombatantId020e4bf4Pvi(actorName, id);
#endif

#endif

                    stats = actor->baseStats_;
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int id = GetCheckedSignedByte(game, (unsigned char)i);
                GameObject* actor = GetCombatantWithFlag0x100(game, id);
                if (actor && TestBitAt0x34((unsigned char*)work->info, (unsigned char)id) && !IsFlag10088Set((S_10088*)actor)) {
#if defined(jpn)

#else
#if defined(jpn)

#else
                    _Z30InitObjFromCombatantId020e4bf4Pvi(actorName, id);
#endif

#endif

                    stats = actor->baseStats_;
                    break;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < 4; i++) if (work->experience[i]) count++;
        if (!stats) {
            for (int i = 0; i < 4; i++) {
#if defined(jpn)
                GameObject* actor = GetCombatantWithFlag0x100(game, i);
                if (actor && TestBitAt0x34((unsigned char*)work->info, (unsigned char)i) && !GetCombatantWithFlag0x1000(game, i))
                    stats = actor->baseStats_;
#else
                if (GetCombatantWithFlag0x100(game, i) && TestBitAt0x34((unsigned char*)work->info, (unsigned char)i) && !GetCombatantWithFlag0x1000(game, i))
                    _Z30InitObjFromCombatantId020e4bf4Pvi(actorName, i);
#endif

            }
        }
#if defined(jpn)
        if (count > 1) sprintf(text, FindEntryByKey(&work->strings, 0x1a), stats);
        else sprintf(text, FindEntryByKey(&work->strings, 0x19), stats);
#else
        messages->actor = actorName;
        int messageId = 0x19;
        if (count > 1) messageId = 0x1a;
        sprintf(text, FindEntryByKey(&work->strings, messageId));
#endif

        strcat(text, FindEntryByKey(&work->strings, 0x22));
#if defined(jpn)
        func_02045d88(messages, text, 1);
#else
        func_0204500c(messages, text, 1, 0xe3);
#endif

        messages->field19b2 = 0;
        messages->field998 = 1;
        state->state++;
    } else if (state->state == 2) {
        BattleResultEntry* entry = _Z24FindByByteAt118_021f0360Pvi(_ZZ17GetGlobal021ffefcvE1s, state->member);
        if (!entry) {
            state->member++;
            if (state->member >= 4) state->state = 4;
            return work->state;
        }
        sprintf(filename, FindEntryByKey(&work->strings, 0), entry->fileId);
        state->task = loader->QueueLoadFile(filename, 0);
        state->state++;
    } else if (state->state == 3) {
        if (!loader->GetTaskStatus(state->task)) return work->state;
        unsigned int length;
        void* file;
        int member = state->member;
        loader->GetLoadedFileByID(state->task, &file, &length);
        loader->RemoveTask(state->task);
        BattleResultEntry* entry = _Z24FindByByteAt118_021f0360Pvi(_ZZ17GetGlobal021ffefcvE1s, member);
        if (file && func_02082490(&work->loaded[member], file, length, entry->type, entry->experience)) {
            if (!entry->flag) state->loaded[member] = 1;
        }
        state->member++;
        if (state->member < 4) {
            state->state = 2;
            return work->state;
        }
        state->state++;
    } else if (state->state == 4) {
        int loaded = 0;
        for (int i = 0; i < 4; i++) if (state->loaded[i]) { loaded = 1; break; }
        int pending = func_ov023_021f4438(work);
        if (!loaded && !pending && !work->gold) {
            messages->field19ae = 0;
            messages->field19ca = 0;
            messages->field19af = 0;
        }
        if (func_ov023_021f4fc8()) {
            _Z20ResetFields_021eefacP14Reset_021eefac(state);
            return 7;
        }
    }
done:
    return work->state;
}
