#include <globaldefs.h>

struct Obj2081;
struct Container020dedd0;
struct Obj020dee58;

unsigned char *FindElementByByte0xc4(Obj2081 *, int);
bool IsField0x9cEqual3(unsigned char *);
extern "C" Obj020dee58 *_Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0 *, int);
extern "C" void _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(void *, int, int, short *, short *);
int LookupValueFromField8(Obj020dee58 *);
extern "C" void _Z25InitEntryAtIndex_0217585cPviiih(void *, int, int, int, unsigned char);
bool CheckField0x9cSetWhenField0xd4Present(unsigned char *);

extern unsigned char data_ov003_0217fabd[];
extern unsigned char data_ov003_0217fa9c[];

struct Entry02175504 {
    char unk_0[0xac];
    short x_;
    short y_;
};

struct Battle02175504 {
    char unk_0[0x74];
    char blk74_[0x848 - 0x74];
    short keys_[0xc];
    char unk_860[0x89c - 0x860];
    Obj2081 *obj_;
    char unk_8a0[0xf00 - 0x8a0];
    char unk_f00[0xff8 - 0xf00];
    int ff8_;
    char unk_ffc[0x1000 - 0xffc];
    char unk_1000[0xc];
    short s100c_;
    char unk_100e[2];
    short s1010_;
    short s1012_;
    short s1014_;
};

// USA: func_ov003_02175504
extern "C" ARM void func_ov003_02175504(Battle02175504 *self) {
    Obj2081 *obj     = self->obj_;
    unsigned char k  = 6;
    unsigned char *e = FindElementByByte0xc4(obj, 3);
    if (e) {
        if (!IsField0x9cEqual3(e)) return;
        short a = 7;
        short b = (short) (self->s1014_ * 6);
        for (unsigned char i = 0; i < 6; i++) {
            Obj020dee58 *it = _Z24FindElementByKey020dedd0P17Container020dedd0i((Container020dedd0 *) (self->blk74_ + 0x800),
                                                                                self->keys_[b]);
            if (it) {
                short x, y;
                _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(obj, 3, a, &x, &y);
                int v = LookupValueFromField8(it);
                _Z25InitEntryAtIndex_0217585cPviiih(self, x, y - 1, (v + 6) & 0xff, k);
            }
            k++;
            a++;
            b++;
        }
        return;
    }
    if (self->s100c_ == 0x77) {
        Entry02175504 *cand = 0;
        e                   = FindElementByByte0xc4(obj, 0x15);
        if (e && IsField0x9cEqual3(e)) cand = (Entry02175504 *) e;
        e = FindElementByByte0xc4(obj, 0x16);
        if (e && IsField0x9cEqual3(e)) cand = (Entry02175504 *) e;
        e = FindElementByByte0xc4(obj, 0x1e);
        if (e && IsField0x9cEqual3(e)) cand = (Entry02175504 *) e;
        if (cand) {
            int cx = cand->x_;
            int cy = cand->y_;
            cx     = (short) (cx << 3) + 3;
            cy     = (short) (cy << 3) + 3;
            _Z25InitEntryAtIndex_0217585cPviiih(self, cx, cy, data_ov003_0217fabd[(self->s1012_ + (k - 0x124)) & 0xff], k);
            return;
        }
    }
    if (self->ff8_ == 0) return;
    if (*(short *) ((char *) self + 0xffe) < 0) return;
    e = FindElementByByte0xc4(obj, 0xe);
    if (!e) return;
    if (!CheckField0x9cSetWhenField0xd4Present(e)) return;
    short a = 0x68;
    for (unsigned char i = 0; i < 8; i++) {
        short x, y;
        _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(obj, 0xe, a, &x, &y);
        _Z25InitEntryAtIndex_0217585cPviiih(self, x, y - 1, data_ov003_0217fa9c[i], k);
        a++;
        k++;
    }
}
