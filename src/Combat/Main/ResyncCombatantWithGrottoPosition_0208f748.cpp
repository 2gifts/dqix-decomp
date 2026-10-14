#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void* func_02012fe4(void* unused);
struct Vector3i;
extern "C" void* func_0202ae18(void);
extern int data_020e8d48;

struct Vec3Local_0208f748 { int x, y, z; };
struct Field0xc_0208f748 { char pad[0xc]; unsigned char flag:4; };

// USA: func_0208f748  (semantic: ResyncCombatantWithGrottoPosition_0208f748)
extern "C" ARM int func_0208f748(unsigned char* obj) {
    void* p = func_02012fe4(obj);
    Field0xc_0208f748* q = (Field0xc_0208f748*)*(void**)((char*)p + 8);
    if (q->flag != 0) return 0;
    GameState* battle = GameState::GetInstance();
    battle->GetProtagonist();
    ((int)func_ov017_0218b5b0());
    func_0202ae18();
    GrottoStruct* grotto = battle->GetGrottoStruct();
    Vec3Local_0208f748 tmp1;
    *(Vector3i*)((int*)&tmp1) = *(Vector3i const*)((int*)((char*)grotto + 0x10));
    Vec3Local_0208f748 tmp0 = *(Vec3Local_0208f748*)&data_020e8d48;
    *(Vector3i*)((int*)(obj + 0x4c)) = *(Vector3i const*)((int*)&tmp1);
    ((Object3D*)(obj + 8))->SetScale((Vector3i const*)&tmp0);
    ((Object3D*)(obj + 8))->MaybeSetBCFGAnimation(0, 0);
    ((Object3D*)(obj + 8))->MakeVisible();
    obj[0xb6] = 1;
    return 1;
}
