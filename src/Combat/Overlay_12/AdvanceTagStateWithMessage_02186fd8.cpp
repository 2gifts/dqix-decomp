#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
enum {
    kStepOffset = 0x1340,
    kActiveOffset = 0x1368,
    kWindowOffset = 0x90,
    kChoiceCOffset = 0x1438,
    kStringsOffset = 0x1314,
    kProfileOffset = 0x543c,
    kTitleTextOffset = 0x1498
};
#else
enum {
    kStepOffset = 0x1370,
    kActiveOffset = 0x13a0,
    kWindowOffset = 0xac,
    kChoiceCOffset = 0x13e0,
    kStringsOffset = 0x133c,
    kProfileOffset = 0x569c,
    kTitleTextOffset = 0x1440
};
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct ProfileNameSelection {
    unsigned int header;
    unsigned int unknown : 9;
    int title : 10;
    int accolade : 11;
    unsigned int edited : 1;
    unsigned int unknownHigh : 1;
};

static inline ProfileNameSelection* GetProfileNameSelection(GameState* state) {
    return (ProfileNameSelection*)((char*)state + kProfileOffset);
}

extern "C" int func_ov012_0218432c(int a);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov023_021e6e60(void* obj);
void BuildMessageC_02189c44(char* self);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
extern "C" int func_ov023_021e6de4(char* obj);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
struct TableA68;
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
#if defined(jpn)
extern "C" void func_ov012_0218adac(void*, int, int);
#else
extern "C" void func_ov012_0218adac(void* obj, int a, int b, int c);
#endif
extern "C" void func_ov012_0218930c(void* obj, int a);
struct Obj021e6e20;
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);
extern int data_02108760;

// USA: func_ov012_02186fd8  (semantic: AdvanceTagStateWithMessage_02186fd8)
extern "C" ARM void func_ov012_02186fd8(char* base) {
    unsigned char state = *(unsigned char*)(base + kStepOffset);
    if (state == 0) {
        *(unsigned char*)(base + kActiveOffset) = 0;
        int ret = func_ov012_0218432c(1);
        *(int*)(base + kChoiceCOffset) = ret;
        if (ret < 0) {
            *(int*)(base + kChoiceCOffset) = 0;
        }

        FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + kWindowOffset), 0, 3);
        func_ov023_021e6e60(base);
        BuildMessageC_02189c44(base);

        (*(unsigned char*)(base + kStepOffset))++;
        return;
    }
    if (state != 1) return;

    *(unsigned char*)(base + kActiveOffset) = 1;
    int sum = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + kWindowOffset));
    *(int*)(base + kChoiceCOffset) = sum;

    if (func_ov023_021e6de4(base) != 0) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);

        GameState* bs = GameState::GetInstance();
        int key = (short)(*(int*)(base + kChoiceCOffset) + 0x27d8);
        void* name = FindEntryByKey_02072a68((struct TableA68*)(base + kStringsOffset), key);
        ProfileNameSelection* profile = GetProfileNameSelection(bs);

        memset(base + kTitleTextOffset, 0, 0x40);
        memcpy(base + kTitleTextOffset, name, strlen((char*)name));

        profile->title = *(int*)(base + kChoiceCOffset) + 0xc8;

#if defined(jpn)
        func_ov012_0218adac(base, 0, -1);
#else
        func_ov012_0218adac(base, 0, -1, 0);
#endif
        func_ov012_0218930c(base, 0);
    } else {
        if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)base) != 0) {
            func_ov012_0218930c(base, 1);
        }
    }
}
