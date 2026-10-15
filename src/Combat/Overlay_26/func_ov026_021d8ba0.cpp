#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"
#include "Resource/CharacterCreationUI.h"

struct Container_021dae60;
struct BattleWork;
struct BattleState;
struct PartyState;
struct Roster;
struct MessageWork;
struct SlotWork;
struct OwnerInfo;
struct ViewInfo;
struct NetSession;
struct Combatant020A36A8;
struct Pair0209a338;
struct Ctx0209a470;
struct Ctx0209a8b4;
struct StreamHeader;
struct S0204671c;
struct Container020d6f44;
struct GatherObj02163a7c;
struct S_10088;
struct FlagObj_021dd3c4;
struct Obj0203c108;
struct S02053dc0;
struct Bytes02033b88;
struct State0207dfc8;
struct TagValueEntry020e385c;
struct Obj02046574;
struct FlagWord02046708;
struct FlagWord020466f4;
struct SearchStruct;
struct IncObj;

struct Cmd {
    unsigned char b[4];
    signed char c;
    unsigned short d;
    unsigned short e;
};

struct Vec3i { int v[3]; };
struct Pos2i { int x, z; };
struct NameBuf { char s[0x80]; };
struct RowLabels {
    char names[8][3];
    int loadTask;
    const char* order[8];
};

inline RowLabels& GetRowLabels() {
    static RowLabels s = {
        {"f4", "f3", "f1", "f2", "b4", "b1", "b2", "b3"},
        -1,
        {s.names[2], s.names[3], s.names[1], s.names[0], s.names[5], s.names[6], s.names[7], s.names[4]},
    };
    return s;
}

struct Group {
    unsigned char unk0;
    unsigned char kind : 4;
    unsigned char numGroups : 2;
    unsigned char unk1_6 : 2;
    unsigned char unk2[4];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char unkE_4 : 4;
    unsigned char unkF[9];
};

