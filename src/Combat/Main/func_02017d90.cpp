#include <globaldefs.h>
#include "World/Object3D.h"
#include "System/Matrix.h"

struct GeometryData { int unused; void* polygons; };
struct TerrainNode {
    unsigned short id;
    unsigned short flags;
    short unused4;
    short angle;
    Vector3i position;
    char pad_14[0x10];
    GeometryData* geometry;
    TerrainNode* parent;
    char pad_2c[0x2c];
    Vector3i lowerMargins;
    Vector3i upperMargins;
};
struct SceneNode { char pad_00[0x2c]; TerrainNode* terrain; };
struct Node020196fc { char pad_00[0x44]; SceneNode* scene; };
struct SceneEntry {
    Node020196fc* node;
    char pad_04[0x34];
    int angle;
    int x;
    int specialZ;
    int z;
};
struct Obj020196fc {
    char pad_00[0x420];
    SceneEntry* scenes;
    char pad_424[0x400];
    TerrainNode** terrain;
    char pad_828[0x1b90];
    unsigned char useScenes;
    char pad_23b9[0x1fb];
    SceneEntry specialScene;
};
struct TerrainGrid {
    short cells[96][12];
    int unused900;
    int scale;
    Vector3i position;
    int unused914;
    int angle;
};
struct TerrainProbe { Vector3i upper; Vector3i lower; };
Node020196fc* GetNodeAtDepth020196fc(Obj020196fc*, int);
void StoreThreeWordsAt0x0020130a8(int*, int, int, int);
extern "C" long long func_020c32f8(int);
extern "C" long long func_020c3260(int);
extern "C" float func_0200c700(long long);
extern "C" int func_0204c030(void*, TerrainGrid*, TerrainProbe);

// USA: func_02017d90
extern "C" ARM int func_02017d90(Obj020196fc* self, int index, TerrainGrid* grid, TerrainProbe probe, Object3D* object) {
    if (self->useScenes) {
        if (!object) return 0;
        SceneEntry* entry = &self->specialScene;
        TerrainNode* node;
        int x, z, angle;
        if (index < 256) {
            entry = &self->scenes[index];
            if (entry->node) node = entry->node->scene->terrain;
            else return 0;
            x = entry->x;
            z = entry->z;
            angle = entry->angle;
        } else {
            if (GetNodeAtDepth020196fc(self, 4))
                node = GetNodeAtDepth020196fc(self, 4)->scene->terrain;
            else return 0;
            x = entry->angle;
            z = entry->specialZ;
            angle = entry->z;
        }
        if (!node) return 0;
        if (!node->geometry) return 0;
        if (node->flags & 4) return 0;
        TerrainNode* parent = node->parent;
        while (parent) {
            if (parent->flags & 4) return 0;
            parent = parent->parent;
        }
        void* polygons = node->geometry->polygons;
        if (!polygons) return 0;
        TerrainProbe local;
        Vector3i origin;
        Matrix3x3 rotation;
        local.upper = object->position_;
        StoreThreeWordsAt0x0020130a8(&origin.x, x, 0, z);
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
    TerrainNode* node = self->terrain[index];
    if (!node->geometry) return 0;
    if (node->flags & 4) return 0;
    TerrainNode* parent = node->parent;
    while (parent) {
        if (parent->flags & 4) return 0;
        parent = parent->parent;
    }
    if (node->flags & 1) return 0;
    void* polygons = node->geometry->polygons;
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
