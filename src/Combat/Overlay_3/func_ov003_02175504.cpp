// USA: func_ov003_02175504
#include <globaldefs.h>

struct Obj2081;
struct Container020dedd0 {
    unsigned short count;
    unsigned char unknown02[10];
    void* entries;
    unsigned char unknown10[4];
    unsigned char useBinarySearch;
};
struct Obj020dee58;

unsigned char *FindElementByByte0xc4(Obj2081 *, int);
bool IsField0x9cEqual3(unsigned char *);
extern "C" Obj020dee58 *_Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0 *, int);
extern "C" void _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(void *, int, int, short *, short *);
int LookupValueFromField8(Obj020dee58 *);
extern "C" void _Z25InitEntryAtIndex_0217585cPviiih(void *, int, int, int, unsigned char);
bool CheckField0x9cSetWhenField0xd4Present(unsigned char *);

#if defined(jpn)
extern unsigned char data_ov003_0217e34d[];
extern unsigned char data_ov003_0217e32c[];
#else
extern unsigned char data_ov003_0217fabd[];
extern unsigned char data_ov003_0217fa9c[];
#endif

struct Entry02175504 {
    char unk_0[0xac];
    short x_;
    short y_;
};

struct Battle02175504 {
#if defined(jpn)
    unsigned char unknownBeforeKeys[0x7c4];
#else
    unsigned char unknownBeforeKeys[0x848];
#endif
    short keys_[12];
    unsigned char unknownBeforeEntries[0x14];
    Container020dedd0 entries;
    unsigned char unknownAfterEntries[0x10];
    Obj2081* menu;
    unsigned char unknownBeforeUpdate[0xff8 - 0x8a0];
    int updateEnabled;
    unsigned char unknownBeforeIndex[2];
    short selectedIndex;
    unsigned char unknownBeforeState[0xc];
    short state;
    unsigned char unknownAfterState[2];
    short unknown1010;
    short selection;
    short page;
};

// USA: func_ov003_02175504
extern "C" ARM void func_ov003_02175504(Battle02175504 *self) {
    Obj2081 *obj     = self->menu;
    unsigned char k  = 6;
    unsigned char *e = FindElementByByte0xc4(obj, 3);
    if (e) {
        if (!IsField0x9cEqual3(e)) return;
        short a = 7;
        short b = (short) (self->page * 6);
        for (unsigned char i = 0; i < 6; i++) {
            Obj020dee58 *it = _Z24FindElementByKey020dedd0P17Container020dedd0i(&self->entries,
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
    if (self->state == 0x77) {
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
#if defined(jpn)
            _Z25InitEntryAtIndex_0217585cPviiih(self, cx, cy, data_ov003_0217e34d[(self->selection + (k - 0x124)) & 0xff], k);
#else
            _Z25InitEntryAtIndex_0217585cPviiih(self, cx, cy, data_ov003_0217fabd[(self->selection + (k - 0x124)) & 0xff], k);
#endif
            return;
        }
    }
    if (self->updateEnabled == 0) return;
    if (self->selectedIndex < 0) return;
    e = FindElementByByte0xc4(obj, 0xe);
    if (!e) return;
    if (!CheckField0x9cSetWhenField0xd4Present(e)) return;
    short a = 0x68;
    for (unsigned char i = 0; i < 8; i++) {
        short x, y;
        _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(obj, 0xe, a, &x, &y);
#if defined(jpn)
        _Z25InitEntryAtIndex_0217585cPviiih(self, x, y - 1, data_ov003_0217e32c[i], k);
#else
        _Z25InitEntryAtIndex_0217585cPviiih(self, x, y - 1, data_ov003_0217fa9c[i], k);
#endif
        a++;
        k++;
    }
}
