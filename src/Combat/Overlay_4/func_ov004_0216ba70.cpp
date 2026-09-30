#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
extern "C" struct BattleStruct* _ZN9GameState11GetInstanceEv();
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Vector3i {
    int x, y, z;
    Vector3i& operator=(const Vector3i& other);
};
typedef Vector3i Vec3;

class VObjNode {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void Method1c(Vec3* arg);
    virtual Vec3 Method20();
    virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53();
    virtual void MethodD8(int arg);
    virtual void v55();
    virtual void MethodE0(int arg);
    char pad[0x1c];
    void* field20;
};

struct CombatantRecord {
    char pad0[0x30];
    unsigned char type30;
    unsigned char level31;
    unsigned short field32;
};

struct BattleRegion4000 {
    CombatantRecord records[4];
    int totalValue;
    unsigned char flagD4;
    unsigned char flagD5;
    unsigned char flagD6;
    unsigned char flagD7;
};

struct BattleRegion3e80 {
    char pad4000[0x4000];
    BattleRegion4000 region4000;
};

struct BattleStructExt {
    char pad3e80[0x3e80];
    BattleRegion3e80 region3e80;
};

struct DataTable02171034 {
    char pad0[6];
    unsigned char byte6;
    unsigned char byte7;
    unsigned short short8;
    char pad1[2];
    int fieldC;
};

struct Struct0200fb08;
extern unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
extern int CallFunc020e0434With02153694(int value);
struct Obj_02184ad8;
extern void SetField1c8True_02184ad8(struct Obj_02184ad8* obj);
void* GetNodeIfType6_0216ae9c(void* a, int id);

extern "C" void* func_ov011_021849c8(void*);
extern "C" VObjNode* func_ov023_021f6880(void* obj, int key);
extern "C" void func_ov023_021f8120(void* obj);
extern "C" void func_ov023_021f7eb8(void* node, void* a, int buf, int mode, int a5, int a6, int a7, int a8, int a9, int a10);

extern "C" void func_ov004_0216afb0(void* a1, int p2, int p3, int p4,
    int p5, int p6, int p7, int p8, unsigned char p9);
extern "C" void func_ov004_0216b06c(void* obj, int p1, int p2, int p3, int p4, int p5, int p6, int p7, unsigned char p8);
extern "C" void func_ov004_0216b120(void* p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7);
extern "C" int func_ov004_0216aed0(void* a, int b, int c, int d);
extern "C" int func_ov004_0216af24(void* a, short key);

extern DataTable02171034 data_ov004_02171034;

static inline BattleRegion4000* GetRegion(struct BattleStruct* bs) {
    return &((BattleStructExt*)bs)->region3e80.region4000;
}
struct ShortPair0217017a { short a; short b; };
extern ShortPair0217017a data_ov004_0217017a[];

static inline void SetNodePosXe(VObjNode* node, int x) {
    const Vec3& t = node->Method20();
    Vec3 pos;
    _ZN8Vector3iaSERKS_((int*)&pos, (int*)&t);
    pos.x = x;
    node->Method1c(&pos);
}

static inline void MoveNodeXv(VObjNode* node, Vec3 p, int dx) {
    p.x = p.x + dx;
    node->Method1c(&p);
}

static inline void ShowHeadBV(void* a, VObjNode* node2, Vec3 savedPos) {
    MoveNodeXv(node2, savedPos, 0x4000);
    func_ov004_0216afb0(a, 0x5a, 2, 0xd3, 31, 60, 5, 8, 1);
}

static inline Vec3 CopyV1(const Vec3& v) {
    Vec3 r = v;
    return r;
}

static inline Vec3 CopyR2(const Vec3& v) {
    Vec3 r = CopyV1(v);
    return r;
}

static inline Vec3 CopyR2b(const Vec3& v) {
    return CopyR2(v);
}

static inline Vec3 GetPosZ1(VObjNode* n) {
    const Vec3& t = n->Method20();
    return CopyR2b(t);
}

