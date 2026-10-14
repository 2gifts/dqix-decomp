#include <globaldefs.h>
#include "GameState/Field3b0.h"
#if defined(jpn)
enum { flagsOffset = 0x57e4, workOffset = 0xe44, combatantOffset = 0x71c6, stateOffset = 0xe24, dispatchOffset = 0x5ca0 };
#else
enum { flagsOffset = 0x55f4, workOffset = 0xec8, combatantOffset = 0x6fd6, stateOffset = 0xea8, dispatchOffset = 0x5ab0 };
#endif
#include "GameState/GameState.h"
#include "Graphics/NSBXX/RenderConfig.h"

unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" void func_02016874(void* big);
extern "C" void func_ov000_02161020(void* obj);
struct Vec3i_020374f0 { int x; int y; int z; };
extern "C" struct Vec3i_020374f0 _ZNK8Object3D8GetScaleEv(unsigned char* src);
struct Vector3i;
int PeekInputLogB(void);
extern "C" void func_ov025_021df864(void* arg);

// USA: func_ov000_02160b54  (semantic: RefreshCombatantAndDispatch_02160b54)
extern "C" ARM void func_ov000_02160b54(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned int* v = ((unsigned int*)func_ov017_0218b5b0());
    GetField0x3b0Value(battle);
    if (!(*(int*)(obj + flagsOffset) & 0x200)) {
        return;
    }
    if (GetBitsInField4(v, 0x100000) == 0) {
        func_02016874(obj + workOffset);
    }
    func_ov000_02161020(obj);
    if (GetBitsInField4(v, 4) == 0) {
        GameObject* c1 = battle->GetGameObjectByIndex(*(short*)(obj + combatantOffset));
        GameObject* c2 = battle->GetGameObjectByIndex(0xc8);
        if (c2 != 0) {
            if (c1 != 0) {
                *(Vector3i*)((int*)((char*)c2 + 0x44)) = *(Vector3i const*)((int*)((char*)c1 + 0x44));
                *(Vector3i*)((int*)((char*)c2 + 0x50)) = *(Vector3i const*)((int*)((char*)c1 + 0x50));
                const struct Vec3i_020374f0& tmp = _ZNK8Object3D8GetScaleEv((unsigned char*)c1);
                ((Object3D*)((unsigned char*)c2))->SetScale((Vector3i const*)&tmp);
            }
            ((Object3D*)c2)->Draw(0);
        }
    }
    RenderConfig::SubmitToFifo();
    if (*(int*)(obj + stateOffset) != 8) {
        return;
    }
    if (PeekInputLogB() != 4) {
        return;
    }
    func_ov025_021df864(obj + dispatchOffset);
}
