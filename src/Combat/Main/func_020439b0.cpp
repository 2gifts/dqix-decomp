#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"
#include "Resource/MessageSystem.h"

#define REG_BG_SCROLL_020439b0 (*(volatile unsigned int*)0x04000018)
#define REG_DISPLAY_020439b0 (*(volatile unsigned int*)0x04000000)

void LoadStateBytePair0206b804(char* obj, int* out1, int* out2);
extern "C" void func_02044c74(void* obj, void* out);
extern "C" void func_02066cf0(void* self, int flag);
#if defined(jpn)
#define ZeroFourHalfwords02044074 func_0204483c
extern "C"
#endif
void ZeroFourHalfwords02044074(struct Struct02044074* s);
#if defined(jpn)
#define func_02042b98 func_02043270
#define func_02043600 func_02043de0
#define func_020437bc func_02043f88
#endif
extern "C" void func_02042b98(void* self, int arg1, int arg2, int arg3, int arg4);
void SetFourHalfwords(struct Struct0204408c* s, short x, short y, short z, short w);
extern "C" void func_02043600(void* a, void* box);
#include "Resource/MessageUpdate.h"
extern "C" void func_02043124(void* self);
extern "C" void func_020437bc(void* buf, void* box, int index);

struct Struct0204394c;
#if defined(jpn)
#define PrepareEncodeStreamBuffer0204394c func_02044104
extern "C"
#endif
void PrepareEncodeStreamBuffer0204394c(struct Struct0204394c* obj);

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

struct RectangleState020439b0 {
    short x;
    short y;
    short width;
    short height;
    int state;
};

struct Holder02042c24 {
    char pad[0x440];
    RectangleState020439b0* currentBounds;
};

struct Stream020439b0 { char pad00[8]; int value; char pad0c[0xa8-0xc]; short sw, count, sx, sy; };
struct Struct02044074 { unsigned short x, y, z, w; };
struct Struct0204408c { short x, y, z, w; };
union Rect020439b0 { Struct02044074 zero; Struct0204408c bounds; };
#if defined(jpn)
enum { StreamOffset = 0, BoundsOffset = 0x104, BoundsStateOffset = 0x10c,
       ShowBoundsOffset = 0x213, FirstRectangleOffset = 0x7e4,
       SecondRectangleOffset = 0x800, HolderOffset = 0x1804,
       EndTokenOffset = 0x40, OtherBoundsFlagOffset = 0x17ea,
       CompositeFlagOffset = 0x17fc, ShowEntriesOffset = 0x1790 };
#else
enum { StreamOffset = 0x34, BoundsOffset = 0x144, BoundsStateOffset = 0x14c,
       ShowBoundsOffset = 0x2c3, FirstRectangleOffset = 0x914,
       SecondRectangleOffset = 0x930, HolderOffset = 0x19e0,
       EndTokenOffset = 0x74, OtherBoundsFlagOffset = 0x19ba,
       CompositeFlagOffset = 0x19cb, ShowEntriesOffset = 0x1962 };
#endif

struct MapTables020439b0 { short otherMap[0x400]; short tiles[0x400]; };
extern void* data_02107800;
#if defined(jpn)
#define TILE_MAP_BUFFER (*(void**)((char*)&data_02107800 + 0x30))
#else
#define TILE_MAP_BUFFER data_02107800
#endif

static inline short GetStreamWidth020439b0(Stream020439b0* stream) { return stream->sw; }

