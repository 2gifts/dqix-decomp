#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

extern "C" int func_ov017_021d60f4(void* a);
extern "C" int _Z28AbsPlus159IfNegative0215ad2ci(int x);
extern "C" unsigned int _Z37LoadResourceIntoGlobalBuffer_0215a750PKcPPv(const char* path, void** outPtr);
void RegisterCombatantSlot(GameState* battleStruct, int id, GameObject* combatant);
extern "C" void NSBXX_Model_SetPolygonID(NSBXXInternalModel* model, int id);

extern SafeAllocator* data_ov001_021658b8[8];
extern const char data_ov001_02165775[];

// USA: func_ov001_0215ce4c
extern "C" ARM int func_ov001_0215ce4c(char* self, int argCount) {
    char path[0x50];
    ObjectArchiveLoadInfo loadInfo;
    void* fileData;
    unsigned int fileSize;
    int sel;
    GameState* bs;
    BackgroundLoader* loader;
    SafeAllocator* allocator;
    int locked;
    Object3D* obj;
    int id;

    bs = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    id = _Z28AbsPlus159IfNegative0215ad2ci(func_ov017_021d60f4(self));
    sel = 0;
    if (argCount >= 2) {
        sel = func_ov017_021d60f4(self + 8);
    }
    allocator = data_ov001_021658b8[sel];
    sprintf(path, data_ov001_02165775);

    locked = 0;
    loader->GetLoadedFileByName(path, &fileData, &fileSize);
    if (fileData == NULL) {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (_Z37LoadResourceIntoGlobalBuffer_0215a750PKcPPv(path, &fileData) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }

    obj = (Object3D*)allocator->Allocate(0xac);
    obj->Initialize();
    loadInfo.allocator = allocator;
    loadInfo.fileData = fileData;
    loadInfo.unk_8 = fileSize;
    loadInfo.unk_10 = 1;
    obj->LoadFromCHRArchive(&loadInfo);
    if (locked != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    NSBXX_Model_SetPolygonID(obj->pModel_->rawInternalModel_, 0x3d);
    obj->position_.x = 0;
    obj->position_.y = -0xa000;
    obj->position_.z = 0x1000;
    obj->MaybeSetBCFGAnimation(0, 0);
    obj->MakeHidden();
    RegisterCombatantSlot(bs, id, (GameObject*)obj);
    return 1;
}
