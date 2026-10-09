#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "System/Cache.h"

struct CharacterColors {
    unsigned short hair_[10][2];
    unsigned short colors2_[8][2];
    unsigned short colors4_[8][4];
    unsigned short colors8_[8][8];
    unsigned short skin_[8][2];
    unsigned short edge_;
};

extern unsigned short data_02109928[10][2] __attribute__((aligned(4)));

// USA: func_02099d34
extern "C" ARM void func_02099d34(Model3D* m, int a, unsigned int b, int c) {
    NSBXXTex* tex;
    unsigned char* entry;
    int count;
    int len;
    CharacterColors* colors;
    unsigned char* p;
    int rem;

    if (b > 8) {
        return;
    }
    if (m == NULL) {
        return;
    }
    tex = m->GetTEX0();
    if (tex == NULL) {
        return;
    }

    entry = NULL;
    count = 0;
    colors = (CharacterColors*)data_02109928;

    switch (a) {
    case 1:
        entry = (unsigned char*)&colors->colors2_[b];
        count = 2;
        break;
    case 2:
        entry = (unsigned char*)&colors->colors4_[b];
        count = 4;
        break;
    case 4:
        entry = (unsigned char*)&colors->colors8_[b];
        count = 8;
        break;
    }
len = count * 2;
    p = (unsigned char*)tex + tex->block4Offset_;
    rem = tex->block4NumEightBytes_ << 3;
    if ((unsigned int)rem > 0x20) {
        int t = rem & 0x1f;
        p += t;
        rem -= t;
    }

    while (rem > 0) {
        memcpy(p + c, entry, len);
        rem -= 0x20;
    }

    unsigned int off = tex->block4Offset_;
    unsigned int size = tex->block4NumEightBytes_ << 3;
    CleanInvalidateCacheRange((const void*)((unsigned char*)tex + off), size);
    StageTexFilePaletteData(tex, true);
}