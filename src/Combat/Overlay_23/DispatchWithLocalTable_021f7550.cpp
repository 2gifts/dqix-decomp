#include <globaldefs.h>

#if defined(jpn)
#define data_ov023_021fd8fc data_ov023_021fcbb0
#endif


#if defined(jpn)
#define func_ov023_021f7550 func_ov023_021f6a84
#endif

struct Pair021f7550 { unsigned int a; unsigned int b; };
extern struct Pair021f7550 data_020e6d5c;

struct Block8Words_021f7550 { unsigned int w[8]; };
extern struct Block8Words_021f7550 data_ov023_021fd8fc;

struct DispatchEntry021f7550 { unsigned int fn; unsigned int locator; };

// USA: func_ov023_021f7550  (semantic: DispatchWithLocalTable_021f7550)
extern "C" ARM int func_ov023_021f7550(void* obj, void* param2) {
    struct Block8Words_021f7550 buf;
    buf = data_ov023_021fd8fc;
    unsigned int tmp1 = data_020e6d5c.b;
    unsigned int tmp0 = data_020e6d5c.a;
    buf.w[7] = tmp1;
    buf.w[6] = tmp0;
    struct DispatchEntry021f7550* entries = (struct DispatchEntry021f7550*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct DispatchEntry021f7550* d = &entries[idx];
    void* base = (char*)obj + ((int)d->locator >> 1);
    void* callback;
    if (d->locator & 1) {
        callback = *(void**)((char*)*(void**)base + d->fn);
    } else {
        callback = (void*)d->fn;
    }
    int result = ((int(*)(void*, void*))callback)(base, param2);
    *(int*)((char*)obj + 0x1c) = result;
    return result;
}
