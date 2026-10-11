#include <globaldefs.h>
#include "std_library_functions.h"

struct StreamState02218710 {
	void* field0;
	int field4;
	int field8;
	int fieldc;
};

int VariadicForward020c7170(int a, int b, int c, ...);
extern "C" int func_ov031_0221883c(void* obj, StreamState02218710* b, int len);
extern int data_ov031_02249ee8;

// USA: func_ov031_02218710
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02218710(void* obj, const char* str) {
	int len;
	StreamState02218710* b = (StreamState02218710*)((char*)obj + 0x19f8);
	len = strlen(str);
	int avail = b->field8 - b->field4;
	if (len > avail) {
		if (func_ov031_0221883c(obj, b, len - avail + 1) == 0) {
			return 1;
		}
		avail = b->field8 - b->field4;
	}

	int written = VariadicForward020c7170(b->field4, avail, (int)&data_ov031_02249ee8, str);
	if (written != len) {
		return 1;
	}

	b->field4 = b->field4 + written;
	return 0;
}
