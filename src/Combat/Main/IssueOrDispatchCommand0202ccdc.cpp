#include <globaldefs.h>

void SetField0x48UnlessState9Or10(int slot);
void TryIssueBattleCommandAndUpdateState(void);
int IssueBattleCommandSlot9(int callback);
int DispatchField0x2OrSetState1_0202cd28(unsigned short*);

struct S0202ccdc {
    char pad0[2];
    unsigned short f2;
};

// USA: func_0202ccdc  (semantic: IssueOrDispatchCommand0202ccdc)
extern "C" ARM void func_0202ccdc(struct S0202ccdc* obj) {
    if (obj->f2 != 0) {
        SetField0x48UnlessState9Or10(obj->f2);
        TryIssueBattleCommandAndUpdateState();
        return;
    }
    int result = IssueBattleCommandSlot9((int)DispatchField0x2OrSetState1_0202cd28);
    int done;
    if (result == 2) {
        done = 1;
    } else {
        SetField0x48UnlessState9Or10(result);
        done = 0;
    }
    if (done) return;
    TryIssueBattleCommandAndUpdateState();
}
