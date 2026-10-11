#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct GameResources;
struct Container020e0310;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct Rec020467f0;
struct ActiveEntry02046900;
struct Obj0204b5e8;
struct AllocTarget0204b12c;
struct List0204af64;
struct Foo0204af38;
struct List0204b0e8;
struct Obj0204c7a8;
struct Obj0204b8d0;
struct Struct0205a198;
struct ClearTarget0205a234;

int GetWord0x0(int* obj);
int GetGlobal02109400(void);
void SetSubBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
extern "C" void _Z21BlankFunction02094b40v(int g);
extern "C" void _Z21BlankFunction02094b34v(int g, int a, int b, int c, int d);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" int _Z18AlwaysTrue02094b4cv(int g);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
void OrGlobalFlag0x40(void);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z31ConfigureSubBg1Control_021ec368iiiii(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov023_021ec39c(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void func_ov023_021ec3c8(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void func_ov023_021ec3f4(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" void _Z28ConfigureBg1Control_021ec420iiiii(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void func_ov023_021ec454(int screenSize, int colorMode, int screenBase, int charBase);
void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);
extern "C" void func_0204b5b4(void*, int);
extern "C" int _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(struct Obj0204b5e8* obj, int a, int b);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(struct AllocTarget0204b12c* obj, SafeAllocator* alloc);
int CountActiveEntries(struct ActiveEntry02046900* entry);
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);
extern "C" void func_0204b174(void* list, void* payload, SafeAllocator* alloc, int field44);
extern "C" void func_0204bc74(void* target, int type, int a, int b, int c, int d, int flags);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(struct List0204b0e8* obj, void* buf);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(struct Obj0204c7a8* obj, SafeAllocator* alloc, int val, unsigned int len);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(struct Struct_0205cf78* s, struct Elem_0205cf78* arr, unsigned char count);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* obj);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(struct Foo0204af38* obj, int count, SafeAllocator* alloc);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198* p);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(struct ClearTarget0205a234* target);
extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);

extern char data_ov023_021fe108[];
#if defined(jpn)
extern char data_ov023_021fd39c[];
#endif
extern char data_ov023_021fe121[];
extern char data_ov023_021fe131[];
extern unsigned char data_ov023_021fd844[];

struct Bytes2 {
    unsigned char v[2];
};

struct Layer021eb578 {
    char pad0[0x1c];
    unsigned char screen : 4;
    unsigned char priority : 4;
    char pad1d[3];
};

struct Panel021eb578 {
    char pad0[4];
    Layer021eb578* layer;
    char pad8[0xd8];
};

struct Obj424_021eb578 {
    char pad0[0x3c];
    char* f3c;
    char* f40;
    char pad44[8];
    short f4c;
    char pad4e[2];
    unsigned char f50;
};

struct Scene021eb578 {
    SafeAllocator* allocs;
    char container[0x18];
    int f1c;
    int f20;
    int f24;
    char pad28[0x1c];
    Layer021eb578 layers[2];
    Layer021eb578 subLayers[2];
    char linker[0x98];
    Layer021eb578* firstLayer;
    char pad160[0x16];
    unsigned char f176;
    char pad177[9];
    Panel021eb578 panels[3];
    char* buffer;
    Obj424_021eb578* obj424;
    char* obj428;
    char* obj42c;
    unsigned char mode;
    unsigned char result;
    unsigned char state;
    char pad433;
    int taskId;
    unsigned short flags;
};

#define IS_SUB_SCREEN_MODE(self)     ((self)->mode == 0 || (self)->mode == 1 || (self)->mode == 6 || ((self)->mode == 7 && !((self)->flags & 8)))
#define IS_MAIN_SCREEN_MODE(self) ((self)->mode == 2 || ((self)->mode == 7 && ((self)->flags & 8)))

#define REG16(a) (*(volatile unsigned short*)(a))
#define REG32(a) (*(volatile unsigned int*)(a))

