#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1fa7
#else
#define REGION_OFFSET_0 0x1d6f
#endif


struct Container020dedd0;
struct Element020de650;
Element020de650* FindElementByKey020dedd0(Container020dedd0* c, int key);

// USA: func_ov000_021815e4
ARM struct Element020de650* FindElementByComputedKey021815e4(char* base) {
    signed char idx = *(signed char*)(base + REGION_OFFSET_0);
    short key = *(short*)(base + idx * 2 + 0x26);
    return FindElementByKey020dedd0((Container020dedd0*)(base + 0x100), key);
}
