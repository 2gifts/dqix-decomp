#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"

extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void __clear(void* buf, int n);
extern "C" void func_0202ae18();
extern "C" void func_0202aec0();
extern "C" void func_0205e22c();
extern "C" void VectorizedMemset(void* dst, int val, unsigned int len);
extern "C" void _Z24GetData02100044_0202ae24v();
extern "C" void* _Z19ResetBuffer02052a10Pc(char* obj);
struct Field150Holder02052e2c;
extern "C" void* _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(struct Field150Holder02052e2c* obj);
extern "C" int _Z33CopyOutBattleField0x7ac0_020ac0b4Pv(void* dst);
extern "C" int _Z24UpdatePlayClocks020ac4f8i(int commit);
struct BattleRecordSnapshot;
extern "C" int _Z31GetFieldPercentOver307_020a0870P20BattleRecordSnapshot(struct BattleRecordSnapshot* record);
extern "C" int _Z31GetFieldPercentOver232_020a08a4P20BattleRecordSnapshot(struct BattleRecordSnapshot* record);
extern "C" int _Z31GetFieldPercentOver944_020a08d8P20BattleRecordSnapshot(struct BattleRecordSnapshot* record);
extern "C" int _Z31GetFieldPercentOver448_020a090cP20BattleRecordSnapshot(struct BattleRecordSnapshot* record);
struct Ctx150 {
    char pad[0x56a];
    unsigned char f56a;
};
extern "C" struct Ctx150* _Z24GetFieldAt0x150_02053c6cPh(unsigned char* obj);
struct Struct0200fb08;
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(struct Struct0200fb08* gs);
extern "C" unsigned char _Z32CopyToRegion0x6482IfDst_020119f8PcPv(char* obj, void* dst);
struct KeyArrayObj_02171f80;
extern "C" void _Z27ClearUnmatchedKeys_02171f80P20KeyArrayObj_02171f80(struct KeyArrayObj_02171f80* obj);

struct Overlay17State02170d88 {
    char pad0[0x3b48];
    void* field3b48;
    char pad3b4c[0x4494 - 0x3b4c];
    int field4494;
};
extern "C" void func_ov017_021b1d44(void* obj, int a, int b);

extern const char* data_ov003_021805e4[5];
extern const char* data_ov003_021805d0[5];

struct Name11 { char c[11]; };
struct Six { unsigned char c[6]; };
struct Shorts14 { unsigned short v[14]; };

struct Info7c {
    unsigned int w0;
    unsigned int a : 9;
    signed int mid : 10;
    signed int val : 11;
    unsigned int hi : 2;
    char text[0x74];
};

struct Packed18 {
    unsigned int w0A : 14;
    unsigned int w0B : 17;
    unsigned int w0C : 1;
    unsigned int w4A : 14;
    unsigned int w4B : 17;
    unsigned int w4C : 1;
    unsigned int w8A : 7;
    unsigned int w8B : 7;
    unsigned int w8C : 7;
    unsigned int w8D : 7;
    unsigned int w8E : 4;
    unsigned int wcA : 10;
    unsigned int wcB : 14;
    unsigned int wcC : 7;
    unsigned int wcD : 1;
    unsigned int w10A : 9;
    unsigned int w10B : 14;
    unsigned int w10C : 7;
    unsigned int w10D : 2;
    short f14;
    unsigned char f16 : 1;
    unsigned char f16b : 4;
    unsigned char f17;
};

struct Blk {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
    unsigned char f06;
    unsigned char f07;
    unsigned int f08 : 24;
    unsigned int f08hi : 8;
    unsigned int f0cA : 14;
    unsigned int f0cB : 14;
    unsigned int f0cC : 4;
    unsigned int f10A : 9;
    unsigned int f10B : 14;
    unsigned int f10C : 9;
};

struct Slot74fe {
    unsigned char pad[0x3c];
    struct Blk blk;
};

struct Name10 { char c[10]; };
struct Words31 { unsigned int w[31]; };
struct Words6 { unsigned int w[6]; };

