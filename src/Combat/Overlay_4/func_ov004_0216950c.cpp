#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
extern "C" void* func_ov004_02168f08(void* ctx, int value);
#else
extern "C" void* func_ov023_021f6524(void* ctx, int value);
#endif
extern "C" int func_ov023_021f9bc8(char* obj);
struct Fields021695fc;
void ResetFieldBlocks_021695fc(struct Fields021695fc* obj);
extern "C" void func_ov004_0216920c(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
int ClearMasksAndNotify_02169adc(void* obj);

extern void* data_ov004_02171030;

struct Node0216950c { char pad[0x5c]; short f5c; short f5e; };

// USA: func_ov004_0216950c
extern "C" ARM int func_ov004_0216950c(void* obj) {
#if defined(jpn)
    unsigned char* table = *(unsigned char**)((char*)data_ov004_02171030 + 0x10);
#else
    unsigned char* table = *(unsigned char**)((char*)data_ov004_02171030 + 0x190);
#endif
    if (!table) return 0;

#if defined(jpn)
    struct Node0216950c* node = (struct Node0216950c*)func_ov004_02168f08(obj, 0x64);
#else
    struct Node0216950c* node = (struct Node0216950c*)func_ov023_021f6524(obj, 0x64);
#endif
    short f5c = node->f5c;
    unsigned char *cur, *next;
    int idx = func_ov023_021f9bc8((char*)node) + f5c * 8;
    cur = table + 4 + idx * 0x2c;
    next = table + 4 + (idx + 1) * 0x2c;
    ResetFieldBlocks_021695fc((struct Fields021695fc*)cur);

    int n = 0x2c;
    for (; idx < table[0]; idx++) {
        memcpy(cur, next, n);
        cur += n;
        next += n;
    }

    unsigned char nc = --table[0];
    unsigned char* last = table + 4 + nc * 0x2c;
    ResetFieldBlocks_021695fc((struct Fields021695fc*)last);

    if (table[0] <= 8) {
        node->f5c = 0;
        node->f5e = 1;
    }
    func_ov004_0216920c(obj);

    if (table[0] == 0) {
        func_ov011_021848a0(obj, 0x66);
        return 0;
    }
    ClearMasksAndNotify_02169adc(obj);
    return 0;
}
