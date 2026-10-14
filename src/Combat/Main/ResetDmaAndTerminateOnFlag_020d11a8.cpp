#include <globaldefs.h>

void ResetDMAChannel(int id);
int TerminateSystem020ce7a4(void);
extern "C" void func_020c976c(unsigned int id);
void WaitWhileChannel0xEBusy_020d1294(int a, int b);
extern "C" void func_020c9be0(void);

// USA: func_020d11a8  (semantic: ResetDmaAndTerminateOnFlag_020d11a8)
extern "C" ARM void func_020d11a8(void) {
    int ok = 1;
    ResetDMAChannel(0);
    ResetDMAChannel(ok);
    ResetDMAChannel(2);
    ResetDMAChannel(3);

    int val = *(volatile unsigned short*)0x27fffa8;
    int flag = (val & 0x8000) >> 15;
    if (flag != 0) {
        int status = TerminateSystem020ce7a4();
        if (status == 4) {
            do {
                func_020c976c(0xa3a47);
                status = TerminateSystem020ce7a4();
            } while (status == 4);
        }
        if (status == 0) ok = 0;
    }
    if (ok != 0) {
        WaitWhileChannel0xEBusy_020d1294(1, 1);
    }
    func_020c9be0();
}
