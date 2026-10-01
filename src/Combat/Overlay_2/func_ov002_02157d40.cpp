#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct TableEntry {
    char* name;
    int unk4;
    unsigned int lo8 : 8;
    unsigned int b8 : 2;
    unsigned int b10 : 2;
    unsigned int rest : 20;
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
extern "C" void* _Z17GetPtrField0x2a04P9GameState(struct BattleStruct* battleStruct);
extern "C" struct CombatantStruct* _Z25GetCombatantWithFlag0x100P9GameStatei(struct BattleStruct* battleStruct, int combatantId);
extern "C" struct BattleStruct* _ZN9GameState11GetInstanceEv();

struct Container020e0310;
struct StoreStruct;
struct Struct02048448;
struct Struct020a8170 {
    char pad[0xc];
    unsigned short count;
};
struct Struct0201bc94;
struct Obj020541a4;
struct Obj02046574;
struct Obj0205eaa0;
struct Obj02048350;
struct List02046a3c;
struct Node02046a3c;
struct List02026a28;
struct List02026abc;
struct Obj021c2744;
struct Obj021c2b28;

extern "C" void* __clear(void* dst, int count);
extern "C" void* func_02012fe4(void);
void* GetData02108e10(void);
void* GetData02153637(void);
extern "C" void* _Z24SearchBothTables02079e2cPci(char* p, int key);
extern "C" void* func_0202ae18(void);
int GetTableValue(void* p);
void SetByteInRange(unsigned char* p, int a, unsigned char b);
extern "C" void _Z15InitObj021c2b28Pvhh(void* p, unsigned char a, unsigned char b);
extern "C" void _Z16Dispatch020e3428Pvi(void* p, int flag);
extern "C" int _Z17IsInRange0201b588i(int v);
extern "C" int _Z17IsInRange0201b5b0i(int v);
extern "C" void _Z17NotifySub020541a4P11Obj020541a4h(struct Obj020541a4* p, unsigned char b);
void StoreInArray0x8b0(struct StoreStruct* p, int a, int b);
int CheckField0NonZero(int* p);
void* LoadFileIntoMemory(const char* path, void* buf, unsigned int* outSize);
void TryClearFlags0x130(unsigned char* p, unsigned short mask);
extern "C" void _Z19ClearStruct020a8170P14Struct020a8170(struct Struct020a8170* p);
int CopyOutRegion0x571d(char* dst, void* src);
int GetByteFieldAt0x9ba(unsigned char* p);
void InsertNodeAfterHead(struct List02046a3c* list, struct Node02046a3c* node);
extern "C" void _Z20AppendString02042058PcPKc(char* dst, const char* src);
extern "C" void _Z20ClearRecords02026644Pc(char* p);
extern "C" void _Z20InitState69_021c2744P11Obj021c2744(struct Obj021c2744* p);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" void _Z22Clear0x54Bytes0208247cPv(void* p);
extern "C" void _Z22ConsumeCounter02048350P11Obj02048350i(struct Obj02048350* p, int a);
extern "C" void _Z22InitStateArray02157ce0Pc(char* p);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(struct Obj02046574* p, int a, char* s);
int CountEntriesByField0x8c(struct List02026a28* p);
int CountEntriesByField0x8e(struct List02026abc* p);
extern "C" void _Z23InitByteHeader_021c2688Ph(unsigned char* p);
extern "C" void _Z24SetFlagsAndReset02026678Pc(char* p);
extern "C" struct CombatantStruct* _ZN9GameState20GetUnknownGameObjectEv(struct BattleStruct* bs);
extern "C" struct CombatantStruct* _ZN9GameState21GetPartyMemberByIndexEi(struct BattleStruct* bs, int id);
int IsEntryEligibleAndFlagged(struct Struct0201bc94* p);
extern "C" void _Z26EnqueueEventTag34_021d27a0hhh(int a, int b, int c);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z26InitAndInsertNode_021acd30Pchhh(char* p, unsigned char a, unsigned char b, unsigned char c);
extern "C" int _Z28CountMatchingEntries02026a78Pc(char* p);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* p, int a, int b);
extern "C" void _Z28InitObjFromCombatant020e4c74PvP10GameObject(void* p, struct CombatantStruct* c);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void* p, int a);
extern "C" int _Z32ClampAndCompareThreshold02048448P14Struct02048448i(struct Struct02048448* p, int a);

