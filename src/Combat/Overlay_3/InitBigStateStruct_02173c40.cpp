#include <globaldefs.h>
#include "System/Memory.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue44_42 = 0x42 };
enum { kRegionValueC4_C2 = 0xc2 };
enum { kRegionValueCA_C8 = 0xc8 };
enum { kRegionValueCB_C9 = 0xc9 };
enum { kRegionValueCC_CA = 0xca };
enum { kRegionValueC6_C4 = 0xc4 };
enum { kRegionValueC8_C6 = 0xc6 };
enum { kRegionValueD0_CC = 0xcc };
enum { kRegionValueD4_D0 = 0xd0 };
enum { kRegionValueD5_D1 = 0xd1 };
enum { kRegionValueD8_D4 = 0xd4 };
enum { kRegionValueEC_E8 = 0xe8 };
enum { kRegionValueED_E9 = 0xe9 };
enum { kRegionValueEE_EA = 0xea };
enum { kRegionValueEF_EB = 0xeb };
enum { kRegionValueF0_F4 = 0xf4 };
enum { kRegionValueF4_F8 = 0xf8 };
enum { kRegionValue10A_118 = 0x118 };
enum { kRegionValue10B_119 = 0x119 };
enum { kRegionValue11C_12A = 0x12a };
enum { kRegionValue11D_12B = 0x12b };
enum { kRegionValue120_12C = 0x12c };
enum { kRegionValue124_130 = 0x130 };
enum { kRegionValue128_134 = 0x134 };
enum { kRegionValue12C_138 = 0x138 };
enum { kRegionValue130_13C = 0x13c };
enum { kRegionValue184_190 = 0x190 };
enum { kRegionValue198_1A4 = 0x1a4 };
enum { kRegionValue1AC_1B8 = 0x1b8 };
enum { kRegionValue1C0_1CC = 0x1cc };
enum { kRegionValue1C4_1D0 = 0x1d0 };
enum { kRegionValue1C8_1D4 = 0x1d4 };
enum { kRegionValue1D0_1DC = 0x1dc };
enum { kRegionValue1D8_1E4 = 0x1e4 };
enum { kRegionValue1E0_1EC = 0x1ec };
enum { kRegionValue344_350 = 0x350 };
#else
enum { kRegionValue44_42 = 0x44 };
enum { kRegionValueC4_C2 = 0xc4 };
enum { kRegionValueCA_C8 = 0xca };
enum { kRegionValueCB_C9 = 0xcb };
enum { kRegionValueCC_CA = 0xcc };
enum { kRegionValueC6_C4 = 0xc6 };
enum { kRegionValueC8_C6 = 0xc8 };
enum { kRegionValueD0_CC = 0xd0 };
enum { kRegionValueD4_D0 = 0xd4 };
enum { kRegionValueD5_D1 = 0xd5 };
enum { kRegionValueD8_D4 = 0xd8 };
enum { kRegionValueEC_E8 = 0xec };
enum { kRegionValueED_E9 = 0xed };
enum { kRegionValueEE_EA = 0xee };
enum { kRegionValueEF_EB = 0xef };
enum { kRegionValueF0_F4 = 0xf0 };
enum { kRegionValueF4_F8 = 0xf4 };
enum { kRegionValue10A_118 = 0x10a };
enum { kRegionValue10B_119 = 0x10b };
enum { kRegionValue11C_12A = 0x11c };
enum { kRegionValue11D_12B = 0x11d };
enum { kRegionValue120_12C = 0x120 };
enum { kRegionValue124_130 = 0x124 };
enum { kRegionValue128_134 = 0x128 };
enum { kRegionValue12C_138 = 0x12c };
enum { kRegionValue130_13C = 0x130 };
enum { kRegionValue184_190 = 0x184 };
enum { kRegionValue198_1A4 = 0x198 };
enum { kRegionValue1AC_1B8 = 0x1ac };
enum { kRegionValue1C0_1CC = 0x1c0 };
enum { kRegionValue1C4_1D0 = 0x1c4 };
enum { kRegionValue1C8_1D4 = 0x1c8 };
enum { kRegionValue1D0_1DC = 0x1d0 };
enum { kRegionValue1D8_1E4 = 0x1d8 };
enum { kRegionValue1E0_1EC = 0x1e0 };
enum { kRegionValue344_350 = 0x344 };
#endif


