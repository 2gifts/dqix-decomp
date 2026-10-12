#include <globaldefs.h>

#if defined(jpn)
enum { kFirstFlagOffset = 0x7e1, kSecondFlagOffset = 0x7e2, kStateOffset = 0x868 };
#else
enum { kFirstFlagOffset = 0x9b1, kSecondFlagOffset = 0x9b2, kStateOffset = 0x998 };
#endif


#if defined(jpn)
#define func_02042b98 func_02043270
#endif


#if defined(jpn)
#define func_ov025_021e5e1c func_ov025_021e630c
#endif

int GetGlobalField0x1c020421a0();
#if defined(jpn)
extern "C" void func_0204500c(void* field, void* buf, int p2);
#else
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
#endif
extern "C" void func_02042b98(void* self, int arg1, int arg2, int arg3, int arg4);

struct Param021e5e1c { char pad[8]; void* field8; };

// USA: func_ov025_021e5e1c  (semantic: InitGlobalFieldsAndFlags_021e5e1c)
extern "C" ARM void func_ov025_021e5e1c(struct Param021e5e1c* p) {
    int base = GetGlobalField0x1c020421a0();
    void* field8 = p->field8;
#if defined(jpn)
    func_0204500c((void*)base, field8, 0);
#else
    func_0204500c((void*)base, field8, 0, 0xe3);
#endif
    *(unsigned char*)(base + 0x1000 + kFirstFlagOffset) = 0;
#if defined(jpn)
    *(int*)(base + 0x1730) = 0xc;
    *(int*)(base + 0x1734) = 0x10;
    func_02042b98((void*)base, *(int*)(base + 0x1730), 0x90, 0x100, 0x30);
#else
    func_02042b98((void*)base, 2, 0x92, 0xfc, 0x4a);
#endif
    *(unsigned char*)(base + 0x1000 + kSecondFlagOffset) = 0;
    *(int*)(base + kStateOffset) = 1;
}
