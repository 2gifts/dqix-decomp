#include <globaldefs.h>

void* GetPointerAt0xbf0_0207c60c(void* base, unsigned int index);
signed short GetShortFromArray0xc10_0207c620(unsigned char* base, unsigned int index);

// USA: func_0207c72c
ARM short GetNthPositiveEntryValue_0207c72c(void* base, unsigned int index, short target) {
    signed char* arr = (signed char*)GetPointerAt0xbf0_0207c60c(base, index);
    if (arr == NULL) return 0;
    short count = 0;
    short bound = GetShortFromArray0xc10_0207c620((unsigned char*)base, index);
    unsigned int i;
    for (i = 0; i < bound; i++) {
        if (*arr > 0) {
            if (target == count) return *arr;
            count++;
        }
        arr++;
    }
    return 0;
}
