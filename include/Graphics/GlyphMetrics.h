#pragma once

#include "std_library_functions.h"

// Shared text layout and display mode state. The first halfword is also
// initialized by func_02029568; the following two bytes remain unidentified.
struct GlyphMetrics {
    unsigned short unknown0;
    unsigned char unknown2[2];
    int rowHeight;
    int columnWidth;
    int displayMode;
};

extern GlyphMetrics data_020ef74c;

typedef char GlyphMetricsSizeCheck[sizeof(GlyphMetrics) == 0x10 ? 1 : -1];
typedef char GlyphMetricsRowHeightCheck[offsetof(GlyphMetrics, rowHeight) == 4 ? 1 : -1];
typedef char GlyphMetricsColumnWidthCheck[offsetof(GlyphMetrics, columnWidth) == 8 ? 1 : -1];
typedef char GlyphMetricsDisplayModeCheck[offsetof(GlyphMetrics, displayMode) == 0xc ? 1 : -1];
