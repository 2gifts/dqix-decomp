#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue464_28C = 0x28c };
enum { kRegionValue4A7_2CF = 0x2cf };
#else
enum { kRegionValue464_28C = 0x464 };
enum { kRegionValue4A7_2CF = 0x4a7 };
#endif


int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b34v(int, int, int, int, int);
int AlwaysTrue02094b4c(void);

// USA: func_ov003_02160ec4  (semantic: UpdateFlag1000State_02160ec4)
// JPN: func_ov003_02161020
extern "C" ARM void func_ov003_02160ec4(void* p) {
    char* obj = (char*)p;
    if (!(*(int*)(obj + kRegionValue464_28C) & 0x1000)) return;
    unsigned char state = *(unsigned char*)(obj + kRegionValue4A7_2CF);
    if (state == 0) {
        int g = GetGlobal02109400();
        _Z21BlankFunction02094b34v(g, 0x1f5, 0x66, 0, 0);
        *(unsigned char*)(obj + kRegionValue4A7_2CF) = *(unsigned char*)(obj + kRegionValue4A7_2CF) + 1;
    } else if (state == 1) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c() != 0) {
            *(int*)(obj + kRegionValue464_28C) &= ~0x1000;
            *(unsigned char*)(obj + kRegionValue4A7_2CF) = *(unsigned char*)(obj + kRegionValue4A7_2CF) + 1;
        }
    }
}
