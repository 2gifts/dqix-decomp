#if defined(jpn)
#define R(j,u) (j)
#define _Z22SetupBattleTag0218a7a0Pc func_ov012_0218b234
#define _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20 func_ov023_021e7184
#define func_ov012_02184384 func_ov012_021853f8
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int func_ov012_02184384(void* ptr, int idx);
extern "C" void func_ov023_021e6e60(void* obj);
extern "C" int func_ov023_021e6448(void* obj);
extern "C" int func_ov023_021e6de4(char* obj);
struct Obj021e6e20 { char pad[R(0x90,0xac)]; };
#if defined(jpn)
#define TestFlagsAndActiveElement2_021e6e20 func_ov023_021e7184
extern "C" int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);
#else
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);
#endif
#if defined(jpn)
extern "C" void func_ov012_0218adac(void* self, int a, int b);
#else
extern "C" void func_ov012_0218adac(void* self, int a, int b, int c);
#endif
extern "C" void func_ov012_0218930c(void* self, int a);
#if defined(jpn)
#define SetupBattleTag0218a7a0 func_ov012_0218b234
extern "C" void SetupBattleTag0218a7a0(char* base);
#else
void SetupBattleTag0218a7a0(char* base);
#endif

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

struct StateField02188924 { unsigned short count : 5; unsigned short idx : 11; };

// USA: func_ov012_02188924  (semantic: AdvanceTagStateB_02188924)
extern "C" ARM void func_ov012_02188924(char* base) {
    int state = *(unsigned char*)(base + R(0x1340,0x1370));
    if (state == 0) {
        *(unsigned char*)(base + R(0x1368,0x13a0)) = 0;
        int idx = ((struct StateField02188924*)(base + R(0x1400,0x1300) + R(0x1c,0xc4)))->idx;
        void* ptr = *(void**)(base + 0x1000 + R(0x420,0x3c8));
        int result = func_ov012_02184384(ptr, idx);
        *(int*)(base + 0x1000 + R(0x448,0x3f0)) = result;
        if (result < 0) {
            *(int*)(base + 0x1000 + R(0x448,0x3f0)) = 0;
        }
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + R(0x90,0xac)), 0, 3);
        func_ov023_021e6e60(base);
        SetupBattleTag0218a7a0(base);
        (*(unsigned char*)(base + R(0x1340,0x1370)))++;
        return;
    }
    if (state != 1) return;
    *(unsigned char*)(base + R(0x1368,0x13a0)) = 1;
    *(int*)(base + R(0x1448,0x13f0)) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + R(0x90,0xac)));
    if (func_ov023_021e6448(base)) {
        *(int*)(base + R(0x1448,0x13f0)) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + R(0x90,0xac)));
    }
    if (func_ov023_021e6de4(base)) {
        short* sptr = *(short**)(base + 0x1000 + R(0x420,0x3c8));
        int sel = *(int*)(base + 0x1000 + R(0x448,0x3f0));
        short sKey = sptr[sel];
        struct Container020e0310* c = (struct Container020e0310*)(base + R(0x131c,0x1344));
        char* name = (char*)GetFieldByKey020e0434(c, sKey);
        if (!name) return;
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        memset(base + R(0x1458,0x1400), 0, 0x40);
        memcpy(base + R(0x1458,0x1400), name, strlen(name));
        GameState* bs = GameState::GetInstance();
        char* p = (char*)bs + R(0x3c,0x29c) + 0x5400;
        int v = *(int*)(p + 0x4);
        int sel2 = *(int*)(base + 0x1000 + R(0x448,0x3f0));
        unsigned short* uptr = *(unsigned short**)(base + 0x1000 + R(0x420,0x3c8));
        unsigned int raw = uptr[sel2];
        *(int*)(p + 0x4) = (v & 0xc007ffff) | ((raw & 0x7ff) << 19);
        int w = *(int*)((char*)bs + 0x5000 + R(0x43c,0x69c));
        w = (w & ~0x40000000) | 0x20000000;
        *(int*)((char*)bs + 0x5000 + R(0x43c,0x69c)) = w;
#if defined(jpn)
        func_ov012_0218adac(base, 0, -1);
#else
        func_ov012_0218adac(base, 0, -1, 0);
#endif
        func_ov012_0218930c(base, 0);
        return;
    }
    if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)base)) {
        func_ov012_0218930c(base, 1);
    }
}
