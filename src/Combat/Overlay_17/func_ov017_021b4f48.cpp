#if defined(jpn)
enum { RegionOffset23ec = 0x240c, RegionOffset60 = 0x5c };
#else
enum { RegionOffset23ec = 0x23ec, RegionOffset60 = 0x60 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct StreamHeader;

extern "C" char* func_02012fe4(void);
int GetField5cb0Value(char* battleStruct);
int GetField5cb4Value(char* battleStruct);
int IsInRange0201b5b0(int monsterId);
void SetupAndRunBufferedScript0209bc98(
    void* dest, struct StreamHeader* data, int size, int param,
    int monsterId, int field5cb0, int field5cb4);

extern const char data_ov017_021d7b71;

struct ScriptSource_021b4f48 {
    unsigned short monsterId;
    char pad2[0x10 - 0x2];
    int param;
};

struct ScriptRequest_021b4f48 {
    char pad0[8];
    struct ScriptSource_021b4f48* source;
    int taskId;
    unsigned char state;
};

// USA: func_ov017_021b4f48
extern "C" ARM void func_ov017_021b4f48(struct ScriptRequest_021b4f48* request) {
    GameState* battle = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + RegionOffset23ec);

    if (loader->GetTaskStatus(request->taskId) == 0) {
        return;
    }
    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int size;
        void* data;
        loader->GetLoadedFileByID(request->taskId, &data, &size);
        if (data != 0) {
            int monsterId = request->source->monsterId;
            int field5cb0 = GetField5cb0Value((char*)battle);
            int field5cb4 = GetField5cb4Value((char*)battle);
            if (IsInRange0201b5b0(monsterId)) {
                int rank = grotto->GetFloorMonsterRank(monsterId % 20);
                int environ = grotto->GetActiveGrottoEnviron();
                monsterId = rank + (environ * 100 + 0x9c40);
            }
            SetupAndRunBufferedScript0209bc98(
                (char*)request->source + RegionOffset60, (struct StreamHeader*)data, size,
                request->source->param, monsterId, field5cb0, field5cb4);
        }
    }
    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&data_ov017_021d7b71, 0);
    request->state = BackgroundLoader::TaskStatus_Fence;
}
