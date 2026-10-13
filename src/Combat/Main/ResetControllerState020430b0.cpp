#include <globaldefs.h>

#if defined(jpn)
enum { kSubobject = 0x1804, kPointer = 0x1c44, kFirst = 0x800, kSecond = 0x7e4, kFlag = 0x17e1, kIndex = 0x1708, kValue = 0x170c, kFlagA = 0x17de, kFlagB = 0x17df, kFlagC = 0x17ed };
#else
enum { kSubobject = 0x19e0, kPointer = 0x1e20, kFirst = 0x930, kSecond = 0x914, kFlag = 0x19b1, kIndex = 0x1838, kValue = 0x183c, kFlagA = 0x19ae, kFlagB = 0x19af, kFlagC = 0x19bd };
#endif

struct Struct02043110;
ARM void ClearField8ViaPointer0x440(struct Struct02043110* s);

// USA: func_020430b0
ARM void ResetControllerState020430b0(char* self) {
    ClearField8ViaPointer0x440((struct Struct02043110*)(self + kSubobject));
    *(void**)(self + kPointer) = (void*)(self + kFirst);
    ClearField8ViaPointer0x440((struct Struct02043110*)(self + kSubobject));
    *(void**)(self + kPointer) = (void*)(self + kSecond);
    *(char*)(self + kFlag) = 0;
    *(char*)(self + kFlagA) = 0;
    *(char*)(self + kFlagB) = 0;
    *(char*)(self + kFlagC) = 0;
    *(int*)(self + kIndex) = -1;
    *(int*)(self + kValue) = 0;
}
