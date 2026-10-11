#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218adac func_ov012_0218bba0
#endif
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void func_ov023_021e6594(char* obj);
extern "C" void func_ov023_021e66ac(void* obj);

class PMFObj021e7bc4;
class PMFObj021e7c58;
void DispatchEntryByIndex_021e7bc4(PMFObj021e7bc4* obj, unsigned int selector, int idx);
void DispatchEntryByIndex_021e7c58(PMFObj021e7c58* obj, unsigned int selector, int idx);

extern "C" int func_ov012_0218ae74(unsigned char* self, const char* name);

// USA: func_ov012_0218adac
extern "C" ARM void func_ov012_0218adac(unsigned char* self, int p1, int p2, int flag) {
    GameState* battle = GameState::GetInstance();
    func_ov023_021e6594((char*)self);

    char buf[0x7c];
    const char* namePtr;

    if (p2 == -1) {
        namePtr = (const char*)((char*)battle + 0x29c + 0x5400);
    } else {
        memcpy(buf, (char*)battle + 0x29c + 0x5400, 0x7c);
        int word0 = *(int*)buf;
        word0 = (word0 & ~0x1e00000) | ((unsigned int)(p2 << 28) >> 7);
        *(int*)buf = word0;
        namePtr = buf;
    }

    if (flag == 0) {
        self[0x14bd] = 0;
        self[0x1334] = 0;
    }

    int result = func_ov012_0218ae74(self, namePtr);

    if (result != 0 || flag == 0) {
        if (p1 != 0) {
            DispatchEntryByIndex_021e7bc4((PMFObj021e7bc4*)(self + 0xd28), 2, 0);
        } else {
            DispatchEntryByIndex_021e7c58((PMFObj021e7c58*)(self + 0xd28), 2, 0);
        }
    }

    func_ov023_021e66ac(self);
}
