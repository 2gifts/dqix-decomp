#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "System/Matrix.h"

struct GeometryTriangle {
    Vector3fix vertices[3];
    Vector3fix normal;
};

extern "C" int func_02031b84(const Vector3fix*, const Vector3fix*, const Vector3fix*,
                              const Vector3fix*, const Vector3fix*, const Vector3fix*,
                              fix32_t*, fix32_t*, fix32_t*, fix32_t*);
extern "C" Vector3fix func_02031d20(const Vector3fix*, const Vector3fix*,
                                    const Vector3fix*, const Vector3fix*);

// Triangle adjustment and backup-position rules; gameplay meanings remain provisional.
extern "C" ARM int func_020315b8(const GeometryTriangle* triangles, int count,
                                  const Vector3fix* originalPosition, fix32_t radius,
                                  Vector3fix* position, const Vector3fix* backupPosition)
{
    int best = -1;
    fix32_t negativeRadius;
    bool hasHit, faceHit;
    int64_t radiusProduct = (int64_t)radius * radius + 0x800;
    fix32_t radiusSquared = (fix32_t)(radiusProduct >> 12);
    *position = *originalPosition;
    Vector3fix previous = *originalPosition;
    Vector3fix initial = *originalPosition;
    Vector3fix previousNormal;
    for (int pass = 0; pass < 2; ++pass) {
        int hitCount = 0;
        negativeRadius = -radius;
        int minusOne = -1;
        for (int index = 0; index < count; ++index) {
            hasHit = false;
            faceHit = false;
            const GeometryTriangle* triangle = &triangles[index];
            Vector3fix positionBefore = *position;
            if (triangle->normal.y > 0x800)
                continue;
            Vector3fix start, end, a, b, c, normal, normalOffset;
            start = *position;
            Vector3fixMultiplyScalar(&triangle->normal, negativeRadius, &normalOffset);
            Vector3fix_Add(&start, &normalOffset, &end);
            a = triangle->vertices[0];
            b = triangle->vertices[1];
            c = triangle->vertices[2];
            normal = triangle->normal;
            fix32_t weightA, weightB, weightC, parameter;
            int result = func_02031b84(&start, &end, &a, &b, &c, &normal,
                                        &weightA, &weightB, &weightC, &parameter);
            if (result == 1 && pass == 0) {
                Vector3fix displacement;
                Vector3fix_Subtract(&end, &start, &displacement);
                Vector3fixMultiplyScalar(&displacement, parameter, &displacement);
                Vector3fix_Add(&start, &displacement, position);
                Vector3fixMultiplyScalar(&normal, radius, &displacement);
                Vector3fix_Add(position, &displacement, position);
                hasHit = true;
                best = index;
                faceHit = true;
                ++hitCount;
            } else if (result == minusOne && pass >= 1) {
                Vector3fix closest;
                closest = func_02031d20(position, &a, &b, &c);
                Vector3fix delta;
                Vector3fix_Subtract(position, &closest, &delta);
                fix32_t ySquared = FIX32_MULTIPLY(delta.y, delta.y);
                fix32_t xSquared = FIX32_MULTIPLY(delta.x, delta.x);
                fix32_t zSquared = FIX32_MULTIPLY(delta.z, delta.z);
                fix32_t sum = xSquared + ySquared;
                fix32_t squaredDistance = xSquared + ySquared + zSquared;
                if (squaredDistance < radiusSquared) {
                    fix32_t scale = fix32_Divide(radius, fix32_Sqrt(squaredDistance));
                    Vector3fixMultiplyScalar(&delta, scale, &delta);
                    Vector3fix_Add(&closest, &delta, position);
                    hasHit = true;
                    if (best == minusOne)
                        best = index;
                }
            }
            if (!hasHit)
                continue;
            normal = triangle->normal;
            if (backupPosition) {
                Vector3fix adjustedBackup = *backupPosition;
                adjustedBackup.y = originalPosition->y;
                if (Vector3fix_Distance(position, &previous) > 4) {
                    fix32_t alignment = Vector3fix_InnerProduct(&normal, &previousNormal);
                    if (alignment < 0xfd7 && alignment > 0x800) {
                        Vector3fix oldDirection, newDirection;
                        Vector3fix_Subtract(&adjustedBackup, &previous, &oldDirection);
                        Vector3fix_Subtract(&adjustedBackup, position, &newDirection);
                        fix32_t dot = Vector3fix_InnerProduct(&oldDirection, &newDirection);
                        fix32_t distance = Vector3fix_Distance(&oldDirection, &newDirection);
                        if (dot < distance * 0x4cc) {
                            Vector3fix beforeDirection;
                            Vector3fix_Subtract(&adjustedBackup, &initial, &beforeDirection);
                            fix32_t oldDot = Vector3fix_InnerProduct(&oldDirection, &beforeDirection);
                            fix32_t newDot = Vector3fix_InnerProduct(&newDirection, &beforeDirection);
                            if (oldDot < 0 || newDot < 0) {
                                position->z = backupPosition->z;
                                position->x = backupPosition->x;
                                return best;
                            }
                        }
                    }
                }
            }
            if (faceHit || hitCount == 0)
                previousNormal = normal;
            previous = positionBefore;
        }
    }
    return best;
}
