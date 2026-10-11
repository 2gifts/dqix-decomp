#include <globaldefs.h>

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
    *(unsigned char*)(obj + 0x19cc) = 0;
    *(int*)(obj + 0x9b4) = 0;

    for (int i = 0; i < 0x80; i++) {
        Forward020416c0((struct State0204166c*)(obj + 0x9b8 + i * 0x1c));
        *(unsigned char*)(obj + i + 0x17b8) = 0;
    }

    func_02043124(obj);
    ClearField8ViaPointer0x440((struct Struct02043110*)(obj + 0x19e0));
    *(int*)(obj + 0x1e20) = (int)(obj + 0x930);
    ClearField8ViaPointer0x440((struct Struct02043110*)(obj + 0x19e0));
    *(int*)(obj + 0x1e20) = (int)(obj + 0x914);
    *(unsigned char*)(obj + 0x19b1) = 0;
    *(int*)(obj + 0x1838) = -1;
    *(int*)(obj + 0x183c) = 0;
}
