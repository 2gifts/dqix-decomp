#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// USA: func_0201c96c
ARM int WarpScript_Opcode_67(Script::Parameter *params, int numParams) {
    float centreX = params[0].ToFloat();
    float centreY = params[1].ToFloat();
    float centreZ = params[2].ToFloat();
    float extentX = params[3].ToFloat();
    float extentY = params[4].ToFloat();
    float extentZ = params[5].ToFloat();
    float extraValue;
    int value0 = params[6].ToInt();
    int value1 = params[7].ToInt();
    extraValue = 0;
    if (numParams >= 9) extraValue = params[8].ToFloat();

    ZoneFeatures::Opcode66Entry entry;
    entry.unk_0[0] = 4096.0f * (centreX + (extentX / 2.0f));
    entry.unk_0[1] = 4096.0f * (centreY + (extentY / 2.0f));
    entry.unk_0[2] = 4096.0f * (centreZ + (extentZ / 2.0f));

    entry.unk_0[3] = 4096.0f * (centreX - (extentX / 2.0f));
    entry.unk_0[4] = 4096.0f * (centreY - (extentY / 2.0f));
    entry.unk_0[5] = 4096.0f * (centreZ - (extentZ / 2.0f));

    entry.unk_18[0] = value0;
    entry.unk_18[1] = value1;
    entry.unk_20    = 4096.0f * extraValue;

    data_020fdc20.warp->CreateOpcode66Entry(entry);
    return 1;
}
