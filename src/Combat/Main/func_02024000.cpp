#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void *func_02012fe4(void);
int IsInRange0201b588(int zoneId);
int IsInRange0201b5b0(int zoneId);
void SetElementFields0202756c(void *receiver, int x, int y, int elementIndex, unsigned char image, unsigned char palette,
                              unsigned short tile, unsigned char flags, int scaleX, int scaleY);

struct GrottoStair {
    fix32_t rotation[9];
    fix32_t worldX;
    fix32_t worldY;
    fix32_t worldZ;
    fix32_t angle;
};

struct GrottoFloor {
    unsigned char unknown0[0x1c8];
    unsigned char *mapData;
    unsigned char *adjacencyData;
    int width;
    int height;
    unsigned char upStairX;
    unsigned char upStairY;
    unsigned char downStairX;
    unsigned char downStairY;
    GrottoStair stairs[2];
};

struct ZoneRecord {
    unsigned short zoneId;
    unsigned char unknown2[0x23ec - 2];
    GrottoFloor grotto;
};

struct ElementReceiver {
    unsigned char unknown0[0x38];
    fix32_t scale;
    unsigned char unknown3c[8];
    int offsetX;
    int offsetY;
    unsigned char unknown4c[0x9ba - 0x4c];
    unsigned char showDownStair;
};

static inline fix32_t MultiplyFixed(fix32_t a, fix32_t b) {
    return FIX32_MULTIPLY(a, b);
}

static inline GrottoStair *GetStair(GrottoFloor *floor, int number) {
    return floor->stairs + number - 1;
}

// USA: func_02024000
extern "C" ARM void func_02024000(void *receiver) {
    ElementReceiver *state = static_cast<ElementReceiver *>(receiver);
    GameState *game = GameState::GetInstance();
    ZoneRecord *zone = static_cast<ZoneRecord *>(func_02012fe4());
    unsigned short zoneId = zone->zoneId;
    if (!IsInRange0201b588(zoneId)) {
        return;
    }
    SetElementFields0202756c(receiver, 0xbc000, 0x3000, 26, 0x42, 0, 0xff, 0xff, 0x1000, 0x1000);
    if (!IsInRange0201b5b0(zoneId)) {
        return;
    }
    unsigned char *visited = reinterpret_cast<unsigned char *>(game) + 0x6fcc + (zoneId % 20 - 1) * 32;
    GrottoFloor *grotto = &zone->grotto;
    GrottoStair *upStair = GetStair(grotto, 1);
    unsigned char upX = grotto->upStairX;
    unsigned char upY = grotto->upStairY;
    unsigned char downX = grotto->downStairX;
    unsigned char downY = grotto->downStairY;
    bool upVisited = false;
    bool downVisited = false;
    GrottoStair *downStair = GetStair(grotto, 2);
    for (int row = 0; row < 16; row++) {
        for (int col = 0; col < 16; col++) {
            bool seen;
            if (col < 8) {
                seen = (visited[row * 2] & (1 << col)) != 0;
            } else {
                seen = (visited[row * 2 + 1] & (1 << (col - 8))) != 0;
            }
            if (col == upX && row == upY && seen) {
                upVisited = true;
            }
            if (col == downX && row == downY && seen) {
                downVisited = true;
            }
        }
    }
    if (upVisited) {
        int y = MultiplyFixed(upStair->worldZ, state->scale) - (state->offsetY << 12) + 0x5c000;
        int x = MultiplyFixed(upStair->worldX, state->scale) - (state->offsetX << 12) + 0x7c000;
        SetElementFields0202756c(receiver, x, y, 24, 0x40, 1, 0xff, 0xff, 0x1000, 0x1000);
    }
    if (!downVisited && !state->showDownStair) {
        return;
    }
    int y = MultiplyFixed(downStair->worldZ, state->scale) - (state->offsetY << 12) + 0x5c000;
    int x = MultiplyFixed(downStair->worldX, state->scale) - (state->offsetX << 12) + 0x7c000;
    SetElementFields0202756c(receiver, x, y, 25, 0x41, 1, 0xff, 0xff, 0x1000, 0x1000);
}
