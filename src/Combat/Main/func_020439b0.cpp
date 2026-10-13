#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

#define REG_BG_SCROLL_020439b0 (*(volatile unsigned int*)0x04000018)
#define REG_DISPLAY_020439b0 (*(volatile unsigned int*)0x04000000)

void LoadStateBytePair0206b804(char* obj, int* out1, int* out2);
extern "C" void func_02044c74(void* obj, void* out);
extern "C" void func_02066cf0(void* self, int flag);
void ZeroFourHalfwords02044074(struct Struct02044074* s);
extern "C" void func_02042b98(void* self, int arg1, int arg2, int arg3, int arg4);
void SetFourHalfwords(struct Struct0204408c* s, short x, short y, short z, short w);
extern "C" void func_02043600(void* a, void* box);
void InitCombatSlots02043040(char* obj);
extern "C" void func_02043124(void* self);
ARM void ResetControllerState020430b0(char* self);
extern "C" void func_020437bc(void* buf, void* box, int index);

struct Struct0204394c;
int PrepareEncodeStreamBuffer0204394c(struct Struct0204394c* obj);

struct Entry020e2cc4;
void SetEntryEnabled020e2cc4(struct Entry020e2cc4* obj, int enabled);

void RestorePairTables0207df90(char* obj);
struct Obj02041754;
void DisableField16Bit002041754(struct Obj02041754* obj);
void BackupPairTables0207dfac(char* obj);
void ClearBitInArray(int unused, unsigned char* arr, int index);

struct Rect020e2d2c;
void SetRectFromPosAndSize(struct Rect020e2d2c* s, int a, int b, int c, int d);

struct Entry020e2c34;
void UpdateAndDrawEntry020e2c34(struct Entry020e2c34* obj);

struct Foo02042fcc {
    short x;
    short y;
    short width;
    short height;
    int state;
};

struct Holder02042c24 {
    char pad[0x440];
    Foo02042fcc* currentBounds;
};

struct Stream020439b0 { char pad00[8]; int value; char pad0c[0xa8-0xc]; short sw, count, sx, sy; };
struct Struct02044074 { unsigned short x, y, z, w; };
struct Struct0204408c { short x, y, z, w; };
union Rect020439b0 { Struct02044074 zero; Struct0204408c bounds; };
struct Obj02041754 {
    int field00, field04, field08, field0c, field10;
    short field14;
    unsigned char flag0 : 1;
    unsigned char remainingFlags : 7;
    unsigned char field17;
    int field18;
};
struct DisplayEntry020439b0 { char fields[0x24]; };
struct Controller020439b0 {
    char pad0[0x34];
    Stream020439b0* stream;
    char pad38[0x8];
    int field40, field44;
    char pad48[0x2c];
    int field74, field78;
    char pad7c[0xc8];
    Struct0204408c bounds144;
    int state14c;
    char pad150[0x173];
    unsigned char flag2c3;
    char pad2c4[0x8];
    unsigned char bits2cc[4];
    char pad2d0[0x644];
    Foo02042fcc target914;
    char pad920[0x10];
    Foo02042fcc target930;
    char pad93c[0x10];
    int previousX, previousY;
    char pad954[0x44];
    int field998;
    char pad99c[0x4];
    int mode9a0;
    char pad9a4[0x14];
    Obj02041754 entries[0x80];
    unsigned char entryEnabled[0x80];
    char pad1838[0x12a];
    unsigned char flag1962;
    char pad1963[0x1];
    DisplayEntry020439b0 displayEntries[2];
    char pad19ac[0x5];
    unsigned char flag19b1;
    char pad19b2[0x8];
    unsigned char flag19ba;
    char pad19bb[0x5];
    unsigned char flag19c0;
    char pad19c1[0x2];
    unsigned char flag19c3, flag19c4;
    char pad19c5[0x6];
    unsigned char flag19cb, flag19cc;
    char pad19cd[0x1];
    unsigned char flag19ce;
    char pad19cf[0x11];
    Holder02042c24 holder;
    char pad1e24[0x4];
    void* encoder;
};

