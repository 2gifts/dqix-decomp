#include <globaldefs.h>
#include "Resource/Script.h"

struct Element0207f5d0 {
    int field00;
    short id;
    short field06;
    short field08;
    short field0a;
    short field0c;
    short field0e;
    short field10;
    unsigned char type;
    unsigned char lower : 4;
    unsigned char upper : 4;
    unsigned char mode : 2;
    unsigned char count : 6;
    unsigned char padding15[3];
    short field18;
    short padding1a;
    short field1c;
    short padding1e;
    short field20;
    short padding22;
    short field24;
    short padding26;
    short field28;
    unsigned char field2a;
    unsigned char field2b;
    unsigned char field2c;
    unsigned char field2d;
};
struct List0207f5d0;
void AppendElement0207f5d0(List0207f5d0*, Element0207f5d0*);
extern void* data_02108ee0[2];

// USA: func_0207f158
extern "C" ARM int func_0207f158(Script::Parameter* parameters) {
    Element0207f5d0 element;
    element.field00 = 0;
    element.id = -1;
    element.field08 = 0;
    element.field06 = 0;
    element.field0c = 0;
    element.field0a = 0;
    element.field0e = -1;
    element.field10 = -1;
    element.type = 0;
    element.lower = 10;
    element.upper = 0;
    element.mode = 0;
    element.count = 3;
    element.field18 = -1;
    element.field1c = -1;
    element.field20 = -1;
    element.field24 = -1;
    element.field28 = 0;
    element.field2a = 0;
    element.field2b = 0;
    element.field2c = 0;
    element.id = parameters[0].ToInt();
    element.field06 = parameters[1].ToInt();
    element.field08 = parameters[2].ToInt();
    element.type = parameters[3].ToInt();
    switch (element.type) {
    case 0:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        element.field0e = parameters[6].ToInt();
        break;
    case 1:
        element.field0a = parameters[4].ToInt();
        element.field0c = parameters[5].ToInt();
        element.upper = parameters[6].ToInt();
        break;
    case 2:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        element.field0e = parameters[6].ToInt();
        element.field10 = parameters[7].ToInt();
        break;
    case 3:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        element.field0e = parameters[6].ToInt();
        element.mode = parameters[7].ToInt();
        element.count = parameters[8].ToInt();
        element.field10 = parameters[9].ToInt();
        break;
    case 4:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        break;
    case 5:
        element.lower = parameters[4].ToInt();
        element.upper = parameters[5].ToInt();
        element.mode = parameters[6].ToInt();
        element.count = parameters[7].ToInt();
        element.field10 = parameters[8].ToInt();
        break;
    }
    AppendElement0207f5d0((List0207f5d0*)data_02108ee0[1], &element);
    return 1;
}
