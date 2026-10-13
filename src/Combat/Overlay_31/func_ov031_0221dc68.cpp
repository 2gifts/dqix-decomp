#include <globaldefs.h>

#if defined(jpn)
#define func_ov031_0221dcbc func_ov031_0221e49c
#define func_ov031_0221de00 func_ov031_0221e5e0
#endif

extern "C" int func_ov031_0221d384(int);
extern "C" int func_ov031_0221dcbc(int, const void*, int);
extern "C" int func_ov031_0221de00(int, const void*, int);
extern "C" int func_ov031_0221dedc(int, const void*, int);

// USA: func_ov031_0221dc68
extern "C" THUMB int func_ov031_0221dc68(int type, int first, const void* packet, int channel) {
    switch (type) {
    case 0:
        func_ov031_0221d384(2);
        return func_ov031_0221dcbc(first, packet, channel);
    case 1:
        func_ov031_0221d384(3);
        return func_ov031_0221de00(first, packet, channel);
    case 2:
        func_ov031_0221d384(5);
        return func_ov031_0221dedc(first, packet, channel);
    default:
        return -1;
    }
}
