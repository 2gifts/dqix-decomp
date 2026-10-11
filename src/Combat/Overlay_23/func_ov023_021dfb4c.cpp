#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
extern "C" void func_ov023_021dcae0(void* obj, int val);
void ResetIfNonNeg_021db2e4(volatile int* p);
struct DispatchEntry_021fdaa8 { int handler; int offsetFlag; };
extern DispatchEntry_021fdaa8 data_ov023_021fdaa8[];

// JPN: func_ov023_021e0160
// USA: func_ov023_021dfb4c  (semantic: RunSubStateDispatch_021dfb4c)
extern "C" ARM void func_ov023_021dfb4c(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6ee, regionalOffset1=0x6ec, regionalOffset2=0x6f0, regionalOffset3=0x6f7, regionalOffset4=0x717, regionalOffset5=0x6b0, regionalOffset6=0x6b4, regionalOffset7=0x6d0};
#else
 enum {regionalOffset0=0x772, regionalOffset1=0x770, regionalOffset2=0x774, regionalOffset3=0x77b, regionalOffset4=0x79b, regionalOffset5=0x734, regionalOffset6=0x738, regionalOffset7=0x754};
#endif
    short field772 = *(short*)((char*)obj + regionalOffset0);
    short field770 = *(short*)((char*)obj + regionalOffset1);
    if (field770 != field772) {
        func_ov023_021dcae0(obj, field772);
    }

    if ((*(unsigned short*)((char*)obj + regionalOffset2) & 1) == 0) {
        return;
    }

    if (*(signed char*)((char*)obj + regionalOffset3) == 1) {
        struct Flags79b_021dfb4c { unsigned char bit0 : 1; unsigned char bit1 : 1; unsigned char rest : 6; };
        if (((Flags79b_021dfb4c*)((char*)obj + regionalOffset4))->bit1 == 0) {
            ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + regionalOffset5));
            for (int i = 0; i < 7; i++) {
                ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + regionalOffset6 + i * 4));
            }
            *(unsigned short*)((char*)obj + regionalOffset2) |= 1;
            *(int*)((char*)obj + regionalOffset7) = 0;
            return;
        }
    }

    (int)BackgroundLoader::GetInstance();
    DispatchEntry_021fdaa8* table = data_ov023_021fdaa8;

    while (*(int*)((char*)obj + regionalOffset7) >= 0 &&
           table[*(int*)((char*)obj + regionalOffset7)].handler != 0) {
        int idx = *(int*)((char*)obj + regionalOffset7);
        DispatchEntry_021fdaa8* entry = &table[idx];
        int offsetFlag = entry->offsetFlag;
        int oldIdx = *(int*)((char*)obj + regionalOffset7);

        char* arg = (char*)obj + (offsetFlag >> 1);
        int (*fn)(void*);
        if (offsetFlag & 1) {
            void* vtab = *(void**)arg;
            fn = *(int(**)(void*))((char*)vtab + entry->handler);
        } else {
            fn = (int(*)(void*))entry->handler;
        }

        int result = fn(arg);
        *(int*)((char*)obj + regionalOffset7) = result;
        if (result < 0) {
            *(unsigned short*)((char*)obj + regionalOffset2) &= ~1;
            ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + regionalOffset5));
            for (int i = 0; i < 7; i++) {
                ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + regionalOffset6 + i * 4));
            }
            return;
        }
        if (oldIdx == result) {
            return;
        }
    }
}
