#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void* func_02012fe4(void* unused);
struct Vector3i;

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
                *(Vector3i*)((int*)(obj + 0x4c)) = *(Vector3i const*)((int*)&grottoVec);
                ((Object3D*)(obj + 8))->SetScale((Vector3i const*)&constVec);
                ((Object3D*)(obj + 8))->MaybeSetBCFGAnimation(0, 0);
                ((Object3D*)(obj + 8))->MakeVisible();
                obj[0xb6] = 1;
            }
            obj[0xb5] = 0;
        }
    }
}
