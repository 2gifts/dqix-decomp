#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov012_0218930c func_ov012_02189be8
enum {
    kProfileOffset = 0x543c,
    kStepOffset = 0x1340,
    kStateOffset = 0x1341,
    kActiveOffset = 0x1368,
    kDesignOffset = 0x144c,
    kWindowOffset = 0x90
};
#else
enum {
    kProfileOffset = 0x569c,
    kStepOffset = 0x1370,
    kStateOffset = 0x1371,
    kActiveOffset = 0x13a0,
    kDesignOffset = 0x13f4,
    kWindowOffset = 0xac
};
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Profile02188aec {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int design : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int designChosen : 1;
    unsigned int remaining : 4;
};
struct Struct0205de24;
struct Struct_0205c570;
struct Obj021e6e20;
struct Obj0205eaa0;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24*, unsigned char, unsigned char);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570*);
extern "C" int _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20(Obj021e6e20*);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" void _Z22BuildMessageF_0218a974Pc(char*);
extern "C" void func_ov023_021e6e60(char*);
extern "C" int func_ov023_021e6de4(char*);
#if defined(jpn)
extern "C" void func_ov012_0218adac(char*, int, int);
#else
extern "C" void func_ov012_0218adac(char*, int, int, int);
#endif
extern "C" void func_ov012_0218930c(char*, int);
extern Obj0205eaa0 data_02108760;

static inline Profile02188aec* GetProfileDesign(GameState* state) {
    return (Profile02188aec*)((char*)state + kProfileOffset);
}

// USA: func_ov012_02188aec
// JPN: func_ov012_02189138
extern "C" ARM void func_ov012_02188aec(char* self) {
    Profile02188aec* profile = GetProfileDesign(GameState::GetInstance());
    if ((*(unsigned char*)(self + kStepOffset)) == 0) {
        (*(unsigned char*)(self + kStepOffset))++;
        (*(unsigned char*)(self + kStepOffset))++;
        return;
    } else if ((*(unsigned char*)(self + kStepOffset)) == 1) {
        (*(unsigned char*)(self + kStepOffset))++;
        return;
    } else if ((*(unsigned char*)(self + kStepOffset)) == 2) {
        (*(unsigned char*)(self + kActiveOffset)) = 0;
        (*(unsigned int*)(self + kDesignOffset)) = (profile->design - profile->female) / 2;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((Struct0205de24*)(self + kWindowOffset), 0, 3);
        func_ov023_021e6e60(self);
        _Z22BuildMessageF_0218a974Pc((char*)self);
        (*(unsigned char*)(self + kStepOffset))++;
        return;
    } else if ((*(unsigned char*)(self + kStepOffset)) == 3) {
        (*(unsigned char*)(self + kActiveOffset)) = 1;
        int selection = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)(Struct0205de24*)(self + kWindowOffset));
        if ((*(unsigned int*)(self + kDesignOffset)) != selection) {
            (*(unsigned int*)(self + kDesignOffset)) = selection;
#if defined(jpn)
            func_ov012_0218adac(self, 0, ((*(unsigned int*)(self + kDesignOffset)) << 1) + profile->female);
#else
            func_ov012_0218adac(self, 0, ((*(unsigned int*)(self + kDesignOffset)) << 1) + profile->female, 0);
#endif
        }
        int finished = 0;
        if (func_ov023_021e6de4(self)) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            Profile02188aec* current = GetProfileDesign(GameState::GetInstance());
            current->design = ((*(unsigned int*)(self + kDesignOffset)) << 1) + current->female;
            current->designChosen = 1;
            finished = 1;
        } else if (_Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20((Obj021e6e20*)self)) {
            (*(unsigned int*)(self + kDesignOffset)) = (profile->design - profile->female) / 2;
            finished = 1;
#if defined(jpn)
            func_ov012_0218adac(self, 0, -1);
#else
            func_ov012_0218adac(self, 0, -1, 0);
#endif
        }
        if (finished) (*(unsigned char*)(self + kStepOffset))++;
        return;
    } else if ((*(unsigned char*)(self + kStepOffset)) == 4) {
        (*(unsigned char*)(self + kStepOffset))++;
        return;
    } else if ((*(unsigned char*)(self + kStepOffset)) == 5) {
        (*(unsigned char*)(self + kStateOffset)) = 1;
        (*(unsigned char*)(self + kStepOffset)) = 1;
        func_ov012_0218930c(self, 1);
    }
}
