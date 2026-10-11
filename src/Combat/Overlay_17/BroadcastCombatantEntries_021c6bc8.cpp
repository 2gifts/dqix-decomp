// JPN: func_ov017_021c7078
#if defined(jpn)
enum { RegionOffset718 = 0x508 };
#else
enum { RegionOffset718 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct FieldsMsg021c6bc8 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
    int f8;
    int fc;
};

struct Whole021c6bc8 {
    unsigned char tag;
    unsigned char pad[3];
    struct FieldsMsg021c6bc8 fields;
};

// USA: func_ov017_021c6bc8  (semantic: BroadcastCombatantEntries_021c6bc8)
extern "C" ARM void func_ov017_021c6bc8() {
    GameState* bs = GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + RegionOffset718);
    unsigned char* search = (unsigned char*)func_ov017_021b8478(table);
    void* data = GetData02100044();

    struct Whole021c6bc8 msg;
    msg.tag = 0x6e;
    struct FieldsMsg021c6bc8* fp = &msg.fields;

    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34(search, (unsigned char)i)) {
            continue;
        }
        GameObject* c = bs->GetCombatantByIndex(i);
        if (*(unsigned char*)(*(char**)((char*)c + 0x138) + 0x26) == 0) {
            continue;
        }
        fp->f0 = *(unsigned short*)(search + 0x8);
        fp->f2 = (unsigned short)i;
        fp->f4 = *(unsigned short*)(*(char**)((char*)c + 0x138) + 0x0);
        fp->f6 = *(unsigned short*)(*(char**)((char*)c + 0x138) + 0x2);
        fp->f8 = *(int*)(*(char**)((char*)c + 0x138) + 0x14);
        fp->fc = *(int*)(*(char**)((char*)c + 0x138) + 0x18);
        func_0205e330(data, &msg, 0);
    }
}
