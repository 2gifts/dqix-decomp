#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#include "Resource/CharacterCreationUI.h"
#include "Graphics/SpriteAffineTransform.h"

struct Elem0205a3d0 {
    unsigned char unknown0[8];
    unsigned short key;
    unsigned char unknownA[11];
    unsigned char flags;
    unsigned char unknown16[2];
};
struct Elem_0205d81c {
    unsigned char unknown0[0xac];
    short tileX, tileY;
    unsigned char unknownB0[12];
    short pixelX, pixelY;
    unsigned char unknownC0[4];
    unsigned char selector;
    unsigned char unknownC5[0x1b];
};
struct Struct_0205d81c;
struct Container0205a330;
void SetEntryByte14ByKey0205a42c(Container0205a3d0*, int, int);
void SetEntryFlag2ByKey0205a370(Container0205a3d0*, int);
Elem0205a3d0* FindEntryByHalfword0205a3d0(Container0205a3d0*, int);
void SetEntryPosition(Container0205a3d0*, int, short, short);
void IterateEntries0205a330(Container0205a330*, int);
extern "C" void func_0205ae8c(void*);
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);
int CheckField0x9cSetWhenField0xd4Present(unsigned char*);

extern "C" ARM void func_ov023_021da9b4(CharacterCreationUI* self) {
    GameState* state = GameState::GetInstance();
    if (self->firstSpriteContext != NULL) {
        signed char index = self->state;
        if (index >= 1 && index <= 8) {
            short y = (short)(((index - 1) << 4) + 0x2b);
            SetEntryByte14ByKey0205a42c(self->firstSpriteEntries, 0, 0x78);
            SetEntryFlag2ByKey0205a370(self->firstSpriteEntries, 0);
            Elem0205a3d0* entry = FindEntryByHalfword0205a3d0(self->firstSpriteEntries, 0);
            if (entry != NULL) entry->flags |= 8;
            unsigned int ticks = state->GetTickCount();
            IterateEntries0205a330((Container0205a330*)self->firstSpriteEntries, ticks);
            SetEntryPosition(self->firstSpriteEntries, 0, 0x6c, y);
            func_0205ae8c(self->firstSpriteContext);
        }
    }
    if (self->spriteContext == NULL) return;
    Elem_0205d81c* element = FindElementByC40205d81c((Struct_0205d81c*)&self->windows[1], 1);
    if (element == NULL) return;
    if (!CheckField0x9cSetWhenField0xd4Present((unsigned char*)element)) return;
    short dx = (short)(element->tileX << 3);
    short dy = (short)(element->tileY << 3);
    dx = (short)(dx + element->pixelX);
    dy = (short)(dy + element->pixelY);
    SetEntryByte14ByKey0205a42c(self->spriteEntries, 0, 0x3f);
    SetEntryFlag2ByKey0205a370(self->spriteEntries, 0);
    Elem0205a3d0* entry = FindEntryByHalfword0205a3d0(self->spriteEntries, 0);
    if (entry != NULL) entry->flags |= 8;
    unsigned int ticks = state->GetTickCount();
    IterateEntries0205a330((Container0205a330*)self->spriteEntries, ticks);
    SetEntryPosition(self->spriteEntries, 0, (short)(dx - 8), (short)(dy - 2));
    func_0205ae8c(self->spriteContext);
}
#else
struct Struct0200fb08;
ARM unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);

struct Container0205a3d0;
void SetEntryByte14ByKey0205a42c(struct Container0205a3d0* c, int key, int val);
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
struct Elem0205a3d0;
struct Elem0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);
ARM void SetEntryPosition(struct Container0205a3d0* c, int key, short a, short b);

struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330* c, int arg);

extern "C" void func_0205ae8c(void* obj);

struct Struct_0205d81c;
struct Elem_0205d81c_021da9b4 {
    char pad0[0xac];
    short x0;
    short y0;
    char pad1[0xbc - 0xb0];
    short x1;
    short y1;
};
ARM struct Elem_0205d81c_021da9b4* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);
ARM int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);

// USA: func_ov023_021da9b4  (semantic: UpdateEntryPositionsFromDamageAndElement_021da9b4)
extern "C" ARM void func_ov023_021da9b4(void* obj) {
    GameState* bs1 = GameState::GetInstance();

    if (*(void**)((char*)obj + 0x7d8) != 0) {
        signed char v = *(signed char*)((char*)obj + 0xc58);
        if (v >= 1 && v <= 8) {
            short posA = 0x6c;
            short posB = (short)(((v - 1) << 4) + 0x2b);
            GameState* bs2 = GameState::GetInstance();
            int norm = NormalizeField5_0200fb08((struct Struct0200fb08*)bs2);
            struct Container0205a3d0* c = *(struct Container0205a3d0**)((char*)obj + 0x7e0);
            if (norm == 4) posA = 0x64;
            SetEntryByte14ByKey0205a42c(c, 0, 0x78);
            SetEntryFlag2ByKey0205a370(c, 0);
            struct Elem0205a3d0* e = FindEntryByHalfword0205a3d0(c, 0);
            if (e != NULL) {
                *(unsigned char*)((char*)e + 0x15) |= 8;
            }
            unsigned int scaleCount = bs2->GetTickCount();
            IterateEntries0205a330((struct Container0205a330*)c, scaleCount);
            SetEntryPosition(c, 0, posA, posB);
            func_0205ae8c(*(void**)((char*)obj + 0x7d8));
        }
    }

    if (*(void**)((char*)obj + 0x7e4) == 0) {
        return;
    }
    struct Elem_0205d81c_021da9b4* elem = FindElementByC40205d81c((struct Struct_0205d81c*)((char*)obj + 0x2b4), 1);
    if (elem == 0) {
        return;
    }
    if (!CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem)) {
        return;
    }
    short dx = (short)(elem->x0 << 3);
    short dy = (short)(elem->y0 << 3);
    dx = (short)(dx + elem->x1);
    dy = (short)(dy + elem->y1);

    struct Container0205a3d0* c2 = *(struct Container0205a3d0**)((char*)obj + 0x7ec);
    SetEntryByte14ByKey0205a42c(c2, 0, 0x78);
    SetEntryFlag2ByKey0205a370(c2, 0);
    struct Elem0205a3d0* e2 = FindEntryByHalfword0205a3d0(c2, 0);
    if (e2 != NULL) {
        *(unsigned char*)((char*)e2 + 0x15) |= 8;
    }
    unsigned int scaleCount2 = bs1->GetTickCount();
    IterateEntries0205a330((struct Container0205a330*)c2, scaleCount2);
    SetEntryPosition(c2, 0, (short)(dx - 8), (short)(dy - 2));
    func_0205ae8c(*(void**)((char*)obj + 0x7e4));
}
#endif
