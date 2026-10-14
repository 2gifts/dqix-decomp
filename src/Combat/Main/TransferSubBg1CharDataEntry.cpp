#include <globaldefs.h>

extern "C" extern int LoadToSubBG1CharacterData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb44
ARM int TransferSubBg1CharDataEntry_020bbb44(int arg0, int arg1, unsigned int arg2) {
    return LoadToSubBG1CharacterData(arg0, arg1, arg2);
}
