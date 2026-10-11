#if defined(jpn)
#define data_ov026_021de87c data_ov026_021dee50
#endif
#include <globaldefs.h>
#include "System/Matrix.h"

struct BattleState;

struct PresetEntry {
    int id;
    int params[3];
    Vector3i pos;
};

struct BattleWork {
    #if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    BattleState* battle;
    #if defined(jpn)
    char pad2a0[0x77c4];
#else
    char pad2a0[0x7550];
#endif
    int presetId;
    int presetParams[3];
    Vector3i presetPos;
};

extern "C" void _Z24StoreThreeWords_021d8b98Piiii(int* p, int a, int b, int c);
extern "C" int _Z31FindCombatantWithValue_0215fc8cPvi(void* p0, int targetVal);

extern PresetEntry data_ov026_021de87c[];

// USA: func_ov026_021d8aac
extern "C" ARM void func_ov026_021d8aac(BattleWork* self, int mode, int kind) {
    if (self->battle == 0) {
        return;
    }
    self->presetId = -1;
    for (PresetEntry* e = data_ov026_021de87c; e->id != -1; e++) {
        if (e->id == 0) {
            if (kind == 2) {
                self->presetId = e->id;
                _Z24StoreThreeWords_021d8b98Piiii(self->presetParams, e->params[0], e->params[1], e->params[2]);
                self->presetPos = e->pos;
                return;
            }
        } else if (_Z31FindCombatantWithValue_0215fc8cPvi(self->battle, (short)e->id)) {
            self->presetId = e->id;
            if (e->id == 0x115) {
                e += mode % 3;
            }
            _Z24StoreThreeWords_021d8b98Piiii(self->presetParams, e->params[0], e->params[1], e->params[2]);
            self->presetPos = e->pos;
            return;
        }
    }
}