struct MapEntry {
    unsigned char state;
    struct Name10 discoveredBy;
    struct Name10 clearedBy;
    unsigned char location;
    unsigned char flags;
    unsigned char quality;
    unsigned char level;
    char pad19;
    unsigned short seed;
};

struct GsView {
    char pad0[0x569c];
    struct Info7c info;
    char pad5718[0x74fe - 0x5718];
    struct Six six;
    struct Slot74fe slot;
};

struct Record {
    struct Name11 name;
    unsigned char f0b;
    unsigned char f0c;
    unsigned char f0d;
    struct Six six;
    union {
        struct Info7c info;
        struct Words31 infoWords;
    };
    struct Shorts14 timers;
    union {
        struct Packed18 packed;
        struct Words6 packedWords;
    };
    union {
        struct MapEntry meta;
        struct Shorts14 metaWords;
    };
};

struct Ext150 {
    char pad0[0x16c];
    unsigned short words[8];
    char pad17c[0x49c - 0x17c];
    unsigned char bit0 : 1;
    char pad49d[0x950 - 0x49d];
    int index;
};

struct Prot02170d88 {
    char pad[0x150];
    struct Ext150* ext;
};

struct Obj02170d88 {
    unsigned char state;
    char pad1[3];
    unsigned int timer;
    char pad8[0x1c0 - 8];
    struct Record src;
    char pad2a0[0x380 - 0x2a0];
    struct Record dst;
    char pad460[0x718 - 0x460];
    unsigned char field718;
    char pad719[3];
    int field71c;
    int field720;
    int field724;
    int field728;
    int field72c;
    unsigned char field730;
    char pad731[7];
    int field738;

    struct Record* GetSource() {
        struct Record* r = &src;
        return r;
    }
};

