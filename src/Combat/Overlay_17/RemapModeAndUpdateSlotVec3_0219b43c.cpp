// JPN: func_ov017_0219bfcc
#if defined(jpn)
enum { RegionOffset630 = 0x420, SlotBaseOffset = 0x2980 };
#else
enum { RegionOffset630 = 0x630, SlotBaseOffset = 0x2b90 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3b0Value(GameState* battleStruct);

struct Vec3copy0202ec84 { unsigned int v[3]; };
int ComputeTwoFromVec3_0202ec84(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct Vec3Target0203a46c;
void SetVec3At0x1c(struct Vec3Target0203a46c* obj, int x, int y, int z);

struct Struct020478bc;
void RecomputeField0x7c(struct Struct020478bc* o, int newIndex);

struct Slot0219b43c { unsigned char pad[0x88]; };

// USA: func_ov017_0219b43c  (semantic: RemapModeAndUpdateSlotVec3_0219b43c)
extern "C" ARM void func_ov017_0219b43c(char* obj, int mode, struct Vec3copy0202ec84* vec3, int extra, int arg5) {
    void* fieldVal = (void*)GetField0x3b0Value(GameState::GetInstance());
    switch (mode) {
    case 2:
        mode = 2;
        break;
    case 5:
        mode = 3;
        break;
    case 6:
        mode = 4;
        break;
    case 14:
        mode = 12;
        break;
    case 15:
        mode = 13;
        break;
    case 16:
        mode = 14;
        break;
    }

    int local1, local0;
    ComputeTwoFromVec3_0202ec84(fieldVal, vec3, &local1, &local0);

    struct Slot0219b43c* slot = (struct Slot0219b43c*)(obj + SlotBaseOffset) + mode;
    *(struct Slot0219b43c**)(obj + 0x3000 + RegionOffset630) = slot;

    switch (mode) {
    default: {
        int x = ((local1 - 0xc) + extra) << 0xc;
        int y = ((local0 - 0x4c) + arg5) << 0xc;
        SetVec3At0x1c(*(struct Vec3Target0203a46c**)(obj + 0x3000 + RegionOffset630), x, y, 0);
        RecomputeField0x7c(*(struct Struct020478bc**)(obj + 0x3000 + RegionOffset630), 1);
        break;
    }
    case 0xc:
    case 0xd:
    case 0xe: {
        int x = ((local1 - 6) + extra) << 0xc;
        int y = ((local0 - 0x4c) + arg5) << 0xc;
        SetVec3At0x1c(*(struct Vec3Target0203a46c**)(obj + 0x3000 + RegionOffset630), x, y, 0);
        break;
    }
    }
}
