#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
extern "C" void func_02017098(void* obj, int index);
struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase_02027ca4(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);
struct Obj02028c14;
void SetFlagBit02028c14(struct Obj02028c14* obj, int index);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);

// USA: func_ov017_021b6174  (semantic: SyncEntryAndSetBit_021b6174)
extern "C" ARM void func_ov017_021b6174(int id, int index, int bit) {
	void* obj = func_02012fe4();
	void* ctx = func_0205ec34();
	unsigned short cur = *(unsigned short*)obj;
	if (id == cur) {
		func_02017098(obj, index);
	}
	struct Entry_02028bd0* entry = FindInlineEntryById(GetEntryTableBase_02027ca4(), id);
	if (entry != NULL) {
		SetFlagBit02028c14((struct Obj02028c14*)entry, index);
	}
	SetOrClearBitInArray_0206df6c(ctx, (unsigned char*)ctx + 0x8c, bit + 0x9e + 0x700, 1);
}
