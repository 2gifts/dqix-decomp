#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/Object3D.h"

struct Bounds0218dd18 {
    Vector3fix center;
    fix32_t radius;
};

struct Info0218dd18 {
    char pad0[0x5c];
    Bounds0218dd18* bounds;
};

struct Node0218dd18 {
    unsigned int flags;
    char pad4[0x14];
    Object3D* model;
};

extern "C" Vector3fix _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(Node0218dd18* node);
extern "C" Info0218dd18* _Z19GetField0xc02040538P9S02040538(Node0218dd18* node);
extern "C" void _Z28SetActiveChildFields02040774P12Node02040774iii(Node0218dd18* node, int x, int y, int z);
unsigned int IsFlag0x1ceBit0x8Set(unsigned char* obj);

// USA: func_ov017_0218dd18
extern "C" ARM int func_ov017_0218dd18(Object3D* self, Node0218dd18* node, int pushNode) {
    Vector3fix pos = self->position_;
    Vector3fix target = _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(node);
    if (fix32abs(target.y - pos.y) >= 0x2000) {
        return 0;
    }
    int selfRadius = self->GetRadius() * 0.5f;
    int nodeRadius = 0x800;
    if (node->model != NULL) {
        nodeRadius = node->model->GetRadius() / 2;
    }
    Bounds0218dd18* bounds = _Z19GetField0xc02040538P9S02040538(node)->bounds;
    if (bounds != NULL) {
        nodeRadius = bounds->radius;
        Vector3fix_Add(&target, &bounds->center, &target);
    }
    int reach = selfRadius + nodeRadius;
    if (reach == 0) {
        return 0;
    }
    if (reach < fix32abs(pos.x - target.x)) {
        return 0;
    }
    if (reach < fix32abs(pos.z - target.z)) {
        return 0;
    }
    target.y = pos.y;
    int dist = Vector3fix_Distance(&pos, &target);
    if (reach < dist) {
        return 0;
    }
    if (node->flags & 0x40000) {
        return 0;
    }
    if (!IsFlag0x1ceBit0x8Set((unsigned char*)self)) {
        if (pushNode) {
            reach -= (int)(0.2f * (self->GetRadius() * 0.5f));
            if (reach < dist) {
                return 0;
            }
            Vector3fix delta;
            Vector3fix_Subtract(&target, &pos, &delta);
            Vector3fixMultiplyScalar(&delta, fix32_Divide(reach, dist), &delta);
            Vector3fix_Add(&pos, &delta, &target);
            _Z28SetActiveChildFields02040774P12Node02040774iii(node, target.x, target.y, target.z);
        } else {
            Vector3fix delta;
            Vector3fix_Subtract(&pos, &target, &delta);
            if (dist < selfRadius) {
                dist = selfRadius;
            }
            Vector3fixMultiplyScalar(&delta, fix32_Divide(reach, dist), &delta);
            Vector3fix_Add(&target, &delta, &pos);
            self->position_ = pos;
        }
    }
    return 1;
}
