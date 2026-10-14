#include <globaldefs.h>

extern "C" void func_ov031_02223440(void);
extern "C" int func_ov031_0223da58(void*);
extern void* TailCallElemAtIndex30_0223c7c4(int);
extern "C" void func_ov031_0223cbbc(int, int);
void SetField1014_022274d0(int, int);
void GetFields181c_02227520(int*, int*);
void SetField181c_0222750c(int, int);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_0222ea24(void);
extern "C" unsigned int func_ov031_0223cf70(void** a);

extern "C" int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);
extern int data_ov031_0224badc;

typedef void (*Callback_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Callback_022234d8 cb);

#if defined(jpn)
extern "C" void* data_ov031_02290c98;
namespace DuplicatePool {
    extern "C" void* data_ov031_02290c98;
}
#else
extern void* data_ov031_02290c98;
#endif

// USA: func_ov031_0222dee0
extern "C" ARM void func_ov031_0222dee0(void) {
	func_ov031_02223440();
	func_ov031_0223da58(*(void**)((char*)data_ov031_02290c98 + 4));
	TailCallElemAtIndex30_0223c7c4(0);
	func_ov031_022234d8((int)&data_ov031_0224badc, (Callback_022234d8)LoadToMainObjStandardPalette);
	func_ov031_0223cbbc(1, 1);
	func_ov031_0223cbbc(0, 0x15);

	int local;
	GetFields181c_02227520(&local, 0);
	if (local >= 3) local += 1;

	SetField1014_022274d0(2, 1);
	SetField181c_0222750c(0, local + 3);
	SetField_022274c0_022274c0((int)func_ov031_0222ea24);
#if defined(jpn)
	void** slot = &DuplicatePool::data_ov031_02290c98;
#else
	void** slot = (void**)0x02290C98;
#endif
	func_ov031_0223cf70(slot);
}
