#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { kSceneHeapSize = 0x22c00, kSceneObjectSize = 0x338, kSceneFieldOffset = 0x170 };
#else
enum { kSceneHeapSize = 0x24000, kSceneObjectSize = 0x33c, kSceneFieldOffset = 0x174 };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

int GetWord0x0_0200fb8c(int* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void SetFlagsAt0x244_020a28a0(unsigned char* obj, unsigned char mask);
void SetByteField0x253_020397c0(void* obj);
void PushInputLogA_020a1df8(int id);
void PushInputLogB_020a1ef0(int id);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;
extern "C" void func_020a0cc4(unsigned int);
extern "C" void func_020a0c0c(void);

extern "C" void func_ov003_02154720(void* mem, unsigned char b);
extern "C" void func_ov003_021544ec(void* mem, SafeAllocator* alloc);
extern "C" int func_ov003_02154af4(void* mem, unsigned int scaleCount);
extern "C" void func_ov003_021549a8(void* mem);

extern "C" ARM void func_ov017_021c1264(void);
extern "C" void func_ov017_021c1394(void* self);

extern int data_ov017_021d8478;

struct Obj021c1404 {
	unsigned char pad0;
	unsigned char flag1;
	char pad2[6];
	SafeAllocator allocator;
	unsigned char step;
	unsigned char pad3;
	unsigned char field1e;
};

// USA: func_ov017_021c1404  (semantic: AdvanceEncounterSequenceStep_021c1404)
extern "C" ARM void func_ov017_021c1404(struct Obj021c1404* obj) {
	GameState* battle = GameState::GetInstance();
	int* word0 = (int*)GetWord0x0_0200fb8c((int*)battle);
	GameObject* combatant = battle->GetUnknownGameObject();
	int fieldVal = GetFieldIfFlag4_020100f8((char*)battle);
	SetBitsInField4_0203b4d8((unsigned int*)word0, 0xc0);
	if (combatant) {
		CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
	}
	SetFlagsAt0x244_020a28a0((unsigned char*)fieldVal, 3);
	unsigned char step = obj->step;

	if (step == 0) {
		func_020a0cc4(kSceneHeapSize);
		void* buf = AllocateAligned4_02012d88(&data_02114e20, kSceneHeapSize);
		if (!buf) {
			func_020a0c0c();
			obj->flag1 = 1;
			return;
		}
		obj->allocator.CreateTypeA(buf, kSceneHeapSize);
		obj->allocator.Reset();
		void* mem = obj->allocator.Allocate(kSceneObjectSize);
		data_ov017_021d8478 = (int)mem;
		if (!mem) {
			func_020a0c0c();
			obj->flag1 = 1;
			return;
		}
		PushInputLogA_020a1df8(3);
		PushInputLogB_020a1ef0(1);
		func_ov003_02154720((void*)data_ov017_021d8478, obj->field1e);
		func_ov003_021544ec((void*)data_ov017_021d8478, &obj->allocator);
		func_ov017_021c1264();
		obj->step = obj->step + 1;
		return;
	}
	if (step == 1) {
		unsigned int scaleCount = battle->GetTickCount();
		if (func_ov003_02154af4((void*)data_ov017_021d8478, scaleCount) == 0) return;
		FontBankLoader* val = GetGlobal02109400_02094a00();
		BlankFunction02094b40(val);
		func_02094ab0(val);
		BlankFunction02094b34(val, 0x6f, 0x1388, 1, 1);
		obj->step = obj->step + 1;
		return;
	}
	if (step == 2) {
		if (!AlwaysTrue02094b4c(GetGlobal02109400_02094a00())) return;
		func_ov003_021549a8((void*)data_ov017_021d8478);
		obj->step = obj->step + 1;
		return;
	}
	if (step != 3) return;

	int* dispReg = (int*)0x4000000;
	unsigned int memField = *(unsigned int*)((char*)data_ov017_021d8478 + kSceneFieldOffset);
	*dispReg = (memField << 8) | (*dispReg & ~0x1f00);
	ClearBitsInField4_0203b4e8((unsigned int*)word0, 0xc0);
	SetByteField0x253_020397c0(combatant);
	ClearFlagBits_020a28b0((unsigned char*)fieldVal, 3);
	func_ov017_021c1394(obj);
	func_020a0c0c();
	obj->flag1 = 1;
	func_ov017_021c1264();
}
