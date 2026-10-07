#include <globaldefs.h>
#include "Graphics/Vector.h"

// Geometric role inferred from vector operations; retain the original entry name.
extern "C" ARM fix32_t func_02031468(const Vector3fix* start, const Vector3fix* end,
                                     const Vector3fix* point, Vector3fix* closest)
{
    fix32_t length = Vector3fix_Distance(start, end);
    fix32_t distance = Vector3fix_Distance(start, point);
    if (length == 0) {
        *closest = *point;
        return distance;
    }
    if (distance == 0) {
        *closest = *point;
        return 0;
    }
    Vector3fix direction;
    Vector3fix offset;
    Vector3fix_Subtract(end, start, &direction);
    Vector3fixMultiplyScalar(&direction, fix32_Divide(0x1000, length), &direction);
    Vector3fix_Subtract(point, start, &offset);
    Vector3fixMultiplyScalar(&offset, fix32_Divide(0x1000, distance), &offset);
    fix32_t dot = Vector3fix_InnerProduct(&direction, &offset);
    if (dot <= 0) {
        *closest = *start;
        return distance;
    }
    fix32_t projected = FIX32_MULTIPLY(distance, dot);
    if (length < projected) {
        *closest = *end;
        return Vector3fix_Distance(point, end);
    }
    Vector3fixMultiplyScalar(&direction, projected, closest);
    Vector3fix_Add(closest, start, closest);
    return Vector3fix_Distance(point, closest);
}
