#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct GameState;
struct SafeAllocator;

struct Vector3i {
    int x;
    int y;
    int z;

    Vector3i& operator=(const Vector3i& other);
};

// A stair's placement inside the floor map: rotation matrix, world position, angle.
struct Struct0201ae8c {
    int matrix[9];
    Vector3i pos;
    int angle;
};

struct FloorMap0201a600 {
    unsigned char* mapData;
    unsigned char* adjacencyData;
    int width;
    int height;
    unsigned char upX;
    unsigned char upY;
    unsigned char downX;
    unsigned char downY;
    Struct0201ae8c up;
    Struct0201ae8c down;
};

struct ActiveGrotto0201a600 {
    char pad_0[REGION_VALUE(0x1e8, 0x1c8)];
    FloorMap0201a600 floorMap;
};

struct GrottoStruct0201a600 {
    char pad_0[5];
    unsigned char environ;
    char pad_6[2];
    signed char unknown_8;
    char pad_9[3];
    int entranceZoneId;
    Vector3i entrance;
    char pad_1c[REGION_VALUE(0x30, 0x50)];
    char activeMapData[1];
};

// Warp trigger box, ZoneFeatures::Opcode68Entry.
struct Opcode68Entry0201a600 {
    int unk_0;
    int bounds[6];
    int targetZone;
    Vector3i targetPos[4];
    short unk_50;
    short unk_52;
    int radiusSq;
    int centre[3];
    int unk_64[2];
    int unk_6c;
};

struct ZoneInfo0201a600 {
    unsigned short id;
};

struct Zone0201a600 {
    unsigned short currentZoneID;
    unsigned short previousZoneID;
    char pad_4[4];
    ZoneInfo0201a600* info;
    char pad_c[REGION_VALUE(0x7c, 0x5c)];
    SafeAllocator* allocator;
    char features[0x88];
    char pad_f4[0x23e8 - 0xf4];
    unsigned char downStairDir;
    unsigned char upStairDir;
    char pad_23ea[2];
    ActiveGrotto0201a600 grotto;
};

struct Resources0201a600 {
    char pad_0[REGION_VALUE(0x34c0, 0x36d0)];
    void* unknown_36d0;
};

// The player's pending spawn request.
struct Field3f8_0201a600 {
    char pad_0[7];
    unsigned char active;
    char pad_8[8];
    Vector3i pos;
    unsigned short angle;
    char pad_1e[0x44];
    unsigned char unk_62;
    unsigned char unk_63;
    char pad_64[4];
    unsigned char unk_68;
};

extern "C" {
GameState* _ZN9GameState11GetInstanceEv();
Resources0201a600* func_ov017_0218b5b0();
GrottoStruct0201a600* _ZN9GameState15GetGrottoStructEv(GameState* gs);
int _ZNK19TreasureMapMetadata10GetMapTypeEv(void* metadata);
void* _ZN9GameState20GetUnknownGameObjectEv(GameState* gs);
void _ZN12ZoneFeatures23AllocateOpcode68EntriesEiP13SafeAllocator(void* features, int count, SafeAllocator* alloc);
void _ZN12ZoneFeatures19CreateOpcode68EntryERKNS_13Opcode68EntryE(void* features, const Opcode68Entry0201a600* entry);
int _Z22IsValueInRange0201b5d8i(int zoneId);
int _Z17IsInRange0201b588i(int zoneId);
unsigned short _ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(const ActiveGrotto0201a600* grotto);
int _ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(const ActiveGrotto0201a600* grotto);
int _ZNK17ActiveGrottoClass13GetFloorCountEv(const ActiveGrotto0201a600* grotto);
void srand(unsigned int seed);
int _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
    void* zone, int tileX, int tileY, int* outX, int* outZ, const void* tileData, bool preferFaceDown);
int _ZNK8FloorMap16GetAdjacencyBitsEii(const FloorMap0201a600* map, int x, int y);
void Mat3x3_WriteRotationY(int* out, int sine, int cosine);
void Mat3x3_WriteIdentity(int* out);
Struct0201ae8c* _Z18CopyStruct0201ae8cP14Struct0201ae8cS0_(Struct0201ae8c* dst, Struct0201ae8c* src);
Field3f8_0201a600* _Z20GetField0x3f8AddressP9GameState(GameState* gs);
int func_02018fbc(Zone0201a600* zone, Vector3i* pos);
void __clear(void* buf, int size);
void func_02024d94(void* obj, unsigned short zoneId, Vector3i* pos);
}

// adjacency patterns that raise the stairs in environment 2
extern const unsigned char data_020e6e44[15];

struct AdjacencyBits0201a600 {
    unsigned char bits;
};

static inline AdjacencyBits0201a600 GetAdjacency0201a600(const FloorMap0201a600* map, int x, int y) {
    AdjacencyBits0201a600 result;
    result.bits = _ZNK8FloorMap16GetAdjacencyBitsEii(map, x, y);
    return result;
}

static inline void* GetSpawner0201a600(Resources0201a600* res) {
    return res->unknown_36d0;
}

static inline int FxSquare0201a600(int a) {
    return (int)(((long long)a * a + 0x800) >> 12);
}