#define SET_LAYER_PRIORITIES(m0, m1, m2, m3, mPlanes, s0, s1, s2, s3, sPlanes)     do {         REG16(0x4000008) = (REG16(0x4000008) & ~3) | (m0);         REG16(0x400000a) = (REG16(0x400000a) & ~3) | (m1);         REG16(0x400000c) = (REG16(0x400000c) & ~3) | (m2);         REG16(0x400000e) = (REG16(0x400000e) & ~3) | (m3);         REG32(0x4000000) = (REG32(0x4000000) & ~0x1f00) | ((mPlanes) << 8);         REG16(0x4001008) = (REG16(0x4001008) & ~3) | (s0);         REG16(0x400100a) = (REG16(0x400100a) & ~3) | (s1);         REG16(0x400100c) = (REG16(0x400100c) & ~3) | (s2);         REG16(0x400100e) = (REG16(0x400100e) & ~3) | (s3);         REG32(0x4001000) = (REG32(0x4001000) & ~0x1f00) | ((sPlanes) << 8);     } while (0)

// JPN: func_ov023_021eb4dc
// USA: func_ov023_021eb578
extern "C" ARM void func_ov023_021eb578(Scene021eb578* self) {
    SafeAllocator* allocs;
    int g;
    GameResources* res;
    BackgroundLoader* loader;
    unsigned char state;
    res = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
    g = GetGlobal02109400();
    loader = BackgroundLoader::GetInstance();
    state = self->state;

    if (state == 0) {
        if (IS_SUB_SCREEN_MODE(self)) {
            SetSubBrightness(res, -16, 15);
        } else if (IS_MAIN_SCREEN_MODE(self)) {
            SetMainBrightness(res, -16, 15);
        }
        _Z21BlankFunction02094b40v(g);
        _Z21BlankFunction02094b34v(g, 0x71, 0x201, 0, 0);
        self->state++;
    }

    if (state == 1) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        if (_Z18AlwaysTrue02094b4cv(g) == 0) {
            return;
        }
        if (self->flags & 0x10) {
            OrBitsIntoField0((unsigned int*)_Z27GetDataPtr02114e04_020d6c00v(), 1);
            OrGlobalFlag0x40();
        }
#if defined(jpn)
        self->taskId = loader->QueueLoadFile(data_ov023_021fd39c, NULL);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_ov023_021fe108, data_ov023_021fe121, NULL);
