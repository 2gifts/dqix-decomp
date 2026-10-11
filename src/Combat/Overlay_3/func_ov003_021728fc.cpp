#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValueEC_E8 = 0xe8 };
enum { kRegionValue120_12C = 0x12c };
enum { kRegionValueEF_EB = 0xeb };
enum { kRegionValueFA_108 = 0x108 };
enum { kRegionValue3C9_139 = 0x139 };
#else
enum { kRegionValueEC_E8 = 0xec };
enum { kRegionValue120_12C = 0x120 };
enum { kRegionValueEF_EB = 0xef };
enum { kRegionValueFA_108 = 0xfa };
enum { kRegionValue3C9_139 = 0x3c9 };
#endif

int GetGlobalField0x1c020421a0();

extern "C" int func_ov017_0218b5b0(void);
int UpdatePlayClocks020ac4f8(int commit);
struct MainBgControlBackup02074af4;
extern "C" ARM void func_02074af4(struct MainBgControlBackup02074af4* obj);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
int* GetGlobal02109030(void);
void ReleaseHandleAndClearFlags(struct Obj020941b0* p);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);

struct S021728fc {
    char pad_0[kRegionValueEC_E8];
    unsigned char field_ec;
    unsigned char pad_ed;
    unsigned char field_ee;
    char pad_ef[kRegionValue120_12C - kRegionValueEF_EB];
    int field_120;
};

// JPN: func_ov003_021717e8
// USA: func_ov003_021728fc  (semantic: SetupMainBgAndReleaseHandle_021728fc)
extern "C" ARM void func_ov003_021728fc(S021728fc* obj) {
    unsigned int* field4 = (unsigned int*)func_ov017_0218b5b0();
    if (obj->field_ee != 0) return;

    UpdatePlayClocks020ac4f8(0);
#if defined(jpn)
    *(int*)((char*)obj + 0xf0) = *(int*)(GetGlobalField0x1c020421a0() + 0x28);
#endif
    func_02074af4((struct MainBgControlBackup02074af4*)((char*)obj + kRegionValueFA_108));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    unsigned int v = (*dispcnt & 0x1f00) >> 8;
    obj->field_120 = v;
    unsigned int mask = 4;
    *dispcnt = (*dispcnt & ~0x1f00) | 0x1300;

    volatile unsigned short* bg = (volatile unsigned short*)((char*)dispcnt + 8);
    bg[0] = bg[0] & ~3;
    bg[1] = (bg[1] & ~3) | 1;
    bg[2] = (bg[2] & ~3) | 2;
    bg[3] = (bg[3] & ~3) | 3;
    bg[1] = (bg[1] & 0x43) | 0xf00;

    SetBitsInWord(field4, mask);
    SetBitsInField4(field4, 0x8de);

    Set3DClearColor(0, 0, 0x7fff, 0, 0);

    int* g = GetGlobal02109030();
    ReleaseHandleAndClearFlags((struct Obj020941b0*)g);
    ((unsigned char*)g)[kRegionValue3C9_139] = (((unsigned char*)g)[kRegionValue3C9_139] & ~1) | 1;
    ResetAndSetFlag0x3c9Bit0_020939dc(g);

    OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x1000);

    obj->field_ec = 1;
    obj->field_ee = 0;
}
