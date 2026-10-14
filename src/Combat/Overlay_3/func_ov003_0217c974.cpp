#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

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
struct Vector3i;

extern char data_ov003_02180c1d;
extern char data_ov003_02180c23;

struct Vec3Words0217fb8c { unsigned int v[3]; };
extern struct Vec3Words0217fb8c data_ov003_0217fb8c;

// USA: func_ov003_0217c974
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

    ObjectArchiveLoadInfo params;
    params.unk_0 = 0;
    params.fileData = decompressed;
    params.unk_14 = 0;
    params.unk_18 = 0;
    params.packageID = 0;
    params.allocator = (SafeAllocator*)(self + 4);
    params.unk_8 = decompSize;
    params.unk_10 = 1;
    ((Object3D*)(self + 0x80))->LoadFromCCHROrCMOTArchive(&params, 0);

    BackupPairTables0207dfac((char*)mgr + kRegionValue2CC_27C);

    struct Vec3Words0217fb8c v = data_ov003_0217fb8c;
    *(int*)(self + 0xc4) = 0;
    *(int*)(self + 0xc8) = 0xfae;
    *(int*)(self + 0xcc) = 0;
    ((Object3D*)((unsigned char*)(self + 0x80)))->SetScale((Vector3i const*)&v);

    ((Object3D*)(self + 0x80))->MaybeSetRegularAnimation((char const*)&data_ov003_02180c23, 0);
}
