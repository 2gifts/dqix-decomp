#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* func_0202ae18(void);
void* GetData02100044(void);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
void* ResetBuffer02052a10(char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021cc0cc {
	unsigned char tag;
	unsigned char pad0[3];
	signed char partySlot;
	unsigned char active;
	char name[12];
	unsigned char pad1[2];
};

// KEEP-NAME
// USA: func_ov017_021cc0cc
ARM void EnqueueEventTag43_021cc0cc(void) {
	GameState* bs = GameState::GetInstance();
	void* search = func_0202ae18();
	void* p = GetData02100044();
	GameObject* c = bs->GetProtagonist();
	if (!c) return;

	LocalEvt021cc0cc buf;
	buf.tag = 0x2b;
	buf.partySlot = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search);
	buf.active = 1;
	#if defined(jpn)
    const char* name = c->baseStats_->unk;
#else
    const char* name = (const char*)ResetBuffer02052a10((char*)c);
#endif
	strncpy(buf.name, name, sizeof(buf.name));
	func_0205e330(p, &buf, 0);
}
