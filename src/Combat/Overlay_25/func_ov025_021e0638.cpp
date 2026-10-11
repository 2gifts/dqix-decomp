// JPN: func_ov025_021e0f48
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"
#if defined(jpn)
enum { Field29c = 0x218, Field55d8 = 0x57c8, Field18c = 0x180, Fielde78 = 0xdf4 };
#else
enum { Field29c = 0x29c, Field55d8 = 0x55d8, Field18c = 0x18c, Fielde78 = 0xe78 };
#endif

struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
extern "C" struct CombatantStruct* _Z25GetCombatantWithFlag0x100P9GameStatei(struct BattleStruct* battleStruct, int combatantId);

struct Obj02048c90;
struct Obj02049410;
struct Obj02049a74;
struct Obj020494c0;
struct List02160094;
struct List021600f8;

struct Ent021e0638 {
    unsigned char id;
    unsigned char val;
    char pad[6];
    unsigned char* obj;
};

struct Node021e0638 {
    unsigned char data[12];
    Node021e0638* next;
};

struct Pool021e0638 {
    unsigned char seq[16];
    unsigned char mark[16];
    unsigned char len;
};

struct Table021e0638 {
    void* data;
    int count;
    unsigned char buf[12];
    unsigned char len;
};

struct B6_021e0638 {
    unsigned char b[6];
};

struct Vec3_021e0638 { int x; int y; int z; };
struct Pos2_021e0638 { int v[2]; };

struct ElemList021e0638 {
    char pad0[8];
    unsigned char count8;
    unsigned char count9;
    char pad1[6];
    unsigned char* p10;
    unsigned char* p14;
    char pad2[0x10];
};

static inline unsigned char* Off21c_021e0638(unsigned char* p) { return p + 0x21c; }
static inline unsigned char* Off8000_021e0638(unsigned char* p) { return p + 0x8000; }

struct Sub148_021e0638 {
    char pad[0x10];
    unsigned int flags;
};

struct Data021e0638 {
    Vec3_021e0638 a;
    Vec3_021e0638 b;
    int radius;
    unsigned char flag;
};

extern "C" int func_ov025_021e1048(void* world, void* out);
extern "C" void func_ov025_021e20ec(void* tbl, SafeAllocator* alloc);
extern "C" int func_ov025_021e2148(void* tbl, int a, int b, void* out, int n);
extern "C" void func_ov025_021e120c(void* buf, int id, int a, int b, int c);
extern "C" void func_020c9be0(void);
extern "C" void func_ov000_0216f82c(B6_021e0638* out, const int* cell);
extern "C" void func_ov000_0216f74c(Pos2_021e0638* out, const int* cell);
extern "C" void _ZN8Vector3iaSERKS_(Vec3_021e0638* dst, const Vec3_021e0638* src);
extern "C" int _ZNK8Object3D9GetRadiusEv(void* self);
extern "C" void __clear(void* p, int n);

extern "C" void _Z20ResetFields_021e20d8Pv(void* obj);
extern "C" void _Z23ResetInnerState02048c90P11Obj02048c90(Obj02048c90*);
int GetSubstructByte0x1c(unsigned char*);
int GetSubstructByte0x1d(unsigned char*);
int GetSubstructByte0x34(unsigned char*);
int GetSubstructByte0x56(unsigned char*);
extern "C" void _Z27CopyBytesAndSetLen_021e2114PhPvi(unsigned char*, void*, int);
extern "C" void _Z24StoreDataWithLen02049410P11Obj02049410Pvi(Obj02049410*, void*, int);
extern "C" void _Z30ApplyFlag0x4IfEligible02049a74P11Obj02049a74(Obj02049a74*);
void ClearSubstructFlag0x4(unsigned char*);
void ClearSubstructFlag0x40(unsigned char*);
void SetSubstructFlag0x40(unsigned char*);
void ClearGlobalBuffer02107850(void);
Data021e0638* GetData02107850(void);
int CheckHighNibble0xc1Not2To5(unsigned char*);
int CheckSubstructFlag0x200(unsigned char*);
extern "C" void _Z26DispatchTargetByte020494c0P11Obj020494c0(Obj020494c0*);
extern "C" unsigned char* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094*, int);
extern "C" unsigned char* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8*, int);

