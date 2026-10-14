#include <globaldefs.h>

extern "C" void func_020c9be0(void);
void SpinDrainAfterWait_020d192c(void);

struct ShutdownGuard020d18d0 {
    int _pad0[3];
    int done;
    int _pad1[2];
    int (*callback)(void);
};
extern ShutdownGuard020d18d0 data_02112160;

// USA: func_020d18d0
ARM void DispatchType0x11ShutdownOnce_020d18d0(int context, int code) {
    if ((code & 0x3f) == 0x11) {
        if (data_02112160.done != 0) return;
        {
            int (*cb)(void) = data_02112160.callback;
            int r = 0;
            if (cb != 0) r = cb();
            if (r != 0) SpinDrainAfterWait_020d192c();
        }
        data_02112160.done = 1;
        return;
    }
    func_020c9be0();
}
