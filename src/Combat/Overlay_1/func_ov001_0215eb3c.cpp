#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void*);
int GetWord0x0(int* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* tables);

struct PairTables_0215eb3c {
    int a[10];
    int b[10];
    int c;
    int d;
    int p1[2];
    int p2[2];
};

// USA: func_ov001_0215eb3c
extern "C" ARM int func_ov001_0215eb3c(void* self, int mode) {
    GameState* bs;
    int base;
    int addr;
    PairTables_0215eb3c* tables;
    int diff;
    int i;
    int j;
    int index;

    bs = GameState::GetInstance();
    if (bs == NULL) {
        return 0;
    }
    base = GetWord0x0((int*)bs);
    if (base == 0) {
        return 0;
    }
    index = func_ov017_021d60f4(self);
    if (index < 0) {
        addr = base + 0x2cc;
        addr = addr + 0xbd0;
    } else {
        addr = base + 0x2cc + index * 0x70;
    }
    if (addr == 0) {
        return 0;
    }
    _Z24BackupPairTables0207dfacPc((char*)addr);
    if (mode >= 2 && func_ov017_021d60f4((char*)self + 0x8) != 0) {
        addr = base + 0x2cc;
        tables = (PairTables_0215eb3c*)(addr + 0xbd0);
        diff = 0;
        for (i = 0; i < 10; i++) {
            diff += abs(tables->a[i] - tables->b[i]);
        }
        diff = 0;
        for (i = 0; i < 2; i++) {
            diff += abs(tables->p1[i] - tables->p2[i]);
        }
        if (index >= 0) {
            tables = (PairTables_0215eb3c*)(base + 0x2cc + index * 0x70);
            diff = 0;
            for (j = 0; j < 10; j++) {
                diff += abs(tables->a[j] - tables->b[j]);
            }
            diff = 0;
            for (j = 0; j < 2; j++) {
                diff += abs(tables->p1[j] - tables->p2[j]);
            }
        }
    }
    return 1;
}
