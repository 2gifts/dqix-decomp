#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185a24 func_ov012_02186084
#define _Z37InitBuffersAndConfigureEntry_021e761cPv func_ov023_021e7868
#define func_ov024_021e6a90 func_ov023_021e7000
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

extern "C" void _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(void* window);
extern "C" void _Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228(void* window);
extern "C" void _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(void* window);
extern "C" unsigned int _Z33UpdateEntryFromDoublePtr_021e6b04Pc(ProfileEditor* editor);
extern "C" void _Z37InitBuffersAndConfigureEntry_021e761cPv(void* card);
extern "C" void func_0205da88(void* window, int, int, int);
extern "C" void func_ov023_021e67f4(ProfileEditor* editor);
extern "C" void func_ov023_021e68cc(ProfileEditor* editor);
extern "C" void func_ov023_021e6a14(ProfileEditor* editor);
extern "C" void func_ov024_021e6a90(ProfileEditor* editor);

// USA: func_ov012_02185a24
extern "C" ARM unsigned int func_ov012_02185a24(ProfileEditor* editor)
{
    _Z37InitBuffersAndConfigureEntry_021e761cPv(editor->card);
    _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(editor->window);
    _Z28CallFunc0204c8f0OverList0x9cP12Cont0205d228(editor->window);
    func_0205da88(editor->window, 1, 2, 1);
    func_0205da88(editor->window, 1, 3, 1);
    func_0205da88(editor->window, 2, 3, 0);
    _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(editor->window);
    func_ov023_021e67f4(editor);
    func_ov023_021e68cc(editor);
    func_ov023_021e6a14(editor);
    func_ov024_021e6a90(editor);
    return _Z33UpdateEntryFromDoublePtr_021e6b04Pc(editor);
}
