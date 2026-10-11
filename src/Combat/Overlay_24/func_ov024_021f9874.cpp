#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};

struct EntryFlags9_021f9874 {
    unsigned char weight : 6;
    unsigned char flag : 1;
    unsigned char sel : 1;
};

struct TargetEntry_021f9874 {
    int value;
    unsigned char subtype;
    unsigned char enabled;
    unsigned char slot;
    unsigned char weight2;
    unsigned char kind;
    struct EntryFlags9_021f9874 flags9;
    char pad[2];
};

struct InsertArg_021f9874 {
    unsigned short f0;
    signed char f2;
    unsigned char f3;
    int value;
    unsigned short f8;
    unsigned char fa;
    unsigned char fb;
};

struct Buf_021f9874 {
    struct TargetEntry_021f9874 entries[16];
    int count;
    int threshold;
};

struct Sub64c_021f9874 {
    char pad[4];
    unsigned int code : 12;
    unsigned int rest : 20;
    char pad2[0xc];
    unsigned int lowbits : 28;
    unsigned int code2 : 4;
};

struct P648_021f9874 {
    unsigned short f0;
    signed char f2;
    unsigned char f3;
};

struct Bits29c_021f9874 {
    unsigned int lo4 : 4;
    unsigned int val5 : 5;
    unsigned int rest : 23;
};

struct Obj_021f9874 {
    int f0;
    char pad04[2];
    unsigned char f6;
    char pad07[1];
    struct CombatantStruct* f8;
    char pad0c[8];
    unsigned char f14;
    char pad15[0x17];
    unsigned char f2c;
    char pad2d[3];
    int f30;
    unsigned char f34;
    char pad35[3];
    int f38;
    int f3c;
    unsigned char f40;
    char pad41[3];
    int f44[4];
    char pad54[0x28];
    struct CombatantStruct* combatantList[8];
    int f9c;
    char pada0[0x24];
    int arrC4[25];
    int f128;
    char pad12c[4];
    int f130;
    char pad134[5];
    unsigned char f139;
    char pad13a[0x32];
    int f16c;
    char pad170[0x238];
    struct InsertArg_021f9874 arr3a8[4];
    struct InsertArg_021f9874 arr3d8[4];
    struct InsertArg_021f9874 arr408[4];
    struct InsertArg_021f9874 arr438[4];
    char pad468[0x30];
    struct InsertArg_021f9874 arr498[4];
    struct InsertArg_021f9874 arr4c8[4];
    char pad4f8[0x30];
    struct InsertArg_021f9874 arr528[4];
    struct InsertArg_021f9874 arr558[4];
    struct InsertArg_021f9874 arr588[4];
    struct InsertArg_021f9874 arr5b8[4];
    char pad5e8[0x60];
    struct P648_021f9874* f648;
    struct Sub64c_021f9874* f64c;
    int f650;
    char pad654[1];
    unsigned char f655;
};

struct FlagsA8_021f9874 {
    char pad0[2];
    unsigned char any;
    char pad1[2];
    unsigned char f5simple;
    unsigned char f3or4;
    unsigned char f4done;
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    char pad2[2];
};

extern "C" void* __clear(void* dst, int size);
extern "C" int _ffltu(unsigned int v);
extern "C" int _fflt(int v);
extern "C" int _ffix(int v);
extern "C" int _fadd(int a, int b);
extern "C" int _fsub(int a, int b);
extern "C" int _fmul(int a, int b);
extern "C" int _fdiv(int a, int b);
extern "C" int _fgr(int a, int b);
extern "C" int _fgeq(int a, int b);
extern "C" int _fleq(int a, int b);
extern "C" int _fls(int a, int b);
extern "C" int _feq(int a, int b);
extern "C" int _fneq(int a, int b);
extern "C" int _s32_div_f(int a, int b);
extern "C" double func_0200c578(int v);
extern "C" double _dflt(int v);
extern "C" double func_0200b0f0(double a, double b);
extern "C" double func_0200b608(double a, double b);
extern "C" int _d2f(double v);
extern "C" void func_ov024_021f6830(void* arr, struct InsertArg_021f9874* item);
int GetFieldAt0x150(unsigned char* obj);
extern "C" int _Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(struct CombatantStruct* combatant);