#endif
        self->state++;
    }

    if (state == 2) {
        void* data;
        unsigned int length;
        unsigned char screens[2];
        int i;
        if (loader->GetTaskStatus(self->taskId) == 0) {
            return;
        }
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        allocs = self->allocs;
        allocs[2].Reset();
        func_020dfec0(self->container, &allocs[2], data, length);
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
#if defined(jpn)
        self->f1c = *(int*)(_Z26GetGlobalField0x1c020421a0v() + 0x28);
#else
        self->f1c = *(int*)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
#endif
        if (self->mode == 0 || self->mode == 1) {
            _Z31ConfigureSubBg1Control_021ec368iiiii(0, 0, 0x1a, 4, 0);
            func_ov023_021ec39c(0, 0, 0x1b, 4);
            func_ov023_021ec3c8(0, 0, 0x1c, 6);
            func_ov023_021ec3f4(0, 0, 0x1d, 2);
            screens[0] = 1;
            screens[1] = 0;
        } else if (self->mode == 7) {
            if (!(self->flags & 8)) {
                _Z31ConfigureSubBg1Control_021ec368iiiii(0, 0, 0xe, 0, 0);
                func_ov023_021ec39c(0, 0, 0xf, 0);
                func_ov023_021ec3c8(0, 0, 7, 1);
                func_ov023_021ec3f4(0, 0, 0x1e, 2);
                screens[0] = 1;
                screens[1] = 0;
            } else {
                _Z28ConfigureBg1Control_021ec420iiiii(0, 0, 0, 1, 0);
                func_ov023_021ec454(0, 0, 0x1f, 1);
                func_ov023_021ec3f4(0, 0, 0x17, 3);
                func_ov023_021ec3c8(0, 0, 0x17, 2);
                screens[0] = 0;
                screens[1] = 1;
            }
        } else if (self->mode == 2) {
            _Z28ConfigureBg1Control_021ec420iiiii(0, 0, 0, 1, 0);
            func_ov023_021ec454(0, 0, 0x1f, 1);
            func_ov023_021ec3f4(0, 0, 0x17, 3);
            func_ov023_021ec3c8(0, 0, 0x17, 2);
            screens[0] = 0;
            screens[1] = 1;
        } else if (self->mode == 6) {
            _Z31ConfigureSubBg1Control_021ec368iiiii(0, 0, 0xe, 0, 0);
            func_ov023_021ec39c(0, 0, 0xf, 0);
            func_ov023_021ec3c8(0, 0, 7, 1);
            func_ov023_021ec3f4(0, 0, 0x1d, 2);
            screens[0] = 1;
            screens[1] = 0;
        }
        for (i = 0; i < 2; i++) {
            Layer021eb578* layer = &self->subLayers[i];
            SetWord0x18ClearByte0x1f((unsigned char*)layer, 0);
            layer->screen = screens[i];
            layer->priority = 3;
            func_0204b5b4(layer, 0);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((struct Obj0204b5e8*)layer, 0, 0);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((struct AllocTarget0204b12c*)layer, &self->allocs[1]);
        }
        self->taskId = loader->QueueLoadFile(data_ov023_021fe131, NULL);
        self->state++;
    }

    if (state == 3) {
        void* out;
        void* data;
        unsigned int length;
        int field;
        void* rec;
        unsigned char panelLayers[3];
        int count;
        int i;
        int j;
        int k;
        if (loader->GetTaskStatus(self->taskId) == 0) {
            return;
        }
        allocs = self->allocs;
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        count = CountActiveEntries((struct ActiveEntry02046900*)data);
        for (i = 0; i < count; i++) {
            rec = FindRecordByIndex((struct Rec020467f0*)data, i, &out, &field);
            if (rec != NULL && i != 1) {
                func_0204b174(&self->subLayers[0], rec, &allocs[1], field);
                func_0204b174(&self->subLayers[1], rec, &allocs[1], field);
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        for (j = 0; j < 2; j++) {
            Layer021eb578* layer = &self->subLayers[j];
            func_0204bc74(layer, 0, 0, 0, 0x20, 0x19, 0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((struct List0204b0e8*)layer, 0);
        }
        self->buffer = (char*)allocs[1].Allocate(0x2a00);
        panelLayers[0] = 0;
        panelLayers[1] = 0;
        panelLayers[2] = 1;
        for (k = 0; k < 3; k++) {
            Panel021eb578* panel = &self->panels[k];
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij((struct Obj0204c7a8*)panel, &allocs[1], (int)self->buffer, 0x400);
            panel->layer = &self->subLayers[panelLayers[k]];
        }
        self->firstLayer = &self->subLayers[0];
        self->f176 = 2;
        _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h((struct Struct_0205cf78*)self->linker, (struct Elem_0205cf78*)self->panels, 3);
        self->taskId = loader->QueueLoadFile((const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self->container, 3), NULL);
        self->state++;
    }

    if (state == 4) {
        void* out;
        void* data;
        unsigned int length;
        int field;
        void* rec;
        unsigned char priorities[2];
        signed char kinds[2];
        unsigned char counts[2];
        int screen;
        int count;
        int i;
        int j;
        if (loader->GetTaskStatus(self->taskId) == 0) {
            return;
        }
        allocs = self->allocs;
        allocs->Reset();
        screen = 0;
        if (IS_SUB_SCREEN_MODE(self)) {
            screen = 1;
        } else if (IS_MAIN_SCREEN_MODE(self)) {
            screen = 0;
        }
        *(Bytes2*)priorities = *(Bytes2*)&data_ov023_021fd844[8];
        *(Bytes2*)kinds = *(Bytes2*)&data_ov023_021fd844[6];
        *(Bytes2*)counts = *(Bytes2*)&data_ov023_021fd844[0];
        for (j = 0; j < 2; j++) {
            Layer021eb578* layer = &self->layers[j];
            _Z17ResetList0204af64P12List0204af64((struct List0204af64*)layer);
            layer->screen = screen;
            layer->priority = priorities[j];
            func_0204b5b4(layer, kinds[j]);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((struct Obj0204b5e8*)layer, 0, 0);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((struct AllocTarget0204b12c*)layer, allocs);
            _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator((struct Foo0204af38*)layer, counts[j], allocs);
        }
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        count = CountActiveEntries((struct ActiveEntry02046900*)data);
        for (i = 0; i < count; i++) {
            rec = FindRecordByIndex((struct Rec020467f0*)data, i, &out, &field);
            if (rec != NULL) {
                if (i < 3) {
                    func_0204b174(&self->layers[0], rec, allocs, field);
                } else {
                    func_0204b174(&self->layers[1], rec, allocs, field);
                }
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)&self->layers[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
        _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((struct List0204b0e8*)&self->layers[0], 0);
        func_0204bc74(&self->layers[1], 0, 0, 0, 0x20, 0x19, 0);
        _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((struct List0204b0e8*)&self->layers[1], 0);
        if (self->mode == 0 || self->mode == 1) {
            SET_LAYER_PRIORITIES(1, 2, 3, 0, 0x1b, 3, 2, 1, 0, 0x1e);
        } else if (self->mode == 7) {
            if (!(self->flags & 8)) {
                SET_LAYER_PRIORITIES(1, 2, 3, 0, 0x1b, 3, 2, 1, 0, 0x1e);
            } else {
                SET_LAYER_PRIORITIES(3, 2, 1, 0, 0x1e, 2, 3, 1, 0, 0x1f);
            }
        } else if (self->mode == 2) {
            SET_LAYER_PRIORITIES(3, 2, 1, 0, 0x1e, 2, 3, 1, 0, 0x1f);
        } else if (self->mode == 6) {
            SET_LAYER_PRIORITIES(3, 1, 2, 0, 0x19, 3, 2, 1, 0, 0x1e);
        }
        self->taskId = loader->QueueLoadFile((const char*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)self->container, 4), NULL);
        self->state++;
    }

    if (state == 5) {
        void* out;
        void* data;
        unsigned int length;
        int field;
        void* rec;
        int screen;
        Obj424_021eb578* obj;
        int count;
        int i;
        int j;
        if (loader->GetTaskStatus(self->taskId) == 0) {
            return;
        }
        screen = self->layers[0].screen;
        allocs = self->allocs;
        _Z18InitStruct0205a444Pc((char*)self->obj424);
        self->obj424->f50 = screen;
        obj = self->obj424;
        obj->f40 = self->obj428;
        obj->f4c = 4;
        self->obj424->f3c = self->obj42c;
        for (j = 0; j < 4; j++) {
            _Z12Init0205a198P14Struct0205a198((struct Struct0205a198*)(self->obj428 + j * 0x28));
        }
        _Z23ClearField0And40205a234P19ClearTarget0205a234((struct ClearTarget0205a234*)self->obj42c);
        loader->GetLoadedFileByID(self->taskId, &data, &length);
        count = CountActiveEntries((struct ActiveEntry02046900*)data);
        allocs[3].Reset();
        for (i = 0; i < count; i++) {
            rec = FindRecordByIndex((struct Rec020467f0*)data, i, &out, &field);
            if (rec != NULL) {
                func_0205a528(self->obj424, rec, field, &allocs[3]);
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    }

    if (state == 6) {
        if (self->layers[0].screen == 0) {
            SetMainBrightness(res, 0, 15);
        } else {
            SetSubBrightness(res, 0, 15);
        }
        if (self->f20 == 0 || self->f24 == 0) {
            self->result = 2;
            self->state = 0;
        } else {
            self->result = 1;
            self->state = 0;
        }
    }
}
