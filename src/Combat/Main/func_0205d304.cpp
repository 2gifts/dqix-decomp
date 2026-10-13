#include <globaldefs.h>

struct Vec2 {
    short x;
    short y;
    inline void Set(short newX, short newY) { x = newX; y = newY; }
};

struct Struct_0205d81c;
struct Struct_0205bf3c;
struct Obj5d594;
struct ScaledElementList0204aa28;

extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c*, int);
extern "C" void _Z24CopyOrClearField0204c770PcPv(char*, void*);
void GetNibbles(struct Obj5d594*, unsigned char*, unsigned char*);
#if defined(jpn)
extern "C" void func_0204d790(void* self, const char* text, unsigned int destination, int mode, unsigned char border, unsigned char fullWidth);
#else
extern "C" void func_0204c980(void* self, const char* text, unsigned int destination, int mode, unsigned char border, unsigned char fullWidth, unsigned char font);
#endif
unsigned int GetScaledElementPtr(struct ScaledElementList0204aa28*);
extern "C" void _Z18ResetState0205bf3cP15Struct_0205bf3c(struct Struct_0205bf3c*);
extern "C" void _Z23ApplyElemFields0205d904Ph(unsigned char*);

struct Elem0205d304 {
    char pad0[0x4];
    void* style;
    char pad8[0x98];
    unsigned int destination;
    int pixelBytes;
    struct Vec2 layout[4];
    char padb8[0xa];
    short c2;
    unsigned char id;
    unsigned char flags;
    char padc6;
    unsigned char fontHeight;
    char padc8[0x18];
};

struct Ctx0205d304 {
    char pad0[0x54];
    char resetState[0x44];
    void* styles;
    struct Elem0205d304* windows;
    struct Vec2 layout[4];
    unsigned char activeWindowId;
    unsigned char nextWindowId;
    char padb2;
    unsigned char windowCapacity;
    unsigned char windowCount;
    unsigned char flagBit2;
    unsigned char noHorizontalInset;
    unsigned char fontHeight;
};

// USA: func_0205d304
extern "C" ARM void func_0205d304(struct Ctx0205d304* renderer, const char* text, int mode, unsigned char border,
#if defined(jpn)
                                       unsigned char flagBit3, unsigned char fullWidth, void* extraStyle) {
#else
                                       unsigned char flagBit3, unsigned char fullWidth, void* extraStyle, unsigned char font) {
#endif
    struct Elem0205d304* elem;
    struct Elem0205d304* e;
    unsigned char lowA, highA, lowB, highB;
    int matched;
    int j;
    unsigned char i;
    unsigned int value;

    if (text == 0 || renderer->styles == NULL || renderer->windows == NULL) return;
    if (renderer->windowCapacity <= renderer->windowCount) return;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)renderer, renderer->nextWindowId) != 0) return;

    elem = &renderer->windows[renderer->windowCount];
    elem->layout[0].Set(renderer->layout[0].x, renderer->layout[0].y);
    elem->layout[1].Set(renderer->layout[1].x, renderer->layout[1].y);
    elem->layout[2].Set(renderer->layout[2].x, renderer->layout[2].y);
    elem->layout[3].Set(renderer->layout[3].x, renderer->layout[3].y);
    if (flagBit3) {
        elem->flags |= 8;
    } else {
        elem->flags &= ~8;
    }
    elem->id = renderer->nextWindowId;
    if (renderer->flagBit2) {
        elem->flags |= 4;
    } else {
        elem->flags &= ~4;
    }
    if (renderer->noHorizontalInset) {
        elem->flags |= 0x10;
    } else {
        elem->flags &= ~0x10;
    }
    elem->fontHeight = renderer->fontHeight;
    _Z24CopyOrClearField0204c770PcPv((char*)elem, extraStyle);

    if (renderer->windowCount != 0) {
        matched = 0;
        GetNibbles((struct Obj5d594*)elem->style, &lowA, &highA);
        for (j = renderer->windowCount - 1; j >= 0; j--) {
            e = &renderer->windows[j];
            GetNibbles((struct Obj5d594*)e->style, &lowB, &highB);
            if (lowA == lowB && highA == highB) {
                e = &renderer->windows[j];
                value = e->destination + e->pixelBytes;
#if defined(jpn)
                func_0204d790(elem, text, value, mode, border, fullWidth);
#else
                func_0204c980(elem, text, value, mode, border, fullWidth, font);
#endif
                matched = 1;
                break;
            }
        }
        if (!matched) {
            value = GetScaledElementPtr((struct ScaledElementList0204aa28*)elem->style);
#if defined(jpn)
            func_0204d790(elem, text, value, mode, border, fullWidth);
#else
            func_0204c980(elem, text, value, mode, border, fullWidth, font);
#endif
        }
        elem->flags &= ~0x20;
        for (i = 0; i < renderer->windowCount; i++) {
            e = &renderer->windows[i];
            e->c2 = 1;
        }
    } else {
        value = GetScaledElementPtr((struct ScaledElementList0204aa28*)elem->style);
#if defined(jpn)
        func_0204d790(elem, text, value, mode, border, fullWidth);
#else
        func_0204c980(elem, text, value, mode, border, fullWidth, font);
#endif
        elem->flags &= ~0x20;
    }

    renderer->windowCount++;
    _Z18ResetState0205bf3cP15Struct_0205bf3c((struct Struct_0205bf3c*)renderer->resetState);
    renderer->activeWindowId = renderer->nextWindowId;
    _Z23ApplyElemFields0205d904Ph((unsigned char*)renderer);
}
