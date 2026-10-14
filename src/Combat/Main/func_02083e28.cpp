#include <globaldefs.h>
#include "std_library_functions.h"

struct StatTriple {
    unsigned int f0 : 10;
    unsigned int f1 : 10;
    unsigned int f2 : 10;
    unsigned int : 2;
};

struct SignedTriple {
    int s0 : 10;
    int s1 : 10;
    int s2 : 10;
    int : 2;
};

struct GrowthTriple {
    int s0 : 10;
    int s1 : 10;
    unsigned int u2 : 10;
    unsigned int : 2;
};

struct ByteQuad {
    int b0 : 8;
    int b1 : 8;
    int b2 : 8;
    int b3 : 8;
};

struct ItemBlock {
    int unk0;
    int unk4;
    struct GrowthTriple growth;
    struct StatTriple rates;
    struct SignedTriple bonusA;
    struct SignedTriple bonusB;
    struct SignedTriple resistA;
    struct SignedTriple resistB;
};

struct Record020836e4 {
    struct ItemBlock* block;
    char* text;
    unsigned int kind : 4;
    unsigned int mode : 5;
    unsigned int : 23;
    char unkC[0xc];
    short count;
    char unk1a[6];
};

struct EquipSlot {
    char unk0[0x14];
    struct ByteQuad resist[5];
    short count;
    char unk2a[2];
};

struct ResistanceSet {
    unsigned char values[0x18];
};

struct StatRow {
    struct StatTriple w[3];
};

struct BattleUnit {
    struct StatTriple stats[3];
    struct StatTriple resists[3];
    char unk18[4];
    unsigned short hp;
    unsigned short mp;
    char unk20;
    unsigned char resistCopy[0x18];
    char unk39[0x33];
    unsigned short maxHp;
    unsigned short maxMp;
    unsigned short attack;
    unsigned short defence;
    unsigned short power;
    char unk76[2];
    struct StatTriple derived;
    unsigned char resistances[0x18];
    char unk94[0x100];
    struct Record020836e4 records[11];
    struct EquipSlot equips[8];
#if defined(jpn)
    char unk454[0x7b8 - 0x454];
#else
    char unk454[0x850 - 0x454];
#endif
    struct StatRow rows[17];
    struct StatTriple base[3];
    char unk928[0xc];
    unsigned char baseResist[0x16];
    char unk94a[6];
    int rowIndex;
};

struct StatOutputs {
    struct Record020836e4* record;
    short* attack;
    short* defence;
    float* rateA;
    float* rateB;
    float* rateC;
    float* rateD;
    short* statB0;
    short* statA1;
    short* statC0;
    short* statB2;
    short* statC1;
    short* statC2;
    unsigned char skipMode;
};

