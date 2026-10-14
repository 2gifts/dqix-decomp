#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "System/Matrix.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/NitroVM.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"

extern "C" void* __clear(void* dst, int count);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);

struct Struct_203dafc;
void ClearEightWords_0203dafc(struct Struct_203dafc* obj);

struct Obj02055718;
int InitAllocatedObject02055718(struct Obj02055718* p, int a, int b);

extern "C" void func_02054f80(void* obj);
extern "C" int func_02055180(void* a, void* b, void* c, void* d);

struct ModelHolder {
    unsigned int pad_0[3];
    void* obj;
};

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

extern char data_ov015_0219413f[];
extern char data_ov015_02194152[];
extern char data_ov015_02194156[];
extern Vector3i data_ov015_02193d08;

// USA: func_ov015_0218e02c
extern "C" ARM int func_ov015_0218e02c(void* self, int* desc) {
    if (desc[1] == 0) {
        return 0;
    }

    NarcHandle narc;
    NitroVM vm;
    char tmp[0x50];
    char path[0x20];

    __clear(path, 0x20);

    (*(SafeAllocator**)((char*)self + 8))->Reset();

    int ok = 1;
    struct Foo0207df50* palette = *(struct Foo0207df50**)*(void**)((char*)self + 4);
    CopyInternalFields0207df50(palette);
    RestorePairTables0207df90((char*)palette);

    sprintf(path, data_ov015_0219413f, desc[1]);

    BackgroundLoader::AddLockGlobal();

    unsigned int length = 0;
    if (LoadFileIntoMemory(path, data_0211e33c, &length) != 0) {
        if (narc.Initialize(data_ov015_02194152, data_0211e33c)) {
            NitroVM_Initialize(&vm);
            for (unsigned int index = 0; PrepareReadFileInNARCByID(&vm, &narc, index); ++index) {
                __clear(tmp, 0x50);
                NitroVM_WriteOutFilePath(&vm, tmp, 0x50);
                if (strstr(tmp, data_ov015_02194156) != 0) {
                    const void* file = narc.GetFileByIndex(index);
                    unsigned int size = vm.fileInfo.endOffset - vm.fileInfo.startOffset;
                    unsigned int len = length;
                    if (len & 3) {
                        len += 4 - (len & 3);
                    }
                    void* buf = (*(SafeAllocator**)((char*)self + 8))->Allocate(len);
                    if (buf == 0) {
                        NitroVM_FinishRead(&vm);
                        narc.Destroy();
                        ok = 0;
                    } else {
                        memcpy(buf, file, len);
                        (*(struct ModelHolder**)((char*)self + 0x28))->obj =
                            (*(SafeAllocator**)((char*)self + 8))->Allocate(0x128);
                        func_02054f80((*(struct ModelHolder**)((char*)self + 0x28))->obj);
                        if (func_02055180((*(struct ModelHolder**)((char*)self + 0x28))->obj,
                                          (*(SafeAllocator**)((char*)self + 8)),
                                          buf, (void*)size) == 0) {
                            ok = 0;
                        }
                    }
                    NitroVM_FinishRead(&vm);
                    break;
                }
                NitroVM_FinishRead(&vm);
            }
        }
        narc.Destroy();

        Params02036804 info;
        ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
        void* allocPtr = *(void**)((char*)self + 8);
        void* dataPtr = &data_0211e33c;
        unsigned int sz = length;
        int onePtr = 1;
        info.alloc = allocPtr;
        info.data = dataPtr;
        info.size = sz;
        info.one = onePtr;
        (*(Object3D**)((char*)self + 0x24))->LoadFromCHRArchive((ObjectArchiveLoadInfo*)&info);

        InitAllocatedObject02055718(*(struct Obj02055718**)((char*)self + 0x28),
                                    *(int*)((char*)self + 0x24), *(int*)((char*)self + 8));

        Vector3i v = data_ov015_02193d08;
        (*(Object3D**)((char*)self + 0x24))->SetScale(&v);
        (*(Object3D**)((char*)self + 0x24))->MaybeSetBCFGAnimation(0, *(int*)((char*)self + 0x44));
    } else {
        ok = 0;
    }

    BackgroundLoader::RemoveLockGlobal();
    BackupPairTables0207dfac((char*)palette);

    if (ok == 0) {
        return 0;
    }
    *(int*)((char*)self + 0xc) = desc[0];
    return 1;
}
