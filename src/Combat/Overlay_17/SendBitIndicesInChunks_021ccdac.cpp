#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);
struct BitArray020839dc;
int CollectSetBitIndices020839dc(struct BitArray020839dc* s, unsigned char* out, int max);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Buf021ccdac {
    unsigned char tag;
    unsigned char pad[3];
    unsigned char idBits : 3;
    unsigned char lenBits : 4;
    unsigned char unused1 : 1;
    unsigned char data[15];
};

// USA: func_ov017_021ccdac  (semantic: SendBitIndicesInChunks_021ccdac)
extern "C" ARM void func_ov017_021ccdac(int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = GetCombatantWithFlag0x100(bs, combatantId);
    if (!c) return;
    int field150 = GetFieldAt0x150((unsigned char*)c);
    if (!field150) return;

    unsigned char indices[0x44];
    void* p;
    int sent;
    int chunk;
    int total;

    total = CollectSetBitIndices020839dc((struct BitArray020839dc*)field150, indices, 0x42);
    total = total & 0xff;

    p = GetData02100044();
    struct Buf021ccdac buf;
    buf.tag = 0xf;
    buf.idBits = combatantId;

    sent = 0;
    chunk = 0;
    while (sent < total) {
        int j;
        for (j = 0; j < 0xf; j++) {
            if (total <= sent + j) break;
            buf.data[j] = indices[chunk * 15 + j];
        }
        buf.lenBits = j;
        func_0205e330(p, &buf, 0);
        sent += buf.lenBits;
        chunk++;
    }
}
