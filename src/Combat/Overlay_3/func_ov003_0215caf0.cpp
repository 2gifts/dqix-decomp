#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct List0204b0e8;
struct List0204af64;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct Struct0205a198;
struct ClearTarget0205a234;
struct Rec020467f0;
struct ActiveEntry02046900;
struct Container020e0310;
struct List0206f7f4;

List0206f7f4 *GetData02108d18_0206f504();
short GetHalfwordChecked(List0206f7f4 *, int);
extern "C" char *strcpy(char *dst, const char *src);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" int func_02005a94();
extern "C" void func_ov003_0215e1ec(char *self);
void SetAndMulField_0215ca90(void *self, int v);
void ResetList0204af64(struct List0204af64 *obj);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char *obj, int value);
extern "C" void func_0204b5b4(void *obj, int val);
void AllocateAndClearBuffer0204b12c(struct AllocTarget0204b12c *obj,
                                                                                         SafeAllocator *alloc);
int DispatchViaTable0204b5e8(struct Obj0204b5e8 *obj, int a, int b);
extern "C" void ColorEffect_ConfigureAlphaBlend(int reg, int a, int b, int c, int d);
int CountActiveEntries(struct ActiveEntry02046900 *entry);
void *FindRecordByIndex(struct Rec020467f0 *rec, int index, void **out, int *out44);
extern "C" void func_0204b174(void *obj, void *data, SafeAllocator *alloc, int size);
extern "C" void func_0204bc74(void *obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
void FlushAndDispatchList0204b0e8(struct List0204b0e8 *obj, void *buf);
void AllocateBuffer0204c7a8(struct Obj0204c7a8 *obj, SafeAllocator *alloc,
                                                                           int buf, unsigned int size);
void LinkArrayPrevPointers0205cf78(struct Struct_0205cf78 *s,
                                                                                     struct Elem_0205cf78 *arr,
                                                                                     unsigned char count);
void Init0205a198(struct Struct0205a198 *s);
void ClearField0And40205a234(struct ClearTarget0205a234 *t);
extern "C" void func_0205a528(void *a, void *ptr, int val, void *d);
extern "C" void func_020dfec0(void *dest, void *allocator, void *fileData, unsigned int size);
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);

struct Bytes2_0215caf0 {
    unsigned char v[2];
};

struct Tbl0217f3a8 {
    struct Bytes2_0215caf0 layer;
    struct Bytes2_0215caf0 prio;
};

struct Layer0215caf0 {
    unsigned char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
};

extern char data_ov003_0217febc[];
extern char data_ov003_0217fed6[];
extern char data_ov003_0217fee7[];
extern char data_ov003_0217ff02[];
extern char data_ov003_0217ff14[];
extern char data_ov003_0217ff27[];
extern struct Tbl0217f3a8 data_ov003_0217f3a8;

#define S16(off) (*(short *) (self + (off)))
#define S32(off) (*(int *) (self + (off)))
#define U8(off) (*(unsigned char *) (self + (off)))
#define REG16(a) (*(volatile unsigned short *) (a))
#define REG32(a) (*(volatile unsigned int *) (a))

