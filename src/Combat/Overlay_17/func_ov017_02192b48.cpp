#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct GeometryTriangle {
    Vector3fix vertices[3];
    Vector3fix normal;
};

struct CopySrc02033edc {
    Vector3fix vertices[3];
    Vector3fix normal;
};

struct CopyDst02033edc;

struct FourHalfwords02033f7c {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
};

struct PolygonHeader {
    int type;
};

struct PolygonData {
    PolygonHeader* header;
    unsigned char pad_4[0x10];
    FourHalfwords02033f7c* materials;
};

struct GeometryData {
    int unused;
    PolygonData* polygons;
};

struct TerrainNode {
    unsigned char pad_0[0x24];
    GeometryData* geometry;
};

struct SceneNode {
    unsigned char pad_0[0x2c];
    TerrainNode* terrain;
};

struct Node02192b48 {
    unsigned char pad_0[0x44];
    SceneNode* scene;
};

struct SceneEntry {
    Node02192b48* node;
    unsigned char pad_4[0x44];
};

struct Zone02192b48 {
    unsigned short id;
#if defined(jpn)
    unsigned char pad_2[0x440 - 0x2];
#else
    unsigned char pad_2[0x420 - 0x2];
#endif
    SceneEntry* scenes;
    unsigned char pad_424[0x824 - 0x424];
    TerrainNode** terrain;
    unsigned char pad_828[0x23b8 - 0x828];
    unsigned char useScenes;
};

struct TerrainGrid {
    short cells[96][12];
    int unused900;
    int scale;
    Vector3i position;
    int unused914;
    int angle;
    int unused91c;
    unsigned char materialIndex[96];
};

struct Probe02192b48 {
    Vector3i top;
    Vector3i bottom;
};

class Actor02192b48 : public Object3D {
public:
    short fieldAC;
    unsigned char pad_ae[0xd4 - 0xae];
    Vector3i fieldD4;
    unsigned char flagsE0;
};

extern int data_ov017_021d62d8[8];
extern int data_ov017_021d62f8[8];

extern "C" void* func_02012fe4(void);
extern "C" void func_02031188(GeometryTriangle* dst, short* src);
extern "C" long long func_020c32f8(int);
extern "C" long long func_020c3260(int);
extern "C" float func_0200c700(long long);
extern "C" int func_020312bc(GeometryTriangle* triangles, int count, Vector3fix* start, Vector3fix* end, Vector3fix* point);
extern "C" int func_020315b8(GeometryTriangle* triangles, int count, Vector3fix* originalPosition, fix32_t radius, Vector3fix* position, Vector3i* backupPosition);
void CopyFourHalfwordsToField0x114(void* obj, FourHalfwords02033f7c* src);
void SetFlag0x80AndCopyToField0x11c(void* obj, FourHalfwords02033f7c* src);
void CopyBlocksSetFlag0x40(CopyDst02033edc* dst, CopySrc02033edc* src);

