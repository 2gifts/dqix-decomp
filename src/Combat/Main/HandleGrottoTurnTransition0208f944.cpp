#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Grotto/Main/DetailedTreasureMapData.h"

void* GetField0x3f8Address(GameState* battleStruct);
extern "C" void* func_02012fe4(void);
int IsInRange0201b588(int id);
int IsValueInRange0201b5d8(int x);

struct Obj0208f944 {
    char _pad0[IS_JPN ? 0x280 : 0x260];
    unsigned char f260;      // 0x260
    char _pad1;               // 0x261
    unsigned char f262;      // 0x262
    char _pad2[5];             // 0x263..0x267
    unsigned int f268;       // 0x268
    unsigned int f26c;       // 0x26c
    unsigned int f270;       // 0x270
    unsigned short f274;      // 0x274
};

struct State0208f944 {
    unsigned short h0;      // 0x0
    char _pad0[5];           // 0x2..0x6
    unsigned char b7;        // 0x7
    char _pad1[2];            // 0x8..0x9
    unsigned char b0xa;      // 0xa
    char _pad2[5];             // 0xb..0xf
    unsigned int w0x10;
    unsigned int w0x14;
    unsigned int w0x18;
    unsigned short h0x1c;
};

// USA: func_0208f944
ARM void HandleGrottoTurnTransition0208f944(struct Obj0208f944* obj) {
    GameState* battle = GameState::GetInstance();
    struct State0208f944* state = (struct State0208f944*)GetField0x3f8Address(battle);
    struct GrottoStruct* grotto = battle->GetGrottoStruct();
    void* misc = func_02012fe4();
    int a = state->h0;
    int b = *(unsigned short*)misc;

    if (obj->f262 != 0 && a != 0xc3b5) {
        state->h0 = obj->f274;
        state->b7 = 1;
        state->h0x1c = 0x3244;
        state->w0x10 = obj->f268;
        state->w0x14 = obj->f26c;
        state->w0x18 = obj->f270;
        state->b0xa = 0;
        a = obj->f274;
    }

    obj->f262 = 0;

    if (!IsInRange0201b588(a)) {
        if (IsInRange0201b588(b)) {
            if (a < 0x7530 || a > 0x9c3f) {
                ((DetailedTreasureMapData*)obj)->Clear();
            }
        }
    }

    if (IsInRange0201b588(a) && !IsInRange0201b588(b)) {
        signed char g8 = *((signed char*)grotto + 8);
        if (g8 != -1) {
            if (!IsValueInRange0201b5d8(a)) {
                int rem = a % 20;
                state->h0 = (unsigned short)((rem + 0x1c40 + 0x8000) + g8 * 20);
            }
        }
    }

    obj->f260 = 0;
}
