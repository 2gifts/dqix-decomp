#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct020dfc40;
struct InitStruct02174408;
struct Obj02081ee4;
struct Sub02081ee4;
struct List0204af64;

struct Global020421a0 {
    char unk_0[0x5c];
    int p5c_;
    char unk_60[0x998 - 0x60];
    int f998_;
    int f99c_;
};

struct Fighter02174114 {
    char unk_0[0x56b];
    unsigned char lo_ : 4;
    unsigned char hi_ : 4;
};

struct Battle02174114 {
    int unk_0;
    int f4_;
    int f8_;
    char s0c_[0x24 - 0xc];
    char s24_[0x34 - 0x24];
    unsigned char b34_;
    unsigned char b35_;
    char unk_36[2];
    int dispcnt_;
    char s3c_[0x7d8 - 0x3c];
    char s7d8_[0x830 - 0x7d8];
    int f830_;
    char s834_[0x88c - 0x834];
    char s88c_[0x898 - 0x88c];
    char s898_[0x89c - 0x898];
    int f89c_;
    char lists_[0x8e0 - 0x8a0];
    char slots_[0xfe0 - 0x8e0];
    int ffe0_;
    int ffe4_;
    int ffe8_;
    int ffec_;
    int fff0_;
    int fff4_;
    int fff8_;
    short sffc_;
    short sffe_;
    short s1000_[10];
    short s1014_;
    short s1016_;
    int f1018_;
    int ids_[5];
    int count_;
    short s1034_[4];
    unsigned char b103c_;
    unsigned char b103d_;
    unsigned char b103e_;
    unsigned char b103f_;
    unsigned char b1040_;
    unsigned char b1041_;
    unsigned char b1042_;
    signed char b1043_;
    signed char b1044_;
    char unk_1045;
    short s1046_;
    short s1048_;
    char unk_104a;
    unsigned char b104b_;
    unsigned char b104c_;
    char unk_104d;
    unsigned char b104e_;
    unsigned char b104f_;
};

Global020421a0 *GetGlobalField0x1c020421a0(void);
extern "C" void func_0204500c(Global020421a0 *, int, int, int);
void ResetStruct020dfc40(Struct020dfc40 *);
extern "C" void func_02074af4(void *);
extern "C" void func_ov023_021dc134(void *, int, int);
void InitStruct0205a444(char *);
void InitObj02174408(InitStruct02174408 *);
void InitWithSub02081ee4(Obj02081ee4 *, Sub02081ee4 *);
void ResetList0204af64(List0204af64 *);
extern "C" void func_0204c684(void *);
unsigned char CopyOutRegion0x5718_02011494(char *, void *);
GameObject *GetCombatantWithFlag0x100_0200ff1c(GameState *, int);

// USA: func_ov003_02174114
extern "C" ARM void func_ov003_02174114(Battle02174114 *self) {
    Global020421a0 *g = GetGlobalField0x1c020421a0();
    int p             = g->p5c_;
    self->fff0_       = g->f99c_;
    func_0204500c(g, p, 0, 0xe3);
    g->f998_ = 1;
    g->f99c_ = self->fff0_;

    self->f4_ = 0;
    self->f8_ = 0;
    ResetStruct020dfc40((Struct020dfc40 *) (self->s0c_));
    self->b34_ = 0;
    self->b35_ = 0;
    func_02074af4(self->s24_);
    volatile unsigned int *reg = (volatile unsigned int *) 0x4000000;
    unsigned int v             = *reg;
    self->dispcnt_             = (v & 0x1f00u) >> 8;
    v                          = *reg;
    *reg                       = (v & ~0x1f00u) | 0x100u;
    func_ov023_021dc134((char *) self + 0x3c, -1, 0);
    InitStruct0205a444(self->s7d8_);
    self->f830_ = 0;
    InitObj02174408((InitStruct02174408 *) self->s834_);
    InitWithSub02081ee4((Obj02081ee4 *) self->s88c_, (Sub02081ee4 *) self->s898_);
    self->f89c_ = 0;
    for (int i = 0; i < 2; i++)
        ResetList0204af64((List0204af64 *) (self->lists_ + i * 32));
    for (int j = 0; j < 8; j++)
        func_0204c684(self->slots_ + j * 0xe0);

    self->ffe0_     = 0;
    self->ffe4_     = 0;
    self->ffe8_     = 0;
    self->ffec_     = -1;
    self->fff4_     = 0;
    self->fff8_     = 0;
    self->sffc_     = -1;
    self->sffe_     = -1;
    self->s1000_[0] = -1;
    self->s1000_[1] = -1;
    self->s1000_[2] = -1;
    self->s1000_[3] = -1;
    self->s1000_[4] = -1;
    self->s1000_[5] = -1;
    self->s1000_[6] = -1;
    self->s1000_[7] = -1;
    self->s1000_[8] = -1;
    self->s1000_[9] = -1;
    self->s1014_    = 0;
    self->s1016_    = 0;
    self->f1018_    = 0;
    for (int k = 0; k < 5; k++)
        self->ids_[k] = -1;
    self->count_    = 0;
    self->s1034_[0] = -1;
    self->s1034_[1] = -1;
    self->s1034_[2] = -1;
    self->s1034_[3] = -1;
    self->b103c_    = 1;
    self->b103d_    = 0;
    self->b103e_    = 0;
    self->b103f_    = 0;
    self->b1040_    = 0;
    self->b1041_    = 0;
    self->b1042_    = 0;
    self->b1043_    = -1;
    self->b1044_    = -1;
    self->s1046_    = 0;
    self->s1048_    = -1;
    self->b104c_    = 0;
    self->b104b_    = 0;
    self->b104e_    = 0;
    self->b104f_    = 0;

    GameState *gs = GameState::GetInstance();
    unsigned char buf[8];
    int n = CopyOutRegion0x5718_02011494((char *) gs, buf);
    for (int m = 0; m < n; m++)
        self->ids_[m] = buf[m];
    self->count_ = n;

    int r = 0;
    while (r < self->count_) {
        GameObject *c = GetCombatantWithFlag0x100_0200ff1c(gs, self->ids_[r]);
        if (c) {
            Fighter02174114 *f = *(Fighter02174114 **) ((char *) c + 0x150);
            bool alive         = f ? (f->lo_ != 0) : false;
            if (alive) {
                int s = r;
                while (s < self->count_) {
                    self->ids_[s] = self->ids_[s + 1];
                    s++;
                    self->ids_[s] = -1;
                }
                self->count_--;
            }
        }
        r++;
    }
}
