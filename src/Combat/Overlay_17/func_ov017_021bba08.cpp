// JPN: func_ov017_021bc000
#if defined(jpn)
enum { RegionOffset9c = 0x98 };
#else
enum { RegionOffset9c = 0x9c };
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

int GetField5cb0Value(char* obj);
int GetField5cb4Value(char* obj);
extern "C" void func_ov017_021baedc(void* self, int flag);

extern char data_ov017_021d7d7e[0xc];

struct Obj021bba08 {
    char pad0[0xc];
    unsigned char f0xc;
    unsigned char f0xd;
    unsigned char f0xe;
    unsigned char f0xf;
    unsigned char f0x10;
    unsigned char f0x11;
    unsigned char f0x12;
    char pad1[0x16 - 0x13];
    short f0x16;
    char pad2[0x1a - 0x18];
    short f0x1a;
    char pad3[0x1e - 0x1c];
    char f0x1e[7];
    char pad4[0x3e - 0x25];
    char f0x3e[0xc];
    short f0x4a;
    short f0x4c;
    short f0x4e;
    short f0x50;
    short f0x52;
    char f0x54[0xc];
    short f0x60;
    char pad6[RegionOffset9c - 0x62];
    unsigned char f0x9c;
};

// USA: func_ov017_021bba08  (semantic: InitStateAndCopyEventData_021bba08)
extern "C" ARM void func_ov017_021bba08(struct Obj021bba08* obj, unsigned char* arg1) {
    func_ov017_021baedc(obj, 1);
    obj->f0x9c = 1;

    GameState* bs = GameState::GetInstance();
    char* b = (char*)bs;
    obj->f0xc = (unsigned char)GetField5cb0Value(b);
    obj->f0xe = (unsigned char)GetField5cb0Value(b);
    obj->f0xd = (unsigned char)GetField5cb4Value(b);
    obj->f0xf = (unsigned char)GetField5cb4Value(b);

    obj->f0x16 = 3;
    obj->f0x10 = 1;
    obj->f0x11 = 0;

    obj->f0x1a = *(unsigned short*)arg1;
    memcpy(obj->f0x1e, arg1 + 5, 7);

    memcpy(obj->f0x3e, data_ov017_021d7d7e, 0xc);

    obj->f0x4a = 100;
    obj->f0x4c = 200;
    obj->f0x4e = 300;
    short v = 0x40;
    obj->f0x50 = v;
    obj->f0x52 = v - 0x41;

    obj->f0x12 = 0;
    memset(obj->f0x54, 0, 0xc);

    obj->f0x60 = 0;
}
