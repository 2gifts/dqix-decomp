#include <globaldefs.h>

extern int data_ov001_02165884;
extern "C" int func_ov001_021646b8(int a, int b);

// USA: func_ov001_02159b34
ARM int NotifyGlobalWithField70_ov001_02159b34(void* unused, void* ctx) {
	func_ov001_021646b8(data_ov001_02165884, *(int*)((char*)ctx + 0x70));
	return 0;
}
