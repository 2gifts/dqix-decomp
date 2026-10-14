#include <globaldefs.h>

extern "C" extern int LoadToSubBG3CharacterData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb5c
ARM int TransferSubBg3CharDataEntry_020bbb5c(int arg0, int arg1, unsigned int arg2) {
    return LoadToSubBG3CharacterData(arg0, arg1, arg2);
}
