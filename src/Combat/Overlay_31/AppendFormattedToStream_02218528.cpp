#include <globaldefs.h>
#include "std_library_functions.h"

struct StreamState0221883c { void* field0; int field4; int field8; int fieldc; };
extern "C" int func_ov031_0221883c(void* obj, StreamState0221883c* b, int len);
int VariadicForward020c7170(int a, int b, int c, ...);

extern char data_ov031_02249ed0[];
extern char data_ov031_02249df8[];

// USA: func_ov031_02218528  (semantic: AppendFormattedToStream_02218528)
extern "C" ARM int func_ov031_02218528(void* obj, char* str, char* val) {
	char* mid = (char*)obj + 0x1f8;
	StreamState0221883c* b = (StreamState0221883c*)(mid + 0x1800);
	int len = strlen(val);
	len += (strlen(data_ov031_02249ed0) - 4) + strlen(str);

	int room = b->field8 - b->field4;
	if (len + 1 > room) {
		int need = len - room + 1;
		if (func_ov031_0221883c(obj, b, need) == 0) {
			return 1;
		}
	}

	char* raw = strstr((char*)b->field0, data_ov031_02249df8);
	char saved = raw[2];
	char* p = raw + 2;
	int n = strlen(p) + 1;
	memmove(p + len, p, n);
	int written = VariadicForward020c7170((int)p, len + 1, (int)data_ov031_02249ed0, str, val);
	p[written] = saved;
	b->field4 = b->field4 + len;
	return 0;
}
