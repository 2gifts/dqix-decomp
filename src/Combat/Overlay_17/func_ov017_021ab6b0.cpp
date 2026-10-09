#include <globaldefs.h>
#include "Resource/Script.h"
#include "GameState/GameState.h"

struct Field150_021ab6b0 {
    unsigned char pad0[0x566];
    unsigned short id;
};
Field150_021ab6b0* GetFieldAt0x150(unsigned char* obj);

struct Header021ab6b0 {
    unsigned short id;
    unsigned short key : 15;
};

struct State021ab6b0 {
    Header021ab6b0* header;
    unsigned short key;
    unsigned short group;
    unsigned short entryId;
    int field_0xc;
    int field_0x10;
    int field_0x14;
    short field_0x18;
};
extern State021ab6b0 data_ov017_021d83b0;

// USA: func_ov017_021ab6b0
extern "C" ARM int func_ov017_021ab6b0(Script::Parameter* params, int numParams) {
    unsigned short key = (params++)->ToInt();
    if (data_ov017_021d83b0.header->key != key) {
        return 0;
    }
    if (key == data_ov017_021d83b0.key && data_ov017_021d83b0.group != 0) {
        return 0;
    }
    unsigned short group = (params++)->ToInt();
    if (group != 0 && group != data_ov017_021d83b0.header->id) {
        return 0;
    }
    int count = (numParams - 2) / 5;
    if (count == 0) {
        if (data_ov017_021d83b0.header->id == group) {
            data_ov017_021d83b0.entryId = 0;
        }
        return 0;
    }
    Field150_021ab6b0* info = GetFieldAt0x150((unsigned char*)GameState::GetInstance()->GetProtagonist());
    unsigned short id;
    float a, b, c, d;
    for (int i = 0; i < count; i++) {
        id = (params++)->ToInt();
        a = (params++)->ToFloat();
        b = (params++)->ToFloat();
        c = (params++)->ToFloat();
        d = (params++)->ToFloat();
        if (id == info->id) {
            break;
        }
    }
    data_ov017_021d83b0.key = key;
    data_ov017_021d83b0.group = group;
    data_ov017_021d83b0.entryId = id;
    data_ov017_021d83b0.field_0x18 = 4096.0f * a;
    data_ov017_021d83b0.field_0xc = 4096.0f * b;
    data_ov017_021d83b0.field_0x10 = 4096.0f * c;
    data_ov017_021d83b0.field_0x14 = 4096.0f * d;
    return 1;
}
