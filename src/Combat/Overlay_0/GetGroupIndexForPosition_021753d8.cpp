#include <globaldefs.h>

struct DataLimit02175348 { int f0; int limit; };
extern struct DataLimit02175348 data_ov000_02184288;

#if defined(jpn)
enum { groupArrayOffset = 0x1f54 };
#else
enum { groupArrayOffset = 0x1d1c };
#endif

// USA: func_ov000_021753d8  (semantic: GetGroupIndexForPosition_021753d8)
// JPN: func_ov000_021767a0
extern "C" ARM int func_ov000_021753d8(void* objRaw, int targetIndex) {
    char* obj = (char*)objRaw;
    int groupIndex = -1;
    int tracked = -1;
    int i;
    for (i = 0; i < data_ov000_02184288.limit; i++) {
        int v = *(int*)(obj + i * 4 + groupArrayOffset);
        if (tracked != v) {
            tracked = v;
            groupIndex++;
        }
        if (targetIndex == i) break;
    }
    return groupIndex;
}
