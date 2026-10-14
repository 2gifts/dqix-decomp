#include <globaldefs.h>

char *GetGlobalField0x1c020421a0(void);
extern "C" char *func_02012fe4(void);
extern "C" void *func_0205ec34(void);
extern "C" void func_ov003_02170960(void *self, int a, int b);
extern "C" int func_0201248c(void *obj, int mask);

struct Obj_0216f414;
struct Entry0216efdc;
Entry0216efdc *FindEntryByShortId_0216f414(Obj_0216f414 *list, int id);
int TestBitInByteArray(int a, unsigned char *bits, int index);
void SetOrClearBitInArray(void *a, unsigned char *bits, int index, int set);
int TestFlag0SetAndFlag1Clear(unsigned short *obj, int mask);
int CheckByteSetAndByteClear(unsigned char *p);

extern unsigned short data_02114e30;
extern char data_02114e54;

struct Entry0216efdc {
    unsigned char pad0[0x16];
    unsigned char flags;
};

struct Global0216efdc {
    char unk_0[0x998];
    int unk_998;
    char unk_99c[4];
    int unk_9a0;
};

struct Progress0216efdc {
    unsigned char pad0[0xb38];
    int chapter;
};

struct BgCnt0216efdc {
    volatile unsigned short priority_ : 2;
    volatile unsigned short rest_ : 14;
};

struct Menu0216efdc {
    unsigned char unk_0;
    unsigned char unk_1;
    signed char state_;
    char unk_3;
    unsigned char unk_4;
    unsigned char unk_5;
    signed char unk_6;
    signed char unk_7;
    unsigned char unk_8;
    signed char unk_9;
    char unk_a[2];
    short unk_c;
    short unk_e;
    char unk_10[0x20 - 0x10];
    unsigned short unk_20;
    char unk_22[0xd4 - 0x22];
    void *unk_d4;
};

// USA: func_ov003_0216efdc
extern "C" ARM void func_ov003_0216efdc(Menu0216efdc *self) {
    Global0216efdc *global     = (Global0216efdc *) GetGlobalField0x1c020421a0();
    Progress0216efdc *progress = (Progress0216efdc *) (func_02012fe4() + 0x1840);
    int chapter                = progress->chapter;
    int state                  = self->state_;
    if (state == 0) {
        volatile unsigned short *bg = (volatile unsigned short *) 0x4000008;
        bg[0]                       = (bg[0] & ~3);
        bg[1]                       = (bg[1] & ~3) | 1;
        bg[2]                       = (bg[2] & ~3) | 2;
        bg[3]                       = (bg[3] & ~3) | 3;
        if (self->unk_d4 != 0) {
            Entry0216efdc *e = FindEntryByShortId_0216f414((Obj_0216f414 *) self->unk_d4, 0x19);
            if (e != 0) {
                e->flags |= 2;
            }
            e = FindEntryByShortId_0216f414((Obj_0216f414 *) self->unk_d4, 0x1a);
            if (e != 0) {
                e->flags &= ~2;
            }
        }
        void *save = func_0205ec34();
        if (TestBitInByteArray((int) save, (unsigned char *) save + 0x8c, 0x783) != 0) {
            self->state_ = 1;
            return;
        }
        SetOrClearBitInArray(save, (unsigned char *) save + 0x8c, 0x783, 1);
        func_ov003_02170960(self, 0x1f, 0);
        global->unk_998 = 1;
        self->unk_20 |= 1;
        self->state_ = 0x65;
    } else if (state == 0x65) {
        if (global->unk_9a0 == 0 && global->unk_998 == 0) {
            self->state_ = 1;
        }
    } else if (state == 1) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0 || self->unk_e == 5) {
            self->unk_1  = 6;
            self->state_ = 0;
            return;
        }
        if (chapter == 0) {
            return;
        }
        if (func_0201248c(&data_02114e30, 0x10) != 0 || self->unk_e == 0x11) {
            self->unk_0++;
            if (self->unk_0 > self->unk_4) {
                self->unk_0 = 1;
            }
            int n;
            if (self->unk_0 == self->unk_4 && (n = chapter % 8) != 0) {
                self->unk_5 = n;
            } else {
                self->unk_5 = 8;
            }
            if (self->unk_6 > self->unk_5 - 1) {
                self->unk_6 = self->unk_5 - 1;
            }
            self->unk_7  = -1;
            self->unk_1  = 2;
            self->state_ = 0;
        } else if (func_0201248c(&data_02114e30, 0x20) != 0 || self->unk_e == 0x10) {
            self->unk_0--;
            if (self->unk_0 < 1) {
                self->unk_0 = self->unk_4;
            }
            int n;
            if (self->unk_0 == self->unk_4 && (n = chapter % 8) != 0) {
                self->unk_5 = n;
            } else {
                self->unk_5 = 8;
            }
            if (self->unk_6 > self->unk_5 - 1) {
                self->unk_6 = self->unk_5 - 1;
            }
            self->unk_7  = -1;
            self->unk_1  = 2;
            self->state_ = 0;
        } else if (func_0201248c(&data_02114e30, 0x80) != 0) {
            self->unk_6 = self->unk_6 + 1;
            if (self->unk_6 > self->unk_5 - 1) {
                self->unk_6 = 0;
            }
            self->unk_7  = -1;
            self->unk_1  = 2;
            self->state_ = 0;
        } else if (func_0201248c(&data_02114e30, 0x40) != 0) {
            self->unk_6 = self->unk_6 - 1;
            if (self->unk_6 < 0) {
                self->unk_6 = self->unk_5 - 1;
                if (self->unk_6 < 0) {
                    self->unk_6 = 0;
                }
            }
            self->unk_7  = -1;
            self->unk_1  = 2;
            self->state_ = 0;
        } else {
            int sel = -2;
            if (self->unk_e <= 0xd) {
                if (self->unk_e >= 6) {
                    sel = self->unk_e - 6;
                }
            }
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x401) != 0 || sel == self->unk_7) {
                self->unk_8  = 0;
                self->unk_9  = -1;
                self->unk_1  = 5;
                self->state_ = 0;
                return;
            }
            if (self->unk_c > 0xd) {
                return;
            }
            if (self->unk_c < 6) {
                return;
            }
            if (CheckByteSetAndByteClear((unsigned char *) &data_02114e54) == 0) {
                return;
            }
            self->unk_6 = self->unk_c - 6;
            if (self->unk_6 > self->unk_5 - 1) {
                self->unk_6 = self->unk_5 - 1;
            }
            if (self->unk_7 != self->unk_6) {
                self->unk_7  = self->unk_6;
                self->unk_1  = 2;
                self->state_ = 0;
                return;
            }
        }
    }
}
