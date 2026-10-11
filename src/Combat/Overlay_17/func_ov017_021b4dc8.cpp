#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct StreamHeader;
struct BoundedArray {
    unsigned short items[0xc];
    unsigned short count;
};

extern "C" char* func_02012fe4(void);
extern "C" int _Z17GetField5cb0ValuePc(char* battleStruct);
extern "C" int _Z17GetField5cb4ValuePc(char* battleStruct);
extern "C" int _Z17IsInRange0201b5b0i(int monsterId);
extern "C" void func_0209c008(void* obj, struct StreamHeader* buffer, int length, int idFlag, int mulVal, int addVal);
void ClearHalfword0x18(void* obj);
void AppendHalfwordCapped(BoundedArray* arr, unsigned short value);

extern const char data_ov017_021d7b5d;

struct ScriptSource_021b4dc8 {
    unsigned short monsterId;
#if defined(jpn)
    char pad2[0x40 - 0x2];
#else
    char pad2[0x44 - 0x2];
#endif

    BoundedArray entries;
};

struct ScriptRequest_021b4dc8 {
    char pad0[8];
    struct ScriptSource_021b4dc8* source;
    int taskId;
    unsigned char state;
    char pad11;
    unsigned short extraEntry;
};

// JPN: func_ov017_021b54b8
// USA: func_ov017_021b4dc8
extern "C" ARM void func_ov017_021b4dc8(struct ScriptRequest_021b4dc8* request) {
#if defined(jpn)
 enum {regionalOffset0=0x240c};
#else
 enum {regionalOffset0=0x23ec};
#endif
    ScriptSource_021b4dc8* source;
    GameState* battle = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + regionalOffset0);
    int monsterId = request->source->monsterId;

    if (loader->GetTaskStatus(request->taskId) == 0) {
        return;
    }

    source = request->source;
    ClearHalfword0x18(&source->entries);
    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int size;
        void* data;
        loader->GetLoadedFileByID(request->taskId, &data, &size);
        if (data != 0) {
            int field5cb0 = _Z17GetField5cb0ValuePc((char*)battle);
            int field5cb4 = _Z17GetField5cb4ValuePc((char*)battle);
            int scriptId = monsterId;
            if (_Z17IsInRange0201b5b0i(monsterId)) {
                int rank = grotto->GetFloorMonsterRank(monsterId % 20);
                int environ = grotto->GetActiveGrottoEnviron();
                scriptId = rank + (environ * 100 + 0x9c40);
            }
            func_0209c008(&source->entries, (struct StreamHeader*)data, size, scriptId, field5cb0, field5cb4);
        }
    }

    if (request->extraEntry != 0) {
        AppendHalfwordCapped(&source->entries, request->extraEntry);
    }
    if (_Z17IsInRange0201b5b0i(monsterId)) {
        AppendHalfwordCapped(&source->entries, 0x26);
        AppendHalfwordCapped(&source->entries, 0x27);
        AppendHalfwordCapped(&source->entries, 0x28);
    }

    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&data_ov017_021d7b5d, 0);
    request->state = 4;
}
