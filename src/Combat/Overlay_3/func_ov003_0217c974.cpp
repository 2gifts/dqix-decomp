#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue2CC_27C = 0x27c };
#else
enum { kRegionValue2CC_27C = 0x2cc };
#endif


struct List0202fec8;

extern "C" void* func_ov017_0218b5b0(void);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(unsigned char* dst, int* src);

extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* params, int flag);
extern "C" int _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* data, int mode);

extern char data_ov003_02180c1d;
extern char data_ov003_02180c23;

struct Vec3Words0217fb8c { unsigned int v[3]; };
extern struct Vec3Words0217fb8c data_ov003_0217fb8c;

struct Params02036804 {
    int flag;
    void* data;
    unsigned int size;
    void* alloc;
    int one;
    int pad18;
    int pad1c;
    int pad20;
};

// USA: func_ov003_0217c974
// JPN: func_ov003_0217b69c
extern "C" ARM void func_ov003_0217c974(char* self) {
    int list = (int)BackgroundLoader::GetInstance();
    int out1, out2;
    ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(*(int*)(self + 0x130)), (void**)(&out1), (unsigned int*)(&out2));

    void* mgr = func_ov017_0218b5b0();
    CopyInternalFields0207df50((struct Foo0207df50*)((char*)mgr + kRegionValue2CC_27C));
    RestorePairTables0207df90((char*)mgr + kRegionValue2CC_27C);

    unsigned int fileSize;
    const void* filePtr;
    if (FindFilesInNarcBySubstring((const void*)out1, &data_ov003_02180c1d, &filePtr, &fileSize, 1) == 0) {
        return;
    }

    unsigned int decompSize;
    void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*(SafeAllocator*)(self + 4), filePtr, decompSize);
    if (decompressed == 0) {
        return;
    }

    struct Params02036804 params;
    params.flag = 0;
    params.data = decompressed;
    params.pad18 = 0;
    params.pad1c = 0;
    params.pad20 = 0;
    params.alloc = self + 4;
    params.size = decompSize;
    params.one = 1;
    _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(self + 0x80, &params, 0);

    BackupPairTables0207dfac((char*)mgr + kRegionValue2CC_27C);

    struct Vec3Words0217fb8c v = data_ov003_0217fb8c;
    *(int*)(self + 0xc4) = 0;
    *(int*)(self + 0xc8) = 0xfae;
    *(int*)(self + 0xcc) = 0;
    _ZN8Object3D8SetScaleEPK8Vector3i((unsigned char*)(self + 0x80), (int*)&v);

    _ZN8Object3D24MaybeSetRegularAnimationEPKci(self + 0x80, &data_ov003_02180c23, 0);
}
