#pragma once

#include "Resource/Script.h"
#include "World/ZoneFeatures.h"

struct Struct_020fdc20 {
    ZoneFeatures::Opcode6aEntry *currentEntry;
    SafeAllocator *allocator;
    ZoneFeatures *warp;
};

extern Struct_020fdc20 data_020fdc20;

bool ProcessExtraOpcode69Params(Script::Parameter *param, int numParams, ZoneFeatures::Opcode68Entry &entry);
int WarpScript_Opcode_69(Script::Parameter *params, int numParams);
int WarpScript_Opcode_72(Script::Parameter *params, int numParams);
int WarpScript_Opcode_67(Script::Parameter *params, int numParams);
