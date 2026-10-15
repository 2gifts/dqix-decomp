#include <globaldefs.h>
#include "Grotto/Main/ActiveGrottoClass.h"

#if defined(jpn)
enum { activeGrottoOffset = 0x240c };
#else
enum { activeGrottoOffset = 0x23EC };
#endif

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d6134(void*, int);

// USA: func_0209db5c
ARM int NotifyOv017WithGrottoByte0x63_0209db5c(void* arg) {
    ActiveGrottoClass* g = (ActiveGrottoClass*)((char*)func_02012fe4() + activeGrottoOffset);
    if (g == NULL) return 0;
    DetailedTreasureMapData* r = g->GetDetailedData();
    if (r == NULL) return 0;
    if (r->mapType_ != 1) return 0;
    func_ov017_021d6134(arg, r->regular_.suffix_);
    return 1;
}
