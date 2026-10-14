#include <globaldefs.h>

extern "C" extern int LoadToSubBG0CharacterData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb38
ARM int TransferSubBg0CharDataEntry_020bbb38(int arg0, int arg1, unsigned int arg2) {
    return LoadToSubBG0CharacterData(arg0, arg1, arg2);
}
