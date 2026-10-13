// KEEP-NAME
// USA: func_ov009_02184d70
// JPN: func_ov009_02186098
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/CharacterCreationUI.h"

int GetFieldByKey020e0434(Container020e0310*, int);

ARM void UpdateCombatantState_02184d70(void* storage) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
    if (!(editor->flags & 0x80) || editor->resourceStep == 2)
        return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char step = editor->resourceStep;
#if !defined(jpn)
    int state = editor->state;
#endif
    if (step == 0) {
#if defined(jpn)
        int state = editor->state;
#endif
        short key = state;
        if ((state == 3) | ((state == 2) | (state == 5)))
            key = editor->sex * 100 + key;
#if defined(jpn)
        const char* filename = (const char*)GetFieldByKey020e0434(&editor->texts, key);
        editor->resourceTask = loader->QueueLoadFile(filename, 0);
#else
        const char* filename = (const char*)GetFieldByKey020e0434(&editor->texts, (short)(key + 50));
        const char* archive = (const char*)GetFieldByKey020e0434(&editor->texts, key);
        editor->resourceTask = loader->QueueLoadFileInGP2(archive, filename, 0);
#endif
        editor->resourceStep = 1;
    } else if (step == 1) {
        if (loader->GetTaskStatus(editor->resourceTask) != 0)
            editor->resourceStep = 2;
    }
}
