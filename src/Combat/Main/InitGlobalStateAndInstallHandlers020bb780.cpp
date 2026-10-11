#include <globaldefs.h>
#if defined(jpn)
#define data_020f1ef0 data_020f205c
#define data_020f1ef4 data_020f2060
#endif

extern char data_0210cf88;
void ResetGlobalState020bb948(void);
int ReturnFalse020bb908(void);
extern "C" void func_020bb7cc(void);
extern void* data_020f1ef0;
extern void* data_020f1ef4;

// USA: func_020bb780
ARM void InitGlobalStateAndInstallHandlers020bb780(void* value, int installHandlers) {
    *(int*)(&data_0210cf88 + 0x8) = (int)value;
    ResetGlobalState020bb948();
    if (installHandlers) {
        data_020f1ef0 = (void*)func_020bb7cc;
        data_020f1ef4 = (void*)ReturnFalse020bb908;
    }
}
