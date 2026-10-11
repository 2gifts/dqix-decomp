#include <globaldefs.h>

struct Container020e0310;
struct StructAcAe021db45c;
struct Unpacked021dbb34;
struct FloatModelOut_021dbc58;
struct MainObj_021e257c;

extern "C" void func_0204c684(void* buf);
extern "C" int _Z33InitBufferFromDataField4_021ddc34Pvssss(void* obj, short a, short b, short c, short d);
extern "C" void _Z28UpdateEntryAndReset_021db45cPvP18StructAcAe021db45ciPsS2_(void* obj, struct StructAcAe021db45c* p1, int p2, short* p3, short* p4);
extern "C" void* func_ov023_021db4e4(void* obj, int key);
extern "C" void __clear(void* buf, int len);
extern "C" void _Z20DecodePacked021dbb34PvP16Unpacked021dbb34(void* handle, struct Unpacked021dbb34* out);
extern "C" void _Z33ConvertModelDataToFloats_021dbc58PvP22FloatModelOut_021dbc58i(int id, void* out, void* p);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" void _Z23SetEntryFields_021e23d0Pviihh(void* obj, int val, int f0xc, unsigned char lowNib, unsigned char highNib);
extern "C" void _Z25ComputeShortPair_021e2bdcPviPsS0_(void* a, int unused, short* out1, short* out2);
extern "C" void func_0204f41c(void* buf, short x, short y, int text, int d, int e, short* f, short* g, int h);
#if defined(jpn)
extern "C" void func_02050678(void*,short,short,int,int,int,short*,short*);
#endif
extern "C" void _Z31FormatAndDispatchValue_021db3c0iisih(void* buf, int x, short y, float v, unsigned char color);
extern "C" void _Z24SetPackedFields_021e24b0Pviihhhhhh(void* obj, int val, int f0xc, unsigned char nibbleD, unsigned char p5, unsigned char p6, unsigned char p7, unsigned char p8, unsigned char p9);
extern "C" void func_ov023_021e257c(void* obj);
extern "C" void* _Z29CreateAndSetFields8A_021db544PvS_ii(void* a, void* b, int c, int d);
int IsValueInCombatantField150List(int combatantId, int value);
extern "C" int func_020dd4c4(int id, void* node);
extern "C" int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
extern "C" long labs(long);

#if defined(jpn)
struct Data021ff9e0 {
    struct Container020e0310* field14;
    int field0;
    int field8;
    int fieldc;
    int field10;
    int field4;
};
#else
struct Data021ff9e0 {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    struct Container020e0310* field14;
};
#endif

extern struct Data021ff9e0 data_ov023_021ff9e0;

extern const short data_ov023_021fd5be[];
extern const short data_ov023_021fd5c6[];
extern const short data_ov023_021fd5ce[];
extern const short data_ov023_021fd5d6[];
extern const short data_ov023_021fd5de[];
extern const short data_ov023_021fd5e6[];
extern const short data_ov023_021fd5ee[];
extern const short data_ov023_021fd5f6[];
extern const short data_ov023_021fd5fe[];
extern const short data_ov023_021fd606[];
extern const short data_ov023_021fd60e[];
extern const short data_ov023_021fd616[];
extern const short data_ov023_021fd61e[];

struct Packed021ddf5c {
    int unk0;
    int unk4;
    int f8lo : 10;
    int f8mid : 10;
    unsigned int f8hi : 10;
    unsigned int fclo : 10;
    unsigned int fchi : 10;
    unsigned int fcrest : 12;
    int f10lo : 10;
    int f10mid : 10;
    int f10hi : 10;
    int f14lo : 10;
    int f14mid : 10;
    int f14hi : 10;
};

struct Node021ddf5c {
    struct Packed021ddf5c* packed;
    int unk4;
    unsigned int low4 : 4;
    char padc[0x18 - 0xc];
    short field18;
};

struct Entry021ddf5c {
    char pad[0x16];
    unsigned char flags;
};

struct Obj021ddf5c {
    char pad0[0x4c];
    struct Node021ddf5c* node;
    char pad50[0xcc - 0x50];
    char list[4];
    void* buf;
    char padd4[0xde - 0xd4];
    short active;
#if defined(jpn)
    char pade0[0x6d8 - 0xe0];
#else
    char pade0[0x75c - 0xe0];
#endif

    int pos;
    char pad760[0x768 - 0x760];
    int lastPos;
    int lastLen;
    char pad770[0x77a - 0x770];
    signed char id;
};

#define SetEntryOn(obj, key) do {     struct Entry021ddf5c* e_ = (struct Entry021ddf5c*)func_ov023_021db4e4((obj)->list, (key));     if (e_) e_->flags |= 1; } while (0)

