#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Struct_0205d81c;
struct Struct_0205c570;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct Struct0205a198;
struct ClearTarget0205a234;
struct Rec020467f0;
struct Struct0205de24;
struct ActiveEntry02046900;
struct Container020e0310;

int TestFlag0SetAndFlag1Clear(unsigned short *obj, int mask);
unsigned char *FindElementForFieldB0(struct Struct_0205d81c *s);
int IsField0x9cEqual3(unsigned char *obj);
void SetFieldAt0x30(void *obj, int value);
extern "C" int func_0205d0e0(void *obj, int val);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
void PushInputLogB(int id);
int GetWord0x0(int *obj);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
void SetWord0x18ClearByte0x1f(unsigned char *obj, int value);
extern "C" void func_0204b5b4(void *obj, int val);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(struct AllocTarget0204b12c *obj,
                                                                                         SafeAllocator *alloc);
extern "C" int _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(struct Obj0204b5e8 *obj, int a, int b);
extern "C" void ColorEffect_ConfigureAlphaBlend(int reg, int a, int b, int c, int d);
extern "C" void func_0204bc74(void *obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(struct List0204b0e8 *obj, void *buf);
extern "C" void func_0204b174(void *obj, void *data, SafeAllocator *alloc, int size);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(struct Obj0204c7a8 *obj, SafeAllocator *alloc,
                                                                           int buf, unsigned int size);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(struct Struct_0205cf78 *s,
                                                                                     struct Elem_0205cf78 *arr,
                                                                                     unsigned char count);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void *memcpy(void *dst, const void *src, unsigned int length);
extern "C" void *_Z21GetTableEntry020421b0i(int idx);
void CleanInvalidateCacheRange(const void *where, unsigned int len);
extern "C" void LoadToMainBG1CharacterData(const void *data, unsigned int offset, unsigned int length);
extern "C" void LoadToMainBG3CharacterData(const void *data, unsigned int offset, unsigned int length);
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198 *s);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(struct ClearTarget0205a234 *t);
extern "C" void _Z18InitStruct0205a444Pc(char *p);
void *FindRecordByIndex(struct Rec020467f0 *rec, int index, void **out, int *out44);
extern "C" void func_0205a528(void *a, void *ptr, int val, void *d);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int CountActiveEntries(struct ActiveEntry02046900 *entry);
extern "C" void func_020dfec0(void *dest, void *allocator, void *fileData, unsigned int size);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void _Z21InitBattleTag0215bf34Pc(char *self);
extern "C" void _Z21InitBattleTag0215c028Pc(char *self);
extern "C" void func_ov002_0215bba8(char *self);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215c0f8(char *self);
extern "C" void func_ov002_0215a938(char *self);

struct Obj0ec8_0215624c {
    int f0;
    int f4;
};

struct Hdr0215624c {
    int size;
    short count;
    char pad[0x1a];
};

struct Bytes3_0215624c {
    unsigned char v[3];
};

struct Tbl0216c96c {
    unsigned char pad[4];
    struct Bytes3_0215624c prio;
    struct Bytes3_0215624c layer;
};

