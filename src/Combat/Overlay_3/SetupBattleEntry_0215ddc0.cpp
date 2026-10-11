#include <globaldefs.h>
#if defined(jpn)
enum { kRegion98 = 0xb0 };
enum { kRegion38 = 0x50 };
enum { kRegion3a = 0x52 };
enum { kRegion3c = 0x54 };
enum { kRegion3e = 0x56 };
enum { kRegion40 = 0x58 };
enum { kRegion42 = 0x5a };
enum { kRegion44 = 0x5c };
enum { kRegion46 = 0x5e };
enum { kRegion14f = 0x167 };
enum { kRegion149 = 0x161 };
enum { kRegion14d = 0x165 };
enum { kRegion7c = 0x94 };
enum { kRegion960 = 0x800 };
#else
enum { kRegion98 = 0x98 };
enum { kRegion38 = 0x38 };
enum { kRegion3a = 0x3a };
enum { kRegion3c = 0x3c };
enum { kRegion3e = 0x3e };
enum { kRegion40 = 0x40 };
enum { kRegion42 = 0x42 };
enum { kRegion44 = 0x44 };
enum { kRegion46 = 0x46 };
enum { kRegion14f = 0x14f };
enum { kRegion149 = 0x149 };
enum { kRegion14d = 0x14d };
enum { kRegion7c = 0x7c };
enum { kRegion960 = 0x960 };
#endif

#if defined(jpn)
enum { kRows = 4 };
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#else
enum { kRows = 2 };
#endif
#include "std_library_functions.h"

struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
void SetupFieldAndFormat_0215de6c(char* base, void* buf);
#if !defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

// JPN: func_ov003_0215f108
// USA: func_ov003_0215ddc0  (semantic: SetupBattleEntry_0215ddc0)
extern "C" ARM void func_ov003_0215ddc0(char* base) {
    FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + kRegion98), 0, 2);

    *(unsigned short*)(base + 0x100 + kRegion38) = 0xb;
    *(unsigned short*)(base + 0x100 + kRegion3a) = 2;
    *(unsigned short*)(base + 0x100 + kRegion3c) = 0x14;
    *(unsigned short*)(base + 0x100 + kRegion3e) = 0;
    *(unsigned short*)(base + 0x100 + kRegion40) = 0x10;
    *(unsigned short*)(base + 0x100 + kRegion42) = kRows;
    *(unsigned short*)(base + 0x100 + kRegion44) = 8;
    *(unsigned short*)(base + 0x100 + kRegion46) = 8;

    *(unsigned char*)(base + kRegion14f) = 8;
    *(unsigned char*)(base + kRegion149) = 0;
    *(unsigned char*)(base + kRegion14d) = 1;

    memset(*(void**)(base + kRegion7c), 0, kRegion960);
    SetupFieldAndFormat_0215de6c(base, *(void**)(base + kRegion7c));

#if defined(jpn)
    func_0205d304(base + kRegion98, *(void**)(base + kRegion7c), 0, 0, 0, 1, 0);
#else
    func_0205d304(base + kRegion98, *(void**)(base + kRegion7c), 0, 0, 0, 1, 0, 0);
#endif
}
