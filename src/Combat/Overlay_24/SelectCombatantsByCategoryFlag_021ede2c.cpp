#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void __clear(void* buf, int n);
struct S_flag4000000;
int IsFlagBit67108864Set_021edc08(struct S_flag4000000* obj);

struct Obj_021ede2c { int field0; };

struct Buf4_021ede2c { short v[4]; };
extern struct Buf4_021ede2c data_ov024_021fea44;

// USA: func_ov024_021ede2c  (semantic: SelectCombatantsByCategoryFlag_021ede2c)
extern "C" ARM int func_ov024_021ede2c(struct Obj_021ede2c* obj) {
    struct Buf4_021ede2c buf = data_ov024_021fea44;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    short out[4];
    __clear(out, 8);
    unsigned short n = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (!IsFlagBit67108864Set_021edc08((struct S_flag4000000*)c)) continue;
        out[n++] = buf.v[i];
    }
    return (n * 3 < count) ? 1 : 0;
}
