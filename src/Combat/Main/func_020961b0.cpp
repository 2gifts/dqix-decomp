#include <globaldefs.h>
#include "std_library_functions.h"

struct SearchStruct0202c1a4;

extern "C" void *func_0202ae18(int n);
int CheckField0NonZero(int *obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4 *obj);
extern "C" void func_020962f4(void *g, struct Entry020961b0 e);
void SetBitInArrayGuarded(int unused, unsigned char *arr, int index);

struct Entry020961b0 {
    unsigned int a : 9;
    unsigned int b : 1;
    unsigned int c : 1;
    unsigned int d : 3;
    unsigned int e : 2;
    unsigned int f : 1;
    unsigned int g : 15;
    unsigned int w4;
    unsigned int w8;
    unsigned int wc;
};

struct Node020961b0 {
    char pad0[2];
    unsigned short id : 9;
    unsigned short f9 : 1;
    unsigned short mid : 3;
    unsigned short f13 : 1;
    unsigned short tail : 2;
    char pad4[8];
    struct Node020961b0 *next;
};

// USA: func_020961b0
extern "C" ARM int func_020961b0(void *g, int id) {
    int n = *(unsigned char *)g;
    if (n >= 8) {
        return 0;
    }
    void *p = func_0202ae18(n);
    struct Node020961b0 *node;
    for (node = (struct Node020961b0 *)*(void **)((char *)g + 0xa0); node != 0; node = node->next) {
        if (node->id != id) {
            continue;
        }
        struct Entry020961b0 e;
        memset(&e, 0, sizeof(e));
        e.a = node->id;
        e.c = node->f9;
        e.f = node->f13;
        e.d = 1;
        if (CheckField0NonZero((int *)p) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4 *)p)) {
            e.b = 1;
        } else {
            e.b = 0;
        }
        func_020962f4(g, e);
        SetBitInArrayGuarded((int)g, (unsigned char *)g + 0xa8 + 0x400, id);
        break;
    }
    if (node == 0) {
        return 0;
    }
    return 1;
}