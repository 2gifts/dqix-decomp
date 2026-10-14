#include <globaldefs.h>

struct IndexNode_0202a9ac;
struct IndexList_0202a9ac;
struct IndexNode_0202a9ac* GetNodeAtIndex(struct IndexList_0202a9ac* list, int index);
void* GetSubstructAt0x4_02029560(void* base);
extern "C" void* func_ov015_0218f39c(void* obj, void* param2);

struct Obj0219011c {
	void* ptr0;
	char pad38[0x38 - 0x4];
	short field38;
};

// USA: func_ov015_0219011c
ARM void SetField18_0219011c(struct Obj0219011c* obj, int val) {
	struct IndexList_0202a9ac* list = (struct IndexList_0202a9ac*)((char*)obj->ptr0 + 0x2c4);
	struct IndexNode_0202a9ac* node = GetNodeAtIndex(list, obj->field38);
	void* sub;
	void* result;
	if (node == 0) {
		return;
	}
	sub = GetSubstructAt0x4_02029560(node);
	result = func_ov015_0218f39c(obj, sub);
	if (result != 0) {
		*(int*)((char*)result + 0x18) = val;
	}
}
