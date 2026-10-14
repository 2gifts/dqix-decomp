#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// USA: func_0201d494
ARM int WarpScript_Opcode_6e_0201d494(Script::Parameter* params, int numParams) {
    Vector3fix vec;
    params = params->ToVec3fix(&vec);
    fix32_t angle = fix32ReduceAngle0To2Pi((int)(4096.0f * params->ToFloat()));
    ZoneFeatures* warp = data_020fdc20.warp;
    warp->vector_70_ = vec;
    warp->angle_7c_ = angle;
    return 1;
}
