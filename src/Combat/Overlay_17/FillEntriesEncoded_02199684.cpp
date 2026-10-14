#include <globaldefs.h>

int AllocateVRAMStagingMemory(unsigned int);

struct Entry_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };

// USA: func_ov017_02199684
ARM void FillEntriesEncoded_02199684(Entry_02199684* arr, int count, int value) {
	for (int i = 0; i < count; i++) {
		arr[i].val = AllocateVRAMStagingMemory(value);
	}
}
