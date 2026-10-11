#if defined(jpn)
#define R(j,u) (j)
#define _Z27ConfigureSubsystem_021889f8P11Obj021889f8 func_ov008_0218973c
#define data_ov005_0215cd20 data_ov005_0215e100
#define data_ov014_021894b8 data_ov014_0218a2f8
#define data_ov015_02193cfc data_ov015_0219482c
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_02194129 data_ov015_02194c69
#define func_ov008_02188730 func_ov008_02189444
#define func_ov014_02185c90 func_ov014_02186d00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Container02037364;
extern "C" void _ZN8Object3D26RemoveAnimationPackageByIDEi(struct Container02037364* obj, int key);

extern "C" void _ZN8Object3D20StopCurrentAnimationEv(unsigned char* obj);

extern "C" void* __clear(void* dst, int count);
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char* path, void* buf, unsigned int* outLen);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* params, int flag);
extern "C" int _ZN8Object3D21MaybeSetBCFGAnimationEii(void* obj, int id, int flags);

struct Struct_203dafc;
void ClearEightWords(struct Struct_203dafc* obj);

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

extern char data_ov015_02194078;
extern int data_0211e33c;

// USA: func_ov015_0218cb2c  (semantic: ResetAndReloadStream_0218cb2c)
extern "C" ARM void func_ov015_0218cb2c(void* self, int val) {
    unsigned char* base = (unsigned char*)self;
    _ZN8Object3D26RemoveAnimationPackageByIDEi((struct Container02037364*)*(void**)(base + 0x24), 3);
    if (val != 0) {
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.CreateTypeA(*(void**)(base + 0x14), *(unsigned int*)(base + 0x18));
        allocator.Reset();

        char buf[0x80];
        __clear(buf, 0x80);

        BackgroundLoader::AddLockGlobal();

        unsigned int length = 0;
        sprintf(buf, &data_ov015_02194078, val);
        void* buffer = _Z18LoadFileIntoMemoryPKcPvPj(buf, &data_0211e33c, &length);

        if (buffer != 0) {
            struct Params02036804 params;
            ClearEightWords((struct Struct_203dafc*)&params);
            params.alloc = &allocator;
            params.data = &data_0211e33c;
            params.size = length;
            params.one = 1;
            params.pad20 = 3;
            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(*(void**)(base + 0x24), &params, 0);
        }

        BackgroundLoader::RemoveLockGlobal();
        allocator.Destroy();
    }
    _ZN8Object3D20StopCurrentAnimationEv(*(unsigned char**)(base + 0x24));
    _ZN8Object3D21MaybeSetBCFGAnimationEii(*(void**)(base + 0x24), 0, *(int*)(base + 0x44));
}
