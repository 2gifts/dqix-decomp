#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_377d4;
struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);
struct Vec3s32_020c3030 { int x; int y; int z; };

// USA: func_ov017_021bf6fc  (semantic: AdvanceProximityCountdown_021bf6fc)
extern "C" ARM int func_ov017_021bf6fc(unsigned char* obj) {
	GameState* battle = GameState::GetInstance();
	GameObject* combatant = battle->GetUnknownGameObject();
	unsigned char* target = *(unsigned char**)(obj + 0xc);
	struct Vec3s32_020c3030 pos = *(struct Vec3s32_020c3030*)((char*)combatant + 0x44);
	struct Vec3s32_020c3030 refPos;
	refPos.x = *(int*)(target + 0x8);
	refPos.y = pos.y;
	refPos.z = *(int*)(target + 0x10);
	int dist = Vector3fix_Distance((const Vector3fix*)&pos, (const Vector3fix*)&refPos);
	*(short*)(obj + 0x14) -= 1;
	if (dist < 0x199 || (*(short*)(obj + 0x14) < 0 && !((Object3D*)((struct S_377d4*)combatant))->IsTransitioningAnimations())) {
		SetByteIfChanged02033b68((struct Obj02033b68*)combatant, 0);
		*(short*)(obj + 0x14) = -1;
		return 2;
	}
	return 1;
}
