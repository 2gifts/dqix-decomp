#include <globaldefs.h>
#if defined(jpn)
extern "C" int func_0202c814(void);
#define SetState3AndDispatch_0202cca4 func_0202c814
#endif
int TrySetBattleContextField020d5aec(int);

extern char data_021015a0;
extern "C" void func_0202ccdc(void);
void SetField0x48UnlessState9Or10(int);

// USA: func_0202cca4
ARM int SetState3AndDispatch_0202cca4(void) {
    int r;
    *(int*)(&data_021015a0 + 0x10) = 3;
    r = TrySetBattleContextField020d5aec((int)((void*)func_0202ccdc));
    if (r == 2) return 1;
    SetField0x48UnlessState9Or10(r);
    return 0;
}
