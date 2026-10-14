#include <globaldefs.h>
void InitCombatantVisualState_020db264(void*, int, int, int, int);

extern int data_0214e4c8;

// USA: func_020daf9c
ARM void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d) {
    InitCombatantVisualState_020db264((void*)(&data_0214e4c8), (int)(a), (int)(b), (int)(c), (int)(d));
}
