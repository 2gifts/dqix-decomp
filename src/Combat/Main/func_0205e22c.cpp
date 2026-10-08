#include <globaldefs.h>

extern "C" void* memset(void* dst, int value, unsigned int length);

struct Struct0205e16c;
extern "C" ARM void _Z23ClearThreeWords0205e16cP14Struct0205e16c(struct Struct0205e16c* p);

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

extern "C" void* func_0202ae18(void);
extern "C" void func_0202c288(void);
void* GetSubstructAt0x7c0(void* base);

struct SearchStruct;
void* GetEntryBySignedByteIndex(struct SearchStruct* obj, int value);

struct Elem0205e22c {
    unsigned char pad[0x10];
    unsigned char field10;
    unsigned char pad2[0x14 - 0x11];
};

// USA: func_0205e22c
extern "C" ARM void func_0205e22c(void* obj) {
    _Z23ClearThreeWords0205e16cP14Struct0205e16c((struct Struct0205e16c*)((char*)obj + 0x1500));
    _Z23ClearThreeWords0205e16cP14Struct0205e16c((struct Struct0205e16c*)((char*)obj + 0x150c));
    _Z23ClearThreeWords0205e16cP14Struct0205e16c((struct Struct0205e16c*)((char*)obj + 0x1518));

    memset(obj, 0, 0x1500);

    struct QNode0205e18c* nodes = (struct QNode0205e18c*)obj;
    for (int i = 0; i < 0xc0; i++) {
        EnqueueNode((struct QList0205e18c*)((char*)obj + 0x1500), &nodes[i]);
    }

    void* base = func_0202ae18();
    func_0202c288();

    struct Elem0205e22c* arr = (struct Elem0205e22c*)GetSubstructAt0x7c0(base);
    memset(arr, 0, 0x74);

    for (int j = 0; j < 5; j++) {
        arr[j].field10 = 0xff;
    }

    int idx = 0;
    int off = 0;
    int size = 0x74;
    for (; idx < 4; idx++) {
        void* entry = GetEntryBySignedByteIndex((struct SearchStruct*)base, idx);
        if (entry != NULL) {
            memset(entry, off, size);
        }
    }

    memset((char*)obj + 0x1524, 0xff, 0x20);
}