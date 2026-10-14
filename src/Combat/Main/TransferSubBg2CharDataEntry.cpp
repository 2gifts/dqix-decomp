#include <globaldefs.h>

extern "C" extern int LoadToSubBG2CharacterData(int arg0, int arg1, unsigned int arg2);

// USA: func_020bbb50
ARM int TransferSubBg2CharDataEntry_020bbb50(int arg0, int arg1, unsigned int arg2) {
    return LoadToSubBG2CharacterData(arg0, arg1, arg2);
}
