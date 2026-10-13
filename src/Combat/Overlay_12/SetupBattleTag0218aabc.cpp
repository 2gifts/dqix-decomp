// KEEP-NAME
#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { kSelectionOffset = 0x1341, kTextOffset = 0x1344, kTextCapacity = 0x800, kWindowOffset = 0x90 };
#define func_ov012_0218ab34 func_ov012_0218b634
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#else
enum { kSelectionOffset = 0x1371, kTextOffset = 0x1374, kTextCapacity = 0x960, kWindowOffset = 0xac };
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);
#endif

extern "C" void func_ov012_021893b4(void*, int, int, int);
extern "C" void func_ov012_0218ab34(void*, void*, int);

// USA: func_ov012_0218aabc
ARM void SetupBattleTag0218aabc(char* editor) {
    func_ov012_021893b4(editor, *(unsigned char*)(editor + kSelectionOffset), 1, 3);
    memset(*(void**)(editor + kTextOffset), 0, kTextCapacity);
    func_ov012_0218ab34(editor, *(void**)(editor + kTextOffset), 0);
#if defined(jpn)
    func_0205d304(editor + kWindowOffset, *(void**)(editor + kTextOffset), 0, 0, 0, 1, 0);
#else
    func_0205d304(editor + kWindowOffset, *(void**)(editor + kTextOffset), 0, 0, 0, 1, 0, 0);
#endif
}
