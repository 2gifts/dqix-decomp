#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021d0d58 {
    unsigned char tag;
    unsigned char pad0[3];
    int val;
    unsigned char pad2[12];
};

// USA: func_ov017_021d0d58
ARM void EnqueueEventTag23Field_021d0d58(void) {
    LocalEvt021d0d58 buf;
    void* p = GetData02100044_0202ae24();
    char* battle = (char*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    buf.tag = 0x17;
    buf.val = *(int*)(battle + 0x2000 + 0xc94);
    func_0205e330(p, &buf, 0);
}
