#include <globaldefs.h>
#include <System/Matrix.h>

#define REG_DIV_NUMER (*(uint64_t*)0x04000290)
#define REG_DIV_DENOM (*(uint64_t*)0x04000298)

static inline void StartDivision64_32SameMode(uint64_t numerator, unsigned long denominator)
{
    REG_DIV_NUMER = numerator;
    REG_DIV_DENOM = denominator;
}

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c29ec
extern "C" ARM void Mat4x4_WriteProjectionUnknown(fix32_t top, fix32_t bottom, fix32_t left, fix32_t right, fix32_t near,
                                                  fix32_t far, fix32_t scaleW, Matrix4x4* out)
{
    int64_t inverseWidth;
    int64_t inverseHeight;
    int64_t inverseDepth;

    fix32_QueueComputeReciprocal(right - left);

    out->entries[1] = 0;
    out->entries[2] = 0;
    out->entries[3] = 0;
    out->entries[4] = 0;
    out->entries[6] = 0;
    out->entries[7] = 0;
    out->entries[8] = 0;
    out->entries[9] = 0;
    out->entries[11] = 0;
    out->entries[15] = scaleW;

    inverseWidth = GetHardwareDividerResult();
    StartDivision64_32SameMode((uint64_t)0x1000 << 32, top - bottom);
    if (scaleW != 0x1000)
    {
        inverseWidth = (inverseWidth * scaleW) / 0x1000;
    }
    out->entries[0] = (long)((0x2000 * inverseWidth + 0x80000000LL) >> 32);

    inverseHeight = GetHardwareDividerResult();
    StartDivision64_32SameMode((uint64_t)0x1000 << 32, near - far);
    if (scaleW != 0x1000)
    {
        inverseHeight = (inverseHeight * scaleW) / 0x1000;
    }
    out->entries[5] = (long)((0x2000 * inverseHeight + 0x80000000LL) >> 32);

    inverseDepth = GetHardwareDividerResult();
    if (scaleW != 0x1000)
    {
        inverseDepth = (inverseDepth * scaleW) / 0x1000;
    }
    out->entries[10] = (long)((0x2000 * inverseDepth + 0x80000000LL) >> 32);

    out->entries[12] = (long)((-(right + left) * inverseWidth + 0x80000000LL) >> 32);
    out->entries[13] = (long)((-(top + bottom) * inverseHeight + 0x80000000LL) >> 32);
    out->entries[14] = (long)(((far + near) * inverseDepth + 0x80000000LL) >> 32);
}
