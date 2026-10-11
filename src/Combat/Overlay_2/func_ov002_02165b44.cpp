#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "System/Matrix.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205d81c;
struct Obj0205dee8;
struct List020a83b0;
struct Obj02048350;
struct TE5b44 {
    char *name;
    int unk4;
    unsigned int lo8 : 8;
    unsigned int b8 : 2;
    unsigned int b10 : 2;
    unsigned int rest : 20;
};
struct TailList020469b4;
struct TailNode020469b4;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow, unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38 *o);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8 *o, int v);
void ClearMatchingEntry_02156ff0(unsigned char *self, int v);
int GetField0x397cValue(GameState *gs);
GameObject *GetCombatantChecked(GameState *gs, int id);
int TestBitInByteArray(int unused, unsigned char *arr, int index);
char *FindEntryByByteId020a83b0(struct List020a83b0 *l, int id);
char *GetData02108e10();
char *SearchBothTables02079e2c(char *t, int id);
void ConsumeCounter02048350(struct Obj02048350 *o, int n);
int CheckField0NonZero(int *p);
void *GetField0x3f8Address(GameState *state);
extern "C" void VectorizedMemset(void *dst, int value, unsigned int length);
extern "C" void *_Z28CallFunc0200fbb4AtField0x3f8Pv(void *obj, const void *src);
void InitAndInsertNode_021acd30(char *g, unsigned char a, unsigned char b, unsigned char c);
void InitAndResetHeader_0219e310(unsigned char *p, int v);
void AppendNodeToTail(struct TailList020469b4 *l, struct TailNode020469b4 *n);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215f170(char *base);
extern "C" void func_ov002_02161b98(char *base);
extern "C" void func_ov002_0215a7b4(char *base, int a, short b, int c, int d);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" char *func_0205ec34(void);
extern "C" char *func_02012fe4(void);
extern "C" int *func_0202ae18(void);
extern "C" int func_0202c508(int *p);
extern "C" void func_ov023_021dca88(char *obj);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