// USA: func_ov017_02192b48
extern "C" ARM int func_ov017_02192b48(TerrainGrid* grid, Probe02192b48* probe, int count, Actor02192b48* self, unsigned char applyMaterial, Vector3i* dest, Vector3i* pos, int* y, int* yLow, int enable, int* reset, unsigned char inCell, int index, int hidden) {
    GeometryTriangle samples[96];
    GameState* gs;
    Zone02192b48* zone;
    int total;
    int threshold;
    int i;

    gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    zone = (Zone02192b48*)func_02012fe4();
    total = 0;
    for (i = 0; i < count; i++) {
        func_02031188(&samples[i], grid->cells[i]);
        Vector3fixMultiplyScalar(&samples[i].vertices[0], grid->scale << 12, &samples[i].vertices[0]);
        Vector3fixMultiplyScalar(&samples[i].vertices[1], grid->scale << 12, &samples[i].vertices[1]);
        Vector3fixMultiplyScalar(&samples[i].vertices[2], grid->scale << 12, &samples[i].vertices[2]);
    }
    Vector3i local = *pos;
    Matrix3x3 rotation;
    Vector3i top;
    Vector3i bottom;
    Vector3i hit;
    Vector3fix_Subtract(&local, &grid->position, &local);
    int rotationAngle = -(grid->angle - 25735);
    int cosine = (int)(4096.0f * (func_0200c700(func_020c32f8(rotationAngle)) / 4294967296.0f));
    int sine = (int)(4096.0f * (func_0200c700(func_020c3260(rotationAngle)) / 4294967296.0f));
    Mat3x3_WriteRotationY(&rotation, sine, cosine);
    Mat3x3_ApplyToVector(&local, &rotation, &local);
    top = local;
    top.y += 0x1800;
    bottom = local;
    bottom.y -= 0xa000;

    if (!(self->GetFlags() & 0x100)) {
        int idx = func_020312bc(samples, count, &top, &bottom, &hit);
        if (idx != -1) {
            hit.y += 0x199;
            Vector3fix_Add(&hit, &grid->position, &hit);
            if (*yLow < hit.y) {
                threshold = 0x800;
                if (zone->id == 0x1131) {
                    unsigned int ticks = gs->GetTickCount();
                    if (ticks > 10) {
                        ticks = 10;
                    }
                    threshold = (int)(4096.0f * (0.1f + 0.25f * (float)ticks));
                }
                if (*y - hit.y < threshold || (hidden && *y - hit.y < 0x1800)) {
                    if (hit.y < *y || fix32abs(*y - hit.y) < 0x1000 || hidden) {
                        *reset = 1;
                        pos->y = *y;
                        self->position_ = *pos;
                        *yLow = hit.y;
                        if (fix32abs(*y - hit.y) > 0x28) {
                            pos->y = hit.y;
                            self->position_ = *pos;
                        }
                        if (hidden) {
                            self->fieldD4 = *pos;
                            self->flagsE0 |= 0x20;
                        }
                        self->fieldAC = 0;
                        if (inCell) {
                            TerrainNode* node;
                            if (zone->useScenes == 0) {
                                node = zone->terrain[index];
                            } else {
                                node = zone->scenes[index].node->scene->terrain;
                            }
                            GeometryData* geometry;
                            PolygonData* polygons;
                            if (node != NULL && (geometry = node->geometry) != NULL && (polygons = geometry->polygons) != NULL) {
                                if (polygons->header->type == 3) {
                                    FourHalfwords02033f7c material = polygons->materials[grid->materialIndex[idx]];
                                    CopyFourHalfwordsToField0x114(self, &material);
                                }
                            }
                        }
                    }
                } else {
                    int clear = 1;
                    for (int k = 0; k < 8 && clear; k++) {
                        int dx = data_ov017_021d62d8[k];
                        int dz = data_ov017_021d62f8[k];
                        Vector3i stepTop = top;
                        stepTop.x += dx;
                        stepTop.z += dz;
                        Vector3i stepBottom = bottom;
                        stepBottom.x += dx;
                        stepTop.z += dz;
                        Vector3i stepHit;
                        if (func_020312bc(samples, count, &stepTop, &stepBottom, &stepHit) != -1) {
                            stepHit.y += 0x199;
                            Vector3fix_Add(&stepHit, &grid->position, &stepHit);
                            if (*y > stepHit.y && *y - stepHit.y < threshold) {
                                clear = 0;
                            }
                        }
                    }
                    if (clear) {
                        *reset = 0;
                    }
                }
            }
        }
    }

    if (enable && !(self->GetFlags() & 0x80)) {
        Vector3i center = local;
        center.y += 0x800;
        int radius = 0x800;
        if (self->unknown_0_ & 0x20) {
            int scaled = self->GetRadius() >> 2;
            if (scaled > 0x800) {
                radius = scaled;
            }
        }
        int idx = func_020315b8(samples, count, &center, radius, &hit, dest);
        if (idx >= 0) {
            Mat3x3_Invert(&rotation, &rotation);
            Mat3x3_ApplyToVector(&hit, &rotation, &hit);
            pos->x = hit.x + grid->position.x;
            pos->z = hit.z + grid->position.z;
            self->position_ = *pos;
            total++;
            CopySrc02033edc triangle;
            Vector3fix_Add(&samples[idx].vertices[0], &grid->position, &triangle.vertices[0]);
            Vector3fix_Add(&samples[idx].vertices[1], &grid->position, &triangle.vertices[1]);
            Vector3fix_Add(&samples[idx].vertices[2], &grid->position, &triangle.vertices[2]);
            triangle.normal = samples[idx].normal;
            CopyBlocksSetFlag0x40((CopyDst02033edc*)self, &triangle);
            if (applyMaterial && inCell) {
                TerrainNode* node;
                if (zone->useScenes == 0) {
                    node = zone->terrain[index];
                } else {
                    node = zone->scenes[index].node->scene->terrain;
                }
                GeometryData* geometry;
                PolygonData* polygons;
                if (node != NULL && (geometry = node->geometry) != NULL && (polygons = geometry->polygons) != NULL) {
                    if (polygons->header->type == 3) {
                        FourHalfwords02033f7c material = polygons->materials[grid->materialIndex[idx]];
                        SetFlag0x80AndCopyToField0x11c(self, &material);
                    }
                }
            }
        }
    }
    return total;
}
