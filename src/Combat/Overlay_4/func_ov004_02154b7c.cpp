#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02154b7c func_ov004_02156204
#endif

struct SelectionData02154b7c {
    char pad0[0x7a];
    unsigned short count;
};

extern SelectionData02154b7c* data_ov004_021707c0;
extern "C" void func_ov004_02153978(void*, short*, short*, short*);
extern "C" int func_ov004_021537e0();
extern "C" int func_ov004_02153860();
extern "C" int func_ov004_021538f0();
extern "C" void func_ov023_021f645c(void*, int, unsigned short, int);
extern "C" void func_ov023_021f64a8(void*, int, int, int);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned int func_ov023_021f6f10(void*);
extern "C" void func_ov023_021f809c(void*, void*);

// USA: func_ov004_02154b7c
extern "C" ARM int func_ov004_02154b7c(void* self) {
    short kind;
    short range;
    short index;
    func_ov004_02153978(self, &kind, &range, &index);
    unsigned short count;
    unsigned short message = 0x32;
    if (kind == 0) {
        count = (short)data_ov004_021707c0->count;
    } else if (range == 0) {
        count = func_ov004_021537e0();
        message = 0x33;
    } else if (kind == 3) {
        count = func_ov004_021538f0();
        message = 0x34;
    } else {
        count = func_ov004_02153860();
        message = 0x34;
    }
    func_ov023_021f645c(self, 7, message, 0xf);
    func_ov023_021f64a8(self, 0x14, count, 0xf);
    void* node = func_ov023_021f6880(func_ov011_021849c8(self), 0x10);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 6) return 0;
    func_ov023_021f809c(node, self);
    return 0;
}
