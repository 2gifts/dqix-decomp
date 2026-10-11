#include <globaldefs.h>

#if defined(jpn)
enum { field7=6,fieldB=8,field6=4,field8=7,extensionOffset=0x144,statsOffset=0x7b8 };
#else
enum { field7=7,fieldB=0xb,field6=6,field8=8,extensionOffset=0x150,statsOffset=0x850 };
#endif

// ---- externs resolved by the scaffold ----
extern "C" extern void _Z36SetNodeFieldsAndMaybeNotify_0215f6f4Pvssi(void* a, short v1, short v2, int flag);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(void* battleStruct, int id);
extern int GetFieldAt0x150(unsigned char* obj);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" extern int _Z33AccumulateFlaggedSlotBits02085fb4Ph(unsigned char* actor);
extern "C" extern int _Z33AccumulateFlaggedSlotBits02086020Ph(unsigned char* actor);
extern "C" extern int _Z33AccumulateFlaggedSlotBits0208608cPh(unsigned char* actor);
extern "C" extern int _Z33AccumulateFlaggedSlotBits020860f8Ph(unsigned char* actor);
extern "C" extern int _Z33AccumulateFlaggedSlotBits02086164Ph(unsigned char* actor);
extern "C" extern int _Z33AccumulateFlaggedSlotBits020861d0Ph(unsigned char* actor);
extern "C" extern int _Z33AccumulateFlaggedSlotBits0208623cPh(unsigned char* actor);
extern "C" extern int _Z35AccumulateSlotBitsFromTable020862a8Ph(unsigned char* actor);
extern "C" extern int _Z35AccumulateSlotBitsFromTable02086314Ph(unsigned char* actor);
extern "C" void _Z27SetField38IfState8_0215e49cPvis(void* a, int key, int value);
extern "C" extern int func_ov023_021f6f10(void* self);
extern "C" extern int _Z27CheckAfterTwoCalls_0215e460v(void);
extern "C" int func_ov004_0215e4e8(void* a, int key);
extern "C" extern int _Z20GetTableByte020dd11cjj(unsigned int a, unsigned int b);

// same class already matched in SetScaledVecX_0215e574.cpp -- reused verbatim so the
// GetVal0x20()/SetVal0x1c() ABI (hidden-return + this in r1, this in r0 + &param in r1) matches.
struct Vector3i {
    int x, y, z;
    Vector3i& operator=(const Vector3i& o);
};
typedef Vector3i Vec3_0216033c;
class Node0215e47c {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetVal0x1c(const Vec3_0216033c& v);
    virtual Vec3_0216033c GetVal0x20();
};
extern "C" Node0215e47c* func_ov004_0215e47c(void* a, int key);


extern "C" extern void* _Z24CheckNodeState6_0215e4c0Pvi(void* a, int key);
struct ObjE2_021f8944;
extern "C" extern void _Z31SetFieldE2AndMaybeCall_021f8944P14ObjE2_021f8944iii(struct ObjE2_021f8944* obj, int a1, int a2, int a3);

// the two globals every literal-pool load in this function resolves to (verified by
// computing pc+8+imm for every `ldr rX,[pc,#N]` -- see HANDOFF).
extern unsigned char data_ov004_021707e8;
extern int data_ov004_02170854[];
#define D0 (&data_ov004_021707e8)
#define D1 (data_ov004_02170854)

class FNode0216033c {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void SetState(int arg);
    virtual void vfdc();
    virtual void SetValue(int arg);
    unsigned char pad0[0xc - 4];
    unsigned char field0xc;
    char pad1[0x20 - 0xd];
    int field0x20;
    char pad2[0x38 - 0x24];
    short field0x38;
};
extern "C" FNode0216033c* func_ov023_021f6880(void* obj, int key);

struct Field134_0216033c {
    char pad[0x30];
    unsigned short s30, s32, s34, s36;
};

struct Flags49c {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

struct Packed3x10 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int pad : 2;
};