extern "C" int _Z33AccumulateFlaggedSlotBits02085fb4Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits02086020Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits0208608cPh(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits020860f8Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits02086164Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits020861d0Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits0208623cPh(unsigned char*);
extern "C" int _Z35AccumulateSlotBitsFromTable020862a8Ph(unsigned char*);
extern "C" int _Z35AccumulateSlotBitsFromTable02086314Ph(unsigned char*);
extern "C" int func_02085cd0(unsigned char*, int);
extern "C" int _Z30AccumulateModeSlotBits02085f1cPhi(unsigned char*, int);
extern "C" int _Z26AccumulateSlotBits02085b88Ph(unsigned char*);
extern "C" void _Z19ClampFieldPairToMaxP20ClampFieldPairStruct(struct BattleUnit*);
extern "C" void _Z18CopyStruct020836e4P14Record020836e4S0_(struct Record020836e4*, struct Record020836e4*);

static inline void StoreResistances(unsigned char* dst, struct ResistanceSet set) {
    memcpy(dst, &set, sizeof(set));
}

static inline void SetDerivedLow(struct BattleUnit* unit, unsigned short value) {
    unit->derived.f0 = value;
}

static inline void SetDerivedMid(struct BattleUnit* unit, unsigned short value) {
    unit->derived.f1 = value;
}

static inline void SetDerivedHigh(struct BattleUnit* unit, unsigned short value) {
    unit->derived.f2 = value;
}

// USA: func_02083e28
extern "C" ARM void func_02083e28(struct BattleUnit* unit, struct StatOutputs* out) {
    int a0 = _Z33AccumulateFlaggedSlotBits02085fb4Ph((unsigned char*)unit) + unit->base[0].f0;
    int a1 = _Z33AccumulateFlaggedSlotBits02086020Ph((unsigned char*)unit) + unit->base[0].f1;
    int a2 = _Z33AccumulateFlaggedSlotBits0208608cPh((unsigned char*)unit) + unit->base[0].f2;
    int b0 = _Z33AccumulateFlaggedSlotBits020860f8Ph((unsigned char*)unit) + unit->base[1].f0;
    int b1 = _Z33AccumulateFlaggedSlotBits02086164Ph((unsigned char*)unit) + unit->base[1].f1;
    int b2 = _Z33AccumulateFlaggedSlotBits020861d0Ph((unsigned char*)unit) + unit->base[1].f2;
    int c0 = _Z33AccumulateFlaggedSlotBits0208623cPh((unsigned char*)unit) + unit->base[2].f0;
    int c1 = _Z35AccumulateSlotBitsFromTable020862a8Ph((unsigned char*)unit) + unit->base[2].f1;
    int c2 = _Z35AccumulateSlotBitsFromTable02086314Ph((unsigned char*)unit) + unit->base[2].f2;
    float rateA;
    float rateB;
    float rateC;
    float rateD;
    rateD = rateC = rateB = rateA = 0.0f;
    struct StatRow* row = &unit->rows[unit->rowIndex];
    a0 += row->w[0].f0;
    a1 += row->w[0].f1;
    a2 += row->w[0].f2;
    b0 += row->w[1].f0;
    b1 += row->w[1].f1;
    b2 += row->w[1].f2;
    c0 += row->w[2].f0;
    c1 += row->w[2].f1;
    c2 += row->w[2].f2;
    if (a0 > 999) a0 = 999;
    if (a2 > 999) a2 = 999;
    if (b1 > 999) b1 = 999;
    if (a0 < 0) a0 = 0;
    if (a2 < 0) a2 = 0;
    if (b1 < 0) b1 = 0;

    int resist[6] = {0};
    for (int i = 0; i < 6; i++) {
        resist[i] = b1;
    }
    struct Record020836e4* recs[11];
    for (int i = 0; i < 11; i++) {
        recs[i] = &unit->records[i];
    }
    struct Record020836e4* rec;
    if (out != NULL && (rec = out->record) != NULL) {
        switch (rec->kind) {
        case 0: recs[8] = rec; break;
        case 1: recs[9] = rec; break;
        case 4: recs[7] = rec; break;
        case 2: recs[0] = rec; break;
        case 5: recs[5] = rec; break;
        case 3: recs[1] = rec; break;
        case 6: recs[6] = rec; break;
        case 7: recs[10] = rec; break;
        }
    }
    for (int i = 0; i < 11; i++) {
        struct Record020836e4* r = recs[i];
        struct ItemBlock* blk;
        if (r != NULL && r->count > 0 && (blk = r->block) != NULL) {
            a1 += blk->bonusA.s1;
            b0 += blk->bonusA.s0;
            c0 += blk->bonusA.s2;
            b2 += blk->bonusB.s0;
            c1 += blk->bonusB.s1;
            c2 += blk->bonusB.s2;
            rateA += blk->growth.u2 / 10.0f;
            rateB += blk->rates.f0 / 10.0f;
            rateC += blk->rates.f1 / 10.0f;
            rateD += blk->rates.f2 / 10.0f;
            resist[0] += blk->resistA.s1;
            resist[1] += blk->resistA.s2;
            resist[2] += blk->resistB.s0;
            resist[3] += blk->resistB.s1;
            resist[4] += blk->resistB.s2;
            resist[5] += blk->resistA.s0;
        }
    }
    if (a1 > 999) a1 = 999;
    if (b0 > 999) b0 = 999;
    if (b2 > 999) b2 = 999;
    if (c0 > 999) c0 = 999;
    if (c1 > 999) c1 = 999;
    if (c2 > 999) c2 = 999;
    if (a1 < 0) a1 = 0;
    if (b0 < 0) b0 = 0;
    if (b2 < 0) b2 = 0;
    if (c0 < 0) c0 = 0;
    if (c1 < 1) c1 = 1;
    if (c2 < 0) c2 = 0;
    int best = 0;
    for (int i = 0; i < 6; i++) {
        if (resist[i] > 999) {
            resist[i] = 999;
        } else if (resist[i] < 0) {
            resist[i] = 0;
        }
        if (best < resist[i]) best = resist[i];
    }

    if (out == NULL) {
        unit->stats[0].f0 = a0;
        unit->stats[0].f1 = a1;
        unit->stats[0].f2 = a2;
        unit->stats[1].f0 = b0;
        unit->stats[1].f1 = b1;
        unit->stats[1].f2 = b2;
        unit->stats[2].f0 = c0;
        unit->stats[2].f1 = c1;
        unit->stats[2].f2 = c2;
        unit->resists[0].f0 = best;
        unit->resists[0].f1 = resist[0];
        unit->resists[0].f2 = resist[1];
        unit->resists[1].f0 = resist[2];
        unit->resists[1].f1 = resist[3];
        unit->resists[1].f2 = resist[4];
        unit->resists[2].f0 = resist[5];

        int attack = unit->stats[0].f0;
        int defence = unit->stats[0].f2;
        int power = unit->stats[0].f1;
        int d0 = unit->stats[1].f1;
        int d2 = unit->stats[1].f2;
        int d1 = unit->stats[2].f0;
        int maxHp = unit->stats[2].f1;
        int maxMpBase = unit->stats[2].f2;
        for (int i = 0; i < 11; i++) {
            struct Record020836e4* r = &unit->records[i];
            if (r != NULL && r->count > 0 && r->block != NULL) {
                attack += r->block->growth.s0;
                defence += r->block->growth.s1;
            }
        }
        attack += func_02085cd0((unsigned char*)unit, -1);
        int maxMp = _Z30AccumulateModeSlotBits02085f1cPhi((unsigned char*)unit, -1) + maxMpBase;
        if (attack > 999) attack = 999;
        if (defence > 999) defence = 999;
        if (maxMp > 999) maxMp = 999;
        if (attack < 0) attack = 0;
        if (defence < 0) defence = 0;
        if (maxMp < 0) maxMp = 0;
        unit->attack = attack;
        unit->defence = defence;
        unit->power = power;
        SetDerivedLow(unit, d0);
        SetDerivedHigh(unit, d2);
        SetDerivedMid(unit, d1);
        unit->maxHp = maxHp;
        unit->maxMp = maxMp;
        _Z19ClampFieldPairToMaxP20ClampFieldPairStruct(unit);

        short totals[0x16] = {0};
        for (int i = 0; i < 0x16; i++) {
            totals[i] = unit->baseResist[i];
        }
        for (int i = 0; i < 8; i++) {
            struct EquipSlot* slot = &unit->equips[i];
            if (slot->count > 0) {
                totals[0] += slot->resist[0].b0;
                totals[1] += slot->resist[0].b1;
                totals[2] += slot->resist[0].b2;
                totals[3] += slot->resist[0].b3;
                totals[4] += slot->resist[1].b0;
                totals[5] += slot->resist[1].b1;
                totals[6] += slot->resist[1].b2;
                totals[8] += slot->resist[1].b3;
                totals[9] += slot->resist[2].b0;
                totals[10] += slot->resist[2].b1;
                totals[11] += slot->resist[2].b2;
                totals[12] += slot->resist[2].b3;
                totals[13] += slot->resist[3].b0;
                totals[14] += slot->resist[3].b1;
                totals[15] += slot->resist[3].b2;
                totals[16] += slot->resist[3].b3;
                totals[17] += slot->resist[4].b0;
                totals[18] += slot->resist[4].b1;
                totals[19] += slot->resist[4].b2;
                totals[20] += slot->resist[4].b3;
            }
        }
        struct ResistanceSet set;
        memset(&set, 100, 0x16);
        for (int i = 0; i < 0x16; i++) {
            if (totals[i] < 0) totals[i] = 0;
            set.values[i] = totals[i];
        }
        StoreResistances(unit->resistances, set);
        StoreResistances(unit->resistCopy, set);
    } else {
        *out->rateA = rateA;
        *out->rateC = rateC;
        *out->rateD = rateD;
        *out->statB0 = b0;
        *out->statA1 = a1;
        *out->statC0 = c0;
        *out->statB2 = b2;
        *out->statC1 = c1;
        int attack = a0;
        int defence = a2;
        for (int i = 0; i < 11; i++) {
            struct Record020836e4* r = recs[i];
            if (r != NULL && r->count > 0 && r->block != NULL) {
                attack += r->block->growth.s0;
                defence += r->block->growth.s1;
            }
        }
        unsigned char mode = 0x21;
        if (recs[8]->count > 0) mode = recs[8]->mode;
        signed char weapon = mode;
        attack += func_02085cd0((unsigned char*)unit, weapon);
        if (out->skipMode == 0) {
            c2 += _Z30AccumulateModeSlotBits02085f1cPhi((unsigned char*)unit, weapon);
        }
        struct Record020836e4* shield;
        if (out->skipMode != 0 && (shield = recs[9]) != NULL && shield->count > 0) {
            struct Record020836e4 saved = unit->records[9];
            _Z18CopyStruct020836e4P14Record020836e4S0_(&unit->records[9], shield);
            rateB += _Z26AccumulateSlotBits02085b88Ph((unsigned char*)unit);
            _Z18CopyStruct020836e4P14Record020836e4S0_(&unit->records[9], &saved);
        }
        if (attack > 999) attack = 999;
        if (defence > 999) defence = 999;
        if (c2 > 999) c2 = 999;
        if (attack < 0) attack = 0;
        *out->attack = attack;
        if (defence < 0) defence = 0;
        *out->defence = defence;
        if (c2 < 0) c2 = 0;
        *out->statC2 = c2;
        *out->rateB = rateB;
    }
}
