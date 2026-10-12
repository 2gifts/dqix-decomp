#include <globaldefs.h>
#include "GameState/GameState.h"

struct StatEntry021caea8 {
    unsigned char padding_0[2];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char reserved : 4;
    unsigned char padding_b[0x18 - 0xb];
};
struct StatContainer021caea8 {
    unsigned char field_0;
    unsigned char reserved_1 : 4;
    unsigned char count : 2;
    unsigned char reserved_2 : 2;
    unsigned char padding_2[2];
    StatEntry021caea8 entries[3];
};
struct StatElement021caea8 {
    unsigned char padding_0[0x36];
    unsigned short value;
    unsigned char padding_38[0x5c - 0x38];
    unsigned char primary[20];
    unsigned char padding_70[0x7f - 0x70];
    unsigned char secondary[20];
    unsigned char padding_93[0xa4 - 0x93];
};
struct StatState021caea8 {
    unsigned char padding_0[8];
    unsigned short id;
    unsigned char padding_a[0x158 - 0xa];
    StatElement021caea8 elements[8];
};
struct StatGlobals021caea8 {
    unsigned char padding_0[0x3718];
    void* node;
};
struct StatLevels021caea8 {
    unsigned int s0 : 3, s1 : 3, s2 : 3, s3 : 3, s4 : 3;
    unsigned int s5 : 3, s6 : 3, s7 : 3, s8 : 3, s9 : 3;
};
struct StatFields021caea8 {
    unsigned short id;
    unsigned short slot;
    StatLevels021caea8 low;
    StatLevels021caea8 high;
    unsigned short value;
    unsigned char primary;
    unsigned char padding_f;
};
struct StatMessage021caea8 {
    unsigned char tag;
    unsigned char padding_1[3];
    StatFields021caea8 fields;
};
extern "C" StatState021caea8* func_ov017_021b8478(void*);
void* GetData02100044();
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021caea8
extern "C" ARM void func_ov017_021caea8(StatContainer021caea8* self) {
    GameState::GetInstance();
    StatGlobals021caea8* globals = (StatGlobals021caea8*)func_ov017_0218b5b0();
    StatState021caea8* state = func_ov017_021b8478(globals->node);
    void* data = GetData02100044();
    for (int i = 0; i < self->count; i++) {
        StatEntry021caea8* entry = &self->entries[i];
        StatMessage021caea8 first;
        StatMessage021caea8 second;
        for (int j = 0; j < entry->count; j++) {
            unsigned char id = entry->ids[j];
            if (id >= 8) continue;
            StatElement021caea8* element = &state->elements[id];
            StatFields021caea8* fields = &first.fields;
            first.tag = 0x60;
            fields->id = state->id;
            fields->slot = entry->ids[j] + 0xc0;
            fields->primary = 1;
            fields->low.s0 = element->primary[0];
            fields->low.s1 = element->primary[1];
            fields->low.s2 = element->primary[2];
            fields->low.s3 = element->primary[3];
            fields->low.s4 = element->primary[4];
            fields->low.s5 = element->primary[5];
            fields->low.s6 = element->primary[6];
            fields->low.s7 = element->primary[7];
            fields->low.s8 = element->primary[8];
            fields->low.s9 = element->primary[9];
            fields->high.s0 = element->primary[10];
            fields->high.s1 = element->primary[11];
            fields->high.s2 = element->primary[12];
            fields->high.s3 = element->primary[13];
            fields->high.s4 = element->primary[14];
            fields->high.s5 = element->primary[15];
            fields->high.s6 = element->primary[16];
            fields->high.s7 = element->primary[17];
            fields->high.s8 = element->primary[18];
            fields->high.s9 = element->primary[19];
            fields->value = element->value;
            func_0205e330(data, &first, 0);
            fields = &second.fields;
            second.tag = 0x60;
            fields->id = state->id;
            fields->slot = entry->ids[j] + 0xc0;
            fields->primary = 0;
            fields->low.s0 = element->secondary[0];
            fields->low.s1 = element->secondary[1];
            fields->low.s2 = element->secondary[2];
            fields->low.s3 = element->secondary[3];
            fields->low.s4 = element->secondary[4];
            fields->low.s5 = element->secondary[5];
            fields->low.s6 = element->secondary[6];
            fields->low.s7 = element->secondary[7];
            fields->low.s8 = element->secondary[8];
            fields->low.s9 = element->secondary[9];
            fields->high.s0 = element->secondary[10];
            fields->high.s1 = element->secondary[11];
            fields->high.s2 = element->secondary[12];
            fields->high.s3 = element->secondary[13];
            fields->high.s4 = element->secondary[14];
            fields->high.s5 = element->secondary[15];
            fields->high.s6 = element->secondary[16];
            fields->high.s7 = element->secondary[17];
            fields->high.s8 = element->secondary[18];
            fields->high.s9 = element->secondary[19];
            func_0205e330(data, &second, 0);
        }
    }
}
