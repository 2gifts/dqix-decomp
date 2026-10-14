#include <globaldefs.h>

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

struct Obj0205d2bc;
void InitEntries0205d2bc(Obj0205d2bc*);
struct Container021e76a8;
void CallInitEntriesIfSet_021e76a8(Container021e76a8*);
extern "C" unsigned int func_ov023_021e6b8c(ProfileEditor* editor);

// USA: func_ov012_02185ab8
#if defined(jpn)
extern "C" ARM void func_ov012_02185ab8(ProfileEditor* editor)
#else
extern "C" ARM unsigned int func_ov012_02185ab8(ProfileEditor* editor)
#endif
{
    CallInitEntriesIfSet_021e76a8((Container021e76a8*)editor->card);
    if (editor->state != 0)
        InitEntries0205d2bc((Obj0205d2bc*)editor->window);
#if !defined(jpn)
    return func_ov023_021e6b8c(editor);
#endif
}
