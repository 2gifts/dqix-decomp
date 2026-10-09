#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/ElementLookup.h"
#include "World/Zone3D.h"

struct CombatWork_021e58f0 {
    char pad0[0xec8];
    Zone3D zone;
    short zoneAngle;
};

struct ZoneInfo_021e58f0 {
    unsigned short field_0;
    unsigned short zoneId;
};

struct Args_021e58f0 {
    char pad0[8];
    const char* zoneName;
};

struct State_021ef988 {
    char pad0[0x20];
    int phase;
};

struct Reset021e3158;

CombatWork_021e58f0* GetActiveCombatWork(void);
extern "C" ZoneInfo_021e58f0* func_ov017_021b8478(void* obj);
extern "C" void _ZN6Zone3D10SwitchZoneEt(Zone3D* zone, int id, int flag);
extern "C" void _Z25StoreAndMaybeCopy02018f6cP11Obj02018f6cs(Zone3D* zone, short angle);
void ResetStruct_021e3158(Reset021e3158* p);

extern State_021ef988 data_ov025_021ef988;
extern Reset021e3158 data_ov025_021ef9a8;

// USA: func_ov025_021e58f0
extern "C" ARM int func_ov025_021e58f0(Args_021e58f0* args) {
    CombatWork_021e58f0* work = GetActiveCombatWork();
    Zone3D* zone = &work->zone;
    ZoneInfo_021e58f0* info = func_ov017_021b8478(func_ov017_0218b5b0()->unknown_ptr_3718);
    if (data_ov025_021ef988.phase == 0) {
        unsigned short id = info->zoneId;
        if (args->zoneName != 0) {
            List0209998c* list = (List0209998c*)GetPtrField0x468(GameState::GetInstance());
            Elem0209998c* elem = FindElementByName0209998c(list, args->zoneName);
            if (elem == 0) {
                return 1;
            }
            id = elem->f0;
        }
        _ZN6Zone3D10SwitchZoneEt(zone, id, 0);
        data_ov025_021ef988.phase = 1;
    } else if (data_ov025_021ef988.phase == 1 && zone->unknown_424_ == 0) {
        _Z25StoreAndMaybeCopy02018f6cP11Obj02018f6cs(zone, work->zoneAngle);
        ResetStruct_021e3158(&data_ov025_021ef9a8);
        return 1;
    }
    return 0;
}
