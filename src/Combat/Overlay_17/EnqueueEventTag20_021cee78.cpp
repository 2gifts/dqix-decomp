#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);
struct Vector3i;

struct LocalEvt021cee78 {
	unsigned char tag;
	unsigned char pad0[3];
	int vec[3];
	unsigned short field10;
	unsigned char field12;
	unsigned char field13;
};

// USA: func_ov017_021cee78
ARM void EnqueueEventTag20_021cee78(int id, unsigned char b) {
	GameObject* c = GameState::GetInstance()->GetGameObjectByIndex(id);
	if (c == NULL) {
		return;
	}
	void* p = GetData02100044_0202ae24();
	LocalEvt021cee78 buf;
	buf.tag = 0x14;
	buf.field12 = id;
	*(Vector3i*)buf.vec = *(Vector3i const*)((int*)((char*)c + 0x44));
	buf.field10 = *(int*)((char*)c + 0x54);
	buf.field13 = b;
	func_0205e330(p, &buf, 0);
}
