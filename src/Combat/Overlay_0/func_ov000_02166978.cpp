#include <globaldefs.h>
#if defined(jpn)
enum { stateOffset = 0x5901, workOffset = 0x371c, pointerOffset = 0x5310, modeOffset = 0x57e8 };
#else
enum { stateOffset = 0x5711, workOffset = 0x3760, pointerOffset = 0x5254, modeOffset = 0x55f8 };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "System/Graphics.h"

extern "C" char* func_ov017_0218b5b0(void);
void* GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b40v(void* obj);
extern "C" void _Z21BlankFunction02094b34v(void* obj, int a, int b, int c, int d);
extern "C" int _Z18AlwaysTrue02094b4cv(void* obj);
extern "C" void func_02012de8(void);
extern "C" void func_ov000_021723a8(void* obj, void* src);
extern "C" void func_ov000_02172128(void* obj, void* src);
extern "C" int func_ov000_021729ac(void* obj);
void SetCombatWorkFlags0x55f4(void* work, int mask);

// USA: func_ov000_02166978
extern "C" ARM void func_ov000_02166978(unsigned char* obj) {
    char* res = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    *(signed char*)(obj + stateOffset) = 0;
    for (;;) {
        signed char state = *(signed char*)(obj + stateOffset);
        if (state == 0) {
            void* g = GetGlobal02109400();
            _Z21BlankFunction02094b40v(g);
            _Z21BlankFunction02094b34v(g, 0x65, 500, 0, 0);
            *(signed char*)(obj + stateOffset) = 1;
        } else if (state == 1) {
            if (_Z18AlwaysTrue02094b4cv(GetGlobal02109400()) != 0) {
                *(signed char*)(obj + stateOffset) = -1;
                break;
            }
        }
        loader->RemoveAllLocks();
        func_02012de8();
    }
    func_ov000_021723a8(obj + workOffset, res + 0x128);
    func_ov000_02172128(obj + workOffset, obj + 0x1c);
    *(unsigned char**)(obj + pointerOffset) = obj + 0x30;
    while (func_ov000_021729ac(obj + workOffset) == 0) {
        loader->RemoveAllLocks();
        func_02012de8();
    }
    DISPCNT = (DISPCNT & ~0x1f00) | 0x1100;
    *(int*)(obj + modeOffset) = 1;
    SetCombatWorkFlags0x55f4(obj, 0x20);
}
