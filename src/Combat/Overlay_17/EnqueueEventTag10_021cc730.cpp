// JPN: func_ov017_021ccbd8
#if defined(jpn)
enum { RegionOffset950 = 0x8b8 };
#else
enum { RegionOffset950 = 0x950 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);
int GetFieldAt0x150(unsigned char* obj);

struct LocalEvt021cc730 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short idLow3:3;
    unsigned short byteVal:8;
    unsigned short idxLow4:4;
    unsigned short flagBit:1;
    unsigned short field6;
    unsigned int field8;
    unsigned char fieldc;
    unsigned char fieldd;
    unsigned char fielde;
    unsigned char pad2[4];
};

// USA: func_ov017_021cc730  (semantic: EnqueueEventTag10_021cc730)
extern "C" ARM void func_ov017_021cc730(int id, unsigned char arg1, unsigned char arg2, unsigned char arg3) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(bs, id);
    if (combatant == 0) return;
    int field150 = GetFieldAt0x150((unsigned char*)combatant);
    if (field150 == 0) return;

    void* p = GetData02100044();
    LocalEvt021cc730 buf;
    int idx = *(int*)((char*)field150 + RegionOffset950);

    buf.tag = 0xa;
    buf.idLow3 = (unsigned short)id;
    buf.byteVal = *(unsigned short*)((char*)field150 + idx * 2 + 0x16c);
    buf.idxLow4 = (unsigned short)*(int*)((char*)field150 + RegionOffset950);
    buf.field8 = *(unsigned int*)((char*)field150 + idx * 4 + 0x138);
    buf.field6 = *(unsigned short*)((char*)field150 + 0x564);
    buf.fieldc = *(unsigned char*)((char*)field150 + idx + 0x186);
    buf.flagBit = (unsigned short)arg1;
    buf.fieldd = arg2;
    buf.fielde = arg3;

    func_0205e330(p, &buf, 0);
}