// USA: func_ov002_02165b44
extern "C" ARM void func_ov002_02165b44(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1b00 + 0xfc) = 0;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215f170(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        func_ov002_02161b98(base);
        *(short *) (base + 0x1b00 + 0xfc) = GetActiveScaledSum0205d794((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        int ta                            = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int tb = ((int (*)(void *, int)) IsActiveElementFlag2Set0205da38)(base + 0x2c8 + 0xc00, 0x14);
        if ((ta | tb) ? 1 : 0) {
            GameState *gs = GameState::GetInstance();
            int id        = *(signed char *) (base + 0x1c00 + 0x20);
            if (id == 4) id = GetField0x397cValue(gs);
            GameObject *m = GetCombatantChecked(gs, id);
            if (m == NULL) return;
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            if (**(int **) ((char *) m + 0x130) & 1) {
                *(short *) (base + 0x1c00 + 0x28) = -1;
                *(short *) (base + 0x1c00 + 0x2a) = -1;
                *(int *) (base + 0x1000 + 0xbb8)  = 0x11;
                return;
            }
            *(int *) (base + 0x1000 + 0xbc0) = 0;
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
            int save    = (int) func_0205ec34();
            char *world = func_02012fe4();
            int kind    = 0;
            if (!TestBitInByteArray(save, (unsigned char *) ((char *) save + 0x8c), 0x113a)) {
                char *p = *(char **) (world + 8);
                if (p != NULL) kind = (unsigned int) (*(unsigned char *) (p + 0xe) << 30) >> 30;
            }
            *(short *) (base + 0x1c00 + 0x28) = 0x232d;
            if (kind == 2) {
                char *e = FindEntryByByteId020a83b0(*(struct List020a83b0 **) (base + 0x2000 + 0x474),
                                                    *(short *) (base + 0x1b00 + 0xfc));
                if (e != NULL) {
                    int *rec                          = func_0202ae18();
                    *(short *) (base + 0x1c00 + 0x2a) = -1;
                    *(int *) (base + 0x1000 + 0xbb8)  = 0x26;
                    *(int *) (base + 0x1000 + 0xbbc)  = 0x2b;
                    if (*(short *) (base + 0x1c00 + 0x22) == 0x5603) {
                        *(short *) (base + 0x1c00 + 0x28)          = 0x7972;
                        *(short *) (base + 0x1c00 + 0x2a)          = -1;
                        *(short *) (base + 0x2400 + 0x88)          = -1;
                        *(unsigned char *) (base + 0x2000 + 0x48a) = 0;
                        if (*(unsigned int *) (base + 0x2000 + 0x47c) & 1) func_ov023_021dca88(base + 0x50);
                        func_ov002_0215a7b4(base, *(signed char *) (base + 0x1c00 + 0x20), *(short *) (base + 0x1c00 + 0x22),
                                            *(short *) (base + 0x1b00 + 0xe8), 0);
                    } else {
                        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 0x64, 0);
                        char *t = SearchBothTables02079e2c(GetData02108e10(), 0xca);
                        ConsumeCounter02048350(
                            (struct Obj02048350 *) GetCombatantChecked(gs, *(signed char *) (base + 0x1c00 + 0x20)),
                            ((struct TE5b44 *) t)->lo8);
                        if (CheckField0NonZero(rec)) func_ov017_021c9e00(*(signed char *) (base + 0x1c00 + 0x20), 0, 0, 1);
                    }
                    unsigned char *q = (unsigned char *) GetField0x3f8Address(gs);
                    VectorizedMemset(q, 0, 0x70);
                    q[4]                       = 1;
                    q[8]                       = 1;
                    q[9]                       = 1;
                    *(signed char *) (q + 0xb) = -1;
                    *(int *) (q + 0x20)        = -1;
                    *(int *) (q + 0x24)        = -1;
                    *(int *) (q + 0x28)        = -1;
                    *(int *) (q + 0x2c)        = -1;
                    *(short *) (q + 0x1e)      = -1;
                    q[0xc]                     = 0;
                    *(short *) (q + 0x6c)      = -1;
                    q[2]                       = 0;
                    q[4]                       = 0;
                    q[5]                       = 1;
                    *(unsigned short *) q      = *(unsigned short *) (e + 8);
                    *(Vector3i *) (q + 0x10)   = *(Vector3i *) (e + 0xc);
                    *(short *) (q + 0x1c)      = *(short *) (e + 0xa);
                    q[7]                       = 1;
                    q[0x63]                    = 0;
                    _Z28CallFunc0200fbb4AtField0x3f8Pv(gs, q);
                    if (func_0202c508(rec) && TestBitInByteArray(save, (unsigned char *) ((char *) save + 0x8c), 0x2b)) {
                        *(unsigned short *) (world + 0x2700 + 0x86) = *(unsigned short *) (e + 0x1a);
                        *(unsigned short *) (world + 0x2700 + 0x84) = *(unsigned short *) (e + 0x1c);
                        Vector3i *pos                               = (Vector3i *) (world + 0x374 + 0x2400);
                        Vector3i v                                  = *pos;
                        v.x                                         = *(int *) (e + 0x20);
                        v.z                                         = *(int *) (e + 0x24);
                        *pos                                        = v;
                        func_ov017_021d1a18(*(short *) (e + 0x1a), *(short *) (e + 0x1c), 0, 0);
                    }
                    char *g = (char *) func_ov017_0218b5b0();
                    InitAndInsertNode_021acd30(g, 0, 0, 0);
                    struct TailList020469b4 *tl;
                    unsigned char *node = *(unsigned char **) (g + 0x3000 + 0x70c);
                    tl                  = *(struct TailList020469b4 **) (g + 0x3000 + 0x6fc);
                    InitAndResetHeader_0219e310(node, 0);
                    AppendNodeToTail(tl, (struct TailNode020469b4 *) node);
                    return;
                }
                kind = 0;
            } else if (kind == 1) {
                *(short *) (base + 0x1c00 + 0x2a) = -1;
                *(int *) (base + 0x1000 + 0xbb8)  = 0x26;
                *(int *) (base + 0x1000 + 0xbbc)  = 0x2b;
                if (*(short *) (base + 0x1c00 + 0x22) == 0x5603) {
                    *(short *) (base + 0x1c00 + 0x28)          = 0x7972;
                    *(short *) (base + 0x1c00 + 0x2a)          = -1;
                    *(short *) (base + 0x2400 + 0x88)          = -1;
                    *(unsigned char *) (base + 0x2000 + 0x48a) = 0;
                    if (*(unsigned int *) (base + 0x2000 + 0x47c) & 1) func_ov023_021dca88(base + 0x50);
                } else {
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 0x64, 0);
                }
                InitAndInsertNode_021acd30((char *) func_ov017_0218b5b0(), 0, 0, 1);
                return;
            }
            if (kind == 0) {
                if (*(short *) (base + 0x1c00 + 0x22) == 0x5603) {
                    *(short *) (base + 0x1b00 + 0xfc)          = -1;
                    *(short *) (base + 0x1c00 + 0x28)          = 0x7936;
                    *(short *) (base + 0x1c00 + 0x2a)          = -1;
                    *(short *) (base + 0x2400 + 0x88)          = 0x7919;
                    *(unsigned char *) (base + 0x2000 + 0x48a) = 1;
                    *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
                    *(int *) (base + 0x1000 + 0xbbc)           = 5;
                } else {
                    *(short *) (base + 0x2400 + 0x88)          = 0x2338;
                    *(unsigned char *) (base + 0x2000 + 0x48a) = 1;
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 0x64, 0);
                    *(int *) (base + 0x1000 + 0xbb8) = 0x26;
                    *(int *) (base + 0x1000 + 0xbbc) = 0x11;
                }
            }
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            *(short *) (base + 0x1b00 + 0xfc) = -1;
            if (*(short *) (base + 0x1c00 + 0x22) == 0x5603) {
                *(short *) (base + 0x1c00 + 0x22) = -1;
                ClearMatchingEntry_02156ff0((unsigned char *) base, 5);
            } else {
                *(short *) (base + 0x1c00 + 0x26) = -1;
                ClearMatchingEntry_02156ff0((unsigned char *) base, 0x13);
                *(int *) (base + 0x1000 + 0xbb8) = 0x11;
                SetFieldB0AndUpdate0205dee8((struct Obj0205dee8 *) (base + 0x2c8 + 0xc00), 0x11);
                SetElementFieldC2((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0x11, 0);
                func_ov002_02161cf0(base);
                func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8) & 0xff, 0);
                *(int *) (base + 0x1000 + 0xbc0) = 1;
            }
        }
    }
}
