#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue1002_F7E = 0xf7e };
enum { kRegionValueFFE_F7A = 0xf7a };
enum { kRegionValue89C_818 = 0x818 };
enum { kRegionValue88C_808 = 0x808 };
enum { kRegionValueFF8_F74 = 0xf74 };
#else
enum { kRegionValue1002_F7E = 0x1002 };
enum { kRegionValueFFE_F7A = 0xffe };
enum { kRegionValue89C_818 = 0x89c };
enum { kRegionValue88C_808 = 0x88c };
enum { kRegionValueFF8_F74 = 0xff8 };
#endif


extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);

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

// USA: func_ov003_021764f4  (semantic: RunTurnCheck_021764f4)
// JPN: func_ov003_02175544
extern "C" ARM int func_ov003_021764f4(unsigned char* self) {
#if defined(jpn)
    *(void**)(self + 0xf74) = self + 0xf7e;
#else
    *(void**)(self + 0xff8) = self + 0x2 + 0x1000;
#endif
    int result = 0;
    if (func_ov003_021765b4(self) != 0) {
        goto dispatch;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x200) == 0) {
        goto alt;
    }
dispatch:
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    result = -1;
    if (*(short*)(self + kRegionValue1002_F7E) == 2) {
        result = 1;
    }
    goto merge;
alt:
    if (func_ov003_021766e8(self) != 0) {
        result = -1;
    }
merge:
    if (result != 0) {
        short key = *(short*)(self + kRegionValueFFE_F7A);
        CallFunc0204c804OnMatchingKey(*(struct Obj2081**)(self + kRegionValue89C_818), key);
        ResetWithSub0208203c((struct Obj0208203c*)(self + kRegionValue88C_808));
        *(void**)(self + kRegionValueFF8_F74) = 0;
    }
    if (*(void**)self != 0 && result != 0) {
        ResetSelectionState020e25e8(*(struct Obj020e25e8**)self);
    }
    return result;
}
