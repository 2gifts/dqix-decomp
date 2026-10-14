#include <globaldefs.h>

extern "C" extern int LoadToSubBG2ScreenData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb80
ARM int TransferSubBg2ScreenDataEntry_020bbb80(int arg0, int arg1, unsigned int arg2) {
    return LoadToSubBG2ScreenData(arg0, arg1, arg2);
}
