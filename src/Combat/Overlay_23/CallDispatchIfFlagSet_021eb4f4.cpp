#include <globaldefs.h>

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8*, int, int);
extern "C" void func_0204b088(void*, int);
#if defined(jpn)
#define func_ov023_021ed44c func_ov023_021ed394
#endif
extern "C" void func_ov023_021ed44c(void*);

// JPN: func_ov023_021eb458
// USA: func_ov023_021eb4f4
ARM void CallDispatchIfFlagSet_021eb4f4(char* obj) {
	if (*(unsigned char*)(obj + 0x431) == 0) return;
	InitEntries0205d2bc((struct Obj0205d2bc*)(obj + 0xc4));
	unsigned short flags = *(unsigned short*)(obj + 0x400 + 0x38);
	if ((flags & 0x40) || (flags & 0x200)) {
		short val = *(short*)(obj + 0x400 + 0x3a);
		DispatchViaTable0204b5e8((struct Obj0204b5e8*)(obj + 0x64), 0, val);
		func_0204b088(obj + 0x64, 0);
		unsigned short flags2 = *(unsigned short*)(obj + 0x400 + 0x38);
		flags2 &= ~0x200;
		*(unsigned short*)(obj + 0x400 + 0x38) = flags2;
	}
	func_ov023_021ed44c(obj);
}
