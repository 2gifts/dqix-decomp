#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov011_021842a0(void* obj);
extern "C" void func_02074af4(void* obj);
extern "C" void* func_ov017_0218b5b0(void);

struct Obj021f672c;
extern void InitObj_021f672c(struct Obj021f672c* obj);

extern void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);

struct SubBgControlBackup02074b64;
extern void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);

struct Struct_218438c {
    char pad0[0x9c];
    int f9c;
    int fa0;
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
    char blkB8[0x54];
    int f10c;
    int f110;
    int f114;
    char blk118[0x72];
    char pad18a[2];
    int f18c;
    int f190;
    char blk194[0x10];
    unsigned char f1a4;
    unsigned char f1a5;
    char pad1a6[2];
    int f1a8;
    int f1ac;
    short f1b0;
    short f1b2;
    int f1b4;
    int f1b8;
    short f1bc;
    short f1be;
    short f1c0;
    short f1c2;
    short f1c4;
    short f1c6;
    int f1c8;
    unsigned char f1cc;
    unsigned char f1cd;
    char pad1ce[2];
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
};

// USA: func_ov011_0218438c  (semantic: InitCombatState_0218438c)
extern "C" ARM void func_ov011_0218438c(struct Struct_218438c* obj) {
    func_ov011_021842a0(obj);
    obj->fa8 = 0;
    obj->fac = 0;
    obj->f9c = 0;
    obj->fa0 = 0;
    obj->fa4 = -1;
    obj->fb0 = 0;
    obj->fb4 = 0;
    memset(obj->blkB8, 0, 0x54);
    obj->f110 = -1;
    obj->f10c = 0;
    obj->f114 = 0;
    InitObj_021f672c((struct Obj021f672c*)((char*)obj + 0x118));
    obj->f18c = -1;
    SetBitsInField4_0203b4d8((unsigned int*)func_ov017_0218b5b0(), 0xc0);
    obj->f190 = (*(unsigned short*)0x4000304 & 0x8000) >> 15;
    obj->f1a4 = 0;
    obj->f1a5 = 0;
    func_02074af4((char*)obj + 0x194);
    BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)((char*)obj + 0x194));
    obj->f1a8 = (*(unsigned int*)0x4000000 & 0x1f00) >> 8;
    obj->f1ac = (*(unsigned int*)0x4001000 & 0x1f00) >> 8;
    obj->f1b0 = 0;
    obj->f1b2 = 0;
    obj->f1b4 = 0;
    obj->f1b8 = 0;
    obj->f1bc = 0;
    obj->f1be = 0;
    obj->f1c0 = 0;
    obj->f1c2 = 0;
    obj->f1c4 = 0;
    obj->f1c6 = 0;
    obj->f1c8 = 0;
    obj->f1d0 = 0;
    obj->f1d4 = 0;
    obj->f1d8 = 0;
    obj->f1dc = 0;
    obj->f1cc = 0;
    obj->f1cd = 0;
}
