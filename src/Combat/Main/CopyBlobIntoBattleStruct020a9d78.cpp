#include <globaldefs.h>

#if defined(jpn)
enum { RegionOffset = 0x7c38 };
#else
enum { RegionOffset = 0x7e78 };
#endif
#include "GameState/GameState.h"
#include "System/Matrix.h"

void* GetField0x3f8Address_0200fd0c(GameState* battleStruct);
extern "C" void* func_02012fe4();
struct S_bc7c;
void SetField0x27d8_0201bc7c(struct S_bc7c* obj, unsigned short val);
struct S_bc88;
void SetField0x27da_0201bc88(struct S_bc88* obj, unsigned short val);

struct Data02109bf4 {
    unsigned char pad[0xc8];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
};
extern struct Data02109bf4 data_02109bf4;

struct SavedLocation {
    unsigned short zoneId;
    short unknown2;
    Vector3i position;
    unsigned short global27da;
    unsigned short global27d8;
    unsigned char flag;
    signed char entryKey;
    short entryX;
    short entryY;
    short entryZ;
};

struct PendingLocation {
    unsigned short zoneId;
    unsigned char unknown2[5];
    unsigned char unknown7;
    unsigned char unknown8[8];
    Vector3i position;
    short unknown1c;
};

struct PendingEntryPosition {
    short x;
    short y;
    short z;
    signed char key;
};

struct GamePendingEntryPosition {
    unsigned char unknown0[RegionOffset];
    PendingEntryPosition pending;
};

// USA: func_020a9d78
ARM int CopyBlobIntoBattleStruct020a9d78(void* srcRaw) {
    SavedLocation* saved = static_cast<SavedLocation*>(srcRaw);
    GameState* battleStruct = GameState::GetInstance();
    PendingLocation* destination = static_cast<PendingLocation*>(GetField0x3f8Address_0200fd0c(battleStruct));

    destination->zoneId = saved->zoneId;
    destination->position = saved->position;

    destination->unknown1c = saved->unknown2;
    destination->unknown7 = 1;

    void* g = func_02012fe4();
    SetField0x27d8_0201bc7c((struct S_bc7c*)g, saved->global27d8);
    SetField0x27da_0201bc88((struct S_bc88*)g, saved->global27da);

    data_02109bf4.b3 = (saved->flag != 0);

    PendingEntryPosition* pending = &reinterpret_cast<GamePendingEntryPosition*>(battleStruct)->pending;
    pending->x = saved->entryX;
    pending->y = saved->entryY;
    pending->z = saved->entryZ;
    pending->key = saved->entryKey;
    return 1;
}
