#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

#if defined(jpn)
enum { ControllerOffset = 0x1804, RectanglePointerOffset = 0x1c44,
       FirstRectangleOffset = 0x800, SecondRectangleOffset = 0x7e4 };
#else
enum { ControllerOffset = 0x19e0, RectanglePointerOffset = 0x1e20,
       FirstRectangleOffset = 0x930, SecondRectangleOffset = 0x914 };
#endif

struct Struct02043110;
void ClearField8ViaPointer0x440(Struct02043110* controller);

// USA: func_020430b0
ARM void ResetControllerState020430b0(MessageSystem* window) {
    char* storage = (char*)window;
    ClearField8ViaPointer0x440((Struct02043110*)(storage + ControllerOffset));
    *(void**)(storage + RectanglePointerOffset) = storage + FirstRectangleOffset;
    ClearField8ViaPointer0x440((Struct02043110*)(storage + ControllerOffset));
    *(void**)(storage + RectanglePointerOffset) = storage + SecondRectangleOffset;
    window->b19b1 = 0;
    window->b19ae = 0;
    window->b19af = 0;
    window->b19bd = 0;
    window->selectedEntry = -1;
    window->selectedValue = 0;
}
