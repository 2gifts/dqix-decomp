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
extern "C"
#endif
ARM int HandleDownloadedQuestFlagsOpcode(
#if defined(jpn)
    Script::Parameter* params, int numParams
#else
    void
#endif
) {
#if defined(jpn)
    if (params->ToInt() != 0) {
        data_ov023_021fff08.quest->flags |= 1;
    } else {
        data_ov023_021fff08.quest->flags &= 1;
    }
#endif
    return 1;
}
