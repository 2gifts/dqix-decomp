#pragma once

#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/MessageGlyphSlot.h"

#if defined(jpn)

struct Entry020e2cc4 {
    unsigned char state;
    unsigned char type;
    unsigned char subtype;
};
struct BattleEntry0204500c {
    Entry020e2cc4 prefix;
    unsigned char reserved[0x21];
};
struct BattleFlags0204500c {
    unsigned char streamMode : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 1;
    unsigned char flag5 : 1;
    unsigned char remaining : 2;
};
struct Foo0207df50;
struct Struct0204394c;
struct MessageSystem0219050c;

struct MessageSystem {
    unsigned char pad0[4];
    void* frame;
    unsigned char pad8[4];
    int stream40;
    int stream44;
    void* textBuffer;
    unsigned short* firstLineBuffer;
    void* secondLineBuffer;
    unsigned char pad20[0xc];
    char* formatBuffer;
    char* expandedBuffer;
    unsigned char pad34[4];
    unsigned int tokenCount;
    unsigned char pad3c[8];
    unsigned int tokenIndex;
    unsigned char pad48[4];
    unsigned char* child;
    unsigned char pad50[0x21c - 0x50];
    unsigned char bitmapAllocationBits[4];
    unsigned char pad220[0x7e2 - 0x220];
    unsigned char b912;
    unsigned char pad7e3[0x81c - 0x7e3];
    int w94c[4];
    unsigned char block95c[0x20];
    unsigned char block97c[0x10];
    unsigned char pad85c[4];
    int w990;
    int w994;
    void* active;
    int state;
    int mode;
    int w9a4;
    unsigned char pad878[8];
    int w9b0;
    int allocatedGlyphCount;
    State0204166c glyphs[0x80];
    unsigned char glyphReferences[0x80];
    int selectedEntry;
    int selectedValue;
    int unknown1710;
    int pendingValue;
    unsigned char pad1718[0x10];
    int w1858;
    int w185c;
    int w1860;
    int w1864;
    int w1868;
    unsigned char pad173c[0x10];
    short h187c;
    short h187e;
    unsigned char pad1750[2];
    unsigned short lineGlyphSlots[0x10];
    unsigned short lineGlyphCount;
    unsigned short h1944;
    unsigned char pad1776[2];
    signed char levels[4];
    signed char b194e[4];
    unsigned char b1952[4];
    unsigned char b1956;
    unsigned char b1957;
    unsigned char b1958;
    unsigned char pad1787[1];
    unsigned char b195a;
    unsigned char b195b;
    unsigned char pad178a[1];
    unsigned char b195d;
    unsigned char pad178c[2];
    unsigned char b1960;
    unsigned char inputDelay;
    unsigned char pad1790[4];
    BattleEntry0204500c entries[2];
    unsigned char b19ac;
    unsigned char b19ad;
    unsigned char b19ae;
    unsigned char b19af;
    unsigned char b19b0;
    unsigned char b19b1;
    unsigned char b19b2;
    unsigned char pad17e3[1];
    unsigned char b19b4;
    unsigned char b19b5;
    unsigned char pendingValueActive;
    unsigned char pad17e7;
    unsigned char b19b8;
    unsigned char pad17e9[2];
    unsigned char b19bb;
    unsigned char b19bc;
    unsigned char b19bd;
    unsigned char b19be;
    unsigned char b19bf;
    unsigned char b19c0;
    unsigned char b19c1;
    unsigned char field17f2;
    unsigned char b19c2;
    unsigned char b19c3;
    unsigned char b19c4;
    unsigned char b19c5;
    unsigned char b19c6;
    unsigned char b19c7;
    unsigned char b19c8;
    unsigned char b19c9;
    unsigned char b19ca;
    unsigned char pad17fc[1];
    unsigned char b19cc;
    unsigned char b19cd;
    BattleFlags0204500c flags17ff;
    unsigned char pad1800[0x1c4c - 0x1800];
    Foo0207df50* encoder;
};

typedef char VerifyStateSize0204500c[sizeof(State0204166c) == 0x1c ? 1 : -1];
typedef char VerifyRecordSize0204500c[sizeof(BattleEntry0204500c) == 0x24 ? 1 : -1];
typedef char VerifyStatesOffset0204500c[offsetof(MessageSystem, glyphs) == 0x888 ? 1 : -1];
typedef char VerifySlotOffset0204500c[offsetof(MessageSystem, lineGlyphSlots) == 0x1752 ? 1 : -1];
typedef char VerifyEntryOffset0204500c[offsetof(MessageSystem, entries) == 0x1794 ? 1 : -1];
typedef char VerifyFlagsOffset0204500c[offsetof(MessageSystem, flags17ff) == 0x17ff ? 1 : -1];
typedef char VerifyEncoderOffset0204500c[offsetof(MessageSystem, encoder) == 0x1c4c ? 1 : -1];

