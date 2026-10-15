#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/GPC.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>

struct ScriptArgument { char data[8]; };
extern "C" const char* func_ov017_021d612c(ScriptArgument*);
extern "C" int func_ov017_021d60f4(ScriptArgument*);
extern "C" int _Z28AbsPlus159IfNegative0215ad2ci(int);
extern "C" void _Z30RegisterCombatantSlot_0200fd38P9GameStateiP10GameObject(GameState*, int, GameObject*);
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_0216572d[];
extern const char data_ov001_0216576f[];

// USA: func_ov001_0215ca4c
extern "C" ARM int func_ov001_0215ca4c(ScriptArgument* arguments, int count) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    const char* resource = func_ov017_021d612c(arguments++);
    int slot = _Z28AbsPlus159IfNegative0215ad2ci(func_ov017_021d60f4(arguments++));
    int id = slot;
    int allocatorIndex = 0;
    if (count >= 3) allocatorIndex = func_ov017_021d60f4(arguments);
    SafeAllocator* allocator = data_ov001_021658b8[allocatorIndex];
    if (slot >= 0xa0 && slot < 0xbf) id = slot;
    char filename[32];
    const char* slash = strrchr(resource, '/');
    strcpy(filename, slash ? slash + 1 : resource);
    void* archiveData;
    unsigned int cachedSize;
    int locked = 0;
    loader->GetLoadedFileInArchive(data_ov001_0216572d, filename, &archiveData, &cachedSize);
    if (!archiveData) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        locked = 1;
        GPCReadPair pair;
        GPCReadPair* reader = &pair;
        ZeroInitGPCPointer(&reader->pGPCFile);
        reader->ZeroInitializeMachine();
        unsigned int headerSize;
        int result;
        if (!LoadAndDecompressGPCHeaderAndInnerFileInfo(&reader->pGPCFile, pair.machine,
                data_ov001_0216572d, data_0211e33c, headerSize, 0x30000, false, 0)) {
            BackgroundLoader::RemoveLockGlobal();
            result = 0;
            reader->Reset();
            ZeroDestroyGPCPointer(&reader->pGPCFile);
            return result;
        }
        void* destination = data_0211e33c + headerSize;
        unsigned int fileSize;
        if (!DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, destination,
                fileSize, 0x30000 - headerSize, resource)) {
            pair.Reset();
            BackgroundLoader::RemoveLockGlobal();
            result = 0;
            pair.Reset();
            ZeroDestroyGPCPointer(&pair.pGPCFile);
            return result;
        }
        archiveData = destination;
        pair.Reset();
        pair.Reset();
        ZeroDestroyGPCPointer(&pair.pGPCFile);
    }
    unsigned int compressedSize;
    const void* compressedData;
    if (!FindFilesInNarcBySubstring(archiveData, data_ov001_0216576f, &compressedData, &compressedSize, 1)) {
        if (locked) BackgroundLoader::RemoveLockGlobal();
        return 0;
    }
    unsigned int decompressedSize;
    void* model = DecompressLZ77FileIntoAllocatedSpace(*allocator, compressedData, decompressedSize);
    Object3D* object = (Object3D*)allocator->Allocate(sizeof(Object3D));
    object->Initialize();
    ObjectArchiveLoadInfo info;
    info.unk_8 = decompressedSize;
    info.allocator = allocator;
    info.fileData = model;
    info.unk_0 = 0;
    info.unk_14 = 0;
    info.unk_18 = 0;
    info.packageID = 0;
    info.unk_10 = 0;
    object->LoadFromCCHROrCMOTArchive(&info, 0);
    if (locked) BackgroundLoader::RemoveLockGlobal();
    _Z30RegisterCombatantSlot_0200fd38P9GameStateiP10GameObject(game, id, (GameObject*)object);
    object->SetScale(266, 266, 266);
    object->MaybeSetBCFGAnimation(0, 0);
    return 1;
}
