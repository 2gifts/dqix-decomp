#pragma once

#include "World/ZoneFeatures.h"

class GameObject;

struct ActorActionFlags {
    unsigned char active : 1;
    unsigned char unknown : 7;
};

struct SubBlock02038508 {
    unsigned char active;
    unsigned char command;
    unsigned char unknown2;
    unsigned char reversed;
    unsigned short unknown4;
    short heading;
    short startHeading;
    short endHeading;
    WrappedVector3fix start;
    WrappedVector3fix end;
    WrappedVector3fix unknown24;
    WrappedVector3fix startControl;
    WrappedVector3fix endControl;
    int unknown48;
    int unknown4c;
    short unknown50;
    unsigned char unknown52;
    unsigned char unknown53;
    unsigned char unknown54;
    ZoneFeatures::Opcode6aEntry* startNode;
    ZoneFeatures::Opcode6aEntry* endNode;
    int unknown60;
};

void InitBlock02038508(SubBlock02038508* block);
SubBlock02038508* GetFieldPtrAt0x26c(void* object);
void CopyBlockTo0x26c(GameObject* object, SubBlock02038508* source);
extern "C" void func_ov017_021d3f00(SubBlock02038508* block, unsigned char first, unsigned char second);
