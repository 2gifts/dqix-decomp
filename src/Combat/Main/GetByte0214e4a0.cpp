#include <globaldefs.h>

extern unsigned char data_0214e4a0;

#if defined(jpn)
#define GetByte0214e4a0 func_020da068
extern "C" ARM unsigned char func_020da068(void);
#endif

// USA: func_020d8704
ARM unsigned char GetByte0214e4a0(void) {
    return data_0214e4a0;
}
