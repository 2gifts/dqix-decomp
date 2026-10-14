#include <globaldefs.h>
#include "std_library_functions.h"

struct TagValueEntry020e38e4 { unsigned int val; unsigned char tag; };
struct TagValueEntry020e385c { unsigned int val; unsigned char tag; };

void* GetData02153660_020e3808(void);
void* GetData02100044_0202ae24(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* state);
int FindEntryIndexByTagAndValue(struct TagValueEntry020e38e4* entries, int tag, int val);
struct TagValueEntry020e385c* FindEntryByTagAndValue(struct TagValueEntry020e385c* entries, int tag, int val);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cebcc  (semantic: DispatchAndCopyEntry_021cebcc)
extern "C" ARM void func_ov017_021cebcc(int kind, int a1, int a2) {
	struct TagValueEntry020e38e4* entries = (struct TagValueEntry020e38e4*)GetData02153660_020e3808();
	void* p = GetData02100044_0202ae24();

	unsigned char buf[0x14];
	buf[0] = 0x34;
	unsigned char* b = buf + 4;
	b[0] = kind;
	*(int*)(b + 4) = a2;
	b[8] = a1;

	if (func_0202c508(func_0202ae18()) != 0 && kind == 3) {
		b[1] = FindEntryIndexByTagAndValue(entries, a1, a2);
		struct TagValueEntry020e385c* found = FindEntryByTagAndValue((struct TagValueEntry020e385c*)entries, a1, a2);
		if (found != NULL) {
			memcpy(b + 4, found, 8);
		}
	}

	func_0205e330(p, buf, 0);
}
