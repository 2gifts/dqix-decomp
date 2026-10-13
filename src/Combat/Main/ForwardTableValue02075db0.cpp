#include <globaldefs.h>

extern "C" int func_02075df4(void* obj, int a, int b, int c);

struct Struct02075db0 {
    char pad0[0x24];
    int** rows;
    char pad1[0x34];
    unsigned short f5c;
    char pad2[0x2];
    int columnIndex;
    int rowIndex;
};

// USA: func_02075db0
ARM int ForwardTableValue02075db0(struct Struct02075db0* s, int a, int b) {
    int** rows;
    int* row;
    if (s->f5c == 0) return 0;
    rows = s->rows;
    if (rows == NULL) return 0;
    row = rows[s->rowIndex];
    return func_02075df4(s, row[s->columnIndex], a, b);
}
