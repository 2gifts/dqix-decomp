#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

extern "C" bool _Z20IsHighByteFF02044494PvS_(void* obj, void* src);
extern "C" int _Z22LookupKeyValue020425e4iii(int a, int b, int fontIndex);

extern int data_020e7a94[];

struct Container02046170 {
    char pad0[0x9b8];
    MessageGlyphSlot glyphs[0x80];
};

#if defined(jpn)
enum TextControl02046f80 { EndText02046f80 = 0xff01 };

enum PositionControlOffset {
    SetX = 0x21, SetY, SetXY, AdvanceX, AdvanceY, AdvanceXY
};
// USA: func_02046170
extern "C" ARM int func_02046f80(void* obj, int fontPixelSize, unsigned short* commands, int commandCount) {
    if (commands == 0) return 0;
    if (commandCount < 0) return 0;
    int advance;
    switch (fontPixelSize) {
    case 10: advance = 10; break;
    case 12: advance = 12; break;
    default: return 0;
    }
    TextControl02046f80 end = EndText02046f80;
    int currentExtent = 0;
    int savedExtent = 0;
    for (int i = 0; i < commandCount; i++) {
        unsigned short command = commands[i];
        if (command == end) break;
        if (command == end + 0x17 || command == end + 9 || command == end + 0x1b ||
            command == end + 0x1e || command == end + 0x1f || command == end + 0x20 ||
            command == end + 3 || command == end + 4 || command == end + 5 || command == end + 6) {
        } else if (command == end + 0x1a) {
            currentExtent += advance >> 1;
        } else if (command == end + SetX) {
            ++i;
            if (savedExtent < commands[i]) savedExtent = commands[i];


            int previous = currentExtent;
            currentExtent = savedExtent;
            savedExtent = previous;
        } else if (command == end + SetY) {
            ++i;
        } else if (command == end + SetXY) {
            unsigned short value = commands[i + 1];
            i += 2;
            if (savedExtent < value) savedExtent = value;
            int previous = currentExtent;
            currentExtent = savedExtent;
            savedExtent = previous;
        } else if (command == end + AdvanceX) {
            unsigned short value = commands[i + 1];

            i += 2;
            currentExtent += value;
        } else if (command == end + AdvanceY) {
            ++i;
        } else if (command == end + AdvanceXY) {
            unsigned short value = commands[i + 1];
            i += 2;
            currentExtent += value;
        } else {
            currentExtent += advance;
        }
    }
    if (currentExtent < savedExtent) currentExtent = savedExtent;
    return currentExtent;
}
#else
// USA: func_02046170
extern "C" ARM int func_02046170(struct Container02046170* window, unsigned short* commands, int commandCount,
                                 int fontIndex) {
    if (commands == 0) return 0;
    if (commandCount < 0) return 0;

    int fallbackGlyphWidth = data_020e7a94[fontIndex] & 0xff;
    int currentExtent = 0;
    int savedExtent = 0;
    int previousCharacter = 0xff;

    for (int i = 0; i < commandCount; i++) {
        unsigned short command = commands[i];
        if (command == 0xff01) break;
        if (command == 0xff18) {
            if (savedExtent < currentExtent) savedExtent = currentExtent;
            currentExtent = 0;
            previousCharacter = 0xff;
        } else if (command == 0xff19) {
            previousCharacter = 0xff;
            currentExtent += fallbackGlyphWidth + 1;
        } else if (_Z20IsHighByteFF02044494PvS_(window, &command)) {
            previousCharacter = 0xff;
        } else {
            MessageGlyphSlot* slot = &window->glyphs[command];
            int characterIndex = slot->characterIndex;
            currentExtent += _Z22LookupKeyValue020425e4iii(previousCharacter, characterIndex, fontIndex);
            previousCharacter = characterIndex;
            int glyphWidth = fallbackGlyphWidth;
            if (slot->character != 0) glyphWidth = slot->character->width;
            currentExtent += glyphWidth + 1;
        }
    }

    if (currentExtent < savedExtent) currentExtent = savedExtent;
    return currentExtent;
}
#endif
