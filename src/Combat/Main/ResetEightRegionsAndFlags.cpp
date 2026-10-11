#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif


#if defined(jpn)
extern "C" void func_020942ac(char* obj);
#define ClearRegion02093980 func_020942ac
#else
void ClearRegion02093980(char* obj);
#endif

// USA: func_02093a14
ARM void ResetEightRegionsAndFlags(char* obj) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        ClearRegion02093980(obj + i * (IS_JPN ? 0x10 : 0x34));
    }
    obj[(IS_JPN ? 0x13b : 0x3cb)] = 0;
    ((unsigned char*)obj)[(IS_JPN ? 0x13d : 0x3cd)] &= ~4;
}
