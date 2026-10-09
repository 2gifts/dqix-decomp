#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

unsigned short SelectByIndexRange0to3_021da644(int idx, int a, int b);
struct FlagObj_021da9b0;
int IsFlagBit8Set_021da9b0(struct FlagObj_021da9b0* obj);
int CheckFlag0x14Bit0x10Set(unsigned char* stats);

struct Ctx_021e9018 { char pad[0x10]; void* field0x10; };
struct Bits_021e9018 { unsigned short low2 : 2; unsigned short element : 4; unsigned short rest : 10; };

struct KeyEntry_021e9018 { short key; unsigned short pad; };
struct ValueEntry_021e9018 { unsigned short value; unsigned short pad; };

extern struct KeyEntry_021e9018 data_ov024_021fe840[];
extern struct ValueEntry_021e9018 data_ov024_021fe842[];
extern struct KeyEntry_021e9018 data_ov024_021fe7c4[];
extern struct ValueEntry_021e9018 data_ov024_021fe7c6[];

// USA: func_ov024_021e9018
extern "C" ARM int func_ov024_021e9018(struct Ctx_021e9018* ctx, int id, short kind, int mode) {
    if (mode != 0) {
        if (kind == 5) {
            return SelectByIndexRange0to3_021da644(id, 0x63, 0x62);
        }
        int idx = 0;
        while (data_ov024_021fe840[idx].key != -1) {
            if (kind == data_ov024_021fe840[idx].key) {
                return data_ov024_021fe842[idx].value;
            }
            idx++;
        }
    } else {
        GameObject* c = GetCombatantByID((int)ctx->field0x10, id);
        if (!c) return 0;
        if (IsFlagBit8Set_021da9b0((struct FlagObj_021da9b0*)c) &&
            (kind == 3 || kind == 4 || kind == 5 || kind == 8)) {
            return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
        }
        if (CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats_) && (unsigned short)(short)(kind - 2) <= 6) {
            return SelectByIndexRange0to3_021da644(id, 0x26d, 0x1b);
        }
        struct Bits_021e9018* b = (struct Bits_021e9018*)((char*)c->currentStats_ + 0x22);
        int element = b->element;
        if (element != kind) return 0;
        if (element == 5) {
            return SelectByIndexRange0to3_021da644(id, 0x61, 0x60);
        }
        int idx = 0;
        while (data_ov024_021fe7c4[idx].key != -1) {
            if (element == data_ov024_021fe7c4[idx].key) {
                return data_ov024_021fe7c6[idx].value;
            }
            idx++;
        }
    }
    return 0;
}
