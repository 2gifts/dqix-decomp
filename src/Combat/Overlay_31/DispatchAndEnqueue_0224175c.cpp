#include <globaldefs.h>

struct QueueState0224175c { int writePos; int readPos; };
extern QueueState0224175c data_ov031_022919bc;

struct Elem8_0224175c { void* val; int pad; };
extern Elem8_0224175c data_ov031_022919c4[];
extern Elem8_0224175c data_ov031_022919c8[];

extern "C" int func_ov031_022413c8(int unused, void* id);
extern "C" void func_ov031_02241720(void* obj);

// USA: func_ov031_0224175c  (semantic: DispatchAndEnqueue_0224175c)
extern "C" ARM void func_ov031_0224175c(void* target, void** ptr) {
	int nextRead = (data_ov031_022919bc.writePos + 1) & 7;
	if (nextRead == data_ov031_022919bc.readPos) {
		func_ov031_022413c8(0, data_ov031_022919c4[data_ov031_022919bc.readPos].val);
		func_ov031_02241720(data_ov031_022919c8[data_ov031_022919bc.readPos].val);
		data_ov031_022919bc.readPos = (data_ov031_022919bc.readPos + 1) & 7;
	}
	if (*ptr == 0) {
		return;
	}
	int writePos = data_ov031_022919bc.writePos;
	data_ov031_022919c4[writePos].val = target;
	data_ov031_022919c8[writePos].val = *ptr;
	*ptr = 0;
	data_ov031_022919bc.writePos = nextRead;
}
