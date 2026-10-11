#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj0205eaa0;
struct Struct_0205def8;
struct Struct_0205d81c;
struct Obj0205dee8;
struct Obj020e280c;
struct IntField0x23c_020a27c4;
struct Obj020e25e8;
struct Entry_0205d6a0;
struct Struct_0205bcdc;
struct Container020dedd0;
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_02160fb4(char *base);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int clear, int key);
extern "C" char *_Z20GetField4Ptr020e1b24Pv(void *p);
extern "C" void _Z26ResetAndReposition020e280cP11Obj020e280cPv(struct Obj020e280c *self, void *b);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
char *GetFieldIfFlag4(char *obj);
int GetIntAt0x23c(struct IntField0x23c_020a27c4 *obj);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
int GetField0x15UnlessInactive(signed char *param);
int GetSignedByteAt0x14(signed char *p);
extern "C" void _Z27ResetSelectionState020e25e8P11Obj020e25e8(struct Obj020e25e8 *obj);
extern "C" char *_Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0 *c, int key);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0 *a, int flag);
extern "C" void func_ov017_0219577c(int a, int b, int c);
extern "C" char *_Z25GetCombatantWithFlag0x100P9GameStatei(GameState *gs, int id);
extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" void func_ov002_0216bfd4(char *self, int a);
extern "C" void _Z27EnqueueEventTag170_021d0198iiii(int a, int b, int c, int d);
extern "C" int _Z28CheckStateAndGetCode0215753cPh(unsigned char *p);
extern "C" void func_ov002_02156e90(void *base);
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
extern "C" void _Z24ReinitController02043204Pc(char *obj);
extern "C" void _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(struct Obj0205dee8 *o, int v);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(struct Struct_0205bcdc *s, int index);
extern "C" void func_0205bb04(void *s, int n);
extern "C" int _Z23IsFlag0x2Active020e2984v(void);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];
extern "C" unsigned char data_ov002_0216d3ac;

struct Bits0216a300 {
    char pad[0x3f];
    unsigned char b0 : 1;
};
#define LST(base) ((base) + 0x2c8 + 0xc00)

#define CONFIRM_0216A300() \
    do { \
        char *e = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0 *) (base + 0x3ec + 0x400), \
                                                                    *(short *) (base + 0x1c00 + 0x22)); \
        if (e != NULL && *(short *) (e + 0x18) == 0x5612) { \
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 1); \
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) LST(base), 0); \
            *(short *) (base + 0x1c00 + 0x28)          = 0x797e; \
            *(short *) (base + 0x1c00 + 0x2a)          = -1; \
            *(int *) (base + 0x1000 + 0xbb8)           = 0x26; \
            *(int *) (base + 0x1000 + 0xbbc)           = 5; \
            *(int *) (base + 0x1000 + 0xbc0)           = 0; \
            *(unsigned char *) (base + 0x1000 + 0xc2e) = 0; \
            return; \
        } \
        if (*(unsigned char *) (base + 0x1000 + 0xc30) != 0) { \
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 1); \
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) LST(base), 0); \
            switch (*(unsigned char *) (base + 0x1000 + 0xc79)) { \
                case 0: func_ov002_0216bfd4(base, 4); return; \
                case 3: func_ov002_0216bfd4(base, 2); return; \
            } \
            return; \
        } \
        func_ov002_02156e90(base); \
        _Z24ReinitController02043204Pc(g); \
        if (*(unsigned char *) (base + 0x2000 + 0x521) != 0) { \
            *(int *) (base + 0x1000 + 0xbb8) = *(int *) (base + 0x1000 + 0xbbc); \
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i((struct Obj0205dee8 *) LST(base), 4); \
            SetElementFieldC2((struct Struct_0205d81c *) LST(base), 4, 0); \
            func_ov002_02161cf0(base); \
            *(unsigned char *) (base + 0x2000 + 0x521) = 0; \
        } else if ((*(short *) (base + 0x1b00 + 0xf0) >= 0 || *(short *) (base + 0x1b00 + 0xe8) >= 0 || \
                    *(short *) (base + 0x1c00 + 0xa) >= 0) && \
                   *(short *) (base + 0x1c00 + 0xa) != 0) \
        { \
            int n_   = (*(short *) (base + 0x1c00 + 0xa) = 7); \
            char *l_ = LST(base); \
            _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((struct Struct_0205bcdc *) (l_ + 4), n_); \
            func_0205bb04(l_ + 0x54, n_); \
            func_ov002_0215b9a4(base, 0x21, 0); \
        } \
        if (*(int *) (base + 0x1000 + 0xbbc) == 0xb) { \
            *(int *) (base + 0x1000 + 0xbb8) = 0xb; \
            func_ov002_0215b9a4(base, 0xb, 0); \
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i((struct Obj0205dee8 *) LST(base), 0xb); \
            SetElementFieldC2((struct Struct_0205d81c *) LST(base), 0xb, 0); \
            SetElementFieldC2((struct Struct_0205d81c *) LST(base), 0xd, 1); \
            func_ov002_02161cf0(base); \
        } \
    } while (0)

