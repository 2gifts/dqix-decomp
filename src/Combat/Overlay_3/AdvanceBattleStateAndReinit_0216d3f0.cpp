#include <globaldefs.h>
#if defined(jpn)
enum { kRegion998 = 0x868 };
enum { kRegion9a0 = 0x870 };
#else
enum { kRegion998 = 0x998 };
enum { kRegion9a0 = 0x9a0 };
#endif

#if defined(jpn)
extern "C" void func_ov003_0216d8d4(char*, int);
#endif

int GetGlobalField0x1c020421a0();
#if !defined(jpn)
extern "C" void func_ov003_0216d8d4(char* obj, int keyA, int p3, int p4, int p5);
#endif
void ReinitController02043204(char* obj);

// JPN: func_ov003_0216ced0
// USA: func_ov003_0216d3f0  (semantic: AdvanceBattleStateAndReinit_0216d3f0)
extern "C" ARM void func_ov003_0216d3f0(char* obj) {
    char* g = (char*)GetGlobalField0x1c020421a0();
    short state = *(short*)(obj + 6);
    if (state == 0) {
#if defined(jpn)
        func_ov003_0216d8d4(obj, 0x1c);
#else
        func_ov003_0216d8d4(obj, 0x1c, -1, -1, -1);
#endif
        *(int*)(g + kRegion998) = 1;
        *(short*)(obj + 6) = 1;
        return;
    }
    switch (state) {
    case 1:
        if (*(int*)(g + kRegion9a0) != 0) break;
        if (*(int*)(g + kRegion998) != 0) break;
        ReinitController02043204(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
        break;
    }
}
