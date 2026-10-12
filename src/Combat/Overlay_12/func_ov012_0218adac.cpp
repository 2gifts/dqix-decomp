#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
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

#if !defined(jpn)
extern "C" int func_ov012_0218ae74(unsigned char* self, const char* name);
#endif

#if defined(jpn)
extern "C" void func_02042428(char*, int);
extern "C" int func_0209b000(const char*, void*, void*, void*, char*, unsigned int, unsigned char, void*, void*);
#endif

// USA: func_ov012_0218adac
#if defined(jpn)
extern "C" ARM void func_ov012_0218adac(unsigned char* self, int p1, int p2) {
#else
extern "C" ARM void func_ov012_0218adac(unsigned char* self, int p1, int p2, int flag) {
#endif
    GameState* battle = GameState::GetInstance();
    func_ov023_021e6594((char*)self);

    char buf[0x7c];
    const char* namePtr;

    if (p2 == -1) {
        namePtr = (const char*)((char*)battle + LOW_REGION(0x3c + 0x5400, 0x29c + 0x5400));
    } else {
        memcpy(buf, (char*)battle + LOW_REGION(0x3c + 0x5400, 0x29c + 0x5400), 0x7c);
        int word0 = *(int*)buf;
        word0 = (word0 & ~0x1e00000) | ((unsigned int)(p2 << 28) >> 7);
        *(int*)buf = word0;
        namePtr = buf;
    }

#if defined(jpn)
    char* text = *(char**)(self + 0x1344);
    memset(text, 0, 0x800);
    func_02042428(*(char**)(self + 0x1344), 12);
    text = *(char**)(self + 0x1344);
    unsigned int length = strlen(text);
    func_0209b000(namePtr, *(void**)(self + 0x1408), *(void**)(self + 0x140c), *(void**)(self + 0x1410), text + length, 0x800 - length, 0, self + 0x1498, self + 0x1458);
    memset(*(void**)(self + 0x1414), 0, 0xf2);
    char* resultText = *(char**)(self + 0x1344);
    memcpy(*(void**)(self + 0x1414), resultText, strlen(resultText));
    {
#else
    if (flag == 0) {
        self[0x14bd] = 0;
        self[0x1334] = 0;
    }

    int result = func_ov012_0218ae74(self, namePtr);

    if (result != 0 || flag == 0) {
#endif
        if (p1 != 0) {
            DispatchEntryByIndex_021e7bc4((PMFObj021e7bc4*)(self + LOW_REGION(0xd0c, 0xd28)), 2, 0);
        } else {
            DispatchEntryByIndex_021e7c58((PMFObj021e7c58*)(self + LOW_REGION(0xd0c, 0xd28)), 2, 0);
        }
    }

    func_ov023_021e66ac(self);
}
