#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Payload021c4664 {
    short mapId;
    short x;
    short y;
    short z;
    short param;
    float dayTimer;
};

struct Evt021c4664 {
    unsigned char tag;
    unsigned char pad1[3];
    Payload021c4664 payload;
};

// USA: func_ov017_021c4664
extern "C" ARM void func_ov017_021c4664(int mapId, Vector3i pos, short param) {
    GameState* battleStruct = GameState::GetInstance();
    void* data = GetData02100044();
    Evt021c4664 evt;
    Payload021c4664* p = &evt.payload;
    evt.tag = 0x36;
    p->mapId = mapId;
    p->x = pos.x >> 10;
    p->y = pos.y >> 10;
    p->z = pos.z >> 10;
    p->param = param;
    p->dayTimer = battleStruct->GetDayTimer();
    func_0205e330(data, &evt, 0);
}
