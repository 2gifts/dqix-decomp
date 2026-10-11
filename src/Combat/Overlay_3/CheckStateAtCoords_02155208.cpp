#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue1E6_1E2 = 0x1e2 };
#else
enum { kRegionValue1E6_1E2 = 0x1e6 };
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

struct Ctx02155208 {
    char pad0[0x18];
    struct Obj2081* field18;      // 0x18
    struct Outer020e28dc* ptr1c;  // 0x1c
    char pad1[kRegionValue1E6_1E2 - 0x20];
    short key1e6;                 // kRegionValue1E6_1E2
};

// USA: func_ov003_02155208  (semantic: CheckStateAtCoords_02155208)
// JPN: func_ov003_021568f0
extern "C" ARM int func_ov003_02155208(struct Ctx02155208* self) {
    int flag = 0;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) flag = 1;

    if (self->ptr1c != NULL && GetInnerFlagBit0020e28dc(self->ptr1c)) {
        (void)*(struct Outer020e28dc* volatile*)&self->ptr1c;
        if (IsFlag0x2Active020e2984()) {
            flag = 1;
        }
    } else if (*((unsigned char*)&data_02114e54 + 0x55) != 0) {
        int a, b;
        SelectCoordsByFlag0x24(&data_02114e54, &a, &b);
        if (!IsPointInsideElement02080d54(self->field18, self->key1e6, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}
