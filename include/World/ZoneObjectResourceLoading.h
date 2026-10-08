#pragma once

#include "Filesystem/FileIO.h"
#include "Filesystem/NarcHandle.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneResourceInitialization.h"

struct ZoneAnimationResource {
    unsigned int mask;
    int slot;
    char extension[8];
};

struct ZoneAnimationResources {
    ZoneAnimationResource entries[6];
};

struct ZoneLoadState {
    char unknown0[0x20];
    int unknown20;
};

void *GetField0x3f8Address(GameState *state);
void FormatFilenameAndSetExtension02014d18(int id, char *extension, char *buffer);
void RestorePairTables0207df90(char *tables);
void BackupPairTables0207dfac(char *tables);
extern char data_020ef1e8[];
extern const ZoneAnimationResources data_020e6f48;
