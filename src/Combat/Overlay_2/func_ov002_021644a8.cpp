#include <globaldefs.h>

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(Struct0205de24*, unsigned char, unsigned char);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215dae0(unsigned char *obj);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(Struct_0205c570*);
int GetFieldC54ArrayValue021573f8(void *self, int v);
struct Struct_0205d81c;
void SetElementFieldC2(Struct_0205d81c*, int, int);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
struct Struct_0205def8;
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
void * FindElementByC40205d81c(Struct_0205d81c*, int);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
extern "C" void func_ov002_02156e90(char *base);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(Obj0205dee8*, int);

extern int data_02114e30;
extern int data_02108760;

// USA: func_ov002_021644a8
extern "C" ARM void func_ov002_021644a8(char *self) {
    int phase = *(int *) (self + 0x1bc0);
    if (phase == 0) {
        *(short *) (self + 0x1bf0) = 0;
        FindAndLinkMatchingEntry0205de24((Struct0205de24*)(self + 0xec8), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215dae0((unsigned char *) self);
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        *(int *) (self + 0x247c) |= 4;
        short saved = *(short *) (self + 0x1bf0);
        *(short *) (self + 0x1bf0) = GetActiveScaledSum0205d794((Struct_0205c570*)(self + 0xec8));
        *(char *) (self + 0x1c20) = GetFieldC54ArrayValue021573f8(self, *(short *) (self + 0x1bf0));
        signed char cur = *(signed char *) (self + 0x1c20);
        *(char *) (self + 0x1c21) = cur;
        SetElementFieldC2((Struct_0205d81c*)(self + 0xec8), 0xd, 1);
        if (*(short *) (self + 0x1bf0) != 0) {
            func_ov002_0215b9a4(self, 0xd, 0);
            SetElementFlag0x20ByKey0205def8((Struct_0205def8*)(self + 0xec8), 1, 0xd);
            unsigned char *ea = (unsigned char *) FindElementByC40205d81c((Struct_0205d81c*)(self + 0xec8), 0xb);
            unsigned char *eb = (unsigned char *) FindElementByC40205d81c((Struct_0205d81c*)(self + 0xec8), 0xd);
            if (ea != 0 && eb != 0) {
                short ac = *(short *) (ea + 0xac);
                short a8 = *(short *) (ea + 0xa8);
                *(short *) (eb + 0xac) = ac + a8;
                *(short *) (eb + 0xae) = 1;
            }
        } else {
            SetElementFlag0x20ByKey0205def8((Struct_0205def8*)(self + 0xec8), 0, 0xd);
        }
        if (saved != *(short *) (self + 0x1bf0)) {
            return;
        }
        int t = TestFlag0SetAndFlag1Clear((unsigned short*)&data_02114e30, 0x601);
        int u = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0xec8), 0x14);
        int hit = (t | u) != 0;
        if (hit != 0) {
            *(char *) (self + 0x1c32) = 0;
            *(char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
            *(int *) (self + 0x247c) &= ~4;
            SetElementFieldC2((Struct_0205d81c*)(self + 0xec8), 0xb, 1);
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
            *(short *) (self + 0x1c12) = 0;
            *(short *) (self + 0x1c28) = 0x238d;
            *(short *) (self + 0x1c2a) = -1;
            *(int *) (self + 0x1bb8) = 0x26;
            *(int *) (self + 0x1bbc) = 0xb;
            *(int *) (self + 0x1bc0) = 0;
            *(char *) (self + 0x1c2e) = 1;
        } else {
            if (CheckFlagOrThreshold_02161b48(self, 1) == 0) {
                return;
            }
            func_ov002_02156e90(self);
            *(short *) (self + 0x1bf0) = -1;
            *(char *) (self + 0x1c20) = -1;
            *(char *) (self + 0x1c21) = -1;
            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), (*(int *) (self + 0x1bb8) = 4));
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8), 0);
            func_ov002_02161cf0(self);
        }
    }
}
