#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185a24 func_ov012_02186084
#endif

extern "C" void _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(void*);
extern "C" void _Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228(void*);
extern "C" void _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(void*);
extern "C" void _Z33UpdateEntryFromDoublePtr_021e6b04Pc(char*);
extern "C" void _Z37InitBuffersAndConfigureEntry_021e761cPv(void*);
extern "C" void func_0205da88(void*, int, int, int);
extern "C" void func_ov023_021e67f4(char*);
extern "C" void func_ov023_021e68cc(char*);
extern "C" void func_ov023_021e6a14(char*);
extern "C" void func_ov024_021e6a90(char*);

// USA: func_ov012_02185a24  (semantic: Trans_02185a24)
extern "C" ARM void func_ov012_02185a24(char* obj) {
    _Z37InitBuffersAndConfigureEntry_021e761cPv(obj + 0xd28);
    _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(obj + 0xac);
    _Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228(obj + 0xac);
    func_0205da88(obj + 0xac, 1, 2, 1);
    func_0205da88(obj + 0xac, 1, 3, 1);
    func_0205da88(obj + 0xac, 2, 3, 0);
    _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(obj + 0xac);
    func_ov023_021e67f4(obj);
    func_ov023_021e68cc(obj);
    func_ov023_021e6a14(obj);
    func_ov024_021e6a90(obj);
    _Z33UpdateEntryFromDoublePtr_021e6b04Pc(obj);
}
