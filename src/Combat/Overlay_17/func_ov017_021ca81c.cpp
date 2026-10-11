// JPN: func_ov017_021caccc
#if defined(jpn)
enum { RegionOffset718 = 0x508 };
#else
enum { RegionOffset718 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* func_ov017_021b8478(void* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Entry021ca81c {
    char pad0[2];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char countPad : 4;
    char pad1[0x18 - 0xb];
};

struct Container021ca81c {
    unsigned char pad0;
    unsigned char outerPad0 : 4;
    unsigned char outerCount : 2;
    unsigned char outerPad1 : 2;
    char pad1[2];
    struct Entry021ca81c entries[1];
};

struct Elem021ca81c {
    char pad0[0x28];
    short f28;
    short f2a;
    short f2c;
    short f2e;
};

struct FieldsMsg021ca81c {
    unsigned short f0;
    unsigned short f2;
    int f4;
    short f8;
    short fa;
    short fc;
    short fe;
};

struct Whole021ca81c {
    unsigned char tag;
    unsigned char pad[3];
    struct FieldsMsg021ca81c fields;
};

// USA: func_ov017_021ca81c
extern "C" ARM void func_ov017_021ca81c(struct Container021ca81c* sl) {
    GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + RegionOffset718);
    unsigned char* fp = (unsigned char*)func_ov017_021b8478(table);
    void* data = GetData02100044();

    for (int i = 0; i < sl->outerCount; i++) {
        struct Entry021ca81c* entry = &sl->entries[i];
        struct Whole021ca81c msg;
        for (int j = 0; j < entry->count; j++) {
            unsigned char idv = entry->ids[j];
            if (idv >= 8) {
                continue;
            }
            struct Elem021ca81c* elem = (struct Elem021ca81c*)(fp + 0x158 + idv * 0xa4);
            struct FieldsMsg021ca81c* mf = &msg.fields;
            msg.tag = 0x5e;
            mf->f0 = *(unsigned short*)(fp + 8);
            mf->f2 = (unsigned short)(entry->ids[j] + 0xc0);
            memcpy(&mf->f4, (char*)elem + 0x58, 4);
            mf->f8 = elem->f28;
            mf->fa = elem->f2a;
            mf->fc = elem->f2c;
            mf->fe = elem->f2e;
            func_0205e330(data, &msg, 0);
        }
    }
}
