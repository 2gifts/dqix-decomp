#include <globaldefs.h>
#include "Combat/LootPointEvent.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LootPointEventPayload {
    unsigned char mode;
    signed char partySlot;
    unsigned char mask;
    unsigned char pointId;
    LootPointState packedState;
};

struct LootPointEvent {
    unsigned char tag;
    unsigned char unknown1[3];
    LootPointEventPayload payload;
    unsigned char unknownc[8];

    LootPointEventPayload* GetPayload() { return &payload; }
};

// USA: func_ov017_021d38f8
ARM void EnqueueEventTag183_021d38f8(unsigned char mode, signed char partySlot,
                                   unsigned char mask, unsigned char pointId,
                                   const LootPointState* packedState) {
    void* dispatcher = GetData02100044();
    LootPointEvent event;
    event.tag = 0xb7;
    LootPointEventPayload* payload = event.GetPayload();
    payload->mode = mode;
    payload->partySlot = partySlot;
    payload->mask = mask;
    payload->pointId = pointId;
    payload->packedState = *packedState;
    func_0205e330(dispatcher, &event, 0);
}
