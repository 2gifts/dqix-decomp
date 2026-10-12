#include <globaldefs.h>

#if defined(jpn)
enum { ENABLED_FIELD_OFFSET = 0x4a8, NODE_FIELD_OFFSET = 0x8f8, VALUE_FIELD_OFFSET = 0x4ac, LIST_FIELD_OFFSET = 0x4ec };
#else
enum { ENABLED_FIELD_OFFSET = 0x6b8, NODE_FIELD_OFFSET = 0xb18, VALUE_FIELD_OFFSET = 0x6bc, LIST_FIELD_OFFSET = 0x6fc };
#endif


#if defined(jpn)
#define InitAndAppendState30_0219931c func_ov017_02199ecc
#endif

struct TailList020469b4;
struct TailNode020469b4;
struct Obj021ac2ec;
struct SetField8Struct_021aca14;

void InitState30_021ac2ec(Obj021ac2ec* p);
void SetField8_021aca14(SetField8Struct_021aca14* obj, int val);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

// USA: func_ov017_0219931c
#if defined(jpn)
extern "C"
#endif
ARM void InitAndAppendState30_0219931c(char* obj) {
	if (*(unsigned char*)(obj + 0x3000 + ENABLED_FIELD_OFFSET) == 0) {
		return;
	}
	char* base = obj + 0x3000;
	Obj021ac2ec* node = *(Obj021ac2ec**)(base + NODE_FIELD_OFFSET);
	InitState30_021ac2ec(node);
	SetField8_021aca14(*(SetField8Struct_021aca14**)(obj + 0x3000 + NODE_FIELD_OFFSET), *(int*)(obj + 0x3000 + VALUE_FIELD_OFFSET));
	AppendNodeToTail(*(TailList020469b4**)(obj + 0x3000 + LIST_FIELD_OFFSET), *(TailNode020469b4**)(obj + 0x3000 + NODE_FIELD_OFFSET));
}
