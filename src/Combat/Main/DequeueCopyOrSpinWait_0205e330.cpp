#include <globaldefs.h>

void PushInterruptDisableState(void);
void BlankFunction020d84e4(void);
void BlankFunction020d84e8(void);
extern "C" void* func_0202ae18(void);
extern "C" void func_020d8694(void);
extern "C" void func_020c9be0(void);
int CheckField0NonZero(int* obj);

struct QNode0205e1e4 {
    char pad[0x18];
    struct QNode0205e1e4* next;
};
struct QList0205e1e4 {
    struct QNode0205e1e4* head;
    struct QNode0205e1e4* tail;
    int count;
};
struct QNode0205e1e4* DequeueNode(struct QList0205e1e4* list);

struct QNode0205e18c {
    char pad[0x18];
    struct QNode0205e18c* next;
};
struct QList0205e18c {
    struct QNode0205e18c* head;
    struct QNode0205e18c* tail;
    int count;
};
void EnqueueNode(struct QList0205e18c* list, struct QNode0205e18c* node);

struct Inner0205e3ec { unsigned int v[4]; };
struct Struct0205e3ec { unsigned char a; unsigned char b; unsigned char pad[2]; struct Inner0205e3ec mid; };
struct Struct0205e3ec* CopyStruct0205e3ec(struct Struct0205e3ec* dst, struct Struct0205e3ec* src);

struct EnqueuedNode_0205e330 {
    char pad[0x16];
    short field16;
};

struct SpinBlock_0205e330 {
    char pad0[0x508];
    volatile int c508;
    char pad1[0x514 - 0x508 - 4];
    volatile int c514;
    char pad2[0x520 - 0x514 - 4];
    volatile int c520;
};

// USA: func_0205e330  (semantic: DequeueCopyOrSpinWait_0205e330)
extern "C" ARM void func_0205e330(unsigned char* obj, struct Struct0205e3ec* arg1, short arg2) {
    struct QNode0205e1e4* node;

    PushInterruptDisableState();
    BlankFunction020d84e4();

    if (CheckField0NonZero((int*)func_0202ae18())) {
        node = DequeueNode((struct QList0205e1e4*)(obj + 0x1500));
        if (node != NULL) {
            CopyStruct0205e3ec((struct Struct0205e3ec*)node, arg1);
            ((struct EnqueuedNode_0205e330*)node)->field16 = arg2;
            EnqueueNode((struct QList0205e18c*)(obj + 0x150c), (struct QNode0205e18c*)node);
        } else {
            for (int i0 = 0; i0 < ((struct SpinBlock_0205e330*)(obj + 0x1000))->c508; i0++);

            for (int i1 = 0; i1 < ((struct SpinBlock_0205e330*)(obj + 0x1000))->c514; i1++);

            for (int i2 = 0; i2 < ((struct SpinBlock_0205e330*)(obj + 0x1000))->c520; i2++);

            func_020c9be0();
        }
    }

    BlankFunction020d84e8();
    func_020d8694();
}
