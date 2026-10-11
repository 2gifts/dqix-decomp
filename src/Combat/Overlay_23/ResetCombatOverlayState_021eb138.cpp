#include <globaldefs.h>

extern "C" void func_02074af4(void*);

struct SubBgControlBackup02074b64;
void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);

struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);

struct List0204af64;
void ResetList0204af64(struct List0204af64* obj);

extern "C" void func_0204c684(void*);

struct InitTarget0205cfd4;
void InitStruct0205cfd4(struct InitTarget0205cfd4* s);

// USA: func_ov023_021eb138  (semantic: ResetCombatOverlayState_021eb138)
extern "C" ARM void func_ov023_021eb138(void* obj, unsigned char flag) {
    *(unsigned char*)((char*)obj + 0x430) = flag;
    *(unsigned char*)((char*)obj + 0x3a) = 0;
    *(unsigned char*)((char*)obj + 0x3b) = 0;
    func_02074af4((char*)obj + 0x2a);
    BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)((char*)obj + 0x2a));

    unsigned int* reg0 = (unsigned int*)0x4000000;
    *(int*)((char*)obj + 0x3c) = (*reg0 & 0x1f00) >> 8;
    unsigned int* reg1 = (unsigned int*)0x4001000;
    struct Struct020dfc40* sub4 = (struct Struct020dfc40*)((char*)obj + 4);
    *(int*)((char*)obj + 0x40) = (*reg1 & 0x1f00) >> 8;
    *(int*)obj = 0;
    ResetStruct020dfc40(sub4);

    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)((char*)obj + 0x44 + i * 0x20));
    }
    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)((char*)obj + 0x84 + i * 0x20));
    }
    for (int i = 0; i < 3; i++) {
        func_0204c684((char*)obj + 0x180 + i * 0xe0);
    }

    InitStruct0205cfd4((struct InitTarget0205cfd4*)((char*)obj + 0xc4));

    *(int*)((char*)obj + 0x420) = 0;
    *(int*)((char*)obj + 0x424) = 0;
    *(int*)((char*)obj + 0x428) = 0;
    *(int*)((char*)obj + 0x42c) = 0;
    *(int*)((char*)obj + 0x20) = 0;
    *(int*)((char*)obj + 0x24) = 0;
    *(unsigned char*)((char*)obj + 0x28) = 0;
    *(unsigned char*)((char*)obj + 0x431) = 0;
    *(unsigned char*)((char*)obj + 0x432) = 0;
    *(unsigned char*)((char*)obj + 0x433) = 0;
    *(int*)((char*)obj + 0x434) = -1;
    *(unsigned short*)((char*)obj + 0x438) = 0;
    *(unsigned short*)((char*)obj + 0x43a) = 0;
    *(unsigned char*)((char*)obj + 0x43c) = 0;
    *(unsigned char*)((char*)obj + 0x43d) = 0;
    *(unsigned short*)((char*)obj + 0x43e) = 0;
    *(unsigned short*)((char*)obj + 0x440) = 0;
    *(unsigned short*)((char*)obj + 0x442) = 0;
    *(unsigned short*)((char*)obj + 0x444) = 0;
    *(unsigned short*)((char*)obj + 0x446) = 0;
    *(unsigned short*)((char*)obj + 0x448) = 0;
    *(unsigned char*)((char*)obj + 0x44a) = 0;
}
