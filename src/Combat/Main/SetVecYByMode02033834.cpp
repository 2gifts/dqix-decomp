#include <globaldefs.h>

struct Obj02033874;

struct Obj02033834 {
    char pad0[0xae];
    short fae;
    char pad1[0x0e];
    unsigned char mode;
    char pad2[0x05];
    unsigned short fc4;
};

short fix32ReduceAngle0To2Pi(int);
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

// USA: func_02033834
ARM void SetVecYByMode02033834(struct Obj02033834* obj, int arg) {
    if (obj->mode == 4 || obj->mode == 3) {
        SetVecYFromValue02033874((struct Obj02033874*)obj, arg);
    } else {
        obj->fae = fix32ReduceAngle0To2Pi(arg);
    }
    obj->fc4 &= ~0x8000;
}
