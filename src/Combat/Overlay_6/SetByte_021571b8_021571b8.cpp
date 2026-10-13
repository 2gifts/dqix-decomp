// KEEP-NAME
// USA: func_ov006_021571b8
// JPN: func_ov006_021587c0
#include <globaldefs.h>
#include "Resource/AlchemyPot.h"

#if defined(jpn)
extern "C" void func_ov023_021dd7d8(void*, unsigned char);
#else
extern "C" void func_ov023_021dced4(void*, unsigned char);
#endif

ARM void SetByte_021571b8_021571b8(void* object, unsigned char value) {
    AlchemyPot* pot = (AlchemyPot*)object;
#if defined(jpn)
    func_ov023_021dd7d8(&pot->window_, value);
#else
    func_ov023_021dced4(&pot->window_, value);
#endif
}