// USA: func_ov004_0216033c
extern "C" ARM int func_ov004_0216033c(void* a) {
    int i;
    Packed3x10* rowBase;
    FNode0216033c* node;
    unsigned char* base150;
    unsigned char* combatant;
    *(unsigned char*)((char*)D0 + field7) = 0x64;
    short v1 = *(signed char*)((char*)D0 + fieldB);
    short v2 = *(signed char*)((char*)D0 + field6);
    _Z36SetNodeFieldsAndMaybeNotify_0215f6f4Pvssi(a, v1, v2, 0);

    int combatantId = *(int*)((char*)D0 + 0x1c);
    unsigned char sb = *(unsigned char*)((char*)D0 + field8);
    void* bs = _ZN9GameState11GetInstanceEv();
    combatant = (unsigned char*)_Z25GetCombatantWithFlag0x100P9GameStatei(bs, combatantId);
    if (!combatant) goto stats_done;
    base150 = (unsigned char*)GetFieldAt0x150(combatant);
    if (!base150) goto stats_done;
    {

    short st10, st9, st8, st7, st6, st5, st4, st3, st2, st1, st0;
    void* obj118a = func_ov011_021849c8(a);

    int t1 = D1[sb];
    int rowIndex = combatantId * 0xc + (t1 - 1);
    rowBase = (Packed3x10*)(*(int*)((char*)D0 + 0x14) + rowIndex * 0x18);

    for (i = 0; i < 0xe; i++) {
        node = func_ov023_021f6880(obj118a, i + 0x51);
        if (!node) continue;

        int t2 = D1[sb];
        if (*(unsigned char*)((char*)D0 + 2) == t2) {
            Packed3x10* f150;
            unsigned short val16;
            switch (i) {
            case 0: f150 = *(Packed3x10**)((char*)combatant + extensionOffset); val16 = f150[0].a; node->SetValue(val16); break;
            case 1: f150 = *(Packed3x10**)((char*)combatant + extensionOffset); val16 = f150[0].b; node->SetValue(val16); break;
            case 2: f150 = *(Packed3x10**)((char*)combatant + extensionOffset); val16 = f150[0].c; node->SetValue(val16); break;
            case 3: f150 = *(Packed3x10**)((char*)combatant + extensionOffset); val16 = f150[1].a; node->SetValue(val16); break;
            case 4: f150 = *(Packed3x10**)((char*)combatant + extensionOffset); val16 = f150[1].b; node->SetValue(val16); break;
            case 5: f150 = *(Packed3x10**)((char*)combatant + extensionOffset); val16 = f150[1].c; node->SetValue(val16); break;
            case 6: f150 = *(Packed3x10**)((char*)combatant + extensionOffset); val16 = f150[2].a; node->SetValue(val16); break;
            case 7: val16 = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x134) + 0x30); node->SetValue(val16); break;
            case 8: val16 = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x134) + 0x32); node->SetValue(val16); break;
            case 9: val16 = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x134) + 0x34); node->SetValue(val16); break;
            case 10: val16 = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x134) + 0x36); node->SetValue(val16); break;
            case 11: f150 = *(Packed3x10**)((char*)combatant + extensionOffset); val16 = f150[3].a; node->SetValue(val16); break;
            case 12: val16 = *(unsigned short*)(base150 + 0x100 + t2 * 2 + 0x6c); node->SetValue(val16); break;
            case 13: { int val32 = *(int*)(base150 + t2 * 4 + 0x138); node->SetValue(val32); } break;
            default: break;
            }
            node->SetState(0xf);
        } else {
            int actorBase = GetFieldAt0x150(combatant) + statsOffset;
            int t3 = D1[sb];
            int entryOff = (t3 & 0xff) * 0xc;
            Packed3x10* entryBase = (Packed3x10*)(actorBase + entryOff);

            st0 = (_Z33AccumulateFlaggedSlotBits02085fb4Ph(base150) + rowBase[0].a + entryBase[0].a);
            st1 = (_Z33AccumulateFlaggedSlotBits02086020Ph(base150) + rowBase[0].b + entryBase[0].b);
            st2 = (_Z33AccumulateFlaggedSlotBits0208608cPh(base150) + rowBase[0].c + entryBase[0].c);
            st3 = (_Z33AccumulateFlaggedSlotBits020860f8Ph(base150) + rowBase[1].a + entryBase[1].a);
            st4 = (_Z33AccumulateFlaggedSlotBits02086164Ph(base150) + rowBase[1].b + entryBase[1].b);
            st5 = (_Z33AccumulateFlaggedSlotBits020861d0Ph(base150) + rowBase[1].c + entryBase[1].c);
            st6 = (_Z33AccumulateFlaggedSlotBits0208623cPh(base150) + rowBase[2].a + entryBase[2].a);
            st7 = (_Z35AccumulateSlotBitsFromTable020862a8Ph(base150) + rowBase[2].b + entryBase[2].b);
            st8 = (_Z35AccumulateSlotBitsFromTable02086314Ph(base150) + rowBase[2].c + entryBase[2].c);
            st9 = st0;
            st10 = st2;
            int reg11 = (short)(_Z33AccumulateFlaggedSlotBits02086164Ph(base150) + rowBase[3].a + entryBase[1].b);

            enum { CAP = 999 };
            if (st0 > CAP) st0 = CAP;
            if (st1 > CAP) st1 = CAP;
            if (st2 > CAP) st2 = CAP;
            if (st3 > CAP) st3 = CAP;
            if (st4 > CAP) st4 = CAP;
            if (st5 > CAP) st5 = CAP;
            if (st6 > CAP) st6 = CAP;
            if (st7 > CAP) st7 = CAP;
            if (st8 > CAP) st8 = CAP;
            if (st9 > CAP) st9 = CAP;
            if (st10 > CAP) st10 = CAP;
            if (reg11 > CAP) reg11 = CAP;

            switch (i) {
            case 0: node->SetValue(st0); break;
            case 1: node->SetValue(st1); break;
            case 2: node->SetValue(st2); break;
            case 3: node->SetValue(st3); break;
            case 4: node->SetValue(st4); break;
            case 5: node->SetValue(st5); break;
            case 6: node->SetValue(st6); break;
            case 7: node->SetValue(st7); break;
            case 8: node->SetValue(st8); break;
            case 9: node->SetValue(st9); break;
            case 10: node->SetValue(st10); break;
            case 11: node->SetValue(reg11); break;
            case 12: { unsigned short v16 = *(unsigned short*)(base150 + 0x100 + D1[sb] * 2 + 0x6c); node->SetValue(v16); } break;
            case 13: { int val32 = *(int*)(base150 + D1[sb] * 4 + 0x138); node->SetValue(val32); } break;
            default: break;
            }
            node->SetState(3);
        }
    }

    {
        if (!(*(Flags49c**)(combatant + extensionOffset))->bit0) {
            _Z27SetField38IfState8_0215e49cPvis(a, 0xe, 2);
        } else {
            _Z27SetField38IfState8_0215e49cPvis(a, 0xe, 3);
        }
    }

    {
        FNode0216033c* node = func_ov023_021f6880(obj118a, 0xe);
        if (node) {
            if (*(unsigned char*)((char*)D0 + 2) == D1[sb]) {
                node->SetState(0xf);
            } else {
                node->SetState(3);
            }
        }
    }

    {
        FNode0216033c* node = func_ov023_021f6880(obj118a, 0xc);
        if (node) {
            if (func_ov023_021f6f10(node) == 8) {
                node->field0x20 = *(int*)((char*)combatant + 0x134);
                FNode0216033c* node2 = func_ov023_021f6880(obj118a, 0xe);
                if (node2) {
                    if (*(unsigned char*)((char*)D0 + 2) == D1[sb]) {
                        node2->SetState(0xf);
                    } else {
                        node2->SetState(3);
                    }
                }
            }
        }
    }

    {
        for (int j = 0; j < 0x13; j++) {
            FNode0216033c* node = func_ov023_021f6880(obj118a, j + 0x12c);
            if (node && func_ov023_021f6f10(node) == 8) {
                if (*(unsigned char*)((char*)D0 + 2) == D1[sb]) {
                    node->SetState(0xf);
                } else {
                    node->SetState(3);
                }
            }
        }
    }

    {
        int t4 = D1[sb];
        unsigned char statId = *(unsigned char*)(base150 + t4 + 0x186);
        FNode0216033c* node = func_ov023_021f6880(obj118a, 0xc8);
        if (node) {
            if (statId != 0) {
                node->field0xc &= ~8;
                node->field0x38 = statId + 0x1d3;
                if (statId == 0xa) {
                    node->SetState(0xd);
                } else {
                    node->SetState(5);
                }
            } else {
                node->field0xc |= 8;
            }
        }
    }

    }
