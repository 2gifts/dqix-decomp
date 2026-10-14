#include <globaldefs.h>

void SetField0x48UnlessState9Or10_0202c848(int slot);
void TryIssueBattleCommandAndUpdateState_0202dd28(void);
int IssueBattleCommandSlot9_020d5214(int callback);
int DispatchField0x2OrSetState1_0202cd28(unsigned short*);

struct S0202ccdc {
    char pad0[2];
    unsigned short f2;
};

// USA: func_0202ccdc  (semantic: IssueOrDispatchCommand0202ccdc)
extern "C" ARM void func_0202ccdc(struct S0202ccdc* obj) {
    if (obj->f2 != 0) {
        SetField0x48UnlessState9Or10_0202c848(obj->f2);
        TryIssueBattleCommandAndUpdateState_0202dd28();
        return;
    }
    int result = IssueBattleCommandSlot9_020d5214((int)DispatchField0x2OrSetState1_0202cd28);
    int done;
    if (result == 2) {
        done = 1;
    } else {
        SetField0x48UnlessState9Or10_0202c848(result);
        done = 0;
    }
    if (done) return;
    TryIssueBattleCommandAndUpdateState_0202dd28();
}
