#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x34ec };
#else
enum { kRegionalFieldOffset = 0x36fc };
#endif

#include "GameState/GameState.h"
#include "System/ColorEffects.h"
#include "System/OverlayId.h"

struct HeadNode02046b24;

extern "C" int _Z27IsIndexMappedToSelf020a18f4j(unsigned int idx);
int GetWord0x0(int* obj);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24** head);

static inline int GetVisiblePlanes() {
    return (int)((*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8);
}

static inline void SetVisiblePlanes(int planes) {
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | (planes << 8);
}

// USA: func_02065418
extern "C" ARM void func_02065418(int keepPlanes) {
    if (!_Z27IsIndexMappedToSelf020a18f4j(OVERLAY_ID(17))) {
        return;
    }
    HeadNode02046b24** head = *(HeadNode02046b24***)((char*)GetWord0x0((int*)GameState::GetInstance()) + kRegionalFieldOffset);
    if (head == NULL) {
        return;
    }
    if (GetHeadNodeIdOrMinusOne(head) == 0x2d) {
        return;
    }
    if (GetHeadNodeIdOrMinusOne(head) == 0x2a) {
        return;
    }
    if (keepPlanes != 0) {
        return;
    }
    SetVisiblePlanes(GetVisiblePlanes() | 0x10);
    ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
}
