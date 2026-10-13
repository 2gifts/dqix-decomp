#include <globaldefs.h>
#include "std_library_functions.h"

struct NameStatus022135f4 {
    unsigned char padding_0x00;
    unsigned char status;
    unsigned short padding_0x02;
};

struct NameRecord022135f4 {
    char text[6];
    unsigned short length;
    char remaining[0xb8];
};

struct NameState022135f4 {
    char padding_0x00[0x444];
    NameStatus022135f4 statuses[12];
    NameRecord022135f4 records[11];
    char padding_0xcb4[0x59];
    unsigned char status;
    char padding_0xd0e[4];
    unsigned char count;
    unsigned char selected;
};

struct NameGlobal022135f4 {
    char padding_0x00[0x10];
    NameState022135f4* state;
};

extern NameGlobal022135f4 data_ov031_0224e5c4;

// USA: func_ov031_022135f4
extern "C" ARM int func_ov031_022135f4() {
    unsigned char index;
    unsigned char selected;
    NameState022135f4* state = data_ov031_0224e5c4.state;
    selected = state->selected;
    NameRecord022135f4* records = state->records;
    NameRecord022135f4* selectedRecord = &records[(short)selected];
    if (state->status >= 6) return 1;
    unsigned char count = state->count;
    index = 0;
    if ((unsigned int)index < (unsigned int)count) do {
        if (index != selected && state->statuses[index].status < 6) {
            if (strncmp(selectedRecord->text, state->records[index].text,
                    state->records[index].length) == 0) return 2;
        }
        index++;
    } while (index < count);
    return 1;
}
