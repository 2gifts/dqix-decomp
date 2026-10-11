// JPN: func_ov017_021c892c
#if defined(jpn)
enum { RegionOffset94c = 0x8b4 };
#else
enum { RegionOffset94c = 0x94c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
void* GetData02100044(void);
struct CheckField0AndGlobalHalfStruct0202c508;
extern "C" int func_0202c508(struct CheckField0AndGlobalHalfStruct0202c508* obj);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Party021c847c {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Msg021c847c {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char arr[8];
    unsigned char pad1[8];
};

// USA: func_ov017_021c847c  (semantic: BroadcastCombatantFieldFlags_021c847c)
extern "C" ARM void func_ov017_021c847c(void) {
    GameState* battleStruct = GameState::GetInstance();
    void* search = func_0202ae18();
    void* data = GetData02100044();

    struct Msg021c847c msg;
    msg.tag = 0x76;
    char* base = (char*)msg.arr;
    int i;
    for (i = 0; i < 4; i++) {
        base[i] = -1;
        *(base + i + 4) = -1;
    }

    if (func_0202c508((struct CheckField0AndGlobalHalfStruct0202c508*)search)) {
        int j;
        for (j = 0; j < 4; j++) {
            GameObject* c = GetCombatantWithFlag0x1000(battleStruct, j);
            if (c != NULL) {
                int field = GetFieldAt0x150((unsigned char*)c);
                if (field != 0) {
                    base[j] = (unsigned char)*(int*)(field + RegionOffset94c);
                }
            }
        }
    }

    struct Party021c847c* party = (struct Party021c847c*)GetPtrField0x2a04(battleStruct);
    int k;
    for (k = 0; k < party->count; k++) {
        unsigned char id = party->ids[k];
        GameObject* c2 = GetCombatantWithFlag0x100(battleStruct, id);
        if (c2 != NULL) {
            int field2 = GetFieldAt0x150((unsigned char*)c2);
            if (field2 != 0) {
                unsigned int v = *(unsigned int*)(field2 + 0x78);
                *(base + id + 4) = (unsigned char)((v << 1) >> 31);
            }
        }
    }

    func_0205e330(data, &msg, 0);
}
