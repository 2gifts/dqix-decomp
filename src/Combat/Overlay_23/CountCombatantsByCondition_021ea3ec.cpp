#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* buf, int n);
extern unsigned char CopyOutRegion0x5718_02011494(char* obj, void* dst);
extern "C" void func_ov017_021d6134(void*, int);

struct Obj130_021ea3ec { char pad[0x130]; unsigned short* ptr130; };

// USA: func_ov023_021ea3ec  (semantic: CountCombatantsByCondition_021ea3ec)
extern "C" ARM int func_ov023_021ea3ec(void* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char buf[4];
    __clear(buf, 4);
    unsigned char len = CopyOutRegion0x5718_02011494((char*)bs, buf);
    int count = 0;
    for (int i = 1; i < len; i++) {
        unsigned char id = buf[i];
        struct Obj130_021ea3ec* c = (struct Obj130_021ea3ec*)GetCombatantWithFlag0x100_0200ff1c(bs, id);
        if (c) {
            int val = *(unsigned short*)((char*)c->ptr130 + 4);
            if (val <= 0) count++;
        }
    }
    func_ov017_021d6134(obj, count);
    return 1;
}
