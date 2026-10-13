#pragma once

#include "World/Object3D.h"

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

struct CharacterCreationUI {
#if defined(jpn)
    unsigned char unknownBeforeTexts[0xc0];
#else
    unsigned char unknownBeforeTexts[0xe0];
#endif
    Container020e0310 texts;
#if defined(jpn)
    unsigned char unknownBeforeTileMaps[0x11c - 0xc8];
#else
    unsigned char unknownBeforeTileMaps[0x158 - 0xe8];
#endif
    CreationTileMap tileMaps[4];
    unsigned char unknownBeforeWindows[0x20];
    CreationWindow windows[2];
    unsigned char unknownBeforeCharacter[0x7f8 - 0x370];
    void* character;
    void* nextCharacter;
    unsigned char unknownBeforeModel[0x78];
    Object3D model;
    unsigned char camera[0x2c8];
    unsigned char unknownBeforeState[0x6c];
    signed char state;
    unsigned char step;
    unsigned char unknownBeforeSecondModel[0x7e];
    Object3D secondModel;
    unsigned char selection;
    unsigned char unknownAfterSelection[3];
    void* characterData;
    unsigned int unknownD8c;
    int resourceTask;
    unsigned char resourceStep;
    unsigned char unknownBeforeFlags[7];
    unsigned int flags;
    signed char furthestState[2];
    unsigned char vocation;
    unsigned char sex;
};