struct MapTables020439b0 { short otherMap[0x400]; short tiles[0x400]; };
extern void* data_02107800;

static inline short GetStreamWidth020439b0(Stream020439b0* stream) { return stream->sw; }

// USA: func_020439b0
extern "C" ARM void func_020439b0(char* self, int flag) {
    Controller020439b0* controller = (Controller020439b0*)self;
    int dx, dy;
    Rect020439b0 mainBounds, targetBounds, otherBounds;

    if (controller->flag19cc != 0) {
        LoadStateBytePair0206b804(self, &dx, &dy);
        func_02044c74(self, controller->stream);

        Stream020439b0* stream = controller->stream;
        int streamValue = stream->value;
        if (streamValue != 0) {
            stream->value = streamValue;

            controller->flag19cc = 0;
            func_02066cf0(self, 1);
            controller->flag19cc = 1;
            if (controller->flag19c0 != 0) {
                controller->field40 = 0;
            }

            ZeroFourHalfwords02044074(&mainBounds.zero);
            ZeroFourHalfwords02044074(&targetBounds.zero);
            ZeroFourHalfwords02044074(&otherBounds.zero);

            if (controller->field998 != 0 && controller->flag19b1 != 0) {
                goto prepareBounds;
            }
            if (controller->flag19cb != 0) {
            prepareBounds:
                if (controller->flag19b1 != 0) {
                    func_02042b98(self, 2, 0x74, 0xfc, 0x4a);
                    SetFourHalfwords(&mainBounds.bounds, dx + 2, dy + 0x74, 0xfc, 0x4a);
                    func_02043600(controller->stream, &mainBounds);
                    SetFourHalfwords(&mainBounds.bounds, 2, 0x74, 0xfc, 0x4a);

                }

                if (controller->flag19c4 != 0 && controller->flag19c3 != 0) {
                    struct Holder02042c24* holder = &controller->holder;
                    holder->currentBounds = &controller->target930;
                    int cond = (holder->currentBounds != 0) ? (holder->currentBounds->state == 2) : 0;
                    if (cond) {
                        short sx, sy, sz, sw;
                        if (holder->currentBounds != 0) {
                            sx = holder->currentBounds->x;
                            sy = holder->currentBounds->y;
                        }
                        if (holder->currentBounds != 0) {
                            sz = holder->currentBounds->width;
                            sw = holder->currentBounds->height;
                        }
                        SetFourHalfwords(&targetBounds.bounds, sx + dx, sy + dy, sz, sw);
                        func_02043600(controller->stream, &targetBounds);
                        SetFourHalfwords(&targetBounds.bounds, sx, sy, sz, sw);
                    }
                    holder->currentBounds = &controller->target914;
                }

                if (controller->mode9a0 == 6) {
                    if (controller->flag19ba != 0 && controller->flag2c3 != 0) {
                        SetFourHalfwords(&otherBounds.bounds, controller->bounds144.x, controller->bounds144.y,
                            controller->bounds144.z, controller->bounds144.w);
                        func_02043600(controller->stream, &otherBounds);
                    }
                }
            }

            Stream020439b0* updatedStream = controller->stream;
            if (updatedStream != 0) {
                short i;
                int base;
                int val;
                short count;
                int step;
                short sx = updatedStream->sx;
                short sy = updatedStream->sy;
                short sw = GetStreamWidth020439b0(updatedStream);
                count = updatedStream->count;
                base = (sx + (sy << 5)) << 5;
                val = updatedStream->value;
                i = 0;
                for (; i < count; i++) {
                    step = sw << 5;
                    StageMemoryToVRAM(VRAMSubregion_MainBG3Character, (const void*)val, base, step, 1, 0);
                    val += step;
                    base += 0x400;
                }
            }

            int oldX = controller->previousX;
            int oldY = controller->previousY;
            REG_BG_SCROLL_020439b0 = ((-oldX) & 0x1ff) | (((-oldY) << 16) & 0x1ff0000);
            controller->previousX = dx;
            controller->previousY = dy;

            if (controller->mode9a0 != 1 && controller->mode9a0 != 0) {
                memset(data_02107800, 0, 0x800);

                if (controller->field998 != 0 && controller->flag19b1 != 0) {
                    goto stageBounds;
                }
                if (controller->flag19cb != 0) {
                stageBounds:
                    if (controller->flag19b1 != 0) {
                        void* rbuf = data_02107800;
                        func_020437bc(rbuf, &mainBounds, 0);
                        func_020437bc(rbuf, &targetBounds, 1);
                        func_020437bc(rbuf, &otherBounds, 2);
                        StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, rbuf, 0, 0x800, 1, 0);
                    }
                }

                if (controller->flag19b1 == 0) {
                    StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, data_02107800, 0, 0x800, 1, 0);
                }

                if (!(controller->field74 != controller->field78 && controller->field998 != 0)) {
                    MapTables020439b0* buf = (MapTables020439b0*)data_02107800;
                    unsigned short i;
                    for (i = 0; i < 0x100; i++) {
                        buf->tiles[i] = 0;
                    }
                    for (unsigned short tableIndex = 0x100; tableIndex < 0x300; tableIndex++) {
                        buf->tiles[tableIndex] = (short)tableIndex;
                    }
                    StageMemoryToVRAM(VRAMSubregion_MainBG3Screen, buf->tiles, 0, 0x800, 1, 0);
                }
            }

            REG_DISPLAY_020439b0 = (REG_DISPLAY_020439b0 & ~0x1f00) | 0x1d00;
        }

        FreeVRAMStagingMemory((const void*)controller->stream->value);

        if (controller->field998 == 0) {
            InitCombatSlots02043040(self);
            func_02043124(self);
            ResetControllerState020430b0(self);
        }
    }

    if (controller->flag19ce != 0 && controller->field44 == 0) {
        PrepareEncodeStreamBuffer0204394c((struct Struct0204394c*)(controller->encoder));
    }
    {
        int i;
        for (i = 0; i < 2; i++) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->displayEntries[i], 0);
        }
    }

    if (flag != 0 && controller->field998 == 0) return;
    {
        void* encoder = controller->encoder;
        if (encoder != 0) {
            Obj02041754* entry;
            int j;
            for (j = 0; j < 0x80; j++) {
                if (controller->entryEnabled[j] != 0) {
                    entry = &controller->entries[j];
                    if (entry->flag0) {
                        if (controller->flag19cc != 0 || controller->flag19ce != 0) {
                            entry->flag0 = 0;
                        } else {
                            RestorePairTables0207df90((char*)controller->encoder);
                            DisableField16Bit002041754(entry);
                            BackupPairTables0207dfac((char*)controller->encoder);
                        }
                        ClearBitInArray((int)self, controller->bits2cc, entry->field08);
                    }
                }
            }
        }
    }

    if (controller->target914.state >= 2) {
        SetRectFromPosAndSize((Rect020e2d2c*)&controller->displayEntries[0], 4, 0x76, 0xf8, 0x46);
        if (controller->flag1962 != 0) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->displayEntries[0], 1);
        }
    }

    if (controller->state14c >= 2) {
        int left = controller->bounds144.x;
        int top = controller->bounds144.y;
        int right = controller->bounds144.z;
        int bottom = controller->bounds144.w;
        SetRectFromPosAndSize((Rect020e2d2c*)&controller->displayEntries[1], left + 2, top + 2, right - 4, bottom - 4);
        if (controller->flag1962 != 0) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->displayEntries[1], 1);
        }
    }

    int k;
    for (k = 0; k < 2; k++) {
        UpdateAndDrawEntry020e2c34((Entry020e2c34*)&controller->displayEntries[k]);
    }
}
