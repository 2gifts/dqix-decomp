#include <globaldefs.h>

struct Neighbors6 {
    unsigned char cells[6];
};

extern "C" void func_ov000_0216f82c(Neighbors6* out, const int* cell);

static inline int IsCellBlocked(unsigned char* grid, unsigned int cell) {
    return grid[cell] >= 0xf2 ? 1 : 0;
}

static inline void SetCell(unsigned char* grid, unsigned int cell, unsigned char value) {
    if (cell < 0x51) {
        grid[cell] = value;
    }
}

// USA: func_ov025_021e12f8
extern "C" ARM void func_ov025_021e12f8(unsigned char* grid, int cell, unsigned char value, unsigned char maxDist, unsigned char skip, unsigned char dist) {
    if (maxDist == dist) {
        return;
    }
    if (skip != 0) {
        skip--;
    }
    if (skip == 0) {
        dist++;
    }
    Neighbors6 nb;
    Neighbors6 tmp;
    int c;
    c = cell;
    func_ov000_0216f82c(&tmp, &c);
    nb = tmp;
    for (int i = 0; i < 6; i++) {
        unsigned char n = nb.cells[i];
        if (n >= 0x51) {
            continue;
        }
        if (skip == 0 && IsCellBlocked(grid, n)) {
            continue;
        }
        if (dist < maxDist) {
            func_ov025_021e12f8(grid, n, value, maxDist, skip, dist);
        }
        if (skip != 0) {
            continue;
        }
        SetCell(grid, n, value);
    }
}
