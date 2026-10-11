// JPN: func_ov025_021e91c0
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _Z15GetData02108e10v();
extern "C" void* _Z19GetActiveCombatWorkv();
extern "C" void* _Z18GetSlotPtr02160f20Pv(void* work);
extern "C" void* _Z22GetNodeAtIndex02160094P12List02160094i(void* list, int idx);
extern "C" void* _Z22GetNodeAtIndex021600f8P12List021600f8i(void* list, int idx);
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void* gs, int idx);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void* gs, int idx);
extern "C" void* _Z25GetCombatantWithFlag0x400P9GameStatei(void* gs, int idx);
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(void* gs, int idx);
extern "C" int _ZNK8Object3D10GetField78Ev(void* obj);
extern "C" int _ZNK8Object3D10GetField7aEv(void* obj);
extern "C" void _Z26SetForwardAndStore0205ebc0Pvii(void* obj, int a, int b);
extern "C" void _Z32ForwardToTargetOrDefault0205eabcPvS_i(void* obj, void* target, int arg);
extern "C" void* _Z24SearchBothTables02079e2cPci(void* data, int id);
extern "C" int _Z27SetSlotEntryNoFlag_021eb42cPvss(void* self, short b, short c);
extern "C" int _Z21SetSlotEntry_021eb148Pvssh(void* self, short b, int c, unsigned char d);
extern "C" void* func_ov000_0215ffa0(void* node);
extern "C" void* _Z23FindNodeAtDepth0215fff4Pvii(void* node, int limit, int idx);
extern "C" int func_ov000_0215fd90(void* obj, int flag);
extern "C" void _Z24InitQueueStruct_021ed124Ph(unsigned char* obj);
extern "C" void _Z22InitContainer_021ebab4Pc(char* obj);
extern "C" void _Z23SetIntField360_021ed31cPci(char* obj, void* val);
extern "C" void _Z15SetName021ed324PvPKc(void* obj, const char* name);
extern "C" void _Z23SetIntField356_021ed314Pci(char* obj, void* val);
extern "C" void _Z19ResetStruct0216fe48P14Struct0216fe48(char* obj);
extern "C" void _Z29SetField0FromCallFunc0202fa38P14Struct0216fd0c(char* obj);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
#if defined(jpn)
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void* loader, const char* path, void* alloc);
extern int data_ov025_021efb88;
#else
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void* loader, const char* a, const char* b, void* alloc);
#endif
extern "C" void* _Z20GetOffsetPtr02160f08Pv(void* work);
extern "C" short* _Z22FindEntryById_021dafd0Pci(void* p, int id);
extern "C" void _ZN8Object3D10EnableFlagEi(void* obj, int flag);
extern "C" void func_ov025_021ded50(void* work, void* rec);

extern int data_ov025_021ef990;
extern int data_ov025_021ef9a4;
extern int data_ov025_021ef9c0;
extern int data_02108760;
extern int data_ov025_021ef9a8[6];
extern int data_ov025_021ef8b4;
extern int data_ov025_021ef8ca;

static inline int InRange(int v) {
    return v >= 0xc0 && v <= 0xc7;
}

#if defined(jpn)
enum { CombatantTailPadding = 0x8 };
#else
enum { CombatantTailPadding = 0x14 };
#endif

struct Slot {
    unsigned short type;
    short pad2;
    short id;
    short pad6;
    char pad8;
    unsigned char count;
    char padA[2];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    char padD[3];
    struct Node* head;
};

struct Node {
    char pad0[0x20];
    unsigned short id;
    char pad22[10];
    unsigned char flag2c;
    char pad2d[3];
    struct Node* next;
};

struct Entry {
    char pad0[0x14];
    unsigned int kindWord;
    unsigned int f18;
    unsigned int pad1c;
    unsigned int id20 : 10;
};

struct Rec {
    short a;
    short b;
    short c;
};

