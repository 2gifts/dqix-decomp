#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue89C_818 = 0x818 };
enum { kRegionValueFFE_F7A = 0xf7a };
enum { kRegionValue8A0_81C = 0x81c };
#else
enum { kRegionValue89C_818 = 0x89c };
enum { kRegionValueFFE_F7A = 0xffe };
enum { kRegionValue8A0_81C = 0x8a0 };
#endif


struct Outer020e28dc;
struct Obj2081;

extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
int IsFlag0x2Active020e2984(void);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
int IsPointInsideElement02080d54(struct Obj2081* obj, int key, int px, int py);

struct Ctx021766e8 {
    struct Outer020e28dc* ptr0;   // 0x0
    char pad0[kRegionValue89C_818 - 0x4];
    struct Obj2081* field89c;     // kRegionValue89C_818
    char pad1[kRegionValueFFE_F7A - kRegionValue8A0_81C];
    short keyffe;                 // kRegionValueFFE_F7A
};

// USA: func_ov003_021766e8  (semantic: CheckStateAtCoords_021766e8)
// JPN: func_ov003_02175730
extern "C" ARM int func_ov003_021766e8(struct Ctx021766e8* self) {
    int flag = 0;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) flag = 1;

    if (self->ptr0 != NULL && GetInnerFlagBit0020e28dc(self->ptr0)) {
        (void)*(struct Outer020e28dc* volatile*)&self->ptr0;
        if (IsFlag0x2Active020e2984()) {
            flag = 1;
        }
    } else if (*((unsigned char*)&data_02114e54 + 0x55) != 0) {
        int a, b;
        SelectCoordsByFlag0x24(&data_02114e54, &a, &b);
        if (!IsPointInsideElement02080d54(self->field89c, self->keyffe, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}
