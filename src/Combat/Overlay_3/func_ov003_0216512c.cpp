#include <globaldefs.h>
#if defined(jpn)
enum { kRegion36 = 0x2a };
enum { kRegion324 = 0x20c };
enum { kRegion328 = 0x210 };
enum { kRegion464 = 0x28c };
enum { kRegion468 = 0x290 };
enum { kRegion474 = 0x29c };
enum { kRegion476 = 0x29e };
enum { kRegion484 = 0x2ac };
enum { kRegion48c = 0x2b4 };
enum { kRegion4a3 = 0x2cb };
enum { kRegion88 = 0x68 };
#else
enum { kRegion36 = 0x36 };
enum { kRegion324 = 0x324 };
enum { kRegion328 = 0x328 };
enum { kRegion464 = 0x464 };
enum { kRegion468 = 0x468 };
enum { kRegion474 = 0x474 };
enum { kRegion476 = 0x476 };
enum { kRegion484 = 0x484 };
enum { kRegion48c = 0x48c };
enum { kRegion4a3 = 0x4a3 };
enum { kRegion88 = 0x88 };
#endif
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

struct Cont0207fe44 {
    char pad0[kRegion36];
    short field36;
};

struct Battle0216512c {
    char pad0[kRegion324];
    struct Cont0207fe44* model;
    char pad328[kRegion464 - kRegion328];
    unsigned int flags;
    char pad468[kRegion474 - kRegion468];
    short field474;
    char pad476[kRegion484 - kRegion476];
    short field484;
    short field486;
    short field488;
    short field48a;
    char pad48c[kRegion4a3 - kRegion48c];
    unsigned char code;
    unsigned char step;
};

unsigned char* GetGlobal02109030(void);
extern "C" void func_ov003_021612c0(struct Battle0216512c* obj);
extern "C" int func_ov003_02161344(struct Battle0216512c* obj);
void CallFunc0204c804OverAllElems(struct Cont0207fe44* obj);
void EnqueueEventTag50_021cea8c(void);
extern "C" void VectorizedMemset(void* dst, int val, int size);
void ClearFlag0x3c9Bit0AndCleanup(unsigned char* obj);
void SetOrClearFlag40_02166f80(void* self, int key, int set);

// JPN: func_ov003_02165114
// USA: func_ov003_0216512c
extern "C" ARM void func_ov003_0216512c(struct Battle0216512c* obj) {
    unsigned char* global = GetGlobal02109030();
    if (obj->step == 0) {
        func_ov003_021612c0(obj);
        obj->step++;
    } else if (obj->step == 1) {
        int result = func_ov003_02161344(obj);
        if (result != -1) {
            if (result != 1) {
                return;
            }
            CallFunc0204c804OverAllElems(obj->model);
            obj->field484 = 0x13;
            obj->step++;
            obj->flags |= 0xc000000;
            EnqueueEventTag50_021cea8c();
            return;
        }
        obj->field488 = 0x1b;
        obj->field474 = obj->field48a = 0xaa;
        obj->model->field36 = obj->field48a;
        obj->field484 = 0x12;
        obj->field486 = 1;
        obj->step = 3;
    } else if (obj->step == 2) {
        GrottoStruct* grotto = GameState::GetInstance()->GetGrottoStruct();
        VectorizedMemset(grotto, 0, kRegion88);
        grotto->unknown_0[0] = 0;
        grotto->unknown_0[1] = 0;
        obj->flags |= 0x82;
        obj->code = 6;
        obj->step = 0;
        ClearFlag0x3c9Bit0AndCleanup(global);
    } else if (obj->step == 3) {
        SetOrClearFlag40_02166f80(obj, obj->field488, 0);
        obj->code = 10;
        obj->step = 1;
    }
}
