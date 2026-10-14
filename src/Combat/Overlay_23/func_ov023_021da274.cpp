#if defined(jpn)
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>

struct Obj0204b010;
struct Obj0204b8d0;
struct PaletteWindow;
enum CreationSex {
    CreationMale = 0,
    CreationFemale = 1,
    CreationSexByteMax = 0xff // Storage range, not an additional selection.
};
void ClearBuffer0204b010(Obj0204b010*, void*);
void DispatchEntry0204b8d0(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void func_0204b04c(void*, void*);
extern "C" void func_0204b9b8(PaletteWindow*, int, int, int, int, unsigned int);

extern "C" ARM void func_ov023_021da274(CharacterCreationUI* editor) {
    if (editor->flags & 0x1000) {
        ClearBuffer0204b010((Obj0204b010*)&editor->tileMaps[0], NULL);
        int page = editor->state;
        if (page >= 1 && page <= 8) {
            short row = (short)((page - 1) * 2);
            short bottom = row + 5;
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[0], 0, 0, row, 15, bottom, 10, 2, 0xffff);
        }
        func_0204b04c(&editor->tileMaps[0], NULL);
    }
    if (editor->flags & 0x2000) {
        ClearBuffer0204b010((Obj0204b010*)&editor->tileMaps[3], NULL);
        int page = editor->state;
        if (page == 1) {
            unsigned int id = 0;
            short x, y;
            if (editor->sex == CreationMale) {
                x = 7;
                y = 5;
            } else if (editor->sex == CreationFemale) {
                id = 1;
                x = 7;
                y = 11;
            }
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], id, 0, 0, x, y, 18, 6, 0xffff);
        } else if (page == 2) {
            unsigned int slot = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, bodyType)))[editor->sex];
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], slot, 0, 0, (short)(slot * 5 + 4), 5, 4, 9, 0xffff);
        } else if (page == 5) {
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], 0, 0, 0, 4, 5, 24, 9, 0xffff);
            int value = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, faceStyle)))[editor->sex];
            func_0204b9b8((PaletteWindow*)&editor->tileMaps[3], (short)(value % 5 * 5 + 4), (short)((value / 5 + 1) * 5), 4, 4, 2);
        } else if (page == 3) {
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], 0, 0, 0, 4, 5, 24, 9, 0xffff);
            CreationSex sex = (CreationSex)editor->sex;
            int value = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, hairStyle)))[sex];
            func_0204b9b8((PaletteWindow*)&editor->tileMaps[3], (short)(value % 5 * 5 + 4), (short)((value / 5 + 1) * 5), 4, 4, 2);
        } else if (page == 8) {
            if (editor->flags & 0x400000) {
                DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], 3, 0, 0, 0, 14, 32, 10, 0xffff);
            } else {
                if (editor->previousKeyboardPage != editor->keyboardPage) {
                    DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[2], (unsigned char)editor->keyboardPage, 0, 0, 0, 0, 32, 24, 0xffff);
                }
                editor->previousKeyboardPage = editor->keyboardPage;
                func_0204b9b8((PaletteWindow*)&editor->tileMaps[2], 2, 7, 28, 12, 1);
                if (editor->navigation.rows != 1) {
                    short row = editor->keyboardChoice / 11;
                    short column = editor->keyboardChoice % 11;
                    short x = column * 2 + 3;
                    if (column >= 5) x += 1;
                    if (column == 10) x += 2;
                    short y = row * 2 + 7;
                    if (column == 10) {
                        bool highlight = true;
                        if (editor->mode == 0 && row == 4) highlight = false;
                        if (highlight) {
                            int width = 3;
                            if (row == 5) width = 4;
                            func_0204b9b8((PaletteWindow*)&editor->tileMaps[2], x, y, width, 2, 0);
                        }
                    } else {
                        func_0204b9b8((PaletteWindow*)&editor->tileMaps[2], x, y, 2, 2, 0);
                    }
                }
            }
            func_0204b04c(&editor->tileMaps[2], NULL);
        } else if (page == 9) {
            unsigned int id = 0;
            if (editor->mode == 0) id = 1;
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], id, 0, 0, 0, 14, 32, 10, 0xffff);
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], 2, 0, 0, 24, 9, 8, 7, 0xffff);
            func_0204b9b8((PaletteWindow*)&editor->tileMaps[2], 2, 7, 28, 12, 1);
            func_0204b04c(&editor->tileMaps[2], NULL);
        }
        func_0204b04c(&editor->tileMaps[3], NULL);
    }
}
#else
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj0204b010;
struct Obj0204b8d0;
struct Struct0200fb08;
struct PaletteWindow;

extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(struct Obj0204b010*, void*);
extern "C" unsigned char _Z24NormalizeField5_0200fb08P14Struct0200fb08(struct Struct0200fb08*);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void func_0204b04c(void* obj, void* p);
extern "C" void func_0204b9b8(PaletteWindow* obj, int x, int y, int width, int height, unsigned palette);
extern "C" void func_ov003_0215ec68(int id, short* w, short* h);

