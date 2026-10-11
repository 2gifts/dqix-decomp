#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD_0 0x4ec
#define REGION_FIELD_1 0x8ec
#else
#define REGION_FIELD_0 0x6fc
#define REGION_FIELD_1 0xb0c
#endif


struct TailList020469b4;
struct TailNode020469b4;
struct Obj021aa50c;

void InitState25_021aa50c(Obj021aa50c* p);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_021aa4cc  (semantic: InitAndAppendState25_021aa4cc)
extern "C" ARM void func_ov017_021aa4cc(char* obj, unsigned char value) {
	obj += 0x3000;
	Obj021aa50c* node = *(Obj021aa50c**)(obj + REGION_FIELD_1);
	if (*((unsigned char*)node + 2) != 0) {
		return;
	}
	InitState25_021aa50c(node);
	*((unsigned char*)*(Obj021aa50c**)(obj + REGION_FIELD_1) + 0x5c) = value;
	AppendNodeToTail(*(TailList020469b4**)(obj + REGION_FIELD_0), (TailNode020469b4*)*(Obj021aa50c**)(obj + REGION_FIELD_1));
}
