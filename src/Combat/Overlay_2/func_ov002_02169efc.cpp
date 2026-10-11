#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>

struct Struct_0205d81c;
struct Struct_0205def8;
struct Rec020467f0;
struct Struct020a9ea4;
struct FlagWord020466f4;
struct Actor0209c678;

extern "C" char *_Z26GetGlobalField0x1c020421a0v();
int GetWord0x0(int *p);
extern "C" void *_Z27GetDataPtr02114e04_020d6c00v();
void SetElementFieldC2(struct Struct_0205d81c *s, int key, int value);
extern "C" void *func_0202ae18();
int CheckField0NonZero(int *p);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int clear, int key);
void OrBitsIntoField0(unsigned int *p, unsigned int mask);
extern "C" void _Z12Init0205a198P14Struct0205a198(void *);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(void *);
extern "C" void _Z18InitStruct0205a444Pc(char *renderer);
void *FindRecordByIndex(Rec020467f0 *archive, int index, void **name, int *size);
extern "C" void func_0205a528(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
extern "C" void _Z19ClearStruct020a9ea4P14Struct020a9ea4(struct Struct020a9ea4 *p);
extern "C" int func_020aad1c(void *loader, void *name, int a, int b);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(FlagWord020466f4 *field, unsigned int bits);
void SetByte0x4(char *gs, unsigned char value);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(Actor0209c678 *actor, int state);
extern "C" void _Z26SetFieldFlag17188_0218d258Pv(void *obj);

extern "C" char data_ov002_0216d384[] __attribute__((aligned(4)));
extern "C" char data_0211e33c;
extern "C" char data_02109bf4;

static inline char *Ld(char *p, int o) {
    return *(char **) (p + o);
}
#define OBJ (self + 0x2c8 + 0xc00)

// USA: func_ov002_02169efc
extern "C" ARM void func_ov002_02169efc(char *self) {
    void *file;
    unsigned int size;
    int recSize;
    void *name;
    char *g                  = _Z26GetGlobalField0x1c020421a0v();
    GameResources *res       = (GameResources *) GetWord0x0((int *) GameState::GetInstance());
    void *flags              = _Z27GetDataPtr02114e04_020d6c00v();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    int state                = *(int *) (self + 0x1bc0);
    if (state == 0) {
        *(short *) (self + 0x1c28)         = 0x125c;
        *(short *) (self + 0x1c2a)         = -1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x24;
        *(unsigned char *) (self + 0x1c2e) = 1;
        SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x15, 1);
        SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x16, 1);
        if (CheckField0NonZero((int *) func_0202ae18())) {
            *(short *) (self + 0x1c28)         = 0x125f;
            *(int *) (self + 0x1bbc)           = 0x15;
            *(unsigned char *) (self + 0x1c2e) = 0;
        }
        *(int *) (self + 0x1bc0) = 0;
    } else if (state == 1) {
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) OBJ, 0, 0x29);
        *(short *) (self + 0x1c28)         = 0x125d;
        *(short *) (self + 0x1c2a)         = -1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x24;
        *(unsigned char *) (self + 0x1c2e) = 0;
        *(int *) (self + 0x1bc0)           = 0;
        OrBitsIntoField0((unsigned int *) flags, 0x80);
        *(int *) (self + 0x1bc4) = loader->QueueLoadFile(data_ov002_0216d384, 0);
    } else if (state == 2) {
        if (loader->GetTaskStatus(*(int *) (self + 0x1bc4)) == 0) {
            return;
        }
        for (unsigned char i = 0; i < 0x2c; i++) {
            _Z12Init0205a198P14Struct0205a198(*(char **) (self + 0x1a64) + i * 0x28);
        }
        _Z23ClearField0And40205a234P19ClearTarget0205a234(*(void **) (self + 0x1a6c));
        _Z18InitStruct0205a444Pc(*(char **) (self + 0x1a68));
        char *r                                      = *(char **) (self + 0x1a68);
        r[0x50]                                      = 0;
        char *v                                      = Ld(self, 0x1a64);
        r                                            = Ld(self, 0x1a68);
        *(char **) (r + 0x40)                        = v;
        *(short *) (r + 0x4c)                        = 8;
        *(int *) (*(char **) (self + 0x1a68) + 0x3c) = *(int *) (self + 0x1a6c);
        ((SafeAllocator *) (self + 0x78 + 0x800))->Reset();
        loader->GetLoadedFileByID(*(int *) (self + 0x1bc4), &file, &size);
        for (int j = 0; j < 4; j++) {
            void *rec = FindRecordByIndex((Rec020467f0 *) file, j, &name, &recSize);
            func_0205a528(*(void **) (self + 0x1a68), rec, recSize, (SafeAllocator *) (self + 0x78 + 0x800));
        }
        loader->RemoveTask(*(int *) (self + 0x1bc4));
        *(int *) (self + 0x1bc4) = -1;
        *(int *) (self + 0x1bc0) = 0x63;
    } else if (state == 0x63) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
            return;
        }
        *(unsigned int *) (self + 0x247c) |= 8;
        _Z19ClearStruct020a9ea4P14Struct020a9ea4((struct Struct020a9ea4 *) (self + 0x98 + 0x2400));
        *(int *) (self + 0x1bc0) = 0x64;
    } else if (state == 0x64) {
        *(unsigned char *) (g + 0x19af) = 0;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (func_020aad1c(self + 0x98 + 0x2400, &data_0211e33c, 0, 1) == 1) {
            *(unsigned char *) (self + 0x1cc2) = 1;
            *(int *) (self + 0x1bc0)           = 0x65;
        }
        BackgroundLoader::RemoveLockGlobal();
    } else if (state == 0x65) {
        *(unsigned char *) (g + 0x19af)    = 0;
        *(short *) (self + 0x1c28)         = 0x125e;
        *(short *) (self + 0x1c2a)         = -1;
        *(int *) (self + 0x1bb8)           = 0x26;
        *(int *) (self + 0x1bbc)           = 0x24;
        *(unsigned char *) (self + 0x1c2e) = 0;
        *(int *) (self + 0x1bc0)           = 0;
        _Z18ClearFlags020466f4P16FlagWord020466f4j((FlagWord020466f4 *) flags, 0x80);
        *(unsigned int *) (self + 0x247c) &= ~8;
        SetByte0x4((char *) GameState::GetInstance(), 0);
    } else if (state == 3) {
        *(unsigned char *) (g + 0x19af) = 0;
        _Z30DispatchContextByState0209c678P13Actor0209c678i((Actor0209c678 *) &data_02109bf4, 0x3c);
        SetBrightness(res, -16, 0xb4);
        *(int *) (self + 0x1bc0) += 1;
    } else if (state == 4) {
        *(unsigned char *) (g + 0x19af) = 0;
        if (!IsBrightnessTransitionActive(res)) {
            _Z26SetFieldFlag17188_0218d258Pv(func_ov017_0218b5b0());
        }
    }
}
