#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Move_021e07b0 {
    int w0;
    unsigned int id : 12;
    unsigned int pad4 : 20;
    char pad8[0x1c];
    unsigned int f24a : 10;
    unsigned int f24b : 10;
    unsigned int messageId : 10;
    unsigned int f24hi : 2;
};

struct Flag_021e07b0 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021e07b0 { char pad0[0xc]; void* field0xc; void* field0x10; };

extern "C" unsigned long long func_ov024_021e4b14(struct Obj_021e07b0* obj, int slot, int id, struct Move_021e07b0* move, int flag);
extern "C" void* func_ov000_0215e958(void* a0);
struct FlagObj_021e05e4;
extern "C" int _Z30IsFlagBit12Field18Set_021e05e4P16FlagObj_021e05e4(struct FlagObj_021e05e4* obj);
void SetBool0x180Clear0x17f(unsigned char* obj, int value);
void ClearFlag0x1000AndBytes7eA1(unsigned char* obj);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
struct ArrayContainsByteStruct;
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);
extern "C" void _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(unsigned char* obj, int amount);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

// JPN: func_ov024_021e1048
// USA: func_ov024_021e07b0
extern "C" ARM void* func_ov024_021e07b0(struct Obj_021e07b0* obj, unsigned char slot, int id, struct Move_021e07b0* move) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    unsigned long long result = func_ov024_021e4b14(obj, slot, id, move, 1);
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    int added = 0;
    if (_Z30IsFlagBit12Field18Set_021e05e4P16FlagObj_021e05e4((struct FlagObj_021e05e4*)c)) {
        int isParty = (id >= 0 && id <= 3);
        if (!isParty) {
            SetBool0x180Clear0x17f((unsigned char*)c, 1);
        }
        ClearFlag0x1000AndBytes7eA1((unsigned char*)c->currentStats_);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, 0x164);
        added = 1;
        if (ArrayContainsByte((struct ArrayContainsByteStruct*)GetPtrField0x2a04(GameState::GetInstance()), slot) && move->id == 0xc6) {
            _Z39IncrementByteCounterCapped0x63_0215a8d4Phi((unsigned char*)obj->field0x10, added);
        }
    }
    if (result != 0) {
        if (!added) {
            _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, 0);
        }
        added = 1;
    }
    if (!added) {
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, (unsigned short)move->messageId);
    }
    struct Flag_021e07b0* fl = (struct Flag_021e07b0*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, result, fl->flag != 0);
    return entry;
}