extern "C" void _ZN13SafeAllocator5ResetEv(void* self);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* self, unsigned int size);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv(void);

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void* memset(void* dst, int v, unsigned int n);
extern "C" int sprintf(char* buf, const char* fmt, ...);

int GetWord0x0(int* obj);

extern "C" int func_02026780(void* list, void* buf, unsigned int size);
extern "C" int func_0202c540(void* p);
extern "C" void func_02046380(void* obj);
extern "C" void func_02046608(void* obj, int a, int b, char* buf, int c, int d, int e);
extern "C" void func_02052d7c(void* obj, signed char idx, int flag);
extern "C" void func_0207c378(void* p, short val, int flag, unsigned int nibble);
extern "C" void func_02082490(void* obj, void* addr, unsigned int size, int val, int extra);
extern "C" void func_020a818c(void* p, void* allocator);
extern "C" void func_020a8304(void* p);
extern "C" void func_ov002_021536e0(void* p);
extern "C" int func_ov002_021536ec(void* a, void* b, int c);
extern "C" void func_ov002_0216c42c(void* ctx, void* buf, void* entry);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_0218f5a4(void* obj, int id, int b, int c, int d);
extern "C" int func_ov017_0219ff58(int a, int b, int c, int d);
extern "C" int func_ov017_021ab860(signed char a);
extern "C" void func_ov017_021c12fc(void* a, int b, int c);
static inline short* ListField22(char* obj) {
    int* list = *(int**)(obj + 0x3000 + 0x71c);
    return (short*)((char*)list + 0x22);
}
extern "C" void func_ov017_021c3fb4(signed char a, int b);
extern "C" void func_ov017_021c4418(signed char a, int b);
extern "C" void func_ov017_021c9e00(signed char a, int b, int c, int d);

extern int data_02108760;
extern unsigned char data_ov002_0216c992;
extern int data_ov002_0216cf51;
extern int data_0211e33c;
extern int data_ov002_0216cf66;

struct Status56b {
    unsigned char lo : 4;
    unsigned char hi : 4;
};
struct SkillSlot {
    int unk0;
    int unk4;
    unsigned int lo4 : 4;
    unsigned int mid : 14;
    unsigned int on : 1;
    unsigned int rest : 13;
    int unkc;
    int unk10;
    int unk14;
    short value;
    short pad1a;
    int pad1c;
};
struct UnitExt {
    char pad0[0x138];
    int limits[0x17];
    struct SkillSlot slots[11];
    char pad2f4[0x277];
    struct Status56b status;
    char pad56c[0x3e4];
    int level;
};
struct Unit {
    unsigned short flags;
    short unk2;
    short id;
    char pad6[0x12a];
    int* status;
    char* name;
    char pad138[0x18];
    struct UnitExt* ext;
};
struct PartyList {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};
struct BattleMenu {
    char pad0[8];
    char obj8[0xc];
    char obj14[0xc];
    char container20[0x880];
    char alloc8a0[0x1318];
    int state;
    int nextState;
    int timer;
    char pad1bc4[0xc];
    char* text;
    char* textCopy;
    char pad1bd8[0x48];
    signed char actor;
    signed char target;
    char pad1c22[4];
    short command;
    short msgId;
    short msgId2;
    char pad1c2c[5];
    unsigned char dirty;
    char pad1c32[6];
    int excludeCount;
    int exclude[0xe];
    int wait;
    char pad1c78[2];
    unsigned char waitMode;
    unsigned char waitKind;
    char pad1c7c[0x4a];
    unsigned char cc6;
    unsigned char cc7;
    char stateArray[0x3c];
    char pad1d04[0x770];
    struct Struct020a8170* anim;
    char pad2478[0x10];
    short prompt;
    unsigned char showPrompt;
    unsigned char f248b;
    unsigned char f248c;
    char pad248d[3];
    int countA;
    int countB;
    char pad2498[0x8a];
    unsigned char f2522;
    unsigned char f2523;
    char buf2524[0xc];
    int f2530;
};
struct StateSlot {
    unsigned char a[4];
    unsigned char active;
    unsigned char pad;
};
struct StateArray {
    short id;
    signed char actor;
    unsigned char count;
    signed char ids[4];
    struct StateSlot first[4];
    struct StateSlot second[4];
    int tail;
};
struct Table11 {
    signed char v[11];
};
struct Frame {
    void* ctx44;
    void* ctx48;
    unsigned int size4c;
    unsigned int size50;
    unsigned char ids54[4];
    void* ctx58;
    unsigned char ids5c[4];
    struct Table11 tab;
    struct StateArray st6c;
    struct StateArray sta8;
    char path[0x28];
    struct StateArray st10c;
    int obj148[0x15];
};

