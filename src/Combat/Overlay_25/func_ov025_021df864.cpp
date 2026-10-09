#include <globaldefs.h>

#include "Graphics/Vector.h"
#include "World/Object3D.h"

struct TrailSegment {
    unsigned char distance;
    unsigned char alpha;
};

struct TrailEffect {
    Object3D mainObj;
    Object3D subObj;
    Vector3fix direction;
    Vector3fix origin;
    int field_170;
    unsigned char mode;
    char pad_175;
    TrailSegment segments[10];
};

// USA: func_ov025_021df864
extern "C" ARM void func_ov025_021df864(TrailEffect* fx) {
    int i;
    int isMain;
    if (fx->mode <= 3) {
        isMain = 1;
    } else {
        isMain = 0;
    }
    if (isMain) {
        for (i = 0; i < 10; i++) {
            TrailSegment* seg = &fx->segments[i];
            if (seg->alpha != 0) {
                Vector3fix pos;
                Vector3fixMultiplyScalar(&fx->direction, seg->distance << 12, &pos);
                Vector3fix_Add(&fx->origin, &pos, &pos);
                pos.y = 0x400;
                Object3D* obj = &fx->mainObj;
                obj->position_ = pos;
                obj->SetInheritedAlpha(seg->alpha);
                obj->DrawMeshWithMaterial(true, 0, 0, 1);
            }
        }
    } else {
        for (i = 0; i < 10; i++) {
            TrailSegment* seg = &fx->segments[i];
            if (seg->alpha != 0) {
                Vector3fix pos;
                Vector3fixMultiplyScalar(&fx->direction, seg->distance << 12, &pos);
                Vector3fix_Add(&fx->origin, &pos, &pos);
                pos.y = 0x400;
                Object3D* obj = &fx->subObj;
                obj->position_ = pos;
                obj->SetInheritedAlpha(seg->alpha);
                obj->DrawMeshWithMaterial(true, 0, 0, 1);
            }
        }
    }
}
