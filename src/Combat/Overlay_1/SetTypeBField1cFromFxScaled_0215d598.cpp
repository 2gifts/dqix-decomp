#include <globaldefs.h>

extern "C" float func_ov017_021d6110(void*);
void* SetTypeBAndField1c_ov001_021590fc(int, int);
extern int data_ov001_02165880;

// USA: func_ov001_0215d598
ARM int SetTypeBField1cFromFxScaled_0215d598(void* obj) {
    int val = (int)(4096.0f * func_ov017_021d6110(obj));
    SetTypeBAndField1c_ov001_021590fc(*(int*)((char*)&data_ov001_02165880 + 0x24), val);
    return 1;
}
