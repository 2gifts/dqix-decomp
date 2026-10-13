#pragma once

#include "World/Zone3D.h"

void InitStruct020133fc(ZoneChestRenderRecord* record);
void SetElementFlagsFromMask02013cb0(Zone3D* zone, unsigned int mask);
ZoneFeatures::Opcode6aEntry* FindNthType2Entry02018c20(Zone3D* zone, int ordinal);
int FindMatchingElementIndex02018bc4(Zone3D* zone, ZoneFeatures::Opcode6aEntry* target);
void UpdateFlaggedType2Entries02018c74(Zone3D* zone, unsigned int flags);
extern "C" void func_0201647c(Zone3D* zone);
extern "C" int func_0201afd0(Zone3D* zone, const void* treasureArchive, unsigned int sourceSize, int unused);
BmdjSceneElement* FindEntryByNodeIdAndKey(Zone3D* zone, ZoneFeatures::Opcode6aEntry* parameter);
void UpdateEntryFlagsForNodeList(Zone3D* zone);
extern "C" void func_02018300(Zone3D*, ZoneFeatures::Opcode6aEntry*, int, int, int);
extern "C" void func_0201874c(Zone3D*, ZoneFeatures::Opcode6aEntry*);
extern "C" void func_02018918(Zone3D*, ZoneFeatures::Opcode6aEntry*);
