#include <globaldefs.h>

extern "C" ARM void func_020c9be0(void);
extern "C" ARM void func_ov031_02239368(int val);
int IssueBattleCommandSlot2_020d503c(int arg);
void SetTagFromFlag2_02239b98(short* p);

struct Inner_0223a47c { unsigned char pad[0x40]; int field40; };
struct Outer_0223a47c { unsigned char pad[4]; struct Inner_0223a47c* inner; };
extern struct Outer_0223a47c data_ov031_02290d18;

// USA: func_ov031_0223a47c
extern "C" ARM int func_ov031_0223a47c(void) {
    if (data_ov031_02290d18.inner->field40 != 1) {
        func_020c9be0();
    }
    func_ov031_02239368(3);
    int r = IssueBattleCommandSlot2_020d503c((int)SetTagFromFlag2_02239b98);
    if (r == 2) {
        return 1;
    }
    func_ov031_02239368(9);
    return 0;
}
