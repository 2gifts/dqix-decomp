#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

int GetData02107800Word0_020429d4(void);
extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);
void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
void SetMainBrightness(GameResources*, int, int);
void SetBrightness(GameResources*, int, int);
void SetByteField0x253_020397c0(void* obj);

struct Obj021b2968 {
    unsigned char pad0;
    unsigned char flag1;
    char pad2[0x36];
    unsigned int flags0x38;
};

// USA: func_ov017_021b2968  (semantic: SetupStreamFieldsAndCounters_021b2968)
extern "C" ARM int func_ov017_021b2968(struct Obj021b2968* self) {
    GameResources* oddStruct = func_ov017_0218b5b0();

    unsigned int bit3 = (self->flags0x38 << 28) >> 31;
    if (bit3) {
        void* buf = (void*)GetData02107800Word0_020429d4();
        memset(buf, 0, 0x800);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(5, (int)buf, 0, 0x800, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(7, (int)buf, 0, 0x800, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(9, (int)buf, 0, 0x800, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(6, (int)buf, 0, 0x20, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(8, (int)buf, 0, 0x20, 1, 0);
        _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0xa, (int)buf, 0, 0x20, 1, 0);

        struct FlagWord02046708* flagWord = (struct FlagWord02046708*)GetDataPtr02114e04_020d6c00();
        if (!TestFlags02046708(flagWord, 1) && !TestFlags02046708(flagWord, 0x40)) {
            SetMainBrightness((GameResources*)oddStruct, 0, 0x28);
        } else {
            SetBrightness((GameResources*)oddStruct, 0, 0x28);
        }
    }

    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetUnknownGameObject();
    if (combatant) {
        SetByteField0x253_020397c0(combatant);
    }

    self->flag1 = 1;
    return 8;
}
