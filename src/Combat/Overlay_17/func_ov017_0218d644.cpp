// JPN: func_ov017_0218e224
#if defined(jpn)
enum { RegionOffset4498 = 0x41e8 };
#else
enum { RegionOffset4498 = 0x4498 };
#endif

#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "std_library_functions.h"

void StoreThreeWords_0218cbcc(int* p, int a, int b, int c);
struct Obj020dbfa4;
void ProcessPendingNode020dbfa4(struct Obj020dbfa4* o, int arg1);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

extern int data_02108760;
extern char data_ov017_021d739f;

struct LocalEvt0218d644 {
    char name[0x10];
    unsigned char byte10;
    unsigned char b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
    short field12;
    short f14, f16, f18, f1a;
    short f1c;
    int f20, f24, f28;
    int words2c[3];
    int f38, f3c, f40;
    int f44, f48, f4c;
};

// USA: func_ov017_0218d644  (semantic: PrepareAndDispatchEventRecord_0218d644)
extern "C" ARM void func_ov017_0218d644(GameResources* ov, void* a, int b) {
    struct Obj020dbfa4* p = *(struct Obj020dbfa4**)((char*)ov + RegionOffset4498);

    struct LocalEvt0218d644 buf;
    buf.name[0] = 0;
    buf.byte10 = 1;
    buf.b0 = 0;
    buf.b1 = 0;
    buf.b2 = 1;
    buf.b3 = 0;
    buf.b4 = 0;
    buf.b5 = 0;
    buf.b6 = 0;
    buf.b7 = 0;
    buf.f14 = -1;
    buf.f16 = -1;
    buf.f18 = -1;
    buf.f1a = -1;
    buf.f1c = -0x1000;
    buf.f20 = 0;
    buf.f24 = 0;
    buf.f28 = 0;
    buf.words2c[0] = 0;
    buf.words2c[1] = 0;
    buf.words2c[2] = 0;
    buf.f38 = 0;
    buf.f3c = 0;
    buf.f40 = 0;
    buf.f44 = 0x1000;
    buf.f48 = 0x1000;
    buf.f4c = 0x1000;
    buf.b2 = 0;
    buf.field12 = (short)b;
    strcpy(buf.name, &data_ov017_021d739f);

    buf.f44 = 0x10a;
    buf.f48 = 0x10a;
    buf.f4c = 0x10a;

    int* src = (int*)a;
    StoreThreeWords_0218cbcc(buf.words2c, src[0], src[1], src[2]);
    ProcessPendingNode020dbfa4(p, (int)&buf);
    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x5f, 0);
}
