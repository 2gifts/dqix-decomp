#include <globaldefs.h>

void* GetPointerAt0xbf0_0207c60c(void* base, unsigned int index);
signed short GetShortFromArray0xc10_0207c620(unsigned char* base, unsigned int index);

// USA: func_0207c638
ARM short CountPositiveEntries0207c638(void* base, unsigned int index) {
    signed char* arr = (signed char*)GetPointerAt0xbf0_0207c60c(base, index);
    short count = GetShortFromArray0xc10_0207c620((unsigned char*)base, index);
    short result = 0;
    short i;
    for (i = 0; i < count; i++) {
        if (arr[i] > 0) result++;
    }
    return result;
}
