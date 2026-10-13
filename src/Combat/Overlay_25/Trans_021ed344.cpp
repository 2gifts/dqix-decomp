#include <globaldefs.h>

struct Obj021ed344 {
    char pad[0x160];
    unsigned short f160;
};

// USA: func_ov025_021ed344  (semantic: Trans_021ed344)
extern "C" ARM void func_ov025_021ed344(struct Obj021ed344* obj, int val) {
    obj->f160 = val;
}
