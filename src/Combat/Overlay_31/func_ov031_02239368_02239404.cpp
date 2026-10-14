#include <globaldefs.h>

struct Ctx020d507c;

extern "C" ARM void func_ov031_02239368(int val);
extern "C" void func_ov031_02239448(unsigned short* a);
void SetField54IfTagNot9Or10_ov031_022393e4(int v);
int IssueBattleCommandSlot7(int a, struct Ctx020d507c* b);

struct DataOv02290d18_02239404 { void* unk0; struct Ctx020d507c* inner; };
extern struct DataOv02290d18_02239404 data_ov031_02290d18;

// USA: func_ov031_02239404  (semantic: IssueCallbackSlotAndSetField54_02239404)
extern "C" ARM int func_ov031_02239404(void) {
    func_ov031_02239368(3);
    int r = IssueBattleCommandSlot7((int)func_ov031_02239448, data_ov031_02290d18.inner);
    if (r == 2) {
        return 1;
    }
    SetField54IfTagNot9Or10_ov031_022393e4(r);
    func_ov031_02239368(9);
    return 0;
}
