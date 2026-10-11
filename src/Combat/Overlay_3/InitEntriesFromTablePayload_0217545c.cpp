#include <globaldefs.h>

struct Obj2081;
struct Elem2081;
Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int key);
int IsField0x9cEqual3(unsigned char* obj);
void FindTableEntryPayload_02173f08(char* out1, char* out2, char* out3, char* out4);
void InitEntryAtIndex_0217585c(void* obj, int a, int b, int idx, unsigned char c);

// USA: func_ov003_0217545c  (semantic: InitEntriesFromTablePayload_0217545c)
extern "C" ARM void func_ov003_0217545c(void* obj) {
	struct Obj2081* o;
	struct Elem2081* elem;
	short elemAE;
	short elemAC;
	char out1, out2, out3, out4;
	short bVal;

#if defined(jpn)
    enum { entriesOffset = 0x818 };
#else
    enum { entriesOffset = 0x89c };
#endif
	o = *(struct Obj2081**)((char*)obj + entriesOffset);
	elem = FindElementByByte0xc4(o, 10);
	if (elem == NULL) return;
	if (!IsField0x9cEqual3((unsigned char*)elem)) return;

	elemAE = *(short*)((char*)elem + 0xae);
	elemAC = *(short*)((char*)elem + 0xac);

#if defined(jpn)
    out1 = 8;
    out2 = 0x41;
#else
	FindTableEntryPayload_02173f08(&out1, &out2, &out3, &out4);
#endif

	{
		short aeShift = elemAE << 3;
		bVal = (short)(aeShift + 0x22);
		short acShift = elemAC << 3;
		InitEntryAtIndex_0217585c(obj, out1 + acShift, bVal, 0x1a, 0x78);
		InitEntryAtIndex_0217585c(obj, out2 + acShift, bVal, 0x1b, 0x7a);
	}
}
