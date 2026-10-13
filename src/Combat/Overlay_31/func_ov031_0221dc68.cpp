#include <globaldefs.h>

extern "C" int func_ov031_0221d384(int);
extern "C" int func_ov031_0221dcbc(int, int, int);
extern "C" int func_ov031_0221de00(int, int, int);
extern "C" int func_ov031_0221dedc(int, int, int);

// USA: func_ov031_0221dc68
extern "C" THUMB int func_ov031_0221dc68(int type, int first, int second, int third) {
    switch (type) {
    case 0:
        func_ov031_0221d384(2);
        return func_ov031_0221dcbc(first, second, third);
    case 1:
        func_ov031_0221d384(3);
        return func_ov031_0221de00(first, second, third);
    case 2:
        func_ov031_0221d384(5);
        return func_ov031_0221dedc(first, second, third);
    default:
        return -1;
    }
}
