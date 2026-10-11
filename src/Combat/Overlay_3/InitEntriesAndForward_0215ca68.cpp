#include <globaldefs.h>

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
extern "C" void func_ov003_0215db2c(void* obj);

#if defined(jpn)
enum { flagOffset = 0x3d4, entriesOffset = 0xb0 };
#else
enum { flagOffset = 0x3bc, entriesOffset = 0x98 };
#endif
struct Obj0215ca68 { char pad[flagOffset]; unsigned char field3bc; };

// USA: func_ov003_0215ca68  (semantic: InitEntriesAndForward_0215ca68)
extern "C" ARM void func_ov003_0215ca68(struct Obj0215ca68* obj) {
	if (obj->field3bc == 0) return;
	InitEntries0205d2bc((struct Obj0205d2bc*)((char*)obj + entriesOffset));
	func_ov003_0215db2c(obj);
}