int GetField0x3acValue_020100a8(GameState*);
SlotWork* FindSlotById_021dae60(Container_021dae60*, int);
MessageWork* GetGlobalField0x1c020421a0();
void* GetData02100044_0202ae24();
void* GetDataPtr02114e04_020d6c00();
unsigned char* GetData02153634_020e3580();
int ClassifyField0x81fe_ov000_0215fc60(char*);
void SetFieldsAndSignalData02184220_ov000_02160d80(void*, int);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
void ClearCombatWorkFlags0x55f4_ov000_02160fbc(void*, int);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void*, int);
void MarkSlots0218173c(void*);
int GetByte0x63d5_02012060(void*);
int CheckField0NonZero_0202b7d8(int*);
int MatchesActiveIndex020a36a8(Combatant020A36A8*);
void InitOverlay17Sub0215e8e8(void*);
void ClearFirstTwoWords0209a338(Pair0209a338*);
void SetupAndRunBufferedScript0209a470(Ctx0209a470*, SafeAllocator*, StreamHeader*, int);
void ClearField00209a804(int*);
void SetupAndRunBufferedScript0209a8b4(Ctx0209a8b4*, SafeAllocator*, StreamHeader*, int);
void ForwardField0xc0_0205eb80(void*);
int GetField0x0(S0204671c*);
void ClearBitsInWord_0203b4b0(unsigned int*, unsigned int);
void SetBitsInWord_0203b4a0(unsigned int*, unsigned int);
void ResetField0x930And0x934_ov000_02180b3c(void*);
ViewInfo* GetPtrField612_0216f208(void*);
void ClearBitsInField4_0203b4e8(unsigned int*, unsigned int);
void InitCombatantPosition_0216118c(void*, int);
void ClearFlagIfParityMismatch02163710_02163710(void*, int);
void RunFlaglearAndSetMode02167e6c_02167e6c(unsigned char*);
Container020d6f44* GetField02163524(void*);
void ResetEntryManager020d6f44(Container020d6f44*);
void ProcessCombatantReactions020d738c(void*);
void ApplyField41ToGatheredCombatants02163a7c(GatherObj02163a7c*);
int GetSubstructByte0x1c_020493a4(unsigned char*);
void SetSubstructByte0x1c_02049390(unsigned char*, unsigned char);
void SetSubstructFields0x10And0x18ClearFlag0x1_02049bd4(unsigned char*, int*);
void ReinitController02043204(char*);
void ReleaseEntriesTwoGroups02174dc0(void*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
char* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
int IsFlag10088Set_02010088(S_10088*);
int IsFlagBit8192Set_021dd3c4(FlagObj_021dd3c4*);
void SwapGlobalEntry0203c108(Obj0203c108*, char*);
void SetStoredWorkPtr_ov000_021744f4(int, void*);
void ClearFlag0x43e02176054(void*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
void* GetField0x19cOrNull(S02053dc0*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void Process02181364(void*);
void ClearFlag_021816e8_021816e8(void*, int);
void SetFlag_02181694_02181694(void*, int);
void ClearByteField_0217f5d0_0217f5d0(void*);
void CopyState0207dfc8(State0207dfc8*, State0207dfc8*);
void EnqueueEventTag89_021ca174(unsigned short);
TagValueEntry020e385c* GetData02153660_020e3808();
int IsEntryCompleteOrMissing020e3ad0(TagValueEntry020e385c*, int, int);
unsigned char* FindEntryByTagAndValue(TagValueEntry020e385c*, int, int);
void ResetTaggedEntryAndNotifyOverlay020e3994(TagValueEntry020e385c*, int, int);
int IsChannelValueZero0203b5e0(void*, int);
void SetBrightness(GameResources*, int, int);
int IsField0Null_02046b08(void**);
void UpdateFieldIfDiffers_02174514_02174514(void*);
void ClearFlag0x1000AndBytes7eA1_02088e64(unsigned char*);
void* GetFieldByKey020e0434(Container020e0310*, int);
void SetIndexedName02046574(Obj02046574*, int, char*);
int TestFlags02046708(FlagWord02046708*, unsigned int);
void OrBitsIntoField0_020466e4(unsigned int*, unsigned int);
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
int GetByte2IfGlobalFlagSet_020e37e8(unsigned char*);
void ClearBitOrNotifyOverlay020e3798(unsigned char*);
void SetBitOrNotifyOverlay020e36f0(unsigned char*);
int CountUnder100Flags0217fb98(void*);
void SetBoundedArrayField0x4f4_ov000_02162c90(char*, int, int);
int TestBitBySignedByteIndex_0202c1c0(SearchStruct*, int);
int GetByteField_02168720_02168720(char*);
void ClearSlotBitndSetByte_021813d4(void*);
void SetForwardAndStore0205eb54(void*, int, int);
void DispatchIfField0xc4NonNeg_0205eb90(void*, int, int);
void EnqueueEventTag108_021cefe0(unsigned short, unsigned char, unsigned char);
void EnqueueEventTag109_021cf650(unsigned short, int, int);
int CheckSlotsAllFree0205e488(void*);
void IncrementCounterUnlessFlagged_02053dd0(IncObj*);
void ResetTwoFields021637c8(void*);

extern "C" {
int* func_0202ae18();
void func_ov026_021d8aac( BattleWork*, int mode, int kind);
void func_ov000_02181608(void*);
void func_ov000_0218048c(void*);
void func_ov000_02162cbc( BattleWork*);
void func_ov000_021626a0( BattleWork*, int, int);
void func_ov000_021629ec( BattleWork*);
int func_ov000_0215e9fc(BattleState*, short*, int, int);
int func_ov000_0215ec1c(BattleState*, short*, int, int);
int func_ov000_0215eb1c(BattleState*, short*, int, int);
Pos2i func_ov000_0216f74c(int* cell);
void func_02043124(MessageWork*);
void func_ov026_021daec8(BattleState*, void*, int);
void func_ov000_02174614(void*, int);
void func_020e4864(void*, char*, int, int, int, int);
void __clear(void*, int);
void func_02046608(MessageWork*, int, char*, char*, int, int, int);
void func_ov000_0217f518(SlotWork*);
void func_ov000_02162c14( BattleWork*, int, void*);
void func_ov000_0217fa60(void*);
void func_ov000_02175258(void*);
void func_ov000_02174c14(void*);
void func_ov000_021814bc(void*);
void func_ov026_021dc8fc( BattleWork*, BattleState*, PartyState*, void*, void*, void*, int);
void* memset(void*, int, unsigned int);
void func_ov000_0217fcc4(void*, int);
int func_0202c540(int*);
void func_ov017_021c6814(unsigned short, unsigned short, Cmd*, unsigned char, int, int);
int func_ov026_021ddd84(GameResources*, BattleWork*, BattleState*, PartyState*, void*, void*, int);
void func_ov017_021c847c();
void func_020dd0b0(int, void*);
void func_0204500c(MessageWork*, void*, int, int);
int func_ov026_021d8a40();
void func_ov026_021dce34(int, BattleWork*, BattleState*, PartyState*, void*, void*, void*, void*, void*, void*, void*, void*);
void func_ov026_021dd8a8(BattleState*, PartyState*);
void func_ov000_0217fbf4(void*, int);
void func_02046380(MessageWork*);
void func_020e4ce8(void*, char*, int);
void func_ov000_0216258c( BattleWork*);
void func_ov026_021db3d8( BattleWork*);
int func_0202c508(int*);
void func_ov000_02175be4(void*);
void func_ov026_021db5a4( BattleWork*);
void func_ov026_021dbba8( BattleWork*);
void func_ov000_0217457c(void*, int);
unsigned char func_ov026_021dd3dc(BattleState*, PartyState*, void*);
void* func_ov000_02160f14( BattleWork*);
void func_ov017_021c894c(unsigned short);
void func_ov017_021c8758(unsigned short);
void func_ov017_021c8654();
void* func_02057924();
void func_02057f00(void*, int);
void func_ov000_02168144( BattleWork*);
void func_ov000_0215d588(BattleState*);
void func_ov000_02160da0( BattleWork*);
void func_ov026_021dc440(SafeAllocator*, BattleWork*, BattleState*, PartyState*, int);
int func_ov026_021dc040(SafeAllocator*, BattleWork*, BattleState*, PartyState*);
void func_ov000_02163894( BattleWork*);
void func_ov000_02163928( BattleWork*);
}

extern char data_ov026_021dedbc[];
extern char data_ov026_021dedd4[];
extern char data_02108760;
extern Vec3i data_ov026_021de6dc;
extern NameBuf data_ov026_021de6f8;
extern NameBuf data_ov026_021de778;
extern char data_ov026_021dedec[];

#define POWCNT (*(volatile unsigned short*)0x04000304)

static inline int IsValidSlot(int slot) {
    return slot >= 0 && slot <= 3;
}

struct SlotWork {
    char pad0[0x10];
    signed char cmds[8];
    signed char cursor;
};

struct OwnerInfo {
    char pad0[0x14];
    char* name;
};

struct ViewInfo {
    char pad0[0xc];
    int count;
};

struct NetSession {
    char pad0[0xc];
    int state;
};

struct MessageWork {
    char pad0[0x20];
    char* namePtr;
    char pad24[0x38];
    char* scriptWork;
    char pad60[0x938];
    int busy;
    char pad99c[0x1013];
    unsigned char flag19af;
    char pad19b0[0x1a];
    unsigned char flag19ca;
};

struct Roster {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
    char pad0a[0x2];
    int field0c;
    char pad10[0x1a];
    unsigned char myIndex;
    char pad2b[0x1];
    int field2c;
    int field30;
    unsigned char memberMask;
};

struct BattleState {
    Random rng;
    char pad20[0x8190];
    Group groups[4];
    char pad8210[0xc04];
    unsigned char result;
    char pad8e15[0x3];
    NetSession* netInfo;
    char pad8e1c[0x4];
    int turns;
    char pad8e24[0x23];
    unsigned char field8e47;
    char pad8e48[0x1];
    unsigned char kind;
};

struct BattleWork {
    char pad0[0x30];
    char alloc[0x11c];
    char stateA[0x150];
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
    char ctxEc8[0x2898];
    char list[0xb8];
    Container020e0310 msgBox;
    char pad3820[0xbc];
    int activeSlot;
    char pad38e0[0x7d0];
    int turnCount;
    unsigned char battleKind;
    char pad40b5[0x11b7];
    char ownerNames[0x150];
    char memberNames[0xc0];
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
    char pad5504[0xd4];
    int field55d8;
    char pad55dc[0x18];
    int workFlags;
    char pad55f8[0x130];
    char ctx5728[0x1a6];
    unsigned short reviveCount;
    char pad58d0[0x40];
    char ctx5910[0x40];
    unsigned char resultKind;
    char pad5951[0x3];
    char iconA[0xac];
    char iconB[0x23c];
    char ctx5c3c[0x1200];
    unsigned int randHi;
    unsigned int randLo;
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
    Container020e0310* GetMsgBox() { return &msgBox; }
};

// USA: func_ov026_021d8ba0
extern "C" ARM void func_ov026_021d8ba0(BattleWork* self) {
    char text2[0x80];
    NameBuf fmt2;
    char text[0x80];
    NameBuf fmt;
    char name[12];
    Cmd cmdA;
    Cmd cmdB;
    Cmd cmdC;
    Cmd cmdD;
    Cmd cmdE;
    short list5[8];
    Cmd cmdF;
    Vec3i v;
    unsigned char moved[12];
    unsigned char cells[12][2];
    unsigned char* members[12];
    short ids[12];
    GameState* gs;
    GameResources* res;
    BattleState* battle;
    SlotWork* slot;
    MessageWork* ctrl;
    int* link;
    BackgroundLoader* loader;
    void* slots;
    void* flagWord;
    unsigned char* notify;
    GameObject* member;
    int target;
    int k;
    unsigned char lowX;
    unsigned char highX;
    unsigned char highY;
    unsigned char lowY;
    int n;
    GameState* gs2;
    GameObject* c;
    unsigned char first;
    int g;
    int ownerCount;
    MessageWork* ctrl2;
    char* memberNames;
    char* ownerNames;
    GameState* gs3;
    BattleState* b3;
    PartyState* party;
    int* lnk;
    void** field3704;
    OwnerInfo* owner;
    unsigned char autoMode;

    gs = GameState::GetInstance();
    res = func_ov017_0218b5b0();
    link = func_0202ae18();
    battle = self->battle;
    slot = FindSlotById_021dae60((Container_021dae60*)self->list, GetField0x3acValue_020100a8(gs));
    ctrl = GetGlobalField0x1c020421a0();
    loader = BackgroundLoader::GetInstance();
    slots = GetData02100044_0202ae24();
    flagWord = GetDataPtr02114e04_020d6c00();
    field3704 = (void**)res->unknown_ptr_array_36fc[2];
    notify = GetData02153634_020e3580();

    if (battle == 0 || slot == 0) {
        return;
    }
    if (ClassifyField0x81fe_ov000_0215fc60((char*)battle) != 0 && battle->turns == 2) {
        SetFieldsAndSignalData02184220_ov000_02160d80(self, 4);
        return;
    }
    {
        int mode = battle->turns;
        func_ov026_021d8aac(self, mode, ClassifyField0x81fe_ov000_0215fc60((char*)battle));
    }
    if (res->unknown_flag_42e2 != 0 && loader->GetNumQueuedTasks() == 0) {
        SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x2000000);
        return;
    }

    if (self->state == 0) {
        func_ov000_02181608(self->list);
        MarkSlots0218173c(self->list);
        self->slotsDirty = 0;
        if (GetByte0x63d5_02012060(gs) != 0) {
            PartyState* party = self->party;
            if (party->field0c < 0 && party->field2c == 0) {
                self->state = 6;
                goto state1;
            }
        }
        ((SafeAllocator*)(self->alloc))->Reset();
        GetRowLabels().loadTask = loader->QueueLoadFile(data_ov026_021dedbc, 0);
        self->state = 1;
        if (CheckField0NonZero_0202b7d8(link) && MatchesActiveIndex020a36a8((Combatant020A36A8*)self->party)) {
            InitOverlay17Sub0215e8e8(self->battle);
        }
    }
state1:
    if (self->state == 1) {
        void* file;
        unsigned int len;
        if (!loader->GetTaskStatus(GetRowLabels().loadTask)) {
            return;
        }
        loader->GetLoadedFileByID(GetRowLabels().loadTask, &file, &len);
        ClearFirstTwoWords0209a338((Pair0209a338*)(self->scriptA));
        SetupAndRunBufferedScript0209a470((Ctx0209a470*)(self->scriptA), (SafeAllocator*)(self->alloc), (StreamHeader*)file, len);
        loader->RemoveTask(GetRowLabels().loadTask);
        GetRowLabels().loadTask = -1;
        GetRowLabels().loadTask = loader->QueueLoadFile(data_ov026_021dedd4, 0);
        self->state = 2;
    }
    if (self->state == 2) {
        void* file;
        unsigned int len;
        if (!loader->GetTaskStatus(GetRowLabels().loadTask)) {
            return;
        }
        loader->GetLoadedFileByID(GetRowLabels().loadTask, &file, &len);
        ClearField00209a804((int*)(self->scriptB));
        SetupAndRunBufferedScript0209a8b4((Ctx0209a8b4*)(self->scriptB), (SafeAllocator*)(self->alloc), (StreamHeader*)file, len);
        loader->RemoveTask(GetRowLabels().loadTask);
        GetRowLabels().loadTask = -1;
        self->state = 3;
    }
    if (self->state == 3) {
        int i;
        if (self->fadeActive != 0) {
            ForwardField0xc0_0205eb80(&data_02108760);
            self->fadeActive = 0;
        }
        self->savedWorkFlags = self->workFlags;
        self->fadeTimer = 0;
        self->savedField = GetField0x0((S0204671c*)GetDataPtr02114e04_020d6c00());
        self->cursorLock = 0;
        SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x80000);
        ClearBitsInWord_0203b4b0(&res->brightnessFlags_0, 0x10);
        func_ov000_0218048c(self->list);
        ResetField0x930And0x934_ov000_02180b3c(self->list);
        self->ready = 0;
        self->readyPrev = 0;
        self->phase = 0;
        self->objId = self->objId771e = self->objId7720 = -1;
        self->objId7722 = self->objId7724 = -1;
        {
            int j;
            for (j = 0; j < 4; j++) {
                self->objIds[j] = -1;
            }
        }
        autoMode = 1;
        self->inputOn = 1;
        self->turnCount = battle->turns;
        self->battleKind = battle->kind;
        if (self->dispMode == 2) {
            autoMode = 0;
        }
        ClearBitsInWord_0203b4b0(&res->brightnessFlags_0, 0x800);
        if (GetPtrField612_0216f208(self->view)->count <= 0) {
            self->posInit = 1;
            ClearBitsInField4_0203b4e8(&res->brightnessFlags_0, 0x400);
            InitCombatantPosition_0216118c(self, 1);
        }
        ClearFlagIfParityMismatch02163710_02163710(self, 1);
        RunFlaglearAndSetMode02167e6c_02167e6c((unsigned char*)self);
        {
            Container020d6f44* reactions = GetField02163524(self);
            ResetEntryManager020d6f44(reactions);
            ProcessCombatantReactions020d738c(reactions);
        }
        if (battle->turns > 0) {
            func_ov000_02162cbc(self);
        }
        func_ov000_021626a0(self, 0x26, 0);
        func_ov000_021626a0(self, 0x27, 1);
        ApplyField41ToGatheredCombatants02163a7c((GatherObj02163a7c*)self);
        func_ov000_021629ec(self);
        {
            int i2;
            int dy, dx;
            int j;
            unsigned char* out;
            unsigned char* cell;
            short* id;
            unsigned char** m;

            gs2 = GameState::GetInstance();
            n = 0;
            n = n + func_ov000_0215e9fc(battle, ids, 12, n);
            n = n + func_ov000_0215ec1c(battle, &ids[n], 12 - n, 0);
            lowY = 0;
            highY = 0;
            highX = lowY;
            lowX = lowY;
            k = lowY;
            m = members;
            cell = cells[0];
            id = ids;
            for (; k < n; cell += 2, m++, id++, k++) {
                *m = (unsigned char*)gs2->GetCombatantByIndex(*id);
                if (*m != 0) {
                    int pos = GetSubstructByte0x1c_020493a4(*m);
                    cell[0] = pos % 9;
                    cell[1] = pos / 9;
                    if (cell[0] < 3) lowX = 1;
                    if (cell[0] > 5) highX = 1;
                    if (cell[1] < 3) lowY = 1;
                    if (cell[1] > 5) highY = 1;
                }
            }
            dx = 0;
            dy = dx;
            if (highX != 0 && lowX == 0) dx = -1;
            if (highX == 0 && lowX != 0) dx = 1;
            if (lowY == 0 && highY != 0) dy = -2;
            if (lowY != 0 && highY == 0) dy = 2;
            if (dx != 0 || dy != 0) {
                out = moved;
                cell = cells[0];
                for (i2 = 0; i2 < n; cell += 2, out++, i2++) {
                    *out = (cell[0] + dx) + (cell[1] + dy) * 9;
                    if (*out >= 81) goto shifted;
                }
                out = moved;
                m = members;
                for (j = 0; j < n; m++, out++, j++) {
                    if (*m != 0) {
                        int where;
                        SetSubstructByte0x1c_02049390(*m, *out);
                        where = *out;
                        const Pos2i& p0 = func_ov000_0216f74c(&where);
                        Pos2i pos = p0;
                        v = data_ov026_021de6dc;
                        v.v[0] = pos.x;
                        v.v[2] = pos.z;
                        SetSubstructFields0x10And0x18ClearFlag0x1_02049bd4(*m, v.v);
                    }
                }
            }
        }
    shifted:
        ReinitController02043204((char*)ctrl);
        func_02043124(ctrl);
        func_ov026_021daec8(self->battle, self->view, autoMode);
        {
            BattleState* b2 = self->battle;
            Group* groups;
            int j;
            int count;
            gs3 = GameState::GetInstance();
            ownerNames = self->ownerNames;
            memberNames = self->memberNames;
            groups = b2->groups;
            ctrl2 = GetGlobalField0x1c020421a0();
            count = 0;
            func_ov000_02174614(self->list, -1);
            ReleaseEntriesTwoGroups02174dc0(self->list);
            ownerCount = 0;
            for (g = 0; g < groups->numGroups; g++) {
                first = 0;
                for (j = 0; j < groups[g].count; j++) {
                    c = GetCombatantWithFlag0x400_0200fea4(gs3, groups[g].ids[j] + 0xc0);
                    if (c == 0 || IsFlag10088Set_02010088((S_10088*)c) || IsFlagBit8192Set_021dd3c4((FlagObj_021dd3c4*)c)) {
                        continue;
                    }
                    owner = *(OwnerInfo**)((char*)c + 0x144);
                    if (owner == 0) {
                        continue;
                    }
                    {
                        fmt = data_ov026_021de6f8;
                        func_020e4864((char*)c + 0x14c, fmt.s + 5, 1, 0, 0, 0);
                        __clear(text, sizeof(text));
                        func_02046608(ctrl2, 0xa, fmt.s, text, 0x100, 0, 0);
                        SwapGlobalEntry0203c108((Obj0203c108*)(memberNames + count * 0x18), text);
                    }
                    self->memberRanks[count] = *((unsigned char*)c + 0x17c);
                    self->memberIds[count] = groups[g].ids[j] + 0xc0;
                    if (first == 0) {
                        first = 1;
                        fmt2 = data_ov026_021de778;
                        func_020e4864(owner->name, fmt2.s + 5, 1, 0, 0, 0);
                        __clear(text2, sizeof(text2));
                        func_02046608(ctrl2, 0xa, fmt2.s, text2, 0x100, 0, 0);
                        SwapGlobalEntry0203c108((Obj0203c108*)(ownerNames + ownerCount * 0x18), text2);
                        ownerCount++;
                    }
                    count++;
                }
            }
            SetStoredWorkPtr_ov000_021744f4((int)self->list, (void*)count);
            groups = battle->groups;
            self->groupKind = groups->kind;
        }
        self->resultKind = 0;
        ((Object3D*)(self->iconA))->MakeHidden();
        ((Object3D*)(self->iconB))->MakeHidden();
        ClearCombatWorkFlags0x55f4_ov000_02160fbc(self, 0x20000);
        for (i = 0; i < 4; i++) {
            SlotWork* s = FindSlotById_021dae60((Container_021dae60*)self->list, i);
            if (s != 0) {
                func_ov000_0217f518(s);
            }
        }
        func_ov000_02162c14(self, GetField0x3acValue_020100a8(gs), &self->cmd);
        func_ov000_0217fa60(self->list);
        ClearFlag0x43e02176054(self->list);
        func_ov000_02175258(self->list);
        func_ov000_02174c14(self->list);
        func_ov000_021814bc(self->list);
        self->uiFlags &= ~0x600;
        if (ClassifyField0x81fe_ov000_0215fc60((char*)battle) != 0) {
            self->versusFlag = 1;
        }
        {
            PartyState* pty;
            int i;
            b3 = self->battle;
            pty = self->party;
            for (i = 0; i < 4; i++) {
                if (TestBitAt0x34_020a35e0((unsigned char*)pty, i)) {
                    func_ov026_021dc8fc(self, b3, pty, self->list, self->scriptA, self->scriptB, i);
                }
            }
        }
        for (i = 0; i < 4; i++) {
            void* p;
            if (!TestBitAt0x34_020a35e0((unsigned char*)self->party, i)) continue;
            member = GetCombatantWithFlag0x100_0200ff1c(gs, i);
            if (member == 0) continue;
            p = GetField0x19cOrNull((S02053dc0*)member);
            if (p != 0) {
                memset(p, 0, 6);
            }
            self->curSlot = self->activeSlot;
            if (IsFlag10088Set_02010088((S_10088*)member)) continue;
            SetByte0xbeShiftPrev((Bytes02033b88*)member, 0);
        }
        if (battle->turns == 0 && self->battle->kind == 2) {
            Process02181364(self->list);
            func_ov000_0217fcc4(self->list, -1);
            self->inputOn = 0;
        }
        if (ClassifyField0x81fe_ov000_0215fc60((char*)battle) != 0) {
            if (func_0202c540(link) != 0) {
                Process02181364(self->list);
                func_ov000_0217fcc4(self->list, -1);
                ClearFlag_021816e8_021816e8(self->list, -1);
                SetFlag_02181694_02181694(self->list, 0);
                self->inputOn = 0;
            } else {
                for (i = 1; i < 4; i++) {
                    SlotWork* s = FindSlotById_021dae60((Container_021dae60*)self->list, i);
                    if (s != 0) {
                        ClearByteField_0217f5d0_0217f5d0(s);
                        s->cmds[s->cursor] = 100;
                    }
                }
            }
        }
        if (MatchesActiveIndex020a36a8((Combatant020A36A8*)self->party)) {
            SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x40000000);
        }
        if (((SafeAllocator*)self->cmdAlloc)->GetSignedAllocator() == 0) {
            ((SafeAllocator*)self->cmdAlloc)->CreateTypeA(((SafeAllocator*)(self->alloc))->Allocate(0x16000), 0x16000);
            CopyState0207dfc8((State0207dfc8*)(self->stateA), (State0207dfc8*)(self->stateB));
        }
        self->state = 0xe;
        {
            Roster* roster = (Roster*)GetPtrField0x2a04_02010828(gs);
            unsigned char m;
            for (m = 0; m < roster->count; m++) {
                if (self->slotsDirty != 0) {
                    SlotWork* s = FindSlotById_021dae60((Container_021dae60*)self->list, m);
                    if (s != 0) {
                        func_ov000_0217f518(s);
                    }
                }
                func_ov000_02162c14(self, roster->ids[m], &cmdA);
                func_ov017_021c6814(self->party->netId, roster->ids[m], &cmdA, 0, -1, 0);
            }
        }
    }
    if (self->state == 0xe) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->turnFlag, 1) != 0) {
            return;
        }
        if (GetCombatWorkFlags0x55f4_ov000_02160fd4(self, 0x40000000) != 0) {
            if (self->slotsDirty != 0) {
                int i;
                for (i = 0; i < 4; i++) {
                    SlotWork* s = FindSlotById_021dae60((Container_021dae60*)self->list, i);
                    if (s != 0) {
                        func_ov000_0217f518(s);
                    }
                }
                self->slotsDirty = 0;
            }
            EnqueueEventTag89_021ca174(self->party->netId);
            self->state = 0x11;
            func_ov017_021c847c();
        }
    }
    if (self->state == 0x11) {
        int online;
        TagValueEntry020e385c* tags;
        online = battle->netInfo->state >= 0 ? 1 : 0;
        ctrl->flag19af = 0;
        ctrl->flag19ca = 0;
        tags = GetData02153660_020e3808();
        if (!online || (IsEntryCompleteOrMissing020e3ad0(tags, 1, -1) && online)) {
            unsigned char* entry = FindEntryByTagAndValue(tags, 1, -1);
            int mine = 0;
            int all;
            if (entry != 0 && (entry[5] & (1 << GetField0x3acValue_020100a8(gs)))) {
                mine = 1;
            }
            all = 0;
            if (entry != 0 && (entry[5] & self->party->memberMask) == entry[5]) {
                all = 1;
            }
            if (all || !mine || !entry) {
                ReinitController02043204((char*)ctrl);
                self->state = 4;
                ResetTaggedEntryAndNotifyOverlay020e3994(tags, 1, -1);
                return;
            }
        }
        if (((POWCNT & 0x8000) >> 15) == 1 && (IsChannelValueZero0203b5e0(res, 0) || IsChannelValueZero0203b5e0(res, 1)) && self->phase == 0) {
            SetBrightness(res, 0, 0xf);
            if (ctrl->busy == 0) {
                void* work = GetGlobalField0x1c020421a0()->scriptWork;
                memset(work, 0, 0x960);
                func_020dd0b0(0, work);
                func_0204500c(ctrl, work, 0, 0xe3);
                ctrl->busy = 1;
            }
        }
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->turnFlag, 1) != 0) {
            return;
        }
        if (func_ov026_021d8a40() && IsField0Null_02046b08(field3704) && TestBitAt0x34_020a35e0((unsigned char*)self->party, self->party->myIndex)) {
            func_ov026_021dce34(-1, self, self->battle, self->party, self->list, self->ctxEc8, self->ctx5c3c, self->ctx5728, self->scriptA, self->scriptB, self->ctx5910, self->view);
        }
    }
    if (self->state == 4) {
        int revived;
        int i;
        if (((POWCNT & 0x8000) >> 15) == 1 && (IsChannelValueZero0203b5e0(res, 0) || IsChannelValueZero0203b5e0(res, 1)) && self->phase == 0) {
            SetBrightness(res, 0, 0xf);
            func_ov026_021dd8a8(battle, self->party);
            self->revivePending = 0;
        } else if (self->revivePending != 0) {
            func_ov026_021dd8a8(battle, self->party);
            self->revivePending = 0;
        }
        if (self->inputOn & (ctrl->busy == 0)) {
            func_ov000_0217fbf4(self->list, -1);
            self->inputOn = 0;
        }
        UpdateFieldIfDiffers_02174514_02174514(self->list);
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->turnFlag, 1) != 0) {
            return;
        }
        {
            GameState* gs5;
            int i;
            int n5;
            short list4[8];
            target = -1;
            memset(list4, target, sizeof(list4));
            n5 = func_ov000_0215eb1c(battle, list4, 8, 0);
            gs5 = GameState::GetInstance();
            for (i = 0; i < n5; i++) {
                GameObject* c = GetCombatantWithFlag0x400_0200fea4(gs5, list4[i]);
                if (c != 0) {
                    ModifiableCombatStats* stats = c->currentStats_;
                    if ((*(int*)&stats->unk1[4] & 0x1000) && GetCombatantWithFlag0x100_0200ff1c(gs5, *(short*)&stats->unk1[0x1a]) == 0) {
                        target = list4[i];
                        ClearFlag0x1000AndBytes7eA1_02088e64((unsigned char*)c->currentStats_);
                        revived = 1;
                        goto checked;
                    }
                }
            }
            revived = 0;
        }
    checked:
        if (revived) {
            MessageWork* msg = GetGlobalField0x1c020421a0();
            Container020e0310* box = self->GetMsgBox();
            GameObject* c = GetCombatantWithFlag0x400_0200fea4(gs, target);
            void* text = GetFieldByKey020e0434(box, 0x28);
            if (text != 0 && c != 0) {
                func_02046380(msg);
                SetIndexedName02046574((Obj02046574*)msg, 0, (char*)c + 0x14c);
                func_020e4ce8(name, (char*)c, 1);
                msg->namePtr = name;
                func_0204500c(msg, text, 0, 0xe3);
                msg->busy = 1;
                self->state = 0xf;
                return;
            }
        }
        if (func_ov026_021d8a40() && IsField0Null_02046b08(field3704) && TestBitAt0x34_020a35e0((unsigned char*)self->party, self->party->myIndex)) {
            func_ov026_021dce34(-1, self, self->battle, self->party, self->list, self->ctxEc8, self->ctx5c3c, self->ctx5728, self->scriptA, self->scriptB, self->ctx5910, self->view);
        }
        if (battle->field8e47 == 0) {
            if (TestFlags02046708((FlagWord02046708*)flagWord, 0x200) == 0) {
                int turns = battle->turns;
                int kind = battle->kind;
                int set = 1;
                if (turns == 0 && kind == 2) {
                    set = 0;
                }
                if (set) {
                    OrBitsIntoField0_020466e4((unsigned int*)flagWord, 0x200);
                }
            }
            if (MatchesActiveIndex020a36a8((Combatant020A36A8*)self->party) && GetByte2IfGlobalFlagSet_020e37e8(notify)) {
                ClearBitOrNotifyOverlay020e3798(notify);
            }
        }
        func_ov000_0216258c(self);
        {
            int me = (signed char)GetField0x3acValue_020100a8(gs);
            int redo = 0;
            int changed = redo;
            int locked = redo;
            if (CheckField0NonZero_0202b7d8(link) && battle->turns == 0 && self->battle->kind == 2) {
                if (ctrl->busy != 0) {
                    locked = 1;
                }
            }
            if (locked == 0) {
                if (self->slotDone[me] != (CountUnder100Flags0217fb98(self->list) == 0)) {
                    changed = 1;
                }
                SetBoundedArrayField0x4f4_ov000_02162c90((char*)self, me, CountUnder100Flags0217fb98(self->list) == 0);
            }
            func_ov026_021db3d8(self);
            if (MatchesActiveIndex020a36a8((Combatant020A36A8*)self->party)) {
                party = self->party;
                redo = 1;
                lnk = func_0202ae18();
                if (CheckField0NonZero_0202b7d8(lnk)) {
                    for (i = 0; i < 4; i++) {
                        if (TestBitAt0x34_020a35e0((unsigned char*)party, i) && TestBitBySignedByteIndex_0202c1c0((SearchStruct*)lnk, i)) {
                            redo = (redo & self->slotDone[i]) ? 1 : 0;
                        }
                    }
                } else if (self->slotDone[0] == 0) {
                    redo = 0;
                }
            } else if (self->resultKind != 0) {
                redo = 1;
            }
            if (redo) {
                func_ov000_0217fcc4(self->list, -1);
            }
            if (GetByteField_02168720_02168720((char*)self) > 0 || ctrl->busy != 0) {
                redo = 0;
            }
            if (redo && CheckField0NonZero_0202b7d8(link) && MatchesActiveIndex020a36a8((Combatant020A36A8*)self->party)) {
                if (func_ov026_021d8a40() == 0) {
                    redo = 0;
                }
            }
            if (CheckField0NonZero_0202b7d8(link)) {
                int cur = self->curSlot;
                int valid = 0;
                int sel;
                if (cur >= 0) {
                    valid = cur <= 3;
                }
                if (valid) {
                    int differs;
                    func_ov000_02162c14(self, cur, &cmdB);
                    differs = !(cmdB.b[0] == self->cmd.b[0] && cmdB.b[1] == self->cmd.b[1] && cmdB.b[2] == self->cmd.b[2] &&
                                cmdB.b[3] == self->cmd.b[3] && cmdB.d == self->cmd.d && cmdB.e == self->cmd.e && cmdB.c == self->cmd.c);
                    if (differs || changed) {
                        func_ov017_021c6814(self->party->netId, self->curSlot, &cmdB, self->slotDone[me], -1, 0);
                        self->cmd.b[0] = cmdB.b[0];
                        self->cmd.b[1] = cmdB.b[1];
                        self->cmd.b[2] = cmdB.b[2];
                        self->cmd.b[3] = cmdB.b[3];
                        self->cmd.c = cmdB.c;
                        self->cmd.d = cmdB.d;
                        self->cmd.e = cmdB.e;
                        if (func_0202c508(link) != 0 && ((cmdB.b[0] == 100 && cmdB.b[1] == 6) || cmdB.b[0] == 0xd)) {
                            Roster* roster = (Roster*)GetPtrField0x2a04_02010828(gs);
                            int m;
                            for (m = 0; m < roster->count; m++) {
                                if (self->curSlot == m) continue;
                                func_ov000_02162c14(self, roster->ids[m], &cmdC);
                                func_ov017_021c6814(self->party->netId, roster->ids[m], &cmdC, self->slotDone[me], -1, 0);
                            }
                        }
                    }
                }
                sel = self->activeSlot;
                if (self->curSlot != sel) {
                    self->curSlot = sel;
                    if (IsValidSlot(sel)) {
                        func_ov000_02162c14(self, sel, &cmdD);
                        func_ov017_021c6814(self->party->netId, sel, &cmdD, self->slotDone[me], -1, 0);
                    }
                }
            }
            if (redo && (self->uiFlags & 0x200)) {
                if (self->slotStatus[self->slotCursor] == 100) {
                    func_ov000_02175be4(self->list);
                    self->uiFlags &= ~0x200;
                    self->uiFlags |= 0x400;
                    self->cursorLock = 0;
                }
                self->slotsDirty = 1;
                redo = 0;
            }
            func_ov026_021db5a4(self);
            if ((self->uiFlags & 0x200) || self->phase > 0) {
                redo = 0;
            }
            if (self->reinitFlag != 0 && self->phase == 0) {
                func_ov026_021dbba8(self);
                InitCombatantPosition_0216118c(self, 0);
            }
            self->ready = redo ? 1 : 0;
            if (redo) {
                ClearSlotBitndSetByte_021813d4(self->list);
                func_ov000_0217fcc4(self->list, -1);
                func_ov000_0217457c(self->list, -1);
                if (self->phase == -1) {
                    self->fadeTimer = 60;
                    ForwardField0xc0_0205eb80(&data_02108760);
                    self->fadeActive = 0;
                    SetForwardAndStore0205eb54(&data_02108760, 0x1b3, 0x1b3);
                    DispatchIfField0xc4NonNeg_0205eb90(&data_02108760, 0, 0);
                    self->fadeActive = 1;
                }
                {
                    Object3D* o;
                    int i;
                    for (i = 0; i < 4; i++) {
                        o = (Object3D*)gs->GetGameObjectByIndex(self->objIds[i]);
                        if (o != 0) {
                            o->StopCurrentAnimation();
                            o->MaybeSetRegularAnimation(data_ov026_021dedec, 1);
                        }
                    }
                }
                ClearCombatWorkFlags0x55f4_ov000_02160fbc(self, 0x40000000);
                if (!CheckField0NonZero_0202b7d8(link)) {
                    Random* rnd;
                    self->resultKind = func_ov026_021dd3dc(self->battle, self->party, self->list);
                    rnd = &self->battle->rng;
                    self->randHi = GetRandomStateHi(rnd);
                    self->randLo = GetRandomStateLo(rnd);
                    self->state = 5;
                } else {
                    int all;
                    int i;
                    if (self->reinitFlag == 0) {
                        RunFlaglearAndSetMode02167e6c_02167e6c((unsigned char*)self);
                    }
                    func_ov026_021daec8(battle, func_ov000_02160f14(self), 0);
                    if (MatchesActiveIndex020a36a8((Combatant020A36A8*)self->party)) {
                        self->resultKind = func_ov026_021dd3dc(self->battle, self->party, self->list);
                        EnqueueEventTag108_021cefe0(self->party->netId, self->resultKind, self->turnFlag);
                        SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x800000);
                    }
                    if (TestFlags02046708((FlagWord02046708*)flagWord, 0x200)) {
                        SetBitOrNotifyOverlay020e36f0(notify);
                    }
                    self->state = 0x12;
                    func_ov017_021c894c(self->party->netId);
                    func_ov017_021c8758(self->party->netId);
                    func_ov017_021c8654();
                    func_ov017_021c847c();
                    all = 1;
                    for (i = 0; i < 4; i++) {
                        GameObject* c;
                        if (TestBitAt0x34_020a35e0((unsigned char*)self->party, i) && (c = gs->GetCombatantByIndex(i)) != 0) {
                            if (IsFlag10088Set_02010088((S_10088*)c) == 0) {
                                all = 0;
                            }
                        }
                    }
                    if (all) {
                        battle->result = 2;
                        SetFieldsAndSignalData02184220_ov000_02160d80(self, 0xa);
                    }
                }
            }
        }
    } else if (self->state == 0x12) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->turnFlag, 0) != 0) {
            return;
        }
        if (GetByte2IfGlobalFlagSet_020e37e8(notify) != 0 || TestFlags02046708((FlagWord02046708*)flagWord, 0x200) == 0) {
            ClearFlags020466f4((FlagWord020466f4*)flagWord, 0x200);
            if (MatchesActiveIndex020a36a8((Combatant020A36A8*)self->party)) {
                self->state = 8;
            } else {
                self->state = 0xa;
            }
        }
    } else if (self->state == 8) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->turnFlag, 0) != 0) {
            return;
        }
        if (CheckSlotsAllFree0205e488(slots)) {
            int i;
            for (i = 0; i < 4; i++) {
                if (TestBitAt0x34_020a35e0((unsigned char*)self->party, i)) {
                    GetCombatantWithFlag0x1000_0200ff58(gs, i);
                    func_ov000_02162c14(self, i, &cmdE);
                    func_ov017_021c6814(self->party->netId, i, &cmdE, 1, -1, 1);
                }
            }
            self->state = 9;
        }
    } else if (self->state == 9) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->turnFlag, 0) != 0) {
            return;
        }
        if (CheckSlotsAllFree0205e488(slots)) {
            Random* rnd = &self->battle->rng;
            self->randHi = GetRandomStateHi(rnd);
            self->randLo = GetRandomStateLo(rnd);
            EnqueueEventTag109_021cf650(self->party->netId, self->randHi, self->randLo);
            self->state = 0xb;
        }
    } else if (self->state >= 0xb && self->state <= 0xd) {
        if (self->state == 0xd) {
            self->state = 5;
        } else {
            self->state = self->state + 1;
        }
    } else if (self->state == 0xa) {
        if (func_ov026_021ddd84(res, self, self->battle, self->party, self->list, &self->turnFlag, 0) != 0) {
            return;
        }
        if (GetCombatWorkFlags0x55f4_ov000_02160fd4(self, 0x20000)) {
            self->state = 5;
        }
    } else if (self->state == 5) {
        int i;
        if (CheckField0NonZero_0202b7d8(link) && link[0xfc0 / 4] != 0) {
            return;
        }
        if (self->fadeActive != 0 && self->fadeTimer != 0) {
            return;
        }
        if (self->turnFlag != 0) {
            int n = func_ov000_0215ec1c(battle, list5, 8, 0);
            int i;
            for (i = 0; i < n; i++) {
                GameObject* c = GetCombatantWithFlag0x400_0200fea4(gs, list5[i]);
                if (c != 0) {
                    ModifiableCombatStats* stats = c->currentStats_;
                    stats->primaryStats.currHP = stats->primaryStats.maxHP;
                }
            }
            self->turnFlag = 0;
        }
        if (self->phase == -1) {
            for (i = 0; i < 4; i++) {
                if (gs->GetGameObjectByIndex(self->objIds[i]) != 0) {
                    return;
                }
            }
            func_ov026_021dbba8(self);
        }
        ((SafeAllocator*)self->cmdAlloc)->Destroy();
        self->reinitFlag = 0;
        func_02057f00(func_02057924(), 0x13);
        if (IsField0Null_02046b08((void**)res->unknown_ptr_array_36fc[1]) == 0) {
            return;
        }
        SetBitsInWord_0203b4a0(&res->brightnessFlags_0, 0x10);
        memset(self->slotDone, 0, 0x10);
        self->party->field30 = 0;
        ClearCombatWorkFlags0x55f4_ov000_02160fbc(self, 0x4000000);
        ClearCombatWorkFlags0x55f4_ov000_02160fbc(self, 0x8000000);
        ClearCombatWorkFlags0x55f4_ov000_02160fbc(self, 0x10000000);
        ClearCombatWorkFlags0x55f4_ov000_02160fbc(self, 0x20000000);
        {
            Object3D* o;
            int i;
            for (i = 0; i < 4; i++) {
                if (TestBitAt0x34_020a35e0((unsigned char*)self->party, i)) {
                    func_ov000_02162c14(self, i, &cmdF);
                    o = (Object3D*)gs->GetGameObjectByIndex(i);
                    if (o != 0) {
                        o->DisableFlag(0x1000);
                    }
                }
            }
        }
        {
            PartyState* party = self->party;
            int r;
            Roster* roster;
            gs = GameState::GetInstance();
            for (i = 0; i < 4; i++) {
                GameObject* c;
                if (TestBitAt0x34_020a35e0((unsigned char*)party, i) && (c = GetCombatantWithFlag0x100_0200ff1c(gs, i)) != 0) {
                    IncrementCounterUnlessFlagged_02053dd0((IncObj*)c);
                }
            }
            roster = (Roster*)GetPtrField0x2a04_02010828(gs);
            if (roster != 0) {
                for (r = 0; r < roster->count; r++) {
                    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, roster->ids[r]);
                    if (c != 0 && IsFlag10088Set_02010088((S_10088*)c) == 0) {
                        self->reviveCount++;
                        break;
                    }
                }
            }
        }
        func_ov000_02168144(self);
        ClearFirstTwoWords0209a338((Pair0209a338*)(self->scriptA));
        ((SafeAllocator*)(self->alloc))->Reset();
        self->field55d8 = 0;
        func_ov000_0215d588(battle);
        if (CheckField0NonZero_0202b7d8(link) && GetByte2IfGlobalFlagSet_020e37e8(notify)) {
            ClearBitOrNotifyOverlay020e3798(notify);
        }
        if (self->resultKind == 1) {
            func_ov000_02160da0(self);
        } else {
            SetFieldsAndSignalData02184220_ov000_02160d80(self, 0xb);
        }
    } else if (self->state == 6) {
        if (loader->GetNumQueuedTasks() > 0) {
            return;
        }
        ResetTwoFields021637c8(self);
        func_ov026_021dc440((SafeAllocator*)(self->alloc), self, self->battle, self->party, 0);
        func_ov026_021dc040((SafeAllocator*)(self->alloc), self, self->battle, self->party);
        func_ov000_02163894(self);
        self->state = 7;
    } else if (self->state == 7) {
        func_ov000_02163928(self);
        if (func_ov026_021dc040((SafeAllocator*)(self->alloc), self, self->battle, self->party) != 0) {
            self->state = 0;
        }
    }
    if (self->state == 0xf && GetGlobalField0x1c020421a0()->busy == 0) {
        self->state = 4;
    }
}
