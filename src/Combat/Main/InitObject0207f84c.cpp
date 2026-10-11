#include <globaldefs.h>

struct Struct0207f510;
struct ArrayHeader0207ef60;
void Reset0207f510(Struct0207f510* obj);
void InitArrayHeader(ArrayHeader0207ef60* arr);

struct Obj0207f84c {
    int field0;
    unsigned char sub4[8];
    unsigned char arrC[8];
    int field14;
    int field18;
    int field1c;
#if !defined(jpn)
    int field20;
    int field24;
    int field28;
#endif
    int field2c;
    int field30;
    short field34;
    short field36;
    unsigned char field38;
    unsigned char field39;
    unsigned char field3a;
    unsigned char field3b;
    unsigned char field3c;
};

// USA: func_0207f84c  (semantic: InitObject0207f84c)
extern "C" ARM void func_0207f84c(Obj0207f84c* self) {
    self->field0 = 0;
    Reset0207f510((Struct0207f510*)self->sub4);
    InitArrayHeader((ArrayHeader0207ef60*)self->arrC);
    self->field14 = 0;
    self->field18 = 0;
#if defined(jpn)
    self->field1c = -1;
#else
    self->field20 = self->field24 = self->field28 = self->field1c = -1;
#endif
    self->field2c = 0;
    self->field30 = 0;
    self->field34 = 8;
    self->field36 = -1;
    self->field38 = 0;
    self->field39 = 0;
    self->field3a = 0;
    self->field3b = 0x10;
    self->field3c = 0x10;
}
