#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"
#include "Combat/EntryGetterTypes.h"

extern void* GetGlobalPtr021075f4(void);

struct EntryList_203dce4;
struct Entry_203dce4;
extern struct Entry_203dce4* GetEntryUnlessFlag0x8000(struct EntryList_203dce4* list, int id);

// USA: func_020656e4
ARM int CheckAndClearFlag020656e4(MessageSystem* message, int unusedDelta) {
    if (!message->pendingValueActive) return 0;

    struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000(
        (struct EntryList_203dce4*)GetGlobalPtr021075f4(),
        message->selectedEntry);
    if (entry == NULL) return 0;

    int result = 1;
    SetValueOnActiveChild02040af0(entry,
        message->pendingValue);

    if (GetDisplayValue020409e0(entry) ==
        GetOffset0x54FromFallbackChain(entry)) {
        message->pendingValueActive = 0;
        result = 0;
    }
    return result;
}

