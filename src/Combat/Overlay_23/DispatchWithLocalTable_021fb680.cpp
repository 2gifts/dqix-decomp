#include <globaldefs.h>

#if defined(jpn)
#define data_ov023_021fd964 data_ov023_021fcc14
#endif


#if defined(jpn)
#define func_ov023_021fb680 func_ov023_021faa24
#endif

struct Pair021fb680 { unsigned int a; unsigned int b; };
extern struct Pair021fb680 data_020e6d5c;

struct Block8Words_021fb680 { unsigned int w[8]; };
extern struct Block8Words_021fb680 data_ov023_021fd964;

struct DispatchEntry021fb680 { unsigned int fn; unsigned int locator; };

// USA: func_ov023_021fb680  (semantic: DispatchWithLocalTable_021fb680)
extern "C" ARM int func_ov023_021fb680(void* obj, void* param2) {
    struct Block8Words_021fb680 buf;
    buf = data_ov023_021fd964;
    unsigned int tmp1 = data_020e6d5c.b;
    unsigned int tmp0 = data_020e6d5c.a;
    buf.w[7] = tmp1;
    buf.w[6] = tmp0;
    struct DispatchEntry021fb680* entries = (struct DispatchEntry021fb680*)&buf;

    int idx = *(int*)((char*)obj + 0x1c);
    struct DispatchEntry021fb680* d = &entries[idx];
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
