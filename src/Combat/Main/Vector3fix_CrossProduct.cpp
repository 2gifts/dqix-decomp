#include <globaldefs.h>
#include <System/Matrix.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c2e34
extern "C" ARM void Vector3fix_CrossProduct(const Vector3fix* a, const Vector3fix* b, Vector3fix* out)
{
    int bz = b->z;
    int ax = a->x;
    int az = a->z;
    int bx = b->x;
    int ay = a->y;
    int by = b->y;
    out->x = (int)(((long long)ay * bz - (long long)az * by + 0x800) >> 12);
    out->y = (int)(((long long)az * bx - (long long)ax * bz + 0x800) >> 12);
    out->z = (int)(((long long)ax * by - (long long)ay * bx + 0x800) >> 12);
}