struct S_a64bc;
void InitFieldsWithDefaults(S_a64bc* p);
void InitStruct0205a444(char* obj);
struct List020727d8;
void ResetListHeader020727d8(List020727d8* list);
struct Obj0217bcb8;
void InitObj0217bcb8(Obj0217bcb8* self);

// USA: func_ov003_02173c40  (semantic: InitBigStateStruct_02173c40)
// JPN: func_ov003_02172e0c
extern "C" ARM void func_ov003_02173c40(char* obj) {
    obj[0] = 0;
    obj[1] = 0;
#if defined(jpn)
    VectorizedMemset(obj + 2, 0, 0x40);
#else
    *(short*)(obj + 2) = -1;
    VectorizedMemset(obj + 4, 0, 0x40);
#endif
    VectorizedMemset(obj + kRegionValue44_42, 0, 0x80);

    obj[kRegionValueC4_C2] = 0;
    obj[kRegionValueCA_C8] = 0;
    obj[kRegionValueCB_C9] = 0;
    obj[kRegionValueCC_CA] = 0;
    *(short*)(obj + kRegionValueC6_C4) = 0;
    *(short*)(obj + kRegionValueC8_C6) = 0;
    *(int*)(obj + kRegionValueD0_CC) = 0;
    obj[kRegionValueD4_D0] = 0;
    obj[kRegionValueD5_D1] = 0;
    InitFieldsWithDefaults((S_a64bc*)(obj + kRegionValueD8_D4));

    obj[kRegionValueEC_E8] = 0;
    obj[kRegionValueED_E9] = 0;
    obj[kRegionValueEE_EA] = 0;
    obj[kRegionValueEF_EB] = 0;
#if defined(jpn)
    *(int*)(obj + 0xec) = 0;
    *(int*)(obj + 0xf0) = 0;
#else
#endif
    *(int*)(obj + kRegionValueF0_F4) = -1;
    *(int*)(obj + kRegionValueF4_F8) = -1;
#if defined(jpn)
    *(int*)(obj + 0x100) = 0;
    *(int*)(obj + 0x104) = 0;
#else
#endif
    obj[kRegionValue10A_118] = 0;
    obj[kRegionValue10B_119] = 0;
    obj[kRegionValue11C_12A] = 0;
    obj[kRegionValue11D_12B] = 0;
    *(int*)(obj + kRegionValue120_12C) = 0;
    *(int*)(obj + kRegionValue124_130) = 0;
    *(int*)(obj + kRegionValue128_134) = 0;
    *(int*)(obj + kRegionValue12C_138) = 0;
    InitStruct0205a444(obj + kRegionValue130_13C);

    ((SafeAllocator*)(obj + kRegionValue184_190))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + kRegionValue198_1A4))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + kRegionValue1AC_1B8))->ResetAllocatorPointer();

    *(int*)(obj + kRegionValue1C0_1CC) = 0;
    *(int*)(obj + kRegionValue1C4_1D0) = 0;
    ResetListHeader020727d8((List020727d8*)(obj + kRegionValue1C8_1D4));
    ResetListHeader020727d8((List020727d8*)(obj + kRegionValue1D0_1DC));
    ResetListHeader020727d8((List020727d8*)(obj + kRegionValue1D8_1E4));

    InitObj0217bcb8((Obj0217bcb8*)(obj + kRegionValue1E0_1EC));

    obj[kRegionValue344_350] = 0;
}
