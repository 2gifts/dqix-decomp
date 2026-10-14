#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
extern "C" int func_0202c540(void* p);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cfabc  (semantic: EnqueueEventTag161_021cfabc)
extern "C" ARM void func_ov017_021cfabc(void) {
    void* x = func_0202ae18();
    if (CheckField0NonZero_0202b7d8((int*)x) != 0 && func_0202c540(x) == 0) {
        GameState::GetInstance();
        void* p = GetData02100044_0202ae24();
        unsigned char buf[0x14];
        buf[0] = 0xa1;
        func_0205e330(p, buf, 0);
    }
}
