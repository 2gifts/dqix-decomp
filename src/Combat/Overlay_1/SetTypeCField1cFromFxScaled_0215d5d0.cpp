#include <globaldefs.h>

extern "C" float func_ov017_021d6110(void*);
void* SetTypeCAndField1c_ov001_0215911c(int, int);
extern int data_ov001_02165880;

// USA: func_ov001_0215d5d0
ARM int SetTypeCField1cFromFxScaled_0215d5d0(void* obj) {
    int val = (int)(4096.0f * func_ov017_021d6110(obj));
    SetTypeCAndField1c_ov001_0215911c(*(int*)((char*)&data_ov001_02165880 + 0x24), val);
    return 1;
}
