#pragma once

#include <globaldefs.h>
#include "System/Matrix.h"
#include "Memory/SafeAllocator.h"

struct Entry02021578 {
    int field0;
    char* name;
    char pad8[0x1c];
};

struct Struct0205a198 {
    unsigned short count, flags;
    void* cells;
    void* copy;
    unsigned int field0c, field10, field14, field18;
    unsigned short field1c, index, field20;
    unsigned char firstCell, field23, field24, field25;
    signed char field26;
    char padding27;
};

struct MapEntryList {
    unsigned char unknown0[0x40];
    Struct0205a198* records;
    unsigned char unknown44[8];
    unsigned short count;
    unsigned short unknown4e;
    unsigned char active;
    unsigned char unknown51[3];
};

struct List0204af64 {
    int byteCount;
    char unknown4[8];
    unsigned char b0c;
    unsigned char unknown0d;
    unsigned short h0e;
    int w10, w14, w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d, b1e, b1f;
};

struct ForwardingRecord02024518;
struct Node02021f88;

struct MapDisplay {
    unsigned char state;
    unsigned char unknown1;
    char headerName[0x10];
    unsigned char field12;
    unsigned char unknown13;
    int displayMode;
    int forwardingX;
    int forwardingY;
    Entry02021578* names;
    int nameCount;
    int field28;
    ForwardingRecord02024518* forwarding;
    int forwardingCount;
    int field34;
    fix32_t scale;
    fix32_t cameraBiasX;
    fix32_t cameraBiasZ;
    int screenX;
    int screenY;
    List0204af64 list4c;
    void* mapState;
    int mapPalette;
    int forwardingFill;
    unsigned char unknown78[0x94 - 0x78];
    MapEntryList entryList;
    Struct0205a198 records[28];
    char name[0x10];
    unsigned char recordVisible[4];
    unsigned char forwardingPending;
    unsigned char mask55d;
    unsigned char field55e;
    unsigned char unknown55f;
    int slots[4];
    unsigned char slotFlags[4];
    unsigned char unknown574[0x5a4 - 0x574];
    int flags;
    unsigned char field5a8;
    unsigned char unknown5a9[3];
    fix32_t cameraX;
    fix32_t cameraZ;
#if defined(jpn)
    unsigned char unknown5b4[0x6a8 - 0x5b4];
#else
    unsigned char unknown5b4[0x754 - 0x5b4];
#endif
    Node02021f88* field754;
    unsigned char flags758[4];
    unsigned char field75c;
    unsigned char field75d;
    unsigned char unknown75e[2];
    int field760;
    unsigned char field764;
    unsigned char field765;
    short field766;
    unsigned char field768;
    unsigned char unknown769[3];
    int field76c;
    int field770;
    int field774;
    unsigned char field778;
    unsigned char refreshRecords;
    unsigned char field77a;
    unsigned char unknown77b;
    int field77c;
    unsigned char field780;
    unsigned char unknown781[0x9b4 - 0x781];
    int field9b4;
    unsigned char field9b8;
    unsigned char field9b9;
    unsigned char field9ba;
    unsigned char unknown9bb;
    int field9bc;
    unsigned char actionState;
    unsigned char field9c1;
    signed char loadStage;
    unsigned char field9c3;
    unsigned char field9c4;
    unsigned char field9c5;
    unsigned char field9c6;
    unsigned char failed;
    unsigned char field9c8;
    unsigned char unknown9c9[3];
    int fileTask920;
    int namesTask;
    int fileTask928;
    int nameTasks[8];
    int scriptTask;
    int task9fc;
    int taska00;
    int taska04;
    int taska08;
    int taska0c;
    int taska10;
    int taska14;
    int taska18;
    int taska1c;
    int taska20;
    int taska24;
    int taska28;
    int taska2c;
    int fileTask984;
    unsigned char fielda34;
    unsigned char bytesa35[0x10];
    unsigned char bytesa45[0x10];
    unsigned char bytesa55[0x20];
#if !defined(jpn)
    unsigned char unknowna75[0x20];
#endif
    unsigned char fielda95;
    unsigned char fielda96;
    unsigned char fielda97;
    unsigned char unknowna98[4];
    int fielda9c;
    short fieldaa0;
    unsigned char bytesaa2[0x100];
#if !defined(jpn)
    char scriptName[0x40];
    unsigned char unknownbe2[2];
    int scriptNameWidth;
    int fieldb3c;
    short fieldb40;
    short fieldb42;
    unsigned char savedTiles[0x40];
#endif
};

#if defined(jpn)
typedef int MapDisplayTaskHandle;
typedef char MapDisplaySizeCheck[sizeof(MapDisplay) == 0xad8 ? 1 : -1];
typedef char MapDisplayStageCheck[offsetof(MapDisplay, loadStage) == 0x916 ? 1 : -1];
typedef char MapDisplayBufferCheck[offsetof(MapDisplay, bytesaa2) == 0x9d6 ? 1 : -1];
#else
typedef int* MapDisplayTaskHandle;
typedef char MapDisplaySizeCheck[sizeof(MapDisplay) == 0xc30 ? 1 : -1];
typedef char MapDisplayStageCheck[offsetof(MapDisplay, loadStage) == 0x9c2 ? 1 : -1];
typedef char MapDisplayBufferCheck[offsetof(MapDisplay, bytesaa2) == 0xaa2 ? 1 : -1];
#endif
typedef char MapDisplayRecordsCheck[offsetof(MapDisplay, records) == 0xe8 ? 1 : -1];
typedef char MapDisplayListCheck[offsetof(MapDisplay, entryList) == 0x94 ? 1 : -1];
typedef char MapDisplayCameraCheck[offsetof(MapDisplay, cameraX) == 0x5ac ? 1 : -1];

extern "C" void func_02020720(MapDisplay* self);
// The caller supplies its display context; this global screen setup does not read it.
extern "C" void func_02020838(MapDisplay* unusedContext);
extern "C" void func_02020aec(MapDisplay* self, MapDisplayTaskHandle handle, SafeAllocator* allocator);
