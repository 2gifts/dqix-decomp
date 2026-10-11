#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044(void);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void func_0205e330(void* data, void* buf, int flags);

// JPN: func_ov017_021ca7a8
// USA: func_ov017_021ca2f8
extern "C" ARM void func_ov017_021ca2f8(unsigned char param0) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	char buf[0x14];
	void* data = GetData02100044();
	GameState::GetInstance();
	void* table = *(void**)((char*)((unsigned int)func_ov017_0218b5b0()) + 0x3000 + regionalOffset0);
	void* a = func_ov017_021b8478(table);
	if (a == NULL) {
		return;
	}
	buf[0] = 0x5b;
	unsigned short v = *(unsigned short*)((char*)a + 8);
	unsigned char* p = (unsigned char*)(buf + 4);
	*(unsigned short*)p = v;
	p[2] = param0;
	func_0205e330(data, buf, 0);
}
