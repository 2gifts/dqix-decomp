#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" void* func_02012fe4(void);

// KEEP-NAME
// USA: func_ov001_02161f64
ARM int SetFlagAtOffset_02161f64_02161f64(void) {
#if defined(jpn)
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + 0x240c);
#else
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + 0x23ec);
#endif
    grotto->unknown_260_[1] = 1;
    return 1;
}
