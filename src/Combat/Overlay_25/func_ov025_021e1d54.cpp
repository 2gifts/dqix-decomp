#include <globaldefs.h>

struct Neighbors021e1d54 {
    unsigned char cells[6];
};

struct Unit021e1d54 {
    unsigned char pad0;
    unsigned char marker;
    char pad2[2];
    int force;
    unsigned char* obj;
};

int GetSubstructByte0x1c(unsigned char* obj);
void SetSubstructByte0x1d(unsigned char* obj, unsigned char value);
extern "C" void _Z27ClearMatchingBytes_021e169cPhi(unsigned char* p, int val);
extern "C" void func_ov000_0216f82c(Neighbors021e1d54* out, const int* cell);
extern "C" void func_ov025_021e13e0(unsigned char* grid, Unit021e1d54* unit);
extern "C" void __clear(void* p, int n);

static inline int IsBlocked(unsigned char v) {
    return v >= 0xf2 ? 1 : 0;
}

// USA: func_ov025_021e1d54
extern "C" ARM void func_ov025_021e1d54(Unit021e1d54* unit, unsigned char* grid) {
    Neighbors021e1d54 near;
    unsigned char counts[6];
    Neighbors021e1d54 far;
    Neighbors021e1d54 tmp;
    int cell;
    Neighbors021e1d54 tmp2;
    int from;
    cell = GetSubstructByte0x1c(unit->obj);
    func_ov000_0216f82c(&tmp, &cell);
    near = tmp;
    unsigned char freeCount = 0;
    for (int i = 0; i < 6; i++) {
        if (near.cells[i] == 0xff) continue;
        if (IsBlocked(grid[near.cells[i]]) == 0) freeCount++;
    }
    if (unit->force == 0 && freeCount >= 4) return;
    __clear(counts, 6);
    int best = 0;
    int bestCell = 0xff;
    for (int i = 0; i < 6; i++) {
        int c = near.cells[i];
        if (c == 0xff) continue;
        from = c;
        func_ov000_0216f82c(&tmp2, &from);
        far = tmp2;
        for (int j = 0; j < 6; j++) {
            int c2 = far.cells[j];
            if (c2 == 0xff) continue;
            if (IsBlocked(grid[c2]) != 0) continue;
            counts[i]++;
            if (best < counts[i]) {
                best = counts[i];
                bestCell = c2;
            }
        }
    }
    if (bestCell >= 0x51) return;
    if (freeCount < best || unit->force != 0) {
        _Z27ClearMatchingBytes_021e169cPhi(grid, unit->marker);
        if (bestCell < 0x51) {
            func_ov025_021e13e0(grid, unit);
        }
        SetSubstructByte0x1d(unit->obj, bestCell);
    }
}
