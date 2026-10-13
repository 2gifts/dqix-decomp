#include <globaldefs.h>

extern "C" unsigned char* func_ov031_02220390(void*);

struct Obj022203f0 {
    unsigned char field_00;
    unsigned char field_01;
    unsigned char field_02;
    unsigned char field_03;
    unsigned char field_04;
    unsigned char field_05;
    unsigned char field_06;
    unsigned char field_07;
};

// USA: func_ov031_022203f0
extern "C" THUMB int func_ov031_022203f0(struct Obj022203f0* self) {
    self->field_00 = 0;
    self->field_01 = 0;
    self->field_02 = 0;
    self->field_03 = 0;
    self->field_04 = 0;
    self->field_05 = 0;
    self->field_06 = 0;
    self->field_07 = 0;

    int size = (int)func_ov031_02220390((unsigned char*)self + 8) - (int)self;
    ((unsigned short*)self)[0] = (unsigned short)(size - 8);
    return size;
}
