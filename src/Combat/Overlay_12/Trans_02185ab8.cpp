#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185ab8 func_ov012_02186118
#endif



struct ProfileEditor
{
#if defined(jpn)
    char unknown0[0x90];
    char window[0xd0c - 0x90];
    char card[0x608];
    char unknown1314[0x1340 - 0x1314];
#else
    char unknown0[0xac];
    char window[0xd28 - 0xac];
    char card[0x60c];
    char unknown1334[0x1370 - 0x1334];
#endif
    unsigned char step;
    unsigned char state;
};

extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(void* window);
extern "C" void _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8(void* card);
extern "C" unsigned int func_ov023_021e6b8c(ProfileEditor* editor);

// USA: func_ov012_02185ab8
#if defined(jpn)
extern "C" ARM void func_ov012_02185ab8(ProfileEditor* editor)
#else
extern "C" ARM unsigned int func_ov012_02185ab8(ProfileEditor* editor)
#endif
{
    _Z29CallInitEntriesIfSet_021e76a8P17Container021e76a8(editor->card);
    if (editor->state != 0)
        _Z19InitEntries0205d2bcP11Obj0205d2bc(editor->window);
#if !defined(jpn)
    return func_ov023_021e6b8c(editor);
#endif
}
