#include <globaldefs.h>

#if defined(jpn)
extern "C" void* data_ov031_02250bf8;
namespace DuplicatePool {
    extern "C" void* data_ov031_02250bf8;
}
#else
extern void* data_ov031_02250bf8;
#endif

int TailCallForward_0223e2e0(int arg0, void* arg1);
extern "C" int func_ov031_0223da58(void* obj);
extern "C" unsigned int func_ov031_0223cf70(void** a);

// USA: func_ov031_02223b1c
extern "C" ARM void func_ov031_02223b1c(void) {
	if (data_ov031_02250bf8 == NULL) {
		return;
	}
	void* field4 = *(void**)((char*)data_ov031_02250bf8 + 4);
	TailCallForward_0223e2e0(0, field4);
	func_ov031_0223da58(*(void**)data_ov031_02250bf8);
#if defined(jpn)
	func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02250bf8);
#else
	func_ov031_0223cf70((void**)0x02250BF8);
#endif
}
