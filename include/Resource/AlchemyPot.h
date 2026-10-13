#pragma once

#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct AlchemySubEffect {
    char unk_0[0x10];
    int state_;
    unsigned char unk_14;
};

struct AlchemyItemInfoWindow {
#if defined(jpn)
    char unk_0[0x6f0];
#else
    char unk_0[0x774];
#endif
    unsigned short flags_;
    char unk_776[0x7];
    signed char windowSprites_;
    char unk_77e[0x1d];
    unsigned char externalBuffer_ : 1;
    unsigned char inMenu_ : 1;
};

struct AlchemyIngredientSprite {
    char unk_0[0x7c];
};

struct AlchemyRecipePrefix {
    short id_;
};

struct AlchemyRecipeRecord {
    short id_;
    unsigned short known_ : 1;
    unsigned short made_ : 1;
    unsigned short unk_2_2 : 14;
};

struct AlchemyPot {
#if !defined(jpn)
    char names_[3][0x80];
#endif
    SafeAllocator* allocators_;
    SafeAllocator* itemAllocator_;
    SafeAllocator* nextItemAllocator_;
    SafeAllocator effectAllocator_;
    void* previousCamera_;
    void* canvasBuffer_;
    unsigned char* amounts_;
    void* itemNames_;
    void* texts_;
    AlchemyRecipePrefix* recipe_;
    AlchemyRecipePrefix* nextRecipe_;
    int unk_1bc;
    AlchemyRecipeRecord* record_;
    unsigned char* unk_1c4;
    void* layout_;
    void* backgrounds_;
    void* canvases_;
    void* menu_;
    void* item_;
    void* nextItem_;
    void* sprites_;
    char renderer_[0x54];
    Object3D protagonist_;
    Object3D pot_;
    Object3D lid_;
    Object3D effect_;
    Object3D steam_;
    char unk_594[0x38];
    char camera_[0x2c8];
    AlchemyIngredientSprite ingredients_[4];
    SafeAllocator ingredientAllocators_[4];
    int task_;
    int backgroundTask_;
    unsigned char state_;
    unsigned char loadStep_;
    unsigned char itemStep_;
    unsigned char backgroundStep_;
    unsigned char unk_ae0;
    unsigned char animationStep_;
    unsigned short flags_;
    AlchemyItemInfoWindow window_;
    SafeAllocator* windowAllocator_;
    SafeAllocator* windowSpriteAllocator_;
    char partNames_[0x18];
    AlchemySubEffect subEffect_;
    short itemId_;
    signed char itemSprites_;
    unsigned char numIngredients_;
    unsigned char effectMode_;
    unsigned char resetBlend_;
};
