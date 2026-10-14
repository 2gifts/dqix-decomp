#include <globaldefs.h>
#include "World/Object3D.h"

struct PairStruct;
struct Object3D;

// USA: func_02072adc
ARM void CopyPairAndStoreField(struct PairStruct* src, struct PairStruct* dst) {
    ((Object3D*)src)->ShallowCloneModelAndAnimationsTo((Object3D*)dst);
    *(short*)((char*)dst + 0x178) = *(int*)((char*)src + 0xac);
}