// USA: func_020439b0
extern "C" ARM void func_020439b0(char* self, int flag) {
    MessageSystem* controller = (MessageSystem*)self;
    int dx, dy;
    Rect020439b0 mainBounds, targetBounds, otherBounds;

    if (controller->b19cc != 0) {
        LoadStateBytePair0206b804(self, &dx, &dy);
        func_02044c74(self, (*(Stream020439b0**)(self + StreamOffset)));

        Stream020439b0* stream = (*(Stream020439b0**)(self + StreamOffset));
        int streamValue = stream->value;
        if (streamValue != 0) {
            stream->value = streamValue;

            controller->b19cc = 0;
            func_02066cf0(self, 1);
            controller->b19cc = 1;
            if (controller->b19c0 != 0) {
                controller->stream40 = 0;
            }

            ZeroFourHalfwords02044074(&mainBounds.zero);
            ZeroFourHalfwords02044074(&targetBounds.zero);
            ZeroFourHalfwords02044074(&otherBounds.zero);

            if (controller->active != 0 && controller->b19b1 != 0) {
                goto prepareBounds;
            }
            if ((*(unsigned char*)(self + CompositeFlagOffset)) != 0) {
            prepareBounds:
                if (controller->b19b1 != 0) {
                    func_02042b98(self, 2, 0x74, 0xfc, 0x4a);
                    SetFourHalfwords(&mainBounds.bounds, dx + 2, dy + 0x74, 0xfc, 0x4a);
                    func_02043600((*(Stream020439b0**)(self + StreamOffset)), &mainBounds);
                    SetFourHalfwords(&mainBounds.bounds, 2, 0x74, 0xfc, 0x4a);

                }

                if (controller->b19c4 != 0 && controller->b19c3 != 0) {
                    struct Holder02042c24* holder = (Holder02042c24*)(self + HolderOffset);
                    holder->currentBounds = &(*(RectangleState020439b0*)(self + SecondRectangleOffset));
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
                        func_02043600((*(Stream020439b0**)(self + StreamOffset)), &targetBounds);
                        SetFourHalfwords(&targetBounds.bounds, sx, sy, sz, sw);
                    }
                    holder->currentBounds = &(*(RectangleState020439b0*)(self + FirstRectangleOffset));
                }

                if (controller->mode == 6) {
                    if ((*(unsigned char*)(self + OtherBoundsFlagOffset)) != 0 && (*(unsigned char*)(self + ShowBoundsOffset)) != 0) {
                        SetFourHalfwords(&otherBounds.bounds, (*(Struct0204408c*)(self + BoundsOffset)).x, (*(Struct0204408c*)(self + BoundsOffset)).y,
                            (*(Struct0204408c*)(self + BoundsOffset)).z, (*(Struct0204408c*)(self + BoundsOffset)).w);
                        func_02043600((*(Stream020439b0**)(self + StreamOffset)), &otherBounds);
                    }
                }
            }

            Stream020439b0* updatedStream = (*(Stream020439b0**)(self + StreamOffset));
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

            int oldX = controller->w94c[0];
            int oldY = controller->w94c[1];
            REG_BG_SCROLL_020439b0 = ((-oldX) & 0x1ff) | (((-oldY) << 16) & 0x1ff0000);
            controller->w94c[0] = dx;
            controller->w94c[1] = dy;

            if (controller->mode != 1 && controller->mode != 0) {
                memset(TILE_MAP_BUFFER, 0, 0x800);

                if (controller->active != 0 && controller->b19b1 != 0) {
                    goto stageBounds;
                }
                if ((*(unsigned char*)(self + CompositeFlagOffset)) != 0) {
                stageBounds:
                    if (controller->b19b1 != 0) {
                        void* rbuf = TILE_MAP_BUFFER;
                        func_020437bc(rbuf, &mainBounds, 0);
                        func_020437bc(rbuf, &targetBounds, 1);
                        func_020437bc(rbuf, &otherBounds, 2);
                        StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, rbuf, 0, 0x800, 1, 0);
                    }
                }

                if (controller->b19b1 == 0) {
                    StageMemoryToVRAM(VRAMSubregion_MainBG2Screen, TILE_MAP_BUFFER, 0, 0x800, 1, 0);
                }

                if (!((*(unsigned int*)(self + EndTokenOffset)) != controller->tokenIndex && controller->active != 0)) {
                    MapTables020439b0* buf = (MapTables020439b0*)TILE_MAP_BUFFER;
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

        FreeVRAMStagingMemory((const void*)(*(Stream020439b0**)(self + StreamOffset))->value);

        if (controller->active == 0) {
            InitCombatSlots02043040((MessageSystem*)self);
            func_02043124(self);
            ResetControllerState020430b0((MessageSystem*)self);
        }
    }

    if ((
#if defined(jpn)
            controller->flags17ff.streamMode
#else
            controller->b19ce
#endif
        ) != 0 && controller->stream44 == 0) {
        PrepareEncodeStreamBuffer0204394c((struct Struct0204394c*)(controller->encoder));
    }
    {
        int i;
        for (i = 0; i < 2; i++) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->entries[i], 0);
        }
    }

    if (flag != 0 && controller->active == 0) return;
    {
        void* encoder = controller->encoder;
        if (encoder != 0) {
            MessageGlyphSlot* entry;
            int j;
            for (j = 0; j < 0x80; j++) {
                if (controller->glyphReferences[j] != 0) {
                    entry = &controller->glyphs[j];
                    if (entry->pendingUpload) {
                        if (controller->b19cc != 0 || (
#if defined(jpn)
            controller->flags17ff.streamMode
#else
            controller->b19ce
#endif
        ) != 0) {
                            entry->pendingUpload = 0;
                        } else {
                            RestorePairTables0207df90((char*)controller->encoder);
                            DisableField16Bit002041754((Obj02041754*)entry);
                            BackupPairTables0207dfac((char*)controller->encoder);
                        }
                        ClearBitInArray((int)self, controller->bitmapAllocationBits, entry->bitmapIndex);
                    }
                }
            }
        }
    }

    if ((*(RectangleState020439b0*)(self + FirstRectangleOffset)).state >= 2) {
        SetRectFromPosAndSize((Rect020e2d2c*)&controller->entries[0], 4, 0x76, 0xf8, 0x46);
        if ((*(unsigned char*)(self + ShowEntriesOffset)) != 0) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->entries[0], 1);
        }
    }

    if ((*(int*)(self + BoundsStateOffset)) >= 2) {
        int left = (*(Struct0204408c*)(self + BoundsOffset)).x;
        int top = (*(Struct0204408c*)(self + BoundsOffset)).y;
        int right = (*(Struct0204408c*)(self + BoundsOffset)).z;
        int bottom = (*(Struct0204408c*)(self + BoundsOffset)).w;
        SetRectFromPosAndSize((Rect020e2d2c*)&controller->entries[1], left + 2, top + 2, right - 4, bottom - 4);
        if ((*(unsigned char*)(self + ShowEntriesOffset)) != 0) {
            SetEntryEnabled020e2cc4((Entry020e2cc4*)&controller->entries[1], 1);
        }
    }

    int k;
    for (k = 0; k < 2; k++) {
        UpdateAndDrawEntry020e2c34((Entry020e2c34*)&controller->entries[k]);
    }
}
