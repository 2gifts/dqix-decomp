#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct InitData020c7de4 {
	int a; int b; int c; int d;
	int e; int f; int g; int h;
};

int GetGlobalWord021112ec_020c75a4(void);
void InitStruct020c7de4(InitData020c7de4* s, int e, int f);
extern InitData020c7de4 data_ov031_022918bc;
extern int data_ov031_022918a0;
extern ProcessorContext data_ov031_022918dc;
extern "C" void func_ov031_0224185c(void);

// USA: func_ov031_02240338  (semantic: InitPrimaryContext_02240338)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02240338(int a, int ctx) {
	if (GetGlobalWord021112ec_020c75a4()) {
		InitStruct020c7de4(&data_ov031_022918bc, (int)&data_ov031_022918a0, 1);
		PopulateContext(&data_ov031_022918dc, (unsigned int)func_ov031_0224185c, 0, ctx + 0x2000, 0x2000, a);
		MarkContextReadyAndSwitch(&data_ov031_022918dc);
		return 1;
	}
	return 0;
}