// USA: func_ov003_0215caf0
extern "C" ARM void func_ov003_0215caf0(char *self) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    unsigned char state      = U8(0x3b8);

    if (state == 0) {
        S32(0x3b4) = (int) ((SafeAllocator *) (self + 0x3c))->Allocate(0xc);
        int idx    = (short) (GetHalfwordChecked(GetData02108d18_0206f504(), 0) - 1);
        if (idx < 0) {
            idx = 0;
        }
        if (idx == 0xe) {
            U8(0x3f3) = 1;
        }
        char buf1[0x40];
        char buf2[0x18];
        __clear(buf1, 0x40);
        __clear(buf2, 0x18);
        if (U8(0x3f0) != 0) {
            strcpy(buf1, data_ov003_0217febc);
            strcpy(buf2, data_ov003_0217fed6);
        } else {
            sprintf(buf1, data_ov003_0217fee7, idx);
            sprintf(buf2, data_ov003_0217ff02, idx);
        }
        ((int *) S32(0x3b4))[0] = loader->QueueLoadFileInGP2(buf1, buf2, 0);
        ((int *) S32(0x3b4))[1] = loader->QueueLoadFile(data_ov003_0217ff14, 0);
        ((int *) S32(0x3b4))[2] = loader->QueueLoadFile(data_ov003_0217ff27, 0);
        U8(0x3b8)               = U8(0x3b8) + 1;
    }

    if (state == 1) {
        if (loader->GetTaskStatus(((int *) S32(0x3b4))[0]) > 0) {
            void *data;
            unsigned int len;
            loader->GetLoadedFileByID(((int *) S32(0x3b4))[0], &data, &len);
            ((SafeAllocator *) self)->Reset();
            func_020dfec0(self + 0x64, self, data, len);
            if (GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x64), 0x32) != 0) {
                U8(0x3ee) = func_02005a94();
            }
            if (U8(0x3ee) == 3) {
                U8(0x3ee) = 0;
                U8(0x3ef) = 0;
            }
            if (U8(0x3f0) != 0) {
                U8(0x3ee) = 2;
                U8(0x3ef) = 1;
            }
            loader->RemoveTask(((int *) S32(0x3b4))[0]);
            ((int *) S32(0x3b4))[0] = -1;
        }

        if (loader->GetTaskStatus(((int *) S32(0x3b4))[1]) > 0) {
            ((SafeAllocator *) (self + 0x28))->Reset();
            struct Bytes2_0215caf0 prio  = data_ov003_0217f3a8.prio;
            struct Bytes2_0215caf0 layer = data_ov003_0217f3a8.layer;
            struct Layer0215caf0 *o;
            for (int i = 0; i < 2; i++) {
                o = (struct Layer0215caf0 *) (self + 0x154 + i * 0x20);
                ResetList0204af64((struct List0204af64 *) o);
                SetWord0x18ClearByte0x1f_0204b11c((unsigned char *) o, 0);
                o->lo = 0;
                o->hi = prio.v[i];
                func_0204b5b4(o, layer.v[i]);
                AllocateAndClearBuffer0204b12c((struct AllocTarget0204b12c *) o,
                                                                                         (SafeAllocator *) (self + 0x28));
                DispatchViaTable0204b5e8((struct Obj0204b5e8 *) o, 0, 0);
            }
            REG16(0x0400000a) = (REG16(0x0400000a) & 0x43) | 0xd08;
            REG16(0x0400000c) = (REG16(0x0400000c) & 0x43) | 0xe08;
            ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);

            void *out;
            void *data2;
            unsigned int len2;
            int val;
            loader->GetLoadedFileByID(((int *) S32(0x3b4))[1], &data2, &len2);
            int n = CountActiveEntries((struct ActiveEntry02046900 *) data2);
            for (int i = 0; i < n; i++) {
                void *rec = FindRecordByIndex((struct Rec020467f0 *) data2, i, &out, &val);
                if (rec != 0) {
                    func_0204b174(self + 0x174, rec, (SafeAllocator *) (self + 0x28), val);
                }
            }
            char *o2;
            for (int i = 0; i < 2; i++) {
                o2 = self + 0x154 + i * 0x20;
                func_0204bc74(o2, 0, 0, 0, 0x20, 0x19, 0);
                FlushAndDispatchList0204b0e8((struct List0204b0e8 *) o2, 0);
            }
            S32(0x354) = (int) ((SafeAllocator *) (self + 0x28))->Allocate(0x1800);
            char *o3;
            for (int i = 0; i < 2; i++) {
                o3 = self + 0x194 + i * 0xe0;
                AllocateBuffer0204c7a8((struct Obj0204c7a8 *) o3,
                                                                           (SafeAllocator *) (self + 0x28), S32(0x354), 0x200);
                *(char **) (o3 + 4) = self + 0x174;
            }
            *(char **) (self + 0x130) = self + 0x154;
            U8(0x14a)                 = 2;
            LinkArrayPrevPointers0205cf78((struct Struct_0205cf78 *) (self + 0x98),
                                                                                 (struct Elem_0205cf78 *) (self + 0x194), 2);
            REG16(0x04000008) = (REG16(0x04000008) & ~3) | 2;
            REG16(0x0400000a) = (REG16(0x0400000a) & ~3) | 1;
            REG16(0x0400000c) = (REG16(0x0400000c) & ~3);
            REG16(0x0400000e) = (REG16(0x0400000e) & ~3) | 3;
            REG32(0x04000000) = (REG32(0x04000000) & ~0x1f00) | 0x1700;
            loader->RemoveTask(((int *) S32(0x3b4))[1]);
            ((int *) S32(0x3b4))[1] = -1;
        }

        if (loader->GetTaskStatus(((int *) S32(0x3b4))[2]) > 0) {
            ((SafeAllocator *) (self + 0x50))->Reset();
            S32(0x3ac) = (int) ((SafeAllocator *) (self + 0x50))->Allocate(0xf0);
            for (unsigned char i = 0; i < 6; i++) {
                Init0205a198((struct Struct0205a198 *) (S32(0x3ac) + i * 0x28));
            }
            S32(0x3b0) = (int) ((SafeAllocator *) (self + 0x50))->Allocate(8);
            ClearField0And40205a234((struct ClearTarget0205a234 *) S32(0x3b0));
            U8(0x3a8)  = 0;
            S32(0x398) = S32(0x3ac);
            S16(0x3a4) = 6;
            S32(0x394) = S32(0x3b0);
            void *out3;
            void *data3;
            unsigned int len3;
            int val3;
            loader->GetLoadedFileByID(((int *) S32(0x3b4))[2], &data3, &len3);
            int n3 = CountActiveEntries((struct ActiveEntry02046900 *) data3);
            for (int i = 0; i < n3; i++) {
                void *rec3 = FindRecordByIndex((struct Rec020467f0 *) data3, i, &out3, &val3);
                func_0205a528(self + 0x358, rec3, val3, self + 0x50);
            }
            loader->RemoveTask(((int *) S32(0x3b4))[2]);
            ((int *) S32(0x3b4))[2] = -1;
        }

        int ready = 1;
        for (int i = 0; i < 3; i++) {
            if (((int *) S32(0x3b4))[i] >= 0) {
                ready = 0;
            }
        }
        if (ready != 0) {
            state++;
        }
    }

    if (state == 2) {
        func_ov003_0215e1ec(self);
        if (U8(0x3f0) != 0) {
            SetAndMulField_0215ca90(self, 3);
        } else {
            int g = GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x64), 0x2710);
            int r = 1;
            if (g != 0) {
                r = func_02005a94();
            }
            SetAndMulField_0215ca90(self, r);
            if (r == 0) {
                U8(0x3f2) = 1;
            }
        }
        U8(0x3bc) = 1;
        U8(0x3b8) = 0;
    }
}
