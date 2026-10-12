#include <globaldefs.h>

struct List0207f6ac;
extern void* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);
extern "C" void func_0204fa0c(void* obj, short a, short b);

struct Entry02081574 {
    char pad0[0x6];
    short field6;
    short field8;
    char pad1[0x12 - 0xa];
    unsigned char field12;
    unsigned char field13nibble : 4;
    unsigned char field13rest : 4;
    char pad2[0x2a - 0x14];
    unsigned char field2a;
};

struct DispatchEntry02081574 {
    int fn;
    int locator;
};

#if defined(jpn)
#define data_020e8a54 data_020e8b68
#define ProcessEntryList02081574 func_02081e78
extern "C" ARM void func_02081e78(void* obj, void* ctx, void* list);
enum { kSelectedIdOffset = 0x2a, kOriginOffset = 0x28 };
#else
enum { kSelectedIdOffset = 0x36, kOriginOffset = 0x34 };
#endif

extern struct DispatchEntry02081574 data_020e8a54[];

// USA: func_02081574
ARM void ProcessEntryList02081574(void* obj, void* ctx, void* list) {
    struct Entry02081574* e;
    short id;
    unsigned char i;
    if (list == NULL) {
        return;
    }
    for (i = 0; i < *(unsigned char*)((char*)list + 0x13); i++) {
        id = (*(short**)list)[i];
        e = (struct Entry02081574*)FindEntryByShortId0207f6ac((struct List0207f6ac*)((char*)obj + 0x4), id);
        if (e != NULL) {
            if (*(short*)((char*)obj + kSelectedIdOffset) == id) {
                short val = e->field8;
                short diff = (short)(e->field6 - *(short*)((char*)obj + kOriginOffset));
                switch (e->field13nibble) {
                case 8:
                    val = (short)(val - 1);
                    break;
                case 0xc:
                    val = (short)(val + 1);
                    break;
                }
                func_0204fa0c(ctx, diff, val);
            }
            if (!(e->field2a & 1)) {
                struct DispatchEntry02081574* d = &data_020e8a54[e->field12];
                void* base = (char*)obj + (d->locator >> 1);
                void* callback;
                if (d->locator & 1) {
                    callback = *(void**)((char*)*(void**)base + d->fn);
                } else {
                    callback = (void*)d->fn;
                }
                ((void(*)(void*, void*, void*))callback)(base, ctx, e);
            }
        }
    }
}
