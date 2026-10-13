#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_02184384 func_ov012_021853f8
#define func_ov012_0218930c func_ov012_02189be8
enum {
    kStepOffset = 0x1340,
    kStateOffset = 0x1341,
    kActiveOffset = 0x1368,
    kWindowOffset = 0x90,
    kChoiceEOffset = 0x1440,
    kListCountsOffset = 0x141c,
    kSecondListOffset = 0x1420
};
#else
enum {
    kStepOffset = 0x1370,
    kStateOffset = 0x1371,
    kActiveOffset = 0x13a0,
    kWindowOffset = 0xac,
    kChoiceEOffset = 0x13e8,
    kListCountsOffset = 0x13c4,
    kSecondListOffset = 0x13c8
};
#endif

#include <globaldefs.h>

struct ProfileListCounts {
    unsigned short available : 5;
    unsigned short other : 11;
};

extern "C" int func_ov012_02184384(unsigned short* entries, int count);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov023_021e6e60(void* obj);
void BuildMessageE_0218a438(char* self);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
extern "C" int func_ov023_021e6de4(char* obj);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
struct Obj021e6e20;
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);
extern "C" void func_ov012_0218930c(void* obj, int a);
extern int data_02108760;

// JPN: func_ov012_02188bb0
// USA: func_ov012_021884f4  (semantic: AdvanceTagState_021884f4)
extern "C" ARM void func_ov012_021884f4(char* base) {
    unsigned char state = *(unsigned char*)(base + kStepOffset);
    if (state == 0) {
        *(unsigned char*)(base + kActiveOffset) = 0;
        *(int*)(base + kChoiceEOffset) = 1;

        unsigned int count = ((ProfileListCounts*)(base + kListCountsOffset))->other;
        int ret = func_ov012_02184384(*(unsigned short**)(base + kSecondListOffset), count);
        if (ret < 0) {
            *(int*)(base + kChoiceEOffset) = 0;
        }

        FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(base + kWindowOffset), 0, 3);
        func_ov023_021e6e60(base);
        BuildMessageE_0218a438(base);

        (*(unsigned char*)(base + kStepOffset))++;
        return;
    }
    if (state != 1) return;

    *(unsigned char*)(base + kActiveOffset) = 1;
    int sum = GetActiveScaledSum0205d794((struct Struct_0205c570*)(base + kWindowOffset));
    *(int*)(base + kChoiceEOffset) = sum;

    if (func_ov023_021e6de4(base) != 0) {
        int v = *(int*)(base + kChoiceEOffset);
        int cont = 1;
        switch (v) {
        case 0:
            *(unsigned char*)(base + kStateOffset) = 0xb;
            *(unsigned char*)(base + kStepOffset) = 0;
            break;
        case 1: {
            if (((ProfileListCounts*)(base + kListCountsOffset))->other != 0) {
                *(unsigned char*)(base + kStateOffset) = 0xc;
                *(unsigned char*)(base + kStepOffset) = 0;
            } else {
                cont = 0;
            }
            break;
        }
        }

        if (cont != 0) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        }
    } else {
        if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)base) != 0) {
            func_ov012_0218930c(base, 1);
        }
    }
}