extern const unsigned char data_ov023_021fd530[];
extern unsigned char data_ov023_021fd532[];

struct Marker021da274 {
    short x;
    short y;
    char pad4[0xe - 4];
    unsigned char kind;
};

struct Info021da274 {
    Marker021da274* marker;
    char pad4[0x1e - 4];
    unsigned char mask;
    char pad1f;
    unsigned char column;
};

struct Window021da274 {
    char pad0[0x20];
};

struct Self021da274 {
    char pad0[0xc0];
    Info021da274* info;
    char padc4[0x158 - 0xc4];
    Window021da274 win158;
    char pad178[0x198 - 0x178];
    Window021da274 win198;
    Window021da274 win1b8;
    char pad1d8[0xc58 - 0x1d8];
    signed char page;
    char padc59[0xd95 - 0xc59];
    unsigned char hidden;
    char padd96[0xd9c - 0xd96];
    unsigned int flags;
    char padda0[3];
    unsigned char sel;
    unsigned char slotsA[2];
    unsigned char slotsB[6];
    unsigned char slotsC[8];
};

#define WIN(w) ((struct Obj0204b8d0*)&(w))

// USA: func_ov023_021da274
extern "C" ARM void func_ov023_021da274(Self021da274* self) {
    if (self->flags & 0x1000) {
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((struct Obj0204b010*)&self->win158, NULL);
        int page = self->page;
        if (page >= 1 && page <= 8) {
            int row = (short)((page - 1) * 2 + 1);
            short col = 0xf;
            short row2 = row + 5;
            short col2 = 0xa;
            if (_Z24NormalizeField5_0200fb08P14Struct0200fb08((struct Struct0200fb08*)GameState::GetInstance()) == 4) {
                col = 0xe;
                col2 = 0xd;
            }
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win158), 0, 0, row, col, row2, col2, 2, 0xffff);
        }
        func_0204b04c(&self->win158, NULL);
    }

    if (self->flags & 0x2000) {
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((struct Obj0204b010*)&self->win1b8, NULL);
        int page = self->page;
        if (page == 1) {
            unsigned int id = 0;
            short x;
            short y;
            if (self->sel == 0) {
                x = 7;
                y = 5;
            } else if (self->sel == 1) {
                id = 1;
                x = 7;
                y = 0xb;
            }
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win1b8), id, 0, 0, x, y, 0x12, 6, 0xffff);
        } else if (page == 2) {
            unsigned int slot = ((unsigned char*)((int)self + 0xda4))[self->sel];
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win1b8), slot, 0, 0, (short)(slot * 5 + 4), 5, 4, 9, 0xffff);
        } else if (page == 5) {
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win1b8), 0, 0, 0, 4, 5, 0x18, 9, 0xffff);
            int v = ((unsigned char*)((int)self + 0xda6))[self->sel];
            func_0204b9b8((PaletteWindow*)&self->win1b8, (short)(v % 5 * 5 + 4), (short)((v / 5 + 1) * 5), 4, 4, 2);
        } else if (page == 3) {
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win1b8), 0, 0, 0, 4, 5, 0x18, 9, 0xffff);
            int v = ((unsigned char*)((int)self + 0xdac))[self->sel];
            func_0204b9b8((PaletteWindow*)&self->win1b8, (short)(v % 5 * 5 + 4), (short)((v / 5 + 1) * 5), 4, 4, 2);
        } else if (page == 8) {
            int i;
            if (self->flags & 0x400000) {
                _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win1b8), 3, 0, 0, 0, 0xe, 0x20, 0xa, 0xffff);
            } else {
                i = 0;
                unsigned char mask = self->info->mask;
                unsigned char column = self->info->column;
                while (1) {
                    unsigned char bit = data_ov023_021fd532[i * 3];
                    if (bit == 0) break;
                    if (mask & bit) {
                        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win198), (&data_ov023_021fd530[i * 3])[column], 0, 0, 0, 0, 0x20, 0x18, 0xffff);
                        break;
                    }
                    i++;
                }
                func_0204b9b8((PaletteWindow*)&self->win198, 2, 7, 0x1c, 0xc, 1);
                Marker021da274* marker = self->info->marker;
                if (marker != NULL) {
                    short x = marker->x;
                    short y = marker->y;
                    short h;
                    short w;
                    func_ov003_0215ec68(marker->kind, &w, &h);
                    func_0204b9b8((PaletteWindow*)&self->win198, x >> 3, y >> 3, w >> 3, h >> 3, 0);
                }
            }
            func_0204b04c(&self->win198, NULL);
        } else if (page == 9) {
            unsigned int id = 0;
            if (self->hidden == 0) id = 1;
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win1b8), id, 0, 0, 0, 0xe, 0x20, 0xa, 0xffff);
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(WIN(self->win1b8), 2, 0, 0, 0x18, 9, 8, 7, 0xffff);
            func_0204b9b8((PaletteWindow*)&self->win198, 2, 7, 0x1c, 0xc, 1);
            func_0204b04c(&self->win198, NULL);
        }
        func_0204b04c(&self->win1b8, NULL);
    }
}

#endif

