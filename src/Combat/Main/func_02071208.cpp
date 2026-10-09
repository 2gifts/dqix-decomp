#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);

struct Obj02071208 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    unsigned char f8;
    char pad9[0xa - 0x9];
    short f0a;
    short f0c;
    short f0e;
    short f10;
    char name[0x20];
    char desc[0xc];
    short f3e;
    short f40;
    short f42;
    unsigned short f44;
    short f46;
    Vector3fix vec;
    short f54;
    char tag[0x10];
};

struct Data02071208 {
    short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned short h6;
    char pad8[0xc - 0x8];
    int w0xc;
    char pad10[0x18 - 0x10];
    int w0x18;
    char pad1c[0x20 - 0x1c];
    Obj02071208* w0x20;
};
extern struct Data02071208 data_02108d70;

// USA: func_02071208
extern "C" ARM int func_02071208(Script::Parameter* params) {
    data_02108d70.h4++;
    if (data_02108d70.w0xc != 0) {
        return 1;
    }

    int b0 = params[0].ToInt();
    int b1 = params[1].ToInt();
    int b2 = params[2].ToInt();
    int b3 = params[3].ToInt();
    int b4 = params[4].ToInt();
    int b5 = params[5].ToInt();

    if (b5 == data_02108d70.w0x18) {
        data_02108d70.w0x20->f0 = b0;
        data_02108d70.w0x20->f2 = b2;
        data_02108d70.w0x20->f1 = b1;
        data_02108d70.w0x20->f3 = b3;
        data_02108d70.w0x20->f0e = b4;
        data_02108d70.w0x20->f0a = b5;

        data_02108d70.w0x20->f0c = params[6].ToInt();

        const char* s7 = params[7].ToString();
        if (s7) {
            memcpy(data_02108d70.w0x20->name, s7, 0x20);
            data_02108d70.w0x20->name[0x1f] = 0;
        }

        const char* s8 = params[8].ToString();
        if (!s8) {
            return 0;
        }
        strcpy(data_02108d70.w0x20->desc, s8);

        data_02108d70.w0x20->f3e = params[9].ToInt();
        data_02108d70.w0x20->f40 = params[10].ToInt();
        data_02108d70.w0x20->f42 = params[11].ToInt();
        params = params[12].ToVec3fix(&data_02108d70.w0x20->vec);
        data_02108d70.w0x20->f54 = _ffix(_fmul(4096.0f, params->ToFloat()));

        data_02108d70.w0x20->f5 = params[1].ToInt();
        data_02108d70.w0x20->f46 = params[2].ToInt();
        if (data_02108d70.w0x20->f46 >= 0) {
            data_02108d70.w0x20->f46 = data_02108d70.h4 - 1;
        }
        data_02108d70.w0x20->f4 = params[3].ToInt();
        data_02108d70.w0x20->f6 = params[4].ToInt();

        const char* s17 = params[5].ToString();
        if (s17) {
            memcpy(data_02108d70.w0x20->tag, s17, 0x10);
            data_02108d70.w0x20->tag[0xf] = 0;
        }

        data_02108d70.w0x20->f44 = params[6].ToInt();
        if (func_0202c540(func_0202ae18())) {
            data_02108d70.w0x20->f44 = data_02108d70.w0x20->f44 & ~8;
        }

        data_02108d70.w0x20->f10 = params[7].ToInt();
        data_02108d70.w0xc = 1;
    }
    return 1;
}