#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x1f00
#define REGION_OFFSET_1 0xa5
#define REGION_OFFSET_2 0xa0
#define REGION_OFFSET_3 0xfa0
#define REGION_OFFSET_4 0xf98
#else
#define REGION_OFFSET_0 0x1d00
#define REGION_OFFSET_1 0x6d
#define REGION_OFFSET_2 0x68
#define REGION_OFFSET_3 0xd68
#define REGION_OFFSET_4 0xd60
#endif

#include "GameState/GameState.h"

void* GetData02108e10(void);
void* SearchBothTables02079e2c(char* p, int key);
void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" void* func_ov000_02161318(void* obj, int id);
extern "C" int func_ov000_02171210(void* a, void* b);

// USA: func_ov000_02175b54  (semantic: RegisterCombatEvent_02175b54)
extern "C" ARM void func_ov000_02175b54(void* obj) {
    void* data = GetData02108e10();
    if (data == 0) {
        return;
    }
    signed char idx = *((signed char*)obj + REGION_OFFSET_0 + REGION_OFFSET_1);
    signed short val = *(signed short*)((char*)obj + idx * 2 + 0x10);
    void* tableEntry = SearchBothTables02079e2c((char*)data, val);
    if (tableEntry == 0) {
        return;
    }
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* field2a04 = (unsigned char*)GetPtrField0x2a04(battleStruct);
    signed char combIdx = *(signed char*)(field2a04 + 0xf00 + 0x78);
    char* entry = (char*)func_ov000_02161318(obj, combIdx);
    if (entry == 0) {
        return;
    }
    signed char cnt = *((signed char*)obj + REGION_OFFSET_0 + REGION_OFFSET_2);
    *((char*)obj + 0x1000 + REGION_OFFSET_3) = (char)(cnt + 1);
    int result = func_ov000_02171210(tableEntry, entry);
    signed char cnt2 = *((signed char*)obj + REGION_OFFSET_0 + REGION_OFFSET_2);
    *((char*)obj + cnt2 + 0x1000 + REGION_OFFSET_4) = (char)result;
    *((char*)obj + 0x1c) = entry[0x1d];
}