struct Combatant {
    char pad0[2];
    short id;
    char pad4[0x134];
    char* flagsObj;
    char pad13c[CombatantTailPadding];
    char* extra;
};

// USA: func_ov025_021e8d20
extern "C" ARM void func_ov025_021e8d20(char* self, char* arg) {
    char* kn;
    int in;
    int kb;
    void* gs = _ZN9GameState11GetInstanceEv();
    void* data = _Z15GetData02108e10v();
    void* work = _Z19GetActiveCombatWorkv();
    Slot* slot = (Slot*)_Z18GetSlotPtr02160f20Pv(work);
    *(char**)self = arg;
    *(int*)(self + 4) = *(int*)(arg + 8);
    int flag = 0;
    data_ov025_021ef9a4 = 0;
    data_ov025_021ef990 = 0;
    data_ov025_021ef9c0 = 0;
    *(int*)(self + 0x1c4) = 0;
    *(int*)(self + 0x1d8) = 0;
    *(short*)(self + 0x21c) = 1;
    *(short*)(self + 0x21e) = 0;
    *(short*)(self + 0x220) = 0x1e;
    *(short*)(self + 0x222) = -1;
    self[0x5ca] = 0;
    self[0x5cb] = 0;
    self[0x5cc] = 0;
    self[0x5d0] = 0;
    self[0x5d1] = 0;
    *(int*)(self + 0x5e4) = 0;
    Node* first = (Node*)_Z22GetNodeAtIndex02160094P12List02160094i(slot, 0);
    if (first != 0) {
        if (InRange(first->id)) {
            flag = 1;
            void* obj = _ZN9GameState20GetGameObjectByIndexEi(gs, first->id);
            if (obj != 0) {
                int a = _ZNK8Object3D10GetField78Ev(obj);
                int b = _ZNK8Object3D10GetField7aEv(obj);
                _Z26SetForwardAndStore0205ebc0Pvii(&data_02108760, a, b);
            }
        }
    }
    if (slot->type == 1 || slot->type == 2) {
        *(int*)(self + 0x224) = 1;
    } else {
        *(int*)(self + 0x224) = 0;
    }
    Entry* entry = (Entry*)_Z24SearchBothTables02079e2cPci(data, (short)slot->type);
    *(Entry**)(self + 8) = entry;
    if ((entry != 0 && ((entry->f18 << 16) >> 28) == 2) || slot->type == 0x1f8 || slot->type == 0x392) {
        int low = 0;
        _Z22GetNodeAtIndex02160094P12List02160094i(slot, low);
        Node* n = (Node*)_Z22GetNodeAtIndex02160094P12List02160094i(slot, low);
        if (n->id <= 3) low = 1;
        if (low != 0) {
            _Z27SetSlotEntryNoFlag_021eb42cPvss(self, 4, 0x14);
            *(int*)(self + 0x1c4) |= 2;
        } else {
            _Z27SetSlotEntryNoFlag_021eb42cPvss(self, 4, 0x6f);
        }
    }
    for (int i = 0; i < slot->count; i++) {
        char* node = (char*)_Z22GetNodeAtIndex021600f8P12List021600f8i(slot, i);
        if (node == 0) continue;
        unsigned char* kinds = (unsigned char*)node + 0x14;
        int j = 1;
        for (; j < (unsigned char)node[0x17]; j++) {
            int k = kinds[j];
            if (k == 3) {
                unsigned short prev = *(unsigned short*)(node + (j - 1) * 2 + 0xe);
                int small = prev <= 3 ? 1 : 0;
                if (small == 0) {
                    Combatant* c = (Combatant*)_Z25GetCombatantWithFlag0x400P9GameStatei(gs, prev);
                    if (c != 0 && c->id == 0xf4) {
                        _Z21SetSlotEntry_021eb148Pvssh(self, 0x1a, 0xcfe5, 1);
                    }
                    flag = 1;
                } else {
                    _Z27SetSlotEntryNoFlag_021eb42cPvss(self, 0x22, 1);
                }
            } else if (k == 2) {
                _Z21SetSlotEntry_021eb148Pvssh(self, 0x20, 0x2c6, 3);
            } else if (!(k != 5 && k != 4)) {
                short prev = *(short*)(node + (j - 1) * 2 + 0xe);
                in = 0;
                if (prev >= 0) in = prev <= 3;
                if (in == 0) flag = 1;
                _Z21SetSlotEntry_021eb148Pvssh(self, 0x23, 0x4d8, 3);
            }
        }
        {
            void* cid = func_ov000_0215ffa0(node);
            Combatant* c = (Combatant*)_ZN9GameState19GetCombatantByIndexEi(gs, (int)cid);
            if (c != 0 && (*(unsigned int*)(c->flagsObj + 0x18) & 0x20)) {
                _Z21SetSlotEntry_021eb148Pvssh(self, 0x1f, 0xb2c, 3);
                *(short*)(self + 0x21c) = 0x1f;
            }
        }
        for (int k = 0; k < 3; k++) {
            kb = (unsigned char)k;
            int m = 0;
            kn = node + k;
            for (; m < (unsigned char)kn[0x18]; m++) {
                void* f = _Z23FindNodeAtDepth0215fff4Pvii(node, m, kb);
                if (f != 0 && f != 0) {
                    if (func_ov000_0215fd90(f, 0xd)) {
                        _Z27SetSlotEntryNoFlag_021eb42cPvss(self, 0x1b, 0x3c);
                    }
                    if (func_ov000_0215fd90(f, 0xc)) {
                        _Z21SetSlotEntry_021eb148Pvssh(self, 0x19, 0x38e, 2);
                    } else if (func_ov000_0215fd90(f, 6) == 0) {
                        _Z32ForwardToTargetOrDefault0205eabcPvS_i(&data_02108760, 0, 0);
                        if (((unsigned char*)f)[0x1c] != 0 && flag != 0) {
                            unsigned int t = slot->type;
                            if (t == 0xf4 || t == 0xf5 || t == 0x48 || t == 0x70) {
                                _Z27SetSlotEntryNoFlag_021eb42cPvss(self, 0x24, 0xb);
                            }
                        }
                    }
                }
            }
        }
    }
    memset(self + 0x1c8, 0, 0x10);
    data_ov025_021ef9a8[0] = 0;
    data_ov025_021ef9a8[1] = -1;
    data_ov025_021ef9a8[2] = 0;
    data_ov025_021ef9a8[3] = 0;
    data_ov025_021ef9a8[4] = 0;
    data_ov025_021ef9a8[5] = 0;
    _Z24InitQueueStruct_021ed124Ph((unsigned char*)(self + 0x5e8));
    _Z22InitContainer_021ebab4Pc(self + 0x22c);
    *(char**)(self + 0x538) = self + 0x5e8;
    *(int*)(self + 0x540) = 0;
    *(int*)(self + 0x544) = 0;
    *(int*)(self + 0x548) = 0;
    *(int*)(self + 0x54c) = 0;
    *(int*)(self + 0x550) = 0;
    *(short*)(self + 0x554) = -1;
    *(short*)(self + 0x556) = -1;
    *(int*)(self + 0x558) = 0;
    *(short*)(self + 0x55c) = -1;
    *(short*)(self + 0x55e) = -1;
    *(int*)(self + 0x560) = 0;
    *(short*)(self + 0x564) = 0;
    *(short*)(self + 0x566) = 0;
    *(short*)(self + 0x568) = 0;
    *(short*)(self + 0x56c) = 0;
    *(short*)(self + 0x56a) = 0;
    *(short*)(self + 0x572) = 0;
    *(short*)(self + 0x570) = 0;
    *(short*)(self + 0x56e) = 0;
    self[0x574] = 0;
    self[0x575] = 0;
    self[0x578] = 0;
    entry = (Entry*)_Z24SearchBothTables02079e2cPci(data, (short)slot->type);
    if (entry != 0) {
        unsigned int kind = entry->kindWord >> 28;
        if (!(kind != 3 && kind != 4)) {
            if (((entry->f18 << 20) >> 25) == 1) self[0x53d] = 1;
        }
    }
    if (slot->type == 1 && first != 0) {
        Combatant* c = (Combatant*)_Z25GetCombatantWithFlag0x100P9GameStatei(gs, first->id);
        if (c != 0) {
            char* p = c->extra + 0x294;
            if (p != 0) {
                unsigned int f = (*(unsigned int*)(p + 8) << 23) >> 27;
                if (f == 4 || f == 10) self[0x53d] = 1;
            }
        }
    }
    if ((slot->b1 && slot->b2) || (slot->b4 && slot->b5)) {
        self[0x5d0] = 1;
    }
    _Z23SetIntField360_021ed31cPci(self + 0x5e8, self + 0x798);
    _Z15SetName021ed324PvPKc(self + 0x5e8, 0);
    _Z23SetIntField356_021ed314Pci(self + 0x5e8, slot);
    _Z19ResetStruct0216fe48P14Struct0216fe48(self + 0x798);
    _Z29SetField0FromCallFunc0202fa38P14Struct0216fd0c(self + 0x798);
    self[0x87c] = 0;
    *(int*)(self + 0x880) = -1;
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    int id = 0;
    Node* nd = (Node*)_Z22GetNodeAtIndex02160094P12List02160094i(slot, 0);
    void* offs = _Z20GetOffsetPtr02160f08Pv(work);
    short* e = 0;
    if (nd != 0) e = _Z22FindEntryById_021dafd0Pci(offs, nd->id);
    if (e != 0) id = e[0x2c / 2];
    if (slot->id != 0) id = slot->id;
    if (id > 0) {
        if (id == *(int*)(self + 0x884)) {
            _Z15SetName021ed324PvPKc(self + 0x5e8, self + 0x83c);
#if !defined(jpn)
            *(short*)(self + 0x794) = id;
#endif
            self[0x87c] = 1;
        } else {
            *(int*)(self + 0x884) = id;
#if defined(jpn)
            *(int*)(self + 0x880) = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, (const char*)&data_ov025_021efb88, 0);
#else
            *(int*)(self + 0x880) = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, (const char*)&data_ov025_021ef8b4, (const char*)&data_ov025_021ef8ca, 0);
#endif
            if (*(int*)(self + 0x880) < 0) self[0x87c] = 1;
        }
    } else {
        *(int*)(self + 0x884) = 0;
        self[0x87c] = 1;
        _Z15SetName021ed324PvPKc(self + 0x5e8, 0);
    }
    for (Node* n = slot->head; n != 0; n = n->next) {
        void* c = _ZN9GameState19GetCombatantByIndexEi(gs, n->id);
        if (c != 0) {
            _ZN8Object3D10EnableFlagEi(c, 0x800);
            if (n->flag2c != 0) {
                int small = n->id <= 3 ? 1 : 0;
                if (small != 0) {
                    void* t = _Z24SearchBothTables02079e2cPci(data, 0x39a);
                    if (t != 0) {
                        Rec rec;
                        rec.a = n->id;
                        rec.b = 0x39a;
                        rec.c = ((Entry*)t)->id20;
                        func_ov025_021ded50(work, &rec);
                    }
                }
            }
        }
    }
    *(short*)(self + 0x57c) = 0;
    *(short*)(self + 0x57e) = 0;
    *(short*)(self + 0x580) = 0x333;
    self[0x582] = 0;
    self[0x5c5] = 0;
    self[0x5c6] = 0;
    *(int*)(self + 0x228) = 0;
    *(short*)(self + 0x5c8) = 0xff;
    *(short*)(self + 0x5ce) = 0;
}
