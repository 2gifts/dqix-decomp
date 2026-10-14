#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern unsigned short data_02109950[8][2];

// USA: func_02099b20
ARM int FillVariantShortTable02109950(Variant02030b0c* p) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 2; j++) {
            data_02109950[i][j] = (unsigned short)((Script::Parameter*)p)->ToInt();
            p++;
        }
    }
    return 1;
}
