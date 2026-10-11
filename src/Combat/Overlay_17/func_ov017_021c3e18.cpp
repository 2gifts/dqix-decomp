// JPN: func_ov017_021c42e0
#if defined(jpn)
enum { RegionOffset7f60 = 0x7c8c };
#else
enum { RegionOffset7f60 = 0x7f60 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3_021c3f68 {
    int x;
    int y;
    int z;
};

struct Party021c3e18 {
    unsigned char unk0[0xf78];
    unsigned char memberIds[4];
    unsigned char memberCount;
};

struct Battle021c3e18 {
    unsigned char unk0[3];
    unsigned char active;
};

extern "C" unsigned short* func_02012fe4(void);
extern "C" void* func_0202ae18(void);
unsigned char GetField0x397cValue(GameState* gs);
extern "C" void _Z16SetVec3_021c3f68P13Vec3_021c3f68iii(struct Vec3_021c3f68* obj, int x, int y, int z);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* _Z15GetSlot021677d8Pvi(void* work, int idx);
extern "C" void _Z26EnqueueEventTag35_021d2ad0hiiih(short id, int x, int y, int z, unsigned char arg);
extern "C" int func_0202c508(void* p);

// USA: func_ov017_021c3e18
extern "C" ARM void func_ov017_021c3e18(unsigned char arg) {
    unsigned short* mapId = func_02012fe4();
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    Party021c3e18* party = (Party021c3e18*)GetPtrField0x2a04(gs);
    Battle021c3e18* battle = (Battle021c3e18*)res->unknown_ptr_3718;
    void* search = func_0202ae18();
    unsigned char self = GetField0x397cValue(gs);
    for (int i = 0; i < party->memberCount; i++) {
        unsigned char id = party->memberIds[i];
        if (id == self) {
            continue;
        }
        GameObject* member = gs->GetPartyMemberByIndex(id);
        if (member == NULL) {
            continue;
        }
        Vector3i pos = member->obj3D_.position_;
        if (*mapId == 10000) {
            _Z16SetVec3_021c3f68P13Vec3_021c3f68iii((Vec3_021c3f68*)&pos, 0xff000, 0, 0xff000);
        }
        if (battle->active != 0) {
            void* work = func_ov017_021b8468(battle);
            if (work != NULL) {
                pos = *(Vector3i*)_Z15GetSlot021677d8Pvi(work, id);
            }
        }
        _Z26EnqueueEventTag35_021d2ad0hiiih(member->obj3D_.unknown_4_, pos.x, pos.y, pos.z, arg);
    }
    if (func_0202c508(search)) {
        Vector3i pos = *(Vector3i*)((char*)gs + RegionOffset7f60);
        _Z26EnqueueEventTag35_021d2ad0hiiih(0xce, pos.x, pos.y, pos.z, arg);
    }
}
