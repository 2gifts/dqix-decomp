#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;

struct Tally02108d70 {
    unsigned char forceFlag;
    unsigned char pad1[0xf];
    int matchCount;
    unsigned char pad2[8];
    int targetValue;
};

extern struct Tally02108d70 data_02108d70;

// USA: func_02071004
ARM int TallyMatchingVariant02071004(struct Variant02030b0c* p) {
    int value = ((Script::Parameter*)p)->ToInt();
    if (data_02108d70.targetValue == value || data_02108d70.forceFlag != 0) {
        data_02108d70.matchCount++;
    }
    return 1;
}
