#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <std_library_functions.h>

struct ScriptArgument { char data[8]; };
extern "C" const char* func_ov017_021d612c(ScriptArgument*);
extern "C" int func_ov017_021d60f4(ScriptArgument*);
int AbsPlus159IfNegative0215ad2c(int);
extern "C" int func_ov001_0215ad3c(const char*, char*, char*);
unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char*, void**);
void RegisterCombatantSlot(GameState*, int, GameObject*);
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_02165745[];
extern const char data_ov001_0216574d[];
extern const char data_ov001_02165752[];
extern const char data_ov001_02165758[];
extern const char data_ov001_02165762[];

static inline int ReadCombatantSlot(ScriptArgument* argument) {
    return AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(argument));
}

// USA: func_ov001_0215b72c
extern "C" ARM int func_ov001_0215b72c(ScriptArgument* arguments, int count) {
    GameState* game = GameState::GetInstance();
    SafeAllocator* allocator;
    int locked;
    Object3D* object;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    const char* resource = func_ov017_021d612c(arguments);
    int slot = ReadCombatantSlot(arguments + 1);
    int allocatorIndex = 0;
    if (count >= 3) allocatorIndex = func_ov017_021d60f4(arguments + 2);
    allocator = data_ov001_021658b8[allocatorIndex];
    if (slot < 160 || slot > 191) return 0;
    char filename[80];
    char archive[80];
    void* data = 0;
    unsigned int size = 0;
    if (func_ov001_0215ad3c(resource, filename, archive)) {
        loader->GetLoadedFileInArchive(archive, filename, &data, &size);
    } else {
        sprintf(filename, data_ov001_02165745, resource);
        loader->GetLoadedFileByName(filename, &data, &size);
    }
    locked = 0;
    if (!data) {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (!LoadResourceIntoGlobalBuffer_0215a750(filename, &data)) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    object = (Object3D*)allocator->Allocate(sizeof(Object3D));
    if (!object) {
        if (locked) BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    object->Initialize();
    if (strstr(filename, data_ov001_0216574d)) {
        int compressed = 0;
        if (strstr(filename, data_ov001_02165752) || strstr(filename, data_ov001_02165758)) compressed = 1;
        ObjectArchiveLoadInfo info;
        info.allocator = allocator;
        info.fileData = data;
        info.unk_8 = size;
        info.unk_10 = 1;
        if (compressed == 0) object->LoadFromCHRArchive(&info);
        else if (compressed == 1) object->LoadFromCCHROrCMOTArchive(&info, 0);
        object->MaybeSetBCFGAnimation(0, 0);
    } else if (strstr(filename, data_ov001_02165762)) {
        void* model = allocator->Allocate(size);
        memcpy(model, data, size);
        object->SetModelFromFile(allocator, model, size, Model3D::TextureStagingMode_Normal);
    } else {
        if (locked) BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    if (locked) BackgroundLoader::RemoveLockGlobal();
    RegisterCombatantSlot(game, slot, (GameObject*)object);
    object->SetScale(266, 266, 266);
    return 1;
}
