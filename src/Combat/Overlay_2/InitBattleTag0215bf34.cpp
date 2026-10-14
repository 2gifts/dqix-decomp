#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void func_ov002_0215be00(void* obj, int a1, int a2, int a3);
void* GetPtrField0x2a04_02010828(GameState* battleStruct);
int GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void* global);

struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);

int CallFunc020e0434With02153694_020e51cc(int value);
extern "C" void func_02046608(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
extern "C" void func_0205d0e0(void* obj, int val);

struct BufOv0215bf34 { char pad[0xbd0]; void* buf; };

// USA: func_ov002_0215bf34
ARM void InitBattleTag0215bf34(char* base) {
    func_ov002_0215be00(base, 0x29, 0x15, 0x15);

    struct StoreStruct* combatant = (struct StoreStruct*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    int field = GetGlobalField0x1c020421a0();
    func_02046380((void*)field);

    StoreInArray0x8b0_020465c0((struct StoreStruct*)field, 0, *(int*)((char*)combatant + 0xf6c));
    SetByteAtIndex_020465d8((unsigned char*)field, 0, 1);
    SetByteInRange_020465f0((unsigned char*)field, 0, 7);

    memset(((struct BufOv0215bf34*)(base + 0x1000))->buf, 0, 0x960);

    int fmt = CallFunc020e0434With02153694_020e51cc(0x3f1);
    func_02046608(field, 8, (void*)fmt, ((struct BufOv0215bf34*)(base + 0x1000))->buf, 0x100, 0, 0);

    func_0205d304(base + 0x2c8 + 0xc00, ((struct BufOv0215bf34*)(base + 0x1000))->buf, 0, 0, 0, 0, 0, 0);
    func_0205d0e0(base + 0x2c8 + 0xc00, 4);
}
