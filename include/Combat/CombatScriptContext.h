#pragma once

#include "Memory/SafeAllocator.h"



struct CombatScriptContext {
    unsigned short paletteColor;
    unsigned short unknown2;
#if !defined(jpn)
    const char* nameOverride;
#endif
    SafeAllocator* allocator;
    unsigned int unknownCounter;
    char* currentObject;
};

extern CombatScriptContext data_020fdc4c;
