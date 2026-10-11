#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct Src021c6784 {
	unsigned char pad0[4];
	int field4;
	unsigned short field8;
	unsigned short fielda;
	unsigned char fieldc;
	unsigned char fieldd;
	unsigned char fielde;
};

struct Entry021c6784 {
	unsigned char f0;
	unsigned char f1;
	unsigned short f2;
	int f4;
};

struct Holder021c6784 {
	unsigned char pad0[0x4c];
	Entry021c6784 items[1];
};

// JPN: func_ov017_021c6c34
// USA: func_ov017_021c6784  (semantic: ApplySrcToIndexedEntry_021c6784)
extern "C" ARM void func_ov017_021c6784(int unused0, Src021c6784* src, GameState* battleStruct, char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	void* table = *(void**)(base + 0x3000 + regionalOffset0);

	void* fieldObj = func_ov017_021b8478(table);
	if (!fieldObj) return;

	void* state = GetField6b0_021b8470(table);
	if (!state) return;

	int value = GetField0x3acValue(battleStruct);
	if (*((signed char*)fieldObj + 0x2a) == value) return;
	if (*(unsigned short*)((char*)fieldObj + 0x8) != src->field8) return;

	Holder021c6784* holder = (Holder021c6784*)((char*)state + 0x1b0 + 0x8000);
	Entry021c6784* entry = &holder->items[src->fielde];
	entry->f2 = src->fielda;
	entry->f1 = src->fieldc;
	entry->f0 = src->fieldd;
	entry->f4 = src->field4;
}
