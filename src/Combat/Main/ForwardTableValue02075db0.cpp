#include <globaldefs.h>

#if defined(jpn)
#define func_02075df4 func_02076d10
#endif

extern "C" int func_02075df4(void* obj, int a, int b, int c);

struct Struct02075db0 {
    char pad0[0x24];
    int** rows;           // 0x24
    char pad1[0x34];    // 0x28..0x5b
    unsigned short f5c; // 0x5c
    char pad2[0x2];     // 0x5e
    int columnIndex;            // 0x60
    int rowIndex;            // 0x64
};

#if defined(jpn)
#define ForwardTableValue02075db0 func_02076ccc
extern "C" ARM int func_02076ccc(struct Struct02075db0* s, int a, int b);
#endif

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
