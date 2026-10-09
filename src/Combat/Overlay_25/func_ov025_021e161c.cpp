#include <globaldefs.h>

struct Neighbors021e161c {
    unsigned char b[6];
};

extern "C" void func_ov000_0216f82c(Neighbors021e161c* out, const int* cell);

// USA: func_ov025_021e161c
extern "C" ARM int func_ov025_021e161c(int cell, int unused, unsigned char* table, int val) {
    Neighbors021e161c s;
    Neighbors021e161c nb;
    func_ov000_0216f82c(&nb, &cell);
    s = nb;
    for (int i = 0; i < 6; i++) {
        unsigned char c = s.b[i];
        if (c == 0xff) {
            continue;
        }
        if (val == table[c]) {
            return c;
        }
    }
    return cell;
}
