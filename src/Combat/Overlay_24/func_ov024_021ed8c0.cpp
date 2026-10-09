#include <globaldefs.h>
#include "std_library_functions.h"
#include "Util/Random.h"

extern "C" int func_ov000_02154f30(struct Random* random, int id, int count, short* ids);

struct Record_021ed8c0 {
	char unk[0x1c];
	unsigned int flags0 : 14;
	unsigned int hitKind : 5;
	unsigned int flags19 : 13;
};

struct Buf8_021ed8c0 { short v[8]; };
extern struct Buf8_021ed8c0 data_ov024_021fec5c;

// USA: func_ov024_021ed8c0
extern "C" ARM void func_ov024_021ed8c0(struct Random** context, int id, struct Record_021ed8c0* record, int* count, short* ids) {
	struct Random* rng = *context;
	int hits = 1;
	switch (record->hitKind) {
	case 0:
	case 10:
		break;
	case 3:
		hits = NextRandomBetween(rng, 3, 4);
		break;
	case 4:
		hits = 2;
		break;
	case 5:
		hits = 4;
		break;
	case 7:
		hits = 7;
		break;
	case 8:
		hits = 3;
		break;
	}

	short n = 0;
	struct Buf8_021ed8c0 buf = data_ov024_021fec5c;
	for (int i = 0; i < hits; i++) {
		int r = func_ov000_02154f30(*context, id, *count, ids);
		if (r < 0) break;
		buf.v[n] = r;
		n++;
	}
	*count = n;
	memcpy(ids, buf.v, sizeof(buf));
}
