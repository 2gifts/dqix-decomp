#include <globaldefs.h>
#include "System/Memory.h"

int GetAndStoreSwapped_022077cc(int a, unsigned int* out);
struct Mutex;
void* LockMutex(Mutex*);
struct RefNode020c80f8;
extern "C" void _Z11UnlockMutexP5Mutex(struct RefNode020c80f8* node);

struct Entry02207440 {
	char pad[0xa];
	short fieldA;
	void** fieldC;
};
extern "C" Entry02207440* func_ov031_02207440(int a);

extern void* data_ov031_0224e588;

// USA: func_ov031_02210f78  (semantic: BuildAndSendPacket_02210f78)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02210f78(int a, int code, void* buf) {
	unsigned char* b = (unsigned char*)buf;
	b[0] = 8;
	b[1] = 2;
	*(short*)(b + 2) = (short)(((code >> 8) & 0xff) | ((code << 8) & 0xff00));
	if (GetAndStoreSwapped_022077cc(a, (unsigned int*)(b + 4)) == 0) {
		LockMutex((Mutex*)((char*)data_ov031_0224e588 + 0x1bc));
		Entry02207440* s = func_ov031_02207440(a);
		if (s != NULL) {
			VectorizedInvertedMemcpy(*s->fieldC, b + 4, s->fieldA);
		}
		_Z11UnlockMutexP5Mutex((RefNode020c80f8*)((char*)data_ov031_0224e588 + 0x1bc));
		if (s == NULL) {
			return 0;
		}
	}
	return 1;
}
