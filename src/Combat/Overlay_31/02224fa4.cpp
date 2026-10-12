#include <globaldefs.h>

struct Selection2Entry { unsigned int word0; unsigned short hword4; unsigned short pad6; };
struct Selection2State {
    unsigned char pad[0x30];
    Selection2Entry* first[47];
    Selection2Entry* second[4];
    void* rest[8];
};
extern Selection2State* data_ov031_02250bfc;
extern const unsigned char data_ov031_022489ac[4];
extern const unsigned char data_ov031_022489b0[4];
extern "C" void func_ov031_0223bb58(void*, int, int, int);

// USA: func_ov031_02224fa4
extern "C" ARM void func_ov031_02224fa4(int index, int state) {
    if (index < 0) return;
    if (index < 47) {
        unsigned char value = data_ov031_022489ac[state];
        Selection2Entry* entry = data_ov031_02250bfc->first[index];
        entry->word0 &= ~0xc00;
        entry->hword4 = (entry->hword4 & ~0xf000) | (value << 12);
        return;
    }
    if (index - 47 < 4) {
        unsigned char value = data_ov031_022489ac[state];
        Selection2Entry* entry = data_ov031_02250bfc->second[index - 47];
        entry->word0 &= ~0xc00;
        entry->hword4 = (entry->hword4 & ~0xf000) | (value << 12);
        return;
    }
    func_ov031_0223bb58(data_ov031_02250bfc->rest[index - 51], -1, 0, data_ov031_022489b0[state]);
}
