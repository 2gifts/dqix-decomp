#pragma once

struct ActionState0201fbe0 {
    unsigned char state;
    unsigned char subState;
    unsigned char b2;
    unsigned char pad3;
    unsigned short field4;
    unsigned char pad[0xe];
};

void ClearActionState(ActionState0201fbe0 *state, int force);

extern ActionState0201fbe0 data_020fdc60[4];
