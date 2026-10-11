#include <globaldefs.h>

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);

#if defined(jpn)
enum { flagOffset = 0x4e8, entriesOffset = 0xe0 };
#else
enum { flagOffset = 0x4ec, entriesOffset = 0xe4 };
#endif
struct Obj021685a8 { char pad[flagOffset]; unsigned char field4ec; };

// USA: func_ov003_021685a8  (semantic: CallInitEntriesIfSet_021685a8)
extern "C" ARM void func_ov003_021685a8(struct Obj021685a8* obj) {
	if (obj->field4ec == 0) return;
	InitEntries0205d2bc((struct Obj0205d2bc*)((char*)obj + entriesOffset));
}
