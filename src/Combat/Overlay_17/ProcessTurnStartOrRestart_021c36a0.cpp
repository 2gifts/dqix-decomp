#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* func_0202ae18(void);
void* GetData02100044(void);
void* GetData02153637(void);
void* GetData02153634(void);
extern "C" int func_0202b000(void* obj);
extern "C" void func_ov017_021c37a4(void);
void OrByte0x1029With0x30ClearField0x1034(unsigned char* obj);
int SetStateToThreeAndDispatch0202b800(int* p);
extern "C" void func_0205e22c(void* p);
struct SlotTable020e3004;
void InitSlotTable020e3004(struct SlotTable020e3004* p);
struct Bytes020e358c;
void ClearThreeBytes020e358c(struct Bytes020e358c* s);
void ClearTwoBytesAtField_02195748(unsigned char* base);
void CollectValidCombatants02010890(GameState* bs, int* outList, int* outCount);
extern "C" void __clear(void* buf, int len);
int StringLength(const char* s);
extern "C" void func_0202c360(void* obj, char* name);
void ClearBufferAndFlag_021972cc(char* p);
void ClearByteField17182_02195520(void* obj);

// JPN: func_ov017_021c3b74
// USA: func_ov017_021c36a0  (semantic: ProcessTurnStartOrRestart_021c36a0)
extern "C" ARM void func_ov017_021c36a0(void) {
	GameState* bs = GameState::GetInstance();
	void* objA = (void*)(int)((int)func_ov017_0218b5b0());
	void* objB = func_0202ae18();
	GameObject* combatant = bs->GetProtagonist();
	void* d100044 = GetData02100044();
	void* d153637 = GetData02153637();
	void* d153634 = GetData02153634();

	if (func_0202b000(objB) != 0) {
		func_ov017_021c37a4();
		return;
	}

#if !defined(jpn)
	OrByte0x1029With0x30ClearField0x1034((unsigned char*)objB);
#endif
	SetStateToThreeAndDispatch0202b800((int*)objB);
	func_0205e22c(d100044);
	InitSlotTable020e3004((struct SlotTable020e3004*)d153637);
	ClearThreeBytes020e358c((struct Bytes020e358c*)d153634);
	ClearTwoBytesAtField_02195748((unsigned char*)objA);

	int list[4];
	int count;
	CollectValidCombatants02010890(bs, list, &count);

	char buf[20];
	__clear(buf, 0x14);

	int len = StringLength(*(char**)((char*)combatant + 0x134));
	if (len > 0x14) {
		len = 0x14;
	}
	memcpy(buf, *(char**)((char*)combatant + 0x134), len);
	buf[len] = 0;
	buf[0x13] = (char)count;

	func_0202c360(objB, *(char**)((char*)combatant + 0x134));
	ClearBufferAndFlag_021972cc((char*)objA);
	ClearByteField17182_02195520(objA);
}
