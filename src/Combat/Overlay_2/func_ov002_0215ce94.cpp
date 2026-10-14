#include <globaldefs.h>

struct Struct0205de24;

extern "C" void *memset(void *dst, int value, unsigned int length);
struct Struct_0205d81c;
unsigned char * FindElementByC40205d81c(Struct_0205d81c*, int);
extern "C" void func_ov002_0215be00(void *obj, int val, int a2, int a3);
extern "C" void func_ov002_0215d0e8(unsigned char *self, void *buf, int a);
extern "C" void func_ov002_0215d214(unsigned char *self, void *buf, int a);
extern "C" void func_0205d304(void *, void *, int, int, bool, bool, void *, bool);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow, unsigned char keyHigh);
struct StructA0205d5d0;
void TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(Obj0205dee8*, int);
void SetElementFieldC2_0205deb4(Struct_0205d81c*, int, int);

// USA: func_ov002_0215ce94
extern "C" ARM void func_ov002_0215ce94(unsigned char *self) {
    int x = 0x16;
    int y = 1;
    if (*(short *) (self + 0x1c26) != -1) {
        unsigned char *e = FindElementByC40205d81c((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 0x10);
        if (e != 0) {
            x = 1;
            y = (short) (*(short *) (e + 0xae) + *(short *) (e + 0xaa));
        }
    }
    func_ov002_0215be00(self, (unsigned char) *(int *) (self + 0x1000 + 0xbb8), x, y);
    memset(*(void **) (self + 0x1000 + 0xbd0), 0, 0x960);
    func_ov002_0215d0e8(self, *(void **) (self + 0x1000 + 0xbd0), 0);
    func_0205d304(self + 0x2c8 + 0xc00, *(void **) (self + 0x1000 + 0xbd0), 0, 1, false, true, 0, false);
    unsigned char *elem =
        FindElementByC40205d81c((Struct_0205d81c*)(self + 0x2c8 + 0xc00), (unsigned char) *(int *) (self + 0x1000 + 0xbb8));
    if (*(short *) (self + 0x1c26) != -1) {
        elem = FindElementByC40205d81c((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 0x11);
    }
    if (elem != 0) {
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (self + 0x2c8 + 0xc00), 0, 3);
        func_ov002_0215be00(self, 8, *(short *) (elem + 0xac), (short) (*(short *) (elem + 0xae) + *(short *) (elem + 0xaa)));
        memset(*(void **) (self + 0x1000 + 0xbd0), 0, 0x960);
        func_ov002_0215d214(self, *(void **) (self + 0x1000 + 0xbd0), 0);
        func_0205d304(self + 0x2c8 + 0xc00, *(void **) (self + 0x1000 + 0xbd0), 0, 0, false, true, 0, false);
        unsigned char *box = FindElementByC40205d81c((Struct_0205d81c*)(self + 0x2c8 + 0xc00), 8);
        if (box != 0) {
            short bx = *(short *) (box + 0xac);
            short by = *(short *) (box + 0xae);
            short bw = *(short *) (box + 0xa8);
            if (*(short *) (self + 0x1c26) != -1) {
                by = by - 4;
            } else {
                bx = 0x1f - bw;
            }
            *(short *) (box + 0xac) = bx;
            *(short *) (box + 0xae) = by;
            TryApplyElemFields0205d5d0((StructA0205d5d0*)(self + 0x2c8 + 0xc00), 8, (int)(*(void **) (self + 0x1000 + 0xbd0)), 1, 0);
        }
    }
    SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + 0x2c8 + 0xc00), (unsigned char) *(int *) (self + 0x1000 + 0xbb8));
    SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + 0x2c8 + 0xc00), (unsigned char) *(int *) (self + 0x1000 + 0xbb8), 0);
}
