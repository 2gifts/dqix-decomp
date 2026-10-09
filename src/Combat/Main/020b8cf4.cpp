#include <globaldefs.h>
#include "Graphics/NSBXX/NSBXX.h"
#include "Graphics/NSBXX/PivotMatrixLookup.h"

typedef char NSBXXPivotMatrixLookupEntryHasFourBytes[sizeof(NSBXXPivotMatrixLookupEntry) == 4 ? 1 : -1];
typedef char NSBXXPivotMatrixLookupFieldAHasOneByte[sizeof(((NSBXXPivotMatrixLookupEntry*)0)->a) == 1 ? 1 : -1];
typedef char NSBXXPivotMatrixLookupFieldBHasOneByte[sizeof(((NSBXXPivotMatrixLookupEntry*)0)->b) == 1 ? 1 : -1];
typedef char NSBXXPivotMatrixLookupFieldCHasOneByte[sizeof(((NSBXXPivotMatrixLookupEntry*)0)->c) == 1 ? 1 : -1];
typedef char NSBXXPivotMatrixLookupFieldDHasOneByte[sizeof(((NSBXXPivotMatrixLookupEntry*)0)->d) == 1 ? 1 : -1];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020b8cf4
ARM bool GetMatrixFromIndex(Matrix3x3* out, intptr_t pivotList, intptr_t basisList, int index)
{
    if (index & 0x8000)
    {
        out->entries[0] = out->entries[1] = out->entries[2] =
        out->entries[3] = out->entries[4] = out->entries[5] =
        out->entries[6] = out->entries[7] = out->entries[8] = 0;
        NSBXXAnimationJAC::PivotMatrix* pivot = (NSBXXAnimationJAC::PivotMatrix*)(pivotList + (((index & 0x7fff) * 3) << 1));
        fix32_t entryA = pivot->a;
        fix32_t entryB = pivot->b;
        int form = pivot->flags & 0xf;
        out->entries[form] = (pivot->flags & 0x10) ? -(1 << 12) : 1 << 12;
        out->entries[data_020e9284[form].a] = entryA;
        out->entries[data_020e9284[form].b] = entryB;
        fix32_t entryC = (pivot->flags & 0x20) ? -entryB : entryB;
        out->entries[data_020e9284[form].c] = entryC;
        fix32_t entryD = (pivot->flags & 0x40) ? -entryA : entryA;
        out->entries[data_020e9284[form].d] = entryD;
        return false;
    }
    else
    {
        NSBXXAnimationJAC::BasisMatrix* basis = (NSBXXAnimationJAC::BasisMatrix*)(basisList + (((index & 0x7fff) * 5) << 1));
        short accumulation = 0;
        int d4 = basis->data[4];
        out->entries[4] = d4 >> 3;
        accumulation = (accumulation << 3) | (d4 & 7);
        int d0 = basis->data[0];
        out->entries[0] = d0 >> 3;
        accumulation = (accumulation << 3) | (d0 & 7);
        int d1 = basis->data[1];
        out->entries[1] = d1 >> 3;
        accumulation = (accumulation << 3) | (d1 & 7);
        int d2 = basis->data[2];
        out->entries[2] = d2 >> 3;
        accumulation = (accumulation << 3) | (d2 & 7);
        int d3 = basis->data[3];
        out->entries[3] = d3 >> 3;
        accumulation = (accumulation << 3) | (d3 & 7);
        out->entries[5] = (short)(accumulation << 3) >> 3;
        return true;
    }
}
