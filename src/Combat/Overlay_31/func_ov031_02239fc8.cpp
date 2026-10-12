#include <globaldefs.h>

struct SlotState02239fc8 {
    int state;
    short unknown_04;
    char padding6[0x48 - 6];
    int unknown_48;
    int (*eventCallback)(void* event);
    short unknown_50;
    short participantMask;
    int commandResult;
    char padding58[0x12a0 - 0x58];
    int dispatchOption;
    int dispatchArgument;
};

struct SlotHolder02239fc8 {
    char padding0[4];
    SlotState02239fc8* slot;
};

extern SlotHolder02239fc8 data_ov031_02290d18 __attribute__((aligned(4)));
extern "C" int func_ov031_0223a060();

// USA: func_ov031_02239fc8
extern "C" ARM int func_ov031_02239fc8() {
    data_ov031_02290d18.slot->dispatchArgument = 0;
    data_ov031_02290d18.slot->dispatchOption = 0;
    data_ov031_02290d18.slot->unknown_48 = 0;
    data_ov031_02290d18.slot->unknown_50 = 0;
    data_ov031_02290d18.slot->participantMask = 1;
    data_ov031_02290d18.slot->commandResult = 0;
    data_ov031_02290d18.slot->state = 0;
    data_ov031_02290d18.slot->unknown_04 = 0;
    data_ov031_02290d18.slot->eventCallback = NULL;
    int result;
    if (func_ov031_0223a060() == 0) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}
