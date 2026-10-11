#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void* func_ov023_021e8f28(int v);
extern "C" void func_ov017_021d6134(void* obj, int v);

// JPN: func_ov023_021e92d4
// USA: func_ov023_021e9370
ARM int SetThreeFieldsFromSub150_021e9370(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x144, regionalOffset1=0x8b8};
#else
 enum {regionalOffset0=0x150, regionalOffset1=0x950};
#endif
    GameState::GetInstance();
    void* p = func_ov023_021e8f28(func_ov017_021d60f4(obj));
    if (p == NULL) {
        return 0;
    }
    char* s = *(char**)((char*)p + regionalOffset0);
    func_ov017_021d6134((char*)obj + 8, *(int*)(s + regionalOffset1));

    s = *(char**)((char*)p + regionalOffset0);
    int idx1 = *(int*)(s + regionalOffset1);
    unsigned short v1 = *(unsigned short*)(s + idx1 * 2 + 0x100 + 0x6c);
    func_ov017_021d6134((char*)obj + 0x10, v1);

    s = *(char**)((char*)p + regionalOffset0);
    int idx2 = *(int*)(s + regionalOffset1);
    int v2 = *(int*)(s + idx2 * 4 + 0x138);
    func_ov017_021d6134((char*)obj + 0x18, v2);

    return 1;
}