extern unsigned char data_ov024_021ffc98[];
extern unsigned char data_ov024_021ffca4[];
extern unsigned char data_ov024_021ffcc5[];

// USA: func_ov024_021f9874
extern "C" ARM void func_ov024_021f9874(struct Obj_021f9874* obj, struct Buf_021f9874* buf, unsigned char p2, unsigned char p3) {
    char unusedF8[0x38];
    int fpArr[8];
    int accumB[8];
    struct FlagsA8_021f9874 flags;
    int accums14[14];
    int accumC[8];
    int arrA[4];
    int arrB[4];
    int slotArr[4];
    struct InsertArg_021f9874 insertBuf;
    int r4;
    int total;
    int v98;
    int v9c;
    int r7c;
    int v94;
    int ratioTmp;
    int flagC;
    int f10Val;
    int matched2;

    memset(unusedF8, 0, 0x38);
    __clear(fpArr, 0x20);
    __clear(accumB, 0x20);
    __clear(&flags, 0xe);
    __clear(accums14, 0x38);
    __clear(accumC, 0x20);
    __clear(arrA, 0x10);
    __clear(arrB, 0x10);

    flagC = 0;

    for (int i = 0; i < buf->count; i++) {
        struct TargetEntry_021f9874* e = &buf->entries[i];
        if (e->kind != 0) continue;
        if (e->enabled == 0) continue;
        {
            int idx = e->slot;
            int v = _fmul(e->value, _ffltu(e->flags9.weight));
            if (obj->f34 != 0) v = _fmul(v, 0x3f99999a);
            accumB[idx] = _fadd(accumB[idx], v);
            if (_fgeq(accumB[idx], _fflt(obj->arrC4[idx]))) fpArr[idx] = 10;
            flags.any = 1;
            if (e->flags9.flag) flagC = 1;
        }
    }

    matched2 = 0;
    if (obj->f14 != 0) {
        for (int i = 0; i < buf->count; i++) {
            struct TargetEntry_021f9874* e = &buf->entries[i];
            if (e->kind != 2) continue;
            if (e->enabled == 0) continue;
            accumC[e->slot] = _fmul(0x3c23d70a, _ffltu(e->weight2));
            flags.any = 1;
            matched2 = 1;
            if (e->flags9.flag) flagC = 1;
        }
        if (matched2) {
            int diff;
            int i;
            for (i = 0; i < buf->count; i++) {
                int thr;
                flags.any = 1;
                thr = _fflt(obj->arrC4[i]);
                diff = _fsub(thr, accumB[i]);
                if (_fleq(diff, 0)) continue;
                {
                    int x = accumC[i];
                    if (obj->f6 != 0) {
                        double d1 = func_0200c578(x);
                        double d2 = func_0200b0f0(0.005, _dflt(obj->f650));
                        x = _d2f(func_0200b608(d1, d2));
                    }
                    {
                        int sq = _fmul(x, x);
                        int capped = sq;
                        if (_fgr(sq, 0x3f666666)) capped = 0x3f666666;
                        accumB[i] = _fadd(accumB[i], _fmul(diff, capped));
                    }
                }
            }
        }
    }

    {
    int i;
    struct TargetEntry_021f9874* e;
    for (i = 0; i < buf->count; i++) {
        e = &buf->entries[i];
        if (e->kind == 3) {
            if (e->enabled != 0) continue;
            int* pA = &arrA[e->slot];
            *pA = _ffix(_fadd(_fflt(*pA), e->value));
            flags.f3or4 = 1;
        }
        if (e->kind == 4 && e->enabled == 0) {
            int* pB = &arrB[e->slot];
            *pB = _ffix(_fadd(_fflt(*pB), e->value));
            flags.f4done = 1;
        }
    }
    }

    accums14[13] = _fflt(obj->f650);
    if (obj->f648->f3 != 0) accums14[13] = _fadd(accums14[13], 0x41f00000);

    if (flags.any != 0) {
        int* pAcc = accumB;
        for (int i = 0; i < obj->f9c; i++) {
            int acc = pAcc[i];
            int raw;
            if (_fleq(acc, 0)) continue;
            raw = obj->arrC4[i];
            if (_fgeq(acc, _fflt(raw))) acc = _fflt(raw);
            {
                struct CombatantStruct* c = obj->combatantList[i];
                unsigned short maxHP = c->currentStats->primaryStats.maxHP;
                int v = _fmul(0x42c80000, acc);
                v = _fdiv(v, _ffltu(maxHP));
                accums14[2] = _fadd(accums14[2], v);
            }
        }
        if (obj->f648->f3 != 0 && obj->f6 != 0) accums14[2] = 0;
    }

    if (flags.f3or4 != 0) {
        int r7;
        for (r7 = 0; r7 < 4; r7++) {
            int val = arrA[r7];
            if (val == 0) continue;
            {
                struct CombatantStruct* c2 = (struct CombatantStruct*)GetCombatantByID(obj->f0, (short)r7);
                unsigned short maxHP2 = c2->currentStats->primaryStats.maxHP;
                int v4 = _fmul(0x42c80000, _fflt(val));
                v4 = _fdiv(v4, _ffltu(maxHP2));
                if (r7 == obj->f128) v4 = _fmul(v4, 0x40000000);
                accums14[6] = _fadd(accums14[6], v4);
            }
        }
        if (obj->f650 != 0) {
            if (obj->f648->f0 == 0x310) {
                if (obj->f130 >= 2) accums14[6] = _fmul(accums14[6], 0x3f28f5c3);
                else accums14[6] = _fmul(accums14[6], 0x3f0ccccd);
                if (obj->f139 == 0) accums14[6] = 0;
            } else if (obj->f648->f0 == 0x21) {
                accums14[6] = _fmul(accums14[6], 0x3f666666);
            }
        }
    }

    for (int i = 0; i < buf->count; i++) {
        struct TargetEntry_021f9874* e = &buf->entries[i];
        if (e->kind == 5 && e->enabled == 0) {
            accums14[5] = _fadd(accums14[5], _ffltu(e->weight2));
            flags.f5simple = 1;
        }
    }

    if (obj->f648->f0 == 0x28) {
        flags.f3or4 = 1;
        accums14[6] = 0x43c80000;
    }

    for (int i = 0; i < buf->count; i++) {
        struct TargetEntry_021f9874* e = &buf->entries[i];
        int useFlag;

        useFlag = 1;
        if (e->flags9.sel) {
            f10Val = _fmul(0x3c23d70a, _ffltu(*((unsigned char*)obj + obj->f3c + 0x54)));
            useFlag = obj->f40;
        } else {
            f10Val = _fmul(0x3c23d70a, _ffltu(*((unsigned char*)obj + obj->f38 + 0x54)));
        }
        __clear(slotArr, 0x10);

        if (e->kind == 8) {
            if (e->enabled != 0) continue;
            slotArr[0] = 0x41200000;
            {
                int t;
                for (t = 0; t < 6; t++) {
                    int val = data_ov024_021ffc98[t * 2 + 1];
                    if (e->subtype == data_ov024_021ffc98[t * 2]) slotArr[0] = _ffltu(val);
                }
            }
        } else if (e->kind == 7) {
            int idx;
            if (e->enabled != 0) continue;
            idx = e->slot;
            if (e->subtype == 0xd) {
                slotArr[1] = _fflt(_s32_div_f(obj->f16c * 13, 100));
                if (e->subtype == 0x11 && obj->f64c->code2 == 2) {
                    if (idx >= 0 && idx < 4) slotArr[1] = _fmul(slotArr[1], obj->f44[idx]);
                }
            } else {
                int t;
                for (t = 0; t < 0xb; t++) {
                    int slot = data_ov024_021ffca4[t * 3 + 1];
                    int val = data_ov024_021ffca4[t * 3 + 2];
                    if (e->subtype != data_ov024_021ffca4[t * 3]) continue;
                    {
                        slotArr[slot] = _ffltu(val);
                        if (useFlag == 0) slotArr[slot] = 0;
                        if (e->subtype == 0x11 && obj->f64c->code2 == 2) {
                            if (idx >= 0 && idx < 4) { int* sa = &slotArr[slot]; *sa = _fmul(*sa, obj->f44[idx]); }
                        }
                        if (_fls(e->value, 0) != 0) {
                            slotArr[slot] = _fmul(0xc0400000, _ffltu(val));
                        }
                        break;
                    }
                }
            }
        } else if (e->kind == 6) {
            if (e->enabled == 0) continue;
            slotArr[3] = _fadd(slotArr[3], e->value);
        } else if (e->kind == 5) {
            int idx;
            if (e->enabled == 0) continue;
            idx = e->slot;
            if (fpArr[idx] != 0) continue;
            if (e->subtype == 0x12) {
                struct CombatantStruct* c = obj->combatantList[idx];
                const volatile struct CombatantStruct* c_v = c;
                if (c != 0) {
                    unsigned int defense = c_v->baseStats->primaryStats.defense;
                    unsigned short maxHP3 = c_v->currentStats->primaryStats.maxHP;
                    int v = _fmul(0x42c80000, _fflt(defense >> 2));
                    v = _fdiv(v, _ffltu(maxHP3));
                    if (_fgr(v, 0x41e80000)) v = 0x41e80000;
                    slotArr[2] = v;
                }
            } else {
                int t;
                for (t = 0; t < 0xd; t++) {
                    int slot = data_ov024_021ffcc5[t * 3 + 1];
                    int val = data_ov024_021ffcc5[t * 3 + 2];
                    if (e->subtype != data_ov024_021ffcc5[t * 3]) continue;
                    slotArr[slot] = _ffltu(val);
                    if (useFlag == 0) slotArr[slot] = 0;
                }
            }
        }

        if (_fneq(slotArr[0], 0)) {
            int v = _fmul(slotArr[0], _ffltu(e->weight2));
            v = _fmul(0x3c23d70a, v);
            accums14[8] = _fadd(accums14[8], v);
            flags.b0 = 1;
        }
        if (_fneq(slotArr[1], 0)) {
            int v = _fmul(slotArr[1], _ffltu(e->weight2));
            v = _fmul(0x3c23d70a, v);
            v = _fmul(f10Val, v);
            accums14[9] = _fadd(accums14[9], v);
            flags.b1 = 1;
        }
        if (_fneq(slotArr[2], 0)) {
            int v = _fmul(slotArr[2], _ffltu(e->weight2));
            v = _fmul(0x3c23d70a, v);
            v = _fmul(f10Val, v);
            accums14[10] = _fadd(accums14[10], v);
            flags.b2 = 1;
        }
        if (_fneq(slotArr[3], 0)) {
            int v = _fmul(slotArr[3], _ffltu(e->weight2));
            v = _fmul(0x3c23d70a, v);
            v = _fmul(f10Val, v);
            accums14[11] = _fadd(accums14[11], v);
            flags.b3 = 1;
        }
    }

    {
        struct P648_021f9874* p648 = obj->f648;
        insertBuf.f0 = p648->f0;
        insertBuf.f2 = p648->f2;
        insertBuf.f3 = p648->f3;
        insertBuf.fa = p2;
        insertBuf.fb = p3;
        insertBuf.f8 = (unsigned short)obj->f650;
    }

    r4 = 0;
    if (flags.any != 0) {
        r4 = accums14[2];
        if (obj->f2c != 0) r4 = _fadd(r4, accums14[11]);
        if (flagC != 0) r4 = _fmul(r4, obj->f30);
        insertBuf.value = _fsub(r4, _fmul(0x3c23d70a, accums14[13]));
        func_ov024_021f6830(obj->arr408, &insertBuf);
        if (_feq(0, accums14[13]) != 0) {
            func_ov024_021f6830(obj->arr438, &insertBuf);
        }
    }

    if (flags.f5simple != 0) {
        insertBuf.value = _fsub(accums14[5], _fmul(0x3dcccccd, accums14[13]));
        func_ov024_021f6830(obj->arr498, &insertBuf);
    }
    if (obj->f655 != 0 && flags.f3or4 != 0) {
        insertBuf.value = _fsub(accums14[6], _fmul(0x3dcccccd, accums14[13]));
        func_ov024_021f6830(obj->arr4c8, &insertBuf);
    }

    {
        r7c = 0x3dcccccd;
        if (obj->f6 == 0) r7c = 0x3c23d70a;
        v94 = 0; v98 = 0; v9c = 0;

        if (flags.b0 != 0) {
                int v90 = _fsub(accums14[8], _fmul(0x3dcccccd, accums14[13]));
                v90 = _fadd(v90, _fmul(0x3c23d70a, accums14[6]));
                insertBuf.value = v90;
                func_ov024_021f6830(obj->arr528, &insertBuf);
            }
            if (obj->f6 == 2 && obj->f64c->code != 0x1f9) {
                r4 = _fmul(r4, 0x3e99999a);
            }
            if (flags.b1 != 0) {
                v94 = _fsub(accums14[9], _fmul(accums14[13], r7c));
                insertBuf.value = v94;
                func_ov024_021f6830(obj->arr558, &insertBuf);
            }
            if (flags.b2 != 0) {
                v98 = _fsub(accums14[10], _fmul(accums14[13], r7c));
                insertBuf.value = v98;
                func_ov024_021f6830(obj->arr588, &insertBuf);
            }
            if (flags.b3 != 0) {
                v9c = _fsub(accums14[11], _fmul(accums14[13], r7c));
                insertBuf.value = v9c;
                func_ov024_021f6830(obj->arr5b8, &insertBuf);
            }

            if (obj->f6 != 0 && obj->f64c->code == 1) {
                unsigned char* fld = (unsigned char*)GetFieldAt0x150((unsigned char*)obj->f8);
                int s0;
                int mp0;
                if (fld != 0 && *(short*)(fld + 0x2ac) > 0 &&
                    ((struct Bits29c_021f9874*)(fld + 0x29c))->val5 == 3 &&
                    !_Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(obj->f8) &&
                    (s0 = buf->entries[0].slot, s0 >= 0) && s0 < 8 &&
                    obj->combatantList[s0] != 0 &&
                    (mp0 = obj->combatantList[s0]->currentStats->primaryStats.currMP, mp0 > 0)) {
                    unsigned short maxMP = obj->f8->currentStats->primaryStats.maxMP;
                    unsigned short currMP = obj->f8->currentStats->primaryStats.currMP;
                    ratioTmp = _ffltu(currMP);
                    ratioTmp = _fdiv(ratioTmp, _ffltu(maxMP));
                    if (_fleq(ratioTmp, 0x3dcccccd)) buf->threshold = _fadd(buf->threshold, 0x42480000);
                    if (_fleq(ratioTmp, 0x3e99999a)) buf->threshold = _fadd(buf->threshold, 0x41f00000);
                    if (_fleq(ratioTmp, 0x3f000000)) buf->threshold = _fadd(buf->threshold, 0x41200000);
                }
            }

            {
                total = _fadd(buf->threshold, v94);
                total = _fadd(v98, total);
                total = _fadd(v9c, total);
                total = _fadd(r4, total);
                insertBuf.value = _fsub(total, _fmul(accums14[13], r7c));
            }
            func_ov024_021f6830(obj->arr3a8, &insertBuf);

            if (_fgr(r4, 0) == 0 || obj->f650 <= 0) {
                func_ov024_021f6830(obj->arr3d8, &insertBuf);
            }
    }
}
