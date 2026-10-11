#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define REGION_LAYOUT(jpnValue, usaValue) jpnValue
#else
#define REGION_LAYOUT(jpnValue, usaValue) usaValue
#endif

struct BattleState;
struct Actor0209c678;
struct FlagWord020466f4;
struct List020727d8;
struct TableA68;
struct ArrayContainsByteStruct;

struct Cmd {
    unsigned char b[4];
    signed char c;
    unsigned short d;
    unsigned short e;
};

struct PartyState {
    char pad0[0x8];
    unsigned short id;
    char pad0a[0x20];
    signed char kind;
};

struct MessageWork {
    char pad0[0x30];
    unsigned char numMembers;
    unsigned char numAlive;
    char pad32[REGION_LAYOUT(0x836, 0x966)];
    int busy;
};

struct Stats021f4c04 {
    unsigned int flags;
};

struct Combatant021f4c04 {
    char pad0[0x130];
    Stats021f4c04* stats;
};

struct BattleWork {
    char pad0[0x30];
    char alloc[REGION_LAYOUT(0x108, 0x11c)];
    char stateA[REGION_LAYOUT(0xe0, 0x150)];
    BattleState* battle;
    PartyState* party;
    char pad2a4[0x974];
    char view[0x220];
    unsigned char dispMode;
    unsigned char posInit;
    char pade3a[0x5e];
    char scriptA[0x8];
    char scriptB[0x8];
    char padea8[0x4];
    int state;
    char padeb0[0x4];
    unsigned char cursorLock;
    unsigned char revivePending;
    char padeb6[0x12];
    char ctxEc8[REGION_LAYOUT(0x28d8, 0x2898)];
    char list[0xb8];
    char msgBox[0xc4];
    int activeSlot;
    char pad38e0[0x7d0];
    int turnCount;
    unsigned char battleKind;
    char pad40b5[REGION_LAYOUT(0x124f, 0x11b7)];
    char ownerNames[REGION_LAYOUT(0x1f0, 0x150)];
    char memberNames[REGION_LAYOUT(0x1c0, 0xc0)];
    int memberRanks[8];
    int memberIds[8];
    unsigned char groupKind;
    char pad54bd[0x3];
    signed char slotStatus[8];
    signed char slotCursor;
    char pad54c9[0x9];
    unsigned short uiFlags;
    char pad54d4[0x4];
    unsigned char versusFlag;
    char pad54d9[0x7];
    unsigned char ready;
    unsigned char readyPrev;
    char pad54e2[0x2];
    Cmd cmd;
    char pad54ee[0x2];
    int curSlot;
    int slotDone[4];
    char pad5504[REGION_LAYOUT(0xd0, 0xd4)];
    int field55d8;
    char pad55dc[0x18];
    int workFlags;
    char pad55f8[0x130];
    char ctx5728[0x1a6];
    unsigned short reviveCount;
    char pad58d0[0x34];
    char rosterList[0xc];
    char ctx5910[0x40];
    unsigned char resultKind;
    char pad5951[0x3];
    char iconA[0xac];
    char iconB[0x23c];
    char ctx5c3c[0x1200];
    int randHi;
    int randLo;
    char pad6e44[0x8cc];
    signed char fadeTimer;
    unsigned char fadeActive;
    signed char phase;
    char pad7713[0x1];
    short objId;
    short objIds[4];
    short objId771e;
    short objId7720;
    short objId7722;
    short objId7724;
    char pad7726[0x9];
    unsigned char inputOn;
    char pad7730[0x4];
    int savedWorkFlags;
    int savedField;
    char pad773c[0xc];
    unsigned char turnFlag;
    unsigned char reinitFlag;
    unsigned char slotsDirty;
    char pad774b[0x1];
    char cmdAlloc[0x14];
    char stateB[0x150];
};

struct Global021ffefc {
    void* inner;
    unsigned int elapsed;
    unsigned int flags;
};

