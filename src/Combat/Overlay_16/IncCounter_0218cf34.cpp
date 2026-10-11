#include <globaldefs.h>

struct Data0218cf34 {
#if defined(jpn)
 unsigned char pad[0x30];
#else
 unsigned char pad[0x44];
#endif
 unsigned long long counter; };
extern struct Data0218cf34 data_ov016_0219d144;

// USA: func_ov016_0218cf34
ARM void IncCounter_0218cf34(void) {
    data_ov016_0219d144.counter++;
}
