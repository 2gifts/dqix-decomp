#include <globaldefs.h>

#if defined(jpn)
#define Reset3FieldsAndDispatch_0216aa10 func_ov004_0216ac84
enum { kControllerField = 0x868 };
#else
enum { kControllerField = 0x998 };
#endif



extern "C" void func_ov004_02169144(void);
void SetCombatModeFromCase020dc2d0(int mode);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);

// USA: func_ov004_0216aa10
#if defined(jpn)
extern "C"
#endif
ARM int Reset3FieldsAndDispatch_0216aa10(void) {
    func_ov004_02169144();
    unsigned short* p = (unsigned short*)0x4001008;
    p[0] = (p[0] & ~3) | 1;
    p[1] = (p[1] & ~3) | 2;
    p[2] = (p[2] & ~3);
    SetCombatModeFromCase020dc2d0(0);
    int g = GetGlobalField0x1c020421a0();
    if (*(int*)((char*)g + kControllerField) != 0) {
        ReinitController02043204((char*)g);
    }
    return 0;
}
