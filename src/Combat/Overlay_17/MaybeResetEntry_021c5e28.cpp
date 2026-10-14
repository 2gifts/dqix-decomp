#include <globaldefs.h>

extern "C" void func_0202ae18(void);
extern "C" int func_0202c508(void);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
void* GetData02108ea8(void);

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
void ResetEntryByKey0207da7c(Entry0207d9bc* arr, unsigned short key);

struct LocalBuf021c5e28 {
	unsigned char tag;
	unsigned char pad[3];
	unsigned char id;
	unsigned char pad1;
	short val;
	unsigned char pad3[0xc];
};

// USA: func_ov017_021c5e28
ARM void MaybeResetEntry_021c5e28(int id, int val) {
	func_0202ae18();
	if (func_0202c508()) {
		void* p = GetData02100044();
		struct LocalBuf021c5e28 buf;
		buf.tag = 0x3e;
		buf.id = (unsigned char)id;
		buf.val = val;
		func_0205e330(p, &buf, 0);
		Entry0207d9bc* arr = (Entry0207d9bc*)GetData02108ea8();
		ResetEntryByKey0207da7c(arr, (unsigned short)val);
	}
}
