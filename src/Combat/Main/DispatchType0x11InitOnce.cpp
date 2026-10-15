#include <globaldefs.h>

extern "C" void func_020c9be0(void);
extern "C" void func_020d11a8(void);

struct InitGuard020d1144 {
    int done;
    int (*callback)(void);
};
extern InitGuard020d1144 data_02112140;

// USA: func_020d1144
ARM void DispatchType0x11InitOnce_020d1144(unsigned int context, unsigned int code, unsigned int error) {
    if ((code & 0x3f) == 0x11) {
        if (data_02112140.done != 0) return;
        data_02112140.done = 1;
        {
            int r = 1;
            if (data_02112140.callback != 0) r = data_02112140.callback();
            if (r == 0) return;
            func_020d11a8();
        }
        return;
    }
    func_020c9be0();
}
