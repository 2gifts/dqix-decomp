#include <globaldefs.h>

void WaitForSharedFlagBit7020d2820(void);
void InitGridRowsAndFlushCache_020d2a48(void*);
struct MsgNode020d248c;
void EnqueueTailNode(MsgNode020d248c*);
extern "C" int func_020d2404(int);
extern "C" void func_020d24c4(int);

struct Node020d2220 {
    struct Node020d2220* next;
    unsigned char pad[20];
};
extern struct Node020d2220 data_02112a60[256];

extern int data_02114248;

struct Dispatch020d2220 {
    struct Node020d2220* pool;
    int field4;
    struct Node020d2220* head;
    struct Node020d2220* tail;
    void* last;
    int field14;
    int field18;
    int field1c;
    int field20;
};
extern struct Dispatch020d2220 data_02112780;

struct Holder020d2220 {
    unsigned char pad[0xac8];
    int tail;
};
extern struct Holder020d2220 data_02113780;

struct Grid020d2220 {
    unsigned char pad[0x280];
};
extern struct Grid020d2220 data_021127e0;
extern struct Grid020d2220* data_021142c0;

struct MsgNode020d2220 {
    void* next;
    int kind;
    void* arg;
};

// USA: func_020d2220
extern "C" ARM void func_020d2220(void) {
    int i;
    struct MsgNode020d2220* node;
    WaitForSharedFlagBit7020d2820();
    data_02112780.pool = data_02112a60;
    for (i = 0; i < 255; i++) {
        data_02112a60[i].next = &data_02112a60[i + 1];
    }
    data_02113780.tail = 0;
    data_02112780.last = &data_02114248;
    data_02112780.head = 0;
    data_02112780.tail = 0;
    data_02112780.field1c = 0;
    data_02112780.field14 = 0;
    data_02112780.field18 = 0;
    data_02112780.field20 = 1;
    data_02112780.field4 = 0;
    data_021142c0 = &data_021127e0;
    InitGridRowsAndFlushCache_020d2a48(&data_021127e0);
    node = (struct MsgNode020d2220*)func_020d2404(1);
    if (node == 0) return;
    node->kind = 0x1d;
    node->arg = data_021142c0;
    EnqueueTailNode((MsgNode020d248c*)node);
    func_020d24c4(1);
}
