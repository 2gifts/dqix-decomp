#pragma once

#include "System/Matrix.h"
#include "Grotto/Main/TileFeatures.h"

class Zone3D;
class Model3D;
class ZoneFeatures;
class FloorMap;

struct BmdjElementResource {
    unsigned short kind;
    unsigned short unknown2;
    union {
        void* polygons;
        Model3D* model;
    };
};

struct BmdjSceneElement {
    unsigned short id;
    unsigned short flags;
    signed char state : 7;
    signed char flag4 : 1;
    char unknown5;
    short angle;
    Vector3i position;
    unsigned char unknown14[0x10];
    BmdjElementResource* resource;
    BmdjSceneElement* parent;
    BmdjSceneElement* linkedElement2c;
    unsigned char unknown30[4];
    short destinationAngle;
    short rotationSpeed;
    short copiedAngle;
    short movementSpeed;
    Vector3i destination;
    Vector3i direction;
    unsigned char unknown54[4];
    Vector3i lowerMargins;
    Vector3i upperMargins;
};

struct BmdjScriptState {
    int unknown0;
    int unknown4;
    int unknown8;
    int unknownC;
    int elementCount;
    int unknown14;
    unsigned char unknown18[0x20];
    unsigned char unknown38;
    unsigned char unknown39[3];
};

struct BmdjScriptNode {
    int unknown0;
    BmdjScriptState scriptState;
    int unknown40;
    BmdjSceneElement* elements;
    Vector3i position;
    BmdjScriptNode* next;
};

struct GrottoTileMapRecord {
    BmdjScriptNode* node;
    TileFeaturePlacementData info;
    Matrix3x3 rotation;
    int angle;
    Vector3i position;
};

BmdjScriptNode* GetNodeAtDepth020196fc(Zone3D* zone, int depth);
void Reset02013490(GrottoTileMapRecord* record);
void InitStruct02013454(BmdjScriptNode* node);
void ResetTrackerState(BmdjScriptState* state);
void ProcessNode0201aedc(Zone3D* zone);
TileFeaturePlacementData* FindEntryByNameSubstr0201e434(ZoneFeatures* features, const char* name);
TileFeaturePlacementData* CopyStruct02019f24(TileFeaturePlacementData* destination, const TileFeaturePlacementData* source);
extern "C" int func_02019728(Zone3D* zone, int unused, ZoneFeatures* features, TileFeaturePlacementData* grid, FloorMap* map);

typedef char BmdjSceneElementSizeCheck[sizeof(BmdjSceneElement) == 0x70 ? 1 : -1];
typedef char BmdjScriptStateSizeCheck[sizeof(BmdjScriptState) == 0x3c ? 1 : -1];
typedef char BmdjScriptNodeSizeCheck[sizeof(BmdjScriptNode) == 0x58 ? 1 : -1];
typedef char BmdjScriptNodeElementsCheck[offsetof(BmdjScriptNode, elements) == 0x44 ? 1 : -1];
typedef char BmdjScriptNodeNextCheck[offsetof(BmdjScriptNode, next) == 0x54 ? 1 : -1];
typedef char GrottoTileInfoSizeCheck[sizeof(TileFeaturePlacementData) == 0x10 ? 1 : -1];
typedef char GrottoTileMapRecordSizeCheck[sizeof(GrottoTileMapRecord) == 0x48 ? 1 : -1];
