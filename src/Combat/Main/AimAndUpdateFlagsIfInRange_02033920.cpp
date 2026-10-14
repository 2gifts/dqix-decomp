#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };
extern "C" int func_02032424(struct Vec3*, struct Vec3*);
struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834*, int);
int fix32SignedAngleDistance(int a, int b);
int fix32abs(int x);
extern "C" int _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, char* data, int mode);
extern char data_020efa3c;

struct Entity02033920 {
    char pad0[4];
    short f4;
    char pad1[0x3e];
    struct Vec3 f44;
    char pad2[4];
    int f54;
    char pad3[0x56];
    short fae;
    short fb0;
    char pad4[0xc];
    unsigned char fbe;
    char pad5[5];
    unsigned short fc4;
};

// USA: func_02033920  (semantic: AimAndUpdateFlagsIfInRange_02033920)
extern "C" ARM void func_02033920(struct Entity02033920* obj, int id, int flag) {
    GameState* battleStruct = GameState::GetInstance();
    if (id == obj->f4) return;
    GameObject* combatant = battleStruct->GetGameObjectByIndex(id);
    if (combatant == 0) return;
    int angle = func_02032424((struct Vec3*)((char*)combatant + 0x44), &obj->f44);
    SetVecYByMode02033834((struct Obj02033834*)obj, angle);
    if (flag == 0) return;
    if (obj->fbe != 0) return;
    int d = fix32SignedAngleDistance(obj->f54, obj->fae);
    int ad = fix32abs(d);
    if (ad <= 0x1000) return;
    if (obj->fb0 > 0x10c) return;
    int r = _ZN8Object3D24MaybeSetRegularAnimationEPKci(obj, &data_020efa3c, 0x11);
    if (r != 0) {
        obj->fc4 |= 0x8000;
    }
}
