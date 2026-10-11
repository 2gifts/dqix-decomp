#include <globaldefs.h>

struct State0xc0cc;
void ReleaseGlobalEntry0203c198(char*);
void InitFields0x0(struct State0xc0cc*);

// USA: func_0203c0f0
// JPN: func_0203bc3c
ARM void ReinitFieldState0203c0f0(struct State0xc0cc* obj) {
    ReleaseGlobalEntry0203c198((char*)obj);
    InitFields0x0(obj);
}
