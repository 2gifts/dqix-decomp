#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"

#if defined(jpn)
enum { activeGrottoOffset = 0x240c };
#else
enum { activeGrottoOffset = 0x23ec };
#endif

extern "C" void* func_02012fe4();
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_0209d7ac
ARM int SubmitActiveGrottoByte0209d7ac(void* arg) {
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + activeGrottoOffset);
    if (grotto == NULL) return 0;
    DetailedTreasureMapData* p = grotto->GetDetailedData();
    if (p == NULL) return 0;
    func_ov017_021d6134(arg, p->mapType_);
    return 1;
}
