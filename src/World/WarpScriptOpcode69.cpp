#include "Combat/Main/ElementLookup.h"
#include "GameState/GameState.h"
#include "Resource/Script.h"
#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// USA: func_0201cb60
ARM bool ProcessExtraOpcode69Params(Script::Parameter *param, int numParams, ZoneFeatures::Opcode68Entry &entry) {
    Script::Parameter *paramStart = param;
    List0209998c *worldData       = static_cast<List0209998c *>(GetPtrField0x468(GameState::GetInstance()));

    entry.unk_0 = (param++)->ToInt();
    if (paramStart[1].type == 0) {
        Elem0209998c *zone = FindElementByName0209998c(worldData, (param++)->ToString());
        if (zone == NULL) return false;
        entry.unk_1c = zone->f0;
    } else {
        entry.unk_1c = (param++)->ToInt();
    }
    entry.unk_64[0] = (param++)->ToInt();
    entry.unk_64[1] = (param++)->ToInt();

    Vector3fix tempVector;
    param           = param->ToVec3fix(&tempVector);
    entry.unk_20[0] = tempVector;
    entry.unk_50    = 4096.0f * (param++)->ToFloat();

    if (numParams - (param - paramStart) > 0) {
        entry.unk_6c = (param++)->ToInt();
    }
    if (numParams - (param - paramStart) > 0) {
        param           = param->ToVec3fix(&tempVector);
        entry.unk_20[1] = tempVector;
        param           = param->ToVec3fix(&tempVector);
        entry.unk_20[2] = tempVector;
        param           = param->ToVec3fix(&tempVector);
        entry.unk_20[3] = tempVector;
    }
    return true;
}

// USA: func_0201ccc8
ARM int WarpScript_Opcode_69(Script::Parameter *params, int numParams) {
    ZoneFeatures::Opcode68Entry entry;
    entry.Reset();
    Script::Parameter *p = params;
    fix32_t centreX      = (int) (4096.0f * (p++)->ToFloat());
    fix32_t centreY      = (int) (4096.0f * (p++)->ToFloat());
    fix32_t centreZ      = (int) (4096.0f * (p++)->ToFloat());
    fix32_t halfExtentX      = (int) (4096.0f * (p++)->ToFloat()) / 2;
    fix32_t halfExtentY      = (int) (4096.0f * (p++)->ToFloat()) / 2;
    fix32_t halfExtentZ      = (int) (4096.0f * (p++)->ToFloat()) / 2;

    fix32_t xMax = centreX + halfExtentX;
    fix32_t xMin = centreX - halfExtentX;
    fix32_t yMax = centreY + halfExtentY;
    fix32_t yMin = centreY - halfExtentY;
    fix32_t zMax = centreZ + halfExtentZ;
    fix32_t zMin = centreZ - halfExtentZ;

    entry.unk_58[1] = centreY;
    entry.unk_4[0]  = xMax;
    entry.unk_58[0] = centreX;
    entry.unk_58[2] = centreZ;
    entry.unk_4[1]  = yMax;
    entry.unk_4[2]  = zMax;
    entry.unk_4[3]  = xMin;
    entry.unk_4[4]  = yMin;
    entry.unk_4[5]  = zMin;

    if (!ProcessExtraOpcode69Params(p, numParams - (p - params), entry)) return 0;
    data_020fdc20.warp->CreateOpcode68Entry(entry);
    return 1;
}
