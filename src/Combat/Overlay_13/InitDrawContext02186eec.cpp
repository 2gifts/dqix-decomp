#include <globaldefs.h>

struct List0208df10;
#if defined(jpn)
extern "C" void func_0208e818(struct List0208df10* l);
#define ClearList0208df10 func_0208e818
#else
void ClearList0208df10(struct List0208df10* l);
#endif
struct List020727d8;
void ResetListHeader020727d8(struct List020727d8* list);
struct List0204af64;
void ResetList0204af64(struct List0204af64* obj);
struct MainBgControlBackup02074af4;
extern "C" void func_02074af4(struct MainBgControlBackup02074af4* obj);
struct SubBgControlBackup02074b64;
void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);

// USA: func_ov013_02186eec  (semantic: InitDrawContext02186eec)
extern "C" ARM void func_ov013_02186eec(void* obj, unsigned char flag) {
    unsigned char* o = (unsigned char*)obj;
    unsigned int v;
#if defined(jpn)
    enum { stateOffset = 0x48, registerOffset = 0x4c, flagOffset = 0x50 };
#else
    enum { stateOffset = 0x5c, registerOffset = 0x60, flagOffset = 0x64 };
#endif

    *(int*)(o + 0x0) = 0;
    ClearList0208df10((struct List0208df10*)(o + 0xc));
    ResetListHeader020727d8((struct List020727d8*)(o + 0x4));
    o[0x24] = 0;
    o[0x25] = 0;
    ResetList0204af64((struct List0204af64*)(o + 0x28));
    *(int*)(o + stateOffset) = -1;
    o[flagOffset] = flag;
    o[flagOffset + 1] = 0;
    o[flagOffset + 2] = 0;
    *(signed char*)(o + flagOffset + 3) = -1;
    o[flagOffset + 4] = 0;
    o[flagOffset + 5] = 0;
#if !defined(jpn)
    *(int*)(o + 0x48) = 0;
    *(int*)(o + 0x4c) = 0;
    *(int*)(o + 0x50) = 0;
    *(int*)(o + 0x54) = 0;
    *(int*)(o + 0x58) = 0;
    *(signed char*)(o + 0x6a) = -1;
#endif

    if (o[flagOffset] == 0) {
        func_02074af4((struct MainBgControlBackup02074af4*)(o + 0x14));
        v = *(volatile unsigned int*)0x4000000;
    } else {
        BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)(o + 0x14));
        v = *(volatile unsigned int*)0x4001000;
    }
    *(int*)(o + registerOffset) = (v & 0x1f00) >> 8;
}