inline Global021ffefc& GetGlobal021ffefc() {
    static Global021ffefc s;
    return s;
}

extern Actor0209c678 data_02109bf4;
extern const char data_ov023_021fe1d8[];
extern const char data_ov023_021fe1ee[];
#if defined(jpn)
extern const char data_ov023_021fd49e[];
extern "C" void func_02073864(void*, void*, const char*, int, int, int);
extern "C" void func_02045d88(void*, const char*, int);
#endif

extern "C" MessageWork* _Z26GetGlobalField0x1c020421a0v();
int GetWord0x0(int* obj);
extern "C" void* func_02012fe4(void);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
void* GetPtrField0x2a04(GameState* gameState);
extern "C" void* func_0202ae18(void);
void SetField0x5729Value(char* obj, unsigned char value);
unsigned char GetField0x5729Value(char* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
int CheckField0NonZero(int* obj);
extern "C" void func_ov017_021d2400(void);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(Actor0209c678* actor, int arg);
void SetCombatWorkFlags0x55f4(void* work, int mask);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(FlagWord020466f4* word, unsigned int mask);
extern "C" void _Z23ResetListHeader020727d8P12List020727d8(List020727d8* list);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath,
                                    unsigned int* outSize);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a4, int a5,
                              int a6);
extern "C" void _Z35SetFieldForListedCombatants021f50fcv();
extern "C" int func_ov000_02163c80(void* work, int mode);
extern "C" GameObject* _Z32FindCombatantByField16a_021a278cPvi(void* unused, int val);
extern "C" void _Z26EnqueueEventTag87_021c9b20ii(int a, int b);
extern "C" int _Z18TrySetMode02076cccPvi(void* obj, int mode);
extern "C" void func_ov017_021a23b0(void* base, int v);
unsigned char CopyOutRegion0x571d(char* obj, void* dst);
extern "C" void func_ov000_0216d370(void* obj, int flagA, int flagB, int flagC);
void* FindEntryByKey(TableA68* table, int key);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" void func_0204500c(void* obj, const char* text, int mode, int tag);
extern "C" void _Z36ResetAndDispatchActorContext0209c6d8Pvs(void* actor, short arg);
extern "C" int func_ov017_021959b4(void);
int ArrayContainsByte(ArrayContainsByteStruct* s, int val);
extern "C" void _Z27EnqueueEventTag129_021cbfb8th(unsigned short a, unsigned char b);
extern "C" void _Z20StopAndReset0209c7fcPv(void* obj);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" void func_02043124(void* obj);
void SetFieldsAndSignalData02184220(void* p, int val);

// USA: func_ov023_021f4c04
extern "C" ARM void func_ov023_021f4c04(BattleWork* self) {
    char text[REGION_LAYOUT(0x50, 0xb4)];
#if !defined(jpn)
    unsigned int len;
    unsigned char ids[4];
#endif

    GameState* gs = GameState::GetInstance();
    MessageWork* ctrl = _Z26GetGlobalField0x1c020421a0v();
    int res = GetWord0x0((int*)gs);
    func_02012fe4();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    FlagWord020466f4* flags = (FlagWord020466f4*)_Z27GetDataPtr02114e04_020d6c00v();
    void* battle = GetPtrField0x2a04(gs);
    void* owner = func_0202ae18();

    GetGlobal021ffefc().elapsed += gs->GetEffectiveDeltaTime();
    int state = self->state;

    if (state == 0) {
        SetField0x5729Value((char*)gs, 1);
        for (int i = 0; i < 4; i++) {
            GameObject* member = gs->GetPartyMemberByIndex(i);
            if (member == NULL) continue;
            if (((Combatant021f4c04*)member)->stats->flags & 1) continue;
            if (TestBitAt0x34((unsigned char*)self->party, (unsigned char)i)) continue;
            SetField0x5729Value((char*)gs, 0);
        }
        if (GetField0x5729Value((char*)gs) != 0 && CheckField0NonZero((int*)owner) != 0) {
            func_ov017_021d2400();
        }
        _Z30DispatchContextByState0209c678P13Actor0209c678i(&data_02109bf4, 0x1e);
        SetCombatWorkFlags0x55f4(self, 0x800000);
        _Z18ClearFlags020466f4P16FlagWord020466f4j(flags, 0x40000);
        GetGlobal021ffefc().elapsed = 0;
        self->state = 1;
    } else if (state == 1) {
        if (GetGlobal021ffefc().elapsed < 1000) return;
        if (loader->GetNumQueuedTasks() > 0) return;
        ((SafeAllocator*)self->alloc)->Reset();
        _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)self->rosterList);
