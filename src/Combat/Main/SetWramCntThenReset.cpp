#include <globaldefs.h>

void SetWramCnt_020c9bfc(unsigned char value);
void ResetDMAChannel(int arg);

// USA: func_020cad00
ARM void SetWramCntThenReset_020cad00(void) {
    SetWramCnt_020c9bfc(3);
    ResetDMAChannel(0);
}
