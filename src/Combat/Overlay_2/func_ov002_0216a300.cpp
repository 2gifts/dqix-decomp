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
int GetGlobalField0x1c020421a0(void);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_02160fb4(char *base);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *o, int a, int b);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
char *GetField4Ptr020e1b24(void *p);
void ResetAndReposition020e280c(struct Obj020e280c *self, void *b);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
char *GetFieldIfFlag4(char *obj);
int GetIntAt0x23c(struct IntField0x23c_020a27c4 *obj);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
int GetField0x15UnlessInactive(signed char *param);
int GetSignedByteAt0x14(signed char *p);
void ResetSelectionState020e25e8(struct Obj020e25e8 *obj);
char *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
void ResetEntryList0205d6a0(struct Entry_0205d6a0 *a, int flag);
extern "C" void func_ov017_0219577c(int a, int b, int c);
extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" void func_ov002_0216bfd4(char *self, int a);
void EnqueueEventTag170_021d0198(int a, int b, int c, int d);
int CheckStateAndGetCode0215753c(unsigned char *p);
extern "C" void func_ov002_02156e90(void *base);
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
void ReinitController02043204(char *obj);
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8 *o, int v);
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc *s, int index);
extern "C" void func_0205bb04(void *s, int n);
int IsFlag0x2Active020e2984(struct Outer020e28dc* window);
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
        char *e = FindElementByKey020dedd0((struct Container020dedd0 *) (base + 0x3ec + 0x400), \
                                                                    *(short *) (base + 0x1c00 + 0x22)); \
        if (e != NULL && *(short *) (e + 0x18) == 0x5612) { \
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 1); \
            ResetEntryList0205d6a0((struct Entry_0205d6a0 *) LST(base), 0); \
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
            ResetEntryList0205d6a0((struct Entry_0205d6a0 *) LST(base), 0); \
            switch (*(unsigned char *) (base + 0x1000 + 0xc79)) { \
                case 0: func_ov002_0216bfd4(base, 4); return; \
                case 3: func_ov002_0216bfd4(base, 2); return; \
            } \
            return; \
        } \
        func_ov002_02156e90(base); \
        ReinitController02043204(g); \
        if (*(unsigned char *) (base + 0x2000 + 0x521) != 0) { \
            *(int *) (base + 0x1000 + 0xbb8) = *(int *) (base + 0x1000 + 0xbbc); \
            SetFieldB0AndUpdate0205dee8((struct Obj0205dee8 *) LST(base), 4); \
            SetElementFieldC2((struct Struct_0205d81c *) LST(base), 4, 0); \
            func_ov002_02161cf0(base); \
            *(unsigned char *) (base + 0x2000 + 0x521) = 0; \
        } else if ((*(short *) (base + 0x1b00 + 0xf0) >= 0 || *(short *) (base + 0x1b00 + 0xe8) >= 0 || \
                    *(short *) (base + 0x1c00 + 0xa) >= 0) && \
                   *(short *) (base + 0x1c00 + 0xa) != 0) \
        { \
            int n_   = (*(short *) (base + 0x1c00 + 0xa) = 7); \
            char *l_ = LST(base); \
            SetIndexIfValid0205bcdc((struct Struct_0205bcdc *) (l_ + 4), n_); \
            func_0205bb04(l_ + 0x54, n_); \
            func_ov002_0215b9a4(base, 0x21, 0); \
        } \
        if (*(int *) (base + 0x1000 + 0xbbc) == 0xb) { \
            *(int *) (base + 0x1000 + 0xbb8) = 0xb; \
            func_ov002_0215b9a4(base, 0xb, 0); \
            SetFieldB0AndUpdate0205dee8((struct Obj0205dee8 *) LST(base), 0xb); \
            SetElementFieldC2((struct Struct_0205d81c *) LST(base), 0xb, 0); \
            SetElementFieldC2((struct Struct_0205d81c *) LST(base), 0xd, 1); \
            func_ov002_02161cf0(base); \
        } \
    } while (0)

