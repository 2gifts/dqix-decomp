#include <globaldefs.h>

struct SelectionEntry { unsigned int word0; unsigned short hword4; unsigned short pad6; };
struct SelectionState {
    unsigned char pad[0x10];
    SelectionEntry* first[10];
    SelectionEntry* second[2];
    void* rest[6];
};
extern SelectionState* data_ov031_02250c00;
extern const unsigned char data_ov031_02248c7c[4];
extern const unsigned char data_ov031_02248c70[4];
extern "C" void func_ov031_0223bb58(void*, int, int, int);

// USA: func_ov031_02226910
extern "C" ARM void func_ov031_02226910(int index, int state) {
    if (index < 0) return;
    if (index < 10) {
        unsigned char value = data_ov031_02248c7c[state];
        SelectionEntry* entry = data_ov031_02250c00->first[index];
        entry->word0 &= ~0xc00;
        entry->hword4 = (entry->hword4 & ~0xf000) | (value << 12);
        return;
    }
    if (index - 10 < 2) {
        unsigned char value = data_ov031_02248c7c[state];
        SelectionEntry* entry = data_ov031_02250c00->second[index - 10];
        entry->word0 &= ~0xc00;
        entry->hword4 = (entry->hword4 & ~0xf000) | (value << 12);
        return;
    }
    func_ov031_0223bb58(data_ov031_02250c00->rest[index - 12], -1, 0, data_ov031_02248c70[state]);
}
