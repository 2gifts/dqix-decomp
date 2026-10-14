#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" void* func_ov031_0223b61c(char* path, unsigned int* outSize, int align);
extern "C" void func_020bbd14(void*);
extern "C" void func_020bd368(void*, int);
extern "C" void func_020be6c4(int);
void ClearField0x0_020bc078(int* field);
void SetEntryByte_020bbf34(int index, int value);
void SetEntryHalfword_020bbf4c(int index, int value);
void SetTableEntryPointer_020bbf6c(int index, void* value);
void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_02236900(void);

extern void* data_ov031_02290d00;
extern char data_ov031_0224be60[];

// USA: func_ov031_0223677c  (semantic: InitTableAndDispatch_0223677c)
extern "C" ARM void func_ov031_0223677c(void) {
	data_ov031_02290d00 = func_ov031_0223cf4c(0xa0, 4);

	unsigned int size;
	void* p = func_ov031_0223b61c(data_ov031_0224be60, &size, 0x20);
	*(void**)((char*)data_ov031_02290d00 + 0x98) = p;
	func_020bbd14(p);

	func_020bd368(data_ov031_02290d00, *(int*)((char*)data_ov031_02290d00 + 0x98));
	func_020be6c4(0);

	ClearField0x0_020bc078((int*)((char*)data_ov031_02290d00 + 0x94));

	int i = 0;
	do {
		SetEntryByte_020bbf34(i, 0x7f);
		SetEntryHalfword_020bbf4c(i, 1);
		SetTableEntryPointer_020bbf6c(i, 0);
		i++;
	} while (i < 0x20);

	void* result = CallWithZeroExtra_0223e218((void*)0, (void*)func_ov031_02236900, (void*)0, 0xc8);
	*(void**)((char*)data_ov031_02290d00 + 0x9c) = result;
}
