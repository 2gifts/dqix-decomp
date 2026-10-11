// JPN: func_ov017_021ba77c
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct SearchStruct0202c1a4;
extern "C" SearchStruct0202c1a4* func_0202ae18(void);
int CheckField0NonZero(int* obj);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);

extern "C" int func_ov017_021b9bcc(int id, const char* name);

struct Data021ba280_8438 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
    unsigned char pad8[8];
    int field10;
};
extern Data021ba280_8438 data_ov017_021d8438;

struct Data021ba280_7c54 {
    signed char byte0;
    signed char byte1;
};
extern Data021ba280_7c54 data_ov017_021d7c54;

// USA: func_ov017_021ba280
extern "C" ARM int func_ov017_021ba280(Script::Parameter* params, int count) {
    if (data_ov017_021d8438.field10 != 0) return 1;
    if (data_ov017_021d7c54.byte0 > -1) return 1;
    if (data_ov017_021d8438.byte1 != 0) return 1;
    if (data_ov017_021d7c54.byte1 > -1) return 1;

    GameState::GetInstance();
    SearchStruct0202c1a4* search = func_0202ae18();
    if (!CheckField0NonZero((int*)search)) return 1;
    if (GetSearchStructCurrentArrEntry(search) == 0) return 1;

    int lo = params[0].ToInt();
    Script::Parameter* hiParam = &params[1];
    params += 2;
    int hi = hiParam->ToInt();
    if (lo >= 0 && (data_ov017_021d8438.field4 < lo || hi < data_ov017_021d8438.field4)) return 1;

    if (count >= 5) {
        int daytimeOnly = params->ToInt();
        params++;
        if (daytimeOnly != 0) {
            if (GameState::GetInstance()->IsMorningDayOrEvening()) return 1;
            data_ov017_021d8438.byte2 = 1;
        }
    } else {
        if (data_ov017_021d8438.byte2 != 0) return 1;
    }

    int id = params[0].ToInt();
    const char* name = params[1].ToString();
    if (name == NULL) return 0;
    if (func_ov017_021b9bcc(id, name) != 0) data_ov017_021d8438.byte0 = 1;
    return 1;
}
