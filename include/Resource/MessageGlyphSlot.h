#pragma once

#include <globaldefs.h>

struct FontCharacter {
    const char* text;
    signed char width;
    signed char byteLength : 6;
    signed char reserved : 1;
    signed char uppercase : 1;
    char padding[2];
};




struct State0204166c {
    unsigned char* pixels;
    unsigned int textureOffset;
    int bitmapIndex;
    int x;
    int y;
#if defined(jpn)
    int depth;
    unsigned char encodedCharacter[2];
    unsigned char fontPixelSize;
    unsigned char pendingUpload : 1;
    unsigned char renderFlag1 : 1;
    unsigned char renderFlag2 : 1;
    unsigned char unknownFlags : 5;
#else
    unsigned short depth;
    unsigned char pendingUpload : 1;
    unsigned char renderFlag1 : 1;
    unsigned char renderFlag2 : 1;
    unsigned char fontIndex : 1;
    unsigned char unknownFlags : 4;
    unsigned char characterIndex;
    FontCharacter* character;
#endif
};

typedef State0204166c MessageGlyphSlot;
typedef char MessageGlyphSlotSizeCheck[sizeof(MessageGlyphSlot) == 0x1c ? 1 : -1];

void ResetState0204166c(MessageGlyphSlot* slot);
