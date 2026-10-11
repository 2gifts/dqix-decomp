#if defined(jpn)
#define R(j,u) (j)
#define func_ov015_0218e670 func_ov015_0218f290
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct0218e498;
extern "C" ARM void func_ov015_0218e498(struct Struct0218e498* obj);
extern "C" ARM void func_ov015_0218e4f8(void* obj);
struct S0218e574;
extern "C" ARM void func_ov015_0218e574(struct S0218e574* obj);
struct S0218e5c0;
extern "C" ARM void func_ov015_0218e5c0(struct S0218e5c0* obj);
struct S0218e60c;
void HandleFlagAndDispatch_0218e60c(struct S0218e60c* obj);
extern "C" ARM void func_ov015_0218e670(void* obj);

struct S0218f1c4 {
    char pad0x1c[0x1c];
    unsigned char field0x1c;
};

// USA: func_ov015_0218f1c4  (semantic: DispatchByField_0218f1c4_0218f1c4)
extern "C" ARM void func_ov015_0218f1c4(struct S0218f1c4* obj) {
    switch (obj->field0x1c) {
    case 0:
        func_ov015_0218e498((struct Struct0218e498*)obj);
        break;
    case 1:
        func_ov015_0218e4f8(obj);
        break;
    case 3:
        func_ov015_0218e574((struct S0218e574*)obj);
        break;
    case 2:
        func_ov015_0218e5c0((struct S0218e5c0*)obj);
        break;
    case 4:
        HandleFlagAndDispatch_0218e60c((struct S0218e60c*)obj);
        break;
    case 5:
        func_ov015_0218e670(obj);
        break;
    case 6:
        func_ov015_0218e670(obj);
        break;
    }
}
