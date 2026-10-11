#include <globaldefs.h>

struct DataLimit02175348 { int f0; int limit; };
extern struct DataLimit02175348 data_ov000_02184288;

#if defined(jpn)
enum { groupArrayOffset = 0x1f54 };
#else
enum { groupArrayOffset = 0x1d1c };
#endif

// USA: func_ov000_0217538c  (semantic: CountDistinctGroups_0217538c)
// JPN: func_ov000_02176754
extern "C" ARM int func_ov000_0217538c(void* objRaw) {
    char* obj = (char*)objRaw;
    int tracked = -1;
    int count = 0;
    for (int i = 0; i < data_ov000_02184288.limit; i++) {
        int v = *(int*)(obj + i * 4 + groupArrayOffset);
        if (tracked != v) {
            tracked = v;
            count++;
        }
    }
    return count;
}