stats_done:

    int r4 = 0;
    switch (D1[*(unsigned char*)((char*)D0 + field8)]) {
    case 0: r4 = 4; break;
    case 1: r4 = 5; break;
    case 2: r4 = 6; break;
    case 3: r4 = 7; break;
    case 4: r4 = 8; break;
    case 5: r4 = 9; break;
    case 6: r4 = 0xa; break;
    case 7: r4 = 0xb; break;
    case 9: r4 = 0xd; break;
    case 8: r4 = 0xc; break;
    case 12: r4 = 0x10; break;
    case 10: r4 = 0xe; break;
    case 11: r4 = 0xf; break;
    }
    if (_Z27CheckAfterTwoCalls_0215e460v() != 0) r4 = 4;
    _Z27SetField38IfState8_0215e49cPvis(a, 0xf, r4);

    int r5v = func_ov004_0215e4e8(a, 0xf);
    Node0215e47c* vnode = func_ov004_0215e47c(a, 0xf);
    if (vnode) {
        const Vector3i& gv = vnode->GetVal0x20();
        Vector3i v2;
        v2 = gv;
        v2.x = ((0x80 - r5v) >> 1) << 12;
        vnode->SetVal0x1c(v2);
        int r2v = v2.x + ((r5v + 2) << 12);
        v2.x = r2v;
#if defined(jpn)
        v2.y += 0x2000;
#endif
        Node0215e47c* vnode2 = func_ov004_0215e47c(a, 0xc8);
        if (vnode2) {
            vnode2->SetVal0x1c(v2);
        }
    }

    int combatantId2 = *(int*)((char*)D0 + 0x1c);
    unsigned char sb2 = *(unsigned char*)((char*)D0 + field8);
    void* bs2 = _ZN9GameState11GetInstanceEv();
    unsigned char* combatant2 = (unsigned char*)_Z25GetCombatantWithFlag0x100P9GameStatei(bs2, combatantId2);
    FNode0216033c* iconNode;
    int tv;
    FNode0216033c* nameNode;
    int k;
    int idx;
    FNode0216033c* kNode;
    int hidden;
    int msgId;
    void* obj118b = func_ov011_021849c8(a);
    idx = 0;
    msgId = 0;
    hidden = 0;
    if (_Z27CheckAfterTwoCalls_0215e460v() != 0) hidden = 1;

    for (k = 0; k < 5; k++) {
        tv = _Z20GetTableByte020dd11cjj(D1[sb2] & 0xff, k & 0xff);
        switch (tv) {
        case 1: msgId = 0x12; break;
        case 2: msgId = 0x13; break;
        case 3: msgId = 0x14; break;
        case 4: msgId = 0x15; break;
        case 5: msgId = 0x16; break;
        case 6: msgId = 0x17; break;
        case 7: msgId = 0x18; break;
        case 8: msgId = 0x19; break;
        case 9: msgId = 0x1a; break;
        case 10: msgId = 0x1b; break;
        case 11: msgId = 0x1c; break;
        case 12: msgId = 0x1d; break;
        case 13: msgId = 0x1e; break;
        case 14: msgId = 0x1f; break;
        case 15: msgId = 0x20; break;
        case 16: msgId = 0x21; break;
        case 17: msgId = 0x22; break;
        case 18: msgId = 0x23; break;
        case 19: msgId = 0x24; break;
        case 20: msgId = 0x25; break;
        case 21: msgId = 0x26; break;
        case 22: msgId = 0x27; break;
        case 23: msgId = 0x28; break;
        case 24: msgId = 0x29; break;
        case 25: msgId = 0x2a; break;
        case 26: msgId = 0x2b; break;
        }
        _Z27SetField38IfState8_0215e49cPvis(a, idx + 0x2a, msgId);

        kNode = func_ov023_021f6880(obj118b, k + 0x5f);
        if (kNode) {
            kNode->SetValue(*(unsigned char*)(*(unsigned char**)(combatant2 + extensionOffset) + tv + 0x464));
            if (*(unsigned char*)((char*)D0 + 2) != D1[sb2]) {
                kNode->SetState(3);
            } else if (*(unsigned char*)(*(unsigned char**)(combatant2 + extensionOffset) + tv + 0x464) >= 100) {
                kNode->SetState(0xd);
            } else {
                kNode->SetState(0xf);
            }

            nameNode = 0;
            FNode0216033c* tmp = func_ov023_021f6880(obj118b, idx + 0x2a);
            if (tmp && func_ov023_021f6f10(tmp) == 8) nameNode = tmp;
            iconNode = 0;
            FNode0216033c* tmp2 = func_ov023_021f6880(obj118b, k + 0x13a);
            if (tmp2 && func_ov023_021f6f10(tmp2) == 8) iconNode = tmp2;

            if (hidden != 0) {
                kNode->field0xc |= 8;
                if (nameNode) nameNode->field0xc |= 8;
                if (iconNode) iconNode->field0xc |= 8;
            } else {
                kNode->field0xc &= ~8;
                if (nameNode) nameNode->field0xc &= ~8;
                if (iconNode) iconNode->field0xc &= ~8;
            }

            idx += 2;
        }
    }

    unsigned char langByte = *(unsigned char*)((char*)D0 + field8);
    int kind;
    int r5final;
    void* obj118c = func_ov011_021849c8(a);
    r5final = 0;
    kind = 0xf;
    if (*(unsigned char*)((char*)D0 + 2) == D1[langByte]) {
        for (int m = 0; m < 0x28; m++) {
            FNode0216033c* n2 = func_ov023_021f6880(obj118c, m + 0xc);
            if (n2) n2->SetState(kind);
        }
        for (int m = 0; m < 3; m++) {
            FNode0216033c* n2 = func_ov023_021f6880(obj118c, m + 0x64);
            if (n2) n2->SetState(kind);
        }
    } else {
        for (r5final = 0; r5final < 0x28; r5final++) {
            FNode0216033c* n2 = func_ov023_021f6880(obj118c, r5final + 0xc);
            if (n2) n2->SetState(3);
        }
        for (r5final = 0; r5final < 3; r5final++) {
            FNode0216033c* n2 = func_ov023_021f6880(obj118c, r5final + 0x64);
            if (n2) n2->SetState(3);
        }
        r5final = 1;
        kind = 3;
    }
    void* node6 = _Z24CheckNodeState6_0215e4c0Pvi(a, 3);
    if (node6) {
        *(unsigned char*)((char*)node6 + 0x10a) = (unsigned char)kind;
        _Z31SetFieldE2AndMaybeCall_021f8944P14ObjE2_021f8944iii((struct ObjE2_021f8944*)node6, (int)(long)a, r5final, 1);
    }

    return 0;
}
