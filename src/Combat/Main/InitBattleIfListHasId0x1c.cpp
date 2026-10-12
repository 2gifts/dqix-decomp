#include <globaldefs.h>

struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(struct ListHead02046b60* list, int val);
void InitBattleAndControllerState(void* param);
extern "C" int func_ov017_0218b5b0(void);

#if defined(jpn)
#define InitBattleIfListHasId0x1c func_020db45c
extern "C" ARM void func_020db45c(void* param);
enum { kListOffset = 0x4ec, kFirstOffset = 0x8f4, kSecondOffset = 0x4fc };
#else
enum { kListOffset = 0x6fc, kFirstOffset = 0xb14, kSecondOffset = 0x70c };
#endif

// USA: func_020d9a58
ARM void InitBattleIfListHasId0x1c(void* param) {
    int base = func_ov017_0218b5b0();
    struct ListHead02046b60* list = *(struct ListHead02046b60**)(base + 0x3000 + kListOffset);
    if (ListContainsId(list, 0x1c)) {
        func_02046a8c(list, *(int*)(base + 0x3000 + kFirstOffset));
        func_02046a8c(list, *(int*)(base + 0x3000 + kSecondOffset));
    }
    InitBattleAndControllerState(param);
}
