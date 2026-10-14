#pragma once

#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"

struct SpriteContext0205ac40;
struct B174Outer;
struct Container0205a3d0;

struct CreationTextEntry {
    int key;
    const char* text;
};

struct Container020e0310 {
    unsigned int count : 12;
    unsigned int unknown : 20;
    CreationTextEntry* entries;
};

struct CreationTileMap {
    unsigned char unknown[0x10];
    void* entries;
    void* buffer;
    unsigned int sizeIndex;
    unsigned char flags;
    unsigned char entryCount;
    unsigned char unknown1e;
    unsigned char sizeTable;
};

struct CreationWindow {
    unsigned char unknown[4];
    int frame[20];
    int cursor[16];
    unsigned char unknown94[4];
    CreationTileMap* tileMaps;
    void* elements;
    short layout[8];
    unsigned char activeWindow;
    unsigned char nextWindow;
    unsigned char tileMapCount;
    unsigned char capacity;
    unsigned char count;
    unsigned char flags;
    unsigned char noHorizontalInset;
    unsigned char fontHeight;
    unsigned int unknownB8;
};

struct CreationNavigation {
    int count;
    int field4;
    int columns, rows;
    unsigned char mode;
    unsigned char unknown11[3];
    int page;
    int column, row;
    int* primaryDimension;
    int* secondaryDimension;
    int* primaryCursor;
    int* secondaryCursor;
    unsigned int input;
    short counter;
    unsigned char unknown36[6];
    unsigned char flags3c;
    unsigned char flags3d;
    unsigned char unknown3e[2];
};

struct CreationChoiceGrid {
    int x, y;
    int width, height;
    int stepX, stepY;
    int columns, rows;
};

struct CharacterCreationUI {
#if defined(jpn)
    SafeAllocator allocators[8];
#else
    SafeAllocator allocators[9];
#endif
    SafeAllocator* modelAllocator;
    SafeAllocator* previewAllocators;
#if defined(jpn)
    unsigned char unknownBeforeTexts[0xc0 - 0xa8];
#else
    unsigned char unknownBeforeTexts[0xe0 - 0xbc];
#endif
    Container020e0310 texts;
    unsigned char unknownBeforeTextBuffer[0x10];
    char* textBuffer;
#if defined(jpn)
    unsigned char unknownBeforeTileMaps[0x11c - 0xdc];
#else
    unsigned char unknownBeforeTileMaps[0x158 - 0xfc];
#endif
    CreationTileMap tileMaps[4];
    unsigned char unknownBeforeWindows[0x20];
    CreationWindow windows[2];
    unsigned char unknownBeforeSprites[0x7d8 - 0x370];
    SpriteContext0205ac40* firstSpriteContext;
    B174Outer* firstSprites;
    Container0205a3d0* firstSpriteEntries;
    SpriteContext0205ac40* spriteContext;
    B174Outer* sprites;
    Container0205a3d0* spriteEntries;
    unsigned char unknownBeforeCharacter[0x7f8 - 0x7f0];
    void* character;
    void* nextCharacter;
    unsigned int unknown800;
    int targetAngle;
    unsigned char unknownBeforeModel[0x70];
    Object3D model;
    unsigned char camera[0x2c8];
    CreationNavigation navigation;
    CreationChoiceGrid grid;
    short cursorX, cursorY;
    short cursorWidth, cursorHeight;
    short lastCursorX, lastCursorY;
    signed char state;
    unsigned char step;
    unsigned char unknownBeforeSecondModel[0x7e];
    Object3D secondModel;
    unsigned char selection;
    unsigned char unknownAfterSelection[3];
    void* characterData;
    int touchedChoice;
    int resourceTask;
    unsigned char resourceStep;
    unsigned char mode;
    unsigned char unknownBeforeFlags[6];
    unsigned int flags;
    signed char furthestState[2];
    unsigned char vocation;
    unsigned char sex;
    unsigned char bodyType[2];
    unsigned char faceStyle[2];
    unsigned char skinColor[2];
    unsigned char eyeColor[2];
    unsigned char hairStyle[2];
    unsigned char hairColor[2];
#if defined(jpn)
    char names[2][11];
    unsigned char nameFlags[2];
    unsigned char keyboardChoice;
    signed char keyboardPage;
    signed char previousKeyboardPage;
#endif
};
