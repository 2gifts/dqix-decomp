#include <globaldefs.h>
#include "World/Object3D.h"
#include "System/Matrix.h"
#include "World/Zone3D.h"

struct TerrainGrid {
    short cells[96][12];
    int unused900;
    int scale;
    Vector3i position;
    int unused914;
    int angle;
};
struct TerrainProbe { Vector3i upper; Vector3i lower; };
extern "C" long long func_020c32f8(int);
extern "C" long long func_020c3260(int);
extern "C" float func_0200c700(long long);
#if defined(jpn)
#define func_0204c030 func_0204ce50
#endif
extern "C" int func_0204c030(void*, TerrainGrid*, TerrainProbe);

// USA: func_02017d90
extern "C" ARM int func_02017d90(Zone3D* self, int index, TerrainGrid* grid, TerrainProbe probe, Object3D* object) {
    if (self->isInMainGrottoFloor_23b8_) {
        if (!object) return 0;
        FloorMap* floor = &self->grotto_.floorMap_;
        BmdjSceneElement* node;
        int x, z, angle;
        if (index < 256) {
            GrottoTileMapRecord* entry = &self->grottoTileMapData_420_[index];
            if (entry->node) node = entry->node->elements->linkedElement2c;
            else return 0;
            x = entry->position.x;
            z = entry->position.z;
            angle = entry->angle;
        } else {
            if (GetNodeAtDepth020196fc(self, 4))
                node = GetNodeAtDepth020196fc(self, 4)->elements->linkedElement2c;
            else return 0;
            x = floor->upStairWorldX;
            z = floor->upStairWorldZ;
            angle = floor->fpUpStairRotation;
        }
        if (!node) return 0;
        if (!node->resource) return 0;
        if (node->flags & 4) return 0;
        BmdjSceneElement* parent = node->parent;
        while (parent) {
            if (parent->flags & 4) return 0;
            parent = parent->parent;
        }
        void* polygons = node->resource->polygons;
        if (!polygons) return 0;
        TerrainProbe local;
        Vector3i origin;
        Matrix3x3 rotation;
        local.upper = object->position_;
        StoreThreeWordsAt0x0020130a8(&origin, x, 0, z);
        Vector3fix_Subtract(&local.upper, &origin, &local.upper);
        int rotationAngle = -(angle - 25735);
        int cosine = (int)(4096.0f * (func_0200c700(func_020c32f8(rotationAngle)) / 4294967296.0f));
        int sine = (int)(4096.0f * (func_0200c700(func_020c3260(rotationAngle)) / 4294967296.0f));
        Mat3x3_WriteRotationY(&rotation, sine, cosine);
        Mat3x3_ApplyToVector(&local.upper, &rotation, &local.upper);
        local.lower = local.upper;
        local.upper.x += object->GetRadius() / 2;
        local.upper.y += object->GetHeight();
        local.upper.z += object->GetRadius() / 2;
        local.lower.x -= object->GetRadius() / 2;
        local.lower.y -= 0xa000;
        local.lower.z -= object->GetRadius() / 2;
        int count = func_0204c030(polygons, grid, local);
        grid->position = origin;
        grid->angle = angle;
        return count;
    }
    BmdjSceneElement* node = self->terrainElements_[index];
    if (!node->resource) return 0;
    if (node->flags & 4) return 0;
    BmdjSceneElement* parent = node->parent;
    while (parent) {
        if (parent->flags & 4) return 0;
        parent = parent->parent;
    }
    if (node->flags & 1) return 0;
    void* polygons = node->resource->polygons;
    if (!polygons) return 0;
    Vector3i origin = node->position;
    Vector3fix_Subtract(&probe.upper, &origin, &probe.upper);
    Vector3fix_Subtract(&probe.lower, &origin, &probe.lower);
    probe.lower.x -= node->lowerMargins.x;
    probe.lower.y -= node->lowerMargins.y;
    probe.lower.z -= node->lowerMargins.z;
    probe.upper.x += node->upperMargins.x;
    probe.upper.y += node->upperMargins.y;
    probe.upper.z += node->upperMargins.z;
    int count = func_0204c030(polygons, grid, probe);
    Vector3fix_Add(&grid->position, &origin, &grid->position);
    int angle = node->angle;
    float adjustedAngle;
    if ((float)angle / 4096.0f > 0) adjustedAngle = 0.5f + 4096.0f * ((float)angle / 4096.0f);
    else adjustedAngle = 4096.0f * ((float)angle / 4096.0f) - 0.5f;
    grid->angle = (int)adjustedAngle;
    return count;
}
