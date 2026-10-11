#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include <globaldefs.h>
#if defined(jpn)
enum { kGrottoPrefix = 0xc, kGrottoBase = 0x2400, kVisitedIndex = 0x4c };
#else
enum { kGrottoPrefix = 0x3ec, kGrottoBase = 0x2000, kVisitedIndex = 12 };
#endif

extern "C" void *func_02012fe4();
extern "C" void func_02027974(void *object, int adjacencyData, void *state);

static inline char *GrottoOffset3ec(Zone3D *zone) {
    return reinterpret_cast<char *>(zone) + kGrottoPrefix;
}

static inline ActiveGrottoClass *GrottoOffset2000(char *zone) {
    return reinterpret_cast<ActiveGrottoClass *>(zone + kGrottoBase);
}

// USA: func_02024d94
extern "C" ARM void func_02024d94(void *object, unsigned short zoneId, Vector3i *position) {
    GameState *gameState        = GameState::GetInstance();
    Zone3D *zone                = static_cast<Zone3D *>(func_02012fe4());
    unsigned char *visitedTiles = reinterpret_cast<unsigned char *>(&gameState->unk_6fc0[kVisitedIndex]) + ((zoneId % 20) - 1) * 32;

    int tileX = static_cast<int>((4.0f + static_cast<float>(position->x) / 4096.0f) / 8.0f);
    int tileZ = static_cast<int>((4.0f + static_cast<float>(position->z) / 4096.0f) / 8.0f);
    if (tileX < 8) {
        visitedTiles[tileZ * 2] |= 1U << tileX;
    } else {
        visitedTiles[tileZ * 2 + 1] |= 1U << (tileX - 8);
    }

    func_02027974(object, reinterpret_cast<int>(GrottoOffset2000(GrottoOffset3ec(zone))->floorMap_.pMapAdjacencyData),
                  *reinterpret_cast<void **>(static_cast<char *>(object) + 0x6c));
}
