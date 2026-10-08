#include <globaldefs.h>

struct DispatchObj020a0dec {
    int selector;
};

extern "C" int _Z26CheckField0NonZero020a10a8Pi(int*);
extern "C" void _Z24DispatchMemberFn020a0decP19DispatchObj020a0dec(struct DispatchObj020a0dec*);
extern "C" void _Z30RotateOffsetAndAdvance0202e894Pvi(void*, int);
int fix32ReduceAngle0To2Pi(int);

struct Obj0202ef14 {
    char pad[0x168];
};

typedef void (Obj0202ef14::*DispatchFn0202ef14)(void*);

struct DispatchTable0202ef14 {
    DispatchFn0202ef14 fns[3];
};

extern const DispatchTable0202ef14 data_020e73cc;
extern const DispatchTable0202ef14 data_020e73e4;

// USA: func_0202ef14
extern "C" ARM void func_0202ef14(struct Obj0202ef14* self) {
    char* obj = (char*)self;
    unsigned int flags = *(unsigned int*)(obj + 0x168);
    struct DispatchObj020a0dec* arr[3];
    arr[0] = (struct DispatchObj020a0dec*)(obj + 0x16c);
    arr[1] = (struct DispatchObj020a0dec*)(obj + 0x194);
    arr[2] = (struct DispatchObj020a0dec*)(obj + 0x1bc);

    int i;
    if (flags & 2) {
        struct DispatchTable0202ef14 table = data_020e73e4;
        for (i = 0; i < 3; i++) {
            if (_Z26CheckField0NonZero020a10a8Pi((int*)arr[i])) {
                _Z24DispatchMemberFn020a0decP19DispatchObj020a0dec(arr[i]);
                void* arg = (void*)((char*)arr[i] + 4);
                (self->*table.fns[i])(arg);
            }
        }
    } else {
        struct DispatchTable0202ef14 table = data_020e73cc;
        for (i = 0; i < 3; i++) {
            if (_Z26CheckField0NonZero020a10a8Pi((int*)arr[i])) {
                _Z24DispatchMemberFn020a0decP19DispatchObj020a0dec(arr[i]);
                void* arg = (void*)((char*)arr[i] + 4);
                (self->*table.fns[i])(arg);
            }
        }
    }

    if (*(unsigned short*)(obj + 0x1ee) != 0) {
        *(unsigned short*)(obj + 0x1ee) -= 1;
        *(unsigned short*)(obj + 0x7c) = (unsigned short)(*(short*)(obj + 0x7c) + *(short*)(obj + 0x1ec));
    }

    if (*(unsigned short*)(obj + 0x210) != 0) {
        *(unsigned short*)(obj + 0x210) -= 1;
        _Z30RotateOffsetAndAdvance0202e894Pvi(obj, *(short*)(obj + 0x20e));
    }

    if (*(unsigned short*)(obj + 0x216) != 0) {
        *(unsigned short*)(obj + 0x216) -= 1;
        *(unsigned short*)(obj + 0x212) = (unsigned short)fix32ReduceAngle0To2Pi(*(short*)(obj + 0x212) + *(short*)(obj + 0x214));
    }
}