struct Hdr1c00 {
    char pad0[0x20];
    signed char actor;
    signed char target;
    char pad22[4];
    short command;
    short msgId;
    short msgId2;
};
static inline struct Hdr1c00* Hdr(struct BattleMenu* p) {
    struct Hdr1c00* h = (struct Hdr1c00*)((char*)p + 0x1c00);
    return h;
}
static inline short* Msg2Ptr(struct BattleMenu* p) {
    short* m = &p->msgId2;
    return m;
}
static inline signed char* ActorPtr(struct BattleMenu* p) {
    signed char* a = &p->actor;
    return a;
}
static inline short* CmdPtr(struct BattleMenu* p) {
    short* c = &p->command;
    return c;
}

static inline int CurLimit(struct UnitExt* e) {
    return e->limits[e->level];
}

static inline int UnitId(struct Unit* u) { int id = u->id; return id; }
static inline char* UnitName(struct Unit* u) { char* name = u->name; return name; }
enum MsgKey { MSG_KEY_NONE = -1, MSG_KEY_DEAD = 0x232c, MSG_KEY_ALIVE = 0x233a };

// USA: func_ov002_02157d40
extern "C" ARM void func_ov002_02157d40(struct BattleMenu* p) {
    struct Frame f;
    char* tbl;
    struct BattleStruct* gs = _ZN9GameState11GetInstanceEv();
    int word = GetWord0x0((int*)gs);
    unsigned short* obj = (unsigned short*)func_02012fe4();
    tbl = (char*)GetData02108e10();
    struct TableEntry* entryA = (struct TableEntry*)_Z24SearchBothTables02079e2cPci(tbl, p->command);
    struct Unit* comb = (struct Unit*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, p->actor);
    int* checkPtr = (int*)func_0202ae18();
    int flagA = 0;
    int flagB;
    bool flag1c;

    if (p->state == 0x11) {

        p->msgId = 0x232d;
        p->msgId2 = -1;
        flagB = 0;
        flag1c = 0;
        if (p->command == 0xd7) {
            p->msgId = 0x233b;
        }
        if (_Z32ClampAndCompareThreshold02048448P14Struct02048448i((struct Struct02048448*)comb, (unsigned short)entryA->lo8) == 0) {
            p->msgId = 0x232f;
            p->msgId2 = -1;
            p->showPrompt = 0;
            p->prompt = -1;
            p->state = 0x26;
            p->nextState = 0x11;
            return;
        }
        if (p->command == 0xd7) {
            flagA = 1;
            flagB = 1;
            char* ov = (char*)func_ov017_0218b5b0();
            *ListField22(ov) = p->actor;
            func_ov017_021c12fc(ov, 1, 0);
        } else if (p->command == 0xd9) {
            flagA = 1;
            if (IsEntryEligibleAndFlagged((struct Struct0201bc94*)func_02012fe4()) != 0) {
                func_ov016_0218b5c0(0, -1);
                p->target = p->actor;
                p->msgId = 0x754a;
                flagB = 1;
                struct PartyList* party = (struct PartyList*)_Z17GetPtrField0x2a04P9GameState(gs);
                for (int i = 0; i < party->count; i++) {
                    _Z17NotifySub020541a4P11Obj020541a4h((struct Obj020541a4*)_ZN9GameState21GetPartyMemberByIndexEi(gs, party->ids[i]), 0);
                }
            } else {
                p->msgId = 0x754e;
                p->showPrompt = 1;
                p->prompt = 0x754f;
                flagA = 0;
            }
        } else if (p->command == 0xcd) {
            Hdr(p)->msgId2 = -1;
            p->showPrompt = 1;
            int r = func_ov017_021ab860(p->actor);
            if (r == 0) {
                p->prompt = 0x232b;
            } else if (r == 1) {
                p->prompt = 0x2338;
            } else if (r == 3) {
                p->msgId = 0x233c;
                p->target = p->actor;
                flagB = 1;
                p->showPrompt = 0;
                flagA = 1;
                p->prompt = -1;
            }
        } else if (p->command == 0x1e || p->command == 0x1f || p->command == 0x20 || p->command == 0x21 || p->command == 0x23 || p->command == 0x26 || p->command == 0x27) {
            p->state = 7;
            flag1c = 1;
        } else if (p->command == 0x22 || p->command == 0x310) {
            _Z22InitStateArray02157ce0Pc((char*)&f.st10c);
            _Z22InitStateArray02157ce0Pc((char*)&f.st10c);
            int res = 0;
            struct TableEntry* entry = (struct TableEntry*)_Z24SearchBothTables02079e2cPci(tbl, p->command);
            if (entry != 0) {
                __clear(f.ids5c, 4);
                int n = CopyOutRegion0x571d((char*)gs, f.ids5c);
                if (entry->b10 & 1) {
                    func_ov016_0218b5c0(0, -1);
                    f.st10c.id = p->command;
                    f.st10c.actor = p->actor;
                    f.st10c.count = n;
                    for (int i = 0; i < n; i++) {
                        f.st10c.ids[i] = f.ids5c[i];
                    }
                    func_ov002_021536e0(&f.ctx58);
                    f.ctx58 = tbl;
                    res = func_ov002_021536ec(&f.ctx58, &f.st10c, 0);
                }
                int found = 0;
                struct StateSlot* first = f.st10c.first;
                struct StateSlot* second = f.st10c.second;
                int i;
                for (i = 0; i < f.st10c.count; i++) {
                    struct StateSlot* a = &first[i];
                    struct StateSlot* b;
                    if (a->active != 0 || (b = &second[i])->active != 0) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    func_ov002_0216c42c(p, &f.st10c, entry);
                    p->cc6 = 0;
                    p->cc7 = 1;
                    _Z22InitStateArray02157ce0Pc((char*)(p->stateArray));
                    memcpy(p->stateArray, &f.st10c, 0x3c);
                    p->msgId = -1;
                    p->msgId2 = -1;
                    p->state = 0x26;
                    p->nextState = 0x26;
                    p->prompt = -1;
                    p->showPrompt = 0;
                    p->waitMode = 1;
                    p->waitKind = 0x14;
                    p->wait = 0x1e;
                    p->timer = 0;
                    return;
                }
                unsigned char* msg = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();
                func_02046380(msg);
                memset(p->text, 0, 0x960);
                tbl = p->text;
                if (comb != 0) {
                    _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)msg, 0, comb->name);
                    _Z30InitObjFromCombatantId020e4bf4Pvi(p->obj8, UnitId(comb));
                    *(void**)msg = p->obj8;
                }
                _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)msg, 1, entry->name);
                if (res != 0) {
                    func_02046608(msg, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), 0x232d), (char*)(tbl + 0x860), 0xe3, 0, 1);
                    _Z20AppendString02042058PcPKc(p->text, (const char*)(tbl + 0x860));
                    struct StateSlot* slots = f.st10c.first;
                    for (int i = 0; i < f.st10c.count; i++) {
                        MsgKey key;
                        if (slots[i].a[0] == 3) {
                            key = MSG_KEY_DEAD;
                        } else {
                            key = MSG_KEY_ALIVE;
                        }
                        if (key < 0) {
                            continue;
                        }
                        struct Unit* target = (struct Unit*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, f.st10c.ids[i]);
                        if (target == 0) {
                            continue;
                        }
                        func_02046380(msg);
                        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)msg, 2, UnitName(target));
                        _Z30InitObjFromCombatantId020e4bf4Pvi(p->obj14, f.st10c.ids[i]);
                        *(void**)(msg + 0x10) = p->obj14;
                        StoreInArray0x8b0((struct StoreStruct*)msg, 9, target->id);
                        func_02046608(msg, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), key), (char*)(tbl + 0x860), 0xe3, 0, 1);
                        _Z20AppendString02042058PcPKc(p->text, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), 8));
                        _Z20AppendString02042058PcPKc(p->text, (const char*)(tbl + 0x860));
                    }
                    _Z22ConsumeCounter02048350P11Obj02048350i((struct Obj02048350*)comb, entry->lo8);
                    if (CheckField0NonZero(checkPtr) != 0) {
                        func_ov017_021c9e00(p->actor, 0, 0, 1);
                    }
                } else {
                    struct CombatantStruct* unknown = _ZN9GameState20GetUnknownGameObjectEv(gs);
                    if (unknown != 0) {
                        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)msg, 2, ((struct Unit*)unknown)->name);
                        _Z28InitObjFromCombatant020e4c74PvP10GameObject(p->obj14, _ZN9GameState20GetUnknownGameObjectEv(gs));
                        *(void**)(msg + 0x10) = p->obj14;
                    }
                    _Z20AppendString02042058PcPKc((char*)(tbl + 0x860), (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), 0x2333));
                    _Z20AppendString02042058PcPKc((char*)(tbl + 0x860), (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), 8));
                    if (n == 1) {
                        _Z20AppendString02042058PcPKc((char*)(tbl + 0x860), (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), 0x2334));
                    } else {
                        _Z20AppendString02042058PcPKc((char*)(tbl + 0x860), (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), 0x2335));
                    }
                    func_02046608(msg, 0xc, (int)(tbl + 0x860), p->text, 0xe3, 0, 1);
                }
                p->dirty = 1;
                memcpy(p->textCopy, p->text, 0x960);
                p->prompt = -1;
                p->showPrompt = 0;
            }
        } else if (p->command == 0xca) {
            if (func_ov017_0219ff58(word, 1, 0, 0) != 0) {
                flagB = 1;
                _Z26InitAndInsertNode_021acd30Pchhh((char*)word, 0, 0, 0);
            } else {
                _ZN13SafeAllocator5ResetEv(p->alloc8a0);
                p->anim = (struct Struct020a8170*)_ZN13SafeAllocator8AllocateEj(p->alloc8a0, 0x10);
                _Z19ClearStruct020a8170P14Struct020a8170(p->anim);
                func_020a818c(p->anim, p->alloc8a0);
                func_020a8304(p->anim);
                if (p->anim->count == 0) {
                    p->msgId2 = -1;
                    p->showPrompt = 1;
                    p->prompt = 0x2338;
                    _ZN13SafeAllocator5ResetEv(p->alloc8a0);
                    p->anim = 0;
                } else {
                    p->state = 0x14;
                    p->timer = 0;
                    return;
                }
            }
        } else if (p->command == 0xcf) {
            unsigned char* ov = (unsigned char*)func_ov017_0218b5b0();
            unsigned char* list;
            unsigned char* node = *(unsigned char**)(ov + 0x3bac);
            list = *(unsigned char**)(ov + 0x36fc);
            if (node[2] == 0) {
                _Z20InitState69_021c2744P11Obj021c2744((struct Obj021c2744*)node);
                *(int*)(node + 0x14) = comb->id;
                InsertNodeAfterHead((struct List02046a3c*)list, (struct Node02046a3c*)node);
            }
            p->state = 0x2b;
            p->nextState = 0x2b;
            return;
        } else if (p->command == 0xd0) {
            unsigned char* msg = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();
            memset(p->text, 0, 0x960);
            tbl = p->text;
            struct Unit* actor = (struct Unit*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, p->actor);
            if (actor != 0) {
                func_02046380(msg);
                _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)msg, 0, actor->name);
                _Z30InitObjFromCombatantId020e4bf4Pvi(p->obj8, p->actor);
                *(void**)msg = p->obj8;
                func_02046608(msg, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), 0x7537), (char*)(tbl + 0x860), 0xe3, 0, 1);
                _Z20AppendString02042058PcPKc(p->text, (const char*)(tbl + 0x860));
            }
            __clear(f.ids54, 4);
            int cnt = CopyOutRegion0x571d((char*)gs, f.ids54);
            int* total = f.obj148;
            int k;
            for (k = 0; k < cnt; k++) {
                struct Unit* member = (struct Unit*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, f.ids54[k]);
                if (member == 0) {
                    continue;
                }
                struct UnitExt* ext = member->ext;
                int busy;
                if (ext != 0) {
                    busy = ext->status.lo != 0;
                } else {
                    busy = 0;
                }
                if (busy) {
                    continue;
                }
                func_02046380(msg);
                _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)msg, 0, member->name);
                _Z30InitObjFromCombatantId020e4bf4Pvi(p->obj8, f.ids54[k]);
                *(void**)msg = p->obj8;
                int key;
                if (GetTableValue((void*)member) == 0x63) {
                    key = 0x7539;
                } else {
                    _ZN16BackgroundLoader13AddLockGlobalEv();
                    ext = member->ext;
                    sprintf(f.path, (const char*)&data_ov002_0216cf51, ext->level);
                    void* loaded = LoadFileIntoMemory(f.path, &data_0211e33c, &f.size50);
                    _Z22Clear0x54Bytes0208247cPv(f.obj148);
                    if (loaded != 0) {
                        func_02082490(f.obj148, loaded, f.size50, GetTableValue((void*)member) + 1, 0);
                    }
                    _ZN16BackgroundLoader16RemoveLockGlobalEv();
                    int diff = *total - CurLimit(member->ext);
                    if (diff <= 0) {
                        key = 0x753a;
                    } else {
                        StoreInArray0x8b0((struct StoreStruct*)msg, 0, diff);
                        SetByteInRange(msg, 0, 0);
                        key = 0x7538;
                    }
                }
                memset(tbl + 0x860, 0, 0x100);
                func_02046608(msg, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), key), (char*)(tbl + 0x860), 0xe3, 0, 1);
                _Z20AppendString02042058PcPKc(p->text, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)(p->container20), 8));
                _Z20AppendString02042058PcPKc(p->text, (const char*)(tbl + 0x860));
            }
            p->dirty = 1;
            memcpy(p->textCopy, p->text, 0x960);
            p->prompt = -1;
            p->showPrompt = 0;
            flagB = 1;
        } else if (p->command == 0xd1) {
            p->state = 7;
            flag1c = 1;
        } else if (p->command == 0xd2) {
            p->f248b = 1;
            unsigned char* list;
            unsigned char* node = *(unsigned char**)((unsigned char*)word + 0x3ba8);
            list = *(unsigned char**)((unsigned char*)word + 0x36fc);
            _Z23InitByteHeader_021c2688Ph(node);
            node[0xc] = p->actor;
            InsertNodeAfterHead((struct List02046a3c*)list, (struct Node02046a3c*)node);
            p->state = 0x2b;
            p->nextState = 0x2b;
            return;
        } else if (p->command == 0xd5) {
            unsigned char* rec = *(unsigned char**)((unsigned char*)func_ov017_0218b5b0() + 0x36d0);
            p->msgId = 0x7543;
            flagA = 1;
            if (func_0202c540(checkPtr) != 0 && _Z17IsInRange0201b588i(*obj) == 0) {
                p->showPrompt = 1;
                p->prompt = 0x7548;
                flagA = 0;
            } else if (GetByteFieldAt0x9ba(rec) == 0) {
                func_ov016_0218b5c0(0, -1);
                p->target = p->actor;
                _Z24SetFlagsAndReset02026678Pc((char*)rec);
            } else {
                p->showPrompt = 1;
                p->prompt = 0x232b;
                p->state = 0x26;
                p->nextState = 0x11;
                flagA = 0;
            }
            flagB = 1;
        } else if (p->command == 0xd3) {
            int ok = 1;
            unsigned char* rec = *(unsigned char**)((unsigned char*)func_ov017_0218b5b0() + 0x36d0);
            p->countA = 0;
            p->countB = 0;
            flagA = ok;
            p->showPrompt = flagA;
            p->msgId = 0x7544;
            if (func_0202c540(checkPtr) != 0) {
                p->prompt = 0x7549;
                flagA = 0;
            } else {
                if (_Z17IsInRange0201b5b0i(*obj) != 0) {
                    ok = 0;
                } else if (GetByteFieldAt0x9ba(rec) != 0) {
                    p->countA = CountEntriesByField0x8c((struct List02026a28*)rec);
                    p->countB = CountEntriesByField0x8e((struct List02026abc*)rec);
                } else {
                    _Z20ClearRecords02026644Pc((char*)rec);
                    _ZN16BackgroundLoader13AddLockGlobalEv();
                    f.size4c = 0;
                    void* data = LoadFileIntoMemory((const char*)&data_ov002_0216cf66, &data_0211e33c, &f.size4c);
                    if (func_02026780(rec, data, f.size4c) == 0) {
                        ok = 0;
                    } else {
                        _Z28CountMatchingEntries02026a78Pc((char*)rec);
                        p->countA = CountEntriesByField0x8c((struct List02026a28*)rec);
                        p->countB = CountEntriesByField0x8e((struct List02026abc*)rec);
                    }
                    _ZN16BackgroundLoader16RemoveLockGlobalEv();
                }
                if (ok) {
                    if (p->countA > 0 && p->countB == 0) {
                        p->prompt = 0x7546;
                        flagB = 1;
                    } else if (*(int*)&p->countA > 0) {
                        p->prompt = 0x7545;
                        flagB = 1;
                    } else {
                        p->prompt = 0x7547;
                    }
                } else {
                    p->prompt = 0x232b;
                    flagA = 0;
                }
            }
            p->state = 0x26;
            p->nextState = 0x26;
        } else if (p->command == 0xce) {
            unsigned char* ov = (unsigned char*)func_ov017_0218b5b0();
            unsigned char* list;
            unsigned char* node = *(unsigned char**)(ov + 0x3bb0);
            list = *(unsigned char**)(ov + 0x36fc);
            if (node[2] == 0) {
                _Z15InitObj021c2b28Pvhh(node, 0, comb->id);
                InsertNodeAfterHead((struct List02046a3c*)list, (struct Node02046a3c*)node);
            }
            p->msgId = 0x233c;
            flagA = 1;
            flagB = 1;
            p->target = p->actor;
        } else if (p->command == 0xa2 || p->command == 0xa4) {
            p->target = p->actor;
            int res = 0;
            struct TableEntry* entry = (struct TableEntry*)_Z24SearchBothTables02079e2cPci(tbl, p->command);
            if (entry != 0 && (entry->b10 & 1)) {
                func_ov016_0218b5c0(res, -1);
                _Z22InitStateArray02157ce0Pc((char*)&f.sta8);
                _Z22InitStateArray02157ce0Pc((char*)&f.sta8);
                f.sta8.id = p->command;
                f.sta8.actor = p->actor;
                f.sta8.count = 1;
                f.sta8.ids[0] = p->target;
                func_ov002_021536e0(&f.ctx48);
                f.ctx48 = tbl;
                res = func_ov002_021536ec(&f.ctx48, &f.sta8, res);
            }
            if (p->command == 0xa2) {
                p->msgId = 0x754c;
            } else if (p->command == 0xa4) {
                p->msgId = 0x754b;
            }
            p->msgId2 = -1;
            if (res != 0) {
                p->showPrompt = 1;
                if (p->command == 0xa2) {
                    p->prompt = 0x754d;
                    p->f248c = 1;
                } else if (p->command == 0xa4) {
                    p->prompt = 0x232c;
                    p->f248c = 1;
                }
                _Z22ConsumeCounter02048350P11Obj02048350i((struct Obj02048350*)comb, entry->lo8);
                if (CheckField0NonZero(checkPtr) != 0) {
                    func_ov017_021c9e00(p->actor, 0, 0, 1);
                }
            } else {
                p->showPrompt = 1;
                p->prompt = 0x232b;
            }
        } else {
            p->msgId2 = -1;
            p->showPrompt = 1;
            p->prompt = 0x232b;
        }
        p->timer = 0;
        if (flagB != 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 0x64, 0);
            p->state = 0x26;
            p->nextState = 0x2b;
            if (p->command == 0xd7) {
                p->state = 0x2b;
            }
        } else if (flag1c == 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 0x64, 0);
            p->state = 0x26;
            p->nextState = 0x11;
        }
    } else if (p->state == 7) {
        p->f2522 = 0;
        p->f2523 = 0;
        memset(p->buf2524, 0, 0xc);
        int res = 0;
        p->f2530 = res;
        p->showPrompt = 1;
        p->prompt = -1;
        p->msgId2 = -1;
        _Z22InitStateArray02157ce0Pc((char*)&f.st6c);
        _Z22InitStateArray02157ce0Pc((char*)&f.st6c);
        f.st6c.id = p->command;
        f.st6c.actor = p->actor;
        f.st6c.count = 1;
        f.st6c.ids[0] = p->target;
        struct TableEntry* entry = (struct TableEntry*)_Z24SearchBothTables02079e2cPci(tbl, p->command);
        if (entry != 0 && (entry->b10 & 1)) {
            func_ov016_0218b5c0(0, -1);
            func_ov002_021536e0(&f.ctx44);
            f.ctx44 = tbl;
            res = func_ov002_021536ec(&f.ctx44, &f.st6c, 0);
        }
        int found = 0;
        struct StateSlot* first = f.st6c.first;
        struct StateSlot* second = f.st6c.second;
        int i;
        for (i = 0; i < f.st6c.count; i++) {
            struct StateSlot* a = &first[i];
            struct StateSlot* b;
            if (a->active != 0 || (b = &second[i])->active != 0) {
                found = 1;
                break;
            }
        }
        if (found) {
            func_ov002_0216c42c(p, &f.st6c, entry);
            p->cc6 = 0;
            p->cc7 = 1;
            _Z22InitStateArray02157ce0Pc((char*)(p->stateArray));
            memcpy(p->stateArray, &f.st6c, 0x3c);
            p->msgId = -1;
            p->msgId2 = -1;
            p->state = 0x26;
            p->nextState = 0x26;
            p->prompt = -1;
            p->showPrompt = 0;
            p->waitMode = 1;
            p->waitKind = 0x14;
            p->wait = 0x1e;
            p->timer = 0;
            return;
        }
        if (p->command == 0xd1) {
            if (CheckField0NonZero((int*)func_0202ae18()) != 0) {
                int ok = 1;
                int j;
                for (j = 0; j < p->excludeCount; j++) {
                    if (p->target == p->exclude[j]) {
                        ok = 0;
                    }
                }
                if (ok) {
                    func_ov016_0218b5c0(0, -1);
                    _Z26EnqueueEventTag34_021d27a0hhh(1, p->actor, p->target);
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 0x64, 0);
                    p->msgId = 0x7536;
                    p->msgId2 = -1;
                    p->state = 0x26;
                    p->nextState = 0x26;
                    p->prompt = -1;
                    p->showPrompt = 0;
                    p->waitMode = 1;
                    p->waitKind = 0xa;
                    p->wait = 0x12c;
                    p->timer = 0;
                    return;
                }
            }
            _Z16Dispatch020e3428Pvi(GetData02153637(), 1);
            p->msgId = 0x7535;
            p->msgId2 = -1;
            int cured = 0;
            struct Unit* target = (struct Unit*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, p->target);
            if (target != 0 && (*target->status & 4)) {
                cured = 1;
            }
            if (cured) {
                int* cp = (int*)func_0202ae18();
                TryClearFlags0x130((unsigned char*)target, 4);
                if (CheckField0NonZero(cp) != 0) {
                    func_ov017_021c9e00(p->target, 0, 0, 1);
                }
                unsigned char* party = (unsigned char*)_Z17GetPtrField0x2a04P9GameState(gs);
                f.tab = *(struct Table11*)&data_ov002_0216c992;
                int any = 0;
                int q;
                for (q = 0; q < 0xb; q++) {
                    if (q == 2 || q == 3 || q == 4) {
                        continue;
                    }
                    struct SkillSlot* slot = &target->ext->slots[(unsigned char)q];
                    if (slot == 0) {
                        continue;
                    }
                    if (slot->on == 0) {
                        continue;
                    }
                    func_0207c378(party + 0x1d4, slot->value, 1, slot->lo4);
                    func_02052d7c((void*)target, f.tab.v[q], -1);
                    any = 1;
                }
                if (any) {
                    if (CheckField0NonZero(cp) != 0) {
                        func_ov017_021c3fb4(p->target, 1);
                        func_ov017_021c4418(p->target, -1);
                    }
                    void* ov = func_ov017_0218b5b0();
                    _ZN16BackgroundLoader11GetInstanceEv();
                    func_ov017_0218f5a4(ov, p->target, 1, 0, 0);
                }
                p->prompt = -1;
                p->showPrompt = 0;
                flagA = 1;
            } else {
                p->prompt = 0x232b;
                p->showPrompt = 1;
            }
        } else {
            _Z16Dispatch020e3428Pvi(GetData02153637(), 1);
            struct Unit* member = (struct Unit*)_ZN9GameState21GetPartyMemberByIndexEi(gs, p->target);
            if (res != 0) {
                if (p->command == 0x1e || p->command == 0x1f || p->command == 0x20 || p->command == 0x21) {
                    p->prompt = 0x232c;
                    flagA = 1;
                } else if (p->command == 0x23) {
                    p->prompt = 0x794b;
                    flagA = 1;
                } else if (p->command == 0x27 || p->command == 0x26) {
                    p->prompt = 0x2336;
                    flagA = 1;
                }
            } else {
                int alive = (*member->status & 1) != 0;
                if (alive) {
                    if (p->command == 0x26) {
                        p->prompt = 0x2337;
                        flagA = 1;
                    } else {
                        p->prompt = 0x232b;
                    }
                } else {
                    p->msgId = 0x2333;
                    p->prompt = 0x2334;
                }
            }
        }
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 0x64, 0);
        p->state = 0x26;
        p->nextState = 0x11;
        p->timer = 0;
    }
    if (flagA != 0) {
        _Z22ConsumeCounter02048350P11Obj02048350i((struct Obj02048350*)comb, entryA->lo8);
        if (CheckField0NonZero(checkPtr) != 0) {
            func_ov017_021c9e00(p->actor, 0, 0, 1);
        }
    }
}
