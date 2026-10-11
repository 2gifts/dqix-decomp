#include <globaldefs.h>

struct ThreeShorts021ded84 {
	unsigned short a;
	unsigned short b;
	unsigned short c;
};

void CopyThreeShorts021ded84(struct ThreeShorts021ded84* dst, struct ThreeShorts021ded84* src);

struct Table_021deda0 {
#if defined(jpn)
	char pad[0x78dc];
#else
	char pad[0x76ec];
#endif
	struct ThreeShorts021ded84 rows[5];
	unsigned short count;
};

// JPN: func_ov025_021df6b0
// USA: func_ov025_021deda0
ARM int ShiftRowsDown_021deda0(struct Table_021deda0* t, struct ThreeShorts021ded84* out) {
	if (t->count != 0) {
		CopyThreeShorts021ded84(out, t->rows);
		t->count = t->count - 1;
		for (int i = 0; i < t->count; i++) {
			CopyThreeShorts021ded84(&t->rows[i], &t->rows[i + 1]);
		}
		return 1;
	}
	return 0;
}
