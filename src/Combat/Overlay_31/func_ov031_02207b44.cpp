#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"
#include "System/Timing.h"

struct Entry02207b44 {
	char pad[0x20];
	char copyData[0x30];
	int field50;
	int field54;
	unsigned short field58;
	unsigned char field5a;
	char pad2[0x5c - 0x5b];
};

extern Entry02207b44 data_ov031_0224e3b8[4];

// USA: func_ov031_02207b44
extern "C" ARM void func_ov031_02207b44(void* obj, int a, int b) {
	int i;
	Entry02207b44* best;
	unsigned int bestAge;
	int oldIRQ;
	unsigned int now;
	Entry02207b44* entry;
	oldIRQ = DisableIRQInterrupts();
	now = (unsigned int)(GetCurrentTimestamp() >> 16);
	best = data_ov031_0224e3b8;
	bestAge = 0;
	i = 0;
	entry = best;
	do {
		if (entry->field5a != 0 && a != 0 && a == entry->field54 && b != 0 && b == entry->field58) {
			best = entry;
			break;
		}
		if (bestAge != 0xffffffffu) {
			if (entry->field5a == 0) {
				bestAge = 0xffffffffu;
				best = entry;
			} else {
				unsigned int age = now - (unsigned int)entry->field50;
				if (age > bestAge) {
					bestAge = age;
					best = entry;
				}
			}
		}
		i++;
		entry++;
	} while (i < 4);
	VectorizedInvertedMemcpy((char*)obj + 0x74, best, 0x20);
	VectorizedInvertedMemcpy(obj, (char*)best + 0x20, 0x30);
	best->field50 = (int)now;
	best->field5a = 1;
	best->field54 = a;
	best->field58 = b;
	SetIRQInterruptState(oldIRQ);
}
