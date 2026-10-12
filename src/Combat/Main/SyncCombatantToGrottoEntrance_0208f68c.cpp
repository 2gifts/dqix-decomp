#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void* func_02012fe4(void* unused);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(unsigned char* dst, int* src);
extern "C" void _ZN8Object3D11MakeVisibleEv(unsigned char* obj);
extern "C" int _ZN8Object3D21MaybeSetBCFGAnimationEii(void* obj, int id, int flags);

extern int data_020e8d3c;

struct Vec3Local_0208f68c { int x, y, z; };

// USA: func_0208f68c  (semantic: SyncCombatantToGrottoEntrance_0208f68c)
extern "C" ARM void func_0208f68c(unsigned char* obj) {
    if (obj[0xb4] != 0) {
        GameState* battle = GameState::GetInstance();
        void* p = func_02012fe4(battle);
        unsigned short val = *(unsigned short*)p;
        GrottoStruct* grotto = battle->GetGrottoStruct();
        Vec3Local_0208f68c constVec = *(Vec3Local_0208f68c*)&data_020e8d3c;
        Vec3Local_0208f68c grottoVec = *(Vec3Local_0208f68c*)((char*)grotto + 0x10);
        int zoneId = *(int*)((char*)grotto + 0xc);
        if (zoneId != 0 && grotto->unknown_0[0] != 0) {
            if (zoneId == val) {
                _ZN8Vector3iaSERKS_((int*)(obj + 0x4c), (int*)&grottoVec);
                _ZN8Object3D8SetScaleEPK8Vector3i(obj + 8, (int*)&constVec);
                _ZN8Object3D21MaybeSetBCFGAnimationEii(obj + 8, 0, 0);
                _ZN8Object3D11MakeVisibleEv(obj + 8);
                obj[0xb6] = 1;
            }
            obj[0xb5] = 0;
        }
    }
}
