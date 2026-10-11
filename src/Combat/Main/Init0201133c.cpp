#if defined(jpn)
#define INIT_PAIR_OFFSET 0x54cc
#else
#define INIT_PAIR_OFFSET 0x572c
#endif
#if defined(jpn)
#define INIT_DATA_OFFSET 0x54d4
#else
#define INIT_DATA_OFFSET 0x5734
#endif
#include <globaldefs.h>
#if defined(jpn)
#define func_0209a3dc func_0209c130
#endif
#include "std_library_functions.h"

struct Pair0209a338;
void ClearFirstTwoWords0209a338(Pair0209a338* p);
extern "C" void func_0209a3dc(void* a, void* b);

// JPN: func_020110b0
// USA: func_0201133c
ARM void Init0201133c(char* obj) {
    memset(obj + INIT_DATA_OFFSET, 0, 0x570);
    ClearFirstTwoWords0209a338((Pair0209a338*)(obj + INIT_PAIR_OFFSET));
    func_0209a3dc(obj + INIT_PAIR_OFFSET, obj + INIT_DATA_OFFSET);
}
