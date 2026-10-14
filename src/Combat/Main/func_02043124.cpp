#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include <std_library_functions.h>
#include <Graphics/VRAMStaging.h>
#include <System/BGBases.h>
struct FlagOwner;
void ClearFlag0x1SetFlag0x2_020e1cb8(FlagOwner*);
#if defined(jpn)
struct StorageView { char pad[0x30]; void* pointer; };
extern StorageView data_02107800;
#else
extern void* data_02107800;
#endif
struct Object02043124 {
    char padding_0x0[IS_JPN ? 4 : 0x38];
    FlagOwner* owner;
    char padding_0x3c[IS_JPN ? 0x860 : 0x95c];
    int field_0x998, field_0x99c, field_0x9a0;
    char padding_0x9a4[IS_JPN ? 0xf89 : 0x1028];
    unsigned char needsReset;
};
#define REG_BG_OFFSET (*(volatile unsigned int*)0x04000018)
#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)
// USA: func_02043124
extern "C" ARM void func_02043124(Object02043124* object) {
    object->field_0x9a0 = 0;
    object->field_0x998 = 0;
    if (object->needsReset) {
        object->needsReset = 0;
        #if defined(jpn)
        void* storage = data_02107800.pointer;
#else
        void* storage = data_02107800;
#endif
        memset(storage, 0, 0x1000);
        StageMemoryToVRAM((VRAMSubregion)7, storage, 0, 0x800, true, false);
        StageMemoryToVRAM((VRAMSubregion)9, storage, 0, 0x800, true, false);
        void* screen = (void*)GetMainBG1ScreenBase();
        if (screen) memset(screen, 0, 0x800);
        REG_BG_OFFSET = 0;
        REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | 0x1300;
    }
    if (object->owner) {
        ClearFlag0x1SetFlag0x2_020e1cb8(object->owner);
    }
    object->owner = 0;
}
