#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);
void* SetTypeFAndField1c_ov001_021591b0(int type, int val);
extern int data_ov001_02165880;

// USA: func_ov001_0215d8d0
ARM int EnqueueEventTypeF_0215d8d0(void* p) {
	int val = func_ov017_021d60f4(p);
	int type = *(int*)((char*)&data_ov001_02165880 + 0x24);
	SetTypeFAndField1c_ov001_021591b0(type, val);
	return 1;
}
