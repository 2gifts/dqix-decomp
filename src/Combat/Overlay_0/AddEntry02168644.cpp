#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x79de
#define REGION_OFFSET_1 0x79c6
#else
#define REGION_OFFSET_0 0x77ee
#define REGION_OFFSET_1 0x77d6
#endif


struct Entry02168268 { signed char a; unsigned char b; short c; short d; };
void ResetEntry02168268(struct Entry02168268* obj);

// USA: func_ov000_02168644
ARM void AddEntry02168644(char* p, int value) {
    unsigned char count = *(unsigned char*)(p + REGION_OFFSET_0);
    *(unsigned char*)(p + REGION_OFFSET_0) = count + 1;
    struct Entry02168268* e = (struct Entry02168268*)(p + REGION_OFFSET_1 + count * 6);
    ResetEntry02168268(e);
    e->a = (signed char)value;
}
