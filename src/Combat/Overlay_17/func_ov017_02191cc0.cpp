#include <globaldefs.h>
#include "GameState/GameState.h"

struct FlagWord02046708;
extern "C" FlagWord02046708* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(struct FlagWord02046708* word, unsigned int mask);
extern "C" int _Z27GetByteAtPtrOrZero_02191b58v(unsigned char* obj, int idx);
extern "C" void _Z34SetupAndDispatchCombatant_02191e5ciisht(unsigned char* obj, int idx, short c, unsigned char d, unsigned short e);
extern "C" void _Z33DispatchOrSetupCombatant_02191f4cii(unsigned char* obj, int idx);
extern "C" int _ZNK8Object3D10GetField06Ev(GameObject* obj);
extern "C" void func_ov017_0219230c(unsigned char* obj, int idx, int c);
extern "C" void func_ov017_02192400(unsigned char* obj, int idx);
extern "C" unsigned char* func_ov017_0219219c(unsigned char* obj, int idx);

// JPN: func_ov017_02192888
// USA: func_ov017_02191cc0
extern "C" ARM void func_ov017_02191cc0(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x3930};
#else
 enum {regionalOffset0=0x3b50};
#endif
    if (_Z17TestFlags02046708P16FlagWord02046708j(_Z27GetDataPtr02114e04_020d6c00v(), 0x20000)) return;
    GameState* battle = GameState::GetInstance();
    GameObject* protagonist = battle->GetProtagonist();
    if (protagonist == 0) return;
    unsigned short field06 = _ZNK8Object3D10GetField06Ev(protagonist);

    for (int i = 0; i <= 199; i++) {
        int flags = _Z27GetByteAtPtrOrZero_02191b58v(obj, i);
        if (!(flags & 1)) continue;
        GameObject* object = battle->GetGameObjectByIndex(i);
        if (object != 0 && field06 != _ZNK8Object3D10GetField06Ev(object)) continue;

        int flag4 = flags & 4;
        int flag2 = flags & 2;
        if (flag4 && flag2) {
            _Z34SetupAndDispatchCombatant_02191e5ciisht(obj, i, 0x999, 1, 0x65ff);
            func_ov017_0219230c(obj, i, 8);
        } else if (flag4) {
            _Z34SetupAndDispatchCombatant_02191e5ciisht(obj, i, 0x1000, 0, 0x282f);
            func_ov017_02192400(obj, i);
        } else if (flag2) {
            unsigned char* state = *(unsigned char**)(obj + regionalOffset0);
            short c = 0x999;
            if (state[3] != 0 && state[1] == 0) c = 0x1000;
            _Z34SetupAndDispatchCombatant_02191e5ciisht(obj, i, c, 1, 0x79e8);
            func_ov017_0219230c(obj, i, 8);
        } else {
            _Z33DispatchOrSetupCombatant_02191f4cii(obj, i);
            func_ov017_02192400(obj, i);
        }
        unsigned char* entry = func_ov017_0219219c(obj, i);
        if (entry != 0) *entry &= ~1;
    }
}