struct Layer0215624c {
    unsigned char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

extern unsigned short data_02114e30;
extern struct Tbl0216c96c data_ov002_0216c96c;
extern char data_ov002_0216ced4[];
extern char data_ov002_0216cee8[];
extern char data_ov002_0216cef8[];
extern char data_ov002_0216cf11[];

#define S16(off) (*(short *) (self + (off)))
#define S32(off) (*(int *) (self + (off)))
#define U8(off) (*(unsigned char *) (self + (off)))
#define REG16(a) (*(volatile unsigned short *) (a))
#define REG32(a) (*(volatile unsigned int *) (a))

// USA: func_ov002_0215624c
extern "C" ARM void func_ov002_0215624c(char *self) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();

    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601)) {
        U8(0x1c2f) = 1;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x802)) {
        U8(0x1c2f)  = 0;
        S32(0x1bb8) = 0x2b;
        if (S32(0x1bc4) >= 0) {
            loader->RemoveTask(S32(0x1bc4));
            S32(0x1bc4) = -1;
        }
        for (int i = 0; i < 5; i++) {
            loader->RemoveTask(((int *) (self + 0x1ba4))[i]);
            *(int *) (self + i * 4 + 0x1ba4) = -1;
        }
        return;
    }

    unsigned char *e = FindElementForFieldB0((struct Struct_0205d81c *) (self + 0xec8));
    if (e != 0 && IsField0x9cEqual3(e) && !(e[0xc5] & 2)) {
        SetFieldAt0x30(&((struct Obj0ec8_0215624c *) (self + 0xec8))->f4, -1);
    }
    S32(0x1bc8) = func_0205d0e0(self + 0xec8, S32(0x1ba0));
    short old   = S16(0x1be0);
    S16(0x1be0) = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (self + 0xec8));
    if (S32(0x1bc0) >= 1 && old != S16(0x1be0)) {
        S32(0x1bc8) = 1;
        int saved   = S32(0x1bb8);
        S32(0x1bb8) = 1;
        func_ov002_0215bba8(self);
        S32(0x1bb8) = saved;
    }

    if (S32(0x1bc0) == 0) {
        PushInputLogB(1);
        char *w     = (char *) GetWord0x0((int *) GameState::GetInstance());
        S32(0x1bd0) = *(int *) ((char *) _Z26GetGlobalField0x1c020421a0v() + 0x5c);
        ((SafeAllocator *) (self + 0x828))->Reset();

        struct Bytes3_0215624c prio  = data_ov002_0216c96c.prio;
        struct Bytes3_0215624c layer = data_ov002_0216c96c.layer;
        struct Layer0215624c *o;
        for (int i = 0; i < 3; i++) {
            o = (struct Layer0215624c *) (self + 0xf84 + i * 0x20);
            SetWord0x18ClearByte0x1f((unsigned char *) o, 0);
            o->lo = 0;
            o->hi = prio.v[i];
            func_0204b5b4(o, layer.v[i]);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((struct AllocTarget0204b12c *) o,
                                                                                     (SafeAllocator *) (self + 0x828));
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((struct Obj0204b5e8 *) o, 0, 0);
        }

        REG16(0x0400000a) = (REG16(0x0400000a) & 0x43) | 0x1d00;
        REG16(0x0400000c) = (REG16(0x0400000c) & 0x43) | 0x1e00;
        REG16(0x0400000e) = (REG16(0x0400000e) & 0x43) | 0x1f08;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);

        char *o2;
        for (int i = 0; i < 3; i++) {
            o2 = self + 0xf84 + i * 0x20;
            func_0204bc74(o2, 0, 0, 0, 0x20, 0x19, 0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((struct List0204b0e8 *) o2, 0);
        }

        void *gfx = *(void **) (w + 0x2c);
        func_0204b174(self + 0xfa4, gfx, (SafeAllocator *) (self + 0x828), 0);
        func_0204b174(self + 0xfc4, gfx, (SafeAllocator *) (self + 0x828), 0);

        for (int i = 0; i < 3; i++) {
            struct Hdr0215624c *h = (struct Hdr0215624c *) (self + 0xf84) + i;
            h->size               = 0x60;
            h->count              = 3;
        }

        S32(0x1bd8) = (int) ((SafeAllocator *) (self + 0x828))->Allocate(0x4400);
        for (int i = 0; i < 12; i++) {
            char *o = self + 0xfe4 + i * 0xe0;
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij((struct Obj0204c7a8 *) o,
                                                                       (SafeAllocator *) (self + 0x828), S32(0x1bd8), 0x400);
            *(char **) (o + 4) = self + 0xfa4;
        }
        *(char **) (self + 0xf60) = self + 0xf84;
        U8(0xf7a)                 = 3;
        _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h((struct Struct_0205cf78 *) (self + 0xec8),
                                                                             (struct Elem_0205cf78 *) (self + 0xfe4), 12);

        memset((void *) S32(0x1bd8), 0, 0x60);
        memset((char *) S32(0x1bd8) + 0x20, 0x11111111, 0x20);
        memcpy((char *) S32(0x1bd8) + 0x40, _Z21GetTableEntry020421b0i(0x15), 0x20);
        CleanInvalidateCacheRange((void *) S32(0x1bd8), 0x60);
        LoadToMainBG1CharacterData((void *) S32(0x1bd8), 0, 0x60);
        LoadToMainBG3CharacterData((void *) S32(0x1bd8), 0, 0x60);

        for (unsigned char i = 0; i < 0x2b; i++) {
            _Z12Init0205a198P14Struct0205a198((struct Struct0205a198 *) (S32(0x1a64) + i * 0x28));
        }
        _Z23ClearField0And40205a234P19ClearTarget0205a234((struct ClearTarget0205a234 *) S32(0x1a6c));
        _Z18InitStruct0205a444Pc((char *) S32(0x1a68));
        *(unsigned char *) (S32(0x1a68) + 0x50) = 0;
        {
            char *p               = (char *) S32(0x1a68);
            *(int *) (p + 0x40)   = S32(0x1a64);
            *(short *) (p + 0x4c) = 0x2b;
        }
        *(int *) (S32(0x1a68) + 0x3c) = S32(0x1a6c);
        memcpy((void *) S32(0x1bd8), *(void **) (w + 0x30), *(unsigned int *) (w + 0x34));

        ((SafeAllocator *) (self + 0x878))->Reset();
        for (int i = 0; i < 4; i++) {
            int val;
            void *out;
            void *rec = FindRecordByIndex((struct Rec020467f0 *) S32(0x1bd8), i, &out, &val);
            func_0205a528((void *) S32(0x1a68), rec, val, self + 0x878);
        }

        S16(0x1be0) = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (self + 0xec8), 0, 2);

        if (U8(0x2485) == 0 && U8(0x253c) == 0) {
            _Z21InitBattleTag0215bf34Pc(self);
            _Z21InitBattleTag0215c028Pc(self);
            int saved   = S32(0x1bb8);
            S32(0x1bb8) = 1;
            func_ov002_02161cf0(self);
            func_ov002_0215c0f8(self);
            S32(0x1bb8) = saved;
        }

        S32(0x247c) |= 4;
        REG16(0x04000008) = (REG16(0x04000008) & ~3) | 3;
        REG16(0x0400000a) = (REG16(0x0400000a) & ~3) | 2;
        REG16(0x0400000c) = (REG16(0x0400000c) & ~3) | 1;
        REG16(0x0400000e) = (REG16(0x0400000e) & ~3);
        REG32(0x04000000) = (REG32(0x04000000) & ~0x1f00) | 0x1f00;
        func_0205d0e0(self + 0xec8, S32(0x1ba0));
        func_0205d0e0(self + 0xec8, S32(0x1ba0));

        if (U8(0x2485) != 0) {
            char *gs                 = (char *) GameState::GetInstance();
            *(short *) (gs + 0x71dc) = 0;
            *(short *) (gs + 0x7f58) = 0;
            *(short *) (gs + 0x71de) = -1;
            *(short *) (gs + 0x71e0) = -1;
        }

        S32(0x1ba4) = loader->QueueLoadFileInGP2(data_ov002_0216ced4, data_ov002_0216cee8, 0);
        S32(0x1ba8) = loader->QueueLoadFileInGP2(data_ov002_0216cef8, data_ov002_0216cf11, 0);
        S32(0x1bc0)++;
    } else if (S32(0x1bc0) == 1) {
        unsigned char ready = 0;
        for (int i = 0; i < 2; i++) {
            if (loader->GetTaskStatus(*(int *) (self + i * 4 + 0x1ba4))) {
                ready++;
            }
        }
        if (ready != 2) {
            return;
        }

        if (loader->GetTaskStatus(S32(0x1ba4))) {
            void *out;
            void *data;
            unsigned int len;
            int val;
            loader->GetLoadedFileByID(S32(0x1ba4), &data, &len);
            int n = CountActiveEntries((struct ActiveEntry02046900 *) data);
            for (unsigned char i = 0; i < 0x2b; i++) {
                _Z12Init0205a198P14Struct0205a198((struct Struct0205a198 *) (S32(0x1a64) + i * 0x28));
            }
            _Z23ClearField0And40205a234P19ClearTarget0205a234((struct ClearTarget0205a234 *) S32(0x1a6c));
            _Z18InitStruct0205a444Pc((char *) S32(0x1a68));
            *(unsigned char *) (S32(0x1a68) + 0x50) = 0;
            {
                char *p               = (char *) S32(0x1a68);
                *(int *) (p + 0x40)   = S32(0x1a64);
                *(short *) (p + 0x4c) = 0x2b;
            }
            *(int *) (S32(0x1a68) + 0x3c) = S32(0x1a6c);
            ((SafeAllocator *) (self + 0x878))->Reset();
            for (int i = 0; i < n; i++) {
                void *rec = FindRecordByIndex((struct Rec020467f0 *) data, i, &out, &val);
                func_0205a528((void *) S32(0x1a68), rec, val, self + 0x878);
            }
            loader->RemoveTask(S32(0x1ba4));
            S32(0x1ba4) = -1;
        }

        if (loader->GetTaskStatus(S32(0x1ba8))) {
            void *data;
            unsigned int len;
            loader->GetLoadedFileByID(S32(0x1ba8), &data, &len);
            ((SafeAllocator *) (self + 0x83c))->Reset();
            func_020dfec0(self + 0x20, self + 0x83c, data, len);
            S32(0x1bdc) = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), 0);
            loader->RemoveTask(S32(0x1ba8));
            S32(0x1ba8) = -1;
        }

        if (U8(0x2485) != 0) {
            S32(0x1bb8) = 4;
            S32(0x1bbc) = 0x2b;
            S32(0x1bc0) = 0;
        } else {
            S32(0x1bb8) = 1;
            S32(0x1bbc) = 0x2b;
            S32(0x1bc0) = 1;
        }
        S32(0x247c) |= 2;
        U8(0x247a) = 0;
        if (U8(0x2485) == 0) {
            func_ov002_0215a938(self);
        }
        func_020dc7e8(1, -1);
        func_020dc7e8(8, -1);
    }
}
