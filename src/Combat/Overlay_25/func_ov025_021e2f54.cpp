#include <globaldefs.h>

struct Ctx021e2f54 {
    char pad0[0x1c4];
    unsigned int flags;
    char pad1c8[0x22c - 0x1c8];
    char queue[4];
};

struct Holder021e2f54 {
    char pad0[0xc];
    struct Ctx021e2f54* ctx;
};

struct Rec021e2f54 {
    char pad0[0x14];
    unsigned int : 28;
    unsigned int kind : 4;
};

struct Event021e2f54 {
    char pad0[0x26];
    unsigned short state;
};

struct List021600f8;

extern struct Holder021e2f54 data_ov025_021ef988;

void* GetData02108e10(void);
extern "C" struct Rec021e2f54* _Z24SearchBothTables02079e2cPci(char* p, int key);
extern "C" void* _Z22GetNodeAtIndex021600f8P12List021600f8i(struct List021600f8* list, int index);
extern "C" short func_ov000_0215ffa0(void* node);
extern "C" void func_ov025_021ecc54(void* queue, struct Event021e2f54* ev);
int ClassifyField0x81fe(char* base);

static inline int IsSpecial021e2f54(void* node) {
    return func_ov000_0215ffa0(node) >= 0xc0 && func_ov000_0215ffa0(node) <= 0xc7;
}

// USA: func_ov025_021e2f54
extern "C" ARM void func_ov025_021e2f54(struct Event021e2f54* ev, short* list, char* world) {
    struct Ctx021e2f54* ctx = data_ov025_021ef988.ctx;
    struct Rec021e2f54* rec = _Z24SearchBothTables02079e2cPci((char*)GetData02108e10(), *list);
    void* node = _Z22GetNodeAtIndex021600f8P12List021600f8i((struct List021600f8*)list, 0);
    if (rec != 0 && node != 0) {
        if (IsSpecial021e2f54(node) && rec->kind == 4) {
            ev->state |= 8;
            func_ov025_021ecc54(ctx->queue, ev);
            ev->state = 7;
            func_ov025_021ecc54(ctx->queue, ev);
        } else {
            func_ov025_021ecc54(ctx->queue, ev);
        }
    } else {
        func_ov025_021ecc54(ctx->queue, ev);
    }
    if (ClassifyField0x81fe(world) != 0) {
        data_ov025_021ef988.ctx->flags |= 0x10;
    }
}
