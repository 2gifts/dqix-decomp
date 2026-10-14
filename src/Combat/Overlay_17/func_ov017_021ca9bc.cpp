#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { RegionOffset718 = 0x508 };
#else
enum { RegionOffset718 = 0x718 };
#endif

extern "C" void* func_ov017_021b8478(void* obj);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Entry021ca9bc {
    char pad0[2];
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char countPad : 4;
    char pad1[0x18 - 0xb];
};

struct Container021ca9bc {
    unsigned char pad0;
    unsigned char outerPad0 : 4;
    unsigned char outerCount : 2;
    unsigned char outerPad1 : 2;
    char pad1[2];
    struct Entry021ca9bc entries[1];
};

struct Bits11_021ca9bc {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char nibble : 4;
};

struct Bits13_021ca9bc {
    bool bit0 : 1;
    bool bit1 : 1;
    bool bit2 : 1;
    bool bit3 : 1;
    bool bit4 : 1;
    bool bit5 : 1;
    bool bit6 : 1;
};

struct Elem021ca9bc {
    char pad0[0xc];
    unsigned short fc;
    char pad1[0x30 - 0xe];
    unsigned short f30;
    short f32;
    short f34;
    char pad2[0x38 - 0x36];
    unsigned char f38;
    char pad3;
    char pad4;
    struct Bits11_021ca9bc bits3b;
    struct Bits13_021ca9bc bits3c;
    unsigned char f3d;
    char pad5[0xa4 - 0x3e];
};

struct Fields021ca9bc {
    unsigned short f0;
    unsigned short f2;
    short f4;
    short f6;
    unsigned short f8;
    unsigned short fa;
    unsigned char fc;
    struct Bits11_021ca9bc bits;
    unsigned char fe;
    struct Bits13_021ca9bc bits13;
};

struct Msg021ca9bc {
    unsigned char tag;
    unsigned char pad[3];
    struct Fields021ca9bc fields;
};

struct Obj021ca9bc {
    char pad0[8];
    unsigned short f8;
    char pad1[0x158 - 0xa];
    struct Elem021ca9bc elems[8];
};

// USA: func_ov017_021ca9bc
extern "C" ARM void func_ov017_021ca9bc(struct Container021ca9bc* sl) {
    GameState::GetInstance();
    unsigned char* table = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + RegionOffset718);
    struct Obj021ca9bc* obj = (struct Obj021ca9bc*)func_ov017_021b8478(table);
    void* data = GetData02100044_0202ae24();

    for (int i = 0; i < sl->outerCount; i++) {
        struct Entry021ca9bc* entry = &sl->entries[i];
        struct Msg021ca9bc msg;
        for (int j = 0; j < entry->count; j++) {
            unsigned char idv = entry->ids[j];
            if (idv >= 8) {
                continue;
            }
            struct Elem021ca9bc* elem = &obj->elems[idv];
            struct Fields021ca9bc* mf = &msg.fields;
            msg.tag = 0x5f;
            mf->f0 = obj->f8;
            mf->f2 = (unsigned short)(entry->ids[j] + 0xc0);
            mf->f4 = elem->f32;
            mf->f6 = elem->f34;
            mf->f8 = elem->fc;
            mf->fa = elem->f30;
            mf->fc = elem->f38;
            mf->bits.bit0 = elem->bits3b.bit0 & 0xff;
            mf->bits.bit1 = elem->bits3b.bit1 & 0xff;
            mf->bits.bit2 = elem->bits3b.bit2 & 0xff;
            mf->bits.bit3 = elem->bits3b.bit3 & 0xff;
            mf->bits.nibble = elem->bits3b.nibble & 0xff;
            mf->bits13.bit0 = elem->bits3c.bit0 != 0;
            mf->bits13.bit1 = elem->bits3c.bit1 != 0;
            mf->bits13.bit2 = elem->bits3c.bit2 != 0;
            mf->bits13.bit3 = elem->bits3c.bit3 != 0;
            mf->bits13.bit4 = elem->bits3c.bit4 != 0;
            mf->bits13.bit5 = elem->bits3c.bit5 != 0;
            mf->bits13.bit6 = elem->bits3c.bit6 != 0;
            mf->fe = elem->f3d;
            func_0205e330(data, &msg, 0);
        }
    }
}
