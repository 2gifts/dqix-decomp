#include <globaldefs.h>
#include "Graphics/GlyphMetrics.h"

// USA: func_02028d68
ARM void SetStructFieldsFromCode02028d68(int code) {
    data_020ef74c.displayMode = code;
    if (code == 0) {
        data_020ef74c.rowHeight = 8;
        data_020ef74c.columnWidth = 8;
        return;
    }
    if ((unsigned int)(code - 1) <= 1) {
        data_020ef74c.columnWidth = 6;
        data_020ef74c.rowHeight = 0xc;
        return;
    }
    if ((unsigned int)(code - 3) <= 1) {
        data_020ef74c.columnWidth = 5;
        data_020ef74c.rowHeight = 0xa;
        return;
    }
    if ((unsigned int)(code - 5) <= 1) {
        data_020ef74c.columnWidth = 6;
        data_020ef74c.rowHeight = 0xc;
    }
}