// USA: func_0201a600
extern "C" ARM int func_0201a600(Zone0201a600* self) {
    GameState* gs = _ZN9GameState11GetInstanceEv();
    Resources0201a600* res = func_ov017_0218b5b0();
    ActiveGrotto0201a600* grotto = &self->grotto;
    void* spawner = GetSpawner0201a600(res);
    GrottoStruct0201a600* grottoData = _ZN9GameState15GetGrottoStructEv(gs);
    SafeAllocator* alloc = self->allocator;
    unsigned char mapType = _ZNK19TreasureMapMetadata10GetMapTypeEv(grottoData->activeMapData);
    _ZN9GameState20GetUnknownGameObjectEv(gs);
    int zoneId = self->info->id;
    int floor = self->currentZoneID % 20;
    Opcode68Entry0201a600 entry;
    int y;
    int halfX;
    int halfY;
    int halfZ;
    int x;
    int z;
    unsigned char tileX;
    unsigned char tileY;
    int outX;
    int outZ;
    AdjacencyBits0201a600 adjacency;
    AdjacencyBits0201a600* adjacencyPtr = &adjacency;
    unsigned char key;
    int found;

    _ZN12ZoneFeatures23AllocateOpcode68EntriesEiP13SafeAllocator(self->features, 2, alloc);

    entry.unk_0 = 0;
    entry.targetZone = -1;
    entry.unk_50 = 0;
    entry.unk_52 = 0;
    entry.radiusSq = 0;
    entry.unk_64[0] = 0;
    entry.unk_64[1] = 0;
    entry.centre[0] = 0;
    entry.centre[1] = 0;
    entry.centre[2] = 0;
    entry.targetPos[0].x = 0;
    entry.targetPos[0].y = 0;
    entry.targetPos[0].z = 0;
    entry.targetPos[1].x = 0;
    entry.targetPos[1].y = 0;
    entry.targetPos[1].z = 0;
    entry.targetPos[2].x = 0;
    entry.targetPos[2].y = 0;
    entry.targetPos[2].z = 0;
    entry.targetPos[3].x = 0;
    entry.targetPos[3].y = 0;
    entry.targetPos[3].z = 0;
    entry.unk_6c = -1;

    if (_Z22IsValueInRange0201b5d8i(zoneId)) {
        halfX = 0x2000;
        halfY = 0x2000;
        halfZ = 0x2000;
    } else {
        halfX = 0x800;
        halfY = 0x1800;
        halfZ = 0x400;
    }
    {
        int zSq = FxSquare0201a600(halfZ);
        int xSq = FxSquare0201a600(halfX);

        entry.radiusSq = xSq + zSq;
    }

    found = 0;
    if (_Z22IsValueInRange0201b5d8i(zoneId)) {
        x = 0;
        y = 0x1000;
        z = 0x11000;
    } else {
        Struct0201ae8c placement;

        tileX = grotto->floorMap.upX;
        tileY = grotto->floorMap.upY;
        srand(_ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(grotto));
        self->upStairDir = _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
            self, tileX, tileY, &outX, &outZ, 0, true);
        y = 0x1800;
        x = outX;
        z = outZ;
        adjacency = GetAdjacency0201a600(&grotto->floorMap, tileX, tileY);
        key = adjacency.bits;
        placement.pos.x = x;
        placement.pos.z = z;
        placement.pos.y = 0;
        if (_ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(grotto) == 2) {
            for (int i = 0; i < 15; i++) {
                if (key == data_020e6e44[i]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            placement.pos.y = 0x666;
        }
        if (self->upStairDir == 0) {
            placement.angle = 0x3243;
            Mat3x3_WriteRotationY(placement.matrix, 0, -0x1000);
        } else if (self->upStairDir == 1) {
            placement.angle = 0x1921;
            Mat3x3_WriteRotationY(placement.matrix, 0x1000, 0);
        } else if (self->upStairDir == 2) {
            placement.angle = 0;
            Mat3x3_WriteIdentity(placement.matrix);
        } else if (self->upStairDir == 3) {
            placement.angle = 0x4b65;
            Mat3x3_WriteRotationY(placement.matrix, -0x1000, 0);
        }
        _Z18CopyStruct0201ae8cP14Struct0201ae8cS0_(&grotto->floorMap.up, &placement);
    }

    {
        int xMax = x + halfX;
        int xMin = x - halfX;
        int yMax = y + halfY;
        int yMin = y - halfY;
        int zMax = z + halfZ;
        int zMin = z - halfZ;

        entry.centre[1] = y;
        entry.bounds[0] = xMax;
        entry.centre[0] = x;
        entry.centre[2] = z;
        entry.bounds[1] = yMax;
        entry.bounds[2] = zMax;
        entry.bounds[3] = xMin;
        entry.bounds[4] = yMin;
        entry.bounds[5] = zMin;
    }

    if (_Z22IsValueInRange0201b5d8i(zoneId) && mapType != 2) {
        entry.targetZone = _ZNK17ActiveGrottoClass13GetFloorCountEv(grotto) + 40000 + grottoData->unknown_8 * 20;
    } else if (floor == 1 || mapType == 2) {
        entry.targetZone = grottoData->entranceZoneId;
        Vector3i exitPos = grottoData->entrance;
        exitPos.z += 0x2000;
        entry.targetPos[0] = entry.targetPos[1] = entry.targetPos[2] = entry.targetPos[3] = exitPos;
    } else {
        entry.targetZone = zoneId - 1;
    }

    {
        Field3f8_0201a600* request = _Z20GetField0x3f8AddressP9GameState(gs);

        if ((zoneId > self->previousZoneID || !_Z17IsInRange0201b588i(self->previousZoneID))
            && request->unk_62 == 0 && request->unk_63 == 0
            && self->previousZoneID != 0 && request->unk_68 == 0) {
            request->active = 1;
            if (_Z22IsValueInRange0201b5d8i(zoneId)) {
                request->pos.x = 0;
                request->pos.y = 0;
                request->pos.z = 0xc000;
                request->pos.y = func_02018fbc(self, &request->pos);
                request->angle = 0x323d;
            } else {
                Vector3i pos;
                short angle;

                __clear(&pos, sizeof(pos));
                pos.x = x;
                pos.z = z;
                func_02024d94(spawner, zoneId, &pos);
                if (self->upStairDir == 0) {
                    pos.z -= 0x1800;
                    angle = 0x3243;
                } else if (self->upStairDir == 1) {
                    pos.x += 0x1800;
                    angle = 0x1921;
                } else if (self->upStairDir == 2) {
                    pos.z += 0x1800;
                    angle = 0;
                } else if (self->upStairDir == 3) {
                    pos.x -= 0x1800;
                    angle = 0x4b65;
                }
                pos.y = func_02018fbc(self, &pos);
                request->angle = angle;
                request->pos = pos;
            }
        }
    }
    _ZN12ZoneFeatures19CreateOpcode68EntryERKNS_13Opcode68EntryE(self->features, &entry);

    if (!_Z22IsValueInRange0201b5d8i(zoneId)) {
        Struct0201ae8c placement;
        Field3f8_0201a600* request;

        tileX = grotto->floorMap.downX;
        tileY = grotto->floorMap.downY;
        srand(_ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(grotto));
        self->downStairDir = _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
            self, tileX, tileY, &outX, &outZ, 0, true);
        x = outX;
        z = outZ;
        placement.pos.x = x;
        placement.pos.z = z;
        placement.pos.y = 0;
        placement.angle = 0;
        Mat3x3_WriteIdentity(placement.matrix);
        adjacency = GetAdjacency0201a600(&grotto->floorMap, tileX, tileY);
        key = adjacency.bits;
        found = 0;
        if (_ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(grotto) == 2) {
            for (int i = 0; i < 15; i++) {
                if (key == data_020e6e44[i]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            placement.pos.y = 0x666;
        }
        _Z18CopyStruct0201ae8cP14Struct0201ae8cS0_(&grotto->floorMap.down, &placement);

        entry.bounds[0] = x + 0xc00;
        entry.bounds[1] = 0x800 + 0x1800;
        entry.bounds[2] = z + 0xc00;
        entry.bounds[3] = x - 0xc00;
        entry.bounds[4] = 0x800 - 0x1800;
        entry.bounds[5] = z - 0xc00;
        entry.centre[0] = x;
        entry.centre[1] = 0x800;
        entry.centre[2] = z;

        if (floor == _ZNK17ActiveGrottoClass13GetFloorCountEv(grotto)) {
            switch (grottoData->environ) {
            case 1:
                entry.targetZone = 41101;
                break;
            case 2:
                entry.targetZone = 41201;
                break;
            case 3:
                entry.targetZone = 41301;
                break;
            case 4:
                entry.targetZone = 41401;
                break;
            case 5:
                entry.targetZone = 41501;
                break;
            default:
                entry.targetZone = 41101;
                break;
            }
            entry.targetZone += grottoData->unknown_8;
        } else {
            entry.targetZone = zoneId + 1;
        }

        request = _Z20GetField0x3f8AddressP9GameState(gs);
        if (zoneId < self->previousZoneID && request->unk_62 == 0 && request->unk_63 == 0
            && self->previousZoneID != 0 && request->unk_68 == 0) {
            Vector3i pos;
            short angle;

            __clear(&pos, sizeof(pos));
            pos.x = x;
            pos.z = z;
            func_02024d94(spawner, zoneId, &pos);
            if (self->downStairDir == 0) {
                pos.z -= 0x1800;
                angle = 0x3243;
            } else if (self->downStairDir == 1) {
                pos.x += 0x1800;
                angle = 0x1921;
            } else if (self->downStairDir == 2) {
                pos.z += 0x1800;
                angle = 0;
            } else if (self->downStairDir == 3) {
                pos.x -= 0x1800;
                angle = 0x4b65;
            }
            pos.y = func_02018fbc(self, &pos);
            request->angle = angle;
            request->pos = pos;
            request->active = 1;
        }
        _ZN12ZoneFeatures19CreateOpcode68EntryERKNS_13Opcode68EntryE(self->features, &entry);
    }
    return 1;
}
