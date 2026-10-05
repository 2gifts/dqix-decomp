// External entry names follow the fork's symbols.txt at b399f53.
// Local argument views remain provisional; see contribution interface notes.
#include "globaldefs.h"
#include "World/Object3D.h"

// Partial consumer views; record flags and attachment meanings are provisional.
struct BestiaryDrawMonster {
    char unknown[0x13];
    unsigned char unknownFlag : 1;
    unsigned char eligible : 1;
    unsigned char remainingFlags : 6;
};
struct BestiaryDrawRecord {
    unsigned int count : 10;
    unsigned int special : 1;
    unsigned int unknown : 21;
};
struct BestiaryPositionedItem {
    char unknown00[0x14];
    int x, y;
    char unknown1c[0xc];
};
struct BestiaryDrawState {
    void* unknown00;
    void* list;
    BestiaryPositionedItem* items;
    char unknown0c[0x34];
    Object3D* model;
    void* unknown44;
    BestiaryDrawMonster* monster;
    BestiaryDrawMonster* loadingMonster;
    BestiaryDrawRecord* record;
    BestiaryDrawRecord* loadingRecord;
    void* labels;
    char unknown5c[0x20];
    unsigned char state;
    char unknown7d[4];
    unsigned char flags;
    char unknown82[0xe];
    unsigned char offsetEnabled[3];
    unsigned char unknown93;
    unsigned char currentIcon;
};
// Whole-tree and both teams' exported patch audit found no prior declarations.
extern "C" {
void _Z25ComputeShortPair_021e2bdcPviPsS0_(void*, short, short*, short*);
void func_0205ac40(void*, void*);
extern const short data_ov014_0218948c[6];
extern const short data_ov014_0218948e[6];
extern const short data_ov014_02189478[3];
}

extern "C" ARM void func_ov014_02184a64(BestiaryDrawState* state) {
    if (!state->state) return;
    if (!state->monster || !state->record) return;
    int eligible = state->monster->eligible;
    if (!eligible) return;
    int first = 0, second = 0;
    if (state->flags & 0x20) {
        if (state->loadingMonster && state->loadingMonster->eligible) first = 1;
        if (state->loadingRecord && state->loadingRecord->special) second = 1;
    } else {
        if (eligible) first = 1;
        if (state->record->special) second = 1;
    }
    if (first || second) {
        for (int i = 0; i < 3; ++i) {
            short x = 0, y = 0;
            int visible = i == 2 ? second : first;
            if (visible) {
                _Z25ComputeShortPair_021e2bdcPviPsS0_(state->labels, data_ov014_02189478[i], &x, &y);
                if (state->offsetEnabled[i]) {
                    x += data_ov014_0218948c[2*i];
                    y += data_ov014_0218948e[2*i];
                }
                BestiaryPositionedItem* item = &state->items[i];
                item->x = x << 12;
                item->y = y << 12;
                if (state->currentIcon) func_0205ac40(state->list, &state->items[i]);
            }
        }
    }
    if ((state->flags & 4) && state->model) state->model->Draw(true);
}