#define SetEntryOff(obj, key) do {     struct Entry021ddf5c* e_ = (struct Entry021ddf5c*)func_ov023_021db4e4((obj)->list, (key));     if (e_) e_->flags &= ~1; } while (0)

#define FlushList(obj, buf) do {     if (data_ov023_021ff9e0.field4) {         (obj)->buf = (buf);         (obj)->active = 1;         func_ov023_021e257c((obj)->list);     } } while (0)

// JPN: func_ov023_021de6e0
// USA: func_ov023_021ddf5c
extern "C" ARM void func_ov023_021ddf5c(struct Obj021ddf5c* obj) {
    char buf[0xe0];
    unsigned char i;
    func_0204c684(buf);
    if (!_Z33InitBufferFromDataField4_021ddc34Pvssss(buf, 0, 0, 0x14, 9)) return;

    if (obj->id < 0) {
        short k0;
        int key;
        float v;
        short k;
        short k3;
        int abs_;
        unsigned char n;
        struct Node021ddf5c* node = obj->node;
        short p1, p0;
        short o1, o0;
        short a1, a0;
        _Z28UpdateEntryAndReset_021db45cPvP18StructAcAe021db45ciPsS2_(obj->list, (struct StructAcAe021db45c*)buf, 0xb, &a0, &a1);
        SetEntryOn(obj, 0xb);
        SetEntryOn(obj, 0x2d);
        SetEntryOff(obj, 0x2e);
        SetEntryOff(obj, 0x2c);
        float vals[6];
        float un[12];
        unsigned char idx[6];
        __clear(un, 0x30);
        __clear(idx, 6);
        _Z20DecodePacked021dbb34PvP16Unpacked021dbb34(node, (struct Unpacked021dbb34*)un);
        n = 0;
        __clear(vals, 0x18);
        for (i = 0; i < 12; i++) {
            if (un[i] != 0.0f) {
                vals[n] = un[i];
                idx[n] = i;
                n++;
                if (n >= 4) break;
            }
        }
        for (i = 0; i < 4; i++) {
            k0 = data_ov023_021fd5be[i];
            if (i < n) {
                SetEntryOn(obj, k0);
                SetEntryOn(obj, data_ov023_021fd5c6[i]);
                SetEntryOff(obj, data_ov023_021fd5ce[i]);
            } else {
                SetEntryOff(obj, k0);
                SetEntryOff(obj, data_ov023_021fd5c6[i]);
                SetEntryOff(obj, data_ov023_021fd5ce[i]);
            }
        }
        for (i = 0; i < n; i++) {
            v = vals[i];
            key = (short)(idx[i] + 12);
            _Z23SetEntryFields_021e23d0Pviihh(obj->list, data_ov023_021fd5c6[i], _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd5d6[i];
            _Z25ComputeShortPair_021e2bdcPviPsS0_(obj->list, k, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.field4) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1, 0);
#endif

#endif

#endif

#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, p0, p1, v, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(obj, k);
                break;
            default:
                if (v < 0.0f) {
                    k3 = data_ov023_021fd5ce[i];
                    SetEntryOn(obj, k3);
                    _Z23SetEntryFields_021e23d0Pviihh(obj->list, k3, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x19), 8, 0xf);
                }
                abs_ = labs((int)v);
                _Z24SetPackedFields_021e24b0Pviihhhhhh(obj->list, data_ov023_021fd5d6[i], abs_, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(obj, data_ov023_021fd5d6[i]);
                break;
            }
        }
        FlushList(obj, buf);
        _Z29CreateAndSetFields8A_021db544PvS_ii(obj->list, (void*)0xb, a0, a1);
        SetEntryOff(obj, 0xb);
    } else if (IsValueInCombatantField150List(obj->id, obj->node->field18)) {
        short k0;
        int key;
        float v;
        short k;
        int abs_;
        short k3;
        unsigned char n;
        int id = obj->id;
        struct Node021ddf5c* node = obj->node;
        short p1, p0;
        short o1, o0;
        short b1, b0;
        _Z28UpdateEntryAndReset_021db45cPvP18StructAcAe021db45ciPsS2_(obj->list, (struct StructAcAe021db45c*)buf, 0xb, &b0, &b1);
        SetEntryOn(obj, 0xb);
        SetEntryOn(obj, 0x2d);
        SetEntryOff(obj, 0x2e);
        SetEntryOff(obj, 0x2c);
        float vals[6];
        float un[12];
        float model[12];
        unsigned char idx[6];
        __clear(model, 0x30);
        __clear(un, 0x30);
        __clear(idx, 6);
        _Z33ConvertModelDataToFloats_021dbc58PvP22FloatModelOut_021dbc58i(id, model, 0);
        _Z20DecodePacked021dbb34PvP16Unpacked021dbb34(node, (struct Unpacked021dbb34*)un);
        n = 0;
        __clear(vals, 0x18);
        for (i = 0; i < 12; i++) {
            int force = 0;
            if (i == 3 && node->low4 == 1) {
                if (model[3]) force = 1;
            }
            if (force || un[i] != 0.0f) {
                vals[n] = model[i];
                idx[n] = i;
                n++;
                if (n >= 4) break;
            }
        }
        for (i = 0; i < 4; i++) {
            k0 = data_ov023_021fd5de[i];
            if (i < n) {
                SetEntryOn(obj, k0);
                SetEntryOn(obj, data_ov023_021fd5e6[i]);
                SetEntryOn(obj, data_ov023_021fd5ee[i]);
            } else {
                SetEntryOff(obj, k0);
                SetEntryOff(obj, data_ov023_021fd5e6[i]);
                SetEntryOff(obj, data_ov023_021fd5ee[i]);
            }
        }
        for (i = 0; i < n; i++) {
            v = vals[i];
            key = (short)(idx[i] + 12);
            _Z23SetEntryFields_021e23d0Pviihh(obj->list, data_ov023_021fd5e6[i], _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd5f6[i];
            _Z25ComputeShortPair_021e2bdcPviPsS0_(obj->list, k, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.field4) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1, 0);
#endif

#endif

#endif

#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, p0, p1, v, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(obj, k);
                break;
            default:
                abs_ = labs((int)v);
                _Z24SetPackedFields_021e24b0Pviihhhhhh(obj->list, data_ov023_021fd5f6[i], abs_, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(obj, data_ov023_021fd5f6[i]);
                break;
            }
            k3 = data_ov023_021fd5ee[i];
            SetEntryOn(obj, k3);
            _Z23SetEntryFields_021e23d0Pviihh(obj->list, k3, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x22), 8, 0xf);
        }
        FlushList(obj, buf);
        _Z29CreateAndSetFields8A_021db544PvS_ii(obj->list, (void*)0xb, b0, b1);
        SetEntryOff(obj, 0xb);
    } else if (!func_020dd4c4(obj->id, obj->node)) {
        short k0;
        unsigned char j;
        short key;
        short k;
        float v;
        float w;
        unsigned char color;
        short k5;
        int abs_;
        unsigned char n;
        struct Node021ddf5c* node = obj->node;
        int id = obj->id;
        short p1, p0;
        short o1, o0;
        short c1, c0;
        _Z28UpdateEntryAndReset_021db45cPvP18StructAcAe021db45ciPsS2_(obj->list, (struct StructAcAe021db45c*)buf, 0xb, &c0, &c1);
        SetEntryOn(obj, 0xb);
        SetEntryOff(obj, 0x2d);
        SetEntryOn(obj, 0x2e);
        SetEntryOff(obj, 0x2c);
        unsigned char changed[12];
        float next[12];
        float cur[12];
        __clear(cur, 0x30);
        _Z33ConvertModelDataToFloats_021dbc58PvP22FloatModelOut_021dbc58i(id, cur, 0);
        __clear(next, 0x30);
        _Z33ConvertModelDataToFloats_021dbc58PvP22FloatModelOut_021dbc58i(id, next, node);
        struct Packed021ddf5c* pk = 0;
        __clear(changed, 0xc);
        if (node && node->field18 > 0) pk = node->packed;
        if (pk) {
            if (pk->f8lo) changed[0] = 1;
            if (pk->f8mid) changed[1] = 1;
            if ((float)pk->f8hi / 10.0f != 0.0f) changed[2] = 1;
            if ((float)pk->fclo / 10.0f != 0.0f) changed[3] = 1;
            if ((float)pk->fchi / 10.0f != 0.0f) changed[4] = 1;
            if (pk->f10lo) changed[6] = 1;
            if (pk->f10mid) changed[7] = 1;
            if (pk->f10hi) changed[8] = 1;
            if (pk->f14lo) changed[9] = 1;
            if (pk->f14mid) changed[10] = 1;
            if (pk->f14hi) changed[11] = 1;
            if (node->low4 == 1) {
                if (cur[3] || next[3]) changed[3] = 1;
            }
        }
        unsigned char idx[6];
        __clear(idx, 6);
        n = 0;
        for (i = 0; i < 12; i++) {
            if (changed[i] || cur[i] - next[i] != 0.0f) {
                idx[n] = i;
                n++;
                if (n >= 4) break;
            }
        }
        for (j = 0; j < 4; j++) {
            k0 = data_ov023_021fd5fe[j];
            if (j < n) {
                SetEntryOn(obj, k0);
                SetEntryOn(obj, data_ov023_021fd606[j]);
            } else {
                SetEntryOff(obj, k0);
                SetEntryOff(obj, data_ov023_021fd606[j]);
            }
        }
        for (i = 0; i < n; i++) {
            j = idx[i];
            key = j + 12;
            _Z23SetEntryFields_021e23d0Pviihh(obj->list, data_ov023_021fd606[i], _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, key), 10, 0xf);
            k = data_ov023_021fd60e[i];
            _Z25ComputeShortPair_021e2bdcPviPsS0_(obj->list, k, &p0, &p1);
            v = cur[j];
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.field4) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, 0xf, &o0, &o1, 0);
#endif

