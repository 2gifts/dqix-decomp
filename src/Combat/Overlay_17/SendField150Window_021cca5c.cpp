#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Packet021cca5c {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short arr[6];
	unsigned short id;
	unsigned char mode;
	unsigned char pad1;
};

// USA: func_ov017_021cca5c  (semantic: SendField150Window_021cca5c)
extern "C" ARM void func_ov017_021cca5c(int id, int flag) {
	GameState* battle = GameState::GetInstance();
	GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battle, id);
	if (!c) return;

	unsigned char* field150 = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)c);
	if (!field150) return;

	void* p = GetData02100044_0202ae24();

	Packet021cca5c buf;
	buf.tag = 0xc;
	buf.id = (unsigned short)id;
	unsigned char mode;
	if (flag == 0) {
		mode = 1;
		buf.mode = mode;
	} else {
		mode = 7;
		buf.mode = mode;
	}

	for (unsigned char i = 0; i < 6; i++) {
		buf.arr[i] = *(unsigned short*)(field150 + (i + mode) * 2 + 0x100 + 0x6c);
	}

	func_0205e330(p, &buf, 0);
}
