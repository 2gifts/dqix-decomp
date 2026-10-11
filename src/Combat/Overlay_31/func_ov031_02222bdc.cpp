#include <globaldefs.h>

struct FlagObj0223da58;
struct Owner02222bdc {
    void* payload;
    FlagObj0223da58* flagged;
};
extern "C" Owner02222bdc* data_ov031_02250ba4;
namespace DuplicatePool {
    extern "C" Owner02222bdc* data_ov031_02250ba4;
}
int TailCallForward_0223e2e0(int, void*);
extern "C" int func_ov031_0223da58(FlagObj0223da58*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_02222bdc
extern "C" ARM void func_ov031_02222bdc(void) {
    TailCallForward_0223e2e0(1, data_ov031_02250ba4->payload);
    func_ov031_0223da58(data_ov031_02250ba4->flagged);
    func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02250ba4);
}
