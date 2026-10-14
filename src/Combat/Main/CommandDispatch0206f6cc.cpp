#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0_0200fb8c(int* obj);
extern "C" void func_ov017_021bac24(int obj);
extern "C" void func_ov017_021ba8e0(int obj);
extern "C" void func_ov003_0217e300(int obj);
extern "C" void func_ov017_021b2c24(int obj);
extern "C" void func_ov017_021b65e0(int obj, int a);
extern "C" void func_ov017_0218d77c(int obj, int a);
extern "C" void func_ov017_021b146c(int obj, int a);
extern "C" void func_ov017_021c12fc(int obj, int a, int b);
extern "C" void func_ov017_021a8614(int obj, int a, int b, int c, int d, int e);

// USA: func_0206f6cc
ARM int CommandDispatch0206f6cc(unsigned char* p, int idx) {
    if (idx < 0 || *(int*)(p + 4) <= idx) {
        return 1;
    }

    int ctx = GetWord0x0_0200fb8c((int*)GameState::GetInstance());
    unsigned char cmd = p[idx];
    switch (cmd) {
        case 1: func_ov017_021bac24(ctx); break;
        case 2: func_ov017_021ba8e0(ctx); break;
        case 3: func_ov003_0217e300(ctx); break;
        case 4: func_ov017_021b2c24(ctx); break;
        case 5: func_ov017_021b65e0(ctx, 0); break;
        case 6: func_ov017_0218d77c(ctx, 3); break;
        case 7: func_ov017_021b146c(ctx, 0); break;
        case 8: func_ov017_021b65e0(ctx, 1); break;
        case 9: func_ov017_021c12fc(ctx, 0, 0); break;
        case 10: func_ov017_021c12fc(ctx, 1, 0); break;
        case 11: func_ov017_021a8614(ctx, 0, 1, 2, 3, 4); break;
        case 12: func_ov017_0218d77c(ctx, 3); break;
        case 0:
        default:
            return 1;
    }
    return 0;
}
