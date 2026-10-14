#include <globaldefs.h>
#include "World/Object3D.h"

struct Entry_021646b8 { int type; char pad[8]; void* field_c; };

// USA: func_ov001_021646b8  (semantic: DispatchStreamResetByType_021646b8)
extern "C" ARM int func_ov001_021646b8(Entry_021646b8* table, int index) {
	Entry_021646b8* entry;
	void* member;
	if (index < 0 || index >= 0x20) return 0;
	entry = &table[index];
	switch (entry->type) {
	case 0:
	case 1:
	case 4:
	case 5:
		member = entry->field_c;
		if (member == 0) return 0;
		((Object3D*)((unsigned char*)member))->StopCurrentAnimation();
		return 1;
	case 6:
		member = entry->field_c;
		if (member == 0) return 0;
		member = *(void**)((char*)member + 0x18);
		if (member == 0) return 0;
		((Object3D*)((unsigned char*)member))->StopCurrentAnimation();
		return 1;
	default:
		return 0;
	}
}
