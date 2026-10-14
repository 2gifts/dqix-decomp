#include <globaldefs.h>

#if defined(jpn)
#include "Resource/Script.h"

struct DownloadedQuestView {
    char unknown00[0x50];
    unsigned int flags;
};

struct DownloadScriptState {
    unsigned char count;
    unsigned char checked;
    unsigned char choosing;
    unsigned char index;
    void* items;
    DownloadedQuestView* quest;
};

extern DownloadScriptState data_ov023_021fff08;
#endif

#if defined(jpn)
extern "C" ARM int HandleDownloadedQuestFlagsOpcode(Script::Parameter* params, int numParams) {
    if (params->ToInt() != 0) {
        data_ov023_021fff08.quest->flags |= 1;
    } else {
        data_ov023_021fff08.quest->flags &= 1;
    }
    return 1;
}
#else
ARM int HandleDownloadedQuestFlagsOpcode_ov023_021f5b94() {
    return 1;
}
#endif