#else

struct ItemNameText {
    char* first;
    char* second;
    int flags;
};


struct Foo02042fcc {
    unsigned char data[0x1c];
};

struct Entry020e2cc4 {
    unsigned char data[0x24];
};

struct Foo0207df50;
struct Struct0204394c;
struct Ctx0206a974;
struct CombatSlots0206b198;
struct RingBuffer02045824;

struct MessageSystem {
    unsigned char pad0[0x18];
    ItemNameText* itemName;
    unsigned char pad1c[0x14];
    signed char cursor30;
    signed char cursor31;
    unsigned char pad32[0x6];
    void* frame;
    unsigned char pad3c[0x4];
    int stream40;
    int stream44;
    void* textBuffer;
    unsigned short* firstLineBuffer;
    void* secondLineBuffer;
    unsigned char pad54[0xc];
    char* formatBuffer;
    char* expandedBuffer;
    unsigned char pad68[4];
    unsigned int tokenCount;
    unsigned char pad70[8];
    unsigned int tokenIndex;
    unsigned char pad7c[0x10];
    unsigned char* child;
    unsigned char pad90[0x23c];
    unsigned char bitmapAllocationBits[4];
    unsigned char pad2d0[0x642];
    unsigned char b912;
    unsigned char pad913[0x1d];
    Foo02042fcc foo930;
    int w94c[4];
    unsigned char block95c[0x20];
    unsigned char block97c[0x10];
    unsigned char pad98c[0x4];
    int w990;
    int w994;
    void* active;
    int state;
    int mode;
    int w9a4;
    unsigned char pad9a8[0x8];
    int w9b0;
    int allocatedGlyphCount;
    State0204166c glyphs[0x80];
    unsigned char glyphReferences[0x80];
    int selectedEntry;
    int selectedValue;
    int unknown1840;
    int pendingValue;
    unsigned char pad1848[0x10];
    int w1858;
    int w185c;
    int w1860;
    int w1864;
    int w1868;
    unsigned char pad186c[0x10];
    short h187c;
    short h187e;
    unsigned char pad1880[0x2];
    unsigned short lineGlyphSlots[0x40];
    unsigned char slotData[0x40];
    unsigned short lineGlyphCount;
    unsigned short h1944;
    unsigned short h1946;
    unsigned char pad1948[0x2];
    signed char levels[4];
    signed char b194e[4];
    unsigned char b1952[4];
    unsigned char b1956;
    unsigned char b1957;
    unsigned char b1958;
    unsigned char pad1959[0x1];
    unsigned char b195a;
    unsigned char b195b;
    unsigned char pad195c[0x1];
    unsigned char b195d;
    unsigned char pad195e[0x2];
    unsigned char b1960;
    unsigned char inputDelay;
    unsigned char pad1962[2];
    Entry020e2cc4 entries[2];
    unsigned char b19ac;
    unsigned char b19ad;
    unsigned char b19ae;
    unsigned char b19af;
    unsigned char b19b0;
    unsigned char b19b1;
    unsigned char b19b2;
    unsigned char pad19b3[0x1];
    unsigned char b19b4;
    unsigned char b19b5;
    unsigned char pendingValueActive;
    unsigned char pad19b7;
    unsigned char b19b8;
    unsigned char pad19b9[0x2];
    unsigned char b19bb;
    unsigned char b19bc;
    unsigned char b19bd;
    unsigned char b19be;
    unsigned char b19bf;
    unsigned char b19c0;
    unsigned char b19c1;
    unsigned char b19c2;
    unsigned char b19c3;
    unsigned char b19c4;
    unsigned char b19c5;
    unsigned char b19c6;
    unsigned char b19c7;
    unsigned char b19c8;
    unsigned char b19c9;
    unsigned char b19ca;
    unsigned char pad19cb[0x1];
    unsigned char b19cc;
    unsigned char b19cd;
    unsigned char b19ce;
    unsigned char b19cf;
    unsigned char pad19d0[0x1];
    unsigned char b19d1;
    unsigned char b19d2;
    unsigned char b19d3;
    unsigned char pad19d4[0x8];
    unsigned char b19dc;
    unsigned char pad19dd[0x44b];
    Foo0207df50* encoder;
};

#endif

#if defined(jpn)
extern "C" void func_0204500c(MessageSystem* window, const char* text, int mode);
#else
extern "C" void func_0204500c(MessageSystem* window, const char* text, int mode, void* context);
#endif
