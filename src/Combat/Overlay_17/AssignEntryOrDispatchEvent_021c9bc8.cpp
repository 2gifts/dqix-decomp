#include <globaldefs.h>

struct Entry0207d9bc;
struct Entry0207da94;
struct Struct0216377c;

void* GetData02108ea8(void);
extern "C" int func_0202c508(void* state);
void ProcessEntries0207da94(struct Entry0207da94* list, int idx);
int AssignEntrySlot0207db58(struct Entry0207d9bc* arr, unsigned short key, char val);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
void Foo0216377c(struct Struct0216377c* obj, unsigned char val);

struct Arg021c9bc8 { char pad[4]; unsigned short f4; unsigned short f6; };

// JPN: func_ov017_021ca078
// USA: func_ov017_021c9bc8  (semantic: AssignEntryOrDispatchEvent_021c9bc8)
extern "C" ARM void func_ov017_021c9bc8(char a0, struct Arg021c9bc8* a1, int a2, char* a3, void* a4) {
#if defined(jpn)
 enum {regionalOffset0=0x3508};
#else
 enum {regionalOffset0=0x3718};
#endif
	void* table = GetData02108ea8();
	unsigned int f4 = a1->f4;
	unsigned short f6 = a1->f6;
	if (func_0202c508(a4)) {
		ProcessEntries0207da94((struct Entry0207da94*)table, f6 & 0xff);
		AssignEntrySlot0207db58((struct Entry0207d9bc*)table, (unsigned short)f4, a0);
		return;
	}
	if (a0 != 0) return;
	struct Struct0216377c* obj = *(struct Struct0216377c**)(a3 + regionalOffset0);
	void* p1 = func_ov017_021b8478(obj);
	int p2 = func_ov017_021b8468(obj);
	if (p1 == 0 || p2 == 0) return;
	if (*(unsigned short*)((char*)p1 + 8) != f4) return;
	typedef void (*Foo0216377cFn)(struct Struct0216377c*, unsigned short);
	((Foo0216377cFn)Foo0216377c)((struct Struct0216377c*)p2, f6);
}
