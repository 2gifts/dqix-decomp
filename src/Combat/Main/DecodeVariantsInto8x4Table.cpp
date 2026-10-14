#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

extern short data_02109970[8][4];

// USA: func_02099b7c
ARM int DecodeVariantsInto8x4Table(struct Variant02030b0c* arg) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            data_02109970[i][j] = ((Script::Parameter*)arg)->ToInt();
            arg = (struct Variant02030b0c*)((char*)arg + 8);
        }
    }
    return 1;
}
