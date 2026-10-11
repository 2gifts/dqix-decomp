#include <globaldefs.h>

extern "C" void _Z30SetDispcntModeAndFlags020c391ciii(int mode, int flagsA, int valB);

struct S18_0219d0c0 {
#if defined(jpn)
 char pad[0x34];
#else
 char pad[0x18];
#endif
 int flag; };
extern S18_0219d0c0 data_ov016_0219d0c0;

// USA: func_ov016_0218be7c  (semantic: SetDispcntModeByFlagAndToggle_0218be7c)
extern "C" ARM void func_ov016_0218be7c(void) {
    if (data_ov016_0219d0c0.flag == 0) {
        _Z30SetDispcntModeAndFlags020c391ciii(6, 0, 0);
    } else {
        _Z30SetDispcntModeAndFlags020c391ciii(2, 0, 0);
    }
    data_ov016_0219d0c0.flag ^= 1;
}