// USA: func_ov002_0216a300
extern "C" ARM void func_ov002_0216a300(char *base) {
    char *g                                 = (char *) _Z26GetGlobalField0x1c020421a0v();
    *(unsigned char *) (g + 0x1000 + 0x9ae) = 0;
    int state                               = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) LST(base), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_02160fb4(base);
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 5, 0);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) LST(base), 0, 0x25);
        char *p = _Z20GetField4Ptr020e1b24Pv(*(void **) (*(char **) base + 0x10));
        if (((struct Bits0216a300 *) p)->b0) {
            _Z26ResetAndReposition020e280cP11Obj020e280cPv(*(struct Obj020e280c **) (base + 4), *(void **) (p + 0x30));
        } else {
            _Z26ResetAndReposition020e280cP11Obj020e280cPv(*(struct Obj020e280c **) (base + 4), (void *) -1);
        }
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) LST(base), 0, 0x25);
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1c00 + 0x12) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) LST(base));
        int ok  = 0;
        char *f = GetFieldIfFlag4((char *) GameState::GetInstance());
        if (f != NULL && ((*(unsigned char *) (f + 0x244) & 2) || GetIntAt0x23c((struct IntField0x23c_020a27c4 *) f) == 0)) {
            ok = TestFlag0SetAndFlag1Clear(data_02114e30, 0x200) ? 1 : 0;
        }
        *(short *) (base + 0x1c00 + 0x12) = GetField0x15UnlessInactive(*(signed char **) (base + 4));
        if (*(short *) (base + 0x1c00 + 0x12) >= 0 || ok) {
            *(short *) (base + 0x1c00 + 0x12) = GetSignedByteAt0x14(*(signed char **) (base + 4));
            _Z27ResetSelectionState020e25e8P11Obj020e25e8(*(struct Obj020e25e8 **) (base + 4));
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
            data_ov002_0216d3ac = 0;
            switch (*(short *) (base + 0x1c00 + 0x12)) {
                case 0: {
                    *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
                    *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
                    char *e                           = _Z24FindElementByKey020dedd0P17Container020dedd0i(
                        (struct Container020dedd0 *) (base + 0x3ec + 0x400), *(short *) (base + 0x1c00 + 0x22));
                    if (e != NULL && *(short *) (e + 0x18) == 0x5612) {
                        func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 1);
                        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) LST(base), 0);
                        *(short *) (base + 0x1c00 + 0x28)          = 0x7972;
                        *(short *) (base + 0x1c00 + 0x2a)          = -1;
                        *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
                        *(int *) (base + 0x1000 + 0xbbc)           = 0x2b;
                        *(int *) (base + 0x1000 + 0xbc0)           = 0;
                        *(unsigned char *) (base + 0x1000 + 0xc2e) = 0;
                        func_ov017_0219577c(1, 1, 1);
                        return;
                    }
                    if (*(unsigned char *) (base + 0x1000 + 0xc30) != 0) {
                        *(unsigned char *) (base + 0x1000 + 0xc2e) = 0;
                        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) LST(base), 0);
                        switch (*(unsigned char *) (base + 0x1000 + 0xc79)) {
                            case 0: {
                                char *m = _Z25GetCombatantWithFlag0x100P9GameStatei(GameState::GetInstance(),
                                                                                    *(signed char *) (base + 0x1c00 + 0x21));
                                int go  = 1;
                                if (m != NULL && *(unsigned short *) (*(char **) (m + 0x130) + 4) == 0) go = 0;
                                if (!func_020dc920(*(unsigned char *) (base + 0x1000 + 0xc21), 1, 0, 0)) go = 0;
                                if (go) {
                                    func_ov002_0216bfd4(base, 1);
                                    _Z27EnqueueEventTag170_021d0198iiii(1, *(signed char *) (base + 0x1c00 + 0x20),
                                                                        *(signed char *) (base + 0x1c00 + 0x21),
                                                                        *(short *) (base + 0x1c00 + 0x22));
                                    *(int *) (base + 0x1000 + 0xc74) = 0x1e;
                                } else {
                                    func_ov002_0216bfd4(base, 6);
                                }
                                return;
                            }
                            case 3:
                                func_ov002_0216bfd4(base, 4);
                                _Z27EnqueueEventTag170_021d0198iiii(2, *(signed char *) (base + 0x1c00 + 0x20),
                                                                    *(signed char *) (base + 0x1c00 + 0x21),
                                                                    *(short *) (base + 0x1c00 + 0x22));
                                return;
                        }
                        return;
                    }
                    if (*(unsigned char *) (base + 0x1000 + 0xc32) != 0) {
                        *(unsigned char *) (base + 0x1000 + 0xc32) = 0;
                        *(short *) (base + 0x1c00 + 0x28)          = 0x2367;
                        *(short *) (base + 0x1c00 + 0x2a)          = -1;
                        *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
                        *(int *) (base + 0x1000 + 0xbbc)           = 5;
                        *(int *) (base + 0x1000 + 0xbc0)           = 0;
                        *(unsigned char *) (base + 0x1000 + 0xc2e) = 1;
                        return;
                    }
                    *(short *) (base + 0x1c00 + 0x28)          = _Z28CheckStateAndGetCode0215753cPh((unsigned char *) base);
                    *(short *) (base + 0x1c00 + 0x2a)          = -1;
                    *(unsigned char *) (base + 0x1000 + 0xc2e) = 0;
                    if (*(short *) (base + 0x1c00 + 0x28) < 0) {
                        func_ov002_02156e90(base);
                        if (*(short *) (base + 0x1c00 + 0xa) >= 0) {
                            func_ov002_02156e90(base);
                            func_ov002_02156e90(base);
                            func_ov002_02161cf0(base);
                            *(int *) (base + 0x1000 + 0xbc0) = 1;
                            *(short *) (base + 0x1c00 + 0xa) = -1;
                        }
                    } else {
                        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) LST(base), 0);
                        *(int *) (base + 0x1000 + 0xbb8)  = 0x26;
                        *(short *) (base + 0x1c00 + 0x16) = 0;
                        *(short *) (base + 0x1c00 + 0x18) = 0;
                        func_ov002_02161cf0(base);
                        *(int *) (base + 0x1000 + 0xbc8) = 1;
                        *(int *) (base + 0x1000 + 0xbc0) = 0;
                    }
                    if (*(int *) (base + 0x1000 + 0xbbc) == 0x24) {
                        SetElementFieldC2((struct Struct_0205d81c *) LST(base), 0x15, 1);
                        *(int *) (base + 0x1000 + 0xbb8) = 0x24;
                        *(int *) (base + 0x1000 + 0xbc0) = 1;
                    }
                    if (*(int *) (base + 0x1000 + 0xbbc) == 0xb) {
                        func_ov002_0215b9a4(base, 0xd, 0);
                        SetElementFieldC2((struct Struct_0205d81c *) LST(base), 0xb, 1);
                        SetElementFieldC2((struct Struct_0205d81c *) LST(base), 0xd, 1);
                    }
                    break;
                }
                case 1:
                    *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
                    *(unsigned char *) (base + 0x1000 + 0xc2e) = 0;
                    CONFIRM_0216A300();
                    break;
            }
        } else if (*(void **) (base + 4) != NULL && _Z23IsFlag0x2Active020e2984v()) {
            _Z27ResetSelectionState020e25e8P11Obj020e25e8(*(struct Obj020e25e8 **) (base + 4));
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            *(unsigned char *) (base + 0x1000 + 0xc2e) = 0;
            data_ov002_0216d3ac                        = 0;
            CONFIRM_0216A300();
        } else {
            data_ov002_0216d3ac = 1;
        }
    }
}
