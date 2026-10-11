#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" int func_ov017_0218b5b0(void);
void ResetOrFindStopwatch(unsigned char* obj, int id);
extern "C" void func_0202738c(void* a, int b, int c, int d);

// JPN: func_ov017_021c64e4
// USA: func_ov017_021c6034
ARM void ResetStopwatchesUnlessCurrent_021c6034(signed char* arr) {
#if defined(jpn)
 enum {regionalOffset0=0x4c0};
#else
 enum {regionalOffset0=0x6d0};
#endif
    struct SearchStruct0202c1a4* obj = (struct SearchStruct0202c1a4*)func_0202ae18();
    signed char idx = GetSearchStructCurrentArrEntry(obj);
    if (arr[idx] == 1) return;
    int t = func_ov017_0218b5b0() + 0x3000;
    unsigned char* r5 = *(unsigned char**)(t + regionalOffset0);
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 1) {
            ResetOrFindStopwatch(r5, i);
            func_0202738c(r5, 1, 1, i);
        }
    }
}
