#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue98_B0 = 0xb0 };
enum { kRegionValue3B8_3D0 = 0x3d0 };
enum { kRegionValue3F0_408 = 0x408 };
enum { kRegionValue3BD_3D5 = 0x3d5 };
enum { kRegionValue998_868 = 0x868 };
#else
enum { kRegionValue98_B0 = 0x98 };
enum { kRegionValue3B8_3D0 = 0x3b8 };
enum { kRegionValue3F0_408 = 0x3f0 };
enum { kRegionValue3BD_3D5 = 0x3bd };
enum { kRegionValue998_868 = 0x998 };
#endif


struct Container020e0310;
struct Entry_0205d6a0;

extern "C" char* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z24ReinitController02043204Pc(char* ctrl);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* list, int flag);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
extern "C" void func_ov003_0215cab0(void* self, int msg);

struct BattleMenu_0215da0c {
    char unk_0[0x64];
    char messages[kRegionValue98_B0 - 0x64];
    char entries[kRegionValue3B8_3D0 - kRegionValue98_B0];
    unsigned char step;
    char unk_3b9[3];
    unsigned char mode;
    char unk_3bd[kRegionValue3F0_408 - kRegionValue3BD_3D5];
    unsigned char showResult;
    unsigned char resultFlag;
    unsigned char unk_3f2;
    unsigned char skipMessage;
};

// USA: func_ov003_0215da0c
// JPN: func_ov003_0215ed68
extern "C" ARM void func_ov003_0215da0c(struct BattleMenu_0215da0c* self) {
    char* global;
    GameState* gs;
    void* ctx;
    unsigned char step;
    int zero;
    int nonZero;

    gs = GameState::GetInstance();
    global = _Z26GetGlobalField0x1c020421a0v();
    ctx = func_0202ae18();

    zero = 0;
    if (func_0202c508(ctx) && gs->GetUnknownGameObject()->obj3D_.unknown_4_ == 0) {
        zero = 1;
    }
    nonZero = 0;
    if (func_0202c508(ctx) && gs->GetUnknownGameObject()->obj3D_.unknown_4_ != 0) {
        nonZero = 1;
    }

    step = self->step;
    if (step == 0) {
        if (self->skipMessage) {
            _Z24ReinitController02043204Pc(global);
            self->step++;
            return;
        }
        int key = 0x442;
        if (self->showResult) {
            if (zero) {
                self->resultFlag = 1;
                key = 0x6e;
            } else if (nonZero) {
                key = 0x74;
            } else {
                key = 0x73;
            }
        }
        func_ov003_0215cab0(self, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self->messages, key));
        self->step++;
    }
    if (step == 1 && *(int*)(global + kRegionValue998_868) == 0) {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)self->entries, 1);
        self->mode = 5;
        self->step = 0;
    }
}
