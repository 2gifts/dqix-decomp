#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"

extern "C" void* func_02012fe4(void* self);
unsigned char* GetElementStride0x24(unsigned char* p, int i);

struct Header02193290 {
    unsigned char data[0xc0];
};

extern Header02193290 data_ov017_021d6318;

struct Params02193290 {
    Header02193290 header;
    unsigned char pad_c0[0x900 - 0xc0];
    int field900;
    int field904;
    Vector3i position;
    int field914;
    int field918;
    unsigned char pad_91c[0x980 - 0x91c];
};

struct Element02193290 {
    Vector3i position;
    short fieldC;
};

struct Owner02193290 {
#if defined(jpn)
    unsigned char pad[0x497];
#else
    unsigned char pad[0x477];
#endif
    unsigned char count;
};

extern "C" int func_ov017_02192b48(Params02193290* params, int a, int b, int c, int d, int e, Vector3i* pos, int f, int g, int h, int* out, int i, int index, int j);

static inline fix32_t Square(fix32_t x) {
    return FIX32_MULTIPLY(x, x);
}

// JPN: func_ov017_02193e58
// USA: func_ov017_02193290
extern "C" ARM int func_ov017_02193290(int a, int b, int c, Vector3i* pos, int d, int e, int f) {
    Owner02193290* owner = (Owner02193290*)func_02012fe4(GameState::GetInstance());
    int total = 0;
    for (int i = 0; i < owner->count; i++) {
        Element02193290* elem = (Element02193290*)GetElementStride0x24((unsigned char*)owner, i);
        if (elem == NULL) {
            continue;
        }
        Vector3i delta = *pos;
        Vector3i elemPos = elem->position;
        if (fix32abs(delta.y - elemPos.y) > 0x1000) {
            continue;
        }
        delta.y = 0;
        elemPos.y = 0;
        Vector3fix_Subtract(&delta, &elemPos, &delta);
        if (Square(delta.x) + Square(delta.z) > 0x1000) {
            continue;
        }
        Params02193290 params;
        memset(&params, 0, sizeof(params));
        memcpy(&params.header, &data_ov017_021d6318, sizeof(Header02193290));
        params.field900 = 8;
        params.field904 = 1;
        params.position = elem->position;
        params.field918 = elem->fieldC;
        int result = 0;
        total += func_ov017_02192b48(&params, a, 8, b, 1, c, pos, d, e, 1, &result, 0, i, f);
    }
    return total;
}
