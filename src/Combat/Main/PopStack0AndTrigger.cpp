#include <globaldefs.h>

extern "C" void func_020a1940(int);
extern volatile unsigned char data_02109da4;
extern signed char data_02109dae[];
extern signed char data_020f1962[];

// USA: _Z28PopStack0AndTrigger_020a1e54i
ARM void PopStack0AndTrigger_020a1e54(int flag) {
    if (data_02109da4 == 0) return;
    data_02109da4--;
    if (flag == 0 || data_02109da4 == 0) return;
    signed char i = data_02109dae[data_02109da4 - 1];
    func_020a1940(data_020f1962[i]);
}