#if defined(jpn)
        func_02073864(self->rosterList, self->alloc, data_ov023_021fd49e, 0, 0, 0);
#else
        BackgroundLoader::AddLockGlobal();
        len = 0;
        void* file = ExtractFileFromGP2(data_ov023_021fe1d8, data_ov023_021fe1ee, &len);
        if (file != NULL) {
            func_020728ac(self->rosterList, self->alloc, file, len, 0, 0, 0);
        }
        BackgroundLoader::RemoveLockGlobal();
#endif
        _Z35SetFieldForListedCombatants021f50fcv();
        int id = self->party->id;
        if (func_ov000_02163c80(self, 1)) {
            GameObject* target = _Z32FindCombatantByField16a_021a278cPvi((void*)res, id);
            if (target != NULL) {
                _Z26EnqueueEventTag87_021c9b20ii((unsigned short)id, 1);
                _Z18TrySetMode02076cccPvi(target, 1);
                *(unsigned char*)((char*)target + 0x17d) &= ~0x80;
            }
        } else {
            _Z26EnqueueEventTag87_021c9b20ii((unsigned short)id, 0);
            func_ov017_021a23b0((void*)res, id);
        }
#if !defined(jpn)
        unsigned char count = CopyOutRegion0x571d((char*)gs, ids);
        unsigned char numMembers = 0;
        unsigned char numAlive = 0;
        for (int j = 0; j < count; j++) {
            GameObject* member = gs->GetCombatantByIndex(ids[j]);
            if (member == NULL) continue;
            if (!TestBitAt0x34((unsigned char*)self->party, ids[j])) continue;
            numMembers++;
            if ((((Combatant021f4c04*)member)->stats->flags & 1) == 0) numAlive++;
        }
        ctrl->numMembers = numMembers;
        ctrl->numAlive = numAlive;
#endif
        func_ov000_0216d370(self->view, 0, 0, 1);
#if defined(jpn)
        int value = *(int*)((char*)gs->GetProtagonist() + 0x134);
        sprintf(text, (const char*)FindEntryByKey((TableA68*)self->rosterList, 0x14), value);
        func_02045d88(ctrl, text, 1);
#else
        gs->GetProtagonist();
        sprintf(text, (const char*)FindEntryByKey((TableA68*)self->rosterList, 0x14));
        func_0204500c(ctrl, text, 1, 0xe3);
#endif
        ctrl->busy = 1;
        _Z36ResetAndDispatchActorContext0209c6d8Pvs(&data_02109bf4, 0x3a);
        self->state = 2;
    } else if (state == 2) {
        if (func_ov017_021959b4() == 0 && *(unsigned char*)((char*)gs + REGION_LAYOUT(0x54c8, 0x5728)) == 0) {
            if (ctrl->busy != 0) return;
        }
        if (ArrayContainsByte((ArrayContainsByteStruct*)battle, self->party->kind)) {
            _Z27EnqueueEventTag129_021cbfb8th(self->party->id, 1);
        }
        *(unsigned char*)((char*)gs + REGION_LAYOUT(0x54c8, 0x5728)) = 0;
        _Z20StopAndReset0209c7fcPv(&data_02109bf4);
        _Z24ReinitController02043204Pc((char*)ctrl);
        func_02043124(ctrl);
        SetFieldsAndSignalData02184220(self, 4);
    }
}
