#if defined(jpn)
enum { kStepOffset = 0x1340, kFirstResetOffset = 0x1300, kSecondResetOffset = 0x1308, kCardOffset = 0xd0c, kFinishedOffset = 0x1364 };
#else
enum { kStepOffset = 0x1370, kFirstResetOffset = 0x131c, kSecondResetOffset = 0x1324, kCardOffset = 0xd28, kFinishedOffset = 0x139c };
#endif

#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void* self);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void* handle, int a, int b);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(int* obj);
extern "C" void func_ov023_021e7340(void* arg);
extern "C" void func_ov023_021e6594(void* self);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);

// JPN: func_ov012_02189b40
// USA: func_ov012_02189264  (semantic: ProcessBattleTag02189264)
extern "C" ARM void func_ov012_02189264(char* self) {
    void* handle = func_ov017_0218b5b0(self);
    unsigned char state = *(unsigned char*)(self + kStepOffset);
    if (state == 0) {
        _Z16SetSubBrightnessP13GameResourcesii(handle, ~0xf, 0xf);
        (*(unsigned char*)(self + kStepOffset))++;
        return;
    }
    if (state != 1) return;
    if (_Z31IsSubBrightnessTransitionActiveP13GameResources((int*)handle) != 0) return;

    *(int*)(self + kFirstResetOffset) = 0;
    *(int*)(self + kSecondResetOffset) = 0;
    func_ov023_021e7340(self + kCardOffset);
    func_ov023_021e6594(self);
    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0xf);
    ClearBitsInWord((unsigned int*)handle, 0x10);
    *(int*)(self + kFinishedOffset) = 1;
    *(unsigned char*)(self + kStepOffset) = 0;
}
