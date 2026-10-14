#include <globaldefs.h>

#if defined(jpn)
enum { BattleTableOffset = 0x73b0 };
#else
enum { BattleTableOffset = 0x75f0 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_0205ec34(void);
int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);
struct Container_02097430;
struct Node_02097430 {
    unsigned char unknown0[0x1a];
    short progressId;
    unsigned char unknown1c[4];
};
extern "C" Node_02097430* func_02097430(Container_02097430* entries, int key);

struct EventFlagState {
    unsigned char unknown0[0x8c];
    unsigned char bits[0x234];
};

struct GameProgressRecords {
    unsigned char unknown0[BattleTableOffset];
    unsigned int records[308];
};

extern short data_020e90d4[21];

// USA: func_020abf60

extern "C" ARM int func_020abf60(void* entriesData) {
    if (entriesData == 0) {
        return 0;
    }
    EventFlagState* events = static_cast<EventFlagState*>(func_0205ec34());
    if (TestBitInByteArray_0206dfb0((int)events, events->bits, 0x796) == 0 ||
        TestBitInByteArray_0206dfb0((int)events, events->bits, 0x1143) != 0) {
        return 0;
    }
    SetOrClearBitInArray_0206df6c(events, events->bits, 0x1143, 1);
    unsigned int* table = reinterpret_cast<GameProgressRecords*>(GameState::GetInstance())->records;
    short* keys = data_020e90d4;
    int i;
    for (i = 0; i < 0x15; i++) {
        short key = *keys;
        keys++;
        short index = func_02097430(static_cast<Container_02097430*>(entriesData), key)->progressId - 1;
        table[index] |= 0x400;
    }
    return 1;
}
