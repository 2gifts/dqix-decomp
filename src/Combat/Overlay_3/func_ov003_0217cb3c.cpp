#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"

struct List0204af64;
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64* graphics);
extern "C" void func_0204b5b4(void* graphics, int priority);
void SetWord0x18ClearByte0x1f(unsigned char* graphics, int value);
struct Obj0204b5e8;
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8* graphics, int a, int b);
struct AllocTarget0204b12c;
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(AllocTarget0204b12c* graphics, SafeAllocator* allocator);
struct Foo0204af38;
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(Foo0204af38* graphics, int count, SafeAllocator* allocator);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900* pac);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0* pac, int index, void** outName, int* outSize);
extern "C" void func_0204b174(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
struct Obj0204b8d0;
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(Obj0204b8d0* graphics, unsigned int a, int b, int c, short d, short e, short width, short height, unsigned short f);
struct List0204b0e8;
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8* graphics, void* characters);

struct BackgroundGraphics0217cb3c {
    char unk_0[0x1c];
    unsigned char screen_ : 4;
    unsigned char palette_ : 4;
    char unk_1d[3];
};

struct Screen0217cb3c {
    char unk_0[0x18];
    SafeAllocator subAllocator_;
    SafeAllocator mainAllocator_;
    BackgroundGraphics0217cb3c subBackground_;
    BackgroundGraphics0217cb3c mainBackground_;
    char unk_80[0xb4];
    int fileIds_[2];
};

// USA: func_ov003_0217cb3c
extern "C" ARM void func_ov003_0217cb3c(Screen0217cb3c* self, int mainScreen, int alternate) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    BackgroundGraphics0217cb3c* background;
    SafeAllocator* allocator;

    if (mainScreen != 0) {
        BG1CNT = (BG1CNT & 0x43) | 0xf00;
        background = &self->mainBackground_;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x300;
        allocator = &self->mainAllocator_;
        _Z17ResetList0204af64P12List0204af64((List0204af64*)background);
        background->screen_ = 0;
        background->palette_ = 1;
        func_0204b5b4(background, 1);
    } else {
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xf00;
        background = &self->subBackground_;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        allocator = &self->subAllocator_;
        _Z17ResetList0204af64P12List0204af64((List0204af64*)background);
        background->screen_ = 1;
        background->palette_ = 0;
        func_0204b5b4(background, 0);
    }

    allocator->Reset();

    int fileId;
    if (alternate != 0) {
        fileId = self->fileIds_[1];
    } else {
        fileId = self->fileIds_[0];
    }

    SetWord0x18ClearByte0x1f((unsigned char*)background, 0);
    _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)background, 0, 0);
    _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((AllocTarget0204b12c*)background, allocator);
    _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator((Foo0204af38*)background, 1, allocator);

    void* name;
    void* file;
    unsigned int size;
    loader->GetLoadedFileByID(fileId, &file, &size);
    int numFiles = CountActiveEntries((ActiveEntry02046900*)file);
    for (int i = 0; i < numFiles; i++) {
        unsigned int dataSize;
        void* data = FindRecordByIndex((Rec020467f0*)file, i, &name, (int*)&dataSize);
        if (data != NULL) {
            func_0204b174(background, data, allocator, dataSize);
        }
    }

    _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((Obj0204b8d0*)background, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)background, NULL);
}
