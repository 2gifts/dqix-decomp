#include <globaldefs.h>

extern "C" unsigned int _Z26GetGlobalField0x1c020421a0v();
extern "C" unsigned int func_020457e0(unsigned int);
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_021884ac  (semantic: Trans_021884ac)
extern "C" ARM unsigned int func_ov011_021884ac(unsigned int arg) {
    func_ov011_02184c68(arg, func_020457e0(_Z26GetGlobalField0x1c020421a0v()));
    return 1;
}
