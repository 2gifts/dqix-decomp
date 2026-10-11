#include <globaldefs.h>

void* GetActiveCombatWork(void);
extern "C" void func_ov000_021626a0(void* self, int a, int b);
struct Obj021eb00c;
void SetFlagField_021eb00c_021eb00c(struct Obj021eb00c* obj);
extern int data_ov025_021ef988;

struct Obj021e4450 {
    char pad[8];
    unsigned char field8;
    unsigned char field9;
};

// JPN: func_ov025_021e4940
// USA: func_ov025_021e4450  (semantic: AdvanceStateAndNotify_021e4450)
extern "C" ARM int func_ov025_021e4450(struct Obj021e4450* self) {
#if defined(jpn)
 enum {regionalOffset0=4};
#else
 enum {regionalOffset0=0xc};
#endif
    void* work = GetActiveCombatWork();
    unsigned char state = self->field8;
    if (state == 5) {
        int flag = (self->field9 == 0) ? 1 : 0;
        func_ov000_021626a0(work, 4, flag);
        state = 0;
    } else if (state == 6) {
        int flag = (self->field9 == 0) ? 1 : 0;
        func_ov000_021626a0(work, 4, flag);
        state = 1;
    }
    void* ptr = *(void**)((char*)&data_ov025_021ef988 + regionalOffset0);
    if (ptr != 0) {
        SetFlagField_021eb00c_021eb00c((struct Obj021eb00c*)ptr);
        ptr = *(void**)((char*)&data_ov025_021ef988 + regionalOffset0);
        *(int*)((char*)ptr + 0x1c4) &= ~0x40;
    }
    func_ov000_021626a0(work, state, self->field9);
    return 1;
}
