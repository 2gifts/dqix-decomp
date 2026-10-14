#include <globaldefs.h>

extern char data_021015a0;
int CallFunc020d51a8One_020d5204(int a);
void SetField0x48UnlessState9Or10_0202c848(int arg);
extern "C" void func_0202c9ac(void);

// USA: func_0202c958  (semantic: CheckStateAndDispatch0202c958)
extern "C" ARM int func_0202c958(void) {
    int state = *(int*)(&data_021015a0 + 0x10);
    if ((unsigned int)(state - 4) <= 2) {
        return 1;
    }
    int result = CallFunc020d51a8One_020d5204((int)func_0202c9ac);
    if (result != 2) {
        SetField0x48UnlessState9Or10_0202c848(result);
        return 0;
    }
    *(short*)(&data_021015a0 + 0x0) = 0;
    *(short*)(&data_021015a0 + 0xa) = 1;
    return 1;
}
