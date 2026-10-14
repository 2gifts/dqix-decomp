#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct EquipSlot02162db0 {
    char unk_0[0x20];
};

struct CombatantRecord02162db0 {
    char unk_0[0x194];
    EquipSlot02162db0 slots[1];
};

struct Combatant02162db0 {
    #if defined(jpn)
    char unk_0[0x144];
#else
    char unk_0[0x150];
#endif
    CombatantRecord02162db0* record;
};

struct SavedSlot02162db0 {
    #if defined(jpn)
    char unk_0[0x17c];
#else
    char unk_0[0x180];
#endif
    signed char type;
    char unk_181;
    short value;
};

struct SlotFlags02162db0 {
    char unk_0[0x18];
    unsigned int flags;
};

struct SlotIds02162db0 {
    char unk_0[0x30];
    int combatantId;
    int ids[8];
};

extern "C" int func_ov017_021d60f4(void* args);
struct Field150Holder02052e2c;
short* GetField150Ptr0x488_02052e2c(Field150Holder02052e2c*);
struct Field150Holder02052df8;
int GetHalfwordEntryFromField150(Field150Holder02052df8*, int);
extern "C" void func_02052d7c(Combatant02162db0* combatant, int index, short value);
void* GetPtrField0x2a04_02010828(GameState* gameState);
void ClearBitsInWord_0203b4b0(unsigned int* word, unsigned int mask);
extern "C" void func_ov017_0218f5a4(GameResources* resources, int combatantId, int a, int b, int c);

extern SlotFlags02162db0 data_ov001_02165880;
extern SlotIds02162db0 data_ov001_02164d14;
extern int data_ov001_02164a30[];
extern int data_ov001_02164d44[];

// USA: func_ov001_02162db0
extern "C" ARM int func_ov001_02162db0(void* args, int argc) {
    GameState* gameState;
    Combatant02162db0* combatant;
    int mode;
    GameResources* resources;
    SavedSlot02162db0* saved;
    int combatantId;
    int slot;
    short* values;

    gameState = GameState::GetInstance();
    combatantId = func_ov017_021d60f4(args);
    combatant = (Combatant02162db0*)GetCombatantWithFlag0x100_0200ff1c(gameState, combatantId);
    if (combatant == NULL) {
        return 0;
    }
    slot = func_ov017_021d60f4((char*)args + 8);
    mode = 0;
    if (argc >= 3) {
        mode = func_ov017_021d60f4((char*)args + 0x10);
    }

    if (!(data_ov001_02165880.flags & 1)) {
        int base = combatantId * 0xc;
        data_ov001_02164d14.combatantId = combatantId;
        data_ov001_02164d14.ids[0] = base + 0x13;
        data_ov001_02164d14.ids[1] = base + 0x14;
        data_ov001_02164d14.ids[2] = base + 0x15;
        data_ov001_02164d14.ids[3] = base + 0x17;
        data_ov001_02164d14.ids[4] = base + 0x19;
        data_ov001_02164d14.ids[5] = base + 0x1b;
        data_ov001_02164d14.ids[6] = base + 0x1c;
        data_ov001_02164d14.ids[7] = base + 0x1d;
        data_ov001_02165880.flags |= 1;
    }

    if (&combatant->record->slots[(unsigned char)data_ov001_02164a30[slot]] == NULL) {
        return 0;
    }
    values = GetField150Ptr0x488_02052e2c((Field150Holder02052e2c*)combatant);
    if (values == NULL) {
        return 0;
    }

    resources = func_ov017_0218b5b0();
    saved = (SavedSlot02162db0*)resources->unknown_ptr_array_371c[6];
    GetPtrField0x2a04_02010828(gameState);
    gameState->GetGameObjectByIndex(data_ov001_02164d44[slot]);

    if (mode == 0) {
        saved->value = -1;
        saved->type = -1;
        saved->value = values[slot];
        func_02052d7c(combatant, slot, -1);
    } else {
        int value = saved->value;
        signed char type = saved->type;
        saved->value = -1;
        saved->type = -1;
        if (GetHalfwordEntryFromField150((Field150Holder02052df8*)combatant, slot) < 0 && type != 6) {
            func_02052d7c(combatant, slot, value);
        }
    }

    ClearBitsInWord_0203b4b0(&resources->brightnessFlags_0, 0x10);
    BackgroundLoader::GetInstance();
    func_ov017_0218f5a4(resources, combatantId, 1, 0, 0);
    return 1;
}
