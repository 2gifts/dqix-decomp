#include <globaldefs.h>
#if defined(jpn)
enum { kRegionc6 = 0xc4 };
enum { kRegionc8 = 0xc6 };
enum { kRegiond8 = 0xd4 };
#else
enum { kRegionc6 = 0xc6 };
enum { kRegionc8 = 0xc8 };
enum { kRegiond8 = 0xd8 };
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "System/BGBases.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"

struct ActiveEntry02046900;
struct Rec020467f0;

extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void func_020a620c(void* obj);
int IsFieldSet(unsigned char* obj);
int CountActiveEntries(struct ActiveEntry02046900* entry);
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* outSize);

extern char data_ov003_02180a76[];

struct Obj021735c4 {
    char pad0[kRegionc6];
    short scrollY;
    char padc8[kRegiond8 - kRegionc8];
    unsigned char fade[0x15];
    unsigned char mode;
    char padee;
    unsigned char state;
    #if defined(jpn)
    char padf0[12];
#else
    char padf0[4];
#endif
    int handle;
};

// JPN: func_ov003_02172410
// USA: func_ov003_021735c4
extern "C" ARM void func_ov003_021735c4(struct Obj021735c4* self) {
    GameResources* res = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_020a620c(self->fade);

    if (self->state == 0) {
        self->handle = loader->QueueLoadFile(data_ov003_02180a76, 0);
        self->state = 1;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->handle) != 0) {
            void* recData;
            void* file;
            unsigned int length;
            unsigned char* recs[3];
            int sizes[3];
            loader->GetLoadedFileByID(self->handle, &file, &length);
            int count = CountActiveEntries((struct ActiveEntry02046900*)file);
            for (int i = 0; i < count; i++) {
                recs[i] = (unsigned char*)FindRecordByIndex((struct Rec020467f0*)file, i, &recData, &sizes[i]);
            }
            memset((void*)GetSubBG0ScreenBase(), 0, 0x800);
            unsigned char* palette = recs[2];
            CleanInvalidateCacheRange(palette + 0x4c, 0x40);
            LoadToSubBGStandardPalette(palette + 0x4c, 0x40, 0x40);
            self->scrollY = -0xc0;
            *(volatile unsigned int*)0x4001010 = (self->scrollY << 16) & 0x1ff0000;
            loader->RemoveTask(self->handle);
            self->handle = -1;
            if (IsFieldSet(self->fade) == 0) {
                self->state = 2;
            } else {
                SetSubBrightness(res, 0, 0x18);
                self->state = 3;
            }
        }
    } else if (self->state == 2) {
        if (IsFieldSet(self->fade) != 0) {
            SetSubBrightness(res, 0, 0x18);
            self->state = 3;
        }
    } else if (self->state == 3) {
        if (IsSubBrightnessTransitionActive(res) == 0) {
            self->mode = 2;
            self->state = 0;
        }
    }
}
