#include <globaldefs.h>
#include "GameState/GameState.h"

struct FlagWord02046708;
FlagWord02046708* GetDataPtr02114e04_020d6c00();
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
int GetByteAtPtrOrZero_02191b58(void*, int);
void SetupAndDispatchCombatant_02191e5c(int, int, short, unsigned char, unsigned short);
void DispatchOrSetupCombatant_02191f4c(int, int);
static inline int GetField06(GameObject* obj) { return obj->obj3D_.GetField06(); }
extern "C" void func_ov017_0219230c(unsigned char* obj, int idx, int c);
extern "C" void func_ov017_02192400(unsigned char* obj, int idx);
extern "C" unsigned char* func_ov017_0219219c(unsigned char* obj, int idx);

// USA: func_ov017_02191cc0
extern "C" ARM void func_ov017_02191cc0(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x3930};
#else
 enum {regionalOffset0=0x3b50};
#endif
    if (TestFlags02046708(GetDataPtr02114e04_020d6c00(), 0x20000)) return;
    GameState* battle = GameState::GetInstance();
    GameObject* protagonist = battle->GetProtagonist();
    if (protagonist == 0) return;
    unsigned short field06 = GetField06(protagonist);

    for (int i = 0; i <= 199; i++) {
        int flags = GetByteAtPtrOrZero_02191b58(obj, i);
        if (!(flags & 1)) continue;
        GameObject* object = battle->GetGameObjectByIndex(i);
        if (object != 0 && field06 != GetField06(object)) continue;

        int flag4 = flags & 4;
        int flag2 = flags & 2;
        if (flag4 && flag2) {
            SetupAndDispatchCombatant_02191e5c((int)obj, i, 0x999, 1, 0x65ff);
            func_ov017_0219230c(obj, i, 8);
        } else if (flag4) {
            SetupAndDispatchCombatant_02191e5c((int)obj, i, 0x1000, 0, 0x282f);
            func_ov017_02192400(obj, i);
        } else if (flag2) {
            unsigned char* state = *(unsigned char**)(obj + regionalOffset0);
            short c = 0x999;
            if (state[3] != 0 && state[1] == 0) c = 0x1000;
            SetupAndDispatchCombatant_02191e5c((int)obj, i, c, 1, 0x79e8);
            func_ov017_0219230c(obj, i, 8);
        } else {
            DispatchOrSetupCombatant_02191f4c((int)obj, i);
            func_ov017_02192400(obj, i);
        }
        unsigned char* entry = func_ov017_0219219c(obj, i);
        if (entry != 0) *entry &= ~1;
    }
}
