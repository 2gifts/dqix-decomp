#include <globaldefs.h>

struct SearchStruct;
extern "C" struct SearchStruct* func_0202ae18(void);
extern "C" int func_0202c540(struct SearchStruct* obj);
int TestFlagBitAt0xe_0202c578(struct SearchStruct* obj, int value);

// USA: func_ov017_021959b4  (semantic: CheckFlagAndBitAt14_021959b4)
extern "C" ARM int func_ov017_021959b4(void) {
    struct SearchStruct* search = func_0202ae18();
    if (func_0202c540(search)) {
        if (TestFlagBitAt0xe_0202c578(search, 0) != 0) return 1;
    }
    return 0;
}
