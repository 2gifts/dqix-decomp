#include <globaldefs.h>

extern "C" int LoadToMainBG2CharacterData(int, int, unsigned int);

#if defined(jpn)
#define TransferBg2CharDataThunk020bba50 func_020bd51c
extern "C" ARM int func_020bd51c(int arg0, int arg1, unsigned int arg2);
#endif

// USA: func_020bba50
ARM int TransferBg2CharDataThunk020bba50(int arg0, int arg1, unsigned int arg2) {
    return LoadToMainBG2CharacterData(arg0, arg1, arg2);
}
