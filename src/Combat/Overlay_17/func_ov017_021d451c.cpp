#include <globaldefs.h>

struct Struct021c90b4 {
	unsigned short a;
	unsigned short b;
	unsigned short c;
	unsigned short d;
	unsigned char e;
	unsigned char f;
	unsigned short g;
	unsigned short h;
};
void CopyStruct021c90b4(Struct021c90b4* dst, Struct021c90b4* src);

struct Entry_021d451c {
	unsigned char flags;
	unsigned char pad1;
	unsigned short id;
	Struct021c90b4 data;
	unsigned char pad2[0x1e - 0x12];
};

extern "C" void func_ov017_021d46a4(Entry_021d451c* arr, Entry_021d451c* slot);

// USA: func_ov017_021d451c
extern "C" ARM void func_ov017_021d451c(Entry_021d451c* arr, Struct021c90b4* rec) {
	Entry_021d451c* found = NULL;
	Entry_021d451c* freeSlot = NULL;
	int i;
	for (i = 0; i < 0x30; i++) {
		if (rec->a == arr[i].id) {
			found = &arr[i];
			break;
		}
		if (freeSlot == NULL && arr[i].flags == 0) {
			freeSlot = &arr[i];
		}
	}
	if (found != NULL) {
		CopyStruct021c90b4(&found->data, rec);
		found->id = rec->a;
		found->flags |= 0x1;
		func_ov017_021d46a4(arr, found);
		return;
	}
	if (freeSlot == NULL) {
		return;
	}
	CopyStruct021c90b4(&freeSlot->data, rec);
	freeSlot->id = rec->a;
	freeSlot->flags |= 0x1;
	func_ov017_021d46a4(arr, freeSlot);
}
