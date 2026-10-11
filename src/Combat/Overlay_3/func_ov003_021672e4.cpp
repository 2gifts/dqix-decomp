#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue60_30 = 0x30 };
#else
enum { kRegionValue60_30 = 0x60 };
#endif


extern "C" unsigned short GetSubBGVRAMBanks(void);
extern "C" unsigned short GetSubObjVRAMBanks(void);

struct SubBgControlBackup02074b64;
void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);

struct Obj021672e4 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    char pad1c[kRegionValue60_30 - 0x1c];
    int f60;
    int f64;
    int f68;
    int f6c;
    int f70;
    unsigned char f74;
    unsigned char f75;
    unsigned char f76;
};

// USA: func_ov003_021672e4
// JPN: func_ov003_021671c4
extern "C" ARM void func_ov003_021672e4(struct Obj021672e4* obj, int p1, int p2) {
    obj->f0 = 0;
    obj->f4 = 0;
    obj->f8 = 0;
    obj->fc = 0;
    obj->f10 = 0;
    obj->f14 = GetSubBGVRAMBanks();
    obj->f18 = GetSubObjVRAMBanks();
    *((unsigned char*)obj + 0x2c) = 0;
    *((unsigned char*)obj + 0x2d) = 0;
    BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)((char*)obj + 0x1c));
    obj->f60 = (*(volatile unsigned int*)0x4001000 & 0x1f00) >> 8;
    obj->f64 = -1;
    obj->f68 = obj->f6c = 0;
    obj->f70 = p1;
    obj->f74 = 0;
    obj->f75 = 0;
    obj->f76 = (unsigned char)p2;
}
