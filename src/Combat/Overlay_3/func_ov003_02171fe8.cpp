#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void __clear(void *dst, int count);
extern "C" void func_ov003_02170a7c(char *in, char *out);
extern "C" void func_020426bc(const char *text, char *codes, int a);
extern "C" void *func_02012fe4(void);
extern "C" int func_ov003_021725a4(void *self, void *rec);

struct Struct0200fb08;
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08 *p);
extern "C" int _Z30CheckNoConflictInArray0209890cPvS_(void *zone, void *rec);

extern const char *data_ov003_021805bc[];

struct S6 {
    char v[6];
};
struct S11 {
    char v[11];
};
struct S14 {
    unsigned short v[14];
};
struct W6 {
    int v[6];
};
struct W31 {
    int v[31];
};

struct Stat7c {
    unsigned int pad0_ : 25;
    unsigned int flag_ : 1;
    unsigned int rest0_ : 6;
    int f0_ : 9;
    int f9_ : 10;
    int f19_ : 11;
    int f30_ : 2;
    int rest_[29];
};

struct Slot {
    S11 name_;
    unsigned char flag7_ : 7;
    unsigned char flag_ : 1;
    unsigned int lo_ : 4;
    unsigned int pad_ : 4;
    unsigned int mid_ : 7;
    unsigned int hi_ : 17;
    int w10_;
    S6 s14_;
    S14 h1a_;
    W6 w38_;
    S14 h50_;
    W31 w6c_;
};

struct SlotRaw {
    S11 name_;
    unsigned char b0b_;
    unsigned int w0c_;
    int w10_;
    S6 s14_;
    S14 h1a_;
    W6 w38_;
    S14 h50_;
    W31 w6c_;
};

struct Wire {
    S11 name_;
    unsigned char b0_;
    unsigned char b1_;
    unsigned char b2_;
    S6 s_;
    W31 w_;
    S14 h_;
    W6 x_;
    TreasureMapMetadata tm_;
};

struct Self0217 {
    char pad0_[0x199];
    unsigned char b199_;
    char pad19a_[0x2a0 - 0x19a];
    Wire wire_;
    char pad380_[0x460 - 0x380];
    Slot slots_[3];
    unsigned char b718_;
    char pad719_[3];
    int w71c_;
    int w720_;
    int w724_;
    char pad728_[4];
    int w72c_;
};

// USA: func_ov003_02171fe8
extern "C" ARM void func_ov003_02171fe8(Self0217 *self, int id, void *data, unsigned int len, unsigned int offset) {
    char a[11];
    char a2[11];
    Slot local;
    if (self->b199_ == id) {
        self->w72c_ = 0;
        memcpy((char *) &self->wire_ + offset, data, len);
        if (offset + len >= 0xe0) {
            self->w71c_ = 1;
            self->w724_ = 1;
            if (*(unsigned int *) ((char *) self + 0x34c) >> 31) {
                self->wire_.tm_.SetDiscoveryState(DiscoveryState_Undiscovered);
                self->wire_.tm_.ClearInitialByteUnknownBit();
                strcpy((char *) &local.name_, (char *) &self->wire_.name_);
                local.lo_   = self->wire_.b0_;
                local.mid_  = self->wire_.b1_;
                local.flag_ = self->wire_.b2_;
                memcpy(&local.w6c_, &self->wire_.w_, 0x7c);
                memcpy(&local.h1a_, &self->wire_.h_, 0x1c);
                memcpy(&local.w38_, &self->wire_.x_, 0x18);
                memcpy(&local.h50_, &self->wire_.tm_, 0x1c);
                memcpy(&local.s14_, &self->wire_.s_, 6);
                local.w6c_.v[0] |= 0x4000000;
            } else {
                GameState *gs = GameState::GetInstance();
                self->wire_.tm_.SetDiscoveryState(DiscoveryState_Undiscovered);
                self->wire_.tm_.ClearInitialByteUnknownBit();
                local.lo_   = self->wire_.b0_;
                local.mid_  = self->wire_.b1_;
                local.flag_ = self->wire_.b2_;
                memcpy(&local.w6c_, &self->wire_.w_, 0x7c);
                memcpy(&local.h1a_, &self->wire_.h_, 0x1c);
                memcpy(&local.w38_, &self->wire_.x_, 0x18);
                memcpy(&local.h50_, &self->wire_.tm_, 0x1c);
                memcpy(&local.s14_, &self->wire_.s_, 6);
                local.w6c_.v[0] |= 0x4000000;
                int kind = _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08 *) gs);
                int idx  = 0;
                switch (kind) {
                    case 2: idx = 1; break;
                    case 3: idx = 2; break;
                    case 4: idx = 3; break;
                    case 5: idx = 4; break;
                }
                __clear(a, 11);
                memset(a, 0, 0xb);
                func_ov003_02170a7c((char *) &self->wire_.name_, a);
                memset(&self->wire_.name_, 0, 0xb);
                func_020426bc(a, (char *) &local.name_, 1);
                func_020426bc(data_ov003_021805bc[idx], (char *) &local.w6c_.v[2], 1);
                Stat7c *st = (Stat7c *) &local.w6c_;
                if (st->f9_ >= 100) {
                    if (st->f9_ < 200) {
                        st->f9_ = 396;
                    }
                }
                if (st->flag_ == 1) {
                    if (st->f19_ >= 700 && st->f19_ < 750) {
                        st->f19_ = st->f19_ + 50;
                    } else if (st->f19_ >= 800) {
                        st->f19_ = st->f19_ + 100;
                    }
                }
                char *tm = (char *) &local.h50_;
                __clear(a2, 11);
                memset(a, 0, 0xb);
                memset(a2, 0, 0xb);
                memcpy(a2, tm + 1, 10);
                func_ov003_02170a7c(a2, a);
                memset(tm + 1, 0, 10);
                func_020426bc(a, tm + 1, 1);
                memset(a, 0, 0xb);
                memset(a2, 0, 0xb);
                memcpy(a2, tm + 0xb, 10);
                func_ov003_02170a7c(a2, a);
                memset(tm + 0xb, 0, 10);
                func_020426bc(a, tm + 0xb, 1);
            }
            char *zone = (char *) func_02012fe4();
            if (self->b718_ < 3) {
                if (_Z30CheckNoConflictInArray0209890cPvS_(zone + 0x840, &local) != 0) {
                    if (func_ov003_021725a4(self, &local) != 0) {
                        SlotRaw *d  = (SlotRaw *) &self->slots_[self->b718_];
                        d->name_    = ((SlotRaw *) &local)->name_;
                        d->b0b_     = ((SlotRaw *) &local)->b0b_;
                        d->w0c_     = ((SlotRaw *) &local)->w0c_;
                        d->w10_     = ((SlotRaw *) &local)->w10_;
                        d->s14_     = ((SlotRaw *) &local)->s14_;
                        d->h1a_     = ((SlotRaw *) &local)->h1a_;
                        d->w38_     = ((SlotRaw *) &local)->w38_;
                        d->h50_     = ((SlotRaw *) &local)->h50_;
                        d->w6c_     = ((SlotRaw *) &local)->w6c_;
                        self->b718_ = self->b718_ + 1;
                    }
                }
            }
        }
    }
}
