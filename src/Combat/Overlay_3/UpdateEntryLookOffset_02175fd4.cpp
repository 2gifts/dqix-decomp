#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValueFF8_F74 = 0xf74 };
enum { kRegionValueFFE_F7A = 0xf7a };
enum { kRegionValue89C_818 = 0x818 };
enum { kRegionValueFE0_F5C = 0xf5c };
enum { kRegionValue7D8_754 = 0x754 };
#else
enum { kRegionValueFF8_F74 = 0xff8 };
enum { kRegionValueFFE_F7A = 0xffe };
enum { kRegionValue89C_818 = 0x89c };
enum { kRegionValueFE0_F5C = 0xfe0 };
enum { kRegionValue7D8_754 = 0x7d8 };
#endif


struct Obj2081;
struct Elem2081;
Elem2081* FindElementByByte0xc4(Obj2081* obj, int key);

int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);

struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);

void GetLookAndTurnOffsets020809c4(void* obj, int id, int id2, short* out1, short* out2);

struct Ctx020e263c;
void UpdateEntryStateAndPosition(struct Ctx020e263c* obj, int value);

struct WinObj020e28f0;
void SetEntryPositionFromObject(struct WinObj020e28f0* obj, short a, short b);

extern "C" void func_0205ae8c(void* obj);

// USA: func_ov003_02175fd4  (semantic: UpdateEntryLookOffset_02175fd4)
// JPN: func_ov003_02174fec
extern "C" ARM void func_ov003_02175fd4(unsigned char* self) {
    if (*(void**)(self + kRegionValueFF8_F74) == NULL) {
        return;
    }
    if (*(short*)(self + kRegionValueFFE_F7A) < 0) {
        return;
    }
    Elem2081* elem = FindElementByByte0xc4(*(Obj2081**)(self + kRegionValue89C_818), *(short*)(self + kRegionValueFFE_F7A));
    if (elem == NULL) {
        return;
    }
    if (CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem) == 0 || *(void**)(self + 0x0) == NULL) {
        return;
    }
    if (GetInnerFlagBit0020e28dc(*(Outer020e28dc**)(self + 0x0)) != 0) {
        return;
    }
    short valA, valB;
    GetLookAndTurnOffsets020809c4(*(Obj2081**)(self + kRegionValue89C_818), *(short*)(self + kRegionValueFFE_F7A), *(short*)*(void**)(self + kRegionValueFF8_F74), &valA, &valB);
    UpdateEntryStateAndPosition(*(Ctx020e263c**)(self + 0x0), *(int*)(self + kRegionValueFE0_F5C));
    valA = valA - 0x10;
    valB = valB - 3;
    SetEntryPositionFromObject(*(WinObj020e28f0**)(self + 0x0), valA, valB);
    func_0205ae8c(self + kRegionValue7D8_754);
}
