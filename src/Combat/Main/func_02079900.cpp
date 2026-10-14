#include <globaldefs.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/ActionDataTables.h"
struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(Struct0200fb08*);
void* ResetObjectState02079a3c(void*);
extern "C" void __clear(void*, unsigned int);
#if defined(jpn)
#define data_020f0dcc data_020f0e94
#define data_020f0de1 data_020f0eab
#define data_020f0df2 data_020f0eb9
extern "C" int func_0207a6fc(void*, Obj02079808*);
#endif
extern char data_020f0dcc[], data_020f0de1[], data_020f0df2[];
// USA: func_02079900
// JPN: func_0207a7c8
extern "C" ARM void func_02079900(ActionDataTables* tables, SafeAllocator* alloc) {
    BackgroundLoader::AddLockGlobal();
    GPCReadPair pair;
    unsigned int offset = 0;
    unsigned char* buffer = data_0211e33c;
    int capacity = 0x30000;
    ResetObjectState02079a3c(&pair);
    unsigned int length;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, data_020f0dcc, buffer, length, capacity, false, 0)) {
        offset = length;
        unsigned int decompressed = 0;
        unsigned int payloadCapacity = capacity - offset;
        unsigned char* payload = buffer + offset;
#if !defined(jpn)
        GameState* game = GameState::GetInstance();
        char filename[0x20];
        __clear(filename, 0x20);
        StringReplaceLanguageTag(data_020f0de1, filename, NormalizeField5_0200fb08((Struct0200fb08*)game));
#else
        const char* filename = data_020f0de1;
#endif
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, payload, decompressed, payloadCapacity, filename);
#if defined(jpn)
        ActionRecordRelocator relocate = &func_0207a6fc;
#else
        ActionRecordRelocator relocate = &RelocateOffsets02079808;
#endif
        func_02079a58(&tables->actions, alloc, payload, relocate, NULL
#if !defined(jpn)
                      , NULL
#endif
        );
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, payload, decompressed, payloadCapacity, data_020f0df2);
        func_02079bac(&tables->damage, alloc, payload, NULL, NULL
#if !defined(jpn)
                      , NULL
#endif
        );
    }
    BackgroundLoader::RemoveLockGlobal();
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
