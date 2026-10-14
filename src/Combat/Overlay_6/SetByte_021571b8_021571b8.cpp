// KEEP-NAME
// USA: func_ov006_021571b8
#include <globaldefs.h>
#include "Resource/AlchemyPot.h"

extern "C" void func_ov023_021dced4(void*, unsigned char);

ARM void SetByte_021571b8_021571b8(void* object, unsigned char value) {
    AlchemyPot* pot = (AlchemyPot*)object;
    func_ov023_021dced4(&pot->window_, value);
}
