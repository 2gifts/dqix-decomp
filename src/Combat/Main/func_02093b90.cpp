#include <globaldefs.h>
#include "std_library_functions.h"

struct FlagWord02046708;
struct AllocatorUnion;
struct Obj0205eaa0;
struct TextEntry02093b90 {
    char text[0x30];
    short code;
    signed char index;
    unsigned char started;
};
struct Obj020941b0 {
    TextEntry02093b90 entries[16];
    int handle;
    float phase;
    unsigned char text[128];
    unsigned char state:7, display:1;
    unsigned char enabled:1, reserved:7;
    unsigned char elapsed;
    signed char count;
    unsigned char unknown, flags;
};
struct Tile02093b90 {
    unsigned int offset;
    unsigned short x, y, width, height;
};
struct S_b20c { void* buffer; Tile02093b90* tiles; unsigned char count; };
extern AllocatorUnion data_02114e20;
extern Obj0205eaa0 data_02108760;
extern "C" char* func_0203bd08();
unsigned char IsPowCnt1Bit15Clear020938cc();
void SetByteAt0xc0203be58(char*, int, int);
FlagWord02046708* GetDataPtr02114e04_020d6c00();
int TestFlags02046708(FlagWord02046708*, unsigned int);
void ReleaseHandleAndClearFlags(Obj020941b0*);
extern "C" void* func_ov017_0218b5b0();
int IsChannelValueZero0203b5e0(void*, int);
extern "C" int func_020941f8(Obj020941b0*);
extern "C" int func_020943dc(Obj020941b0*);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
int GetDisplayModeCode0209378c(int);
extern "C" int func_020937f0(int);
void ClearTwoWordsAndByte(S_b20c*);
void SetField0_0205b220(void*, int);
void SetFieldsAt0x4And0x8_0205b228(void*, int, unsigned char);
extern "C" void func_0205b234(void*, int, int, void*, int, int);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToMainObjVRAM(const void*, unsigned int, unsigned int);
extern "C" void LoadToSubObjVRAM(const void*, unsigned int, unsigned int);
void TailForward02012da4(AllocatorUnion*, void*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern "C" void func_020945ac(Obj020941b0*);

static inline unsigned char* GetText02093b90(Obj020941b0* obj) { unsigned char* text=obj->text; return text; }

// USA: func_02093b90
extern "C" ARM void func_02093b90(Obj020941b0* self, int ticks) {
    char* context = func_0203bd08();
    SetByteAt0xc0203be58(context, IsPowCnt1Bit15Clear020938cc(), 1);
    FlagWord02046708* flags = GetDataPtr02114e04_020d6c00();
    if (TestFlags02046708(flags, 0x20)) {
        ReleaseHandleAndClearFlags(self);
        return;
    }
    if (!self->enabled) return;
    unsigned char currentDisplay = IsPowCnt1Bit15Clear020938cc();
    if (self->display != currentDisplay) {
        ReleaseHandleAndClearFlags(self);
        self->display = currentDisplay;
        return;
    }
    if (IsChannelValueZero0203b5e0(func_ov017_0218b5b0(), 1)) {
        ReleaseHandleAndClearFlags(self);
        return;
    }
    if (func_020941f8(self)) return;
    self->phase += 0.2f;
    if (6.28f <= self->phase) self->phase -= 6.28f;
    if (self->count <= 0) return;
    if (func_020943dc(self)) return;
    if (TestFlags02046708(flags, 0x8000)) return;
    if (self->text[0]) {
        void* pixels = AllocateAligned4(&data_02114e20, 0x800);
        if (!pixels) return;
        int display = self->display;
        if (pixels) {
          unsigned char* text = GetText02093b90(self);
          if (text) {
            GetDisplayModeCode0209378c(display);
            int destination = func_020937f0(display);
            if (destination) {
                memset(pixels, 0x11111111, 0x800);
                Tile02093b90 tiles[8];
                unsigned char index;
                unsigned char x;
                unsigned int offset;
                offset=0;
                x=0;
                index=0;
                for (;index<8; ++index) {
                    int tileIndex = index;
                    Tile02093b90* tile = &tiles[tileIndex];
                    tiles[index].offset=0;

                    tile->x=0;
                    tile->y=0;
                    tile->width=0;
                    tile->height=0;
                    tiles[index].offset=offset;
                    tile->x=x;
                    tile->y=0;
                    tile->width=32;
                    x+=32;
                    tile->height=16;
                    offset+=256;
                }
                S_b20c descriptor;
                ClearTwoWordsAndByte(&descriptor);
                SetField0_0205b220(&descriptor, (int)pixels);
                SetFieldsAt0x4And0x8_0205b228(&descriptor, (int)tiles, 8);
                func_0205b234(&descriptor, 16, 3, text, 15, 0);
                CleanInvalidateCacheRange(pixels, 0x800);
                if (display==0) LoadToMainObjVRAM(pixels, destination-0x800, 0x800);
                else LoadToSubObjVRAM(pixels, destination-0x800, 0x800);
            }
          }
        }
        TailForward02012da4(&data_02114e20,pixels);
        memset(self->text,0,128);
        self->flags |=4;
        if (!self->entries[0].started) {
            DispatchWithShortB4_0205eaa0(&data_02108760,29,0);
            self->entries[0].started=1;
        }
        return;
    }
    self->elapsed += ticks;
    unsigned int limit;
    switch ((unsigned char)self->count) {
    case 0: case 1: limit=180; break;
    case 2: limit=120; break;
    default: limit=60; break;
    }
    if (self->count>0 && self->entries[0].code==0x4e23) limit=150;
    if (limit>=self->elapsed) return;
    void* pixels = AllocateAligned4(&data_02114e20,0x800);
    if (pixels) {
        int display=self->display;
        if (pixels) {
            int destination=func_020937f0(display);
            if (destination) {
                memset(pixels,0x11111111,0x800);
                CleanInvalidateCacheRange(pixels,0x800);
                if (display==0) LoadToMainObjVRAM(pixels,destination-0x800,0x800);
                else LoadToSubObjVRAM(pixels,destination-0x800,0x800);
            }
        }
        TailForward02012da4(&data_02114e20,pixels);
    }
    func_020945ac(self);
    self->elapsed=0;
}
