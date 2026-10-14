#include <globaldefs.h>
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0(void);
int AppendLineTag02041cc0(char* dst, int a1);

struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

extern "C" void func_02046608(int a, int b, void* c, void* d, int e, int f, int g);

struct Combatant021e853c { char pad[0xf68]; int f68; int f6c; };

// USA: func_ov023_021e853c  (semantic: AppendTagAndStoreEntries_021e853c)
extern "C" ARM void func_ov023_021e853c(void* obj) {
    struct Combatant021e853c* combatant = (struct Combatant021e853c*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    int field = GetGlobalField0x1c020421a0();
    AppendLineTag02041cc0(*(char**)((char*)obj + 0x5d8), 0x18);
    int arr[2] = { combatant->f6c, combatant->f68 };
    for (int i = 0; i < 2; i++) {
        StoreInArray0x8b0_020465c0((struct StoreStruct*)field, i, arr[i]);
        SetByteAtIndex_020465d8((unsigned char*)field, i, 1);
        SetByteInRange_020465f0((unsigned char*)field, i, 0xa);
    }
    int key = GetFieldByKey020e0434((struct Container020e0310*)((char*)obj + 0x4c), 1);
    func_02046608(field, 0xa, (void*)key, *(void**)((char*)obj + 0x5d8), 0x100, 0, 0);
}
