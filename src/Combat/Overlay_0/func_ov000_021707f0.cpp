#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>

struct Struct_0205d81c;
struct ShortArrays0204c610;
struct Elem_0205d81c {
    char pad_00[0xac];
    short x;
    short y;
    char pad_b0[0x12];
    unsigned short suppressionFlags;
};
struct CombatPaletteStats {
    char pad_00[0x3b];
    unsigned char : 3;
    unsigned char active : 1;
    unsigned char mode : 4;
};
struct PaletteCursor {
    char pad_00[0x320];
    char drawEntry[0x14];
    int x;
    int y;
    char pad_33c[6];
    unsigned char size;
    char pad_343[3];
    unsigned char visible;
};
struct CursorList {
    char storage[0x54];
};
struct BattlePaletteState {
    char pad_00[0x11c];
    CursorList cursorList;
    PaletteCursor* cursor;
    char pad_174[8];
    int combatantIndex;
    char pad_180[0x1d60 - 0x180];
    signed char states[8];
    signed char stateIndex;

    CursorList* GetCursorList() { return &cursorList; }
};
struct PaletteOwner {
    char pad_00[0x38];
    Struct_0205d81c* elements;
    char pad_3c[0x430 - 0x3c];
    unsigned short colors[2];
    float phase;
};

int GetWord0x0(int*);
void* GetOffsetPtr02160f08(void*);
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);
int IsField0x9cEqual3(unsigned char*);
void GetFourShortsAtIndex(ShortArrays0204c610*, int, short*, short*, short*, short*);
extern "C" void* func_ov017_021b8468(void*);
extern "C" double func_02009424(double);
extern "C" void func_0205ac40(void*, void*);
struct PaletteChannel {
    short value;
    short pad[2];
};
extern PaletteChannel data_ov000_02183488[];
extern PaletteChannel data_ov000_0218348a[];
extern PaletteChannel data_ov000_0218348c[];

// USA: func_ov000_021707f0
extern "C" ARM void func_ov000_021707f0(PaletteOwner* owner) {
    float amount;
    GameState* state = GameState::GetInstance();
    if (!state) {
        return;
    }
    GameResources* resources = (GameResources*)GetWord0x0((int*)state);
    if (!resources || !resources->unknown_ptr_3718) {
        return;
    }
    void* battle = func_ov017_021b8468(resources->unknown_ptr_3718);
    if (!battle) {
        return;
    }
    BattlePaletteState* palette = (BattlePaletteState*)GetOffsetPtr02160f08(battle);
    if (!palette) {
        return;
    }
    CursorList* list = palette->GetCursorList();
    if (!list || !palette->cursor) {
        return;
    }
    PaletteCursor* cursor = palette->cursor;
    if (palette->states[palette->stateIndex] != 13) {
        return;
    }
    short left = 0;
    short top = 0;
    short right = 0;
    short bottom = 0;
    Elem_0205d81c* element = FindElementByC40205d81c(owner->elements, 13);
    signed char colorIndex = 0;
    short slot = 0;
    GameObject* unit = GameState::GetInstance()->GetCombatantByIndex(palette->combatantIndex);
    if (unit) {
        CombatPaletteStats* stats = (CombatPaletteStats*)unit->currentStats_;
        if (stats->active) {
            if (stats->mode == 1) {
                colorIndex = 4;
                slot = 1;
            } else {
                slot = 1;
                if (stats->mode == 0) {
                    colorIndex = 0;
                }
            }
        }
    }
    if (!element || !slot) {
        return;
    }
    if (!IsField0x9cEqual3((unsigned char*)element)) {
        return;
    }
    if (element->suppressionFlags) {
        return;
    }
    short x = element->x;
    short y = element->y;
    GetFourShortsAtIndex((ShortArrays0204c610*)element, 5, &left, &top, &right, &bottom);
    cursor->x = (left + (short)(x * 8)) << 12;
    cursor->y = (top + (short)(y * 8)) << 12;
    cursor->size = 0x7c;
    cursor->visible = 0;
    if (colorIndex) {
        float wave = (float)func_02009424(owner->phase);
        int choice = 0;
        if (wave >= 0.5f) {
            choice = 1;
        }
        slot = 0;
        for (; slot < 2; colorIndex += 2, ++slot) {
            int index = colorIndex + choice;
            owner->colors[slot] = data_ov000_02183488[index].value |
                (data_ov000_0218348a[index].value << 5) | (data_ov000_0218348c[index].value << 10);
        }
    } else {
        amount = (float)func_02009424(owner->phase);
        slot = 0;
        for (; slot < 2; colorIndex += 2, ++slot) {
            int index = colorIndex;
            int next = colorIndex + 1;
            short red = data_ov000_02183488[index].value +
                (int)((data_ov000_02183488[next].value - data_ov000_02183488[index].value) * amount);
            short green = data_ov000_0218348a[index].value +
                (int)((data_ov000_0218348a[next].value - data_ov000_0218348a[index].value) * amount);
            short blue = data_ov000_0218348c[index].value +
                (int)((data_ov000_0218348c[next].value - data_ov000_0218348c[index].value) * amount);
            owner->colors[slot] = red | (green << 5) | (blue << 10);
        }
    }
    CleanInvalidateCacheRange(owner->colors, 4);
    LoadToSubObjStandardPalette(owner->colors, 0x142, 4);
    func_0205ac40(list, cursor->drawEntry);
}
