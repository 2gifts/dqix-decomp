#include <globaldefs.h>
struct Input0220764c {
    int field_0x0;
    void* (*allocate)(void*, unsigned int);
    void (*free)(void*, void*, unsigned int);
    int enabled;
    unsigned int field_0x10, field_0x14, field_0x18, field_0x1c, field_0x20;
    char pad24[8];
    int field_0x2c, field_0x30;
};
struct Config0220764c {
    int field_0x0;
    void (*free)(void*, void*, unsigned int);
    int field_0x8;
    void* (*allocate)(void*, unsigned int);
    char pad10[0x30];
    int enabled;
    unsigned int field_0x44, field_0x48, field_0x4c, field_0x50, field_0x54;
    void* (*allocateWithHeader)(unsigned int);
    void (*freeWithHeader)(void*);
    int field_0x60;
    char pad64[0xc];
    int field_0x70, field_0x74;
};
extern Config0220764c data_ov031_0224e234;
extern char data_ov031_0224e274;
extern "C" void* _Z31AllocateWithSizeHeader_022075f4j(unsigned int);
extern "C" void _Z27FreeWithSizeHeader_02207620Pv(void*);
extern "C" void func_ov031_02204dbc(void*);
// USA: func_ov031_0220764c
extern "C" ARM void func_ov031_0220764c(Input0220764c* input) {
    data_ov031_0224e234.enabled = input->enabled == 1;
    data_ov031_0224e234.field_0x44 = (((input->field_0x10 >> 24) & 0xff) | ((input->field_0x10 >> 8) & 0xff00) | ((input->field_0x10 << 8) & 0xff0000) | ((input->field_0x10 << 24) & 0xff000000));
    data_ov031_0224e234.field_0x48 = (((input->field_0x14 >> 24) & 0xff) | ((input->field_0x14 >> 8) & 0xff00) | ((input->field_0x14 << 8) & 0xff0000) | ((input->field_0x14 << 24) & 0xff000000));
    data_ov031_0224e234.field_0x4c = (((input->field_0x18 >> 24) & 0xff) | ((input->field_0x18 >> 8) & 0xff00) | ((input->field_0x18 << 8) & 0xff0000) | ((input->field_0x18 << 24) & 0xff000000));
    data_ov031_0224e234.field_0x50 = (((input->field_0x1c >> 24) & 0xff) | ((input->field_0x1c >> 8) & 0xff00) | ((input->field_0x1c << 8) & 0xff0000) | ((input->field_0x1c << 24) & 0xff000000));
    data_ov031_0224e234.field_0x54 = (((input->field_0x20 >> 24) & 0xff) | ((input->field_0x20 >> 8) & 0xff00) | ((input->field_0x20 << 8) & 0xff0000) | ((input->field_0x20 << 24) & 0xff000000));
    data_ov031_0224e234.allocateWithHeader = _Z31AllocateWithSizeHeader_022075f4j;
    data_ov031_0224e234.freeWithHeader = _Z27FreeWithSizeHeader_02207620Pv;
    data_ov031_0224e234.allocate = input->allocate;
    data_ov031_0224e234.free = input->free;
    data_ov031_0224e234.field_0x60 = 0x40;
    data_ov031_0224e234.field_0x70 = input->field_0x2c;
    data_ov031_0224e234.field_0x74 = input->field_0x30;
    func_ov031_02204dbc(&data_ov031_0224e274);
}
