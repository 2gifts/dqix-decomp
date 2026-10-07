#include <globaldefs.h>
#include "Graphics/Vector.h"

extern "C" ARM int func_02031b84(const Vector3fix* start, const Vector3fix* end,
                                 const Vector3fix* a, const Vector3fix* b,
                                 const Vector3fix* c, const Vector3fix* unusedNormal,
                                 fix32_t* weightA, fix32_t* weightB, fix32_t* weightC,
                                 fix32_t* parameter)
{
    Vector3fix edgeAB, edgeAC, direction, normal, relative, cross;
    Vector3fix_Subtract(b, a, &edgeAB);
    Vector3fix_Subtract(c, a, &edgeAC);
    Vector3fix_Subtract(start, end, &direction);
    Vector3fix_CrossProduct(&edgeAB, &edgeAC, &normal);
    fix32_t determinant = Vector3fix_InnerProduct(&direction, &normal);
    if (determinant <= 0)
        return 0;
    Vector3fix_Subtract(start, a, &relative);
    *parameter = Vector3fix_InnerProduct(&relative, &normal);
    if (*parameter < 0)
        return 0;
    if (*parameter > determinant)
        return 0;
    Vector3fix_CrossProduct(&direction, &relative, &cross);
    *weightB = Vector3fix_InnerProduct(&edgeAC, &cross);
    if (*weightB < 0 || *weightB > determinant)
        return -1;
    *weightC = -Vector3fix_InnerProduct(&edgeAB, &cross);
    if (*weightC < 0 || *weightB + *weightC > determinant)
        return -1;
    fix32_t reciprocal = fix32_Divide(0x1000, determinant);
    *parameter = FIX32_MULTIPLY(*parameter, reciprocal);
    *weightB = FIX32_MULTIPLY(*weightB, reciprocal);
    *weightC = FIX32_MULTIPLY(*weightC, reciprocal);
    *weightA = 0x1000 - *weightB - *weightC;
    return 1;
}
