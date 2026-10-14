#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205def8;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int a, int b);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void CopyByteField0215aa5c(char *base);
void CopyByteField0215aa14(char *base);
void ResetAndRebuildEntries02160734(unsigned char *base);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215f3a0(void *base);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

static inline int AnyConfirm021696c0(char *base) {
    int a = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
    int b = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(base + 0x2c8 + 0xc00), 0x14);
    return (a | b) ? 1 : 0;
}

// USA: func_ov002_021696c0
extern "C" ARM void func_ov002_021696c0(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0, 1);
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0, 0x29);
        func_ov002_02156e90(base);
        *(int *) (base + 0x1000 + 0xbb8) = 0x21;
        *(int *) (base + 0x1000 + 0xbc0) = 0x32;
    } else if (state == 0x32) {
        CopyByteField0215aa5c(base);
        *(short *) (base + 0x1c00 + 0xa) = 0;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        ResetAndRebuildEntries02160734((unsigned char *) base);
        *(int *) (base + 0x1000 + 0xbc0) = 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1c00 + 0xa) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (AnyConfirm021696c0(base) && *(short *) (base + 0x1c00 + 0xa) == 7) {
            CopyByteField0215aa14(base);
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8) = 0x21;
            *(int *) (base + 0x1000 + 0xbc0) = 0x64;
        } else if (AnyConfirm021696c0(base)) {
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
            *(int *) (base + 0x1000 + 0xbb8) = 0x22;
            *(int *) (base + 0x1000 + 0xbc0) = 0;
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            CopyByteField0215aa14(base);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8) = 0x21;
            *(int *) (base + 0x1000 + 0xbc0) = 0x64;
        }
    } else if (state == 0x64) {
        *(short *) (base + 0x1c00 + 0xa) = 0;
        *(int *) (base + 0x1000 + 0xbb8) = 0x15;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215f3a0(base);
        *(int *) (base + 0x1000 + 0xbc0) = 1;
    }
}
