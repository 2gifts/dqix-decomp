// JPN: func_ov017_021c74a0
#if defined(jpn)
enum { RegionOffset718 = 0x508 };
#else
enum { RegionOffset718 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021b8478(void* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct FieldsMsg021c6ff0 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    short f8;
    short fa;
    short fc;
    short fe;
};

struct Whole021c6ff0 {
    unsigned char tag;
    unsigned char pad[3];
    struct FieldsMsg021c6ff0 fields;
};

// USA: func_ov017_021c6ff0
extern "C" ARM void func_ov017_021c6ff0() {
    GameState* bs = GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + RegionOffset718);
    unsigned char* search = (unsigned char*)func_ov017_021b8478(table);
    void* data = GetData02100044();

    struct Whole021c6ff0 msg;
    msg.tag = 0x70;
    struct FieldsMsg021c6ff0* fp = &msg.fields;

    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34(search, (unsigned char)i)) {
            continue;
        }
        GameObject* c = bs->GetCombatantByIndex(i);
        if (c == 0 || *(unsigned char*)(*(char**)((char*)c + 0x138) + 0x26) == 0) {
            continue;
        }
        fp->f0 = *(unsigned short*)(search + 0x8);
        fp->f2 = (unsigned short)i;
        memcpy(&fp->f4, *(char**)((char*)c + 0x138) + 0x58, 4);
        fp->f8 = *(short*)(*(char**)((char*)c + 0x138) + 0x28);
        fp->fa = *(short*)(*(char**)((char*)c + 0x138) + 0x2a);
        fp->fc = *(short*)(*(char**)((char*)c + 0x138) + 0x2c);
        fp->fe = *(short*)(*(char**)((char*)c + 0x138) + 0x2e);
        func_0205e330(data, &msg, 0);
    }
}
