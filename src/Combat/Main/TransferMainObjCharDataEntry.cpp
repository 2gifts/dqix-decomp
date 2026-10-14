#include <globaldefs.h>

extern "C" int LoadToMainObjVRAM(int, int, unsigned int);

// USA: func_020bbb2c
ARM int TransferMainObjCharDataEntry_020bbb2c(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainObjVRAM(arg0, arg1, arg2);
}
