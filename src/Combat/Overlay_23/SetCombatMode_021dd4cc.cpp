#include <globaldefs.h>

#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
extern char data_ov023_021fce18[];
extern char data_ov023_021fce2d[];
enum { ModeFlagsOffset = 0x6f0, CurrentModeOffset = 0x6f9, PendingModeOffset = 0x6fa, ModeTaskOffset = 0x6fc };
#else
extern char data_ov023_021fdb40[];
extern char data_ov023_021fdb52[];
extern char data_ov023_021fdb60[];
extern char data_ov023_021fdb72[];
enum { ModeFlagsOffset = 0x774, CurrentModeOffset = 0x77d, PendingModeOffset = 0x77e, ModeTaskOffset = 0x780 };
#endif

struct ModeLoadRequest {
    char unknown0[ModeFlagsOffset];
    unsigned short flags;
    char unknownAfterFlags[CurrentModeOffset - ModeFlagsOffset - sizeof(unsigned short)];
    signed char currentMode;
    signed char pendingMode;
    char unknownBeforeTask;
    int taskId;
};

// USA: func_ov023_021dd4cc  (semantic: SetCombatMode_021dd4cc)
extern "C" ARM void func_ov023_021dd4cc(ModeLoadRequest* request, int mode) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    signed char currentMode = request->currentMode;
    if (mode == currentMode) {
        if (request->taskId < 0) return;
        loader->RemoveTask(request->taskId);
        request->taskId = -1;
        request->pendingMode = request->currentMode;
        return;
    }
    signed char other = request->pendingMode;
    if (mode == other) return;
    if (request->taskId >= 0) {
        loader->RemoveTask(request->taskId);
        request->taskId = -1;
        request->pendingMode = -1;
    }
    int result;
    if (mode == 2) {
#if defined(jpn)
        result = loader->QueueLoadFile(data_ov023_021fce18, NULL);
#else
        result = loader->QueueLoadFileInGP2(data_ov023_021fdb40, data_ov023_021fdb52, NULL);
#endif
    } else {
#if defined(jpn)
        result = loader->QueueLoadFile(data_ov023_021fce2d, NULL);
#else
        result = loader->QueueLoadFileInGP2(data_ov023_021fdb60, data_ov023_021fdb72, NULL);
#endif
    }
    request->taskId = result;
    request->flags |= 8;
    request->pendingMode = (char)mode;
}