// USA: func_ov002_0216a300
extern "C" ARM void func_ov002_0216a300(char *base) {
    char *g                                 = (char *) GetGlobalField0x1c020421a0();
    *(unsigned char *) (g + 0x1000 + 0x9ae) = 0;
    int state                               = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) LST(base), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_02160fb4(base);
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 5, 0);
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) LST(base), 0, 0x25);
        char *p = GetField4Ptr020e1b24(*(void **) (*(char **) base + 0x10));
        if (((struct Bits0216a300 *) p)->b0) {
            ResetAndReposition020e280c(*(struct Obj020e280c **) (base + 4), *(void **) (p + 0x30));
        } else {
            ResetAndReposition020e280c(*(struct Obj020e280c **) (base + 4), (void *) -1);
        }
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) LST(base), 0, 0x25);
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1c00 + 0x12) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) LST(base));
        int ok  = 0;
        char *f = GetFieldIfFlag4((char *) GameState::GetInstance());
        if (f != NULL && ((*(unsigned char *) (f + 0x244) & 2) || GetIntAt0x23c((struct IntField0x23c_020a27c4 *) f) == 0)) {
            ok = TestFlag0SetAndFlag1Clear(data_02114e30, 0x200) ? 1 : 0;
        }
        *(short *) (base + 0x1c00 + 0x12) = GetField0x15UnlessInactive(*(signed char **) (base + 4));
        if (*(short *) (base + 0x1c00 + 0x12) >= 0 || ok) {
            *(short *) (base + 0x1c00 + 0x12) = GetSignedByteAt0x14(*(signed char **) (base + 4));
            ResetSelectionState020e25e8(*(struct Obj020e25e8 **) (base + 4));
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
            data_ov002_0216d3ac = 0;
            switch (*(short *) (base + 0x1c00 + 0x12)) {
                case 0: {
                    *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
                    *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
                    char *e                           = FindElementByKey020dedd0(
                        (struct Container020dedd0 *) (base + 0x3ec + 0x400), *(short *) (base + 0x1c00 + 0x22));
                    if (e != NULL && *(short *) (e + 0x18) == 0x5612) {
                        func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 1);
                        ResetEntryList0205d6a0((struct Entry_0205d6a0 *) LST(base), 0);
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
                        ResetEntryList0205d6a0((struct Entry_0205d6a0 *) LST(base), 0);
                        switch (*(unsigned char *) (base + 0x1000 + 0xc79)) {
                            case 0: {
                                char *m = (char *)GetCombatantWithFlag0x100(GameState::GetInstance(), *(signed char *) (base + 0x1c00 + 0x21));
                                int go  = 1;
                                if (m != NULL && *(unsigned short *) (*(char **) (m + 0x130) + 4) == 0) go = 0;
                                if (!func_020dc920(*(unsigned char *) (base + 0x1000 + 0xc21), 1, 0, 0)) go = 0;
                                if (go) {
                                    func_ov002_0216bfd4(base, 1);
                                    EnqueueEventTag170_021d0198(1, *(signed char *) (base + 0x1c00 + 0x20),
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
                                EnqueueEventTag170_021d0198(2, *(signed char *) (base + 0x1c00 + 0x20),
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
                    *(short *) (base + 0x1c00 + 0x28)          = CheckStateAndGetCode0215753c((unsigned char *) base);
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
                        ResetEntryList0205d6a0((struct Entry_0205d6a0 *) LST(base), 0);
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
        } else if (*(struct Outer020e28dc **) (base + 4) != NULL && IsFlag0x2Active020e2984(*(struct Outer020e28dc **) (base + 4))) {
            ResetSelectionState020e25e8(*(struct Obj020e25e8 **) (base + 4));
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            *(unsigned char *) (base + 0x1000 + 0xc2e) = 0;
            data_ov002_0216d3ac                        = 0;
            CONFIRM_0216A300();
        } else {
            data_ov002_0216d3ac = 1;
        }
    }
}
