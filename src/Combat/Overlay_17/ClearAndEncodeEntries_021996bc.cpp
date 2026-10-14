#include <globaldefs.h>

int FreeVRAMStagingMemory(void const*);

struct Entry_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };

// USA: func_ov017_021996bc
ARM void ClearAndEncodeEntries_021996bc(Entry_02199684* arr, int count) {
	for (int i = 0; i < count; i++) {
		int old = arr[i].val;
		arr[i].val = 0;
		if (old != 0) {
			FreeVRAMStagingMemory((void const*)old);
		}
	}
}
