#include <globaldefs.h>
#include "Graphics/Vector.h"

struct GeometryTriangle { Vector3fix vertices[3]; Vector3fix normal; };
extern "C" {
    int func_02031b84(const Vector3fix*, const Vector3fix*, const Vector3fix*,
                    const Vector3fix*, const Vector3fix*, const Vector3fix*,
                    fix32_t*, fix32_t*, fix32_t*, fix32_t*);
    int func_02032090(const Vector3fix*, const Vector3fix*, const Vector4fix*, fix32_t*, Vector3fix*);
}
extern "C" ARM int func_020319d8(const GeometryTriangle* triangles, int count,
                                 const Vector3fix* start, const Vector3fix* end, Vector3fix* point)
{
    int best = -1;
    fix32_t bestHeight;
    for (int index = 0; index < count; ++index) {
        const GeometryTriangle* triangle = &triangles[index];
        if (triangle->normal.y <= 0x800) {
            fix32_t a, b, c, parameter;
            if (func_02031b84(start, end, &triangle->vertices[0], &triangle->vertices[1],
                             &triangle->vertices[2], &triangle->normal, &a, &b, &c, &parameter) == 1) {
                int64_t productB = (int64_t)triangle->vertices[1].y * b + 0x800;
                int64_t productA = (int64_t)triangle->vertices[0].y * a + 0x800;
                int64_t productC = (int64_t)triangle->vertices[2].y * c + 0x800;
                fix32_t weightedB = (fix32_t)(productB >> 12);
                fix32_t weightedA = (fix32_t)(productA >> 12);
                fix32_t weightedC = (fix32_t)(productC >> 12);
                fix32_t sum = weightedA + weightedB;
                fix32_t height = weightedA + weightedB + weightedC;
                if (best < 0 || bestHeight < height) {
                    bestHeight = height;
                    best = index;
                }
            }
        }
    }
    if (best >= 0) {
        const GeometryTriangle* triangle = &triangles[best];
        Vector4fix normalPlane;
        Vector3fix secondEdge;
        Vector3fix firstEdge;
        Vector4fix crossPlane;
        fix32_t parameter;
        normalPlane.xyz = triangle->normal;
        normalPlane.w = Vector3fix_InnerProduct(&normalPlane.xyz, &triangle->vertices[0]);
        Vector3fix_Subtract(&triangle->vertices[1], &triangle->vertices[0], &firstEdge);
        Vector3fix_Subtract(&triangle->vertices[2], &triangle->vertices[0], &secondEdge);
        Vector3fix_CrossProduct(&firstEdge, &secondEdge, &crossPlane.xyz);
        crossPlane.w = Vector3fix_InnerProduct(&crossPlane.xyz, &triangle->vertices[0]);
        if (func_02032090(start, end, &crossPlane, &parameter, point) == 0)
            best = -1;
    }
    return best;
}
