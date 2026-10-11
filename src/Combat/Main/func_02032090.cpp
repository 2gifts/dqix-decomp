#include <globaldefs.h>
#include "Graphics/Vector.h"

// USA: func_02032090
extern "C" ARM int func_02032090(const Vector3fix* start, const Vector3fix* end,
                                 const Vector4fix* plane, fix32_t* parameter, Vector3fix* point)
{
    Vector3fix direction;

    Vector3fix_Subtract(end, start, &direction);
    *parameter = fix32_Divide(plane->w - Vector3fix_InnerProduct(&plane->xyz, start),
                              Vector3fix_InnerProduct(&plane->xyz, &direction));
    if (*parameter >= 0 && *parameter <= 0x1000) {
        Vector3fixMultiplyScalar(&direction, *parameter, point);
        Vector3fix_Add(start, point, point);
        return 1;
    }
    return 0;
}
