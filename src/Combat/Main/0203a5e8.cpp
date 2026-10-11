#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* __clear(void*, int);
int GetField0x3b0Value(GameState*);
struct Vec3copy0202ec84 { unsigned int v[3]; };
extern "C" int _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void*, Vec3copy0202ec84*, int*, int*);

struct SlotEntry02039fec {
    unsigned char pad0[5];
    signed char timer;
    unsigned char pad6[2];
    short velocity;
    short position;
    unsigned char pad0xc[0xc];
};
struct Obj02039fec {
    unsigned char pad0[0x550];
    struct SlotEntry02039fec slots[16];
    int cursor;
    int limit;
};
struct SlotProjection0203a5e8 {
    unsigned char field0[2];
    short verticalOffset;
    signed char horizontalOffset;
    signed char timer;
    unsigned char field6;
    unsigned char kind;
    short velocity;
    short position;
    Vec3copy0202ec84 vector;
};
struct ObjProjection0203a5e8 {
    unsigned char prefix[0x550];
    SlotProjection0203a5e8 slots[16];
    int cursor;
    int limit;
};

// USA: func_0203a5e8
extern "C" ARM void func_0203a5e8(Obj02039fec* obj, int index) {
    SlotProjection0203a5e8* current = (SlotProjection0203a5e8*)&obj->slots[index];
    ObjProjection0203a5e8* projection = (ObjProjection0203a5e8*)obj;
    signed char horizontal = 0;
    int vertical = 0;
    void* camera = (void*)GetField0x3b0Value(GameState::GetInstance());
    if (camera != NULL) {
        bool alternate = false;
        int step = alternate;
        int xs[16];
        int clampedYs[16];
        int ys[16];
        __clear(xs, sizeof(xs));
        __clear(clampedYs, sizeof(clampedYs));
        __clear(ys, sizeof(ys));
        for (int i = 0; i < 16; i++) {
            if (projection->slots[i].timer > 0) {
                int x, y = 0;
                _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(camera, &projection->slots[i].vector, &x, &y);
                x += projection->slots[i].horizontalOffset;
                y += projection->slots[i].verticalOffset;
                ys[i] = y;
                if (y < 36) y = 36;
                else if (y > 196) y = 196;
                xs[i] = x;
                clampedYs[i] = y;
            }
        }
        for (int attempt = 0; attempt < 16; attempt++) {
            bool collision = false;
            int* rowPositions = ys;
            int candidateY = vertical + rowPositions[index];
            if (candidateY < 36) candidateY = 36;
            else if (candidateY > 196) candidateY = 196;
            for (int j = 0; j < 16; j++) {
                if (j == index) continue;
                if (projection->slots[j].timer <= 0 || projection->slots[j].timer >= 35) continue;
                if (current->kind == 4 && projection->slots[j].kind == 4) continue;
                if (abs(horizontal + xs[index] - xs[j]) < 8 && abs(candidateY - clampedYs[j]) < 14) {
                    collision = true;
                    break;
                }
            }
            if (!collision) break;
            if (!alternate) {
                vertical = 20 * step - 4;
                step = -step;
                horizontal = 24;
                alternate = true;
            } else {
                vertical = 20 * step;
                horizontal = 0;
                if (step <= 0) step--;
                alternate = false;
            }
        }
    }
    if (current->horizontalOffset == -127) {
        current->horizontalOffset = 0;
        current->verticalOffset = 0;
    }
    current->horizontalOffset += horizontal;
    current->verticalOffset += vertical;
}
