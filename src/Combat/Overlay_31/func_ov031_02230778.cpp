#include <globaldefs.h>

struct Layer02230778 {
    unsigned char pad0[0x44];
    unsigned char update;
};
struct Context02230778 {
    unsigned char pad0[4];
    unsigned short offset;
    unsigned char padding_0x6[2];
    Layer02230778* layer;
};
extern Context02230778 data_ov031_02290ca0;
extern const unsigned char data_ov031_02249048[];
extern "C" int FastIntDivide(int, unsigned int);
extern "C" int FastIntModulus(int, unsigned int);
#define REG_BG0OFS_02230778 (*(volatile unsigned int*)0x04000010)
#define REG_BG2OFS_02230778 (*(volatile unsigned int*)0x04000018)

static inline void SetScroll02230778(int first, int second) {
    REG_BG0OFS_02230778 = (first << 16) & 0x1ff0000;
    REG_BG2OFS_02230778 = (second << 16) & 0x1ff0000;
}

// USA: func_ov031_02230778
extern "C" ARM void func_ov031_02230778() {
    if (!data_ov031_02290ca0.layer->update) return;
    int index = FastIntDivide(data_ov031_02290ca0.offset, 29);
    int scroll = FastIntModulus(data_ov031_02290ca0.offset, 29) - 51;
    int second = scroll + data_ov031_02249048[index];
    SetScroll02230778(scroll, second);
    data_ov031_02290ca0.layer->update = 0;
}
