#include <globaldefs.h>

void WaitWhileChannelBusy_020d1564(int);
extern "C" void func_020c9be0(void);

// USA: func_020d192c
ARM void SpinDrainAfterWait_020d192c(void) {
    WaitWhileChannelBusy_020d1564(2);
    func_020c9be0();
}
