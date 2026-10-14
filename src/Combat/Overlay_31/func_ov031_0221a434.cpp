#include <globaldefs.h>
#include "System/Memory.h"

typedef void* (*AllocFn0221a434)(void*, unsigned int);

void SetGlobal0224e5a4IfNotNine_ov031_02211b08(int a, int b);

extern char* data_ov031_0224e69c;
extern void* data_ov031_0224a244;

struct CallbackObj0221a434 {
	AllocFn0221a434 allocFn;
	void* other;
};

// USA: func_ov031_0221a434  (semantic: CreateAndRegisterCallbacks_0221a434)
extern "C" ARM int func_ov031_0221a434(AllocFn0221a434 allocFn, void* other) {
	if (data_ov031_0224e69c != NULL) {
		SetGlobal0224e5a4IfNotNine_ov031_02211b08(9, 0xffffa1dc);
		return 0;
	}
	void* obj = allocFn(&data_ov031_0224a244, 0x1c20);
	data_ov031_0224e69c = (char*)obj;
	if (obj == NULL) {
		SetGlobal0224e5a4IfNotNine_ov031_02211b08(9, 0xffffa1dc);
		return 0;
	}
	VectorizedMemset(obj, 0, 0x1c20);
	((CallbackObj0221a434*)data_ov031_0224e69c)->allocFn = allocFn;
	((CallbackObj0221a434*)data_ov031_0224e69c)->other = other;
	return 1;
}
