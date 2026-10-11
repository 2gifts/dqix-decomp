#include <globaldefs.h>
#if defined(jpn)
enum { kRegioned = 0xe9 };
enum { kRegionef = 0xeb };
enum { kRegionf0 = 0xec };
enum { kRegion10c = 0x11a };
enum { kRegion10d = 0x11b };
enum { kRegion124 = 0x130 };
#else
enum { kRegioned = 0xed };
enum { kRegionef = 0xef };
enum { kRegionf0 = 0xf0 };
enum { kRegion10c = 0x10c };
enum { kRegion10d = 0x10d };
enum { kRegion124 = 0x124 };
#endif


extern "C" int func_ov017_0218b5b0(void);
void OrGlobalFlag0x40(void);
struct SubBgControlBackup02074b64;
void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);

struct S02173508 {
    char pad_f0[kRegioned];
    unsigned char field_ed;
    unsigned char pad_ee;
    unsigned char field_ef;
    char pad_100[kRegion10c - kRegionf0];
    char field10c[1];
    char pad_10d[kRegion124 - kRegion10d];
    int field_124;
};

// JPN: func_ov003_02172350
// USA: func_ov003_02173508  (semantic: SetupSubBgAndFlags_02173508)
extern "C" ARM void func_ov003_02173508(S02173508* obj) {
    func_ov017_0218b5b0();
    if (obj->field_ef != 0) return;

    OrGlobalFlag0x40();
    BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)((char*)obj + kRegion10c));

    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
    obj->field_124 = (*reg & 0x1f00) >> 8;
    *reg = (*reg & ~0x1f00) | 0x1300;

    volatile unsigned short* bg = (volatile unsigned short*)((char*)reg + 0x8);
    bg[0] = bg[0] & ~3;
    bg[1] = (bg[1] & ~3) | 1;
    bg[2] = (bg[2] & ~3) | 2;
    bg[3] = (bg[3] & ~3) | 3;

    bg[0] = (bg[0] & 0x43) | 0xe00;
    bg[1] = (bg[1] & 0x43) | 0xf00;

    obj->field_ed = 1;
    obj->field_ef = 0;
}
