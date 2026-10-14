#include <globaldefs.h>

extern void* GetGlobalPtr021075f4_0203cf4c(void);
struct EntryList_203dce4;
struct Entry_203dce4;
extern struct Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(struct EntryList_203dce4* list, int id);

struct Global02161880 { char pad[0x98]; unsigned int field98; };

// USA: func_ov001_02161880
ARM int ClearFlagAcrossEntries_02161880(void) {
	struct Global02161880* g = (struct Global02161880*)GetGlobalPtr021075f4_0203cf4c();
	g->field98 &= ~0x2;
	int i;
	for (i = 0; i < 0x20; i++) {
		struct Entry_203dce4* e = GetEntryUnlessFlag0x8000_0203dce4((struct EntryList_203dce4*)g, i);
		if (e != NULL) {
			*(unsigned int*)e &= ~0x10000;
		}
	}
	return 1;
}
