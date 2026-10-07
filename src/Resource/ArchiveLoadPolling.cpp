// External entry names follow the fork's symbols.txt at b399f53.
// Local argument views remain provisional; see contribution interface notes.
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

// Partial loading records inferred from four 12-byte slots. Type names and
// completion flag meanings remain provisional.
struct ArchiveLoadSlot {
    int resourceID;
    int unknown04;
    int taskID;
};
struct ArchiveLoadingState {
    char unknown00[8];
    int activeResourceID;
    char unknown0c;
    unsigned char flags;
    unsigned char resourceKind;
    char unknown0f[5];
    ArchiveLoadSlot slots[4];
};
extern "C" {
void func_020daa58(void*, void*, int, int);
void _Z35ProcessBufferWithPairTables020dab68P12Pair020dab68ii(void*, void*, unsigned int);
void _Z19ResetFields020da2e4Ph(void*);
}

extern "C" ARM int func_020da8e0(void* statePointer)
{
    ArchiveLoadingState* state = (ArchiveLoadingState*)statePointer;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (!loader)
        return 0;
    ArchiveLoadSlot* slot = state->slots;
    int allComplete = 1;
    for (unsigned char index = 0; index < 4; ++index, ++slot) {
        int taskID = slot->taskID;
        if (taskID != -1) {
            if (loader->GetTaskStatus(taskID) == 0) {
                allComplete = 0;
            } else {
                unsigned int length = 0;
                void* data = NULL;
                loader->GetLoadedFileByID(taskID, &data, &length);
                switch (state->resourceKind) {
                case 1:
                    func_020daa58(state, data, 3100, 3110);
                    break;
                case 2:
                    func_020daa58(state, data, 3200, 3210);
                    break;
                case 3:
                    _Z35ProcessBufferWithPairTables020dab68P12Pair020dab68ii(state, data, length);
                    break;
                }
                state->activeResourceID = slot->resourceID;
                state->flags |= 4;
                loader->RemoveTask(taskID);
                _Z19ResetFields020da2e4Ph(slot);
            }
        }
    }
    if (allComplete)
        state->flags &= ~1;
    return 1;
}
