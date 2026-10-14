#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
extern int AbsPlus159IfNegative0215ad2c(int x);
extern SafeAllocator* data_ov001_021658b8[8];
void* GetFieldPtrAt0x5ca4_02010768(void* obj);
void SetField0x3b0Value_020100c4(GameState* battleStruct, int value);

struct Obj0204a120;
void InitState0204a120(struct Obj0204a120* obj);

struct Owner0204a3f0;
struct Holder0204a3f0;
void SetHolderAndMarkNode0204a3f0(struct Owner0204a3f0* owner, struct Holder0204a3f0* h);

void SetName0204a440(char* obj, const char* src);
void SetStringField0234_0204a464(char* obj, const char* src);
void SetStringField0244_0204a488(char* obj, const char* src);

struct S0204a5dc;
void SetField0x220(struct S0204a5dc* p, int v);

// USA: func_ov001_02160768  (semantic: AllocateAndInitStateNode_02160768)
extern "C" ARM int func_ov001_02160768(char* self) {
	GameState* bs = GameState::GetInstance();
	SafeAllocator* allocator = data_ov001_021658b8[0];
	void* fieldPtr = GetFieldPtrAt0x5ca4_02010768(bs);

	int a = func_ov017_021d60f4(self);
	void* name = func_ov017_021d612c(self + 0x8);
	void* str1 = func_ov017_021d612c(self + 0x10);
	void* str2 = func_ov017_021d612c(self + 0x18);
	int b = func_ov017_021d60f4(self + 0x20);

	int id1 = AbsPlus159IfNegative0215ad2c(a);
	int id2 = AbsPlus159IfNegative0215ad2c(b);

	GameObject* combatant1 = bs->GetGameObjectByIndex(id1);
	if (combatant1 == NULL) return 0;

	GameObject* combatant2 = bs->GetGameObjectByIndex(id2);
	if (combatant2 == NULL) return 0;

	void* newObj = allocator->Allocate(0x268);

	*(void**)((char*)fieldPtr + 0x4) = GetField0x3b0Value_020100bc(bs);

	InitState0204a120((struct Obj0204a120*)newObj);
	SetHolderAndMarkNode0204a3f0((struct Owner0204a3f0*)newObj, (struct Holder0204a3f0*)combatant1);
	SetName0204a440((char*)newObj, (const char*)name);
	SetStringField0234_0204a464((char*)newObj, (const char*)str1);
	SetStringField0244_0204a488((char*)newObj, (const char*)str2);
	SetField0x220((struct S0204a5dc*)newObj, (int)combatant2);

	((Object3D*)((unsigned char*)combatant1))->EnableFlag(1);
	((Object3D*)((unsigned char*)combatant1))->EnableFlag(0x20);

	SetField0x3b0Value_020100c4(bs, (int)newObj);
	return 1;
}
