#include <globaldefs.h>

#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

struct EntryFlags9_021f9874 {
    unsigned char weight : 6;
    unsigned char flag : 1;
    unsigned char sel : 1;
};

struct TargetEntry_021f9874 {
    float value;
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
    float value;
    unsigned short f8;
    unsigned char fa;
    unsigned char fb;
};

struct Buf_021f9874 {
    struct TargetEntry_021f9874 entries[16];
    int count;
    float threshold;
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
    GameObject* f8;
    char pad0c[8];
    unsigned char f14;
    char pad15[0x17];
    unsigned char f2c;
    char pad2d[3];
    float f30;
    unsigned char f34;
    char pad35[3];
    int f38;
    int f3c;
    unsigned char f40;
    char pad41[3];
    float f44[4];
    unsigned char f54[0x28];
    GameObject* combatantList[8];
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
extern "C" void func_ov024_021f6830(void* arr, struct InsertArg_021f9874* item);
int GetFieldAt0x150(unsigned char* obj);
extern "C" int _Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(GameObject* combatant);

static inline unsigned short GetMaxHP(GameObject* c) { return c->currentStats_->primaryStats.maxHP; }
static inline unsigned short GetMaxMP(GameObject* c) { return c->currentStats_->primaryStats.maxMP; }
static inline unsigned short GetCurrMP(GameObject* c) { return c->currentStats_->primaryStats.currMP; }
static inline unsigned int GetBaseDefense(GameObject* c) { return c->baseStats_->primaryStats.defense; }

extern unsigned char data_ov024_021ffc98[12];
extern unsigned char data_ov024_021ffca4[33];
extern unsigned char data_ov024_021ffcc5[39];

// USA: func_ov024_021f9874
extern "C" ARM void func_ov024_021f9874(struct Obj_021f9874* obj, struct Buf_021f9874* buf, unsigned char p2, unsigned char p3) {
    char unusedF8[0x38];
    int fpArr[8];
    float accumB[8];
    struct FlagsA8_021f9874 flags;
    float accums14[14];
    float accumC[8];
    int arrA[4];
    int arrB[4];
    float slotArr[4];
    struct InsertArg_021f9874 insertBuf;
    float normalizedHPScore;
    float total;
    float v98;
    float v9c;
    float costScale;
    float v94;
    float ratioTmp;
    int flagC;
    float f10Val;
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
            float v = e->value * e->flags9.weight;
            if (obj->f34 != 0) v *= 1.2f;
            accumB[idx] += v;
            if (accumB[idx] >= obj->arrC4[idx]) fpArr[idx] = 10;
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
            accumC[e->slot] = 0.01f * e->weight2;
            flags.any = 1;
            matched2 = 1;
            if (e->flags9.flag) flagC = 1;
        }
        if (matched2) {
            float diff;
            int i;
            for (i = 0; i < buf->count; i++) {
                float thr;
                flags.any = 1;
                thr = obj->arrC4[i];
                diff = thr - accumB[i];
                if (diff <= 0.0f) continue;
                {
                    float x = accumC[i];
                    if (obj->f6 != 0) {
                        double d1 = x;
                        double d2 = 0.005 * (double)obj->f650;
                        x = (float)(d1 - d2);
                    }
                    {
                        float sq = x * x;
                        float capped = sq;
                        if (sq > 0.9f) capped = 0.9f;
                        accumB[i] += diff * capped;
                    }
                }
            }
        }
    }

    for (int i = 0; i < buf->count; i++) {
        struct TargetEntry_021f9874* e = &buf->entries[i];
        if (e->kind == 3) {
            if (e->enabled != 0) continue;
            arrA[e->slot] += e->value;
            flags.f3or4 = 1;
        }
        if (e->kind == 4 && e->enabled == 0) {
            arrB[e->slot] += e->value;
            flags.f4done = 1;
        }
    }

    accums14[13] = obj->f650;
    if (obj->f648->f3 != 0) accums14[13] += 30.0f;

    if (flags.any != 0) {
        float* accumulated = accumB;
        for (int i = 0; i < obj->f9c; i++) {
            float acc = accumulated[i];
            int raw;
            if (acc <= 0.0f) continue;
            raw = obj->arrC4[i];
            if (acc >= raw) acc = raw;
            accums14[2] += 100.0f * acc / GetMaxHP(obj->combatantList[i]);
        }
        if (obj->f648->f3 != 0 && obj->f6 != 0) accums14[2] = 0.0f;
    }

    if (flags.f3or4 != 0) {
        for (int slot = 0; slot < 4; slot++) {
            int val = arrA[slot];
            if (val == 0) continue;
            {
                float normalizedHP = 100.0f * val / GetMaxHP(GetCombatantByID(obj->f0, (short)slot));
                if (slot == obj->f128) normalizedHP *= 2.0f;
                accums14[6] += normalizedHP;
            }
        }
        if (obj->f650 != 0) {
            if (obj->f648->f0 == 0x310) {
                if (obj->f130 >= 2) accums14[6] *= 0.66f;
                else accums14[6] *= 0.55f;
                if (obj->f139 == 0) accums14[6] = 0.0f;
            } else if (obj->f648->f0 == 0x21) {
                accums14[6] *= 0.9f;
            }
        }
    }

    for (int i = 0; i < buf->count; i++) {
        struct TargetEntry_021f9874* e = &buf->entries[i];
        if (e->kind == 5 && e->enabled == 0) {
            accums14[5] += e->weight2;
            flags.f5simple = 1;
        }
    }

    if (obj->f648->f0 == 0x28) {
        flags.f3or4 = 1;
        accums14[6] = 400.0f;
    }

    for (int i = 0; i < buf->count; i++) {
        struct TargetEntry_021f9874* e = &buf->entries[i];
        int useFlag;

        useFlag = 1;
        if (e->flags9.sel) {
            f10Val = 0.01f * obj->f54[obj->f3c];
            useFlag = obj->f40;
        } else {
            f10Val = 0.01f * obj->f54[obj->f38];
        }
        __clear(slotArr, 0x10);

        if (e->kind == 8) {
            if (e->enabled != 0) continue;
            slotArr[0] = 10.0f;
            {
                int t;
                for (t = 0; t < 6; t++) {
                    unsigned int val = data_ov024_021ffc98[t * 2 + 1];
                    if (e->subtype == data_ov024_021ffc98[t * 2]) slotArr[0] = val;
                }
            }
        } else if (e->kind == 7) {
            int idx;
            if (e->enabled != 0) continue;
            idx = e->slot;
            if (e->subtype == 0xd) {
                slotArr[1] = obj->f16c * 13 / 100;
                if (e->subtype == 0x11 && obj->f64c->code2 == 2) {
                    if (idx >= 0 && idx < 4) slotArr[1] *= obj->f44[idx];
                }
            } else {
                int t;
                for (t = 0; t < 0xb; t++) {
                    int slot = data_ov024_021ffca4[t * 3 + 1];
                    unsigned int val = data_ov024_021ffca4[t * 3 + 2];
                    if (e->subtype != data_ov024_021ffca4[t * 3]) continue;
                    {
                        slotArr[slot] = val;
                        if (useFlag == 0) slotArr[slot] = 0.0f;
                        if (e->subtype == 0x11 && obj->f64c->code2 == 2) {
                            if (idx >= 0 && idx < 4) slotArr[slot] *= obj->f44[idx];
                        }
                        if (e->value < 0.0f) {
                            slotArr[slot] = -3.0f * val;
                        }
                        break;
                    }
                }
            }
        } else if (e->kind == 6) {
            if (e->enabled == 0) continue;
            slotArr[3] += e->value;
        } else if (e->kind == 5) {
            int idx;
            if (e->enabled == 0) continue;
            idx = e->slot;
            if (fpArr[idx] != 0) continue;
            if (e->subtype == 0x12) {
                GameObject* c = obj->combatantList[idx];
                if (c != 0) {
                    unsigned int defense = GetBaseDefense(c);
                    unsigned short maxHP3 = GetMaxHP(c);
                    float v = 100.0f * (int)(defense >> 2);
                    v = v / maxHP3;
                    if (v > 29.0f) v = 29.0f;
                    slotArr[2] = v;
                }
            } else {
                int t;
                for (t = 0; t < 0xd; t++) {
                    int slot = data_ov024_021ffcc5[t * 3 + 1];
                    unsigned int val = data_ov024_021ffcc5[t * 3 + 2];
                    if (e->subtype != data_ov024_021ffcc5[t * 3]) continue;
                    slotArr[slot] = val;
                    if (useFlag == 0) slotArr[slot] = 0.0f;
                }
            }
        }

        if (slotArr[0]) {
            float v = slotArr[0] * e->weight2;
            v = 0.01f * v;
            accums14[8] += v;
            flags.b0 = 1;
        }
        if (slotArr[1]) {
            float v = slotArr[1] * e->weight2;
            v = 0.01f * v;
            v = f10Val * v;
            accums14[9] += v;
            flags.b1 = 1;
        }
        if (slotArr[2]) {
            float v = slotArr[2] * e->weight2;
            v = 0.01f * v;
            v = f10Val * v;
            accums14[10] += v;
            flags.b2 = 1;
        }
        if (slotArr[3]) {
            float v = slotArr[3] * e->weight2;
            v = 0.01f * v;
            v = f10Val * v;
            accums14[11] += v;
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

    normalizedHPScore = 0.0f;
    if (flags.any != 0) {
        normalizedHPScore = accums14[2];
        if (obj->f2c != 0) normalizedHPScore += accums14[11];
        if (flagC != 0) normalizedHPScore *= obj->f30;
        insertBuf.value = normalizedHPScore - 0.01f * accums14[13];
        func_ov024_021f6830(obj->arr408, &insertBuf);
        if (0.0f == accums14[13]) {
            func_ov024_021f6830(obj->arr438, &insertBuf);
        }
    }

    if (flags.f5simple != 0) {
        insertBuf.value = accums14[5] - 0.1f * accums14[13];
        func_ov024_021f6830(obj->arr498, &insertBuf);
    }
    if (obj->f655 != 0 && flags.f3or4 != 0) {
        insertBuf.value = accums14[6] - 0.1f * accums14[13];
        func_ov024_021f6830(obj->arr4c8, &insertBuf);
    }

    costScale = 0.1f;
    if (obj->f6 == 0) costScale = 0.01f;
    v94 = 0.0f; v98 = 0.0f; v9c = 0.0f;

    if (flags.b0 != 0) {
        float v90 = accums14[8] - 0.1f * accums14[13];
        v90 += 0.01f * accums14[6];
        insertBuf.value = v90;
        func_ov024_021f6830(obj->arr528, &insertBuf);
    }
    if (obj->f6 == 2 && obj->f64c->code != 0x1f9) {
        normalizedHPScore *= 0.3f;
    }
    if (flags.b1 != 0) {
        v94 = accums14[9] - accums14[13] * costScale;
        insertBuf.value = v94;
        func_ov024_021f6830(obj->arr558, &insertBuf);
    }
    if (flags.b2 != 0) {
        v98 = accums14[10] - accums14[13] * costScale;
        insertBuf.value = v98;
        func_ov024_021f6830(obj->arr588, &insertBuf);
    }
    if (flags.b3 != 0) {
        v9c = accums14[11] - accums14[13] * costScale;
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
            (mp0 = obj->combatantList[s0]->currentStats_->primaryStats.currMP, mp0 > 0)) {
            ratioTmp = (float)GetCurrMP(obj->f8) / GetMaxMP(obj->f8);
            if (ratioTmp <= 0.1f) buf->threshold += 50.0f;
            if (ratioTmp <= 0.3f) buf->threshold += 30.0f;
            if (ratioTmp <= 0.5f) buf->threshold += 10.0f;
        }
    }

    total = buf->threshold + v94;
    total = v98 + total;
    total = v9c + total;
    total = normalizedHPScore + total;
    insertBuf.value = total - accums14[13] * costScale;
    func_ov024_021f6830(obj->arr3a8, &insertBuf);

    if (!(normalizedHPScore > 0.0f) || obj->f650 <= 0) {
        func_ov024_021f6830(obj->arr3d8, &insertBuf);
    }
}
