#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" int _ZNK8Object3D9IsVisibleEv(unsigned char* obj);
extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);
extern "C" void* func_02012fe4(void* unused);

struct Struct0208f820 {
    unsigned char pad_00[8];
    unsigned char pad_08[0xac];
    unsigned char flagB4;
    unsigned char flagB5;
    unsigned char flagB6;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0208f820
extern "C" ARM void _Z30MaybeNotifyGrottoState0208f820P14Struct0208f820(struct Struct0208f820* p) {
    if (p->flagB4 != 0 && p->flagB6 != 0) {
        if (_ZNK8Object3D9IsVisibleEv((unsigned char*)p + 8) == 0) {
            return;
        }
        GameState* battle = GameState::GetInstance();
        GrottoStruct* grotto = battle->GetGrottoStruct();
        unsigned short val = *(unsigned short*)func_02012fe4(grotto);
        if (val != *(int*)((char*)grotto + 0xc)) {
            return;
        }
        _ZN8Object3D4DrawEb((unsigned char*)p + 8, 1);
    }
}