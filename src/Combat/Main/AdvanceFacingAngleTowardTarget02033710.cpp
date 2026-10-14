#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

int fix32ReduceAngle0To2Pi(int angle);
struct S_377d4;
struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
int fix32SignedAngleDistance(int a, int b);
struct Vector3i;

extern char data_020efa3c;

struct Vec3_33710 { int x; int y; int z; };
struct Flags0xc4_33710 { unsigned short low : 15; unsigned short hi : 1; };

struct Obj02033710 {
    char pad0[0x14];
    char* name;
    char pad1[0x38];
    struct Vec3_33710 pos;
    char pad2[0x52];
    short angleAE;
    short scaleB0;
    char pad3[0xc];
    unsigned char stateBe;
    char pad4[5];
    struct Flags0xc4_33710 flagsC4;
};

// USA: func_02033710
ARM void AdvanceFacingAngleTowardTarget(struct Obj02033710* obj) {
    GameState* battleStruct = GameState::GetInstance();
    if (obj->stateBe == 4 || obj->stateBe == 6) {
        return;
    }
    unsigned int scaleCount = battleStruct->GetTickCount();
    int scaled = obj->scaleB0 * (int)scaleCount;
    struct Vec3_33710 tmp = obj->pos;
    int d = fix32SignedAngleDistance(tmp.y, obj->angleAE);
    int atTarget = 1;
    if (d > 0) {
        if (d < scaled) {
            tmp.y = obj->angleAE;
        } else {
            tmp.y += scaled;
            atTarget = 0;
        }
    } else if (d < 0) {
        int ad = -d;
        if (ad < scaled) {
            tmp.y = obj->angleAE;
        } else {
            tmp.y -= scaled;
            atTarget = 0;
        }
    }
    tmp.y = fix32ReduceAngle0To2Pi(tmp.y);
    *(Vector3i*)((int*)&obj->pos) = *(Vector3i const*)((int*)&tmp);
    if (atTarget) {
        if (obj->flagsC4.hi) {
            if (!((Object3D*)((struct S_377d4*)obj))->IsTransitioningAnimations()) {
                obj->flagsC4.hi = 0;
                if (obj->stateBe == 0) {
                    if (obj->name != NULL) {
                        if (strcmp(obj->name, &data_020efa3c) == 0) {
                            SetByte0xbeShiftPrev((struct Bytes02033b88*)obj, 0);
                        }
                    }
                }
            }
        }
    }
}
