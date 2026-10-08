#ifndef DQIX_NSBXX_PIVOT_MATRIX_LOOKUP_H
#define DQIX_NSBXX_PIVOT_MATRIX_LOOKUP_H

#include "std_library_functions.h"

#if defined(jpn)
#define data_020e9260 data_020e936c
#define data_020e9284 data_020e9390
#endif

// Four byte-sized matrix-entry positions for each pivot form (0 through 8).
struct NSBXXPivotMatrixLookupEntry
{
    uint8_t a, b, c, d;
};

extern NSBXXPivotMatrixLookupEntry const data_020e9260[], data_020e9284[];

#endif
