#include <globaldefs.h>

struct MenuEntry {
    unsigned char field_0x0[0x15];
    unsigned char active;
};

struct MenuPage {
    struct MenuEntry entries[26];
    unsigned char cursor;
    unsigned char field_0x23d;
    unsigned char field_0x23e;
    unsigned char count;
};

extern struct MenuPage data_ov004_02170b90[] __attribute__((aligned(4)));
extern int data_ov004_0216fe90[];

// USA: func_ov004_0215ef9c
extern "C" ARM void func_ov004_0215ef9c(int which) {
    struct MenuPage* page = &data_ov004_02170b90[which ? 0 : 1];
    if (page->count <= 1) {
        page->cursor = 0;
        return;
    }
    int pos = page->cursor;
    int mode = 0;
    if (pos >= 26) {
        mode = 3;
    } else {
        int n = 0;
        while (n < 4) {
            if (--pos < 0) {
                break;
            }
            if (page->entries[data_ov004_0216fe90[pos] - 1].active) {
                n++;
            }
        }
        if (pos < 0) {
            mode = 1;
        }
    }
    if (mode >= 1) {
        int n = 0;
        for (int i = 0; i < 26; i++) {
            if (page->entries[data_ov004_0216fe90[i] - 1].active) {
                n++;
                if (n & 1) {
                    pos = i;
                }
            }
        }
        int m = 0;
        while (m < mode - 1) {
            if (--pos < 0) {
                break;
            }
            if (page->entries[data_ov004_0216fe90[pos] - 1].active) {
                m++;
            }
        }
        if (pos < 0) {
            pos = 0;
        }
    }
    page->cursor = pos;
}
