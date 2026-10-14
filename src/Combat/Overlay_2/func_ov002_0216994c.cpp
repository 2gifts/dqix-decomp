#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Obj0205eaa0;
struct StructA0205d5d0;

int GetIndexedOffsetByte7c_0215a9f0(void *self);
extern "C" char *func_0205ec34();
short FindShortIndex0206e3e8(int unused, int key);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
void InitBattleTag021609d4(char *self);
extern "C" void func_ov002_02161b98(char *self);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
extern "C" void func_ov002_0215bba8(char *self);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short *pad, int buttons);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
int NextIndexOrZero_0215a9b4(void *self, short idx);
int GetShortFromTable0206e3d4(int a, int b);
char *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *obj, int a, int b);
void SetFieldByIndexedOffsetC7c_0215a9cc(void *self, int idx);
char *GetGlobalField0x1c020421a0();
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void func_ov002_021607cc(void *obj, void *ptr, int flag);
int TryApplyElemFields0205d5d0(struct StructA0205d5d0 *, int, int, int, unsigned char);
extern "C" void func_ov002_02156e90(void *obj);
int CheckFlagOrThreshold_02161b48(char *self, int v);

extern "C" unsigned short data_02114e30;
extern "C" char data_02108760;

struct Fld0216994c {
    char pad[0x68];
    int f68;
};

// USA: func_ov002_0216994c
extern "C" ARM void func_ov002_0216994c(char *self) {
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        *(unsigned int *) (self + 0x247c) &= ~4;
        int key                    = GetIndexedOffsetByte7c_0215a9f0(self);
        *(short *) (self + 0x1c0c) = FindShortIndex0206e3e8((int) func_0205ec34(), key) - 1;
        if (*(short *) (self + 0x1c0c) < 0) {
            *(short *) (self + 0x1c0c) = 0;
        }
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (self + 0x2c8 + 0xc00), 0, 3);
        func_ov002_02161cf0(self);
        InitBattleTag021609d4(self);
        *(int *) (self + 0x1bc0) += 1;
        return;
    }
    if (state != 1) {
        return;
    }
    *(unsigned int *) (self + 0x247c) |= 4;
    func_ov002_02161b98(self);
    *(short *) (self + 0x1c0c) =
        GetActiveScaledSum0205d794((struct Struct_0205c570 *) (self + 0x2c8 + 0xc00));
    struct Fld0216994c *l = (struct Fld0216994c *) (self + 0x2c8 + 0xc00) + 1;
    l--;
    int f = l->f68;
    if (*(unsigned char *) (self + 0x2484) != f) {
        func_ov002_0215bba8(self);
    }
    int a  = TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x601);
    int b  = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0x2c8 + 0xc00), 0x14);
    int ok = (a | b) ? 1 : 0;
    if (ok) {
        int next = NextIndexOrZero_0215a9b4(self, *(short *) (self + 0x1c0c));
        int idx  = GetShortFromTable0206e3d4((int) func_0205ec34(), next);
        int one  = 1;
        int en   = one;
        if (idx >= 0 && *(short *) (self + 0x1c0c) != 0x1f) {
            en = 0;
            if (*(unsigned int *) (self + 0x2480) & (one << (idx - 1))) {
                en = one;
            }
        }
        if (!en) {
            return;
        }
        *(unsigned int *) (self + 0x247c) &= ~4;
        unsigned char *elem = (unsigned char *) FindElementByC40205d81c(
            (struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 0x21);
        if (elem == 0) {
            return;
        }
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
        SetFieldByIndexedOffsetC7c_0215a9cc(self, idx);
        void *buf = *(void **) (GetGlobalField0x1c020421a0() + 0x5c);
        memset(buf, 0, 0x960);
        func_ov002_021607cc(self, buf, (elem[0xc5] & 2) ? 1 : 0);
        TryApplyElemFields0205d5d0((struct StructA0205d5d0 *) (self + 0x2c8 + 0xc00), 0x21,
                                                             (int) buf, 1, 0);
        func_ov002_02156e90(self);
        return;
    }
    if (CheckFlagOrThreshold_02161b48(self, 1)) {
        *(unsigned int *) (self + 0x247c) &= ~4;
        *(short *) (self + 0x1c0c) = 0;
        func_ov002_02156e90(self);
    }
}
