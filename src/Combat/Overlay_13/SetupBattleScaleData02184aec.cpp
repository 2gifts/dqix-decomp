#if defined(jpn)
#define R(j,u) (j)
#define _Z23EmptyDestructor0205cb60Pv func_0205deb8
#define _Z25ResetDisplayState02155480P11Obj02155480 func_ov006_02156b68
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#define func_ov006_021570fc func_ov006_02158704
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z15Forward0204359cPvi(void*, int);
extern "C" void func_020439b0(void*, int);
extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(void*);
extern "C" void _Z23EmptyDestructor0205cb60Pv(void*);

// USA: func_ov013_02184aec  (semantic: SetupBattleScaleData02184aec)
extern "C" ARM void func_ov013_02184aec(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    unsigned char tag = o[R(0x5c8,0x63c)];
    switch (tag) {
        case 0: case 5: case 6: return;
    }

    void* battle = GameState::GetInstance();
    void* field = _Z26GetGlobalField0x1c020421a0v();
    int count = ((GameState*)battle)->GetTickCount();
    _Z15Forward0204359cPvi(field, count);
    func_020439b0(field, 0);
    _Z19InitEntries0205d2bcP11Obj0205d2bc(o + R(0x34,0x38));
    _Z23EmptyDestructor0205cb60Pv(o + R(0x3d0,0x3d4));
}
