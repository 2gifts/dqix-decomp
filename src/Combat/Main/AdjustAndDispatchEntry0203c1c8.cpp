#include <globaldefs.h>

struct CachedTextTable;
extern CachedTextTable* data_02105244;

struct Struct0203c1c8 {
#if defined(jpn)
    short textSlots[10];
#endif
    int x;
    int y;
#if defined(jpn)
    int lineHeight;
    int characterAdvance;
#endif
    int paletteOffset;
    int alignment;
    int priority;
#if defined(jpn)
    signed int affineIndex : 16;
    unsigned int unknown32 : 8;
    unsigned int unknown33 : 8;
    int affineMode;
#else
    short entryIndex;
#endif
};

#if defined(jpn)
int GetEntryByteField0203c284(const Struct0203c1c8* text);
extern "C" void func_0203c4d0(CachedTextTable* cache, int count, const short* slots, int affineMode,
                            int priority, int affineIndex, int x, int y,
                            int paletteOffset, int characterAdvance, int lineHeight);
#else
ARM unsigned char GetEntryByteField0203c284(char* obj);
extern "C" void func_0203c4d0(void*, short, int, int, int, int);
#endif

// USA: func_0203c1c8
// JPN: func_0203bd44
#if defined(jpn)
ARM void AdjustAndDispatchEntry0203c1c8(Struct0203c1c8* obj, int count) {
#else
ARM void AdjustAndDispatchEntry0203c1c8(Struct0203c1c8* obj) {
#endif
    if (data_02105244 == NULL) return;

#if defined(jpn)
    int width = GetEntryByteField0203c284(obj);
#else
    unsigned char width = GetEntryByteField0203c284((char*)obj);
#endif
    int halfWidth = width >> 1;
    int x = obj->x;
    int y = obj->y;
    int alignment = obj->alignment;

    switch (alignment) {
        case 1: x -= width; break;
        case 2: x -= halfWidth; break;
        case 3: x = 0x80 - halfWidth; break;
    }

#if defined(jpn)
    func_0203c4d0(data_02105244, count, obj->textSlots, obj->affineMode,
                  obj->priority, obj->affineIndex, x, y,
                  obj->paletteOffset, obj->characterAdvance, obj->lineHeight);
#else
    func_0203c4d0(data_02105244, obj->entryIndex, obj->priority, x, y, obj->paletteOffset);
#endif
}
