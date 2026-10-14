#include <globaldefs.h>

short fix32sin(int x);
short fix32cos(int x);

struct AngleTrig0202e9a4;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0202e9a4  (semantic: SetAngleAndTrigTable0202e9a4)
ARM void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4* obj, int angle) {
    *(int*)((char*)obj + 0x58) = angle;
    *(int*)((char*)obj + 0x5c) = fix32sin((int)(((long long)angle * 0x47 + 0x800) >> 12));
    *(int*)((char*)obj + 0x60) = fix32cos((int)(((long long)angle * 0x47 + 0x800) >> 12));
}
