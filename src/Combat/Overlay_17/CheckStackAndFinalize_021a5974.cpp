#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
struct ListHead02046b60;
extern int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void func_ov002_021556fc(int val);
void PopStack0AndTrigger(int flag);
void PopStack1AndTrigger(int flag);
extern "C" void func_ov017_021a55b0(void* self);

extern int data_ov017_021d83ac;

// JPN: func_ov017_021a63ac
// USA: func_ov017_021a5974
ARM void CheckStackAndFinalize_021a5974(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x34ec};
#else
 enum {regionalOffset0=0x36fc};
#endif
    int val = data_ov017_021d83ac;
    if (val != 0) {
        func_ov002_021556fc(val);
        data_ov017_021d83ac = 0;
    }
    int base = func_ov017_0218b5b0();
    struct ListHead02046b60* list = *(struct ListHead02046b60**)(base + regionalOffset0);
    if (list != NULL
        && (ListContainsId(list, 0x2) || ListContainsId(list, 0x2f) || ListContainsId(list, 0x2d)))
    {
        PopStack0AndTrigger(0);
        PopStack1AndTrigger(0);
    } else {
        PopStack0AndTrigger(1);
        PopStack1AndTrigger(1);
    }
    func_ov017_021a55b0(self);
    self[0x1] = 1;
}
