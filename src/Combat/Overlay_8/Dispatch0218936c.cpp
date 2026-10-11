#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_02184968 func_ov008_02185a64
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_0205d0e0(void* obj);
extern "C" void func_ov008_021895a8(void* obj);
extern "C" void func_ov008_02189c70(void* obj);
extern "C" void func_ov008_0218af80(void* obj);
extern "C" void func_ov008_02184754(void* obj);
extern "C" void func_ov008_0218b084(void* obj);

struct Manager0218936c {
    char pad[R(0xe95, 0xe99)];
    signed char sub99;
    signed char sub9a;
    signed char sub9b;
    char pad2[R(0xeb0 - 0xe98, 0xeb8 - 0xe9c)];
    unsigned char fieldEb8;
};

// USA: func_ov008_0218936c
ARM unsigned char Dispatch0218936c(Manager0218936c* obj) {
    func_0205d0e0((char*)obj + 0x18);
    switch (obj->sub99) {
    case 0:
        func_ov008_021895a8(obj);
        break;
    case 1:
        func_ov008_02189c70(obj);
        break;
    case 2:
        obj->sub9a = 0;
        break;
    }
    switch (obj->sub9b) {
    case 0:
        func_ov008_0218af80(obj);
        break;
    case 1:
        func_ov008_02184754((char*)obj + 0x2a8);
        break;
    case 2:
        func_ov008_0218b084(obj);
        break;
    }
    return obj->fieldEb8;
}
