#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);
struct BitScan02083a50;
int CollectSetBitIndices(struct BitScan02083a50* obj, short* out, int max);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021ccfd0 {
    unsigned char tag;
    unsigned char pad1[3];
    unsigned char threeBit : 3;
    unsigned char count : 3;
    unsigned char pad4 : 2;
    unsigned char pad5;
    short vals[7];
};

// USA: func_ov017_021ccfd0  (semantic: EmitBitIndexGroups_021ccfd0)
extern "C" ARM void func_ov017_021ccfd0(int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, combatantId);
    if (!combatant) {
        return;
    }
    int field150 = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (!field150) {
        return;
    }

    unsigned short buffer[288];
    void* p;
    int consumed;
    int j;
    int count;

    count = (unsigned short)CollectSetBitIndices((struct BitScan02083a50*)field150, (short*)buffer, 0x11f);
    p = GetData02100044_0202ae24();
    consumed = 0;
    j = 0;
    struct LocalEvt021ccfd0 evt;
    evt.tag = 0x10;
    evt.threeBit = (unsigned char)combatantId;

    while (consumed < count) {
        int i = 0;
        for (; i < 7; i++) {
            if (count <= consumed + i) {
                break;
            }
            evt.vals[i] = buffer[j * 7 + i];
        }
        evt.count = i;
        func_0205e330(p, &evt, 0);
        consumed += evt.count;
        j++;
    }
}
