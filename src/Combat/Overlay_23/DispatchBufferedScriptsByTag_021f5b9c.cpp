#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern char data_ov023_021fe3ac[];
extern char data_ov023_021fe3b1[];
extern char data_ov023_021fe3b5[];
extern char data_ov023_021fe3ba[];
extern char data_ov023_021fe3c2[];

extern "C" int func_ov023_021f5cd8(unsigned char* buf, int len, unsigned char* out);
extern "C" int func_ov023_021f5d58(unsigned char* buf, int len, unsigned char* out);
extern "C" void func_ov023_021f5e70(unsigned char* buf, int len, unsigned char* out);
extern "C" void func_ov023_021f6058(unsigned char* buf, int len, unsigned char* out);

struct Entry021f5b9c {
    char pad0[0x88];
    char tag[0x24];
    int len;
};

struct Data021fff08_021f5b9c { char pad[4]; int field4; };
extern struct Data021fff08_021f5b9c data_ov023_021fff08;

// USA: func_ov023_021f5b9c  (semantic: DispatchBufferedScriptsByTag_021f5b9c)
extern "C" ARM void func_ov023_021f5b9c(unsigned char* cursor, struct Entry021f5b9c* arr, int count, SafeAllocator* alloc) {
    struct Entry021f5b9c* e;
    unsigned char* out = (unsigned char*)alloc->Allocate(0xc800);
    int i = 0;
    for (; i < count; i++) {
        e = &arr[i];
        int handled = 0;
        if (strstr(e->tag, data_ov023_021fe3ac)) {
            handled = 1;
            if (func_ov023_021f5cd8(cursor, e->len, out) == 0) {
                e->tag[0] = 0;
            }
        } else if (strstr(e->tag, data_ov023_021fe3b1)) {
            func_ov023_021f5d58(cursor, e->len, out);
        } else if (strstr(e->tag, data_ov023_021fe3b5)) {
        } else if (strstr(e->tag, data_ov023_021fe3ba)) {
            func_ov023_021f5e70(cursor, e->len, out);
        } else if (strstr(e->tag, data_ov023_021fe3c2)) {
            func_ov023_021f6058(cursor, e->len, out);
        }
        cursor += e->len;
        if (handled) {
            e->len -= 4;
        }
    }
    data_ov023_021fff08.field4 = 0;
}
