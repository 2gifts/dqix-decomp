#include <globaldefs.h>

void ClearBytes0x50To0x53_02012780(unsigned char* obj);

// USA: func_020127cc
ARM void SetCompareFlags0x50To0x53_020127cc(unsigned char* obj) {
    ClearBytes0x50To0x53_02012780(obj);
    if (*(int*)(obj + 0x38) < *(unsigned short*)(obj + 0x20)) obj[0x53] = 1;
    if (*(int*)(obj + 0x38) > *(unsigned short*)(obj + 0x20)) obj[0x51] = 1;
    if (*(int*)(obj + 0x3c) < *(unsigned short*)(obj + 0x22)) obj[0x52] = 1;
    if (*(int*)(obj + 0x3c) > *(unsigned short*)(obj + 0x22)) obj[0x50] = 1;
}
