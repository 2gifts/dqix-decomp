#include <globaldefs.h>
#include "Resource/FontBankLoader.h"




// USA: func_ov003_02159464  (semantic: ResetOrBlank_02159464)
extern "C" ARM void func_ov003_02159464(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    FontBankLoader* g;
    unsigned char state;
    if (o[0x59d] == 0) return;
    g = GetGlobal02109400();
    state = o[0x59e];
    if (state == 0) {
        BlankFunction02094b30(g, 0x200, 1);
        o[0x59e] = o[0x59e] + 1;
        return;
    }
    if (state != 1) return;
    if (AlwaysTrue02094b4c(g) != 0) {
        o[0x59d] = 0;
        o[0x59e] = 0;
    }
}
