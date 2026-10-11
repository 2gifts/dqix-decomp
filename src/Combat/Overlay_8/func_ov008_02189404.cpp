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

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(struct Cont0205d228*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
extern "C" void func_ov008_0218aee4(void* obj);
extern "C" void func_ov008_02184878(void* obj);

struct Flags02189404 { char pad[R(0xeb8, 0xec0)]; unsigned char flagEc0 : 1; };

// USA: func_ov008_02189404
extern "C" ARM void func_ov008_02189404(char* obj) {
    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(obj + 0x18));
    CallFunc0204c8f0OverList0x9c((struct Cont0205d228*)(obj + 0x18));
    func_0205da88(obj + 0x18, 1, 2, 1);
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(obj + 0x18));
    func_ov008_0218aee4(obj);
    if (*(signed char*)(obj + R(0xe97, 0xe9b)) == 0) return;
    if (!((struct Flags02189404*)obj)->flagEc0) return;
    func_ov008_02184878(obj + 0x2a8);
}
