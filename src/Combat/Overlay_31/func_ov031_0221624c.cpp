#include <globaldefs.h>
#include "System/Memory.h"

extern void* data_ov031_0224e5d8;
extern "C" int func_ov031_022161b0(int index, void* out);

// USA: func_ov031_0221624c
extern "C" ARM int func_ov031_0221624c(char* entries) {
	if (*(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa90) != 2) return -1;

	VectorizedMemset(entries, 0, 0x780);

	int i = 0;
	char* p = entries;
	do {
		*(int*)p = 0;
		p += 0x78;
		i++;
	} while (i < 0x10);

	int count = *(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa88);
	if (count <= 0) goto ret0;

	{
		int index = 0;
		char* entry = entries;
		do {
			int r = func_ov031_022161b0(index, entry);
			if (r == -1) goto ret0;
			index++;
			entry += 0x78;
			count = *(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa88);
		} while (index < count);
	}

ret0:
	return 0;
}
