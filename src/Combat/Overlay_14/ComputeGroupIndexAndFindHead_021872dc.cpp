#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct ListHeadStruct021874f8;
short CountLinkedListNodes_021874f8(struct ListHeadStruct021874f8* obj);
struct S02187520;
short FindIndexDiv16_02187520(struct S02187520* obj);
struct Node02187340;
extern "C" struct Node02187340* func_ov014_02187340(void* obj, int target);

// USA: func_ov014_021872dc  (semantic: ComputeGroupIndexAndFindHead_021872dc)
extern "C" ARM struct Node02187340* func_ov014_021872dc(unsigned char* obj, int param1) {
    short count = CountLinkedListNodes_021874f8((struct ListHeadStruct021874f8*)obj);
    int t1 = count + 15;
    int t0 = t1 >> 3;
    int rounded = t1 + ((unsigned int)t0 >> 28);
    int r5 = (rounded << 12) >> 16;

    short idx = FindIndexDiv16_02187520((struct S02187520*)obj);
    short s = (short)(idx + param1);
    if (s < 0) {
        s = (short)(r5 + s);
    }
    if (r5 <= s) {
        s = (short)(s - r5);
    }

    struct Node02187340* ret = func_ov014_02187340(obj, s);
    *(struct Node02187340**)(obj + 0xbc) = ret;
    return ret;
}
