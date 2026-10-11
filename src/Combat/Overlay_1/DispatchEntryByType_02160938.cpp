#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov017_021917f0(int a, int b);

struct Entry_02160938 { int type; int val; int pad2; int pad3; };
struct DataTable_02160938 { char pad[4]; Entry_02160938* table; };
extern struct DataTable_02160938 data_ov001_02165880;

// USA: func_ov001_02160938
ARM int DispatchEntryByType_02160938(void* self) {
	int a = func_ov017_021d60f4(self);
	int flag = func_ov017_021d60f4((char*)self + 0x8);
	if (data_ov001_02165880.table[a].type != 4 && data_ov001_02165880.table[a].type != 0 && data_ov001_02165880.table[a].type != 5) {
		return 0;
	}
	if (flag != 0) {
		func_ov017_021917f0(data_ov001_02165880.table[a].val, 1);
	} else {
		func_ov017_021917f0(data_ov001_02165880.table[a].val, 0);
	}
	return 1;
}
