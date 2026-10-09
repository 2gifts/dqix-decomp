#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov000_0217228c(void* obj);
extern "C" void* func_0202ae18(GameState* gs);

struct Entry02174b14 {
    char pad0[0x24];
    unsigned char field24;
    char pad25[0x44 - 0x25];
    int posX;
    int posY;
    int combatantId;
    char pad50[0x448 - 0x50];
};

struct Obj02174b14 {
    char pad0[0x6c];
    signed char order[4];
    char pad70[0x958 - 0x70];
    struct Entry02174b14 entries[4];
};

// USA: func_ov000_02174b14
extern "C" ARM void func_ov000_02174b14(struct Obj02174b14* obj) {
    func_ov000_0217228c(obj);
    func_0202ae18(GameState::GetInstance());
    int any = 0;
    for (int i = 0; i < 4; i++) {
        struct Entry02174b14* entry = &obj->entries[obj->order[i]];
        if (entry->combatantId < 0) {
            continue;
        }
        int flag = (entry->field24 & 4) ? 1 : 0;
        any = (any | flag) ? 1 : 0;
    }
    int y = 0;
    if (!any) {
        y = 0x20;
    }
    struct Entry02174b14* entry;
    for (int j = 0; j < 4; j++) {
        entry = &obj->entries[obj->order[j]];
        int id = entry->combatantId;
        int valid = 0;
        if (id >= 0) {
            valid = id <= 3;
        }
        if (!valid) {
            continue;
        }
        entry->posX = 0;
        entry->posY = y;
        if (entry->field24 & 4) {
            y += 0x48;
        } else {
            y += 0x28;
        }
    }
}
