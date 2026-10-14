#include <globaldefs.h>
// USA: func_0207c620
ARM signed short GetShortFromArray0xc10_0207c620(unsigned char *base, unsigned int index) {
    if (index > 7) return -1;
    return *(signed short*)(base + 0xc10 + index * 2);
}
