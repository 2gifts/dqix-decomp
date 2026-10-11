#if defined(jpn)
#define R(j,u) (j)
#define _Z22SetupBattleTag02189d68Pc func_ov012_0218a804
#define _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20 func_ov023_021e7184
#define data_ov009_0218ac04 data_ov009_0218bb6c
#define data_ov013_02187d94 data_ov013_02188cd0
#define func_ov008_02187278 func_ov008_02188140
#define func_ov008_02187b20 func_ov008_021888fc
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov013_02185900 func_ov013_02186aec
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" int func_ov012_0218432c(int a);
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
#define SetupBattleTag02189d68 func_ov012_0218a804
extern "C" void SetupBattleTag02189d68(char* base);
#else
void SetupBattleTag02189d68(char* base);
#endif

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;
struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

struct CountField0218a5f0 { unsigned short count : 5; unsigned short rest : 11; };

// USA: func_ov012_02187158  (semantic: AdvanceTagState_02187158)
extern "C" ARM void func_ov012_02187158(char* base) {
    int state = *(unsigned char*)(base + R(0x1340,0x1370));
    if (state == 0) {
        *(unsigned char*)(base + R(0x1368,0x13a0)) = 0;
        *(int*)(base + R(0x143c,0x13e4)) = 0;
        int cmpVal = func_ov012_0218432c(2);
        int i;
        for (i = 0; i < ((struct CountField0218a5f0*)(base + R(0x1400,0x1300) + R(0x1c,0xc4)))->count; i++) {
            if (cmpVal == (*(signed char**)(base + 0x1000 + R(0x418,0x3c0)))[i]) {
                *(int*)(base + 0x1000 + R(0x43c,0x3e4)) = i;
                break;
            }
        }
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + R(0x90,0xac)), 0, 3);
        func_ov023_021e6e60(base);
        SetupBattleTag02189d68(base);
        (*(unsigned char*)(base + R(0x1340,0x1370)))++;
        return;
    }
    if (state != 1) return;
    *(unsigned char*)(base + R(0x1368,0x13a0)) = 1;
    *(int*)(base + R(0x143c,0x13e4)) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + R(0x90,0xac)));
    if (func_ov023_021e6448(base)) {
        *(int*)(base + R(0x143c,0x13e4)) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + R(0x90,0xac)));
    }
    if (func_ov023_021e6de4(base)) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        GameState* bs = GameState::GetInstance();
        int val = (*(signed char**)(base + 0x1000 + R(0x418,0x3c0)))[*(int*)(base + 0x1000 + R(0x43c,0x3e4))];
        short key = (short)(val + 0x2710);
        char* name = (char*)FindEntryByKey((struct TableA68*)(base + R(0x1314,0x133c)), key);
        char* p = (char*)bs + R(0x3c,0x29c) + 0x5400;
        memset(base + R(0x1498,0x1440), 0, 0x40);
        memcpy(base + R(0x1498,0x1440), name, strlen(name));
        int v = *(int*)(p + 0x4);
        *(int*)(p + 0x4) = (v & 0xfff801ff) | ((val & 0x3ff) << 9);
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
