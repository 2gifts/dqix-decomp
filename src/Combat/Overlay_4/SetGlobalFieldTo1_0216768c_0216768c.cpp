#include <globaldefs.h>

#if defined(jpn)
enum { stateFieldOffset = 0x218 };
#else
enum { stateFieldOffset = 0x2c8 };
#endif


int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_0216768c
#if defined(jpn)
extern "C" ARM int func_ov004_02167c98(void)
#else
ARM int SetGlobalFieldTo1_0216768c_0216768c(void)
#endif
{
    *(int*)((char*)GetGlobalField0x1c020421a0() + stateFieldOffset) = 1;
    return 0;
}
