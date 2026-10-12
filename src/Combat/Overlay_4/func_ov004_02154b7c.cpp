#include <globaldefs.h>

extern char* data_ov004_021707c0; // pointer to struct with fields at 0x78 (short), 0x7a (short)

extern "C" void func_ov004_02153978(void* self, short* a, short* b, short* c);
extern "C" short func_ov004_021537e0(void);
extern "C" short func_ov004_021538f0(void);
extern "C" short func_ov004_02153860(void);
extern "C" void func_ov023_021f645c(void* a, int b, int c, int d);
extern "C" void func_ov023_021f64a8(void* a, int b, int c, int d);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" int func_ov023_021f809c(void*, void*);

// USA: func_ov004_02154b7c
extern "C" ARM int func_ov004_02154b7c(void* self) {
    short fA, fB, fC;
    func_ov004_02153978(self, &fA, &fB, &fC);

    int mode = 0x32;
    unsigned short total;
    if (fA == 0) {
        // the (short) hop keeps the sign-extending ldrsh: without it mwcc folds the
        // int->unsigned short conversion into the load and emits a single ldrh.
        total = (unsigned short)(short)(int)*(short*)(data_ov004_021707c0 + 0x7a);
    } else if (fB == 0) {
        total = func_ov004_021537e0();
        mode = 0x33;
    } else if (fA == 3) {
        total = func_ov004_021538f0();
        mode = 0x34;
    } else {
        total = func_ov004_02153860();
        mode = 0x34;
    }

    func_ov023_021f645c(self, 7, mode, 0xf);
    func_ov023_021f64a8(self, 0x14, total, 0xf);

    void* node = func_ov023_021f6880(func_ov011_021849c8(self), 0x10);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 6) return 0;
    func_ov023_021f809c(node, self);
    return 0;
}