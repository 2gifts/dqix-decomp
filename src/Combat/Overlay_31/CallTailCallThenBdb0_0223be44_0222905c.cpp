#include <globaldefs.h>

struct SubObj0222905c { unsigned int field0; unsigned short field4; };
struct DataOv02290c5c {
    unsigned char field0;
    unsigned char field1;
    unsigned char pad2[6];
    SubObj0222905c* field8;
};
extern DataOv02290c5c data_ov031_02290c5c;

extern "C" void func_ov031_02229124(void);
extern "C" void func_ov031_02223998(int);
extern "C" void func_ov031_022373b4(int);
extern "C" void func_ov031_0222336c(int, int, int);
ARM int CallTailCallThenBdb0_0223be44(int a, int b);
extern "C" void func_ov031_022237dc(unsigned short a, unsigned short b, unsigned short c, unsigned short d);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_022292c0(void);

extern unsigned short data_ov031_02248e12[];
extern unsigned short data_ov031_02248e16[];
extern unsigned short data_ov031_02248e14[];
extern unsigned short data_ov031_02248e18[];

// USA: func_ov031_0222905c  (semantic: InitFieldsAndDispatch_0222905c)  (semantic: InitFieldsAndDispatch_0222905c)
extern "C" ARM void func_ov031_0222905c(void) {
    data_ov031_02290c5c.field1 = 0;
    func_ov031_02229124();
    func_ov031_02223998(0x10);
    func_ov031_022373b4(3);
    func_ov031_0222336c(0x39, -1, 0);
    SubObj0222905c* p = (SubObj0222905c*)CallTailCallThenBdb0_0223be44(0, 0x5b);
    data_ov031_02290c5c.field8 = p;
    p->field0 = (p->field0 & 0xfe00ff00) | 0x84 | 0xe00000;
    p = data_ov031_02290c5c.field8;
    p->field4 = (unsigned short)((p->field4 & ~0xc00) | 0xc00);
    unsigned char idx = data_ov031_02290c5c.field0;
    func_ov031_022237dc(data_ov031_02248e12[idx * 4], data_ov031_02248e16[idx * 4], data_ov031_02248e14[idx * 4], data_ov031_02248e18[idx * 4]);
    SetField_022274c0_022274c0((int)func_ov031_022292c0);
}