static inline Node021e0638* NthNode021e0638(Node021e0638* head, int idx) {
    if (idx == 0) {
        return head;
    }
    Node021e0638* p = head->next;
    for (int x = 0; x < idx - 1; x++) {
        if (p == 0) {
            return 0;
        }
        p = p->next;
    }
    return p;
}

// USA: func_ov025_021e0638
extern "C" ARM void func_ov025_021e0638(unsigned char* self) {
    int n;
    Node021e0638* tail;
    GameState* gs = GameState::GetInstance();
    unsigned char* world = *(unsigned char**)(self + Field29c);
    ElemList021e0638* cur = (ElemList021e0638*)(world + 0x821c) + *(int*)(self + Field55d8);
    Ent021e0638 ents[12];
    int ids[60];
    unsigned char seen[0x51];
    Node021e0638 head;
    Table021e0638 tbl;
    unsigned char tmp[12];
    unsigned char out[16];
    unsigned char sendbuf[32];
    unsigned char common[6];
    Pos2_021e0638 pp;
    Pos2_021e0638 pos;
    int posCell;
    int cellB;
    B6_021e0638 nbB;
    int cellA;
    B6_021e0638 nbA;
    B6_021e0638 s2;
    B6_021e0638 s1;
    SafeAllocator* alloc = (SafeAllocator*)(self + 0x30);

    alloc->Reset();
    n = func_ov025_021e1048(world, ents);
    head.next = 0;
    Pool021e0638* pool = (Pool021e0638*)alloc->Allocate(n * 33);
    if (pool == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        _Z23ResetInnerState02048c90P11Obj02048c90((Obj02048c90*)ents[i].obj);
        head.data[i] = GetSubstructByte0x1c(ents[i].obj);
        pool[i].len = 0;
        memset(pool[i].mark, 0, 0x10);
    }
    _Z20ResetFields_021e20d8Pv(&tbl);
    func_ov025_021e20ec(&tbl, alloc);
    int i;
    int changed;
    int nodes;
    int nids;
    nodes = 0;
    nids = 0;
    changed = 1;
    tail = &head;
    for (i = *(int*)(self + Field55d8); i < *(int*)(Off8000_021e0638(world) + 0xe24); i++) {
        unsigned char* o = ((ElemList021e0638*)Off8000_021e0638(Off21c_021e0638(world)))[i].p10;
        if (o != 0) {
            ids[nids++] = *(unsigned short*)(o + 0x20);
        }
    }
    unsigned char* lists = Off21c_021e0638(world);
    for (int j = 0; j < *(int*)(self + Field55d8); j++) {
        ElemList021e0638* e = (ElemList021e0638*)(lists + 0x8000) + j;
        if (e->p10 != 0) {
            ids[nids++] = *(unsigned short*)(e->p10 + 0x20);
        }
    }
    while (changed) {
        changed = 0;
        for (int i = 0; i < nids; i++) {
            int id = ids[i];
            int k;
            for (k = 0; k < n; k++) {
                if (id == ents[k].id) {
                    goto found;
                }
            }
            k = -1;
found:
            if (k < 0 || n <= k) {
                continue;
            }
            unsigned char* obj = ents[k].obj;
            int target;
            int off = k * 33;
            unsigned char* entry = (unsigned char*)pool + off;
            unsigned char len = (&pool->len)[off];
            if (len >= 0x10) {
                continue;
            }
            int prev;
            if (len != 0) {
                prev = entry[len - 1];
            } else {
                prev = GetSubstructByte0x1c(obj);
            }
            target = GetSubstructByte0x1d(obj);
            if (prev == target) {
                continue;
            }
            unsigned char m = 0;
            for (int j = 0; j < n; j++) {
                unsigned char b = tail->data[j];
                if (target != b) {
                    tmp[m++] = b;
                }
            }
            _Z27CopyBytesAndSetLen_021e2114PhPvi((unsigned char*)&tbl, tmp, m);
            __clear(out, 0x10);
            unsigned char cnt = func_ov025_021e2148(&tbl, prev, target, out, 0x10);
            if (cnt < 2) {
                continue;
            }
            if (len == 0) {
                entry[len++] = tail->data[k];
            }
            if (len >= 0x10) {
                func_020c9be0();
            }
            unsigned char v = out[cnt - 2];
            unsigned char nl = len + 1;
            entry[len] = v;
            (&pool->len)[off] = nl;
            tail->data[k] = v;
            if (nl > 2 && nodes > 0) {
                unsigned char c;
                unsigned char a = entry[nl - 1];
                unsigned char bq = entry[nl - 3];
                int y;
                int x;
                int m2;
                unsigned char u;
                unsigned char cc;
                int flag;
                int xn;
                int x2;
                int y2;
                Node021e0638* p;
                cellA = bq;
                func_ov000_0216f82c(&nbA, &cellA);
                s1 = nbA;
                cellB = a;
                func_ov000_0216f82c(&nbB, &cellB);
                s2 = nbB;
                m2 = 0;
                for (x = 0; x < 6; x++) {
                    u = s1.b[x];
                    if (u == 0xff) {
                        continue;
                    }
                    for (y = 0; y < 6; y++) {
                        unsigned char w = s2.b[y];
                        if (w == 0xff) {
                            continue;
                        }
                        if (u == w) {
                            common[m2] = u;
                            m2++;
                        }
                    }
                }
                cc = m2;
                if (nodes - 1 == 0) {
                    p = &head;
                } else {
                    p = head.next;
                    for (xn = 0; xn < nodes - 2; xn++) {
                        if (p == 0) {
                            p = 0;
                            break;
                        }
                        p = p->next;
                    }
                }
                flag = 0;
                for (x2 = 0; x2 < cc; x2++) {
                    flag = 1;
                    y2 = 0;
                    c = common[x2];
                    for (; y2 < n; y2++) {
                        if (y2 == i) {
                            continue;
                        }
                        if (c == p->data[y2]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 0) {
                        break;
                    }
                }
                if (flag != 0) {
                    unsigned char* mp = (unsigned char*)((unsigned int)pool + off);
                    mp += nl - 2;
                    mp[0x10] = 1;
                }
            }
            changed = 1;
        }
        Node021e0638* node = (Node021e0638*)alloc->Allocate(0x10);
        if (node == 0) {
            break;
        }
        memcpy(node, tail, 0x10);
        node->next = 0;
        Node021e0638* t = tail->next;
        if (t == 0) {
            tail->next = node;
        } else {
            while (t->next != 0) {
                t = t->next;
            }
            t->next = node;
        }
        nodes++;
        tail = node;
    }
    for (int i = 0; i < n; i++) {
        unsigned char m = 0;
        for (int j = 0; j < pool[i].len; j++) {
            if (pool[i].mark[j] == 0) {
                sendbuf[m++] = pool[i].seq[j];
            }
        }
        _Z24StoreDataWithLen02049410P11Obj02049410Pvi((Obj02049410*)ents[i].obj, sendbuf, m);
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        unsigned char* c = (unsigned char*)_Z25GetCombatantWithFlag0x100P9GameStatei((BattleStruct*)gs, *(short*)(ents[i].obj + 4));
        if (c != 0 && (*(unsigned int*)(c + Field18c) & 1)) {
            flag = 1;
        }
        if (GetSubstructByte0x56(ents[i].obj) != 0 && flag == 0 && self[Fielde78] != 0) {
            _Z30ApplyFlag0x4IfEligible02049a74P11Obj02049a74((Obj02049a74*)ents[i].obj);
        } else {
            ClearSubstructFlag0x4(ents[i].obj);
        }
        ClearSubstructFlag0x40(ents[i].obj);
    }
    for (int i = 0; i < nids; i++) {
        unsigned char* c = (unsigned char*)gs->GetCombatantByIndex(ids[i]);
        if (c != 0 && GetSubstructByte0x34(c) != 0) {
            ClearSubstructFlag0x4(c);
            SetSubstructFlag0x40(c);
        }
    }
    for (int i = 0; i < cur->count8; i++) {
        if (cur->p10 != 0) {
            unsigned char* c = (unsigned char*)gs->GetCombatantByIndex(*(unsigned short*)(cur->p10 + i * 0x34 + 0x20));
            if (c != 0) {
                ClearSubstructFlag0x4(c);
                ClearSubstructFlag0x40(c);
            }
        }
    }
    for (int i = 0; i < cur->count9; i++) {
        if (cur->p14 != 0) {
            unsigned char* c = (unsigned char*)gs->GetCombatantByIndex(*(short*)(cur->p14 + i * 0x24 + 0xe));
            if (c != 0) {
                ClearSubstructFlag0x4(c);
                ClearSubstructFlag0x40(c);
            }
        }
    }
    for (int i = 0; i < cur->count9; i++) {
        if (cur->p14 != 0) {
            unsigned char* c = (unsigned char*)gs->GetCombatantByIndex(*(short*)(cur->p14 + i * 0x24 + 0xe));
            if (c != 0) {
                memset(seen, 0, 0x51);
                Sub148_021e0638* sub = 0;
                int extra = 1;
                if (*(unsigned short*)c & 0x400) {
                    sub = *(Sub148_021e0638**)(c + 0x148);
                }
                if (sub != 0) {
                    unsigned int t2 = (sub->flags << 1) >> 0x1e;
                    if (t2 != 0) {
                        extra += t2;
                    }
                }
                func_ov025_021e120c(seen, GetSubstructByte0x1c(c), 1, extra & 0xff, 0);
                for (int j = 0; j < n; j++) {
                    int id = GetSubstructByte0x1d(ents[j].obj);
                    if (id < 0x51 && seen[id] == 1) {
                        ClearSubstructFlag0x4(c);
                        ClearSubstructFlag0x40(c);
                    }
                }
            }
        }
    }
    ClearGlobalBuffer02107850();
    unsigned char* na = _Z22GetNodeAtIndex02160094P12List02160094i((List02160094*)cur, 0);
    unsigned char* nb = _Z22GetNodeAtIndex021600f8P12List021600f8i((List021600f8*)cur, 0);
    if (na != 0 && nb != 0) {
        unsigned char* ca = (unsigned char*)gs->GetCombatantByIndex(*(unsigned short*)(na + 0x20));
        unsigned char* cb = (unsigned char*)gs->GetCombatantByIndex(*(short*)(nb + 0xe));
        if (ca != 0 && cb != 0) {
            unsigned int id = GetSubstructByte0x1d(ca);
            if (id >= 0x51) {
                id = GetSubstructByte0x1c(ca);
            }
            if (id < 0x51) {
                posCell = id;
                func_ov000_0216f74c(&pos, &posCell);
                pp = pos;
                Vec3_021e0638 va;
                __clear(&va, 0xc);
                va.x = pp.v[0];
                va.z = pp.v[1];
                Vec3_021e0638 vb = *(Vec3_021e0638*)(cb + 0x44);
                vb.y = 0;
                Data021e0638* d = GetData02107850();
                _ZN8Vector3iaSERKS_(&d->a, &va);
                _ZN8Vector3iaSERKS_(&d->b, &vb);
                d->radius = _ZNK8Object3D9GetRadiusEv(ca) >> 1;
                d->flag = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        unsigned char* o = ents[i].obj;
        if (GetSubstructByte0x56(o) != 0 && GetSubstructByte0x34(o) == 0 && CheckHighNibble0xc1Not2To5(o) != 0
            && (*(unsigned int*)(*(unsigned char**)(o + 0x138) + 0x14) & 1) == 0 && self[Fielde78] != 0
            && CheckSubstructFlag0x200(o) == 0) {
            _Z26DispatchTargetByte020494c0P11Obj020494c0((Obj020494c0*)o);
        }
    }
}
