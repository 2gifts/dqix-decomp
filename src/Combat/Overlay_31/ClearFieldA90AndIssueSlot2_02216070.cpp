#include <globaldefs.h>

extern void* data_ov031_0224e5d8;

int IssueBattleCommandSlot2_020d503c(int arg);

// USA: func_ov031_02216070  (semantic: ClearFieldA90AndIssueSlot2_02216070)
extern "C" ARM int func_ov031_02216070(int arg) {
    if (arg == 0) {
        return -1;
    }
    *(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa90) = 3;
    data_ov031_0224e5d8 = 0;
    int r = IssueBattleCommandSlot2_020d503c(arg);
    return (r == 2) ? 0 : r;
}
