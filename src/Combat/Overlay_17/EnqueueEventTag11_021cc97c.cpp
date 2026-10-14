#if defined(jpn)
enum {regionalOffset0=0x8bc};
#else
enum {regionalOffset0=0x954};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);
int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct LocalEvt021cc97c {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short id;
    unsigned short val;
    unsigned char arr[12];
};

// USA: func_ov017_021cc97c
ARM void EnqueueEventTag11_021cc97c(int id) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, id);
    if (combatant == NULL) return;
    int field150 = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (field150 == 0) return;

    void* p = GetData02100044_0202ae24();
    LocalEvt021cc97c buf;
    buf.tag = 0xb;
    buf.id = (unsigned short)id;
    buf.val = *(unsigned short*)((char*)field150 + regionalOffset0);
    int i;
    for (i = 0; i < 12; i++) {
        buf.arr[i] = *(unsigned char*)((char*)field150 + (i + 1) + 0x186);
    }
    func_0205e330(p, &buf, 0);
}
