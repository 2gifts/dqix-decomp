#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
void* GetData02100044(void);
void* GetData02153637(void);
void* GetData02153634(void);
extern "C" int func_0202b000(void* obj);
extern "C" void func_ov017_021c37a4(void);
void OrByte0x1029With0x30ClearField0x1034(unsigned char* obj);
int SetState2AndCall0202d6c8(void* obj);
extern "C" void func_0205e22c(void* obj);
struct SlotTable020e3004;
void InitSlotTable020e3004(struct SlotTable020e3004* p);
struct Bytes020e358c;
void ClearThreeBytes020e358c(struct Bytes020e358c* s);
void ClearTwoBytesAtField_02195748(unsigned char* base);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_0202c360(void* obj, int val);
extern "C" void func_0202b2f0(void* obj);
void SetField0To5AndField0x1008To1(unsigned char* obj);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void BlankFunction020d84dc(void);
extern "C" void func_ov017_02191108(int, int, int, int, int);
extern "C" void func_ov017_02191234(int a);
extern "C" void func_0202c288(void* obj);
ARM void ClearBufferAndFlag_021972cc(char* p);
void ClearByteField17182_02195520(void* obj);

// JPN: func_ov017_021c3a88
// USA: func_ov017_021c35ac  (semantic: ResetBattleStateAndQueues_021c35ac)
extern "C" ARM void func_ov017_021c35ac(void) {
    GameState* battle = GameState::GetInstance();
    int g = ((int)func_ov017_0218b5b0());
    void* search = func_0202ae18();
    void* d100044 = GetData02100044();
    void* d153637 = GetData02153637();
    void* d153634 = GetData02153634();

    if (func_0202b000(search) != 0) {
        func_ov017_021c37a4();
        return;
    }

#if defined(jpn)

#else
    OrByte0x1029With0x30ClearField0x1034((unsigned char*)search);
#endif

    SetState2AndCall0202d6c8(search);
    func_0205e22c(d100044);
    InitSlotTable020e3004((struct SlotTable020e3004*)d153637);
    ClearThreeBytes020e358c((struct Bytes020e358c*)d153634);
    ClearTwoBytesAtField_02195748((unsigned char*)g);

    GameObject* combatant = battle->GetProtagonist();
    GetFieldAt0x150((unsigned char*)combatant);
    int field134 = *(int*)((char*)combatant + 0x134);
    func_0202c360(search, field134);
    func_0202b2f0(search);
    SetField0To5AndField0x1008To1((unsigned char*)search);
    ClearBitsInWord((unsigned int*)g, 2);
    BlankFunction020d84dc();
    func_ov017_02191108(g, 1, 1, 1, 1);
    func_ov017_02191234(g);
    func_0202c288(search);
    ClearBufferAndFlag_021972cc((char*)g);
    ClearByteField17182_02195520((void*)g);
}
