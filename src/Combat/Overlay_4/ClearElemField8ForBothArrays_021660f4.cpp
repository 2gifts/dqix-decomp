#include <globaldefs.h>

struct Elem021660f4 {
    char pad[8];
    int field8;
};

struct Obj021660f4 {
    struct Elem021660f4* arr[2];
    int field8;
    char pad[0x48 - 0xc];
    short counts[2];
    short field4c;
};
#if defined(jpn)
struct RegionalContextPointer { unsigned int reserved; struct Obj021660f4* value; };
extern RegionalContextPointer data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c.value
#else
extern struct Obj021660f4* data_ov004_0217101c;
#define CONTEXT_VALUE data_ov004_0217101c
#endif

// USA: func_ov004_021660f4  (semantic: ClearElemField8ForBothArrays_021660f4)
extern "C" ARM void func_ov004_021660f4(void) {
    struct Elem021660f4* arr[2];
    short counts[2];
#if defined(jpn)
    short i = 0;
#endif
    struct Obj021660f4* obj = CONTEXT_VALUE;
    arr[0] = obj->arr[0];
    arr[1] = obj->arr[1];
    counts[0] = obj->counts[0];
    counts[1] = obj->counts[1];

#if defined(jpn)
    for (; i < 2; i++) {
#else
    short i;
    for (i = 0; i < 2; i++) {
#endif
        struct Elem021660f4* e = arr[i];
        short cnt = counts[i];
        short j;
        for (j = 0; j < cnt; j++) {
            e->field8 = 0;
            e = (struct Elem021660f4*)((char*)e + 0xc);
        }
    }
    obj->field8 = 0;
    obj->field4c = 0;
}
