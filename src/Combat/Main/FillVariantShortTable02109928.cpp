#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern unsigned short data_02109928[10][2];

// USA: func_02099ac4
ARM int FillVariantShortTable02109928_02099ac4(Variant02030b0c* p) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 2; j++) {
            data_02109928[i][j] = (unsigned short)((Script::Parameter*)p)->ToInt();
            p++;
        }
    }
    return 1;
}
