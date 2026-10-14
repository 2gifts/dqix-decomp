#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct SizeInputStruct022054fc {
	unsigned short field0;
	unsigned char field2;
	unsigned char field3;
};

struct InitData020c7de4 {
	int a; int b; int c; int d;
	int e; int f; int g; int h;
};

struct FourWords;

int ComputeAlignedSizePair_022054fc(SizeInputStruct022054fc* p);
void InitStruct020c7de4(InitData020c7de4* s, int e, int f);
extern "C" void _Z19ZeroInitializeMutexP5Mutex(FourWords* p);
void PopulateContext(ProcessorContext*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void MarkContextReadyAndSwitch(ProcessorContext* context);
extern "C" void func_ov031_022052b4(void);

// USA: func_ov031_02205648
ARM int InitContextFromParams_02205648(int a, void* ctx, SizeInputStruct022054fc* p) {
	int totalSize = ComputeAlignedSizePair_022054fc(p);
	InitStruct020c7de4((InitData020c7de4*)ctx, a, p->field3);
	_Z19ZeroInitializeMutexP5Mutex((FourWords*)((char*)ctx + 0xe0));
	PopulateContext((ProcessorContext*)((char*)ctx + 0x20), (unsigned int)func_ov031_022052b4, (unsigned int)ctx, a + totalSize, p->field0, p->field2);
	MarkContextReadyAndSwitch((ProcessorContext*)((char*)ctx + 0x20));
	return a + totalSize;
}
