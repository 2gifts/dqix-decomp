#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021d612c(void* obj);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" extern int _Z28AbsPlus159IfNegative0215ad2ci(int x);
extern "C" unsigned int _Z37LoadResourceIntoGlobalBuffer_0215a750PKcPPv(const char* path, void** outPtr);

extern const char data_ov001_02165745[];
extern SafeAllocator* data_ov001_021658b8[8];

// USA: func_ov001_0215bb3c
extern "C" ARM int func_ov001_0215bb3c(char* self, int mode) {
    char path[0x50];
    ObjectArchiveLoadInfo loadInfo;
    void* fileData;
    unsigned int fileSize;
    GameState* gs;
    BackgroundLoader* loader;
    SafeAllocator* allocator;
    int packageID;
    void* name;
    int id;
    int sel;

    gs =GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    name = func_ov017_021d612c(self);
    char* idArg = self + 0x8;
    self += 0x10;
    id = _Z28AbsPlus159IfNegative0215ad2ci(func_ov017_021d60f4(idArg));

    sel = 0;
    if (mode >= 3) {
        sel = func_ov017_021d60f4(self);
        self += 0x8;
    }
    allocator = data_ov001_021658b8[sel];

    packageID = 3;
    if (mode >= 4) {
        packageID = func_ov017_021d60f4(self);
    }

    GameObject* obj = gs->GetGameObjectByIndex(id);
    if (obj == NULL) return 0;

    sprintf(path, data_ov001_02165745, name);
    int locked = 0;
    loader->GetLoadedFileByName(path, &fileData, &fileSize);
    if (fileData == NULL) {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (_Z37LoadResourceIntoGlobalBuffer_0215a750PKcPPv(path, &fileData) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }

    AnimationPackage* package = obj->obj3D_.loadedAnimationPackageList_;
    int type = 0;
    if (package != NULL) {
        type = package->animationType;
    }

    loadInfo.allocator = allocator;
    loadInfo.fileData = fileData;
    loadInfo.unk_8 = fileSize;
    loadInfo.unk_10 = 1;
    loadInfo.packageID = packageID;

    if (type == 0) {
        obj->obj3D_.LoadFromCHRArchive(&loadInfo);
    } else if (type == 1) {
        obj->obj3D_.LoadFromCCHROrCMOTArchive(&loadInfo, NULL);
    }

    if (locked) {
        BackgroundLoader::RemoveLockGlobal();
    }
    obj->obj3D_.MaybeSetBCFGAnimation(0, 0);
    return 1;
}
