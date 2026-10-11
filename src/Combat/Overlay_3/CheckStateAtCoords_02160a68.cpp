#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue324_20C = 0x20c };
enum { kRegionValue390_278 = 0x278 };
enum { kRegionValue328_210 = 0x210 };
enum { kRegionValue488_2B0 = 0x2b0 };
enum { kRegionValue394_27C = 0x27c };
#else
enum { kRegionValue324_20C = 0x324 };
enum { kRegionValue390_278 = 0x390 };
enum { kRegionValue328_210 = 0x328 };
enum { kRegionValue488_2B0 = 0x488 };
enum { kRegionValue394_27C = 0x394 };
#endif


int GetWord0x0(int* obj);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
int IsFieldNotPositive_021a4e70(unsigned char* base);

struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
int IsFlag0x2Active020e2984(void);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);

struct Obj2081;
int IsPointInsideElement02080d54(struct Obj2081* obj, int key, int px, int py);

extern unsigned short data_02114e30;
extern unsigned char data_02114e54;

struct Ctx02160a68 {
    char pad0[kRegionValue324_20C];
    struct Obj2081* field324;      // kRegionValue324_20C
    char pad1[kRegionValue390_278 - kRegionValue328_210];
    struct Outer020e28dc* ptr390;  // kRegionValue390_278
    char pad2[kRegionValue488_2B0 - kRegionValue394_27C];
    short key488;                  // kRegionValue488_2B0
};

// USA: func_ov003_02160a68  (semantic: CheckStateAtCoords_02160a68)
// JPN: func_ov003_02160bc4
extern "C" ARM int func_ov003_02160a68(struct Ctx02160a68* self) {
    int flag = 0;
    unsigned char* battleWord = (unsigned char*)GetWord0x0((int*)GameState::GetInstance());
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) {
        if (IsFieldNotPositive_021a4e70(battleWord)) {
            flag = 1;
        }
    }

    if (GetInnerFlagBit0020e28dc(self->ptr390)) {
        (void)*(struct Outer020e28dc* volatile*)&self->ptr390;
        if (IsFlag0x2Active020e2984()) {
            flag = 1;
        }
    } else if (*((unsigned char*)&data_02114e54 + 0x55) != 0) {
        int a, b;
        SelectCoordsByFlag0x24(&data_02114e54, &a, &b);
        if (!IsPointInsideElement02080d54(self->field324, self->key488, (short)a, (short)b)) {
            flag = 1;
        }
    }
    return flag;
}
