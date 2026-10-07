#include <globaldefs.h>
#include "Graphics/Vector.h"

static inline fix32_t RoundedRegionProduct(fix32_t a, fix32_t b)
{
    int64_t product = (int64_t)a * (int64_t)b;
    return (fix32_t)((product + (int64_t)0x800) >> 12);
}

// Keep widened dot products: their spill/reload behavior is present in the original.
extern "C" ARM Vector3fix func_02031d20(const Vector3fix* point, const Vector3fix* a,
                                        const Vector3fix* b, const Vector3fix* c)
{
    Vector3fix ab, ac, ap;
    Vector3fix_Subtract(b, a, &ab);
    Vector3fix_Subtract(c, a, &ac);
    Vector3fix_Subtract(point, a, &ap);
    fix32_t d1 = Vector3fix_InnerProduct(&ab, &ap);
    fix32_t d2 = Vector3fix_InnerProduct(&ac, &ap);
    if (d1 <= 0 && d2 <= 0)
        return *a;
    Vector3fix bp;
    Vector3fix_Subtract(point, b, &bp);
    fix32_t d3 = Vector3fix_InnerProduct(&ab, &bp);
    fix32_t d4 = Vector3fix_InnerProduct(&ac, &bp);
    if (d3 >= 0 && d4 <= d3)
        return *b;
    fix32_t vc = RoundedRegionProduct(d1, d4) - RoundedRegionProduct(d3, d2);
    if (vc <= 0 && d1 >= 0 && d3 <= 0) {
        fix32_t v = fix32_Divide((fix32_t)d1, (fix32_t)(d1 - d3));
        Vector3fix result;
        Vector3fixMultiplyScalar(&ab, v, &result);
        Vector3fix_Add(a, &result, &result);
        return result;
    }
    Vector3fix cp;
    Vector3fix_Subtract(point, c, &cp);
    fix32_t d5 = Vector3fix_InnerProduct(&ab, &cp);
    fix32_t d6 = Vector3fix_InnerProduct(&ac, &cp);
    if (d6 >= 0 && d5 <= d6)
        return *c;
    fix32_t vb = RoundedRegionProduct(d5, d2) - RoundedRegionProduct(d1, d6);
    if (vb <= 0 && d2 >= 0 && d6 <= 0) {
        fix32_t w = fix32_Divide((fix32_t)d2, (fix32_t)(d2 - d6));
        Vector3fix result;
        Vector3fixMultiplyScalar(&ac, w, &result);
        Vector3fix_Add(a, &result, &result);
        return result;
    }
    fix32_t va = RoundedRegionProduct(d3, d6) - RoundedRegionProduct(d5, d4);
    if (va <= 0 && d4 - d3 >= 0 && d5 - d6 >= 0) {
        fix32_t w = fix32_Divide((fix32_t)(d4 - d3), (fix32_t)((d4 - d3) + (d5 - d6)));
        Vector3fix result;
        Vector3fix_Subtract(c, b, &result);
        Vector3fixMultiplyScalar(&result, w, &result);
        Vector3fix_Add(b, &result, &result);
        return result;
    }
    return *point;
}
