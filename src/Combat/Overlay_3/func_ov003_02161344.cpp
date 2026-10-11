#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue470_298 = 0x298 };
enum { kRegionValue49C_2C4 = 0x2c4 };
enum { kRegionValue324_20C = 0x20c };
enum { kRegionValue488_2B0 = 0x2b0 };
enum { kRegionValue308_1F0 = 0x1f0 };
enum { kRegionValue390_278 = 0x278 };
#else
enum { kRegionValue470_298 = 0x470 };
enum { kRegionValue49C_2C4 = 0x49c };
enum { kRegionValue324_20C = 0x324 };
enum { kRegionValue488_2B0 = 0x488 };
enum { kRegionValue308_1F0 = 0x308 };
enum { kRegionValue390_278 = 0x390 };
#endif


struct IntField0x23c_020a27c4;
int GetFieldIfFlag4(char* obj);
int GetIntAt0x23c(struct IntField0x23c_020a27c4* obj);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_ov003_02160854(void* obj);

struct Ctx02160a68;
extern "C" int func_ov003_02160a68(struct Ctx02160a68* self);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

struct Obj2081;
void CallFunc0204c804OnMatchingKey(struct Obj2081* obj, int key);

struct Obj0208203c;
void ResetWithSub0208203c(struct Obj0208203c* obj);

struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8* obj);

extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov003_02161344
// JPN: func_ov003_02161430
extern "C" ARM int func_ov003_02161344(char* obj) {
    *(void**)(obj + kRegionValue470_298) = obj + kRegionValue49C_2C4;
    int result = 0;
    int flagB = result;

    GameState* battle = GameState::GetInstance();
    struct IntField0x23c_020a27c4* p = (struct IntField0x23c_020a27c4*)GetFieldIfFlag4((char*)battle);
    if (p != 0 && ((*((unsigned char*)p + 0x244) & 2) != 0 || GetIntAt0x23c(p) == 0)) {
        flagB = (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x200) != 0) ? 1 : 0;
    }

    if (func_ov003_02160854(obj) != 0 || flagB != 0) {
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        result = -1;
        if (*(short*)(obj + kRegionValue49C_2C4) == 0x2c) {
            result = 1;
        }
    } else {
        if (func_ov003_02160a68((struct Ctx02160a68*)obj) != 0) {
            result = -1;
        }
    }

    if (result != 0) {
        CallFunc0204c804OnMatchingKey(*(struct Obj2081**)(obj + kRegionValue324_20C), *(short*)(obj + kRegionValue488_2B0));
        ResetWithSub0208203c((struct Obj0208203c*)(obj + kRegionValue308_1F0));
        *(void**)(obj + kRegionValue470_298) = 0;
    }

    if (*(void**)(obj + kRegionValue390_278) != 0 && result != 0) {
        ResetSelectionState020e25e8(*(struct Obj020e25e8**)(obj + kRegionValue390_278));
    }

    return result;
}