// USA: func_ov004_0216ba70
extern "C" ARM int func_ov004_0216ba70(void* a) {
    int count;
    int i;
    int delta;
    int base;
    BattleRegion4000* ext;
    struct BattleStruct* bs2;
    BattleRegion4000* reg2;
    Vec3 v6c;

    ext = &((BattleStructExt*)_ZN9GameState11GetInstanceEv())->region3e80.region4000;
    count = ext->flagD4;

    bs2 = _ZN9GameState11GetInstanceEv();
    reg2 = GetRegion(bs2);

    func_ov004_0216afb0(a, 0x37, 2, 0xd3, 6, 0x46, 4, 0xa, 1);

    delta = func_ov004_0216af24(a, 0x37);

    VObjNode* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x37);
    if (node) {
        SetNodePosXe(node, ((0xd0 - delta) >> 1) << 12);
    }

    if (reg2->flagD5 != 0) {
        VObjNode* node2 = func_ov023_021f6880(func_ov011_021849c8(a), 0x37);
        Vec3 savedPos = GetPosZ1(node2);
        ShowHeadBV(a, node2, savedPos);
        VObjNode* node3 = func_ov023_021f6880(func_ov011_021849c8(a), 0x5a);
        if (node3) {
            node3->MethodD8(0xd);
            MoveNodeXv(node3, savedPos, -0x5000);
        }
    }

    func_ov004_0216b120(a, 0x28, 2, 0xd3, 2, 0x10, 0xcb, 1);

    {
    int flag = 0;
    if (NormalizeField5_0200fb08((struct Struct0200fb08*)bs2) == 4 ||
        NormalizeField5_0200fb08((struct Struct0200fb08*)bs2) == 2) {
        flag = 2;
    }
    base = 0;

    func_ov004_0216afb0(a, 0x38, 2, 0xd3, 0x3e7, 7, base + 0x13, 0xa, 1);
    func_ov004_0216afb0(a, 0x39, 2, 0xd3, 0x3e7, 0x57, base + 0x13, 0xa, 1);
    func_ov004_0216afb0(a, 0x3a, 2, 0xd3, 0x15, 0xa8 - flag, base + 0x13, 0xa, 1);

    VObjNode* node4 = func_ov023_021f6880(func_ov011_021849c8(a), 0x3a);
    if (node4) {
        node4->field20 = (void*)CallFunc020e0434With02153694(0x3f3);
    }

    func_ov004_0216afb0(a, 0x47, 2, 0xd3, 0x3e7, 0xa1, base + 0x13, 8, 1);
    func_ov004_0216b06c(a, 0x96, 2, 0xd3, 0xbe, base + 0x13, 8, 2, 0);

    base += 0xc;
    if (count > 1) {
        switch (count) {
        case 2: base += 2; break;
        case 3: base += 1; break;
        }

        int msgBase = 0x3f3 - 0xc;
        for (i = 1; i < count; i++) {
            int idx3 = i + i * 2;
            func_ov004_0216afb0(a, idx3 + 0x38, 2, 0xd3, msgBase, 7, base + 0x13, 0xa, 1);
            func_ov004_0216afb0(a, idx3 + 0x39, 2, 0xd3, msgBase, 0x57, base + 0x13, 0xa, 1);
            func_ov004_0216afb0(a, idx3 + 0x3a, 2, 0xd3, 0x15, 0xa8 - flag, base + 0x13, 0xa, 1);

            VObjNode* node5 = func_ov023_021f6880(func_ov011_021849c8(a), idx3 + 0x3a);
            if (node5) {
                node5->field20 = (void*)CallFunc020e0434With02153694(0x3f3);
            }

            func_ov004_0216afb0(a, i + 0x47, 2, 0xd3, msgBase, 0xa1, base + 0x13, 8, 1);
            func_ov004_0216b06c(a, i + 0x96, 2, 0xd3, 0xbe, base + 0x13, 8, 2, 0);

            base += 0xc;
        }
        if (count == 4) base -= 1;
    }

    func_ov004_0216b120(a, 0x29, 2, 0xd3, 2, base + 0x14, 0xcb, 1);
    func_ov004_0216afb0(a, 0x44, 2, 0xd3, 0x13, 7, base + 0x17, 0xa, 1);

    if (data_ov004_02171034.short8 != 0) {
        func_ov004_0216b06c(a, 0x9a, 2, 0xd3, 0x92, base + 0x18, 8, 4, 0);
        func_ov004_0216afb0(a, 0x4f, 2, 0xd3, 0x34, 0x98, base + 0x18, 0xa, 1);
    }
    func_ov004_0216b06c(a, 0x9b, 2, 0xd3, 0xa8, base + 0x18, 8, 2, 1);
    func_ov004_0216afb0(a, 0x50, 2, 0xd3, 0x34, 0xad, base + 0x18, 0xa, 1);
    func_ov004_0216b06c(a, 0x9c, 2, 0xd3, 0xbd, base + 0x18, 8, 2, 1);
    func_ov004_0216afb0(a, 0x45, 2, 0xd3, 0x14, 7, base + 0x22, 0xa, 1);
    func_ov004_0216afb0(a, 0x46, 2, 0xd3, 0x3e7, 0xbd, base + 0x22, 0xa, 1);
    }

    for (int j = 0; j < count; j++) {
        void* list = func_ov011_021849c8(a);
        VObjNode* jnode = func_ov023_021f6880(list, j * 3 + 0x38);
        if (jnode) {
            jnode->field20 = &ext->records[j];
        }

        int typeVal = ext->records[j].type30;
        if (typeVal >= 0 && typeVal < 0xd) {
            int sl = 0x3e7;
            if (typeVal != 0) sl = (short)(typeVal + 6);
            unsigned char flagD6 = GetRegion(_ZN9GameState11GetInstanceEv())->flagD6;
            if (flagD6 == 1) sl = 0x46;
            func_ov004_0216aed0(a, j * 3 + 0x39, sl, 0);
        }

        int levelVal = ext->records[j].level31;
        if (levelVal >= 0 && levelVal <= 0xa) {
            int lv = 0x3e7;
            if (levelVal != 0) lv = (short)(levelVal + 0x15);
            func_ov004_0216aed0(a, j + 0x47, lv, 0);
        }

        int key39 = (unsigned int)j * 3 + 0x39;
        int delta2 = func_ov004_0216af24(a, key39);
        VObjNode* node2 = func_ov023_021f6880(func_ov011_021849c8(a), key39);
        if (node2) {
            const Vec3& lt = node2->Method20();
            _ZN8Vector3iaSERKS_((int*)&v6c, (int*)&lt);
            v6c.x = v6c.x + ((delta2 + 2) << 12);

            VObjNode* node3 = func_ov023_021f6880(func_ov011_021849c8(a), j + 0x47);
            if (node3) {
                node3->Method1c(&v6c);
                unsigned char lv2 = ext->records[j].level31;
                if (lv2 == 0xa) {
                    node3->MethodD8(0xd);
                } else if (lv2 != 0) {
                    node3->MethodD8(5);
                }
            }
        }

        unsigned short fieldVal = ext->records[j].field32;
        VObjNode* node4b = func_ov023_021f6880(func_ov011_021849c8(a), j + 0x96);
        if (node4b) {
            node4b->MethodE0(fieldVal);
        }
    }

    int val = ext->totalValue;
    int tier = 0;
    if (val >= 1100 && val < 1200) tier = 1;
    else if (val >= 100 && val < 200) tier = 2;
    else if (val >= 1200 && val < 1300) tier = 3;
    else if (val >= 1300 && val < 1400) tier = 4;
    else if (val >= 4200 && val < 4300) tier = 5;
    else if (val >= 1500 && val < 1600) tier = 6;
    else if (val >= 5800 && val < 5900) tier = 7;
    else if (val >= 1800 && val < 1900) tier = 8;
    else if (val >= 1900 && val < 2000) tier = 9;
    else if (val >= 200 && val < 300) tier = 0xa;
    else if (val >= 2100 && val < 2200) tier = 0xb;
    else if (val >= 2000 && val < 2100) tier = 0xc;
    else if (val >= 2200 && val < 2300) tier = 0xd;
    else if (val >= 2300 && val < 2400) tier = 0xe;
    else if (val >= 5700 && val < 5800) tier = 0xf;
    else if (val >= 400 && val < 500) tier = 0x10;

    int msgId = -1;
    switch (tier) {
    case 0: msgId = 0x24; break;
    case 1: msgId = 0x25; break;
    case 2: msgId = 0x26; break;
    case 3: msgId = 0x27; break;
    case 4: msgId = 0x28; break;
    case 5: msgId = 0x29; break;
    case 6: msgId = 0x2a; break;
    case 7: msgId = 0x2b; break;
    case 8: msgId = 0x2c; break;
    case 9: msgId = 0x2d; break;
    case 0xa: msgId = 0x2e; break;
    case 0xb: msgId = 0x2f; break;
    case 0xc: msgId = 0x30; break;
    case 0xd: msgId = 0x31; break;
    case 0xe: msgId = 0x32; break;
    case 0xf: msgId = 0x33; break;
    case 0x10: msgId = 0x47; break;
    }

    if (GetRegion(_ZN9GameState11GetInstanceEv())->flagD7 != 0) {
        msgId = 0x2bc;
    }
    if (msgId >= 0) {
        func_ov004_0216aed0(a, 0x46, msgId, 1);
    }

    unsigned char w6;
    unsigned char w7;
    unsigned short w8;
    w8 = data_ov004_02171034.short8;
    w6 = data_ov004_02171034.byte6;
    w7 = data_ov004_02171034.byte7;
    if (w8 != 0) {
        VObjNode* na = func_ov023_021f6880(func_ov011_021849c8(a), 0x9a);
        if (na) na->MethodE0(w8);
    }
    VObjNode* nb = func_ov023_021f6880(func_ov011_021849c8(a), 0x9b);
    if (nb) nb->MethodE0(w7);
    VObjNode* nc = func_ov023_021f6880(func_ov011_021849c8(a), 0x9c);
    if (nc) nc->MethodE0(w6);

    void* node5 = GetNodeIfType6_0216ae9c(a, 0xd3);
    func_ov023_021f8120(node5);

    int fieldC = data_ov004_02171034.fieldC;
    if (count >= 1 && count <= 4) {
        ShortPair0217017a* e = &data_ov004_0217017a[count - 1];
        func_ov023_021f7eb8(node5, a, fieldC, 6, e->a, 0x1a, e->b, 0, 1, 0);
    }

    SetField1c8True_02184ad8((struct Obj_02184ad8*)a);
    return 0;
}
