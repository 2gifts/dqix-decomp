#pragma once

#include "Util/ElementIndexTable.h"
#include "World/Object3D.h"
#include "World/ZoneResourceInitialization.h"

struct InitTarget02013018;
struct ListNode;
struct Node020130e0;
struct Table_1f1b0;

void Init02013018(InitTarget02013018 *self);
void AppendToNodeList(ListNode *parent, ListNode *child);
void AppendNodeToList020130e0(Node020130e0 *list, Node020130e0 *node);
int FindRecordIndexByHalfwordKey(Table_1f1b0 *table, int key);
void InitWithUnitScaleVec0201310c(void *node);
int IsField600B4Zero_021b8b54(void *object);

struct ZoneResourceTreeRecord {
    short key;
    short trackerKey;
    short parentKey;
    unsigned short flags;
    Vector3i position;
    char unknown14[0xc];
};

struct ZoneResourceRuntimeNode {
    unsigned short key;
    unsigned short flags;
    signed char remaining : 7;
    unsigned char flag4 : 1;
    unsigned char unknown5[3];
    Vector3i position;
    char unknown14[0xc];
    ZoneResourceTreeRecord *source;
    Struct02012ff0 *tracker;
    ZoneResourceRuntimeNode *parent;
    ZoneResourceRuntimeNode *firstChild;
    ZoneResourceRuntimeNode *next;
    union {
        short targetAngle;
        unsigned short animationState;
    };
    union {
        short rotationSpeed;
        unsigned short delay;
    };
    short angle;
    union {
        unsigned short unknown3a;
        short movementSpeed;
    };
    Vector3i targetPosition;
    Vector3i direction;
    Object3D *object;
    char unknown58[0x18];
};

struct ZoneResourceTree {
    ZoneResourceNode resources;
    ZoneResourceRuntimeNode *nodes;
    Vector3i position;
};

extern "C" void *func_ov017_021b8478(void *object);
