#include <globaldefs.h>

#include "Resource/GameResources.h"
#include "Combat/MapDisplay.h"
extern "C" int func_02012fe4(void);
extern "C" int sprintf(char* dst, const char* fmt, ...);

struct Obj020e063c;
void RestartTaskHandle020e063c(Obj020e063c* self, int b, int c);


extern char data_020f2948[];
extern char data_020f294f[];

// USA: func_020dc3d4
ARM void RestartTaskWithDebugLog020dc3d4(void) {
    char buf[0x18];
    GameResources* resources = func_ov017_0218b5b0();
    MapDisplay* display = (MapDisplay*)resources->unknown_ptr_36d0;
    func_02020720(display);
    sprintf(buf, data_020f2948, func_02012fe4() + 0x26);
    RestartTaskHandle020e063c((Obj020e063c*)display, (int)data_020f294f, (int)buf);
}

