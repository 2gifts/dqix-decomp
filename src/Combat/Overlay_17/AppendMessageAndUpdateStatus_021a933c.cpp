#include <globaldefs.h>

struct Container020e0310;
int GetGlobalField0x1c020421a0(void);
int GetFieldByKey020e0434(struct Container020e0310*, int);
extern "C" void func_0204500c(void*, const char*, int, int);
#if defined(jpn)
extern "C" void func_02045d88(void*, const char*, int);
#endif

// JPN: func_ov017_021a9b20
// USA: func_ov017_021a933c  (semantic: AppendMessageAndUpdateStatus_021a933c)
extern "C" ARM void func_ov017_021a933c(void* obj, int key) {
#if defined(jpn)
 enum {regionalOffset0=0x208, regionalOffset1=0x7e2, regionalOffset2=0x86c};
#else
 enum {regionalOffset0=0x278, regionalOffset1=0x9b2, regionalOffset2=0x99c};
#endif
    char* o = (char*)obj;
    int g = GetGlobalField0x1c020421a0();
    if (key <= 0xc7 && key >= 0x64) {
        if (*(int*)(o + 0x14) == 1) key += 0x64;
    }
#if defined(jpn)
    func_02045d88((void*)g, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(o + regionalOffset0), (short)key), 0);
#else
    func_0204500c((void*)g, (const char*)GetFieldByKey020e0434((struct Container020e0310*)(o + regionalOffset0), (short)key), 0, 0xe3);
#endif

    if (key <= 0x12b && key >= 0x64) {
        *((unsigned char*)g + 0x1000 + regionalOffset1) = 1;
    } else {
        *((unsigned char*)g + 0x1000 + regionalOffset1) = 0;
    }
    if (key > 0x12b || key < 0x64) return;
    if (*(int*)(o + 0x14) == 0) {
        *(int*)(g + regionalOffset2) = 2;
    } else {
        *(int*)(g + regionalOffset2) = 1;
    }
}
