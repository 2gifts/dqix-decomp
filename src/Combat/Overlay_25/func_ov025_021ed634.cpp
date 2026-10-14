#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Val0c { char pad[0xc]; short v; };
struct Bits64_02159f7c;
struct Src020e4e38;
struct Outer_02054000;
struct StoreStruct;

struct List021600f8 {
    unsigned short id;
    short s2;
    char pad4[2];
    short s6;
    char pad8;
    unsigned char count;
};
struct List02160094;
struct Node021600f8 {
    char pad0[0xe];
    short s0e;
    char pad10[8];
    unsigned char count;
    char pad19[4];
    unsigned char bit0 : 1;
};
struct Node02160094 {
    char pad0[0x18];
    float f18;
    char pad1c[4];
    unsigned short s20;
};
struct Row02079e2c {
    char pad[0x18];
    unsigned int pad5 : 5;
    unsigned int kind : 7;
};
struct Entry021dafd0 { char pad[0xc]; short v; };
struct Entry2c { char pad[0x2c]; short v; };
struct Sub18 { char pad[0x18]; short v; };
struct Comb { char pad[0x138]; unsigned char* p138; char pad13c[0xc]; char* p148; char pad14c[0x41]; unsigned char b18d; };

struct Self021ed634 {
    unsigned short ids[16];
    short a20[16];
    short a40[16];
    short a60[16];
    unsigned short a80[16];
    unsigned char types[16];
    Val0c* ptrs[16];
    int fF0[16];
    char pad130[0x24];
    short s154;
    char pad156[2];
    int f158;
    char pad15c[2];
    unsigned short s15e;
    unsigned short s160;
    unsigned short s162;
    List021600f8* list;
    void* f168;
    char pad16c[0x40];
    unsigned short s1ac;
};

struct Cur {
    int f0;
    int pad4;
    int f8;
    int pad0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
};
struct Obj12 { void* a; void* b; int c; };
struct Arr16 { short v[16]; };
struct MessageEntryCounts {
    unsigned char unknown00[0x30];
    unsigned char flaggedEntries;
    unsigned char positiveFlaggedEntries;
};

extern Arr16 data_ov025_021ef040;
extern Arr16 data_ov025_021ef060;
extern Arr16 data_ov025_021ef020;

