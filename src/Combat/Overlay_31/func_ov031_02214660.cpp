#include <globaldefs.h>
#include "System/Memory.h"

struct Command02214660 {
    unsigned char field_0;
    unsigned char type;
    unsigned char field_2;
    unsigned char length;
    unsigned char payload[0x20];
};
struct CommandState02214660 {
    unsigned char prefix[0x300];
    Command02214660 commands[9];
    unsigned char gap[0x8c8];
    unsigned char mode : 4;
    unsigned char flags : 4;
};
extern "C" int func_ov031_0221474c(void*);
extern unsigned char data_ov031_02249abc[];
extern unsigned char data_ov031_02245fd8[];
extern unsigned char data_ov031_02245fe8[];

// USA: func_ov031_02214660
extern "C" ARM int func_ov031_02214660(CommandState02214660* state) {
    int count;
    Command02214660* entry = state->commands;
    count = func_ov031_0221474c(state);
    entry += count;
    if (state->mode == 0 || state->mode == 4) {
        VectorizedInvertedMemcpy(data_ov031_02249abc, entry->payload, 8);
        entry->length = 8;
        entry->type = 6;
        count = (count + 1) & 255;
        ++entry;
    }
    if (state->mode == 0 || state->mode == 7) {
        VectorizedInvertedMemcpy(data_ov031_02245fd8, entry->payload, 8);
        entry->length = 8;
        entry->type = 9;
        count = (count + 1) & 255;
        ++entry;
    }
    if (state->mode == 0 || state->mode == 8) {
        VectorizedInvertedMemcpy(data_ov031_02245fe8, entry->payload, 11);
        entry->length = 11;
        entry->type = 10;
        count = (count + 1) & 255;
    }
    return count;
}
