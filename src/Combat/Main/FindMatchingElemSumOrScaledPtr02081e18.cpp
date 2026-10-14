#include <globaldefs.h>

int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char* window);
struct ScaledElementList0204aa28;
unsigned int GetScaledElementPtr(ScaledElementList0204aa28* layout);

struct WindowVramLayout {
    char unknown0[0x1c];
    unsigned char transferKind : 4;
    unsigned char bgLayer : 4;
};

struct WindowAllocation {
    char unknown0[4];
    WindowVramLayout* layout;
    char unknown8[0xa0 - 8];
    unsigned int destinationOffset;
    unsigned int pixelBytes;
    char unknownA8[0xe0 - 0xa8];
};

struct Obj02081e18 {
#if defined(jpn)
    char unknown0[0x20];
#else
    char unknown0[0x2c];
#endif
    int unknown2c;
    WindowAllocation* windows;
    char unknown34[5];
    unsigned char windowCount;
};

ARM unsigned int FindMatchingElemSumOrScaledPtr02081e18(Obj02081e18* menu, int bgLayer) {
    if (menu->unknown2c == 0 || menu->windows == 0) return 0;
    WindowAllocation* window;
    int i;
    for (i = (int)menu->windowCount - 1; i >= 0; i--) {
        window = &menu->windows[i];
        if (CheckField0x9cSetWhenField0xd4Present_0204c7e0(reinterpret_cast<unsigned char*>(window)) && window->layout) {
            WindowVramLayout* layout = window->layout;
            if (bgLayer == layout->bgLayer) {
                return window->destinationOffset + window->pixelBytes;
            }
        }
    }
    return GetScaledElementPtr(reinterpret_cast<ScaledElementList0204aa28*>(menu->windows->layout));
}
