#include <globaldefs.h>
#include "GameState/GameState.h"

void FilterSlotsWithFlag0x800020dc4d0(signed char* out, signed char* outCount);
struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendFormatted02041fac(char* buf, int a, int b);
int AppendPaletteTag_02041e70(char* dst, int palette);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int CallFunc020e0434With02153694_020e51cc(int value);
extern "C" int func_ov002_02159774(void* base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215e250
extern "C" ARM void func_ov002_0215e250(unsigned char* base, char* dst, int flag) {
    if (dst == NULL) return;

    GameState* bs = GameState::GetInstance();
    int cursor = *(short*)(base + 0x1bf6);

    signed char idArr[7];
    signed char count;
    FilterSlotsWithFlag0x800020dc4d0(idArr, &count);

    signed char matched = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, idArr[i]);
        if (c != NULL) {
            if (CheckField0x56bLowNibble((struct Obj02061bd8*)c) != 0) {
                matched++;
            }
        }
    }
    count = count - matched;

    int idx = 0;
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    int field = GetFieldByKey020e0434((struct Container020e0310*)(base + 0x20), 2);
    AppendFormatted02041fac(dst, field, 0x16);

    for (int i2 = 0; i2 < count; i2++) {
        GameObject* c800 = bs->GetPartyMemberByIndex(idArr[idx]);
        if (c800 != NULL) {
            GameObject* c100 = GetCombatantWithFlag0x100_0200ff1c(bs, idArr[idx]);
            if (CheckField0x56bLowNibble((struct Obj02061bd8*)c100) != 0) {
                for (int attempt = 0; attempt < 4; attempt++) {
                    idx = (idx + 1) % 4;
                    if (idx == 0) break;
                    GameObject* c3 = GetCombatantWithFlag0x100_0200ff1c(bs, idArr[idx]);
                    if (c3 == NULL) continue;
                    if (CheckField0x56bLowNibble((struct Obj02061bd8*)c3) != 0) continue;
                    bs->GetPartyMemberByIndex(idArr[idx]);
                    break;
                }
            }

            int pal = func_ov002_02159774(base, idArr[idx], 0, 1, 1);
            AppendPaletteTag_02041e70(dst, pal);
            AppendNameTag_02041b70(dst, i2, (const char*)(base + 0x1ab0 + idArr[idx] * 0x3c));
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendString02042058(dst, *(const char**)(base + 0x1000 + 0xbdc));

            idx++;
        }
    }

    AppendNameTag_02041b70(dst, count, (const char*)CallFunc020e0434With02153694_020e51cc(0x1a));
}