#endif

#endif

#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, v, 0xf);
#else
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, p0, p1, v, 0xf);
#endif

#endif

#endif

                }
                SetEntryOff(obj, k);
                break;
            default:
                abs_ = labs((int)v);
                _Z24SetPackedFields_021e24b0Pviihhhhhh(obj->list, data_ov023_021fd60e[i], abs_, 8, 0xf, 1, 3, 0, 0);
                SetEntryOn(obj, data_ov023_021fd60e[i]);
                break;
            }
            _Z23SetEntryFields_021e23d0Pviihh(obj->list, data_ov023_021fd616[i], _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x20), 8, 0xf);
            w = next[j];
            color = 9;
            if (v == w) color = 0xf;
            else if (v < w) color = 5;
            k5 = data_ov023_021fd61e[i];
            _Z25ComputeShortPair_021e2bdcPviPsS0_(obj->list, k5, &p0, &p1);
            switch (key) {
            case 14:
            case 15:
            case 16:
            case 17:
                if (data_ov023_021ff9e0.field4) {
#if defined(jpn)
                    func_02050678(buf, p0 + 16, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, color, &o0, &o1);
#else
                    func_0204f41c(buf, p0 + 1, p1, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x1a), 8, color, &o0, &o1, 0);
#endif

#if defined(jpn)
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, (short)(p0 + 8), p1, w, color);
#else
                    _Z31FormatAndDispatchValue_021db3c0iisih(buf, p0, p1, w, color);
