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
#include "World/Object3D.h"

extern "C" void* __clear(void* dst, int count);
void* LoadFileIntoMemory(const char* path, void* buf, unsigned int* outLen);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* params, int flag);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
struct Vector3i;

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

struct Vec3Words02193cfc { unsigned int v[3]; };

extern char data_ov015_02194129;
extern struct Vec3Words02193cfc data_ov015_02193cfc;
extern int data_0211e33c;

// USA: func_ov015_0218df0c
extern "C" ARM int func_ov015_0218df0c(void* self, int* desc) {
    if (desc[1] == 0) {
        return 0;
    }

    char buf[0x20];
    __clear(buf, 0x20);

    ((SafeAllocator*)(*(void**)((char*)self + 8)))->Reset();

    int ok = 1;
    struct Foo0207df50* mgr = *(struct Foo0207df50**)*(void**)((char*)self + 4);
    CopyInternalFields0207df50(mgr);
    RestorePairTables0207df90((char*)mgr);

    sprintf(buf, &data_ov015_02194129, desc[1]);

    BackgroundLoader::AddLockGlobal();

    unsigned int length = 0;
    void* buffer = LoadFileIntoMemory(buf, &data_0211e33c, &length);

    if (buffer == 0) {
        ok = 0;
    } else {
        struct Params02036804 params;
        ClearEightWords((struct Struct_203dafc*)&params);
        void* allocPtr = *(void**)((char*)self + 8);
        unsigned int sz = length;
        void* dataPtr = &data_0211e33c;
        int onePtr = ok;
        params.data = dataPtr;
        params.size = sz;
        params.alloc = allocPtr;
        params.one = onePtr;
        _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(*(void**)((char*)self + 0x24), &params, 0);

        struct Vec3Words02193cfc v = data_ov015_02193cfc;
        ((Object3D*)((unsigned char*)*(void**)((char*)self + 0x24)))->SetScale((Vector3i const*)&v);

        ((Object3D*)(*(void**)((char*)self + 0x24)))->MaybeSetBCFGAnimation(0, *(int*)((char*)self + 0x44));
    }

    BackgroundLoader::RemoveLockGlobal();
    BackupPairTables0207dfac((char*)mgr);

    int result;
    if (ok == 0) {
        result = 0;
    } else {
        *(int*)((char*)self + 0xc) = desc[0];
        result = 1;
    }
    return result;
}
