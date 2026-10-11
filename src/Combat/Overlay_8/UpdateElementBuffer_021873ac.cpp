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

struct StructA0205d5d0;
#if defined(jpn)
#if defined(jpn)
#define TryApplyElemFields0205d5d0 _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih
extern "C" int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d);
#endif
#else
#if defined(jpn)
#define TryApplyElemFields0205d5d0 _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih
extern "C" int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#else
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
#endif
#endif
extern "C" void func_ov008_02187278(void* obj, char* dst, int mode, void* extra);

struct Obj021873ac {
    char pad[0xb8];
    char* bufPtr;
    char pad2[0xb18 - 0xbc];
    int flags;
};

// USA: func_ov008_021873ac
ARM void UpdateElementBuffer_021873ac(struct Obj021873ac* obj, int modeArg) {
    if (modeArg == 0) {
        if (!(obj->flags & 0x800)) return;
        memset(obj->bufPtr, 0, R(0x800,0x960));
        func_ov008_02187278(obj, obj->bufPtr, modeArg, 0);
#if defined(jpn)
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->bufPtr, 1);
#else
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->bufPtr, 1, 0);
#endif
        obj->flags &= ~0x800;
    } else if (modeArg == 1) {
        if (!(obj->flags & 0x1000)) return;
        memset(obj->bufPtr, 0, R(0x800,0x960));
        func_ov008_02187278(obj, obj->bufPtr, modeArg, 0);
#if defined(jpn)
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 2, (int)obj->bufPtr, 1);
#else
        TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0x130), 2, (int)obj->bufPtr, 1, 0);
#endif
        obj->flags &= ~0x1000;
    }
}
