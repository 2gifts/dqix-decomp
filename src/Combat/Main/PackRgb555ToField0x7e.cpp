#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

struct Global020fdc20_d4ec {
    int pad0;
    int pad4;
    unsigned char* obj;
};
extern struct Global020fdc20_d4ec data_020fdc20;

// USA: func_0201d4ec
ARM int WarpScript_Opcode_70(Script::Parameter* arg0, int) {
    struct Variant02030b0c* v = (struct Variant02030b0c*)arg0;
    int a = ((Script::Parameter*)v)->ToInt();
    int b = ((Script::Parameter*)(v + 1))->ToInt();
    int c = ((Script::Parameter*)(v + 2))->ToInt();
    *(unsigned short*)(data_020fdc20.obj + 0x7e) = a | (b << 5) | (c << 10);
    return 1;
}
