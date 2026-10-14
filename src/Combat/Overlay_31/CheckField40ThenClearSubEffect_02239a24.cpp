#include <globaldefs.h>

extern "C" void func_ov031_02239368(int);
int ForwardClearBattleSubEffectAt0x800020d68d0(void *p);
void SetField54IfTagNot9Or10_ov031_022393e4(int v);

struct Struct02239a24 { unsigned char pad[4]; char *inner; };
extern struct Struct02239a24 data_ov031_02290d18;

// USA: func_ov031_02239a24  (semantic: CheckField40ThenClearSubEffect_02239a24)
extern "C" ARM int func_ov031_02239a24(void) {
    if (*(int *)(data_ov031_02290d18.inner + 0x40) != 6) {
        return 0;
    }
    func_ov031_02239368(3);
    void *p = data_ov031_02290d18.inner + 0x1e00;
    int r = ForwardClearBattleSubEffectAt0x800020d68d0(p);
    if (r == 2) {
        return 1;
    }
    SetField54IfTagNot9Or10_ov031_022393e4(r);
    return 0;
}
