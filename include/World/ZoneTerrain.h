#pragma once

#include "System/Matrix.h"
#include "World/Bounds3D.h"

class Zone3D;
class Object3D;

struct ZoneTerrainSample {
    Vector3fix a;
    Vector3fix b;
    Vector3fix c;
    Vector3fix normal;
};

struct ZoneTerrainGrid {
    short cells[96][12];
    int unknown900;
    int scale;
    Vector3fix position;
    int unknown914;
    int angle;
    unsigned char remaining[0x980 - 0x91c];
};

typedef char ZoneTerrainSampleSizeCheck[sizeof(ZoneTerrainSample) == 0x30 ? 1 : -1];
typedef char ZoneTerrainGridSizeCheck[sizeof(ZoneTerrainGrid) == 0x980 ? 1 : -1];
typedef char ZoneTerrainGridScaleOffsetCheck[offsetof(ZoneTerrainGrid, scale) == 0x904 ? 1 : -1];
typedef char ZoneTerrainGridPositionOffsetCheck[offsetof(ZoneTerrainGrid, position) == 0x908 ? 1 : -1];

extern "C" int func_02017d90(Zone3D*, int, ZoneTerrainGrid*, Bounds3D, Object3D*);
extern "C" void func_02031188(ZoneTerrainSample*, short*);
extern "C" int func_020312bc(ZoneTerrainSample*, int, Vector3fix*, Vector3fix*, Vector3fix*);
extern "C" int func_020319d8(ZoneTerrainSample*, int, Vector3fix*, Vector3fix*, Vector3fix*);
extern "C" int func_020315b8(ZoneTerrainSample*, int, Vector3fix*, int, Vector3fix*, int);

extern "C" Zone3D* func_02012fe4();
extern "C" int func_02018fbc(Zone3D* zone, Vector3fix* position);
extern "C" Vector3fix func_02019210(Zone3D* zone, const Vector3fix* position,
                                   const Vector3fix* offset, int radius);
