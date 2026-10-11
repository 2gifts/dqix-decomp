#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue718_614 = 0x614 };
enum { kRegionValue460_35C = 0x35c };
#else
enum { kRegionValue718_614 = 0x718 };
enum { kRegionValue460_35C = 0x460 };
#endif


extern "C" int func_02001aec(void* a, void* b, int n);

// USA: func_ov003_021725a4  (semantic: CheckAllEntriesMatch_021725a4)
// JPN: func_ov003_02171570
extern "C" ARM int func_ov003_021725a4(void* obj, void* other) {
    int i;
    unsigned int field = *(unsigned int*)((char*)other + 0x6c);
    if (((field << 5) >> 31) == 0) {
        return 0;
    }
    unsigned char count = *((unsigned char*)obj + kRegionValue718_614);
    if (count == 0) {
        return 1;
    }
    for (i = 0; i < count; i++) {
        char* base = (char*)obj + kRegionValue460_35C;
        if (func_02001aec(base + i * 0xe8 + 0x14, (char*)other + 0x14, 6) == 0) {
            return 0;
        }
    }
    return 1;
}
