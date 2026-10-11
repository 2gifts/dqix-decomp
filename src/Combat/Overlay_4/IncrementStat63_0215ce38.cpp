#if defined(jpn)
#define R(j,u) (j)
#define func_ov004_0215a738 func_ov004_0215b740
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Stat0215ce38 { char pad[0x5c]; short cur; short max; };

extern "C" Stat0215ce38* func_ov004_02156ed0(void* obj, int key);
extern "C" void func_ov004_0215a738(void* obj);

// USA: func_ov004_0215ce38
ARM int IncrementStat63_0215ce38(void* obj) {
    Stat0215ce38* stat = func_ov004_02156ed0(obj, 0x63);
    short cur = stat->cur;
    short max = stat->max;
    short newCur = cur + 1;
    if (max <= newCur) newCur = 0;
    stat->cur = newCur;
    stat->max = max;
    func_ov004_0215a738(obj);
    return 0;
}
