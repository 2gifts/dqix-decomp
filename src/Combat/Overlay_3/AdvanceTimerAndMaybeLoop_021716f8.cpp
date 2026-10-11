#include <globaldefs.h>
#if defined(jpn)
enum { kRegion724 = 0x620 };
enum { kRegion728 = 0x624 };
enum { kRegion72c = 0x628 };
#else
enum { kRegion724 = 0x724 };
enum { kRegion728 = 0x728 };
enum { kRegion72c = 0x72c };
#endif

#if defined(jpn)
extern "C" void func_ov003_021714f0(void*);
#endif
#include "GameState/GameState.h"

struct Obj_02172518;
void LoopCallOv017_02172518(struct Obj_02172518* obj, int flag);
extern "C" void func_0202ae18(void);
extern "C" void func_0202b0f4(void);

struct Obj021716f8 {
    char pad0[0x34c];
    int field34c;
    char pad350[kRegion724 - 0x350];
    int field724;
    char pad728[4];
    unsigned int field72c;
};

// JPN: func_ov003_02170a58
// USA: func_ov003_021716f8  (semantic: AdvanceTimerAndMaybeLoop_021716f8)
extern "C" ARM void func_ov003_021716f8(struct Obj021716f8* obj) {
    unsigned char* b = (unsigned char*)obj;

    if (obj->field724 != 0) {
#if defined(jpn)
        func_ov003_021714f0(obj);
#else
        int flag = ((unsigned int)obj->field34c >> 31) ? 1 : 0;
        LoopCallOv017_02172518((struct Obj_02172518*)obj, flag);
#endif
        b[0] = 3;
    }

    obj->field72c += GameState::GetInstance()->GetEffectiveDeltaTime();
    if (obj->field72c <= 0xbb8) return;

    func_0202ae18();
    func_0202b0f4();
    b[0] = 4;
}
