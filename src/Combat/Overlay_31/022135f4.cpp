#include <globaldefs.h>
#include <std_library_functions.h>

struct GlobalStruct0224e5c4_022133f8 {
    void* field0;
    void* field4;
    void* field8;
    void* fieldc;
    void* field10;
};
extern GlobalStruct0224e5c4_022133f8 data_ov031_0224e5c4;

// USA: func_ov031_022135f4
extern "C" ARM int func_ov031_022135f4(void) {
    int selectedOffset;
    char* entries;
    unsigned char index;
    unsigned char selected;
    unsigned char* state;
    unsigned int count;
    state = (unsigned char*)data_ov031_0224e5c4.field10;
    selected = state[0xd13];
    entries = (char*)state + 0x474;
    selectedOffset = 0xc0 * selected;
    if (state[0xd0d] >= 6) return 1;
    count = state[0xd12];
    index = 0;
    if (index < count) {
        do {
            if (index != selected && (state + index * 4)[0x445] < 6) {
                int offset = index * 0xc0;
                unsigned short length = *(unsigned short*)(state + offset + 0x47a);
                if (strncmp(entries + selectedOffset, entries + offset, length) == 0) {
                    return 2;
                }
            }
            ++index;
        } while (index < count);
    }
    return 1;
}
