#include <globaldefs.h>
#include "Combat/LootPointEvent.h"
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
extern "C" int _s32_div_f(int a, int b);

struct BitHistory0208f048 {
    char pad[0x188];
    LootPointState hist0188;
    LootPointState hist018c;
};

// USA: func_0208f048  (semantic: UpdateAndEnqueueBitHistory0208f048)
extern "C" ARM void func_0208f048(unsigned char* p0) {
    void* g;
    char* mid;
    int total;
    int count1;
    int i;
    GameState* bs;
    struct BitHistory0208f048* base7;

    if (*p0 != 0x62) {
        return;
    }

    g = func_02012fe4();
    mid = (char*)((int)g + (IS_JPN ? 0x1860 : 0x1840));
    total = _s32_div_f(*(int*)(mid + 0xb34), 100) + 4;
    if (total > 14) {
        total = 14;
    }
    count1 = total - 7;

    bs = GameState::GetInstance();
    base7 = (struct BitHistory0208f048*)((char*)bs + (IS_JPN ? 0x5a7c : 0x5cdc));

    i = 0;
    while (count1 > 0) {
        unsigned int v = base7->hist018c.word;
        unsigned int t1 = (v << 7) >> 24;
        base7->hist018c.word = (v & 0xfe01ffff) | (((t1 | (1u << i)) << 24) >> 7);
        i++;
        count1--;
    }
    EnqueueEventTag183_021d38f8(0, 0, (base7->hist018c.word << 7) >> 24, 0x63, &base7->hist018c);

    if (i > 0) {
        i = 0;
        total = 7;
    }
    while (total > 0) {
        unsigned int v = base7->hist0188.word;
        unsigned int t1 = (v << 7) >> 24;
        base7->hist0188.word = (v & 0xfe01ffff) | (((t1 | (1u << i)) << 24) >> 7);
        total--;
        i++;
    }
    EnqueueEventTag183_021d38f8(0, 0, (base7->hist0188.word << 7) >> 24, 0x62, &base7->hist0188);
}
