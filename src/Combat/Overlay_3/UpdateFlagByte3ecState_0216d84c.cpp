#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue3EC_27C = 0x27c };
#else
enum { kRegionValue3EC_27C = 0x3ec };
#endif


int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b34v(int, int, int, int, int);
int AlwaysTrue02094b4c(void);

// USA: func_ov003_0216d84c  (semantic: UpdateFlagByte3ecState_0216d84c)
// JPN: func_ov003_0216d328
extern "C" ARM void func_ov003_0216d84c(void* p) {
    char* obj = (char*)p;
    if (!(*(unsigned char*)(obj + 0x1000 + kRegionValue3EC_27C) & 1)) return;
    short state = *(short*)(obj + 8);
    if (state == 0) {
        int g = GetGlobal02109400();
        _Z21BlankFunction02094b34v(g, 0x1f5, 0x66, 0, 0);
        *(short*)(obj + 8) = 1;
    } else if (state == 1) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c() != 0) {
            *(unsigned char*)(obj + 0x1000 + kRegionValue3EC_27C) &= ~1;
            *(short*)(obj + 8) = -1;
        }
    }
}
