#include <globaldefs.h>
#if defined(jpn)
#define STATE_OFFSET 0x3d30
#define RESOURCE_OFFSET 0x34f8
#else
#define STATE_OFFSET 0x3db8
#define RESOURCE_OFFSET 0x3708
#endif

#if defined(jpn)
#define func_ov005_0215a37c func_ov005_0215b8d0
#endif

extern "C" void* func_ov017_0218b5b0(void);
int GetField1c_021a193c(int* obj);
int SetShiftedFieldsAndCallTwice_021e3258(void* obj, int a, int b, int c, short d);

// USA: func_ov005_0215a37c  (semantic: CheckStateAndDispatch0215a37c)
extern "C" ARM void func_ov005_0215a37c(char* obj) {
	if (*(unsigned char*)(obj + STATE_OFFSET) != 3) return;
	char* singleton = (char*)func_ov017_0218b5b0();
	int* p = *(int**)(singleton + RESOURCE_OFFSET);
	int field = GetField1c_021a193c(p);
	SetShiftedFieldsAndCallTwice_021e3258((void*)field, 0xbd, 0x10, 0xbd, 0x2f);
}
