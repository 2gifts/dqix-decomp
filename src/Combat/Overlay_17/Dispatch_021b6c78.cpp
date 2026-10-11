#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void _Z23InitRegionArray02087628Pc(char* p);
#define InitRegionArray02087628 _Z23InitRegionArray02087628Pc

extern "C" unsigned char _Z19CopyOutRegion0x5718PcPv(void* src, void* dst);
#define CopyOutRegion0x5718 _Z19CopyOutRegion0x5718PcPv

int GetField0x3acValue(GameState* b);

extern "C" void __clear(void* buf, int size);

extern "C" void* _Z15GetFieldAt0x150Ph(unsigned char* p);
#define GetFieldAt0x150 _Z15GetFieldAt0x150Ph

extern "C" signed char _Z27GetSignedField6Bit_021b6c2cii(int a, int b);
#define GetSignedField6Bit_021b6c2c _Z27GetSignedField6Bit_021b6c2cii

struct Base02087510;
extern "C" int _Z28FindFreeSlotAndStore02087510P12Base02087510cPv(Base02087510* base, char id, void* data);
#define FindFreeSlotAndStore02087510 _Z28FindFreeSlotAndStore02087510P12Base02087510cPv

#define GetCombatantAtField0x3ac _Z24GetCombatantAtField0x3acP9GameState

struct Obj020397cc;
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc* p, int flag);
#define CancelPendingAction020397cc _Z27CancelPendingAction020397ccP11Obj020397cci

// USA: func_ov017_021b6c78  (semantic: Dispatch_021b6c78)
extern "C" ARM void func_ov017_021b6c78(void) {
    GameState* battle = GameState::GetInstance();
    void* region = GetPtrField0x2a04(battle);
    InitRegionArray02087628((char*)region);

    if (*((unsigned char*)region + 0xf7c) <= 1) {
        return;
    }

    char buf1[4];
    char buf2[0x10];
    unsigned char count = CopyOutRegion0x5718(battle, buf1);

    for (unsigned char idx = 0; idx < count; idx = (unsigned char)(idx + 1)) {
        char id = buf1[idx];
        if (id != GetField0x3acValue(battle)) {
            __clear(buf2, 0x10);
            GameObject* combatant = GetCombatantWithFlag0x100(battle, id);
            if (combatant) {
                unsigned char* fp = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
                memcpy(buf2, fp + 0x54 + 0x400, 0x10);
            }
            signed char v = GetSignedField6Bit_021b6c2c(id, 1);
            if (v >= 0) {
                FindFreeSlotAndStore02087510((Base02087510*)region, v, buf2);
            }
        }
    }

    GameObject* c = battle->GetProtagonist();
    if (c) {
        CancelPendingAction020397cc((Obj020397cc*)c, 1);
    }
}