int Check021ed2f4(void* obj);
void* GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* obj);
extern "C" ARM void* __clear(void* dst, int count);
extern "C" void func_ov025_021ed1f0(void* self);
Node02160094* GetNodeAtIndex02160094(List02160094* list, int index);
Node021600f8* GetNodeAtIndex021600f8(List021600f8* list, int index);
void ShiftArrayDown_021ed2a0(char* self);
void* FindNodeAtDepth0215fff4(void* obj, int limit, int idx);
extern "C" short func_ov000_0215ffa0(void* obj);
void* GetField6b0_021b8470(void* obj);
int CheckAnyBitOrFlag_02159f7c(void* obj, Bits64_02159f7c* bits);
extern "C" int func_ov000_0215fd90(void* obj, int flag);
void StoreInArray0x8b0(StoreStruct* base, int index, int value);
void InitObjFromCombatantId020e4bf4(void* obj, int id);
class GameObject;
GameObject* GetCombatantWithFlag0x400(GameState* gs, int id);
GameObject* GetCombatantWithFlag0x100(GameState* gs, int id);
extern "C" void func_020e4ce8(void* dst, void* src, int flag);
void CopyStringToField0x3ac(char* g, char* s);
void SetByte0x1880(void*, signed char);
void CopyStringToField042c(void* g, char* s);
extern "C" int _Z22CheckKeyMatch_0215fb9cis(int obj, unsigned short id);
void BuildName020488ec(char* s);
void CopyStringToField046c(void* g, char* s);
Row02079e2c* SearchBothTables02079e2c(char* table, int key);
void InitObjFromPackedFields020e4e38(void* obj, Src020e4e38* src);
void CopyStringToField0x3ec(char* g, char* s);
void* GetActiveCombatWork(void);
char* GetOffsetPtr02160f08(void* w);
void* FindEntryById_021dafd0(char* obj, int id);
Sub18* GetActiveSub_02054000(Outer_02054000* o);
void Clear12Bytes020e46c4(void* p);
void DispatchIfCountPositive020dcf7c(int count, void* buf);
unsigned char CopyOutRegion0x571d(char*, void*);
extern "C" void* func_ov017_021b8478(void* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
char* GetFieldByKeyFromWork0x88(void* work, int key);
extern "C" unsigned int strlen(const char* s);
extern "C" int sprintf(char* buf, const char* fmt, ...);
#if !defined(jpn)
extern "C" void func_0204500c(void* g, char* s, int a, int b);
#endif
extern "C" void func_02042b98(void* self, int a, int b, int c, int d);

#if defined(jpn)
extern "C" void func_020473a0(void*, char*);
extern "C" void func_02047410(void*, int);
extern "C" int func_ov025_021ed5a4(int, char*);
void* GetBoundedField156_02171674(void*, int);
void* GetBoundedField420_0217199c(void*, int);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
extern "C" void func_020474a8(void*, int, char*, char*);
extern "C" void func_0204500c(void*, char*, int);
extern "C" void func_02043270(void*, int, int, int, int);
extern "C" char* strcpy(char*, const char*);
extern "C" char* strcat(char*, const char*);
extern char data_ov025_021efbfc[];
#endif

#if defined(jpn)
#define COPY_FIELD CopyStringToField0x3ec
#define STATE_OFFSET 0x870
#else
#define COPY_FIELD CopyStringToField042c
#define STATE_OFFSET 0x9a0
#endif

static inline int IsValidId(int x) { return x >= 0 && x <= 3; }
static inline int IsValidIdS(short x) { return x >= 0 && x <= 3; }
static inline int IsValidIdU(unsigned short x) { return x >= 0 && x <= 3; }

// USA: func_ov025_021ed634
extern "C" ARM void func_ov025_021ed634(Self021ed634* self) {
    if (Check021ed2f4(self) != 0) return;
    if (self->list == 0) return;
    GameState* gs = GameState::GetInstance();
    char* g = (char*)GetGlobalField0x1c020421a0();
#if defined(jpn)

#else
    func_02046380(g);
#endif
#if defined(jpn)
    char output[0x100];
    char buf[0x100];
    Arr16 arrC;
    Arr16 arrB;
    Arr16 arrA;
    char nameB[0x40];
    char nameA[0x40];
    char plural[0x24];
    char name[1];
#else
    char bufE[0x80];
    char bufF[0x80];
    char buf[0x100];
    char objB[12];
    char objA[12];
    char objC[12];
    Obj12 objD;
    Arr16 arrC;
    Arr16 arrB;
    Arr16 arrA;
    char out[5];
    char name[1];
#endif
    __clear(name, 1);
    if (self->s15e == 0) {
        int type = self->types[0];
        int id = self->ids[0];
        int v20 = self->a20[0];
        Val0c* ptr = self->ptrs[0];
        short s60 = self->a60[0];
#if defined(jpn)
        int v40 = self->a40[0];
        int u80 = self->a80[0];
#else
        int u80 = self->a80[0];
        int v40 = self->a40[0];
#endif
        func_ov025_021ed1f0(self);
        if (id <= 0) return;
        Node02160094* node = GetNodeAtIndex02160094((List02160094*)self->list, 0);
        int cnt40 = 0;
        int fp = 0;
        int cnt3c = 0;
        int sum38 = 0;
        int cnt34 = 0;
        int flag = IsValidId(v20) ? 1 : 0;
        arrC = data_ov025_021ef040;
        int cnt[2];
        cnt[0] = 0;
        arrB = data_ov025_021ef060;
        short who;
        int sb = 0;
        int found8 = 0;
        int count30 = self->list->count;
        if (self->list->id == 0x61) {
            Node021600f8* nd = GetNodeAtIndex021600f8(self->list, 0);
            if (nd != 0) {
                if (nd->bit0 == 0) found8 = 1;
            }
        }
        if (found8 != 0 || self->list->id == 0x1b) {
            if (ptr != 0) fp = ptr->v;
        } else if (id == 0x172) {
            fp = self->fF0[0];
            ShiftArrayDown_021ed2a0((char*)self);
        } else if (self->list->id == 0x3a6) {
            for (int i = 0; i < self->list->count; i++) {
                Node021600f8* nd = GetNodeAtIndex021600f8(self->list, i);
                if (nd != 0 && nd->s0e == v20) {
                    for (int j = 0; j < nd->count; j++) {
                        Val0c* n = (Val0c*)FindNodeAtDepth0215fff4(nd, j, 0);
                        if (n != 0 && n->v >= 0) {
                            fp = n->v;
                            cnt40++;
                            break;
                        }
                    }
                    if (cnt40 != 0) break;
                }
            }
        } else if (type == 3) {
            if (ptr != 0) {
                int v = ptr->v;
                if (v >= 0) { if (v > 0) fp += v; }
                else { sum38 -= v; cnt3c++; }
            }
        } else {
            arrA = data_ov025_021ef020;
            cnt[1] = 0;
            for (int i = 0; i < self->list->count; i++) {
                Node021600f8* nd = GetNodeAtIndex021600f8(self->list, i);
                if (nd == 0) continue;
                who = func_ov000_0215ffa0(nd);
                if (IsValidIdS(who) != 0) {
                    if (flag == 0) continue;
                }
                if (IsValidIdS(who) == 0) {
                    if (flag != 0) continue;
                }
                for (int k = 0; k < nd->count; k++) {
                    Val0c* n = (Val0c*)FindNodeAtDepth0215fff4(nd, k, 0);
                    if (n == 0) continue;
                    int v = n->v;
                    if (v >= 0) { if (v > 0) fp += v; }
                    else { sum38 -= v; cnt3c++; }
                    void* obj = GetField6b0_021b8470(func_ov017_0218b5b0()->unknown_ptr_3718);
                    if (n->v > 0) {
                        int found = 0;
                        for (int m = 0; m < cnt[0]; m++) {
                            if (who == arrC.v[m]) { found = 1; break; }
                        }
                        if (found == 0) { arrC.v[cnt[0]] = who; cnt[0]++; }
                    } else {
                        if (CheckAnyBitOrFlag_02159f7c(obj, (Bits64_02159f7c*)n) != 0 || func_ov000_0215fd90(n, 4) != 0) {
                            int found = 0;
                            for (int m = 0; m < sb; m++) {
                                if (who == arrB.v[m]) { found = 1; break; }
                            }
                            if (found == 0) { arrB.v[sb] = who; sb++; }
                        }
                    }
                    if (flag == 0) {
                        if (func_ov000_0215fd90(n, 2) != 0) {
                            int found = 0;
                            for (int m = 0; m < cnt[1]; m++) {
                                if (who == arrA.v[m]) { found = 1; break; }
                            }
                            if (found == 0) { arrA.v[cnt[1]] = who; cnt[1]++; cnt34++; }
                        }
                    }
                }
            }
        }
        if (cnt3c > 0) {
            int displayValue = sum38 / cnt3c;
            if (displayValue == 0 && sum38 != 0) displayValue = -1;
            #if defined(jpn)
func_02047410(g, displayValue);
#else
StoreInArray0x8b0((StoreStruct*)g, 0, displayValue);
#endif
        } else if (cnt[0] != 0) {
            int displayValue = fp / cnt[0];
            if ((unsigned int)(id - 0x261) <= 1) displayValue = fp;
            if (displayValue == 0 && fp != 0) displayValue = 1;
            #if defined(jpn)
func_02047410(g, displayValue);
#else
StoreInArray0x8b0((StoreStruct*)g, 0, displayValue);
#endif
        } else {
            #if defined(jpn)
func_02047410(g, fp);
#else
StoreInArray0x8b0((StoreStruct*)g, 0, fp);
#endif
        }
        if (type == 5) {
            v20 = arrC.v[0];
            if (v20 < 0) {
                v20 = arrB.v[0];
                if (v20 < 0) {
                    Node021600f8* nd = GetNodeAtIndex021600f8(self->list, 0);
                    if (nd != 0) v20 = func_ov000_0215ffa0(nd);
                }
            }
#if defined(jpn)
        }

#else
            if (IsValidId(v20)) {
                InitObjFromCombatantId020e4bf4(objA, v20);
            } else {
                GameObject* c = GetCombatantWithFlag0x400(gs, v20);
                if (c != 0) {
                    func_020e4ce8(objA, c, 1);
                    ((Cur*)g)->f20 = (int)objA;
                }
            }
            ((Cur*)g)->f10 = (int)objA;
        }

#endif
#if defined(jpn)
        func_020473a0(g, name);
#else
        CopyStringToField0x3ac((char*)g, name);
#endif
#if defined(jpn)
        if (v40 < 0) {
            if (node != 0) v40 = node->s20;
        }
        if (v40 >= 0) {
            if (func_ov025_021ed5a4(v40, nameB)) func_020473a0(g, nameB);
            SetByte0x1880(g, (signed char)v40);
        }

#else
        if (v40 < 0) {
            if (node != 0) v40 = node->s20;
            int b = IsValidId(v40) ? 1 : 0;
            if (b != 0) {
                InitObjFromCombatantId020e4bf4(objB, v40);
                ((Cur*)g)->f0 = (int)objB;
            } else {
                GameObject* c = GetCombatantWithFlag0x400(gs, v40);
                if (c != 0) {
                    func_020e4ce8(objB, c, 1);
                    ((Cur*)g)->f0 = (int)objB;
                }
            }
        }
        if (v40 >= 0) {
            SetByte0x1880(g, (signed char)v40);
            int b = IsValidId(v40) ? 1 : 0;
            if (b != 0) {
                InitObjFromCombatantId020e4bf4(objB, v40);
                ((Cur*)g)->f0 = (int)objB;
            } else {
                GameObject* c = GetCombatantWithFlag0x400(gs, v40);
                if (c != 0) {
                    func_020e4ce8(objB, c, 1);
                    ((Cur*)g)->f0 = (int)objB;
                }
            }
        }

#endif
        if ((unsigned int)(id - 0xf1) <= 1) {
            int t = self->list->s6;
            if (t >= 0) v20 = t;
        }
        COPY_FIELD(g, name);
        if (_Z22CheckKeyMatch_0215fb9cis((int)GetField6b0_021b8470(func_ov017_0218b5b0()->unknown_ptr_3718), self->list->id) != 0) {
            Comb* c = (Comb*)GetCombatantWithFlag0x400(gs, v20);
            if (c != 0) {
                c->p138[0x25] = c->b18d;
                BuildName020488ec((char*)c);
                COPY_FIELD(g, (char*)c + 0x14c);
            }
#if defined(jpn)

#else
            func_020e4ce8(objA, c, 1);
            ((Cur*)g)->f10 = (int)objA;
#endif
        } else {
#if defined(jpn)
            if (func_ov025_021ed5a4(v20, nameA)) CopyStringToField0x3ec(g, nameA);
        }

#else
            if (IsValidId(v20)) {
                InitObjFromCombatantId020e4bf4(objA, v20);
            } else {
                GameObject* c = GetCombatantWithFlag0x400(gs, v20);
                func_020e4ce8(objA, c, 1);
            }
            if (v40 == v20) ((Cur*)g)->f10 = (int)objB;
            else ((Cur*)g)->f10 = (int)objA;
        }

#endif
        if (id == 0xf2 || id == 0x207) {
            Comb* c = (Comb*)GetCombatantWithFlag0x400(gs, v20);
            if (c != 0 && c->p148 != 0) COPY_FIELD(g, c->p148 + 0x2c);
        }
#if defined(jpn)
        CopyStringToField042c(g, name);
#else
        CopyStringToField046c(g, name);
#endif
        ActionDataTables* data = GetData02108e10();
        List021600f8* l = self->list;
        Row02079e2c* row;
        if (l->id == 0x1f8 || l->id == 0x3a9 || l->id == 0x3a7 || l->id == 0x3ac || l->id == 0x3ad || l->id == 0x392) {
            row = SearchBothTables02079e2c((char*)data, l->s2);
        } else {
            row = SearchBothTables02079e2c((char*)data, (short)l->id);
        }
        if (row != 0) {
#if defined(jpn)
            CopyStringToField042c(g, *(char**)row);
#else
            InitObjFromPackedFields020e4e38(objC, (Src020e4e38*)row);
            ((Cur*)g)->f8 = (int)objC;
            ((Cur*)g)->f18 = (int)objC;
#endif
        }
#if defined(jpn)
        CopyStringToField0x3ac(g, name);
#else
        CopyStringToField0x3ec(g, name);
#endif
#if defined(jpn)
        if (node != 0) {
            char* w = GetOffsetPtr02160f08(GetActiveCombatWork());
            int index = node->s20;
            char* entry;
            if (IsValidId(index)) {
                for (int n = 0; n < 4; n++) {
                    if (*(int*)(w + 0x9a4 + n * 0x488) == index) {
                        entry = w + 0x958 + n * 0x488;
                        goto found_entry;
                    }
                }
            }
            entry = 0;
found_entry:
            if (entry != 0) {
                void* a = GetBoundedField156_02171674(entry, *(signed char*)(entry + 0x20));
                void* b = GetBoundedField420_0217199c(entry, *(short*)(entry + 0x1e));
                if (*(signed char*)self->pad16c != 0) {
                    CopyStringToField0x3ac(g, self->pad16c);
                    if (*(short*)((char*)self->list + 4) != 0)
                        SetIndexedName02046574((Obj02046574*)g, 0, self->pad16c);
                } else if (a != 0) CopyStringToField0x3ac(g, *(char**)a);
                else if (b != 0) CopyStringToField0x3ac(g, *(char**)b);
            }
        }

#else
        if (node != 0) {
            char* w = GetOffsetPtr02160f08(GetActiveCombatWork());
            Entry2c* e = (Entry2c*)FindEntryById_021dafd0(w, node->s20);
            if (IsValidIdU(node->s20)) {
                int cnt = e->v;
                if (self->s1ac != 0) cnt = (short)self->s1ac;
                if (id == 0x257 || id == 0xc) {
                    GameObject* c = GetCombatantWithFlag0x100(gs, node->s20);
                    if (c != 0) {
                        Sub18* s = GetActiveSub_02054000((Outer_02054000*)c);
                        if (s != 0) cnt = s->v;
                    }
                }
                if (cnt > 0) {
                    Clear12Bytes020e46c4(&objD);
                    __clear(bufE, 0x80);
                    __clear(bufF, 0x80);
                    objD.a = bufE;
                    objD.b = bufF;
                    DispatchIfCountPositive020dcf7c(cnt, &objD);
                    ((Cur*)g)->f18 = (int)&objD;
                }
            }
        }

#endif
#if defined(jpn)
        if ((id == 9 && cnt34 >= 2) || (id == 4 && sb >= 2) || (id == 7 && sb >= 2)
            || (row != 0 && row->kind == 1 && id == 0x1b && sb >= 2)) {
            strcpy(plural, nameA);
            strcat(plural, data_ov025_021efbfc);
            CopyStringToField0x3ec(g, plural);
        }

#else
        if ((id == 9 && cnt34 >= 2) || (id == 4 && sb >= 2) || (id == 7 && sb >= 2)
            || ((id == 0xf0 || id == 0x209) && count30 >= 2)
            || (row != 0 && row->kind == 1 && (id == 0x20c || id == 0x11f || id == 0x11d || id == 0x20b) && count30 >= 2)
            || (row != 0 && row->kind == 1 && id == 0x1b && sb >= 2)
            || (row != 0 && row->kind == 1 && id == 0x26d && sb >= count30)) {
            *(g + 0x1000 + 0x9d7) = 1;
        }
        int n5 = CopyOutRegion0x571d((char*)gs, out);
        unsigned char positiveFlaggedEntries = 0;
        unsigned char flaggedEntries = 0;
        unsigned char* tb = (unsigned char*)func_ov017_021b8478(func_ov017_0218b5b0()->unknown_ptr_3718);
        char* ew = GetOffsetPtr02160f08(GetActiveCombatWork());
        for (int q = 0; q < n5; q++) {
            Entry021dafd0* e = (Entry021dafd0*)FindEntryById_021dafd0(ew, (unsigned char)out[q]);
            if (e != 0 && TestBitAt0x34(tb, (unsigned char)out[q]) != 0) {
                ++flaggedEntries;
                if (e->v > 0) ++positiveFlaggedEntries;
            }
        }
        ((MessageEntryCounts*)g)->flaggedEntries = flaggedEntries;
        ((MessageEntryCounts*)g)->positiveFlaggedEntries = positiveFlaggedEntries;

#endif
        char* fmt = GetFieldByKeyFromWork0x88(self->f168, (short)id);
        if (fmt == 0) return;
        if (strlen(fmt) == 0) return;
#if defined(jpn)
        __clear(output, 0x100);
#endif
        if (id == 0x205 || id == 0x1be || id == 0x1bf || id == 0x224 || id == 0x1c0 || id == 0x225 || id == 0x263
            || (unsigned int)(id - 0x266) <= 3) {
            __clear(buf, 0x100);
            void* obj = GetField6b0_021b8470(func_ov017_0218b5b0()->unknown_ptr_3718);
            if (id == 0x205) {
                sprintf(buf, fmt, (double)node->f18);
            } else if (obj != 0) {
                sprintf(buf, fmt, (double)*(float*)((char*)obj + 0x8e3c));
            }
            if (id == 0x1bf || id == 0x224 || id == 0x1c0 || id == 0x225 || (unsigned int)(id - 0x264) <= 7) {
                Comb* c = (Comb*)GetCombatantWithFlag0x400(gs, self->list->s6);
                if (c != 0 && c->p148 != 0) COPY_FIELD(g, c->p148 + 0x2c);
            }
#if defined(jpn)
            func_020474a8(g, 0xc, buf, output);
#else
            func_0204500c(g, buf, 0, 0xe3);
#endif
        } else {
#if defined(jpn)
            func_020474a8(g, 0xc, fmt, output);
#else
            func_0204500c(g, fmt, 0, 0xe3);
#endif
        }
#if defined(jpn)
        func_0204500c(g, output, 0);
        *(g + 0x17e1) = 0;
        *(int*)(g + 0x1730) = 0xc;
        *(int*)(g + 0x1734) = 0x12;
        func_02043270(g, *(int*)(g + 0x1730), 0x92, 0x100, 0x30);
        *(g + 0x17e2) = 0;
        *(unsigned char*)(g + 0x1789) |= 2;
        *(g + 0x17f6) = 1;
        *(int*)(g + 0x868) = 1;
#else
        *(g + 0x1000 + 0x9b1) = 0;
        func_02042b98(g, 2, 0x92, 0xfc, 0x4a);
        *(g + 0x1000 + 0x9b2) = 0;
        *(unsigned char*)(g + 0x1000 + 0x95b) |= 2;
        *(g + 0x1000 + 0x9c5) = 1;
        *(int*)(g + 0x998) = 1;
#endif
        self->s160 = self->s162;
        if (u80 != 0) self->s160 = u80;
        self->f158 = (int)ptr;
        self->s154 = s60;
        self->s15e = 1;
    } else if (self->s15e == 1 && *(int*)(g + STATE_OFFSET) == 0) {
        unsigned int dt = gs->GetEffectiveDeltaTime();
        unsigned int t = self->s160;
        if (dt < t) {
            self->s160 = t - dt;
        } else {
            self->s160 = 0;
            self->s15e = 0;
            self->f158 = 0;
            self->s154 = 0;
        }
    }
}
