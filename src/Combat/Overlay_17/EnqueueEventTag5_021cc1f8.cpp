#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned char GetField0x397cValue_020100b0(GameState* battleStruct);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cc1f8 {
	unsigned char tag;
	char pad0[3];
	unsigned char id;
	unsigned char len;
	unsigned char arr[4];
	unsigned char extra;
	char pad1[9];
};

// USA: func_ov017_021cc1f8  (semantic: EnqueueEventTag5_021cc1f8)
extern "C" ARM void func_ov017_021cc1f8(int id, const char* src, int len, int extra) {
	GameState* bs = GameState::GetInstance();
	if (id == GetField0x397cValue_020100b0(bs)) {
		void* p = GetData02100044_0202ae24();
		struct LocalEvt021cc1f8 buf;
		buf.tag = 5;
		buf.id = (unsigned char)id;
		int i;
		for (i = 0; i < len; i++) {
			buf.arr[i] = src[i];
		}
		buf.len = (unsigned char)len;
		buf.extra = (unsigned char)extra;
		func_0205e330(p, &buf, 0);
	}
}
