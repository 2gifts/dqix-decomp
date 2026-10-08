#include <globaldefs.h>

extern "C" short _Z8fix32sini(int x);
extern "C" short _Z8fix32cosi(int x);

struct AngleTrig0202e9a4;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0202e9a4  (semantic: SetAngleAndTrigTable0202e9a4)
extern "C" ARM void _Z28SetAngleAndTrigTable0202e9a4P17AngleTrig0202e9a4i(struct AngleTrig0202e9a4* obj, int angle) {
    *(int*)((char*)obj + 0x58) = angle;
    *(int*)((char*)obj + 0x5c) = _Z8fix32sini((int)(((long long)angle * 0x47 + 0x800) >> 12));
    *(int*)((char*)obj + 0x60) = _Z8fix32cosi((int)(((long long)angle * 0x47 + 0x800) >> 12));
}