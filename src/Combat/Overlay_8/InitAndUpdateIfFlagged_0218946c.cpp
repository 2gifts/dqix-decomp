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

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
extern "C" void func_ov008_02184968(void* p);

struct FlagE99_0218946c { char pad[R(0x95, 0x99)]; signed char flag99; };
struct FlagE9b_0218946c { char pad[R(0x97, 0x9b)]; signed char flag9b; };
struct FlagEc0_0218946c { char pad[R(0xeb8, 0xec0)]; unsigned char flag : 1; };

// USA: func_ov008_0218946c  (semantic: InitAndUpdateIfFlagged_0218946c)
extern "C" ARM void func_ov008_0218946c(char* obj) {
    if (((struct FlagE99_0218946c*)(obj + 0xe00))->flag99 != 0) {
        InitEntries0205d2bc((struct Obj0205d2bc*)(obj + 0x18));
    }
    if (((struct FlagE9b_0218946c*)(obj + 0xe00))->flag9b == 0) return;
    if (!((struct FlagEc0_0218946c*)obj)->flag) return;
    func_ov008_02184968(obj + 0x2a8);
}