#endif

                }
                SetEntryOff(obj, k5);
                break;
            default:
                abs_ = labs((int)w);
                _Z24SetPackedFields_021e24b0Pviihhhhhh(obj->list, data_ov023_021fd61e[i], abs_, 8, color, 1, 3, 0, 0);
                SetEntryOn(obj, data_ov023_021fd61e[i]);
                break;
            }
        }
        FlushList(obj, buf);
        _Z29CreateAndSetFields8A_021db544PvS_ii(obj->list, (void*)0xb, c0, c1);
        SetEntryOff(obj, 0xb);
    } else {
        short d1, d0;
        _Z28UpdateEntryAndReset_021db45cPvP18StructAcAe021db45ciPsS2_(obj->list, (struct StructAcAe021db45c*)buf, 0xb, &d0, &d1);
        SetEntryOn(obj, 0xb);
        SetEntryOn(obj, 0x2c);
#if defined(jpn)

#else
        {
            struct Entry021ddf5c* e = (struct Entry021ddf5c*)func_ov023_021db4e4(obj->list, 0x2c);
            if (e) e->flags |= 8;
        }

#endif
        _Z23SetEntryFields_021e23d0Pviihh(obj->list, 0x2c, _Z21GetFieldByKey020e0434P17Container020e0310i(data_ov023_021ff9e0.field14, 0x21), 10, 0xf);
        SetEntryOff(obj, 0xa);
        SetEntryOff(obj, 0xc);
        SetEntryOff(obj, 0xd);
        SetEntryOff(obj, 0xe);
        SetEntryOff(obj, 0x2d);
        SetEntryOff(obj, 0x2e);
        FlushList(obj, buf);
        _Z29CreateAndSetFields8A_021db544PvS_ii(obj->list, (void*)0xb, d0, d1);
        SetEntryOff(obj, 0xb);
    }

    if (obj->lastPos) {
        func_ov023_021ddc98(buf, obj->lastPos, (unsigned short)data_ov023_021ff9e0.fieldc, 0);
    } else {
        int len = func_ov023_021ddc98(buf, obj->pos, (unsigned short)data_ov023_021ff9e0.fieldc, 0);
        obj->lastPos = obj->pos;
        obj->lastLen = len;
        obj->pos = obj->pos + len;
    }
}
