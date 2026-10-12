#include <globaldefs.h>

#if defined(jpn)
enum { kSubobject = 0x1804, kPointer = 0x1c44, kFirst = 0x800, kSecond = 0x7e4, kFlag = 0x17e1, kIndex = 0x1708, kValue = 0x170c, kResetFlag = 0x17fd, kCount = 0x884, kEntries = 0x888, kFlags = 0x1688, kFirstEntry = 14 };
#else
enum { kSubobject = 0x19e0, kPointer = 0x1e20, kFirst = 0x930, kSecond = 0x914, kFlag = 0x19b1, kIndex = 0x1838, kValue = 0x183c, kResetFlag = 0x19cc, kCount = 0x9b4, kEntries = 0x9b8, kFlags = 0x17b8, kFirstEntry = 0 };
#endif
#if defined(jpn)
#define Forward020416c0 func_02041bbc
extern "C" void func_02041bbc(struct State0204166c* s);
#endif


#if defined(jpn)
#define func_02043224 func_02043998
#endif

struct State0204166c;
void Forward020416c0(struct State0204166c* s);

extern "C" void func_02043124(void* obj);

struct Struct02043110;
void ClearField8ViaPointer0x440(struct Struct02043110* s);

// USA: func_02043224  (semantic: ReinitCombatController_02043224)
extern "C" ARM void func_02043224(char* obj) {
    *(unsigned char*)(obj + kResetFlag) = 0;
    *(int*)(obj + kCount) = kFirstEntry;

    for (int i = kFirstEntry; i < 0x80; i++) {
        Forward020416c0((struct State0204166c*)(obj + kEntries + i * 0x1c));
        *(unsigned char*)(obj + i + kFlags) = 0;
    }

    func_02043124(obj);
    ClearField8ViaPointer0x440((struct Struct02043110*)(obj + kSubobject));
    *(int*)(obj + kPointer) = (int)(obj + kFirst);
    ClearField8ViaPointer0x440((struct Struct02043110*)(obj + kSubobject));
    *(int*)(obj + kPointer) = (int)(obj + kSecond);
    *(unsigned char*)(obj + kFlag) = 0;
    *(int*)(obj + kIndex) = -1;
    *(int*)(obj + kValue) = 0;
}