// USA: func_ov003_02170d88
extern "C" ARM void func_ov003_02170d88(struct Obj02170d88* self) {
    struct Prot02170d88* prot;
    struct Slot74fe* slot;
    int lang;
    struct GsView* view;
    self->state = 8;
    self->timer = 0;
    self->field71c = 0;
    self->field720 = 0;
    self->field724 = 0;
    func_0202ae18();
    func_0202aec0();
    _Z24GetData02100044_0202ae24v();
    func_0205e22c();
    view = (struct GsView*)GameState::GetInstance();
    prot = (struct Prot02170d88*)((GameState*)view)->GetProtagonist();
    strcpy(self->GetSource()->name.c, (char*)_Z19ResetBuffer02052a10Pc((char*)prot));
    self->GetSource()->f0b = prot->ext->index;
    self->GetSource()->f0c = prot->ext->words[prot->ext->index];
    memcpy(&self->GetSource()->info, &view->info, 0x7c);
    memcpy(&self->GetSource()->timers, _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c((struct Field150Holder02052e2c*)prot), 0x1c);
    VectorizedMemset(&self->GetSource()->packed, 0, 0x18);
    slot = &view->slot;
    struct Packed18* pk = &self->src.packed;
    int score = 0;
    _Z33CopyOutBattleField0x7ac0_020ac0b4Pv(&score);
    int bit = 0;
    int level = 0;
    struct Prot02170d88* p2 = (struct Prot02170d88*)((GameState*)view)->GetProtagonist();
    if (p2) {
        bit = p2->ext->bit0;
        level = *((unsigned char*)p2->ext + p2->ext->index + 0x186);
    }
    _Z24UpdatePlayClocks020ac4f8i(0);
    struct Info7c* fld = &view->info;
    VectorizedMemset(pk, 0, 0x18);
    pk->w0A = slot->blk.f00;
    pk->w8A = slot->blk.f02;
    pk->w4A = slot->blk.f04;
    pk->w8B = slot->blk.f06;
    pk->w4B = slot->blk.f08;
    pk->w0B = score;
    pk->wcA = slot->blk.f10A;
    pk->w10A = slot->blk.f08hi;
    pk->wcB = slot->blk.f0cB;
    pk->w10B = slot->blk.f10B;
    pk->w8C = (unsigned char)_Z31GetFieldPercentOver307_020a0870P20BattleRecordSnapshot((struct BattleRecordSnapshot*)&slot->blk);
    pk->w8D = (unsigned char)_Z31GetFieldPercentOver232_020a08a4P20BattleRecordSnapshot((struct BattleRecordSnapshot*)&slot->blk);
    pk->wcC = (unsigned char)_Z31GetFieldPercentOver944_020a08d8P20BattleRecordSnapshot((struct BattleRecordSnapshot*)&slot->blk);
    pk->w10C = (unsigned char)_Z31GetFieldPercentOver448_020a090cP20BattleRecordSnapshot((struct BattleRecordSnapshot*)&slot->blk);
    pk->f14 = fld->val;
    pk->f16 = bit;
    pk->f16b = level;
    pk->f17 = _Z24GetFieldAt0x150_02053c6cPh((unsigned char*)p2)->f56a;
    pk->w0C = 1;
    VectorizedMemset(&self->src.meta, 0, 0x1c);

    struct Six six = view->six;
    self->src.six = six;

    int kind = _Z24NormalizeField5_0200fb08P14Struct0200fb08((struct Struct0200fb08*)view);
    lang = 0;
    switch (kind) {
    case 2: lang = 1; break;
    case 3: lang = 2; break;
    case 4: lang = 3; break;
    case 5: lang = 4; break;
    }

    self->dst.name = self->src.name;
    self->dst.f0b = self->src.f0b;
    self->dst.f0c = self->src.f0c;
    self->dst.f0d = self->src.f0d;
    self->dst.six = self->src.six;
    self->dst.infoWords = self->src.infoWords;
    self->dst.timers = self->src.timers;
    self->dst.packedWords = self->src.packedWords;
    self->dst.metaWords = self->src.metaWords;

    memset(self->dst.name.c, 0, 0xb);
    sprintf(self->dst.name.c, data_ov003_021805e4[lang]);
    memset(self->dst.info.text, 0, 0x74);
    sprintf(self->dst.info.text, data_ov003_021805d0[lang]);

    struct Packed18* dp = &self->dst.packed;
    if (!(fld->mid < 310)) {
        self->dst.info.mid = 203;
    }
    short v;
    int val = fld->val;
    v = val;
    if (val >= 750 && val < 800) {
        v -= 50;
    } else if (val >= 900) {
        v -= 100;
    }
    self->dst.info.val = v;
    dp->f14 = v;

    struct MapEntry meta;
    _Z32CopyToRegion0x6482IfDst_020119f8PcPv((char*)view, &meta);
    if (((TreasureMapMetadata*)&meta)->GetMapType() != 0) {
        self->dst.f0d = 1;
        self->dst.meta.state = meta.state;
        self->dst.meta.discoveredBy = meta.discoveredBy;
        self->dst.meta.clearedBy = meta.clearedBy;
        self->dst.meta.location = meta.location;
        self->dst.meta.flags = meta.flags;
        self->dst.meta.quality = meta.quality;
        self->dst.meta.level = meta.level;
        self->dst.meta.seed = meta.seed;
        struct MapEntry* dm = &self->dst.meta;
        memset(dm->discoveredBy.c, 0, 10);
        memset(dm->clearedBy.c, 0, 10);
        char buf[11];
        __clear(buf, 0xb);
        memset(buf, 0, 0xb);
        memcpy(buf, data_ov003_021805e4[lang], 0xb);
        memcpy(dm->discoveredBy.c, buf, 10);
        memset(buf, 0, 0xb);
        memcpy(buf, data_ov003_021805e4[lang], 0xb);
        memcpy(dm->clearedBy.c, buf, 10);
    }
    _Z27ClearUnmatchedKeys_02171f80P20KeyArrayObj_02171f80((struct KeyArrayObj_02171f80*)self);
    self->field718 = 0;
    self->field738 = 0;
    self->field72c = 0;
    self->field730 = 3;
    ((struct Overlay17State02170d88*)func_ov017_0218b5b0())->field4494 = 1;
    func_ov017_021b1d44(((struct Overlay17State02170d88*)func_ov017_0218b5b0())->field3b48, 0x20, 1);
}
