#include "Combat/FormationPosition.h"
#include <globaldefs.h>

struct FormationPathState {
    char unknown00[0x10];
    int startingPosition[3];
    char unknown1c[0x4];
    unsigned int flags;
    unsigned char cells[0x10];
    unsigned char cellCount;
    char unknown35[0x3];
    int unknown38;
    unsigned short unknown3c;
    char unknown3e[0x2];
    int currentPosition[3];
};

struct FormationPathActor {
    char unknown00[0x13c];
    FormationPathState *path;
    FormationPathState *GetPath() const {
        FormationPathState *result = path;
        return result;
    }
};

static inline Vec2_0216f74c GetFormationPosition(const int &cell) {
    return func_ov000_0216f74c(const_cast<int *>(&cell));
}

// USA: func_02048e2c
extern "C" ARM void func_02048e2c(FormationPathActor *actor) {
    if (actor->path == 0) {
        return;
    }

    {
        FormationPathState *state  = actor->path;
        unsigned char previousCell = state->cells[0];
        int readIndex;
        int writeIndex = 1;
        readIndex      = writeIndex;
        while (readIndex < actor->path->cellCount) {
            const unsigned char *cell = state->cells;
            cell += readIndex;
            unsigned char currentCell = *cell;
            if (previousCell != currentCell) {
                actor->GetPath()->cells[writeIndex] = currentCell;
                state                               = actor->path;
                writeIndex++;
                previousCell = state->cells[readIndex];
            }
            readIndex++;
        }
        state->cellCount = writeIndex;
    }

    if (actor->path->cellCount <= 1) {
        actor->path->cellCount = 0;
        return;
    }

    for (;;) {
        Vec2_0216f74c position = GetFormationPosition(actor->path->cells[1]);
        int x                  = position.x;
        int z                  = position.y;
        if (actor->path->currentPosition[0] == x && actor->path->currentPosition[2] == z) {
            actor->path->cellCount--;
            if (actor->path->cellCount <= 1) {
                actor->path->cellCount = 0;
                return;
            }
            for (int shiftIndex = 1; shiftIndex < actor->path->cellCount; shiftIndex++) {
                actor->path->cells[shiftIndex] = actor->path->cells[shiftIndex + 1];
            }
        } else {
            actor->path->flags |= 0x10;
            return;
        }
    }
}
