// KEEP-NAME
#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { kSelectionOffset = 0x1341, kTextOffset = 0x1344, kTextCapacity = 0x800, kWindowOffset = 0x90, kListCountsOffset = 0x141c };
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#else
enum { kSelectionOffset = 0x1371, kTextOffset = 0x1374, kTextCapacity = 0x960, kWindowOffset = 0xac, kListCountsOffset = 0x13c4 };
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);
#endif

extern "C" void func_ov012_021893b4(void*, int, int, int);
extern "C" void func_ov012_02189dfc(void*, void*, int);

struct ProfileListCounts {
    unsigned short available : 5;
    unsigned short other : 11;
};

// USA: func_ov012_02189d68
// JPN: func_ov012_0218a804
ARM void SetupBattleTag02189d68(char* editor) {
    func_ov012_021893b4(editor, *(unsigned char*)(editor + kSelectionOffset), 16, 1);
    memset(*(void**)(editor + kTextOffset), 0, kTextCapacity);
    func_ov012_02189dfc(editor, *(void**)(editor + kTextOffset), 0);
    int displayMode = 0;
    if (((ProfileListCounts*)(editor + kListCountsOffset))->available > 9)
        displayMode = 1;
#if defined(jpn)
    func_0205d304(editor + kWindowOffset, *(void**)(editor + kTextOffset), 0, 0, displayMode, 1, 0);
#else
    func_0205d304(editor + kWindowOffset, *(void**)(editor + kTextOffset), 0, 0, displayMode, 1, 0, 0);
#endif
}
